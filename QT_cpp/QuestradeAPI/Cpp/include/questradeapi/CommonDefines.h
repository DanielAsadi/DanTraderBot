/********************************************************************
 * Declarations basic data types for Questrade API.
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.0.0
 * Creation Date:  Tue Sep 9 15:50:45 2014
 *******************************************************************/
 
#ifndef QUESTRADEAPI_COMMON_DEFINES_H
#define QUESTRADEAPI_COMMON_DEFINES_H

#include <limits>
#include <string>
#include <vector>
#include <memory>
#include <functional>

#ifdef WIN32
    #define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
    #include <windows.h>

    #if defined(QUESTRADEAPILIBRARY_EXPORTS) // inside DLL
        #define QUESTRADELIBRARYAPI   __declspec(dllexport)
        #define QUESTRADEAPI_EXTERN
    #else // outside DLL
        #define QUESTRADELIBRARYAPI   __declspec(dllimport)
        #define QUESTRADEAPI_EXTERN extern
    #endif  // APILIBRARY_EXPORTS
#else
    #define QUESTRADELIBRARYAPI
    #define APIENTRY

    #ifdef QUESTRADEAPILIBRARY_EXPORTS
	#define QUESTRADEAPI_EXTERN 
    #else 
        #define QUESTRADEAPI_EXTERN extern
    #endif
#endif

#ifdef QUESTRADEAPINODLL
	#undef QUESTRADEAPI_EXTERN 
	#undef QUESTRADELIBRARYAPI
	#define QUESTRADEAPI_EXTERN 
	#define QUESTRADELIBRARYAPI
#endif


using namespace std;

/**
 *  @defgroup general General functionality of Questrade API
 */

namespace QuestradeAPI
{

/// @ingroup general
/// Initialize library
QUESTRADELIBRARYAPI void APIENTRY Init();

/// @ingroup general
/// Uninitialize library
QUESTRADELIBRARYAPI void APIENTRY UnInit();

#ifdef WIN32

// typedefs for integers
typedef          __int16  int16;
typedef          __int32  int32;
typedef          __int64  int64;
typedef unsigned __int16 uint16;
typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;

#else

// typedefs for integers
typedef          short       int16;
typedef          int         int32;
typedef          long long   int64;
typedef unsigned short       uint16;
typedef unsigned int         uint32;
typedef unsigned long long   uint64;

#endif

// Invalid values to be used in case valued is unspecified
static const uint16 invalidUShort   = (std::numeric_limits<uint16>::max)();
static const int16  invalidShort    = (std::numeric_limits<int16>::min)();
static const uint32 invalidUInt     = (std::numeric_limits<uint32>::max)();
static const int32  invalidInt      = (std::numeric_limits<int32>::min)();
static const uint64 invalidULong    = (std::numeric_limits<uint64>::max)();
static const int64  invalidLong     = (std::numeric_limits<int64>::min)();
static const double invalidDbl      = (std::numeric_limits<double>::infinity)();
static const uint64 invalidLegId    = 32767;

// Forward declarations for DateTime
class DateTimeImplementation;

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::DateTimeImplementation>;

namespace QuestradeAPI
{

/// @ingroup general
/// @brief Structure for date time
struct QUESTRADELIBRARYAPI DateTime
{
public:
    /// Builds DateTime from ISO 8601 (e.g. 2014-10-21T10:56:55.557000-04:00)
    DateTime(const std::string& isoString);
    /// Build time from epoch time (number of seconds from January 1st 1970 00:00 UTC)
    DateTime(int64 epochTime);

    /// Generates invalid DateTime
    DateTime();

    /// Converts DateTime to ISO 8601 format in EST timezone
    std::string toIsoString() const;
    /// Converts to EpochTime (number of seconds from January 1st 1970 00:00 UTC)
    int64 toEpochTime() const;
    /// Is this DateTime object valid
    bool isValid() const;

    /// Creates DateTime object coressponding to start of day in EST/EDT timezone
    static DateTime startOfDay();

private:
    typedef DateTimeImplementation Impl;
    std::shared_ptr<const Impl> m_spImpl;
    DateTime(std::shared_ptr<const Impl> spImpl);
    friend class DateTimeImplementation;
};

} // namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<std::string>;
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::uint64>;
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::DateTime>;

#endif //QUESTRADEAPI_COMMON_DEFINES_H_
