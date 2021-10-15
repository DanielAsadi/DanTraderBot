/********************************************************************
 * Declaration of GetOptions.
 *
 * GetOptions - Returns option chain for the underlying symbol
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETOPTIONS_H
#define QUESTRADEAPI_GETOPTIONS_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetOptionsResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetOptionsResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetOptions Response structure
struct QUESTRADELIBRARYAPI GetOptionsResponse
{
public:
    /// Option chain for the underlying symbol
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<ChainPerExpiryDate> getOptionChain() const;

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
    /// Return async request Id that was passed to BeginGetOptions function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetOptionsResponse();

private:
    typedef GetOptionsResponseImplementation Impl;

    GetOptionsResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetOptionsResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetOptionsResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns option chain for the underlying symbol
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// symbolId - The symbol ID
QUESTRADELIBRARYAPI GetOptionsResponse APIENTRY GetOptions(AuthenticationInfo& authInfo,
                                                uint64 symbolId);

/// @ingroup services
/// Asynchronous execution of GetOptions
QUESTRADELIBRARYAPI int APIENTRY GetOptionsAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetOptionsResponse)> callback,
                                                int32 requestId,
                                                uint64 symbolId);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETOPTIONS_H
