/********************************************************************
 * Declarations of all enumerations used by Questrade API.
 *
 * Copyright (C) 2014 Questrade, Inc. All Rights Reserved.
 *
 * Protocol Version: 1.1.0
 * Creation Date:  Wed Sep 23 10:44:05 2015
 *******************************************************************/
 
#ifndef QUESTRADEAPI_COMMON_ENUMS_DEFINES_H
#define QUESTRADEAPI_COMMON_ENUMS_DEFINES_H

#include "CommonDefines.h"
#include <string>


/**
 *  @defgroup enums Questrade API Enums
 */

namespace QuestradeAPI 
{

/// @ingroup enums
/// @brief AccountStatus enumeration
struct QUESTRADELIBRARYAPI AccountStatus
{
    /// Values for AccountStatus.
    enum Value
    {
        Undefined = -1,
        UnAllocated = 0,
        Active = 1,
        SuspendedClosed = 2,
        SuspendedViewOnly = 3,
        LiquidateOnly = 4,
        Closed = 5,
        Count
    };

    /// Converts value of AccountStatus to String
    static const char* toString(Value value);
    /// Converts value of AccountStatus from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Types of clients on account
struct QUESTRADELIBRARYAPI ClientAccountType
{
    /// Values for ClientAccountType.
    enum Value
    {
        Undefined = 0,
        Individual = 1,
        Joint = 2,
        InformalTrust = 3,
        Corporation = 4,
        InvestmentClub = 5,
        FormalTrust = 6,
        Partnership = 7,
        SoleProprietorship = 8,
        Family = 9,
        JointAndInformalTrust = 10,
        Institution = 11,
        Count
    };

    /// Converts value of ClientAccountType to String
    static const char* toString(Value value);
    /// Converts value of ClientAccountType from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief ClientOrderSide aka Action
struct QUESTRADELIBRARYAPI OrderSide
{
    /// Values for OrderSide.
    enum Value
    {
        Undefined = 0,
        Buy = 1,
        Sell = 2,
        Short = 3,
        Cov = 4,
        BTO = 5,
        STC = 6,
        STO = 7,
        BTC = 8,
        Count
    };

    /// Converts value of OrderSide to String
    static const char* toString(Value value);
    /// Converts value of OrderSide from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief CurrencyType enumeration
struct QUESTRADELIBRARYAPI CurrencyType
{
    /// Values for CurrencyType.
    enum Value
    {
        Undefined = 0,
        CAD = 22,
        USD = 99,
        Count
    };

    /// Converts value of CurrencyType to String
    static const char* toString(Value value);
    /// Converts value of CurrencyType from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Option exercise type
struct QUESTRADELIBRARYAPI ExerciseType
{
    /// Values for ExerciseType.
    enum Value
    {
        Undefined = 0,
        American = 1,
        European = 2,
        Count
    };

    /// Converts value of ExerciseType to String
    static const char* toString(Value value);
    /// Converts value of ExerciseType from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Possible granularities of historical data, required for charting
struct QUESTRADELIBRARYAPI CandlesGranularity
{
    /// Values for CandlesGranularity.
    enum Value
    {
        Undefined = 0,
        OneMinute = 1,
        TwoMinutes = 2,
        ThreeMinutes = 3,
        FourMinutes = 4,
        FiveMinutes = 5,
        TenMinutes = 6,
        FifteenMinutes = 7,
        TwentyMinutes = 8,
        HalfHour = 9,
        OneHour = 10,
        TwoHours = 11,
        FourHours = 12,
        OneDay = 13,
        OneWeek = 14,
        OneMonth = 15,
        ThreeMonths = 16,
        OneYear = 17,
        Count
    };

    /// Converts value of CandlesGranularity to String
    static const char* toString(Value value);
    /// Converts value of CandlesGranularity from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief IndustryGroup enumeration
struct QUESTRADELIBRARYAPI IndustryGroup
{
    /// Values for IndustryGroup.
    enum Value
    {
        Undefined = 0,
        Agriculture = 1,
        BuildingMaterials = 2,
        Chemicals = 3,
        Coal = 4,
        ForestProducts = 5,
        MetalsMining = 6,
        Steel = 7,
        AdvertisingMarketingServices = 8,
        Autos = 9,
        Entertainment = 10,
        HomebuildingConstruction = 11,
        ManufacturingApparelFurniture = 12,
        PackagingContainers = 13,
        PersonalServices = 14,
        Publishing = 15,
        Restaurants = 16,
        RetailApparelSpecialty = 17,
        TravelLeisure = 18,
        AssetManagement = 19,
        Banks = 20,
        BrokersExchanges = 21,
        CreditServices = 22,
        Insurance = 23,
        InsuranceLife = 24,
        InsurancePropertyCasualty = 25,
        InsuranceSpecialty = 26,
        RealEstateServices = 27,
        REITs = 28,
        BeveragesAlcoholic = 29,
        BeveragesNonAlcoholic = 30,
        ConsumerPackagedGoods = 31,
        Education = 32,
        RetailDefensive = 33,
        TobaccoProducts = 34,
        Biotechnology = 35,
        DrugManufacturers = 36,
        HealthCarePlans = 37,
        HealthCareProviders = 38,
        MedicalDevices = 39,
        MedicalDiagnosticsResearch = 40,
        MedicalDistribution = 41,
        MedicalInstrumentsEquipment = 42,
        UtilitiesIndependentPowerProducers = 43,
        UtilitiesRegulated = 44,
        CommunicationServices = 45,
        OilGasDrilling = 46,
        OilGasEP = 47,
        OilGasIntegrated = 48,
        OilGasMidstream = 49,
        OilGasRefiningMarketing = 50,
        OilGasServices = 51,
        AerospaceDefense = 52,
        Airlines = 53,
        BusinessServices = 54,
        Conglomerates = 55,
        ConsultingOutsourcing = 56,
        EmploymentServices = 57,
        EngineeringConstruction = 58,
        FarmConstructionMachinery = 59,
        IndustrialDistribution = 60,
        IndustrialProducts = 61,
        TransportationLogistics = 62,
        TruckManufacturing = 63,
        WasteManagement = 64,
        ApplicationSoftware = 65,
        CommunicationEquipment = 66,
        ComputerHardware = 67,
        OnlineMedia = 68,
        Semiconductors = 69,
        Count
    };

    /// Converts value of IndustryGroup to String
    static const char* toString(Value value);
    /// Converts value of IndustryGroup from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief IndustrySector enumeration
struct QUESTRADELIBRARYAPI IndustrySector
{
    /// Values for IndustrySector.
    enum Value
    {
        Undefined = 0,
        BasicMaterials = 1,
        ConsumerCyclical = 2,
        FinancialServices = 3,
        RealEstate = 4,
        ConsumerDefensive = 5,
        Healthcare = 6,
        Utilities = 7,
        CommunicationServices = 8,
        Energy = 9,
        Industrial = 10,
        Technology = 11,
        Count
    };

    /// Converts value of IndustrySector to String
    static const char* toString(Value value);
    /// Converts value of IndustrySector from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief IndustrySubgroup enumeration
struct QUESTRADELIBRARYAPI IndustrySubgroup
{
    /// Values for IndustrySubgroup.
    enum Value
    {
        Undefined = 0,
        AgriculturalInputs = 1,
        BuildingMaterials = 2,
        Chemicals = 3,
        SpecialtyChemicals = 4,
        Coal = 5,
        LumberWoodProduction = 6,
        PaperPaperProducts = 7,
        Aluminum = 8,
        Copper = 9,
        Gold = 10,
        IndustrialMetalsMinerals = 11,
        Silver = 12,
        Steel = 13,
        AdvertisingAgencies = 14,
        MarketingServices = 15,
        AutoTruckDealerships = 16,
        AutoManufacturers = 17,
        AutoParts = 18,
        RecreationalVehicles = 19,
        RubberPlastics = 20,
        BroadcastingRadio = 21,
        BroadcastingTV = 22,
        MediaDiversified = 23,
        ResidentialConstruction = 24,
        TextileManufacturing = 25,
        ApparelManufacturing = 26,
        FootwearAccessories = 27,
        HomeFurnishingsFixtures = 28,
        PackagingContainers = 29,
        PersonalServices = 30,
        Publishing = 31,
        Restaurants = 32,
        ApparelStores = 33,
        DepartmentStores = 34,
        HomeImprovementStores = 35,
        LuxuryGoods = 36,
        SpecialtyRetail = 37,
        Gambling = 38,
        Leisure = 39,
        Lodging = 40,
        ResortsCasinos = 41,
        AssetManagement = 42,
        BanksGlobal = 43,
        BanksRegionalAfrica = 44,
        BanksRegionalAsia = 45,
        BanksRegionalAustralia = 46,
        BanksRegionalCanada = 47,
        BanksRegionalEurope = 48,
        BanksRegionalLatinAmerica = 49,
        BanksRegionalUS = 50,
        SavingsCooperativeBanks = 51,
        SpecialtyFinance = 52,
        CapitalMarkets = 53,
        FinancialExchanges = 54,
        InsuranceBrokers = 55,
        CreditServices = 56,
        InsuranceDiversified = 57,
        InsuranceLife = 58,
        InsurancePropertyCasualty = 59,
        InsuranceReinsurance = 60,
        InsuranceSpecialty = 61,
        RealEstateGeneral = 62,
        RealEstateServices = 63,
        REITDiversified = 64,
        REITHealthcareFacilities = 65,
        REITHotelMotel = 66,
        REITIndustrial = 67,
        REITOffice = 68,
        REITResidential = 69,
        REITRetail = 70,
        BeveragesBrewers = 71,
        BeveragesWineriesDistilleries = 72,
        BeveragesSoftDrinks = 73,
        Confectioners = 74,
        FarmProducts = 75,
        HouseholdPersonalProducts = 76,
        PackagedFoods = 77,
        EducationTrainingServices = 78,
        DiscountStores = 79,
        PharmaceuticalRetailers = 80,
        FoodDistribution = 81,
        GroceryStores = 82,
        Tobacco = 83,
        Biotechnology = 84,
        DrugManufacturersMajor = 85,
        DrugManufacturersSpecialtyGeneric = 86,
        HealthCarePlans = 87,
        LongTermCareFacilities = 88,
        MedicalCare = 89,
        MedicalDevices = 90,
        DiagnosticsResearch = 91,
        MedicalDistribution = 92,
        MedicalInstrumentsSupplies = 93,
        UtilitiesIndependentPowerProducers = 94,
        UtilitiesDiversified = 95,
        UtilitiesRegulatedElectric = 96,
        UtilitiesRegulatedGas = 97,
        UtilitiesRegulatedWater = 98,
        PayTV = 99,
        TelecomServices = 100,
        OilGasDrilling = 101,
        OilGasEP = 102,
        OilGasIntegrated = 103,
        OilGasMidstream = 104,
        OilGasRefiningMarketing = 105,
        OilGasEquipmentServices = 106,
        AerospaceDefense = 107,
        Airlines = 108,
        BusinessServices = 109,
        Conglomerates = 110,
        RentalLeasingServices = 111,
        SecurityProtectionServices = 112,
        StaffingOutsourcingServices = 113,
        EngineeringConstruction = 114,
        InfrastructureOperations = 115,
        FarmConstructionEquipment = 116,
        IndustrialDistribution = 117,
        BusinessEquipment = 118,
        DiversifiedIndustrials = 119,
        MetalFabrication = 120,
        PollutionTreatmentControls = 121,
        ToolsAccessories = 122,
        AirportsAirServices = 123,
        IntegratedShippingLogistics = 124,
        Railroads = 125,
        ShippingPorts = 126,
        Trucking = 127,
        TruckManufacturing = 128,
        WasteManagement = 129,
        ElectronicGamingMultimedia = 130,
        HealthInformationServices = 131,
        InformationTechnologyServices = 132,
        SoftwareApplication = 133,
        SoftwareInfrastructure = 134,
        CommunicationEquipment = 135,
        ComputerDistribution = 136,
        ComputerSystems = 137,
        ConsumerElectronics = 138,
        ContractManufacturers = 139,
        DataStorage = 140,
        ElectronicComponents = 141,
        ElectronicsDistribution = 142,
        ScientificTechnicalInstruments = 143,
        InternetContentInformation = 144,
        SemiconductorEquipmentMaterials = 145,
        SemiconductorMemory = 146,
        Semiconductors = 147,
        Solar = 148,
        Count
    };

    /// Converts value of IndustrySubgroup to String
    static const char* toString(Value value);
    /// Converts value of IndustrySubgroup from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Duration types of options
struct QUESTRADELIBRARYAPI OptionDurationType
{
    /// Values for OptionDurationType.
    enum Value
    {
        Undefined = 0,
        Weekly = 1,
        Monthly = 2,
        Quarterly = 3,
        LEAP = 4,
        Count
    };

    /// Converts value of OptionDurationType to String
    static const char* toString(Value value);
    /// Converts value of OptionDurationType from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Option types
struct QUESTRADELIBRARYAPI OptionType
{
    /// Values for OptionType.
    enum Value
    {
        Undefined = 0,
        Call = 1,
        Put = 2,
        Count
    };

    /// Converts value of OptionType to String
    static const char* toString(Value value);
    /// Converts value of OptionType from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief For bracket order describes the type of component
struct QUESTRADELIBRARYAPI OrderClass
{
    /// Values for OrderClass.
    enum Value
    {
        Undefined = 0,
        Primary = 1,
        Limit = 2,
        StopLoss = 3,
        Count
    };

    /// Converts value of OrderClass to String
    static const char* toString(Value value);
    /// Converts value of OrderClass from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Order Effect
struct QUESTRADELIBRARYAPI OrderEffect
{
    /// Values for OrderEffect.
    enum Value
    {
        Undefined = 0,
        Debit = 1,
        Credit = 2,
        Even = 3,
        Count
    };

    /// Converts value of OrderEffect to String
    static const char* toString(Value value);
    /// Converts value of OrderEffect from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Action for inserted order
struct QUESTRADELIBRARYAPI OrderAction
{
    /// Values for OrderAction.
    enum Value
    {
        Undefined = 0,
        Buy = 1,
        Sell = 2,
        Count
    };

    /// Converts value of OrderAction to String
    static const char* toString(Value value);
    /// Converts value of OrderAction from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Platform from which order was placed
struct QUESTRADELIBRARYAPI OrderSource
{
    /// Values for OrderSource.
    enum Value
    {
        Undefined = 0,
        Automatic = 1,
        BackOfficeAgent = 2,
        QuestradeIQ = 3,
        QuestradeIQEdge = 4,
        QuestradeIQMobile = 5,
        QuestradeIQEssential = 6,
        TradeDesk = 7,
        QuestradeIQMobileWeb = 8,
        TradingAPI = 9,
        AutomatedCorrection = 10,
        Count
    };

    /// Converts value of OrderSource to String
    static const char* toString(Value value);
    /// Converts value of OrderSource from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief State of the order
struct QUESTRADELIBRARYAPI OrderState
{
    /// Values for OrderState.
    enum Value
    {
        Undefined = 0,
        Failed = 1,
        Pending = 2,
        Accepted = 3,
        Rejected = 4,
        CancelPending = 5,
        Canceled = 6,
        PartialCanceled = 7,
        Partial = 8,
        Executed = 9,
        ReplacePending = 10,
        Replaced = 11,
        Stopped = 12,
        Suspended = 13,
        Expired = 14,
        Queued = 15,
        Triggered = 16,
        Activated = 17,
        PendingRiskReview = 18,
        ContingentOrder = 19,
        Conditional = 20,
        Count
    };

    /// Converts value of OrderState to String
    static const char* toString(Value value);
    /// Converts value of OrderState from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Types used for filtering orders by state
struct QUESTRADELIBRARYAPI OrderStateFilterTypes
{
    /// Values for OrderStateFilterTypes.
    enum Value
    {
        Undefined = 0,
        All = 1,
        Open = 2,
        Closed = 3,
        Count
    };

    /// Converts value of OrderStateFilterTypes to String
    static const char* toString(Value value);
    /// Converts value of OrderStateFilterTypes from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Time in force aka Duration of the order
struct QUESTRADELIBRARYAPI OrderTimeInForce
{
    /// Values for OrderTimeInForce.
    enum Value
    {
        Undefined = 0,
        Day = 1,
        GoodTillCanceled = 2,
        GoodTillExtendedDay = 3,
        GoodTillDate = 4,
        ImmediateOrCancel = 5,
        FillOrKill = 6,
        Count
    };

    /// Converts value of OrderTimeInForce to String
    static const char* toString(Value value);
    /// Converts value of OrderTimeInForce from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Type of the order
struct QUESTRADELIBRARYAPI OrderType
{
    /// Values for OrderType.
    enum Value
    {
        Undefined = 0,
        Market = 1,
        Limit = 2,
        Stop = 3,
        StopLimit = 4,
        TrailStopInPercentage = 5,
        TrailStopInDollar = 6,
        TrailStopLimitInPercentage = 7,
        TrailStopLimitInDollar = 8,
        LimitOnOpen = 9,
        LimitOnClose = 10,
        Count
    };

    /// Converts value of OrderType to String
    static const char* toString(Value value);
    /// Converts value of OrderType from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Basic types of securities
struct QUESTRADELIBRARYAPI SecurityType
{
    /// Values for SecurityType.
    enum Value
    {
        Undefined = 0,
        Stock = 1,
        Option = 2,
        Bond = 3,
        Right = 4,
        Commodity = 5,
        MutualFund = 6,
        Index = 7,
        Currency = 8,
        Count
    };

    /// Converts value of SecurityType to String
    static const char* toString(Value value);
    /// Converts value of SecurityType from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Strategy type for multi-leg order
struct QUESTRADELIBRARYAPI StrategyType
{
    /// Values for StrategyType.
    enum Value
    {
        Undefined = 0,
        CallsPuts = 1,
        Calls = 2,
        Puts = 3,
        CoveredCall = 4,
        MarriedPuts = 5,
        VerticalCallSpread = 6,
        VerticalPutSpread = 7,
        CalendarCallSpread = 8,
        CalendarPutSpread = 9,
        DiagonalCallSpread = 10,
        DiagonalPutSpread = 11,
        Collar = 12,
        Straddle = 13,
        Strangle = 14,
        ButterflyCall = 15,
        ButterflyPut = 16,
        IronButterfly = 17,
        CondorCall = 18,
        CondorPut = 19,
        IronCondor = 20,
        Custom = 21,
        SingleLeg = 22,
        Count
    };

    /// Converts value of StrategyType to String
    static const char* toString(Value value);
    /// Converts value of StrategyType from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Tick types for last trade of the quotes
struct QUESTRADELIBRARYAPI TickType
{
    /// Values for TickType.
    enum Value
    {
        Undefined = 0,
        Up = 1,
        Equal = 2,
        Down = 3,
        Count
    };

    /// Converts value of TickType to String
    static const char* toString(Value value);
    /// Converts value of TickType from String
    static Value fromString(const std::string& name);
};

/// @ingroup enums
/// @brief Types of accounts
struct QUESTRADELIBRARYAPI UserAccountType
{
    /// Values for UserAccountType.
    enum Value
    {
        Undefined = 0,
        Cash = 1,
        Margin = 2,
        TFSA = 3,
        RRSP = 4,
        SRRSP = 5,
        LRRSP = 6,
        LIRA = 7,
        LIF = 8,
        RIF = 9,
        SRIF = 10,
        LRIF = 11,
        RRIF = 12,
        PRIF = 13,
        RESP = 14,
        FRESP = 15,
        FX = 16,
        FXD = 17,
        Count
    };

    /// Converts value of UserAccountType to String
    static const char* toString(Value value);
    /// Converts value of UserAccountType from String
    static Value fromString(const std::string& name);
};

} // namespace QuestradeAPI

#endif // QUESTRADEAPI_COMMON_ENUMS_DEFINES_H