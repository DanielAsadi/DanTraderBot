/********************************************************************
 * Authentication Token Handler declaration
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.0.0
 * Creation Date:  Wed Oct 22 18:47:47 2014
 *******************************************************************/

#ifndef AUTHENTICATION_TOKEN_HANDLER_H
#define AUTHENTICATION_TOKEN_HANDLER_H

#include "questradeapi/Authentication.h"

// Example of class that handles authentication
class AuthenticationTokenHandler
{
public:
    AuthenticationTokenHandler();

    ~AuthenticationTokenHandler();

    QuestradeAPI::AuthenticationInfo m_info;
};

#endif //AUTHENTICATION_TOKEN_HANDLER_H
