/********************************************************************
 * Declarations for Authentication in Questrade API.
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.0.0
 * Creation Date:  Tue Sep 9 15:50:45 2014
 *******************************************************************/

#ifndef QUESTRADEAPI_AUTHENTICATION_H
#define QUESTRADEAPI_AUTHENTICATION_H

#include "CommonDefines.h"
#include <memory>
#include <string>

namespace QuestradeAPI { class AuthenticationInfoImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<QuestradeAPI::AuthenticationInfoImplementation>;

namespace QuestradeAPI
{

/// @ingroup general
/// @brief Authentication Information
struct QUESTRADELIBRARYAPI AuthenticationInfo
{
public:
    /// Returns whether authentication was successful and not interrupted.
    bool isAuthenticated() const;

    /// Returns whether authentication code provided was valid code
    bool isValid() const;
    /// Returns particular error code in case of unsuccessful request
    int32 getErrorCode() const;
    /// Returns error message text in case of unsuccessful request
    std::string getErrorMessage() const;

    /// Returns refresh token with which this session was created.
    std::string getRefreshToken() const;

    /// Returns access token of current session. (may change over time if requests are rare)
    std::string getAccessToken() const;

    /// Returns URL of proxy server used by current session. (may change over time if requests are rare)
    std::string getProxyURL() const;

    /// Retuns true if it is a demo AuthenticationInfo
    bool isDemo() const;

    /// Creates invalid object (added for use with STL libraries)
    AuthenticationInfo();

private:
    typedef AuthenticationInfoImplementation Impl;
    std::shared_ptr<Impl> m_spImpl;
    AuthenticationInfo(std::shared_ptr<Impl> spImpl);
    friend QUESTRADELIBRARYAPI AuthenticationInfo APIENTRY Authenticate(const std::string& refreshToken, bool isDemo);
    friend class AuthenticationInfoImplementation;
};

/// @ingroup general
/// Authenticates with provided parameters
///
/// clientId - Client ID of the Application using DLL
///
/// refreshToken - Refresh token which user of the application got from Questrade site
///
/// isDemo - flag whether this is Live token or Demo (Practice) token
QUESTRADELIBRARYAPI AuthenticationInfo APIENTRY Authenticate(const std::string& refreshToken, bool isDemo);

} // namespace QuestradeAPI

#endif //QUESTRADEAPI_AUTHENTICATION_H