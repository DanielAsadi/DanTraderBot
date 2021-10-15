/********************************************************************
 * Declaration of ReplaceStrategyOrder.
 *
 * ReplaceStrategyOrder - Replace multileg order
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_REPLACESTRATEGYORDER_H
#define QUESTRADEAPI_REPLACESTRATEGYORDER_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class ReplaceStrategyOrderResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::ReplaceStrategyOrderResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief ReplaceStrategyOrder Response structure
struct QUESTRADELIBRARYAPI ReplaceStrategyOrderResponse
{
public:
    /// Resulting order ID
    uint64                      getOrderId() const;
    /// Orders that were changed and created after request
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<OrderData>      getOrders() const;

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
    /// Return async request Id that was passed to BeginReplaceStrategyOrder function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    ReplaceStrategyOrderResponse();

private:
    typedef ReplaceStrategyOrderResponseImplementation Impl;

    ReplaceStrategyOrderResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class ReplaceStrategyOrderResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::ReplaceStrategyOrderResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Replace multileg order
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI ReplaceStrategyOrderResponse APIENTRY ReplaceStrategyOrder(AuthenticationInfo& authInfo,
                                                ReplaceStrategyOrderRequest request);

/// @ingroup services
/// Asynchronous execution of ReplaceStrategyOrder
QUESTRADELIBRARYAPI int APIENTRY ReplaceStrategyOrderAsync(AuthenticationInfo& authInfo,
                                                std::function<void(ReplaceStrategyOrderResponse)> callback,
                                                int32 requestId,
                                                ReplaceStrategyOrderRequest request);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_REPLACESTRATEGYORDER_H
