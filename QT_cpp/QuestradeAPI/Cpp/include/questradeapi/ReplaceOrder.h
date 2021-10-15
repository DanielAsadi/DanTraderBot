/********************************************************************
 * Declaration of ReplaceOrder.
 *
 * ReplaceOrder - Replace order
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_REPLACEORDER_H
#define QUESTRADEAPI_REPLACEORDER_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class ReplaceOrderResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::ReplaceOrderResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief ReplaceOrder Response structure
struct QUESTRADELIBRARYAPI ReplaceOrderResponse
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
    /// Return async request Id that was passed to BeginReplaceOrder function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    ReplaceOrderResponse();

private:
    typedef ReplaceOrderResponseImplementation Impl;

    ReplaceOrderResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class ReplaceOrderResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::ReplaceOrderResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Replace order
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI ReplaceOrderResponse APIENTRY ReplaceOrder(AuthenticationInfo& authInfo,
                                                ReplaceOrderRequest request);

/// @ingroup services
/// Asynchronous execution of ReplaceOrder
QUESTRADELIBRARYAPI int APIENTRY ReplaceOrderAsync(AuthenticationInfo& authInfo,
                                                std::function<void(ReplaceOrderResponse)> callback,
                                                int32 requestId,
                                                ReplaceOrderRequest request);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_REPLACEORDER_H
