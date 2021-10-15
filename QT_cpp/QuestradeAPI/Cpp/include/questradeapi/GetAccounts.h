/********************************************************************
 * Declaration of GetAccounts.
 *
 * GetAccounts - Returns user accounts
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETACCOUNTS_H
#define QUESTRADEAPI_GETACCOUNTS_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetAccountsResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetAccountsResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetAccounts Response structure
struct QUESTRADELIBRARYAPI GetAccountsResponse
{
public:
    /// Array of account data
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<AccountData>    getAccounts() const;
    /// ID of the active user
    uint64                      getUserId() const;

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
    /// Return async request Id that was passed to BeginGetAccounts function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetAccountsResponse();

private:
    typedef GetAccountsResponseImplementation Impl;

    GetAccountsResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetAccountsResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetAccountsResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns user accounts
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI GetAccountsResponse APIENTRY GetAccounts(AuthenticationInfo& authInfo);

/// @ingroup services
/// Asynchronous execution of GetAccounts
QUESTRADELIBRARYAPI int APIENTRY GetAccountsAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetAccountsResponse)> callback,
                                                int32 requestId);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETACCOUNTS_H
