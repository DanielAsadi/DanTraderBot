/********************************************************************
 * Declaration of CancelOrder.
 *
 * CancelOrder - Cancel order
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_CANCELORDER_H
#define QUESTRADEAPI_CANCELORDER_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class CancelOrderResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::CancelOrderResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief CancelOrder Response structure
struct QUESTRADELIBRARYAPI CancelOrderResponse
{
public:
    /// Resulting Order ID
    uint64                      getOrderId() const;

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
    /// Return async request Id that was passed to BeginCancelOrder function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    CancelOrderResponse();

private:
    typedef CancelOrderResponseImplementation Impl;

    CancelOrderResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class CancelOrderResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::CancelOrderResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Cancel order
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - Account number
///
/// orderId - Order ID
QUESTRADELIBRARYAPI CancelOrderResponse APIENTRY CancelOrder(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber,
                                                uint64 orderId);

/// @ingroup services
/// Asynchronous execution of CancelOrder
QUESTRADELIBRARYAPI int APIENTRY CancelOrderAsync(AuthenticationInfo& authInfo,
                                                std::function<void(CancelOrderResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber,
                                                uint64 orderId);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_CANCELORDER_H
