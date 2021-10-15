/********************************************************************
 * Declaration of GetServerTime.
 *
 * GetServerTime - Returns server time
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETSERVERTIME_H
#define QUESTRADEAPI_GETSERVERTIME_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetServerTimeResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetServerTimeResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetServerTime Response structure
struct QUESTRADELIBRARYAPI GetServerTimeResponse
{
public:
    /// Current server time
    DateTime                    getTime() const;

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
    /// Return async request Id that was passed to BeginGetServerTime function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetServerTimeResponse();

private:
    typedef GetServerTimeResponseImplementation Impl;

    GetServerTimeResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetServerTimeResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetServerTimeResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns server time
///
/// authInfo - AuthenticationInfo object with which this service should be called.
QUESTRADELIBRARYAPI GetServerTimeResponse APIENTRY GetServerTime(AuthenticationInfo& authInfo);

/// @ingroup services
/// Asynchronous execution of GetServerTime
QUESTRADELIBRARYAPI int APIENTRY GetServerTimeAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetServerTimeResponse)> callback,
                                                int32 requestId);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETSERVERTIME_H
