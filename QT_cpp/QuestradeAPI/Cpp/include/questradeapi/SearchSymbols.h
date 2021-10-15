/********************************************************************
 * Declaration of SearchSymbols.
 *
 * SearchSymbols - Search symbols by prefix
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/

#ifndef QUESTRADEAPI_SEARCHSYMBOLS_H
#define QUESTRADEAPI_SEARCHSYMBOLS_H

#include "Authentication.h"
#include "CommonStructures.h"

namespace QuestradeAPI { class SearchSymbolsResponseImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::SearchSymbolsResponseImplementation>;

namespace QuestradeAPI
{

/// @ingroup services
/// @brief SearchSymbols Response structure
struct QUESTRADELIBRARYAPI SearchSymbolsResponse
{
public:
    /// Resulting symbols matching the search criteria
    ///
    /// Returns empty vector in case of not valid response,
    /// check isValid() to know whether the request went through correctly.
    std::vector<EquitySymbol>   getSymbols() const;

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
    /// Return async request Id that was passed to BeginSearchSymbols function
    int32 getAsyncRequestId() const;
    /// Dumps message in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid response (added for use with STL containers)
    SearchSymbolsResponse();

private:
    typedef SearchSymbolsResponseImplementation Impl;

    SearchSymbolsResponse(std::shared_ptr<const Impl> spImpl);
    const std::shared_ptr<const Impl> m_spImpl;
    friend class SearchSymbolsResponseImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::function<void(QuestradeAPI::SearchSymbolsResponse)>;


namespace QuestradeAPI
{

/// @ingroup services
/// Search symbols by prefix
///
/// authInfo - AuthenticationInfo object with which this service should be called.
///
/// prefix - The prefix
///
/// offset - The offset
QUESTRADELIBRARYAPI SearchSymbolsResponse APIENTRY SearchSymbols(AuthenticationInfo& authInfo,
                                                const std::string& prefix,
                                                uint64 offset = 0);

/// @ingroup services
/// Asynchronous execution of SearchSymbols
QUESTRADELIBRARYAPI int APIENTRY SearchSymbolsAsync(AuthenticationInfo& authInfo,
                                                std::function<void(SearchSymbolsResponse)> callback,
                                                int32 requestId,
                                                const std::string& prefix,
                                                uint64 offset = 0);

} // namespace QuestradeAPI
#endif // QUESTRADEAPI_SEARCHSYMBOLS_H
