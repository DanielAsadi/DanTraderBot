/********************************************************************
 * Declaration of GetStrategyQuote.
 *
 * GetStrategyQuote - Get Greeks and L1 data for strategies
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETSTRATEGYQUOTE_H
#define QUESTRADEAPI_GETSTRATEGYQUOTE_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetStrategyQuoteResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetStrategyQuoteResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetStrategyQuote Response structure
struct QUESTRADELIBRARYAPI GetStrategyQuoteResponse
{
public:
    /// Result array of Strategy Option Quotes
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<Level1StrategyData> getStrategyQuotes() const;

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
    /// Return async request Id that was passed to BeginGetStrategyQuote function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetStrategyQuoteResponse();

private:
    typedef GetStrategyQuoteResponseImplementation Impl;

    GetStrategyQuoteResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetStrategyQuoteResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetStrategyQuoteResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Get Greeks and L1 data for strategies
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// variants - Input array of Strategy Variants
QUESTRADELIBRARYAPI GetStrategyQuoteResponse APIENTRY GetStrategyQuote(AuthenticationInfo& authInfo,
                                                const std::vector<StrategyVariantRequest>& variants);

/// @ingroup services
/// Asynchronous execution of GetStrategyQuote
QUESTRADELIBRARYAPI int APIENTRY GetStrategyQuoteAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetStrategyQuoteResponse)> callback,
                                                int32 requestId,
                                                const std::vector<StrategyVariantRequest>& variants);


/// @ingroup services
/// Stream of GetStrategyQuote
QUESTRADELIBRARYAPI int APIENTRY GetStrategyQuoteStream(AuthenticationInfo& authInfo,
                                                std::function<void(GetStrategyQuoteResponse)> callback,
                                                int32 requestId,
                                                const std::vector<StrategyVariantRequest>& variants);

/// @ingroup services
/// Stops streaming of GetStrategyQuote if it is currently running (does nothing otherwise)
QUESTRADELIBRARYAPI int APIENTRY StopGetStrategyQuoteStream(AuthenticationInfo& authInfo);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETSTRATEGYQUOTE_H
