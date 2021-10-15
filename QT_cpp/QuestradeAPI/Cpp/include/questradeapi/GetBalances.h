/********************************************************************
 * Declaration of GetBalances.
 *
 * GetBalances - GetBalance
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETBALANCES_H
#define QUESTRADEAPI_GETBALANCES_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetBalancesResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetBalancesResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetBalances Response structure
struct QUESTRADELIBRARYAPI GetBalancesResponse
{
public:
    /// Per-currency balances
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<BalanceData>    getPerCurrencyBalances() const;
    /// Combined balances
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<BalanceData>    getCombinedBalances() const;
    /// Start of Day per-currency balances
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<BalanceData>    getSodPerCurrencyBalances() const;
    /// Start of Day combined balances
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<BalanceData>    getSodCombinedBalances() const;

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
    /// Return async request Id that was passed to BeginGetBalances function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetBalancesResponse();

private:
    typedef GetBalancesResponseImplementation Impl;

    GetBalancesResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetBalancesResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetBalancesResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// GetBalance
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - Account number
QUESTRADELIBRARYAPI GetBalancesResponse APIENTRY GetBalances(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber);

/// @ingroup services
/// Asynchronous execution of GetBalances
QUESTRADELIBRARYAPI int APIENTRY GetBalancesAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetBalancesResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETBALANCES_H
