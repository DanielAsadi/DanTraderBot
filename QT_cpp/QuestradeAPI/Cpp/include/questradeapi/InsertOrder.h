/********************************************************************
 * Declaration of InsertOrder.
 *
 * InsertOrder - Insert order
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_INSERTORDER_H
#define QUESTRADEAPI_INSERTORDER_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class InsertOrderResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::InsertOrderResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief InsertOrder Response structure
struct QUESTRADELIBRARYAPI InsertOrderResponse
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
    /// Return async request Id that was passed to BeginInsertOrder function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    InsertOrderResponse();

private:
    typedef InsertOrderResponseImplementation Impl;

    InsertOrderResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class InsertOrderResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::InsertOrderResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Insert order
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI InsertOrderResponse APIENTRY InsertOrder(AuthenticationInfo& authInfo,
                                                InsertOrderRequest request);

/// @ingroup services
/// Asynchronous execution of InsertOrder
QUESTRADELIBRARYAPI int APIENTRY InsertOrderAsync(AuthenticationInfo& authInfo,
                                                std::function<void(InsertOrderResponse)> callback,
                                                int32 requestId,
                                                InsertOrderRequest request);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_INSERTORDER_H
