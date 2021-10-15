/********************************************************************
 * Main file for test console which runs all the examples
 *
 * Copyright (C) 2015 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Apr 05 18:47:47 2015
 *******************************************************************/

#include <iostream>
#include <thread>
    
#include "AuthenticationTokenHandler.h"
#include "ApiTestDefines.h"

using namespace QuestradeAPI;

int runTest()
{
    AuthenticationTokenHandler authHandler;

    char action = ' ';
    do
    {
        while (!authHandler.m_info.isValid())
        {
            std::cout << "Authentication is invalid. Please specify a new refresh token." << std::endl;
            authHandler = AuthenticationTokenHandler();
        }
        std::cout << std::endl << "Choose scenario." << std::endl
                  << "'1' - for getServerTime test" << std::endl
                  << "'2' - for Market Data tests" << std::endl
                  << "'3' - for Orders test (new orders will be inserted in practice accounts only)" << std::endl
                  << "'4' - for Account Info test (for best demonstration better to have some order and positions)" << std::endl
                  << "'5' - for Async calls test" << std::endl
                  << "'6' - for Stream test" << std::endl
                  << "'e' - for exit" << std::endl;
        std::cout.flush();
        std::string line("");
        std::getline(std::cin, line);
        action = line[0];
        std::cout << std::endl;
        switch(action)
        {
        case '1':
            TestTime(authHandler.m_info);
            continue;
        case '2':
            TestMarketData(authHandler.m_info);
            continue;
        case '3':
            TestOrders(authHandler.m_info);
            continue;
        case '4':
            testAccountInfo(authHandler.m_info);
            continue;
        case '5':
            TestAsync(authHandler.m_info);
            continue;
        case '6':
            TestStream(authHandler.m_info);
            continue;
        default:
            continue;
        }
    } while (action != 'e' && action != 'E');

    return 0;
}

int main(int argc, char* argv[])
{
    Init();

    // Is done threaded to demonstrate recommended multithreaded handling.
    std::thread th = std::thread(runTest);
    th.join();
    
    UnInit();
    
    return 0;
}

