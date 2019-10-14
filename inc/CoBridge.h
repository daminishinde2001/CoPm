// Before updating this file, first update the definition / description
// document ICD_Guiletta_CANopen.doc

#ifndef __INTERFACE_COBRIDGE_H__
#define __INTERFACE_COBRIDGE_H__

#include <stdint.h>

#pragma pack(1)

#define PWB_SDO_PM_OUTPUT               0x2400
#define PWB_SDO_PM_STATUS               0x2401
#define PWB_SDO_INTERLINK_DC_CONTACTOR  0x2402
#define PWB_SDO_PM_MAX_OUTPUT           0x2403

#define PWB_SDO_CONFIG_PM_TYPE          0x2420
#define PWB_SDO_CONFIG_PM_TOPOLOGY      0x2421


typedef struct
{
    union
    {
        struct
        {
            uint8_t bfDCOutputShortCircuit : 1;
            uint8_t bfReserved1 : 1;
            uint8_t bfReserved2 : 1;
            uint8_t bfReserved3 : 1;
            uint8_t bfInSleeping : 1;
            uint8_t bfReserved4 : 1;
            uint8_t bfReserved5 : 1;
            uint8_t bfReserved6 : 1;
        }bits;

        uint8_t data;
    }tab0;

    union
    {
        struct
        {
            uint8_t bfShutdownOnDcSide : 1;
            uint8_t bfPowerModuleFault : 1;
            uint8_t bfPowerModuleProtected : 1;
            uint8_t bfFanFailure : 1;
            uint8_t bfTemperatureOverhigh : 1;
            uint8_t bfDcOutputOvervoltage : 1;
            uint8_t bfWalkInEnabled : 1;
            uint8_t bfCommunicationLost : 1;
        }bits;

        uint8_t data;
    }tab1;

    union
    {
        struct
        {
            uint8_t bfPowerIsLimited : 1;
            uint8_t bfRepeatedModuleId : 1;
            uint8_t bfUnequalSharingCurrent : 1;
            uint8_t bfAcInputPhaseLost : 1;
            uint8_t bfAcInputPhaseUnbalanced : 1;
            uint8_t bfAcInputUndervoltage : 1;
            uint8_t bfAcInputOvervoltage : 1;
            uint8_t bfShutdownOnPfcSide : 1;
        }bits;

        uint8_t data;
    }tab2;
}TPwbStateInfy;

typedef struct
{
    union
    {
        struct
        {
            uint8_t bfPowerModuleShutdown : 1;
            uint8_t bfPowerModuleFault : 1;
            uint8_t bfCurrentIsLimited : 1;
            uint8_t bfFanFailure : 1;
            uint8_t bfAcInputOvervoltage : 1;
            uint8_t bfAcInputUndervoltge : 1;
            uint8_t bfDcOutputOvervoltage : 1;
            uint8_t bfDcOutputUndervoltage : 1;
        }bits;

        uint8_t data;
    }tab0;

    union
    {
        struct
        {
            uint8_t bfProtectedAsOvercurrent : 1;
            uint8_t bfProtectedAsOvertemperature : 1;
            uint8_t bfSetToShutdown : 1;
            uint8_t bfReserved1 : 5;
        }bits;

        uint8_t data;
    }tab1;

    uint8_t tab2; //reserved
}TPwbStateIncr;

typedef struct
{
    union
    {
        struct
        {
            uint8_t bfAcInputOvervoltage : 1;
            uint8_t bfAcInputUndervoltage : 1;
            uint8_t bfProtectedAsAcOvervoltage : 1;
            uint8_t bfReserved1 : 1;
            uint8_t bfReserved2 : 1;
            uint8_t bfReserved3 : 1;
            uint8_t bfDcOutputOvervoltage : 1;
            uint8_t bfProtectedAsDcOvervoltage : 1;
        }bits;

        uint8_t data;
    }tab0;

    union
    {
        struct
        {
            uint8_t bfDcOutputUndervoltage : 1;
            uint8_t bfFanFailure : 1;
            uint8_t bfReserved1 : 1;
            uint8_t bfReserved2 : 1;
            uint8_t bfAmbientOvertemperature : 1;
            uint8_t bfReserved3 : 1;
            uint8_t bfProtectedAsPfcTemperature1 : 1;
            uint8_t bfProtectedAsPfcTemperature2 : 1;
        }bits;

        uint8_t data;
    }tab1;

    union
    {
        struct
        {
            uint8_t bfProtectedAsDcTemperature1 : 1;
            uint8_t bfProtectedAsDcTemperature2 : 1;
            uint8_t bfCommunicationFaultBetweenPfcAndDcdc : 1;
            uint8_t bfReserved1 : 1;
            uint8_t bfPfcFault : 1;
            uint8_t bfDcdcFault : 1;
            uint8_t bfReserved2 : 1;
            uint8_t bfDcdcShutdown : 1;
        }bits;

        uint8_t data;
    }tab2;
}TPwbStateUugr;

typedef struct
{
    uint8_t    temperature;
    union
    {
        TPwbStateInfy    infy;
        TPwbStateIncr    incr;
        TPwbStateUugr    uugr;
    }state;
}TPwbPmState;

enum TPwbPowerModuleType
{
    PWB_UNDEFINED = 0,
    PWB_INFY50030,
    PWB_INFY75025,
    PWB_INFY100025,
    PWB_INCR50030,
    PWB_INCR75025,
    PWB_UUGR100030,
};

inline const char* PwbTypeString(TPwbPowerModuleType PmType)
{
    const char* retValue = "Undefined";

    switch(PmType)
    {
    case PWB_INFY50030:  retValue = "Infy,500V/30A"; break;
    case PWB_INFY75025:  retValue = "Infy,750V/25A"; break;
    case PWB_INFY100025:  retValue = "Infy,1000V/25A"; break;
    case PWB_INCR50030:  retValue = "Increase,500V/30A"; break;
    case PWB_INCR75025:  retValue = "Increase,750V/25A"; break;
    case PWB_UUGR100030:  retValue = "UuGreen,1000V/30A"; break;
    default: break;
    }

    return retValue;
}

enum TPwbInterlinkDcContactorWrite
{
    PWB_INTERLINK_FORCED_OFF = 0,
    PWB_INTERLINK_TIMED_ENABLE,

    // 2..254, reserved, do not use
    PWB_INTERLINK_FORCED_ENABLE = 255,
};

enum TPwbInterlinkDcContactorRead
{
    PWB_INTERLINK_OPEN = 0,
    PWB_INTERLINK_CLOSED,
};

typedef struct
{
    uint16_t    voltage;
    uint16_t    current;
}TPwbVI;

typedef union
{
    struct
    {
        uint32_t m_bInterlinkDCPlusClose:1;
        uint32_t m_bInterlinkDCMinusrClose:1;
        uint32_t m_bHasOutletError:1;
        uint32_t m_bHasConfigurationError:1;
        uint32_t m_unused:28;
    }m_bits;
    uint32_t m_data;
}TPwbStatus;

typedef struct
{
    TPwbStatus  m_status;
    uint16_t    m_reserved0;
    uint16_t    m_reserved1;
}PWB_PDO_1;


#pragma pack()

#endif // __INTERFACE_COBRIDGE_H__
