/********************************************************************
 * Declarations of all structures used by Questrade API.
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/
 
#ifndef QUESTRADEAPI_STRUCTURES_H
#define QUESTRADEAPI_STRUCTURES_H

#include "CommonEnumsDefines.h"
#include "CommonDefines.h"

/**
 *  @defgroup structures Questrade API Structures
 */

/**
 *  @defgroup services Questrade API Services
 */


namespace QuestradeAPI { class OrderLegDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::OrderLegDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Describes leg for multi-leg order
struct QUESTRADELIBRARYAPI OrderLegData
{
public:

    /// Leg ID
    uint64                      getLegId() const;
    /// Symbol name
    std::string                 getSymbol() const;
    /// Symbol ID
    uint64                      getSymbolId() const;
    /// Leg ratio quantity
    double                      getLegRatioQuantity() const;
    /// Order side
    OrderSide::Value            getSide() const;
    /// Average execution price
    double                      getAvgExecPrice() const;
    /// Last execution price
    double                      getLastExecPrice() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    OrderLegData();

private:
    typedef OrderLegDataImplementation Impl;
    OrderLegData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class OrderLegDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::OrderLegData>;


namespace QuestradeAPI { class OrderDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::OrderDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Describes order details
struct QUESTRADELIBRARYAPI OrderData
{
public:

    /// Order ID
    uint64                      getId() const;
    /// Symbol name
    std::string                 getSymbol() const;
    /// Symbol ID
    uint64                      getSymbolId() const;
    /// Total order quantity
    double                      getTotalQuantity() const;
    /// Open order quantity
    double                      getOpenQuantity() const;
    /// Filled quantity
    double                      getFilledQuantity() const;
    /// Canceled quantity
    double                      getCanceledQuantity() const;
    /// BOSide
    OrderSide::Value            getSide() const;
    /// Type
    OrderType::Value            getOrderType() const;
    /// Limit price
    double                      getLimitPrice() const;
    /// Stop price
    double                      getStopPrice() const;
    /// Is all or none
    bool                        isAllOrNone() const;
    /// Is anonymous
    bool                        isAnonymous() const;
    /// Iceberg quantity
    double                      getIcebergQuantity() const;
    /// Min quantity
    double                      getMinQuantity() const;
    /// Average execution price
    double                      getAvgExecPrice() const;
    /// Last execution price
    double                      getLastExecPrice() const;
    /// Platform from which order was placed
    OrderSource::Value          getSource() const;
    /// Time in force
    OrderTimeInForce::Value     getTimeInForce() const;
    /// Good-till date
    DateTime                    getGtdDate() const;
    /// Order state
    OrderState::Value           getState() const;
    /// Rejection reason string
    std::string                 getRejectionReason() const;
    /// Chain ID
    uint64                      getChainId() const;
    /// Order record creation time
    DateTime                    getCreationTime() const;
    /// Order record update time
    DateTime                    getUpdateTime() const;
    /// Notes
    std::string                 getNotes() const;
    /// Primary route
    std::string                 getPrimaryRoute() const;
    /// Secondary route
    std::string                 getSecondaryRoute() const;
    /// Actual route to which order was sent
    std::string                 getOrderRoute() const;
    /// Venue holding order
    std::string                 getVenueHoldingOrder() const;
    /// Commission charged for the order
    double                      getComissionCharged() const;
    /// Exchange order ID
    std::string                 getExchangeOrderId() const;
    /// Whether or not the order was placed by a significant shareholder
    bool                        isSignificantShareHolder() const;
    /// Whether or not the order was placed by an insider
    bool                        isInsider() const;
    /// Whether or not the synthetic order's limit price offset is in dollars
    bool                        isLimitOffsetInDollar() const;
    /// User ID placing the order
    uint64                      getUserId() const;
    /// Placement commission
    double                      getPlacementCommission() const;
    /// Array of legs for multi-leg orders
    std::vector<OrderLegData>   getLegs() const;
    /// Strategy type for multi-leg orders
    StrategyType::Value         getStrategyType() const;
    /// The trigger stop price for the order
    double                      getTriggerStopPrice() const;
    /// Order Group ID of the order, if its bracket component
    uint64                      getOrderGroupId() const;
    /// For bracket order describes the type of component
    OrderClass::Value           getOrderClass() const;
    /// Specifies if GUI should display cross zero icon
    bool                        isCrossZero() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    OrderData();

private:
    typedef OrderDataImplementation Impl;
    OrderData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class OrderDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::OrderData>;


namespace QuestradeAPI { class ExecutionDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::ExecutionDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Execution Data
struct QUESTRADELIBRARYAPI ExecutionData
{
public:

    /// Symbol name
    std::string                 getSymbol() const;
    /// Symbol ID
    uint64                      getSymbolId() const;
    /// Execution quantity
    double                      getQuantity() const;
    /// BOSide
    OrderSide::Value            getSide() const;
    /// Execution fill price
    double                      getPrice() const;
    /// Execution ID
    uint64                      getId() const;
    /// Order ID
    uint64                      getOrderId() const;
    /// Chain ID
    uint64                      getOrderChainId() const;
    /// Exchange execution ID
    std::string                 getExchangeExecId() const;
    /// Execution time
    DateTime                    getTimestamp() const;
    /// Notes
    std::string                 getNotes() const;
    /// Execution venue
    std::string                 getVenue() const;
    /// Total execution cost
    double                      getTotalCost() const;
    /// Order placement commission
    double                      getOrderPlacementCommission() const;
    /// Questrade commission for this execution
    double                      getCommission() const;
    /// ECN fee for this execution
    double                      getExecutionFee() const;
    /// SEC fee for this execution
    double                      getSecFee() const;
    /// Leg ID for part of multileg execution
    uint64                      getLegId() const;
    /// Canadian security fee for this execution
    double                      getCanadianExecutionFee() const;
    /// Parent execution ID for part of multi-leg execution
    uint64                      getParentId() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    ExecutionData();

private:
    typedef ExecutionDataImplementation Impl;
    ExecutionData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class ExecutionDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::ExecutionData>;


namespace QuestradeAPI { class Level1DataItemImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::Level1DataItemImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Level 1 quote data
struct QUESTRADELIBRARYAPI Level1DataItem
{
public:

    /// Symbol name
    std::string                 getSymbol() const;
    /// Symbol ID
    uint64                      getSymbolId() const;
    /// Tier of Pink sheet if applicable
    std::string                 getTier() const;
    /// Bid price
    double                      getBidPrice() const;
    /// Bid size
    uint64                      getBidSize() const;
    /// Ask price
    double                      getAskPrice() const;
    /// Ask size
    uint64                      getAskSize() const;
    /// Last trade price during trading hours
    double                      getLastTradePriceTrHrs() const;
    /// Last trade price
    double                      getLastTradePrice() const;
    /// Last trade size
    uint64                      getLastTradeSize() const;
    /// Last trade tick
    TickType::Value             getLastTradeTick() const;
    /// Last trade time
    DateTime                    getLastTradeTime() const;
    /// Volume
    uint64                      getVolume() const;
    /// Open price
    double                      getOpenPrice() const;
    /// High price
    double                      getHighPrice() const;
    /// Low price
    double                      getLowPrice() const;
    /// How much is data delayed
    uint64                      getDelay() const;
    /// Whether or not the symbol was halted
    bool                        isHalted() const;
    /// 52 weeks High price
    double                      getHigh52w() const;
    /// 52 weeks Low price
    double                      getLow52w() const;
    /// Volume Weighted Average Price
    double                      getVWAP() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    Level1DataItem();

private:
    typedef Level1DataItemImplementation Impl;
    Level1DataItem(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class Level1DataItemImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::Level1DataItem>;


namespace QuestradeAPI { class EquitySymbolImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::EquitySymbolImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Data for equities returned by symbol search
struct QUESTRADELIBRARYAPI EquitySymbol
{
public:

    /// Symbol name
    std::string                 getSymbol() const;
    /// Symbol ID
    uint64                      getSymbolId() const;
    /// Description of the symbol
    std::string                 getDescription() const;
    /// Security Type
    SecurityType::Value         getSecurityType() const;
    /// Listing exchange
    std::string                 getListingExchange() const;
    /// Whether the symbol is tradable
    bool                        isTradable() const;
    /// Whether the symbol is quotable
    bool                        isQuotable() const;
    /// Currency
    CurrencyType::Value         getCurrency() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    EquitySymbol();

private:
    typedef EquitySymbolImplementation Impl;
    EquitySymbol(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class EquitySymbolImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::EquitySymbol>;


namespace QuestradeAPI { class CandleDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::CandleDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Historical Candle Data
struct QUESTRADELIBRARYAPI CandleData
{
public:

    /// Start time
    DateTime                    getStart() const;
    /// End time
    DateTime                    getEnd() const;
    /// Low price
    double                      getLow() const;
    /// High price
    double                      getHigh() const;
    /// Open price
    double                      getOpen() const;
    /// Closing price
    double                      getClose() const;
    /// Volume
    double                      getVolume() const;
    /// Volume Weighted Average Price
    double                      getVWAP() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    CandleData();

private:
    typedef CandleDataImplementation Impl;
    CandleData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class CandleDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::CandleData>;


#ifdef WIN32
#pragma warning( disable : 4251)
#endif

namespace QuestradeAPI
{
/// @ingroup structures
/// Structure that used as input in some services
struct QUESTRADELIBRARYAPI InsertOrderRequest
{
public:
    /// Creates a structure with empty request parameters
    InsertOrderRequest();

    /// Creates a request with required fields filled out.
    InsertOrderRequest(const std::string& accountNumber,
                            uint64 symbolId,
                            double quantity,
                            OrderType::Value orderType,
                            OrderTimeInForce::Value timeInForce,
                            OrderAction::Value action,
                            const std::string& primaryRoute);
    /// The account number
    std::string m_accountNumber;
    /// The symbol ID
    uint64 m_symbolId;
    /// Quantity of the order
    double m_quantity;
    /// Iceberg quantity
    double m_icebergQuantity;
    /// Minimum quantity
    double m_minQuantity;
    /// The limit price
    double m_limitPrice;
    /// The stop price
    double m_stopPrice;
    /// Is All-or-none flag
    bool m_isAllOrNone;
    /// Is anonymous flag
    bool m_isAnonymous;
    /// The type
    OrderType::Value m_orderType;
    /// The time in force
    OrderTimeInForce::Value m_timeInForce;
    /// The good-till date
    DateTime m_gtdDate;
    /// The side
    OrderAction::Value m_action;
    /// The primary route
    std::string m_primaryRoute;
    /// The secondary route
    std::string m_secondaryRoute;
    /// Is limit offset in dollar flag for synthetic orders
    bool m_isLimitOffsetInDollar;
};
}//namespace QuestradeAPI

#ifdef WIN32
#pragma warning( default : 4251)
#endif

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::InsertOrderRequest>;

#ifdef WIN32
#pragma warning( disable : 4251)
#endif

namespace QuestradeAPI
{
/// @ingroup structures
/// Structure that used as input in some services
struct QUESTRADELIBRARYAPI ReplaceOrderRequest
{
public:
    /// Creates a structure with empty request parameters
    ReplaceOrderRequest();

    /// Creates a request with required fields filled out.
    ReplaceOrderRequest(const std::string& accountNumber,
                            uint64 orderId,
                            double quantity,
                            OrderType::Value orderType,
                            OrderTimeInForce::Value timeInForce);
    /// Account number
    std::string m_accountNumber;
    /// ID of the order to replace
    uint64 m_orderId;
    /// New quantity
    double m_quantity;
    /// New iceberg quantity
    double m_icebergQuantity;
    /// New min quantity
    double m_minQuantity;
    /// New limit price
    double m_limitPrice;
    /// New stop price
    double m_stopPrice;
    /// New type
    OrderType::Value m_orderType;
    /// New time in force
    OrderTimeInForce::Value m_timeInForce;
    /// New good-till date
    DateTime m_gtdDate;
    /// New value for is limit offset in dollar for synthetic orders
    bool m_isLimitOffsetInDollar;
    /// New value for is all or none
    bool m_isAllOrNone;
    /// New value for is anonymous
    bool m_isAnonymous;
};
}//namespace QuestradeAPI

#ifdef WIN32
#pragma warning( default : 4251)
#endif

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::ReplaceOrderRequest>;

namespace QuestradeAPI { class PositionDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::PositionDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Position Data
struct QUESTRADELIBRARYAPI PositionData
{
public:

    /// Symbol name
    std::string                 getSymbol() const;
    /// Symbol ID
    uint64                      getSymbolId() const;
    /// Open quantity
    double                      getOpenQuantity() const;
    /// Closed quantity
    double                      getClosedQuantity() const;
    /// Current market value
    double                      getCurrentMarketValue() const;
    /// Current price
    double                      getCurrentPrice() const;
    /// Average entry price
    double                      getAverageEntryPrice() const;
    /// Closed profit and loss
    double                      getClosedPnl() const;
    /// Open profit and loss
    double                      getOpenPnl() const;
    /// Total cost
    double                      getTotalCost() const;
    /// Whether or not real-time prices are used
    bool                        isRealTime() const;
    /// Whether or not the position is under corporate action
    bool                        isUnderReorg() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    PositionData();

private:
    typedef PositionDataImplementation Impl;
    PositionData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class PositionDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::PositionData>;


namespace QuestradeAPI { class AccountDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::AccountDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Account Data
struct QUESTRADELIBRARYAPI AccountData
{
public:

    /// Type
    UserAccountType::Value      getType() const;
    /// Account number
    std::string                 getNumber() const;
    /// Status
    AccountStatus::Value        getStatus() const;
    /// Whether or not the account is primary
    bool                        isPrimary() const;
    /// Whether or not the account is a billing account
    bool                        isBilling() const;
    /// Client account type
    ClientAccountType::Value    getClientAccountType() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    AccountData();

private:
    typedef AccountDataImplementation Impl;
    AccountData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class AccountDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::AccountData>;


namespace QuestradeAPI { class ChainPerStrikePriceImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::ChainPerStrikePriceImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Pair of call and put options with same expiry date, root and strike
struct QUESTRADELIBRARYAPI ChainPerStrikePrice
{
public:

    /// Strike price
    double                      getStrikePrice() const;
    /// Call symbol ID
    uint64                      getCallSymbolId() const;
    /// Put symbol ID
    uint64                      getPutSymbolId() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    ChainPerStrikePrice();

private:
    typedef ChainPerStrikePriceImplementation Impl;
    ChainPerStrikePrice(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class ChainPerStrikePriceImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::ChainPerStrikePrice>;


namespace QuestradeAPI { class ChainPerRootImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::ChainPerRootImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Option chain grouped per option root symbol for same expiry date
struct QUESTRADELIBRARYAPI ChainPerRoot
{
public:

    /// OCC root
    std::string                 getOptionRoot() const;
    /// Array of pairs of options per strike price
    std::vector<ChainPerStrikePrice> getChainPerStrikePrice() const;
    /// Multiplier
    double                      getMultiplier() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    ChainPerRoot();

private:
    typedef ChainPerRootImplementation Impl;
    ChainPerRoot(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class ChainPerRootImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::ChainPerRoot>;


namespace QuestradeAPI { class ChainPerExpiryDateImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::ChainPerExpiryDateImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Option chain grouped per expiry date
struct QUESTRADELIBRARYAPI ChainPerExpiryDate
{
public:

    /// Expiry date
    DateTime                    getExpiryDate() const;
    /// Description
    std::string                 getDescription() const;
    /// Listing exchange
    std::string                 getListingExchange() const;
    /// Exercise type
    ExerciseType::Value         getOptionExerciseType() const;
    /// Sub-chains grouped by option root symbol
    std::vector<ChainPerRoot>   getChainPerRoot() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    ChainPerExpiryDate();

private:
    typedef ChainPerExpiryDateImplementation Impl;
    ChainPerExpiryDate(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class ChainPerExpiryDateImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::ChainPerExpiryDate>;


namespace QuestradeAPI { class BalanceDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::BalanceDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Balance Data
struct QUESTRADELIBRARYAPI BalanceData
{
public:

    /// Currency
    CurrencyType::Value         getCurrency() const;
    /// Cash
    double                      getCash() const;
    /// Market value
    double                      getMarketValue() const;
    /// Total equity
    double                      getTotalEquity() const;
    /// Buying power
    double                      getBuyingPower() const;
    /// Maintenance Excess
    double                      getMaintenanceExcess() const;
    /// Is data real-time
    bool                        isRealTime() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    BalanceData();

private:
    typedef BalanceDataImplementation Impl;
    BalanceData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class BalanceDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::BalanceData>;


#ifdef WIN32
#pragma warning( disable : 4251)
#endif

namespace QuestradeAPI
{
/// @ingroup structures
/// Order Leg Data coming from client
struct QUESTRADELIBRARYAPI InsertOrderLegData
{
public:
    /// Creates a structure with empty request parameters
    InsertOrderLegData();

    /// Creates a request with required fields filled out.
    InsertOrderLegData(uint64 symbolId,
                            OrderAction::Value action,
                            uint64 legQuantity);
    /// Symbol ID
    uint64 m_symbolId;
    /// Leg Action
    OrderAction::Value m_action;
    /// Leg quantity
    uint64 m_legQuantity;
};
}//namespace QuestradeAPI

#ifdef WIN32
#pragma warning( default : 4251)
#endif

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::InsertOrderLegData>;

#ifdef WIN32
#pragma warning( disable : 4251)
#endif

namespace QuestradeAPI
{
/// @ingroup structures
/// Structure that used as input in some services
struct QUESTRADELIBRARYAPI InsertStrategyOrderRequest
{
public:
    /// Creates a structure with empty request parameters
    InsertStrategyOrderRequest();

    /// Creates a request with required fields filled out.
    InsertStrategyOrderRequest(const std::string& accountNumber,
                            uint64 symbolId,
                            OrderType::Value orderType,
                            OrderTimeInForce::Value timeInForce,
                            const std::string& primaryRoute,
                            const std::vector<InsertOrderLegData>& legs);
    /// The account number
    std::string m_accountNumber;
    /// The symbol ID
    uint64 m_symbolId;
    /// The limit price
    double m_limitPrice;
    /// The type
    OrderType::Value m_orderType;
    /// The time-in-force
    OrderTimeInForce::Value m_timeInForce;
    /// The primary route
    std::string m_primaryRoute;
    /// The secondary route
    std::string m_secondaryRoute;
    /// Legs data
    std::vector<InsertOrderLegData> m_legs;
    /// The strategy type
    StrategyType::Value m_strategy;
};
}//namespace QuestradeAPI

#ifdef WIN32
#pragma warning( default : 4251)
#endif

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::InsertStrategyOrderRequest>;

#ifdef WIN32
#pragma warning( disable : 4251)
#endif

namespace QuestradeAPI
{
/// @ingroup structures
/// Structure that used as input in some services
struct QUESTRADELIBRARYAPI ReplaceStrategyOrderRequest
{
public:
    /// Creates a structure with empty request parameters
    ReplaceStrategyOrderRequest();

    /// Creates a request with required fields filled out.
    ReplaceStrategyOrderRequest(const std::string& accountNumber,
                            uint64 orderId,
                            double quantity,
                            OrderType::Value orderType,
                            OrderTimeInForce::Value timeInForce);
    /// Account number
    std::string m_accountNumber;
    /// Order ID to repace
    uint64 m_orderId;
    /// New quantity
    double m_quantity;
    /// New limit price
    double m_limitPrice;
    /// New type
    OrderType::Value m_orderType;
    /// New time in force
    OrderTimeInForce::Value m_timeInForce;
};
}//namespace QuestradeAPI

#ifdef WIN32
#pragma warning( default : 4251)
#endif

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::ReplaceStrategyOrderRequest>;

#ifdef WIN32
#pragma warning( disable : 4251)
#endif

namespace QuestradeAPI
{
/// @ingroup structures
/// Leg record for a strategy
struct QUESTRADELIBRARYAPI StrategyVariantLeg
{
public:
    /// Creates a structure with empty request parameters
    StrategyVariantLeg();

    /// Creates a request with required fields filled out.
    StrategyVariantLeg(uint64 symbolId,
                            uint64 ratio,
                            OrderAction::Value action);
    /// Symbol ID
    uint64 m_symbolId;
    /// Ratio
    uint64 m_ratio;
    /// BOSide
    OrderAction::Value m_action;
};
}//namespace QuestradeAPI

#ifdef WIN32
#pragma warning( default : 4251)
#endif

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::StrategyVariantLeg>;

#ifdef WIN32
#pragma warning( disable : 4251)
#endif

namespace QuestradeAPI
{
/// @ingroup structures
/// Strategy record for strategy quotes
struct QUESTRADELIBRARYAPI StrategyVariantRequest
{
public:
    /// Creates a structure with empty request parameters
    StrategyVariantRequest();

    /// Creates a request with required fields filled out.
    StrategyVariantRequest(uint64 variantId,
                            const std::vector<StrategyVariantLeg>& legs);
    /// Variant ID
    uint64 m_variantId;
    /// Strategy
    StrategyType::Value m_strategy;
    /// Array of Strategy legs
    std::vector<StrategyVariantLeg> m_legs;
};
}//namespace QuestradeAPI

#ifdef WIN32
#pragma warning( default : 4251)
#endif

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::StrategyVariantRequest>;

namespace QuestradeAPI { class Level1StrategyDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::Level1StrategyDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief L1 and Greeks data for an options strategy
struct QUESTRADELIBRARYAPI Level1StrategyData
{
public:

    /// Variant ID corresponding to variant in request
    uint64                      getVariantId() const;
    /// Bid price
    double                      getBidPrice() const;
    /// Ask price
    double                      getAskPrice() const;
    /// Underlying name
    std::string                 getUnderlying() const;
    /// Underlying ID
    uint64                      getUnderlyingId() const;
    /// Open price
    double                      getOpenPrice() const;
    /// Volatility
    double                      getVolatility() const;
    /// Delta
    double                      getDelta() const;
    /// Gamma
    double                      getGamma() const;
    /// Theta
    double                      getTheta() const;
    /// Vega
    double                      getVega() const;
    /// Rho
    double                      getRho() const;
    /// Whether or not the data is real-time
    bool                        isRealTime() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    Level1StrategyData();

private:
    typedef Level1StrategyDataImplementation Impl;
    Level1StrategyData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class Level1StrategyDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::Level1StrategyData>;


#ifdef WIN32
#pragma warning( disable : 4251)
#endif

namespace QuestradeAPI
{
/// @ingroup structures
/// Data for each component of bracket order
struct QUESTRADELIBRARYAPI BracketOrderComponent
{
public:
    /// Creates a structure with empty request parameters
    BracketOrderComponent();

    /// Creates a request with required fields filled out.
    BracketOrderComponent(OrderClass::Value orderClass);
    /// The limit price
    double m_limitPrice;
    /// The stop price
    double m_stopPrice;
    /// The type
    OrderType::Value m_orderType;
    /// The time in force
    OrderTimeInForce::Value m_timeInForce;
    /// For bracket order describes the type of component
    OrderClass::Value m_orderClass;
    /// Order ID of Active order
    uint64 m_orderId;
    /// The quantity
    double m_quantity;
    /// The action, required only on initial insertion
    OrderAction::Value m_action;
};
}//namespace QuestradeAPI

#ifdef WIN32
#pragma warning( default : 4251)
#endif

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::BracketOrderComponent>;

namespace QuestradeAPI { class AccountActivityImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::AccountActivityImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief 
struct QUESTRADELIBRARYAPI AccountActivity
{
public:

    /// Transaction date
    DateTime                    getTradeDate() const;
    /// Transaction date
    DateTime                    getTransactionDate() const;
    /// Settlement date
    DateTime                    getSettlementDate() const;
    /// Activity action
    std::string                 getAction() const;
    /// Symbol name
    std::string                 getSymbol() const;
    /// Symbol ID
    uint64                      getSymbolId() const;
    /// Description
    std::string                 getDescription() const;
    /// Currency
    CurrencyType::Value         getCurrency() const;
    /// The quantity
    double                      getQuantity() const;
    /// The price
    double                      getPrice() const;
    /// Gross amount
    double                      getGrossAmount() const;
    /// The commission
    double                      getCommission() const;
    /// Net Amount
    double                      getNetAmount() const;
    /// Activity Type
    std::string                 getType() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    AccountActivity();

private:
    typedef AccountActivityImplementation Impl;
    AccountActivity(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class AccountActivityImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::AccountActivity>;


namespace QuestradeAPI { class MarketImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::MarketImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Listing exchange information
struct QUESTRADELIBRARYAPI Market
{
public:

    /// Listing exchange name
    std::string                 getName() const;
    /// Array of trading venues
    std::vector<std::string>    getTradingVenues() const;
    /// Default trading venue
    std::string                 getDefaultTradingVenue() const;
    /// Array of primary order routes
    std::vector<std::string>    getPrimaryOrderRoutes() const;
    /// Array of secondary order routes
    std::vector<std::string>    getSecondaryOrderRoutes() const;
    /// Array of level 1 feeds
    std::vector<std::string>    getLevel1Feeds() const;
    /// Array of level 2 feeds
    std::vector<std::string>    getLevel2Feeds() const;
    /// Extended market start time
    DateTime                    getExtendedStartTime() const;
    /// Trading hours start time
    DateTime                    getStartTime() const;
    /// Trading hours end time
    DateTime                    getEndTime() const;
    /// Extended market end time
    DateTime                    getExtendedEndTime() const;
    /// Snap quote limit
    uint64                      getSnapQuotesLimit() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    Market();

private:
    typedef MarketImplementation Impl;
    Market(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class MarketImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::Market>;


namespace QuestradeAPI { class UnderlyingMultiplierPairImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::UnderlyingMultiplierPairImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Underlying information for the option
struct QUESTRADELIBRARYAPI UnderlyingMultiplierPair
{
public:

    /// Multiplier
    uint64                      getMultiplier() const;
    /// Underlying symbol name
    std::string                 getUnderlyingSymbol() const;
    /// Underlying symbol ID
    uint64                      getUnderlyingSymbolId() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    UnderlyingMultiplierPair();

private:
    typedef UnderlyingMultiplierPairImplementation Impl;
    UnderlyingMultiplierPair(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class UnderlyingMultiplierPairImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::UnderlyingMultiplierPair>;


namespace QuestradeAPI { class ContractDeliverablesImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::ContractDeliverablesImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Deliverables of option contract
struct QUESTRADELIBRARYAPI ContractDeliverables
{
public:

    /// Array of underlyings for option
    std::vector<UnderlyingMultiplierPair> getUnderlyings() const;
    /// Cash in lieu amount
    double                      getCashInLieu() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    ContractDeliverables();

private:
    typedef ContractDeliverablesImplementation Impl;
    ContractDeliverables(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class ContractDeliverablesImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::ContractDeliverables>;


namespace QuestradeAPI { class MinTickDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::MinTickDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Min tick rules data
struct QUESTRADELIBRARYAPI MinTickData
{
public:

    /// Price above which this min tick applies
    double                      getPivot() const;
    /// Min tick
    double                      getMinTick() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    MinTickData();

private:
    typedef MinTickDataImplementation Impl;
    MinTickData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class MinTickDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::MinTickData>;


namespace QuestradeAPI { class SymbolDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::SymbolDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Symbol Data
struct QUESTRADELIBRARYAPI SymbolData
{
public:

    /// Symbol name
    std::string                 getSymbol() const;
    /// Symbol ID
    uint64                      getSymbolId() const;
    /// Previous day close price
    double                      getPrevDayClosePrice() const;
    /// 52-week high price
    double                      getHighPrice52() const;
    /// 52-week low price
    double                      getLowPrice52() const;
    /// Average 3-month volume
    uint64                      getAverageVol3Months() const;
    /// Average 20-day volume
    uint64                      getAverageVol20Days() const;
    /// Number of outstanding shares
    uint64                      getOutstandingShares() const;
    /// The EPS
    double                      getEps() const;
    /// The PE ratio
    double                      getPe() const;
    /// The dividend
    double                      getDividend() const;
    /// The yield
    double                      getYield() const;
    /// Expiration date
    DateTime                    getExDate() const;
    /// Market capitalization
    uint64                      getMarketCap() const;
    /// Multiplier
    uint64                      getTradeUnit() const;
    /// Option type
    OptionType::Value           getOptionType() const;
    /// Option duration type
    OptionDurationType::Value   getOptionDurationType() const;
    /// OCC root
    std::string                 getOptionRoot() const;
    /// Contract deliverables
    ContractDeliverables        getOptionContractDeliverables() const;
    /// Exercise type
    ExerciseType::Value         getOptionExerciseType() const;
    /// Listing exchange
    std::string                 getListingExchange() const;
    /// Description
    std::string                 getDescription() const;
    /// Security type
    SecurityType::Value         getSecurityType() const;
    /// Expiration date
    DateTime                    getOptionExpiryDate() const;
    /// Dividend date
    DateTime                    getDividendDate() const;
    /// Strike price
    double                      getOptionStrikePrice() const;
    /// Whether or not the symbol is tradable
    bool                        isTradable() const;
    /// Whether or not the symbol is quotable
    bool                        isQuotable() const;
    /// Whether or not the symbol has options
    bool                        isHasOptions() const;
    /// Currency string
    std::string                 getCurrency() const;
    /// Array of MinTickData
    std::vector<MinTickData>    getMinTicks() const;
    /// Industry Sector
    IndustrySector::Value       getIndustrySector() const;
    /// Industry Group
    IndustryGroup::Value        getIndustryGroup() const;
    /// Industry Subgroup
    IndustrySubgroup::Value     getIndustrySubgroup() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    SymbolData();

private:
    typedef SymbolDataImplementation Impl;
    SymbolData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class SymbolDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::SymbolData>;


#ifdef WIN32
#pragma warning( disable : 4251)
#endif

namespace QuestradeAPI
{
/// @ingroup structures
/// Option filters based on underlying Ids
struct QUESTRADELIBRARYAPI OptionIdFilter
{
public:
    /// Creates a structure with empty request parameters
    OptionIdFilter();

    /// Creates a request with required fields filled out.
    OptionIdFilter(uint64 underlyingId,
                            const DateTime& expiryDate);
    /// Option type
    OptionType::Value m_optionType;
    /// Underlying ID
    uint64 m_underlyingId;
    /// Expiry date
    DateTime m_expiryDate;
    /// Min strike price
    double m_minstrikePrice;
    /// Max strike price
    double m_maxstrikePrice;
};
}//namespace QuestradeAPI

#ifdef WIN32
#pragma warning( default : 4251)
#endif

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::OptionIdFilter>;

namespace QuestradeAPI { class Level1OptionDataImplementation; }
QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::shared_ptr<const QuestradeAPI::Level1OptionDataImplementation>;

namespace QuestradeAPI
{
/// @ingroup structures
/// @brief Get L1 data for multiple options
struct QUESTRADELIBRARYAPI Level1OptionData
{
public:

    /// Underlying name
    std::string                 getUnderlying() const;
    /// Underlying ID
    uint64                      getUnderlyingId() const;
    /// Symbol name
    std::string                 getSymbol() const;
    /// Symbol ID
    uint64                      getSymbolId() const;
    /// Bid price
    double                      getBidPrice() const;
    /// Bid size
    uint64                      getBidSize() const;
    /// Ask price
    double                      getAskPrice() const;
    /// Ask size
    uint64                      getAskSize() const;
    /// Last trade price trade hours
    double                      getLastTradePriceTrHrs() const;
    /// Last trade price
    double                      getLastTradePrice() const;
    /// Last trade size
    uint64                      getLastTradeSize() const;
    /// Last trade tick
    TickType::Value             getLastTradeTick() const;
    /// Last trade time
    DateTime                    getLastTradeTime() const;
    /// Volume
    uint64                      getVolume() const;
    /// Open price
    double                      getOpenPrice() const;
    /// High price
    double                      getHighPrice() const;
    /// Low price
    double                      getLowPrice() const;
    /// Volatility
    double                      getVolatility() const;
    /// Delta
    double                      getDelta() const;
    /// Gamma
    double                      getGamma() const;
    /// Theta
    double                      getTheta() const;
    /// Vega
    double                      getVega() const;
    /// Rho
    double                      getRho() const;
    /// Open interest
    uint64                      getOpenInterest() const;
    /// How much is data delayed
    uint64                      getDelay() const;
    /// Whether or not the symbol was halted
    bool                        isHalted() const;
    /// Volume Weighted Average Price
    double                      getVWAP() const;

    /// Dumps data in json format (use for debug purposes only, as json is generated)
    std::string dumpToJson() const;

    /// Creates invalid structure (added for use with STL containers)
    Level1OptionData();

private:
    typedef Level1OptionDataImplementation Impl;
    Level1OptionData(std::shared_ptr<const Impl> spImpl);
    std::shared_ptr<const Impl> m_spImpl;
    friend class Level1OptionDataImplementation;
};
}//namespace QuestradeAPI

QUESTRADEAPI_EXTERN template class QUESTRADELIBRARYAPI std::vector<QuestradeAPI::Level1OptionData>;



#endif // QUESTRADEAPI_STRUCTURES_H
