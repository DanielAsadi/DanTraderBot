/********************************************************************
 * Declaration of GetSymbols.
 *
 * GetSymbols - Returns symbols data, if you want to get by names then ids must be empty
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_GETSYMBOLS_H
#define QUESTRADEAPI_GETSYMBOLS_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class GetSymbolsResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::GetSymbolsResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief GetSymbols Response structure
struct QUESTRADELIBRARYAPI GetSymbolsResponse
{
public:
    /// Array of symbol data
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<SymbolData>     getSymbols() const;

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
    /// Return async request Id that was passed to BeginGetSymbols function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    GetSymbolsResponse();

private:
    typedef GetSymbolsResponseImplementation Impl;

    GetSymbolsResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class GetSymbolsResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::GetSymbolsResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Returns symbols data, if you want to get by names then ids must be empty
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// ids - Input array of symbol IDs
///
/// names - Input array of symbol names
QUESTRADELIBRARYAPI GetSymbolsResponse APIENTRY GetSymbols(AuthenticationInfo& authInfo,
                                                const std::vector<uint64>& ids,
                                                const std::vector<std::string>& names = std::vector<std::string>());

/// @ingroup services
/// Asynchronous execution of GetSymbols
QUESTRADELIBRARYAPI int APIENTRY GetSymbolsAsync(AuthenticationInfo& authInfo,
                                                std::function<void(GetSymbolsResponse)> callback,
                                                int32 requestId,
                                                const std::vector<uint64>& ids,
                                                const std::vector<std::string>& names = std::vector<std::string>());

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_GETSYMBOLS_H
