/********************************************************************
 * Declaration of GetQuote.
 *
 * GetQuote - Returns L1 data
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETQUOTE_H
#define QUESTRADEAPI_GETQUOTE_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetQuoteResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetQuoteResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetQuote Response structure
struct QUESTRADELIBRARYAPI GetQuoteResponse
{
public:
    /// Array of quotes
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<Level1DataItem> getQuotes() const;

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
    /// Return async request Id that was passed to BeginGetQuote function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetQuoteResponse();

private:
    typedef GetQuoteResponseImplementation Impl;

    GetQuoteResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetQuoteResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetQuoteResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns L1 data
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// ids - Input array of symbol IDs
QUESTRADELIBRARYAPI GetQuoteResponse APIENTRY GetQuote(AuthenticationInfo& authInfo,
                                                const std::vector<uint64>& ids);

/// @ingroup services
/// Asynchronous execution of GetQuote
QUESTRADELIBRARYAPI int APIENTRY GetQuoteAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetQuoteResponse)> callback,
                                                int32 requestId,
                                                const std::vector<uint64>& ids);


/// @ingroup services
/// Stream of GetQuote
QUESTRADELIBRARYAPI int APIENTRY GetQuoteStream(AuthenticationInfo& authInfo,
                                                std::function<void(GetQuoteResponse)> callback,
                                                int32 requestId,
                                                const std::vector<uint64>& ids);

/// @ingroup services
/// Stops streaming of GetQuote if it is currently running (does nothing otherwise)
QUESTRADELIBRARYAPI int APIENTRY StopGetQuoteStream(AuthenticationInfo& authInfo);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETQUOTE_H
