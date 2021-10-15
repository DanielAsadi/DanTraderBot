/********************************************************************
 * Declaration of OrderAndExecutionNotifications.
 *
 * OrderAndExecutionNotifications - Push execution notification
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_ORDERANDEXECUTIONNOTIFICATIONS_H
#define QUESTRADEAPI_ORDERANDEXECUTIONNOTIFICATIONS_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class OrderAndExecutionNotificationsResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::OrderAndExecutionNotificationsResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief OrderAndExecutionNotifications Response structure
struct QUESTRADELIBRARYAPI OrderAndExecutionNotificationsResponse
{
public:
    /// Resulting array of OrderData
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<OrderData>      getOrders() const;
    /// Resulting array of ExecutionData
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<ExecutionData>  getExecutions() const;
    /// Resulting account number
    std::string                 getAccountNumber() const;

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
    /// Return async request Id that was passed to BeginOrderAndExecutionNotifications function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    OrderAndExecutionNotificationsResponse();

private:
    typedef OrderAndExecutionNotificationsResponseImplementation Impl;

    OrderAndExecutionNotificationsResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class OrderAndExecutionNotificationsResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::OrderAndExecutionNotificationsResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Stream of OrderAndExecutionNotifications
QUESTRADELIBRARYAPI int APIENTRY OrderAndExecutionNotificationsStream(AuthenticationInfo& authInfo,
                                                std::function<void(OrderAndExecutionNotificationsResponse)> callback,
                                                int32 requestId);

/// @ingroup services
/// Stops streaming of OrderAndExecutionNotifications if it is currently running (does nothing otherwise)
QUESTRADELIBRARYAPI int APIENTRY StopOrderAndExecutionNotificationsStream(AuthenticationInfo& authInfo);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_ORDERANDEXECUTIONNOTIFICATIONS_H
