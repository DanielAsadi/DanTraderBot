/********************************************************************
 * Declaration of GetAccountActivities.
 *
 * GetAccountActivities - Returns account orders
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETACCOUNTACTIVITIES_H
#define QUESTRADEAPI_GETACCOUNTACTIVITIES_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetAccountActivitiesResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetAccountActivitiesResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetAccountActivities Response structure
struct QUESTRADELIBRARYAPI GetAccountActivitiesResponse
{
public:
    /// Array of Order Data
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<AccountActivity> getActivities() const;

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
    /// Return async request Id that was passed to BeginGetAccountActivities function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetAccountActivitiesResponse();

private:
    typedef GetAccountActivitiesResponseImplementation Impl;

    GetAccountActivitiesResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetAccountActivitiesResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetAccountActivitiesResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns account orders
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - The account number
///
/// startTime - The start time of the interval which to return orders for
///
/// endTime - The end time of the interval which to return orders for
QUESTRADELIBRARYAPI GetAccountActivitiesResponse APIENTRY GetAccountActivities(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber,
                                                const DateTime& startTime,
                                                const DateTime& endTime = DateTime());

/// @ingroup services
/// Asynchronous execution of GetAccountActivities
QUESTRADELIBRARYAPI int APIENTRY GetAccountActivitiesAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetAccountActivitiesResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber,
                                                const DateTime& startTime,
                                                const DateTime& endTime = DateTime());

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETACCOUNTACTIVITIES_H
