/********************************************************************
 * Declares all the functions that are used in examples
 *
 * Copyright (C) 2015 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Apr 05 18:47:47 2015
 *******************************************************************/

#ifndef API_TEST_DEFINES_H
#define API_TEST_DEFINES_H

#include "QuestradeAPI/Cpp/include/questradeapi/Authentication.h"
#include <mutex>

// Defined in SimpleExample.cpp
void TestTime(QuestradeAPI::AuthenticationInfo authInfo);

// Defined in AccountInfoExample.cpp
void testAccountInfo(QuestradeAPI::AuthenticationInfo authInfo);

// Defined in MarketDataExample.cpp
void TestMarketData(QuestradeAPI::AuthenticationInfo authInfo);

// Defined in OrdersExample.cpp
void TestOrders(QuestradeAPI::AuthenticationInfo authInfo);

// Defined in AsyncExample.cpp
void TestAsync(QuestradeAPI::AuthenticationInfo authInfo);

// Defined in StreamExample.cpp
void TestStream(QuestradeAPI::AuthenticationInfo authInfo);

extern std::recursive_mutex testStremingMutex;

#endif //API_TEST_DEFINES_H