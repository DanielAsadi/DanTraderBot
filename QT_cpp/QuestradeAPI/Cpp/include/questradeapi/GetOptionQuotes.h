/********************************************************************
 * Declaration of GetOptionQuotes.
 *
 * GetOptionQuotes - Returns L1 and Greeks data for options, based on filters and IDs
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETOPTIONQUOTES_H
#define QUESTRADEAPI_GETOPTIONQUOTES_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetOptionQuotesResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetOptionQuotesResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetOptionQuotes Response structure
struct QUESTRADELIBRARYAPI GetOptionQuotesResponse
{
public:
    /// Result L1 options data
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<Level1OptionData> getOptionQuotes() const;

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
    /// Return async request Id that was passed to BeginGetOptionQuotes function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetOptionQuotesResponse();

private:
    typedef GetOptionQuotesResponseImplementation Impl;

    GetOptionQuotesResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetOptionQuotesResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetOptionQuotesResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns L1 and Greeks data for options, based on filters and IDs
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// filters - Input array of OptionIdFilter structures
///
/// optionIds - Input array of option IDs
QUESTRADELIBRARYAPI GetOptionQuotesResponse APIENTRY GetOptionQuotes(AuthenticationInfo& authInfo,
                                                const std::vector<OptionIdFilter>& filters = std::vector<OptionIdFilter>(),
                                                const std::vector<uint64>& optionIds = std::vector<uint64>());

/// @ingroup services
/// Asynchronous execution of GetOptionQuotes
QUESTRADELIBRARYAPI int APIENTRY GetOptionQuotesAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetOptionQuotesResponse)> callback,
                                                int32 requestId,
                                                const std::vector<OptionIdFilter>& filters = std::vector<OptionIdFilter>(),
                                                const std::vector<uint64>& optionIds = std::vector<uint64>());


/// @ingroup services
/// Stream of GetOptionQuotes
QUESTRADELIBRARYAPI int APIENTRY GetOptionQuotesStream(AuthenticationInfo& authInfo,
                                                std::function<void(GetOptionQuotesResponse)> callback,
                                                int32 requestId,
                                                const std::vector<OptionIdFilter>& filters = std::vector<OptionIdFilter>(),
                                                const std::vector<uint64>& optionIds = std::vector<uint64>());

/// @ingroup services
/// Stops streaming of GetOptionQuotes if it is currently running (does nothing otherwise)
QUESTRADELIBRARYAPI int APIENTRY StopGetOptionQuotesStream(AuthenticationInfo& authInfo);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETOPTIONQUOTES_H
