/********************************************************************
 * Declaration of ReplaceBracketOrder.
 *
 * ReplaceBracketOrder - Replace bracket order
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_REPLACEBRACKETORDER_H
#define QUESTRADEAPI_REPLACEBRACKETORDER_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class ReplaceBracketOrderResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::ReplaceBracketOrderResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief ReplaceBracketOrder Response structure
struct QUESTRADELIBRARYAPI ReplaceBracketOrderResponse
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
    /// Return async request Id that was passed to BeginReplaceBracketOrder function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    ReplaceBracketOrderResponse();

private:
    typedef ReplaceBracketOrderResponseImplementation Impl;

    ReplaceBracketOrderResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class ReplaceBracketOrderResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::ReplaceBracketOrderResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Replace bracket order
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - The account number
///
/// components - Data for each bracket order component
QUESTRADELIBRARYAPI ReplaceBracketOrderResponse APIENTRY ReplaceBracketOrder(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber,
                                                const std::vector<BracketOrderComponent>& components);

/// @ingroup services
/// Asynchronous execution of ReplaceBracketOrder
QUESTRADELIBRARYAPI int APIENTRY ReplaceBracketOrderAsync(AuthenticationInfo& authInfo,
                                                std::function<void(ReplaceBracketOrderResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber,
                                                const std::vector<BracketOrderComponent>& components);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_REPLACEBRACKETORDER_H
