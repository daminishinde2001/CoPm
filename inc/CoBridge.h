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
#define PWB_SDO_CONFIG_PM_GROUP         0x2422
#define PWB_SDO_CONFIG_PM_OFFSET        0x2423

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


/**** 3rd-party PM image update ****/

#define PWB_SDO_UPDATE_START            0x2440
#define PWB_SDO_UPDATE_STATUS           0x2441
#define PWB_SDO_UPDATE_DATA_FRAME       0x2442
#define PWB_SDO_UPDATE_DATA_END         0x2443

enum TPwbUpdateState {
    PUS_PROCESSING = 0,
    PUS_READY_TO_RECEIVE,
    PUS_ERROR,
};

enum TPwbUpdateError {
    PUE_UNKOWN_REASON = 0,
    PUE_START_PRIMARY_ERASE_NO_RESP = 1,
    PUE_START_PRIMARY_ERASE_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_PRIMARY_BOOTLOADER_NO_RESP,
    PUE_START_PRIMARY_BOOTLOADER_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_SECONDARY_ERASE_NO_RESP,
    PUE_START_SECONDARY_ERASE_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_SECONDARY_BOOTLOADER_NO_RESP,
    PUE_START_SECONDARY_BOOTLOADER_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_PRIMARY_READ_VER_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_SECONDARY_READ_VER_UNEXPECTED_RESP_ADDR_ERROR,

    PUE_START_PRIMARY_ERASE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_PRIMARY_BOOTLOADER_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_SECONDARY_ERASE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_SECONDARY_BOOTLOADER_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_PRIMARY_READ_VER_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_SECONDARY_READ_VER_UNEXPECTED_RESP_GROUP_ID_ERROR,

    PUE_START_PRIMARY_READ_VER_SAME_ADDR_ERROR,
    PUE_START_SECONDARY_READ_VER_SAME_ADDR_ERROR,

    PUE_START_PRIMARY_CHK_SOFT_STATE_NO_RESP,
    PUE_START_PRIMARY_CHK_SOFT_STATE_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_PRIMARY_CHK_SOFT_STATE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_PRIMARY_CHK_SOFT_STATE_UNEXPECTED_RESP_SAME_ADDR_ERROR,
    PUE_START_SECONDARY_CHK_SOFT_STATE_NO_RESP,
    PUE_START_SECONDARY_CHK_SOFT_STATE_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_SECONDARY_CHK_SOFT_STATE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_SECONDARY_CHK_SOFT_STATE_UNEXPECTED_RESP_SAME_ADDR_ERROR,

    PUE_DATA_PRIMARY_WRITE_NO_RESP = 51,
    PUE_DATA_PRIMARY_WRITE_FAILURE,
    PUE_DATA_SECONDARY_WRITE_NO_RESP,
    PUE_DATA_SECONDARY_WRITE_FAILURE,
    PUE_DATA_PRIMARY_INVALID_SEQUENCE_NUMBER,
    PUE_DATA_SECONDARY_INVALID_SEQUENCE_NUMBER,

    PUE_END_PRIMARY_UPDATE_NO_RESP = 71,
    PUE_END_PRIMARY_UPDATE_FAILURE,
    PUE_END_PRIMARY_VERSION_NO_RESP,
    PUE_END_PRIMARY_WRONG_VERSION,
    PUE_END_SECONDARY_UPDATE_NO_RESP,
    PUE_END_SECONDARY_UPDATE_FAILURE,
    PUE_END_SECONDARY_VERSION_NO_RESP,
    PUE_END_SECONDARY_WRONG_VERSION,
    PUE_END_NOT_GET_SERIAL_NUMBER,
};


// TPwbUpdateStatus is the data field of PWB_SDO_UPDATE_STATUS

// state<1byte>              |    data<3bytes>
// =====================================================================
// Processing                |    empty
// ---------------------------------------------------------------------
// ReadyToReceive            |    0: done
//                           |    1: upload image 1
//                           |    2: upload image 2
// ---------------------------------------------------------------------
// Error                     |    id<1byte>, detail<2bytes>

struct TPwbUpdateStatus {
    uint8_t  state;    // TPwbUpdateState

    union {
        uint8_t  expectedImageIndex;

        struct {
            uint8_t  id;    // TPwbUpdateError
            uint16_t detail;
        } error;
    } data;
};

#pragma pack()

#endif // __INTERFACE_COBRIDGE_H__
