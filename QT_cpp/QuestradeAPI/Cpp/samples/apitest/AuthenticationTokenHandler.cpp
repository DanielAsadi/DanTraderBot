/********************************************************************
 * Authentication Token Handler definition
 * Gives example on how AuthenticationInfo may be used
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.0.0
 * Creation Date:  Wed Oct 22 18:47:47 2014
 *******************************************************************/

#include <iostream>

#include "ApiTestDefines.h"
#include "AuthenticationTokenHandler.h"

using namespace QuestradeAPI;

AuthenticationTokenHandler::AuthenticationTokenHandler()
{
    std::string refreshToken;
    std::string demoStr;

    // This example reads authentication data fron cin
    std::cout << "Enter Refresh Token: ";
    std::getline(std::cin, refreshToken);
    std::cout << "Is it practice account y/n: ";
    std::getline(std::cin, demoStr);
    bool isDemo = (demoStr[0] == 'n' || demoStr[0] == 'N' ? false : true);

    m_info = Authenticate(refreshToken, isDemo);
}

AuthenticationTokenHandler::~AuthenticationTokenHandler()
{
    // It doesn't make sense to dump new refresh token in the middle of the execution
    // Because if you make request not very often it might change a few times
    // So dump it only when you stop using QuestradeAPI library
    // Or don't dump at all (but then you would have to generate a new refresh token each time you restart)
    if (m_info.isValid())
    {
        std::cout << "New generated token (you may save copy of it for future use): " << std::endl << m_info.getRefreshToken() << std::endl;
        std::cout << "Press Enter to continue..." << std::endl;
        while (std::getchar() != '\n') continue;
    }
}