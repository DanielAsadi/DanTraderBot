/********************************************************************
 * Declaration of GetOrders.
 *
 * GetOrders - Returns account orders
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETORDERS_H
#define QUESTRADEAPI_GETORDERS_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetOrdersResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetOrdersResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetOrders Response structure
struct QUESTRADELIBRARYAPI GetOrdersResponse
{
public:
    /// Array of Order Data
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
    /// Return async request Id that was passed to BeginGetOrders function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetOrdersResponse();

private:
    typedef GetOrdersResponseImplementation Impl;

    GetOrdersResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetOrdersResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetOrdersResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns account orders
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - The account number
///
/// stateFilter - The state of the orders to return
///
/// startTime - The start time of the interval which to return orders for
///
/// endTime - The end time of the interval which to return orders for
QUESTRADELIBRARYAPI GetOrdersResponse APIENTRY GetOrders(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber,
                                                OrderStateFilterTypes::Value stateFilter = OrderStateFilterTypes::All,
                                                const DateTime& startTime = DateTime::startOfDay(),
                                                const DateTime& endTime = DateTime());

/// @ingroup services
/// Asynchronous execution of GetOrders
QUESTRADELIBRARYAPI int APIENTRY GetOrdersAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetOrdersResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber,
                                                OrderStateFilterTypes::Value stateFilter = OrderStateFilterTypes::All,
                                                const DateTime& startTime = DateTime::startOfDay(),
                                                const DateTime& endTime = DateTime());

/// @ingroup services
/// Returns orders by ids
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - The account number
///
/// ids - Input array of order IDs
QUESTRADELIBRARYAPI GetOrdersResponse APIENTRY GetOrdersByID(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber,
                                                const std::vector<uint64>& ids);

/// @ingroup services
/// Asynchronous execution of GetOrdersByID
QUESTRADELIBRARYAPI int APIENTRY GetOrdersByIDAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetOrdersResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber,
                                                const std::vector<uint64>& ids);

} // namespace QuestradeAPI

#endif // QUESTRADEAPI_GETORDERS_H
