/********************************************************************
 * Declaration of InsertBracketOrder.
 *
 * InsertBracketOrder - Insert bracket order
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_INSERTBRACKETORDER_H
#define QUESTRADEAPI_INSERTBRACKETORDER_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class InsertBracketOrderResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::InsertBracketOrderResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief InsertBracketOrder Response structure
struct QUESTRADELIBRARYAPI InsertBracketOrderResponse
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
    /// Return async request Id that was passed to BeginInsertBracketOrder function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    InsertBracketOrderResponse();

private:
    typedef InsertBracketOrderResponseImplementation Impl;

    InsertBracketOrderResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class InsertBracketOrderResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::InsertBracketOrderResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Insert bracket order
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - The account number
///
/// symbolId - The symbol ID
///
/// primaryRoute - The primary route
///
/// components - List of bracket order components
///
/// secondaryRoute - The secondary route
QUESTRADELIBRARYAPI InsertBracketOrderResponse APIENTRY InsertBracketOrder(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber,
                                                uint64 symbolId,
                                                const std::string& primaryRoute,
                                                const std::vector<BracketOrderComponent>& components,
                                                const std::string& secondaryRoute = "AUTO");

/// @ingroup services
/// Asynchronous execution of InsertBracketOrder
QUESTRADELIBRARYAPI int APIENTRY InsertBracketOrderAsync(AuthenticationInfo& authInfo,
                                                std::function<void(InsertBracketOrderResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber,
                                                uint64 symbolId,
                                                const std::string& primaryRoute,
                                                const std::vector<BracketOrderComponent>& components,
                                                const std::string& secondaryRoute = "AUTO");

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_INSERTBRACKETORDER_H
