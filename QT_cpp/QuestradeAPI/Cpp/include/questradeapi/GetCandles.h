/********************************************************************
 * Declaration of GetCandles.
 *
 * GetCandles - Get historical candles for the symbol
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETCANDLES_H
#define QUESTRADEAPI_GETCANDLES_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetCandlesResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetCandlesResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetCandles Response structure
struct QUESTRADELIBRARYAPI GetCandlesResponse
{
public:
    /// Array of candles
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<CandleData>     getCandles() const;

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
    /// Return async request Id that was passed to BeginGetCandles function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetCandlesResponse();

private:
    typedef GetCandlesResponseImplementation Impl;

    GetCandlesResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetCandlesResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetCandlesResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Get historical candles for the symbol
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// symbolId - The symbol ID
///
/// startTime - The start time
///
/// endTime - The end time
///
/// interval - The interval
QUESTRADELIBRARYAPI GetCandlesResponse APIENTRY GetCandles(AuthenticationInfo& authInfo,
                                                uint64 symbolId,
                                                const DateTime& startTime,
                                                const DateTime& endTime,
                                                CandlesGranularity::Value interval);

/// @ingroup services
/// Asynchronous execution of GetCandles
QUESTRADELIBRARYAPI int APIENTRY GetCandlesAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetCandlesResponse)> callback,
                                                int32 requestId,
                                                uint64 symbolId,
                                                const DateTime& startTime,
                                                const DateTime& endTime,
                                                CandlesGranularity::Value interval);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETCANDLES_H
