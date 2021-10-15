/********************************************************************
 * Declaration of BracketOrderImpact.
 *
 * BracketOrderImpact - Bracket Order Impact
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_BRACKETORDERIMPACT_H
#define QUESTRADEAPI_BRACKETORDERIMPACT_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class BracketOrderImpactResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::BracketOrderImpactResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief BracketOrderImpact Response structure
struct QUESTRADELIBRARYAPI BracketOrderImpactResponse
{
public:
    /// The estimated commissions
    double                      getEstimatedCommissions() const;
    /// The buying power effect
    double                      getBuyingPowerEffect() const;
    /// The buying power result
    double                      getBuyingPowerResult() const;
    /// The maintenance excess effect
    double                      getMaintExcessEffect() const;
    /// The maintenance excess result
    double                      getMaintExcessResult() const;
    /// Resulting side of the order
    OrderSide::Value            getSide() const;
    /// The trade value calculation
    std::string                 getTradeValueCalculation() const;
    /// Estimated price of execution
    double                      getPrice() const;

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
    /// Return async request Id that was passed to BeginBracketOrderImpact function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    BracketOrderImpactResponse();

private:
    typedef BracketOrderImpactResponseImplementation Impl;

    BracketOrderImpactResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class BracketOrderImpactResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::BracketOrderImpactResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Bracket Order Impact
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - The account number
///
/// symbolId - The symbol ID
///
/// primaryRoute - The primary route
///
/// components - List of bracket order components
///
/// secondaryRoute - The secondary route
QUESTRADELIBRARYAPI BracketOrderImpactResponse APIENTRY BracketOrderImpact(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber,
                                                uint64 symbolId,
                                                const std::string& primaryRoute,
                                                const std::vector<BracketOrderComponent>& components,
                                                const std::string& secondaryRoute = "AUTO");

/// @ingroup services
/// Asynchronous execution of BracketOrderImpact
QUESTRADELIBRARYAPI int APIENTRY BracketOrderImpactAsync(AuthenticationInfo& authInfo,
                                                std::function<void(BracketOrderImpactResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber,
                                                uint64 symbolId,
                                                const std::string& primaryRoute,
                                                const std::vector<BracketOrderComponent>& components,
                                                const std::string& secondaryRoute = "AUTO");

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_BRACKETORDERIMPACT_H
