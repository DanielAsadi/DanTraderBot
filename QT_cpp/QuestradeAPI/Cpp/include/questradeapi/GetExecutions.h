/********************************************************************
 * Declaration of GetExecutions.
 *
 * GetExecutions - Returns account executions
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETEXECUTIONS_H
#define QUESTRADEAPI_GETEXECUTIONS_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetExecutionsResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetExecutionsResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetExecutions Response structure
struct QUESTRADELIBRARYAPI GetExecutionsResponse
{
public:
    /// Array of executions
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<ExecutionData>  getExecutions() const;

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
    /// Return async request Id that was passed to BeginGetExecutions function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetExecutionsResponse();

private:
    typedef GetExecutionsResponseImplementation Impl;

    GetExecutionsResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetExecutionsResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetExecutionsResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns account executions
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - Account number
///
/// startTime - Start time
///
/// endTime - End time
QUESTRADELIBRARYAPI GetExecutionsResponse APIENTRY GetExecutions(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber,
                                                const DateTime& startTime = DateTime::startOfDay(),
                                                const DateTime& endTime = DateTime());

/// @ingroup services
/// Asynchronous execution of GetExecutions
QUESTRADELIBRARYAPI int APIENTRY GetExecutionsAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetExecutionsResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber,
                                                const DateTime& startTime = DateTime::startOfDay(),
                                                const DateTime& endTime = DateTime());

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETEXECUTIONS_H
