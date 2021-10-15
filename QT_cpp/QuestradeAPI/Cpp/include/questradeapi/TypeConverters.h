/********************************************************************
 * Declarations of functions that convert related types
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.0.0
 * Creation Date:  Wed Oct 22 18:47:47 2014
 *******************************************************************/

#ifndef QUESTRADEAPI_TYPE_CONVERTERS_H
#define QUESTRADEAPI_TYPE_CONVERTERS_H

#include "CommonStructures.h"

namespace QuestradeAPI
{

/// @ingroup enums
/// Converts OrderSide to corresponding OrderAction.
QUESTRADELIBRARYAPI OrderAction::Value APIENTRY convertSide(OrderSide::Value side);

/// @ingroup structures
/// Converts OrderData to make a copy of the order.
QUESTRADELIBRARYAPI InsertOrderRequest APIENTRY createCopyOfOrderRequest(const std::string& account, OrderData order);

/// @ingroup structures
/// Converts OrderData to make a replace request for the order.
QUESTRADELIBRARYAPI ReplaceOrderRequest APIENTRY createReplaceRequest(const std::string& account, OrderData origOrder);

/// @ingroup structures
/// Converts OrderData to make a copy of the strategy order. (request will be invalid if it order is not a strategy order)
/// Strategy Type is not copied to allow more flexibility
QUESTRADELIBRARYAPI InsertStrategyOrderRequest APIENTRY createCopyOfStrategyOrderRequest(const std::string& account, OrderData order);

/// @ingroup structures
/// Converts OrderData to make a replace request for the strategy order. (request will be invalid if it order is not a strategy order)
QUESTRADELIBRARYAPI ReplaceStrategyOrderRequest APIENTRY createStrategyReplaceRequest(const std::string& account, OrderData origOrder);

/// @ingroup structures
/// Converts OrderData to make a copy as a bracket order component. (OrderClass::Primary is assumed if order is not part of Bracket)
QUESTRADELIBRARYAPI BracketOrderComponent APIENTRY createCopyAsBracketComponent(OrderData order);

/// @ingroup structures
/// Converts OrderData to make a replace request for the bracket order component.
QUESTRADELIBRARYAPI BracketOrderComponent APIENTRY createReplacingBracketComponent(OrderData origOrder);

} // namespace QuestradeAPI

#endif //QUESTRADEAPI_TYPE_CONVERTERS_H
