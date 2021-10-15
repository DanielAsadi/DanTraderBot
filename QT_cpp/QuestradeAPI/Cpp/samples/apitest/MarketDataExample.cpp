/********************************************************************
 * Example for getting Market Data
 *
 * Copyright (C) 2015 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Apr 05 18:47:47 2015
 *******************************************************************/

#include <iostream>

#include "questradeapi/GetQuote.h"
#include "questradeapi/SearchSymbols.h"
#include "questradeapi/GetCandles.h"
#include "questradeapi/GetSymbols.h"
#include "questradeapi/GetOptions.h"
#include "ApiTestDefines.h"

using namespace QuestradeAPI;


void TestMarketData(AuthenticationInfo authInfo)
{
    // Find couple of symbols to get market data
    auto symbolsResp = SearchSymbols(authInfo, "MSFT", 0);
    std::cout << symbolsResp.dumpToJson() << std::endl << std::endl;

    auto symbols = symbolsResp.getSymbols();

    if (symbols.empty())
    {
        std::cerr << "Error getting symbols " << symbolsResp.getErrorCode() << std::endl << symbolsResp.getErrorMessage() << std::endl;
        return;
    }

    // Symbol ID vector for later use
    std::vector<uint64> symIdVec;
    for (auto it = symbols.begin(); it != symbols.end(); ++it)
    {
        symIdVec.push_back(it->getSymbolId());
    }

    Sleep(2000);

    // Lets extract some options
    auto options = GetOptions(authInfo, symbols.at(0).getSymbolId());
    auto chain = options.getOptionChain();

    if (! chain.empty())
    {
        auto chainPerExpiryElem = chain.at(0);
        // There may be many roots, because of adjusted options, mini options etc
        auto chainPerRootElem = chainPerExpiryElem.getChainPerRoot().at(0);
        auto chainPerStrikeElem = chainPerRootElem.getChainPerStrikePrice().at(0);
        
        std::cout << "Expiry Date: " << chainPerExpiryElem.getExpiryDate().toIsoString() << std::endl
                  << "Option Root: " << chainPerRootElem.getOptionRoot() << std::endl
                  << "Option Strike: " << chainPerStrikeElem.getStrikePrice() << std::endl
                  << "Call Symbol ID: " << chainPerStrikeElem.getCallSymbolId() << std::endl
                  << "Put Symbol ID: " << chainPerStrikeElem.getPutSymbolId() << std::endl << std::endl;
        // Lets put this options into vector as well
        symIdVec.push_back(chainPerStrikeElem.getCallSymbolId());
        symIdVec.push_back(chainPerStrikeElem.getPutSymbolId());
    }
    else
    {
        std::cout << "No options were extracted, error code: " << options.getErrorCode() << std::endl << options.getErrorMessage() << std::endl;
    }

    Sleep(2000);

    // Get L1 Quotes
    auto l1Resp = GetQuote(authInfo, symIdVec);
    auto l1Vec = l1Resp.getQuotes();

    if (!l1Vec.empty())
    {
        // Print only first one not to have too many stuff in the output
        // Actually you will get all 4
        std::cout << l1Vec.at(0).dumpToJson() << std::endl << std::endl;
    }
    else
    {
        std::cout << "No L1 data returned. Error Code: " << l1Resp.getErrorCode() << std::endl << l1Resp.getErrorMessage() << std::endl << std::endl;
    }
    
    Sleep(2000);

    auto symbolData = GetSymbols(authInfo, symIdVec);
    auto symbolDataVec = symbolData.getSymbols();
    if (!symbolDataVec.empty())
    {
        // Stocks and options have slightly different fields filled out, so both are present as example output.

        // Should be stock
        std::cout << symbolDataVec.front().dumpToJson() << std::endl  << std::endl;
        Sleep(2000);
        // Should be option
        std::cout << symbolDataVec.back().dumpToJson() << std::endl  << std::endl;
        Sleep(2000);
    }
    else
    {
        std::cout << "No Symbol data returned. Error Code: " << symbolData.getErrorCode() << std::endl << symbolData.getErrorMessage() << std::endl << std::endl;
    }
    
    Sleep(2000);

    // Candles for the first symbol (example with switch from EDT to EST)
    auto candles = GetCandles(authInfo, symbols[0].getSymbolId(), DateTime("2014-10-30T09:30:00-04:00"), DateTime("2014-11-04T16:00:00-05:00"), CandlesGranularity::OneDay);

    std::cout << candles.dumpToJson() << std::endl << std::endl;

    Sleep(2000);
}
