/********************************************************************
 * Test Order Entry related messages
 *
 * Copyright (C) 2015 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Apr 05 18:47:47 2015
 *******************************************************************/

#include <iostream>

#include "questradeapi/GetAccounts.h"
#include "questradeapi/SearchSymbols.h"
#include "questradeapi/InsertOrderImpact.h"
#include "questradeapi/InsertOrder.h"
#include "questradeapi/ReplaceOrderImpact.h"
#include "questradeapi/ReplaceOrder.h"
#include "questradeapi/CancelOrder.h"
#include "questradeapi/GetMarkets.h"
#include "questradeapi/OrderAndExecutionNotifications.h"
#include "questradeapi/TypeConverters.h"
#include "questradeapi/BracketOrderImpact.h"
#include "questradeapi/BracketReplaceImpact.h"
#include "questradeapi/InsertBracketOrder.h"
#include "questradeapi/ReplaceBracketOrder.h"
#include "questradeapi/StrategyOrderImpact.h"
#include "questradeapi/StrategyReplaceImpact.h"
#include "questradeapi/InsertStrategyOrder.h"
#include "questradeapi/ReplaceStrategyOrder.h"
#include "questradeapi/GetOptions.h"

#include "ApiTestDefines.h"

using namespace QuestradeAPI;

namespace
{

void TestOrderError(AuthenticationInfo authInfo, std::string primaryAcc, uint64 symbolId)
{
    // This one is erroneous because type Limit is specified, but no Limit Price is given
    InsertOrderRequest errInsReq(primaryAcc, symbolId, 100, OrderType::Limit, OrderTimeInForce::GoodTillCanceled, OrderAction::Buy, "AUTO");

    auto insError = InsertOrderImpact(authInfo, errInsReq);
    std::cout << "Sample response, if error occurs when placing order:" << std::endl << "   Error code Message: " << insError.getErrorMessage() << std::endl << "   Error code: " << insError.getErrorCode() << std::endl << std::endl;
    Sleep(2000);
}


void printNotificationData(OrderAndExecutionNotificationsResponse resp)
{
    std::unique_lock<std::recursive_mutex> lock(testStremingMutex);
    std::cout << "Notification (" << resp.getAsyncRequestId() << "): " << std::endl << resp.dumpToJson() << std::endl << resp.getErrorMessage() << std::endl;
}

}

void TestOrders(AuthenticationInfo authInfo)
{
    // Symbol which orders will be for
    auto symbolsResp = SearchSymbols(authInfo, "MSFT", 0);
    std::cout << symbolsResp.dumpToJson() << std::endl << std::endl;

    auto symbols = symbolsResp.getSymbols();

    if (symbols.empty())
    {
        std::cerr << "Error getting symbols " << symbolsResp.getErrorCode() << std::endl << symbolsResp.getErrorMessage() << std::endl << std::endl;
        return;
    }

    // get accounts
    auto accounts = GetAccounts(authInfo);
    
    std::string primaryAcc;

    // finding primary account
    for (auto& acc : accounts.getAccounts())
    {
        if (acc.isPrimary())
        {
            primaryAcc = acc.getNumber();
            std::cout << acc.dumpToJson() << std::endl << std::endl;
        }
    }

    if (primaryAcc.empty())
    {
        std::cerr << "Error getting primary account " << accounts.getErrorCode() << std::endl << accounts.getErrorMessage() << std::endl << std::endl;
        std::cerr << accounts.dumpToJson() << std::endl << std::endl;
        return;
    }

    // GetMarkets main use is to get routes for exchanges
    auto einfo = GetMarkets(authInfo);
    auto exvec = einfo.getMarkets();
    std::string route = "AUTO";

    if (!exvec.empty())
    {
        for (auto it = exvec.begin(); it != exvec.end(); ++it)
        {
            // Compare names of markets and name of Listing Exchange of symbol
            // and then you can get possible Primary and Secondary Routes
            if (it->getName() == symbols[0].getListingExchange())
            {
                std::cout << it->dumpToJson() << std::endl << std::endl;
                route = it->getPrimaryOrderRoutes().back();
            }
        }
    }
    else
    {
        std::cout << "No exchanges were extracted, error code: " << einfo.getErrorCode() << std::endl << einfo.getErrorMessage();
        // "AUTO" works always, so we can continue
    }

    Sleep(2000);
    
    // Prepare request for inserting order
    InsertOrderRequest insReq(primaryAcc, symbols[0].getSymbolId(), 100, OrderType::Limit, OrderTimeInForce::Day, OrderAction::Buy, route);
    insReq.m_limitPrice = 0.1;

    // First we try impact without actually inserting an order
    auto insImpact = InsertOrderImpact(authInfo, insReq);
    std::cout << insImpact.dumpToJson() << std::endl << "Error code: " << insImpact.getErrorCode() << std::endl << insImpact.getErrorMessage() << std::endl << std::endl;

    Sleep(2000);

    BracketOrderComponent primaryIns(OrderClass::Primary);

    primaryIns.m_limitPrice = 2;
    primaryIns.m_orderType = OrderType::Limit;
    primaryIns.m_timeInForce = OrderTimeInForce::Day;
    primaryIns.m_quantity = 100;
    primaryIns.m_action = OrderAction::Buy;

    BracketOrderComponent limitIns(OrderClass::Limit);

    limitIns.m_limitPrice = 1000;
    limitIns.m_orderType = OrderType::Limit;
    limitIns.m_timeInForce = OrderTimeInForce::Day;
    limitIns.m_quantity = primaryIns.m_quantity;
    limitIns.m_action = OrderAction::Sell;

    BracketOrderComponent stopIns(OrderClass::StopLoss);

    stopIns.m_stopPrice = 1;
    stopIns.m_limitPrice = 0.9;
    stopIns.m_orderType = OrderType::StopLimit;
    stopIns.m_timeInForce = OrderTimeInForce::Day;
    stopIns.m_quantity = primaryIns.m_quantity;
    stopIns.m_action = OrderAction::Sell;

    std::vector<BracketOrderComponent> compsIns;
    compsIns.push_back(primaryIns);
    compsIns.push_back(limitIns);
    compsIns.push_back(stopIns);

    // impact for bracket
    auto bracketImpact = BracketOrderImpact(authInfo, primaryAcc,symbols[0].getSymbolId(),"AUTO",compsIns);
    std::cout << bracketImpact.dumpToJson() << std::endl << "Error code: " << bracketImpact.getErrorCode() << std::endl << bracketImpact.getErrorMessage() << std::endl << std::endl;

    Sleep(2000);

    // Prepare request for inserting order
    auto optionsResp = GetOptions(authInfo, symbols[0].getSymbolId());

    if (optionsResp.getOptionChain().empty())
    {
        std::cerr << "Option chain not found for MSFT" << std::endl;
        return;
    }

    std::vector<InsertOrderLegData> legs;
    legs.push_back(InsertOrderLegData(optionsResp.getOptionChain().front().getChainPerRoot().front().getChainPerStrikePrice().front().getCallSymbolId(),
                                      OrderAction::Sell,
                                      10));
    legs.push_back(InsertOrderLegData(symbols[0].getSymbolId(), OrderAction::Buy, 1000));


    InsertStrategyOrderRequest insStrategy(primaryAcc, symbols[0].getSymbolId(), OrderType::Limit, OrderTimeInForce::Day, route, legs);
    insStrategy.m_limitPrice = -1.23;

    // First we try impact without actually inserting an order
    auto strategyImpact = StrategyOrderImpact(authInfo, insStrategy);
    std::cout << strategyImpact.dumpToJson() << std::endl << "Error code: " << strategyImpact.getErrorCode() << std::endl << strategyImpact.getErrorMessage() << std::endl << std::endl;

    Sleep(2000);

    if (!authInfo.isDemo())
    {
        TestOrderError(authInfo, primaryAcc, symbols[0].getSymbolId());

        std::cout << "You are not connected to practice, no actual orders will be inserted" << std::endl << std::endl;
        return;
    }

    OrderAndExecutionNotificationsStream(authInfo, printNotificationData, 0);

    // Insert order (will most probably fail if impact failed)
    // so in actual program you probably should check that Impact didn't fail
    auto insResp = InsertOrder(authInfo, insReq);

    uint64 orderId = insResp.getOrderId();
    std::cout << insResp.dumpToJson() << std::endl << "Error code: " << insResp.getErrorCode() << std::endl << insResp.getErrorMessage() << std::endl << std::endl;

    Sleep(2000);

    if (insResp.getErrorCode() == 0)
    {
        // replace order request
        ReplaceOrderRequest repReq = createReplaceRequest(primaryAcc, insResp.getOrders().at(0));
        repReq.m_limitPrice = 0.01; // change limit price in order

        // impact for replace
        auto repImpact = ReplaceOrderImpact(authInfo, repReq);
        std::cout << repImpact.dumpToJson() << std::endl << "Error code: " << repImpact.getErrorCode() << std::endl << repImpact.getErrorMessage() << std::endl << std::endl;

        Sleep(2000);

        // Replace order inserted before
        auto repResp = ReplaceOrder(authInfo, repReq);

        std::cout << repResp.dumpToJson() << std::endl << "Error code: " << repResp.getErrorCode() << std::endl << repResp.getErrorMessage() << std::endl << std::endl;

        Sleep(2000);

        // Cancel will work even though original order ID is specified, but server will find last in chain anyway.
        auto canResp = CancelOrder(authInfo, primaryAcc, orderId);

        std::cout << canResp.dumpToJson() << std::endl << "Error code: " << canResp.getErrorCode() << std::endl << canResp.getErrorMessage() << std::endl << std::endl;

        Sleep(2000);
    }

    // Market is the only type that doesn't need any extra information (apart from what you have in constructor)
    // This will create a position so that you would see positions and executions in Account Info
    InsertOrderRequest marketReq(primaryAcc, symbols[0].getSymbolId(), 100, OrderType::Market, OrderTimeInForce::Day, OrderAction::Buy, "AUTO");

    auto marketOrder = InsertOrder(authInfo, marketReq);

    std::cout << marketOrder.dumpToJson() << std::endl << "Error code: " << marketOrder.getErrorCode() << std::endl << marketOrder.getErrorMessage() << std::endl << std::endl;

    Sleep(2000);

    if (marketOrder.getErrorCode() == 0)
    {
        Sleep(8000); // Sleep some extra time to get an execution
        // insert bracket order on position
        BracketOrderComponent limit(OrderClass::Limit);

        limit.m_limitPrice = 1000;
        limit.m_orderType = OrderType::Limit;
        limit.m_timeInForce = OrderTimeInForce::Day;
        limit.m_quantity = marketOrder.getOrders()[0].getTotalQuantity();
        limit.m_action = OrderAction::Sell;

        BracketOrderComponent stop(OrderClass::StopLoss);

        stop.m_stopPrice = 0.1;
        stop.m_orderType = OrderType::Stop;
        stop.m_timeInForce = OrderTimeInForce::Day;
        stop.m_quantity = limit.m_quantity;
        stop.m_action = OrderAction::Sell;

        std::vector<BracketOrderComponent> comps;
        comps.push_back(limit);
        comps.push_back(stop);

        // impact for bracket
        auto brImpact = BracketOrderImpact(authInfo, primaryAcc,symbols[0].getSymbolId(),"AUTO",comps);
        std::cout << brImpact.dumpToJson() << std::endl << "Error code: " << brImpact.getErrorCode() << std::endl << brImpact.getErrorMessage() << std::endl << std::endl;

        Sleep(2000);

        // insert bracket on position
        auto brIns = InsertBracketOrder(authInfo, primaryAcc,symbols[0].getSymbolId(),"AUTO",comps);
        std::cout << brIns.dumpToJson() << std::endl << "Error code: " << brIns.getErrorCode() << std::endl << brIns.getErrorMessage() << std::endl << std::endl;
        Sleep(2000);
    }

    auto insResp2 = InsertOrder(authInfo, insReq);
    if (insResp2.getErrorCode() == 0)
    {
        Sleep(2000);
        // add bracket order to an existing order
        BracketOrderComponent limit(OrderClass::Limit);

        limit.m_limitPrice = 1000;
        limit.m_orderType = OrderType::Limit;
        limit.m_timeInForce = OrderTimeInForce::Day;
        limit.m_quantity = insResp2.getOrders()[0].getTotalQuantity();
        limit.m_action = OrderAction::Sell;

        BracketOrderComponent primary(OrderClass::Primary);
        primary.m_orderId = insResp2.getOrderId(); // You can take old ID even if it was replaced

        std::vector<BracketOrderComponent> comps;
        comps.push_back(primary);
        comps.push_back(limit);

        // impact for bracket
        auto brImpact = BracketOrderImpact(authInfo, primaryAcc,symbols[0].getSymbolId(),"AUTO",comps);
        std::cout << brImpact.dumpToJson() << std::endl << "Error code: " << brImpact.getErrorCode() << std::endl << brImpact.getErrorMessage() << std::endl << std::endl;

        Sleep(2000);

        // insert bracket on position
        auto brIns = InsertBracketOrder(authInfo, primaryAcc,symbols[0].getSymbolId(),"AUTO",comps);
        std::cout << brIns.dumpToJson() << std::endl << "Error code: " << brIns.getErrorCode() << std::endl << brIns.getErrorMessage() << std::endl << std::endl;
        Sleep(2000);
    }

    // insert bracket on position
    auto bracketIns = InsertBracketOrder(authInfo, primaryAcc,symbols[0].getSymbolId(),"AUTO",compsIns);
    std::cout << bracketIns.dumpToJson() << std::endl << "Error code: " << bracketIns.getErrorCode() << std::endl << bracketIns.getErrorMessage() << std::endl << std::endl;
    Sleep(2000);

    if (bracketIns.getErrorCode() == 0)
    {
        auto brOrders1 = bracketIns.getOrders();
        std::vector<BracketOrderComponent> replComp1;
        replComp1.reserve(brOrders1.size());

        for (const auto& order : brOrders1)
        {
            replComp1.push_back(createReplacingBracketComponent(order));
            replComp1.back().m_timeInForce = OrderTimeInForce::GoodTillCanceled;
            replComp1.back().m_limitPrice = replComp1.back().m_limitPrice - 0.01;
        }

        // impact for bracket
        auto bracketReplImp = BracketReplaceImpact(authInfo, primaryAcc,replComp1);
        std::cout << bracketReplImp.dumpToJson() << std::endl << "Error code: " << bracketReplImp.getErrorCode() << std::endl << bracketReplImp.getErrorMessage() << std::endl << std::endl;

        Sleep(2000);

        // insert bracket on position
        auto bracketRepl1 = ReplaceBracketOrder(authInfo, primaryAcc,replComp1);
        std::cout << bracketRepl1.dumpToJson() << std::endl << "Error code: " << bracketRepl1.getErrorCode() << std::endl << bracketRepl1.getErrorMessage() << std::endl << std::endl;
        Sleep(2000);

        // example where only 1 order is changed
        auto replComp2 = replComp1;

        for (auto& comp : replComp2)
        {
            if (comp.m_orderClass == OrderClass::Primary)
            {
                comp.m_timeInForce = OrderTimeInForce::Day;
                break;
            }
        }

        // insert bracket on position
        auto bracketRepl2 = ReplaceBracketOrder(authInfo, primaryAcc,replComp2);
        std::cout << bracketRepl2.dumpToJson() << std::endl << "Error code: " << bracketRepl2.getErrorCode() << std::endl << bracketRepl2.getErrorMessage() << std::endl << std::endl;
        Sleep(2000);
    }

    auto strategyResp = InsertStrategyOrder(authInfo, insStrategy);
    std::cout << strategyResp.dumpToJson() << std::endl << "Error code: " << strategyResp.getErrorCode() << std::endl << strategyResp.getErrorMessage() << std::endl << std::endl;

    Sleep(2000);

    if (strategyResp.getErrorCode() == 0)
    {
        // replace order request
        ReplaceStrategyOrderRequest repReq = createStrategyReplaceRequest(primaryAcc, strategyResp.getOrders().at(0));
        repReq.m_limitPrice = 0.01; // change limit price in order

        // impact for replace
        auto repImpact = StrategyReplaceImpact(authInfo, repReq);
        std::cout << repImpact.dumpToJson() << std::endl << "Error code: " << repImpact.getErrorCode() << std::endl << repImpact.getErrorMessage() << std::endl << std::endl;

        Sleep(2000);

        // Replace order inserted before
        auto repResp = ReplaceStrategyOrder(authInfo, repReq);

        std::cout << repResp.dumpToJson() << std::endl << "Error code: " << repResp.getErrorCode() << std::endl << repResp.getErrorMessage() << std::endl << std::endl;

        Sleep(2000);
    }

    TestOrderError(authInfo, primaryAcc, symbols[0].getSymbolId());

    StopOrderAndExecutionNotificationsStream(authInfo);
}
