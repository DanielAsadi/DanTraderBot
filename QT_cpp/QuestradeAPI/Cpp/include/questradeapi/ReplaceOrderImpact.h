/********************************************************************
 * Declaration of ReplaceOrderImpact.
 *
 * ReplaceOrderImpact - Impact of replacing the order
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_REPLACEORDERIMPACT_H
#define QUESTRADEAPI_REPLACEORDERIMPACT_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class ReplaceOrderImpactResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::ReplaceOrderImpactResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief ReplaceOrderImpact Response structure
struct QUESTRADELIBRARYAPI ReplaceOrderImpactResponse
{
public:
    /// Resulting estimated commissions
    double                      getEstimatedCommissions() const;
    /// Resulting buying power effect
    double                      getBuyingPowerEffect() const;
    /// Resulting buying power result
    double                      getBuyingPowerResult() const;
    /// Resulting maintenance excess effect
    double                      getMaintExcessEffect() const;
    /// Resulting maintenance excess result
    double                      getMaintExcessResult() const;
    /// Resulting trade value calculation
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
    /// Return async request Id that was passed to BeginReplaceOrderImpact function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    ReplaceOrderImpactResponse();

private:
    typedef ReplaceOrderImpactResponseImplementation Impl;

    ReplaceOrderImpactResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class ReplaceOrderImpactResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::ReplaceOrderImpactResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Impact of replacing the order
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI ReplaceOrderImpactResponse APIENTRY ReplaceOrderImpact(AuthenticationInfo& authInfo,
                                                ReplaceOrderRequest request);

/// @ingroup services
/// Asynchronous execution of ReplaceOrderImpact
QUESTRADELIBRARYAPI int APIENTRY ReplaceOrderImpactAsync(AuthenticationInfo& authInfo,
                                                std::function<void(ReplaceOrderImpactResponse)> callback,
                                                int32 requestId,
                                                ReplaceOrderRequest request);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_REPLACEORDERIMPACT_H
