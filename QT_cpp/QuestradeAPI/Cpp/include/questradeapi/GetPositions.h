/********************************************************************
 * Declaration of GetPositions.
 *
 * GetPositions - Returns account positions
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETPOSITIONS_H
#define QUESTRADEAPI_GETPOSITIONS_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetPositionsResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetPositionsResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetPositions Response structure
struct QUESTRADELIBRARYAPI GetPositionsResponse
{
public:
    /// Resulting array of position data
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<PositionData>   getPositions() const;

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
    /// Return async request Id that was passed to BeginGetPositions function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetPositionsResponse();

private:
    typedef GetPositionsResponseImplementation Impl;

    GetPositionsResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetPositionsResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetPositionsResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns account positions
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// accountNumber - Account number
QUESTRADELIBRARYAPI GetPositionsResponse APIENTRY GetPositions(AuthenticationInfo& authInfo,
                                                const std::string& accountNumber);

/// @ingroup services
/// Asynchronous execution of GetPositions
QUESTRADELIBRARYAPI int APIENTRY GetPositionsAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetPositionsResponse)> callback,
                                                int32 requestId,
                                                const std::string& accountNumber);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETPOSITIONS_H
