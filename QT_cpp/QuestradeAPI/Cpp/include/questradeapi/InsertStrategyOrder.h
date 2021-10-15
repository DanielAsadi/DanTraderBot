/********************************************************************
 * Declaration of InsertStrategyOrder.
 *
 * InsertStrategyOrder - Insert multileg order
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_INSERTSTRATEGYORDER_H
#define QUESTRADEAPI_INSERTSTRATEGYORDER_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class InsertStrategyOrderResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::InsertStrategyOrderResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief InsertStrategyOrder Response structure
struct QUESTRADELIBRARYAPI InsertStrategyOrderResponse
{
public:
    /// The ID of the new order
    uint64                      getOrderId() const;
    /// Orders that were created after request
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
    /// Return async request Id that was passed to BeginInsertStrategyOrder function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    InsertStrategyOrderResponse();

private:
    typedef InsertStrategyOrderResponseImplementation Impl;

    InsertStrategyOrderResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class InsertStrategyOrderResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::InsertStrategyOrderResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Insert multileg order
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI InsertStrategyOrderResponse APIENTRY InsertStrategyOrder(AuthenticationInfo& authInfo,
                                                InsertStrategyOrderRequest request);

/// @ingroup services
/// Asynchronous execution of InsertStrategyOrder
QUESTRADELIBRARYAPI int APIENTRY InsertStrategyOrderAsync(AuthenticationInfo& authInfo,
                                                std::function<void(InsertStrategyOrderResponse)> callback,
                                                int32 requestId,
                                                InsertStrategyOrderRequest request);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_INSERTSTRATEGYORDER_H
