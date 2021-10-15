/********************************************************************
 * Example of Async calls
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.0.0
 * Creation Date:  Wed Oct 22 18:47:47 2014
 *******************************************************************/

#include <iostream>

#include "questradeapi/GetAccounts.h"
#include "questradeapi/GetOrders.h"
#include "questradeapi/GetQuote.h"
#include "questradeapi/SearchSymbols.h"

#include "questradeapi/GetServerTime.h"

#include "ApiTestDefines.h"

using namespace QuestradeAPI;


namespace
{
    void printGetOrders(GetOrdersResponse resp)
    {
        std::unique_lock<std::recursive_mutex> lock(testStremingMutex);
        std::cout << "Async Get Orders (" << resp.getAsyncRequestId() << "): " << resp.getOrders().size() << std::endl;
    }

    void printSymbols(SearchSymbolsResponse resp)
    {
        std::unique_lock<std::recursive_mutex> lock(testStremingMutex);
        std::cout << "Async Symbol Search (" << resp.getAsyncRequestId() << "): " << resp.getSymbols().size() << std::endl;
    }

    void printL1(GetQuoteResponse resp)
    {
        std::unique_lock<std::recursive_mutex> lock(testStremingMutex);
        std::cout << "Async L1 Quote (" << resp.getAsyncRequestId() << "): " << resp.getQuotes().size() << std::endl;
    }
}


void TestAsync(AuthenticationInfo authInfo)
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
    
    auto accounts = GetAccounts(authInfo);
    
    std::string primaryAcc;
    for (auto& acc : accounts.getAccounts())
    {
        if (acc.isPrimary())
        {
            primaryAcc = acc.getNumber();
        }
    }
    if (primaryAcc.empty())
    {
        std::cerr << "Error getting primary account " << accounts.getErrorCode() << std::endl << accounts.getErrorMessage() << std::endl;
        std::cerr << accounts.dumpToJson() << std::endl;
        return;
    }

    // All this calls will be simultaneous
    // The actual order of responses might be different
    GetOrdersAsync(authInfo, printGetOrders, 1, primaryAcc);
    GetQuoteAsync(authInfo, printL1, 2, symIdVec);
    SearchSymbolsAsync(authInfo, printSymbols, 3, "ABC", 0);
    
    Sleep(2000);
}
