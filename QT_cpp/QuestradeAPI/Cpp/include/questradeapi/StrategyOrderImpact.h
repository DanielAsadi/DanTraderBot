/********************************************************************
 * Declaration of StrategyOrderImpact.
 *
 * StrategyOrderImpact - Estimates multi-leg order impact
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_STRATEGYORDERIMPACT_H
#define QUESTRADEAPI_STRATEGYORDERIMPACT_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class StrategyOrderImpactResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::StrategyOrderImpactResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief StrategyOrderImpact Response structure
struct QUESTRADELIBRARYAPI StrategyOrderImpactResponse
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
    /// The trade value calculation
    std::string                 getTradeValueCalculation() const;
    /// The resulting legs data
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<OrderLegData>   getLegs() const;
    /// The order side
    OrderAction::Value          getSide() const;
    /// The order effect
    OrderEffect::Value          getEffect() const;
    /// The price
    double                      getPrice() const;
    /// The actual order strategy
    StrategyType::Value         getStrategy() const;

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
    /// Return async request Id that was passed to BeginStrategyOrderImpact function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    StrategyOrderImpactResponse();

private:
    typedef StrategyOrderImpactResponseImplementation Impl;

    StrategyOrderImpactResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class StrategyOrderImpactResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::StrategyOrderImpactResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Estimates multi-leg order impact
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI StrategyOrderImpactResponse APIENTRY StrategyOrderImpact(AuthenticationInfo& authInfo,
                                                InsertStrategyOrderRequest request);

/// @ingroup services
/// Asynchronous execution of StrategyOrderImpact
QUESTRADELIBRARYAPI int APIENTRY StrategyOrderImpactAsync(AuthenticationInfo& authInfo,
                                                std::function<void(StrategyOrderImpactResponse)> callback,
                                                int32 requestId,
                                                InsertStrategyOrderRequest request);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_STRATEGYORDERIMPACT_H
