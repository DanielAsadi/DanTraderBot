/********************************************************************
 * Account Information examples
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.0.0
 * Creation Date:  Wed Oct 22 18:47:47 2014
 *******************************************************************/

#include <iostream>

#include "QuestradeAPI/Cpp/include/questradeapi/GetAccounts.h"
#include "QuestradeAPI/Cpp/include/questradeapi/GetPositions.h"
#include "QuestradeAPI/Cpp/include/questradeapi/GetExecutions.h"
#include "QuestradeAPI/Cpp/include/questradeapi/GetBalances.h"
#include "QuestradeAPI/Cpp/include/questradeapi/GetOrders.h"

#include "ApiTestDefines.h"

using namespace QuestradeAPI;

void testAccountInfo(AuthenticationInfo authInfo)
{
    // Get Accounts
    auto accounts = GetAccounts(authInfo);
    
    std::string primaryAcc;

    // Extract primary account, that is where we expect to find the most of stuff
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
        std::cerr << "Error getting primary account " << accounts.getErrorCode() << std::endl << accounts.getErrorMessage() << std::endl;
        std::cerr << accounts.dumpToJson() << std::endl << std::endl;
        return;
    }
    
    Sleep(2000);
    
    // Get Orders for last 3 days and today
    std::vector<uint64> orderIdVec;
    auto resp2 = GetOrders(authInfo, primaryAcc, OrderStateFilterTypes::All, DateTime(DateTime::startOfDay().toEpochTime() - 3 * 24 * 3600));
    auto vec = resp2.getOrders();
    if (!vec.empty())
    {
        // insert couple of orders from vector to extrace later in GetOrdersByID
        orderIdVec.push_back(vec.front().getId());
        orderIdVec.push_back(vec.back().getId());
        std::cout << vec.back().dumpToJson() << std::endl << std::endl;

        for (auto data = vec.begin(); data != vec.end(); ++data)
        {
            auto legVec = data->getLegs();
            // Place a multi-leg order through any non-API platform and this will demonstrate one of the option legs
            // (Note: It might not be the last leg of what you entered in custom strategy, because leg order is not guaranteed to be same as in initial request)
            if (! legVec.empty())
            {
                std::cout << std::endl << std::endl << "Example of OrderLeg:" << std::endl << legVec.back().dumpToJson() << std::endl;
                break;
            }
        }
    }
    Sleep(2000);
    
    // Positions on account
    auto pos = GetPositions(authInfo, primaryAcc);
    auto posVec = pos.getPositions();

    if (!posVec.empty())
    {
        std::cout << posVec.front().dumpToJson() << std::endl << std::endl;
    }

    Sleep(2000);

    // Executions on Account
    auto execs = GetExecutions(authInfo, primaryAcc);
    auto execVec = execs.getExecutions();

    if (! execVec.empty())
    {
        std::cout << execVec.at(0).dumpToJson() << std::endl << std::endl;
    }
    
    Sleep(2000);

    // Account balances
    auto balance = GetBalances(authInfo, primaryAcc);

    std::cout << balance.dumpToJson() << std::endl << std::endl;

    Sleep(2000);

    // Demonstrates orders by ID
    auto ordersData = GetOrdersByID(authInfo, primaryAcc, orderIdVec);

    std::cout << ordersData.dumpToJson() << std::endl << std::endl;
    
    Sleep(2000);
}