/********************************************************************
 * Declaration of BracketReplaceImpact.
 *
 * BracketReplaceImpact - Bracket Replace impact
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_BRACKETREPLACEIMPACT_H
#define QUESTRADEAPI_BRACKETREPLACEIMPACT_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class BracketReplaceImpactResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::BracketReplaceImpactResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief BracketReplaceImpact Response structure
struct QUESTRADELIBRARYAPI BracketReplaceImpactResponse
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
    /// Return async request Id that was passed to BeginBracketReplaceImpact function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    BracketReplaceImpactResponse();

private:
    typedef BracketReplaceImpactResponseImplementation Impl;

    BracketReplaceImpactResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class BracketReplaceImpactResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::BracketReplaceImpactResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Bracket Replace impact
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - The account number
///
/// components - Data for each bracket order component
QUESTRADELIBRARYAPI BracketReplaceImpactResponse APIENTRY BracketReplaceImpact(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber,
                                                const std::vector<BracketOrderComponent>& components);

/// @ingroup services
/// Asynchronous execution of BracketReplaceImpact
QUESTRADELIBRARYAPI int APIENTRY BracketReplaceImpactAsync(AuthenticationInfo& authInfo,
                                                std::function<void(BracketReplaceImpactResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber,
                                                const std::vector<BracketOrderComponent>& components);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_BRACKETREPLACEIMPACT_H
