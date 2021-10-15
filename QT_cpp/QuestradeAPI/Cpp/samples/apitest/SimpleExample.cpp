/********************************************************************
 * Just a simple test that gets time and displays it 
 * next to current time on local machine clock
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.0.0
 * Creation Date:  Wed Oct 22 18:47:47 2014
 *******************************************************************/

#include <ctime>
#include <iostream>

#include "questradeapi/GetServerTime.h"

#include "ApiTestDefines.h"

using namespace QuestradeAPI;

void TestTime(AuthenticationInfo authInfo)
{
    time_t now = time(NULL);
    auto stime = GetServerTime(authInfo).getTime();
    std::cout << "Server Epoch Time: " << stime.toEpochTime() << " (" << stime.toIsoString() << ")" << std::endl
              << "Local Epoch Time: " << now << std::endl << std::endl;
}