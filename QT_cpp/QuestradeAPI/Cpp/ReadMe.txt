INTRODUCTION
========================================================================
This SDK provides an easy-to-use client for the Questrade API, 
offering VC++ developers convenient access to our trading platform.

The SDK allows software application to execute trades directly through 
the Questrade REST API in your VC++ application. 

Following functional areas are covered:

 - Authentication
 - Account Data
 - Market Data
 - Placing Orders

Please refer to Developer Portal for additional information and services provided:
http://developer.questrade.com/


REQUIREMENTS
========================================================================
SDK requires Visual C++ 2012 re-distributable package from Microsoft 
and can be used for development of 32 bit applications only.
http://www.microsoft.com/en-ca/download/details.aspx?id=30679

As development environment Microsoft Visual Studio 2012 or higher is required.


FOLDER STRUCTURE
========================================================================
Bin 		- debug and release versions of QuestradeApi.dll
Include		- all Questrade C++ API SDK header files
Lib 		- lib files of QuestradeApi.dll for linking with Application
Samples 	- sample console project, to demonstrate functionality
Temp		- intermediate build files, after building sample application

ReferenceManual.pdf  -  Function/Class reference generated with Doxygen.

GETTING STARTED 
========================================================================
Step 1) Initialize the library

This is done by calling QuestradeAPI::Init()
It is recommended to call this function in the main thread or thread 
that creates other threads for the purpose of using QuestradeAPI.
Application must call Init before making any other function calls from QuestradeAPI library.

========================================================================
Step 2) Create an object of QuestradeAPI::AuthenticationInfo

Similar to web interface, pass the refresh_token as refreshToken. 
Also specify true if this is Practice account, or false for Live.

Validate the result of the call, by checking AutheticationInfo::isValid(). 
If this function returns false then token and/or consumer key was 
invalid or became invalid before this attempt.

========================================================================
Step 3) Once a valid AuthenticationInfo object is created

At this point, library is initialized and a session is established using provided key.
Application can start making calls to any of functions in API library to retrieve 
account data, market data, place trades, etc.

All API functions require always AuthenticationInfo object to be supplied, 
and generally have additional parameters.

Some calls might require parameters, such as:
 - Account Number is extracted from GetAccounts
 - Symbol ID is extracted from SearchSymbols or GetOptions
 - Primary and Secondary routes are extracted from GetMarkets
 - Order ID is extracted from any Response that has OrderData in it.

Asynchronous Calls
=====================================================================
Asynchronous method of calling API functions is supported. 

- In addition, functions expect callback function and requestId.

- On response, the callback function will be called in a new thread created 
specifically for this request and pass back the provided requestId.

- When callback function is called, application needs check resp.isValid().

If the result is false, a problem has occurred and application needs to 
check AuthetnticationInfo::isValid(), as session might have expired or been 
revoked by client.
In particular, user would need to obtain manually a new refresh token.

If AuthenticationInfo is valid, then application needs to check the error code 
and message in the response. 

Note: Error code and message may be still filled out even in valid responses.
These are cases of order being rejected due to business issues, etc.

========================================================================

Step 4) Application should un-initialize the library on completion
This is done by calling QuestradeAPI::UnInit(). 

