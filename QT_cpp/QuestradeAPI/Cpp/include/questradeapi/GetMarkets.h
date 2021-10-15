/********************************************************************
 * Declaration of GetMarkets.
 *
 * GetMarkets - Returns listings exchange info
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETMARKETS_H
#define QUESTRADEAPI_GETMARKETS_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetMarketsResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetMarketsResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetMarkets Response structure
struct QUESTRADELIBRARYAPI GetMarketsResponse
{
public:
    /// Array of listing exchanges
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<Market>         getMarkets() const;

    /// Returns whether request was successful
    bool isValid() const;
    /// Returns particular error code in case of unsuccessful request
    int32 getErrorCode() const;
    /// Returns error message text in case of unsuccessful request
    std::string getErrorMessage() const;
    /// Returns rate limit reset time after this request
    DateTime getRateLimitReset() const;
    /// Returns rate limit remaining after this request
    int32 getRateLimitRemaining() const;
    /// Return async request Id that was passed to BeginGetMarkets function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetMarketsResponse();

private:
    typedef GetMarketsResponseImplementation Impl;

    GetMarketsResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetMarketsResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetMarketsResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns listings exchange info
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI GetMarketsResponse APIENTRY GetMarkets(AuthenticationInfo& authInfo);

/// @ingroup services
/// Asynchronous execution of GetMarkets
QUESTRADELIBRARYAPI int APIENTRY GetMarketsAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetMarketsResponse)> callback,
                                                int32 requestId);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETMARKETS_H
