/********************************************************************
 * Example of Stream calls
 *
 * Copyright (C) 2015 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Apr 05 18:47:47 2015
 *******************************************************************/

#include <iostream>

#include "questradeapi/GetOptions.h"
#include "questradeapi/SearchSymbols.h"
#include "questradeapi/GetQuote.h"
#include "questradeapi/GetOptionQuotes.h"
#include "questradeapi/GetStrategyQuote.h"

#include "ApiTestDefines.h"
#include "AuthenticationTokenHandler.h"

using namespace QuestradeAPI;

std::recursive_mutex testStremingMutex;

namespace
{
    void printL1(GetQuoteResponse resp)
    {
        std::unique_lock<std::recursive_mutex> lock(testStremingMutex);
        std::cout << "Stream L1 Quote (" << resp.getAsyncRequestId() << "): " << std::endl << resp.dumpToJson() 
            << std::endl << "RequestID " << resp.getAsyncRequestId() << " : " << resp.getErrorMessage() << std::endl;
    }

    void printL1Options(GetOptionQuotesResponse resp)
    {
        std::unique_lock<std::recursive_mutex> lock(testStremingMutex);
        std::cout << "Stream L1 Option Quotes (" << resp.getAsyncRequestId() << "): " << std::endl << (resp.getOptionQuotes().empty() ? resp.dumpToJson() : resp.getOptionQuotes().front().dumpToJson()) 
            << std::endl << "RequestID " << resp.getAsyncRequestId() << " : " << resp.getErrorMessage() << std::endl;
    }

    void printL1Strategy(GetStrategyQuoteResponse resp)
    {
        std::unique_lock<std::recursive_mutex> lock(testStremingMutex);
        std::cout << "Stream L1 Strategy Quote (" << resp.getAsyncRequestId() << "): " << std::endl << resp.dumpToJson() 
            << std::endl << "RequestID " << resp.getAsyncRequestId() << " : " << resp.getErrorMessage() << std::endl;
    }
}


void TestStream(AuthenticationInfo authInfo)
{
    // First few calls to prepare data

    auto symbolsResp = SearchSymbols(authInfo, "MSFT", 0);
    auto symbols = symbolsResp.getSymbols();
    if (symbols.empty())
    {
        std::cerr << "Error getting symbols " << symbolsResp.getErrorCode() << std::endl << symbolsResp.getErrorMessage() << std::endl;
        return;
    }
    std::vector<uint64> symIdVec;
    for (auto it = symbols.begin(); it != symbols.end(); ++it)
    {
        symIdVec.push_back(it->getSymbolId());
    }

    GetQuoteStream(authInfo, printL1, 0, symIdVec);
    
    auto optionsResp = GetOptions(authInfo, symbols.front().getSymbolId());

    if (optionsResp.getOptionChain().empty())
    {
        std::cerr << "Option chain not found for MSFT" << std::endl;
    }
    else
    {
        DateTime expiry(optionsResp.getOptionChain().front().getExpiryDate());
        std::vector<OptionIdFilter> filters;
        filters.push_back(OptionIdFilter(symbols.front().getSymbolId(), expiry));
        filters.back().m_optionType = OptionType::Call;

        GetOptionQuotesStream(authInfo, printL1Options, 1, filters);

        std::vector<StrategyVariantRequest> variants;
        std::vector<StrategyVariantLeg> legs;

        legs.push_back(StrategyVariantLeg(symbols.front().getSymbolId(), 100, OrderAction::Buy));
        legs.push_back(StrategyVariantLeg(optionsResp.getOptionChain().front().getChainPerRoot().front().getChainPerStrikePrice().front().getCallSymbolId(), 1, OrderAction::Sell));

        variants.push_back(StrategyVariantRequest(1,legs));

        GetStrategyQuoteStream(authInfo, printL1Strategy, 2, variants);
    }
    
    Sleep(30000);

    StopGetQuoteStream(authInfo);

    Sleep(10000);

    StopGetOptionQuotesStream(authInfo);

    Sleep(10000);

    StopGetStrategyQuoteStream(authInfo);
}
