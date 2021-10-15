/********************************************************************
 * Declaration of InsertOrderImpact.
 *
 * InsertOrderImpact - Impact of inserting the order
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_INSERTORDERIMPACT_H
#define QUESTRADEAPI_INSERTORDERIMPACT_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class InsertOrderImpactResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::InsertOrderImpactResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief InsertOrderImpact Response structure
struct QUESTRADELIBRARYAPI InsertOrderImpactResponse
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
    /// Return async request Id that was passed to BeginInsertOrderImpact function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    InsertOrderImpactResponse();

private:
    typedef InsertOrderImpactResponseImplementation Impl;

    InsertOrderImpactResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class InsertOrderImpactResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::InsertOrderImpactResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Impact of inserting the order
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI InsertOrderImpactResponse APIENTRY InsertOrderImpact(AuthenticationInfo& authInfo,
                                                InsertOrderRequest request);

/// @ingroup services
/// Asynchronous execution of InsertOrderImpact
QUESTRADELIBRARYAPI int APIENTRY InsertOrderImpactAsync(AuthenticationInfo& authInfo,
                                                std::function<void(InsertOrderImpactResponse)> callback,
                                                int32 requestId,
                                                InsertOrderRequest request);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_INSERTORDERIMPACT_H
