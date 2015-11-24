
// When updating the interface do update the description ICD also
// ...\OpsFs\07. Projects\05. Charger SW\03. Design\Shared\ICD_Terra_Canopen_objects.doc

#ifndef __INTERFACE_COPM_H__
#define __INTERFACE_COPM_H__

#include <stdint.h>
#include <string>

#pragma pack(1)

#define PM_SDO_CONV_ENABLE                     0x2100
enum TPmConverterControl
{
    PM_CONVERTER_OFF = 0,
    PM_CONVERTER_ENABLE = 1,
    PM_CONVERTER_START_SELF_TEST = 4,
    PM_CONVERTER_CLEAR_ERRORS = 6
};
#define PM_SDO_CONV_STATUS                     0x2101
enum TPmConverterStatus
{
    PM_STATUS_ENABLED                       = 1<<0,
    PM_STATUS_GLOBAL_ERROR                  = 1<<1,
    PM_STATUS_INPUT_OVER_VOLTAGE_PROTECT    = 1<<2,
    PM_STATUS_INPUT_UNDER_VOLTAGE_PROTECT   = 1<<3,
    PM_STATUS_OUTPUT_OVER_VOLTAGE_PROTECT   = 1<<4,
    PM_STATUS_OUTPUT_UNDER_VOLTAGE_PROTECT  = 1<<5,
    PM_STATUS_FAN_FAILURE                   = 1<<6,
    PM_STATUS_OVER_TEMPERATURE_DETECT       = 1<<7,
    PM_STATUS_INPUT_OVER_CURRENT_PROTECT    = 1<<8,
    PM_STATUS_OUTPUT_OVER_CURRENT_PROTECT   = 1<<9,
    PM_STATUS_AUX_SUPPLY                    = 1<<10,
    PM_STATUS_INTERLOCK                     = 1<<11,
    PM_STATUS_RESET_DETECTED                = 1<<12,
    PM_STATUS_SETPOINT_TIMEOUT              = 1<<13,
    PM_STATUS_SETPOINT_NOT_MET              = 1<<14,
    PM_STATUS_PFC_ERROR                     = 1<<15
};

inline std::string PmStatus2String(int PmStatus)
{
    std::string retValue = "Undefined";

    switch(PmStatus)
    {
    case PM_STATUS_ENABLED:                      retValue = "PM_STATUS_ENABLED"; break;
    case PM_STATUS_GLOBAL_ERROR:                 retValue = "PM_STATUS_GLOBAL_ERROR"; break;
    case PM_STATUS_INPUT_OVER_VOLTAGE_PROTECT:   retValue = "PM_STATUS_INPUT_OVER_VOLTAGE_PROTECT"; break;
    case PM_STATUS_INPUT_UNDER_VOLTAGE_PROTECT:  retValue = "PM_STATUS_INPUT_UNDER_VOLTAGE_PROTECT"; break;
    case PM_STATUS_OUTPUT_OVER_VOLTAGE_PROTECT:  retValue = "PM_STATUS_OUTPUT_OVER_VOLTAGE_PROTECT"; break;
    case PM_STATUS_OUTPUT_UNDER_VOLTAGE_PROTECT: retValue = "PM_STATUS_OUTPUT_UNDER_VOLTAGE_PROTECT"; break;
    case PM_STATUS_FAN_FAILURE:                  retValue = "PM_STATUS_FAN_FAILURE"; break;
    case PM_STATUS_OVER_TEMPERATURE_DETECT:      retValue = "PM_STATUS_OVER_TEMPERATURE_DETECT"; break;
    case PM_STATUS_INPUT_OVER_CURRENT_PROTECT:   retValue = "PM_STATUS_INPUT_OVER_CURRENT_PROTECT"; break;
    case PM_STATUS_OUTPUT_OVER_CURRENT_PROTECT:  retValue = "PM_STATUS_OUTPUT_OVER_CURRENT_PROTECT"; break;
    case PM_STATUS_AUX_SUPPLY:                   retValue = "PM_STATUS_AUX_SUPPLY"; break;
    case PM_STATUS_INTERLOCK:                    retValue = "PM_STATUS_INTERLOCK"; break;
    case PM_STATUS_RESET_DETECTED:               retValue = "PM_STATUS_RESET_DETECTED"; break;
    case PM_STATUS_SETPOINT_TIMEOUT:             retValue = "PM_STATUS_SETPOINT_TIMEOUT"; break;
    case PM_STATUS_SETPOINT_NOT_MET:             retValue = "PM_STATUS_SETPOINT_NOT_MET"; break;
    case PM_STATUS_PFC_ERROR:                    retValue = "PM_STATUS_PFC_ERROR"; break;
    }

    return retValue;
}

#define PM_SDO_CONV_TEMP                       0x2104
#define PM_SDO_DEFECT_REASON                   0x2105
#define PM_SDO_LAST_REASON                     0x2106
#define PM_SDO_DC_OUTPUT_U                     0x2107
#define PM_SDO_DC_OUTPUT_I                     0x2108
#define PM_SDO_DC_OUTPUT_U_SETPOINT            0x2109
#define PM_SDO_DC_OUTPUT_I_SETPOINT            0x210a
#define PM_SDO_DC_OUTPUT_I_SLOPE_LIMIT         0x210b
#define PM_SDO_VOLTAGE_SETPOINT_OFFSET         0x210d
#define PM_SDO_CONV_INHIBIT                    0x210e
#define PM_SDO_COMV_INHIBIT_NR_OF_ELEMENTS_IDX      0
#define PM_SDO_COMV_INHIBIT_ON_USER_REQUEST_IDX     1
#define PM_SDO_COMV_INHIBIT_NOT_DISCOVERED_IDX      2

#define PM_SDO_CAPABILITIES                    0x2110
#define PM_SDO_CAPABILITIES_NR_OF_ELEMENTS_IDX      0
#define PM_SDO_CAPABILITIES_VERSION_IDX             1
#define PM_SDO_CAPABILITIES_AC_U_MIN_MAX_IDX        2
#define PM_SDO_CAPABILITIES_AC_I_MIN_MAX_IDX        3
#define PM_SDO_CAPABILITIES_DC_U_MIN_MAX_IDX        4
#define PM_SDO_CAPABILITIES_DC_I_MIN_MAX_IDX        5
#define PM_SDO_CAPABILITIES_TEMP_MIN_MAX_IDX        6
#define PM_SDO_CAPABILITIES_POWER_MAX_IDX           7

#define PM_SDO_MEASUREMENTS                    0x2111
#define PM_SDO_MEASUREMENTS_NR_OF_ELEMENTS_IDX          0
#define PM_SDO_MEASUREMENTS_INPUT_CURRENT_1             1
#define PM_SDO_MEASUREMENTS_INPUT_CURRENT_2             2
#define PM_SDO_MEASUREMENTS_INPUT_CURRENT_3             3
#define PM_SDO_MEASUREMENTS_INPUT_VOLTAGE_1             4
#define PM_SDO_MEASUREMENTS_INPUT_VOLTAGE_2             5
#define PM_SDO_MEASUREMENTS_INPUT_VOLTAGE_3             6
#define PM_SDO_MEASUREMENTS_OUTPUT_VOLTAGE_AFTER_DIODE  7
#define PM_SDO_MEASUREMENTS_OUTPUT_VOLTAGE_BEFORE_DIODE 8
#define PM_SDO_MEASUREMENTS_OUTPUT_CURRENT              9

#define PM_SDO_MEASUREMENTS_TEMPERATURE        0x2112
#define PM_SDO_MEASUREMENTS_TEMP_NR_OF_ELEMENTS_IDX 0
#define PM_SDO_MEASUREMENTS_TEMP_IGBT1              1
#define PM_SDO_MEASUREMENTS_TEMP_RECTIFIER1         2
#define PM_SDO_MEASUREMENTS_TEMP_IGBT3              3
#define PM_SDO_MEASUREMENTS_TEMP_OUTPUT_DIODE       4
#define PM_SDO_MEASUREMENTS_TEMP_INDUCTOR1          5
#define PM_SDO_MEASUREMENTS_TEMP_TRANSFORMER1       6
#define PM_SDO_MEASUREMENTS_TEMP_INDUCTOR3          7
#define PM_SDO_MEASUREMENTS_TEMP_TRANSFORMER3       8
#define PM_SDO_MEASUREMENTS_TEMP_DCB0               9
#define PM_SDO_MEASUREMENTS_TEMP_DCB1              10
#define PM_SDO_MEASUREMENTS_TEMP_DSP               11

#define PM_SDO_FAN_SPEED                       0x2113
#define PM_SDO_FAN_TACHO                       0x2114

#define PM_SDO_TEMPERATURE_PREDICTIONS         0x2116
#define PM_SDO_TEMP_PREDICTIONS_NR_OF_ELEMENTS      0
#define PM_SDO_TEMP_PREDICTIONS_INDUCTOR_CORE_1     1
#define PM_SDO_TEMP_PREDICTIONS_INDUCTOR_COIL_1     2
#define PM_SDO_TEMP_PREDICTIONS_INDUCTOR_CORE_2     3
#define PM_SDO_TEMP_PREDICTIONS_INDUCTOR_COIL_2     4
#define PM_SDO_TEMP_PREDICTIONS_INDUCTOR_CORE_3     5
#define PM_SDO_TEMP_PREDICTIONS_INDUCTOR_COIL_3     6
#define PM_SDO_TEMP_PREDICTIONS_TRANSFORMER_CORE_1  7
#define PM_SDO_TEMP_PREDICTIONS_TRANSFORMER_COIL_1  8
#define PM_SDO_TEMP_PREDICTIONS_TRANSFORMER_CORE_2  9
#define PM_SDO_TEMP_PREDICTIONS_TRANSFORMER_COIL_2 10
#define PM_SDO_TEMP_PREDICTIONS_TRANSFORMER_CORE_3 11
#define PM_SDO_TEMP_PREDICTIONS_TRANSFORMER_COIL_3 12

#define PM_SDO_COOLING_PARAMETERS              0x2117
#define PM_SDO_COOLING_PARMS_NR_OF_ELEMENTS_IDX     0
#define PM_SDO_COOLING_PARMS_VERSION_IDX            1
#define PM_SDO_COOLING_PARMS_TOPOLOGY_IDX           2
#define PM_SDO_COOLING_PARMS_AIRFLOW_IDX            3
#define PM_SDO_COOLING_PARMS_MIN_FAN_PWM_IDX        4

#define PM_SDO_CURRENT_TRANSFER_RATIO          0x211a
#define PM_SDO_NUMBER_OF_PHASES                0x211b

#define PM_SDO_BIST_RESULTS                    0x2141

#define PM_SDO_BIST_RESULT_GLOBAL_BOARD_TEST1_IDX   1
#define PM_SDO_BIST_RESULT_GLOBAL_BOARD_TEST2_IDX   2
#define PM_SDO_BIST_RESULT_TEMPERATURE_IDX          3
#define PM_SDO_BIST_RESULT_CONVERTER1_IDX           4
#define PM_SDO_BIST_RESULT_CONVERTER2_IDX           5
#define PM_SDO_BIST_RESULT_CONVERTER3_IDX           6

typedef union {
    struct {
        uint16_t m_chargerOn:1;
        uint16_t m_globalError:1;
        uint16_t m_inputOverVoltageDetect:1;
        uint16_t m_inputUnderVoltageDetect:1;
        uint16_t m_outputOverVoltageDetect:1;
        uint16_t m_outputUnderVoltageDetect:1;
        uint16_t m_fanFailure:1;
        uint16_t m_overTemperatureDetect:1;
        uint16_t m_inputOverCurrentProtect:1;
        uint16_t m_outputOverCurrentProtect:1;
        uint16_t m_auxUnderVoltageDetect:1;
        uint16_t m_interlock:1;
        uint16_t m_resetDetect:1;
        uint16_t m_unused:2;
        uint16_t m_cccvMode:1;
    }           m_bits;
    uint16_t    m_value;
} TPmStatus;

struct PM_PDO_1
{
    uint16_t    m_voltage;
    uint16_t    m_current;
    int16_t     m_temperature;
    TPmStatus   m_status;
};

#define PM_SDO_CONV_TEMP_MASK   0x3FF

// Test results definitions
#define PM_TR_NOT_TESTED       0
#define PM_TR_TEST_FAILED      1
#define PM_TR_RESERVED         2
#define PM_TR_TEST_PASSED      3

// the test results are reported with several SDOs
// 2 general SDOs with general board info
// one SDO for each channel
// 1 SDO for temperature measurements
typedef union
{
    uint32_t ulAll;
    struct
    {
        uint32_t bfTestResult : 2;                 // bit 0..1
        // Passive tests
        uint32_t bfEeprom : 2;
        uint32_t bfFan : 2;
        uint32_t bfLEMReference : 2;
        uint32_t bfDcBusVoltageZero : 2;           // bit 8..9
        uint32_t bfDcCurrentZero : 2;
        uint32_t bfDumploadCurrentZero : 2;
        // active tests
        uint32_t bfAuxPower15V : 2;
        uint32_t bfAuxPower12V : 2;                // bit 16..17
        uint32_t bfSpiExtAdc : 2;
        // main output
        uint32_t bfDcOutputCurrent : 2;
        uint32_t bfBusVoltage : 2;
        uint32_t bfOutputVoltage : 2;              // bit 24..25
        // DC capacitors
        uint32_t bfDcCapacitors : 2;
        uint32_t bfDcBus : 2;
        // grid
        uint32_t bfGridConnection : 2;
    } bits;
} TPmBistResultGeneral1;

typedef union
{
    uint32_t ulAll;
    struct
    {
        uint32_t bfCpldInterlock : 2;              // bit 0..1
        uint32_t bfCpldOVP : 2;
        uint32_t bfCpldOCP : 2;
        uint32_t bfCpldReset : 2;
        uint32_t bfDcOutputVoltageZero : 2;        // bit 8..9
        uint32_t bfReserved2 : 2;
        // dumpload
        uint32_t bfDischargeSpeed : 2;
        uint32_t bfDumploadCurrentSense : 2;
        uint32_t bfDumploadPowerLimit : 2;         // bit 16..17
        uint32_t bfDcOutputOvp : 2;
        uint32_t bfReserved5 : 2;
        uint32_t bfReserved6 : 2;
        uint32_t bfReserved7 : 2;                  // bit 24..25
        uint32_t bfReserved8 : 2;
        uint32_t bfReserved9 : 2;
        uint32_t bfReserved10 : 2;
    } bits;
} TPmBistResultGeneral2;

typedef union
{
    uint32_t ulAll;
    struct
    {
        // passive tests
        uint32_t bfLEMZero : 2;                    // bit 0..1
        uint32_t bfReserved1: 2;
        uint32_t bfDcStageCurrentZero : 2;
        // active tests
        uint32_t bfAcVoltage : 2;
        uint32_t bfAcCurrent : 2;                  // bit 8..9
        uint32_t bfDvdt : 2;
        uint32_t bfResonantStage : 2;
        uint32_t bfDcCurrent : 2;
        uint32_t bfDcVoltage : 2;                  // bit 16..17
        uint32_t bfReserved2 : 2;
        uint32_t bfReserved3 : 2;
        uint32_t bfReserved4 : 2;
        uint32_t bfReserved5 : 2;                  // bit 24..25
        uint32_t bfReserved6 : 2;
        uint32_t bfReserved7 : 2;
        uint32_t bfReserved8 : 2;
    } bits;
} TPmBistConvXResult;

typedef union
{
    uint32_t ulAll;
    struct
    {
        uint32_t bfTemperatureADC : 2;
        uint32_t bfTemperatureIGBT1 : 2;
        uint32_t bfTemperatureRECT1 : 2;
        uint32_t bfTemperatureIGBT3 : 2;
        uint32_t bfTemperatureDiode : 2;
        uint32_t bfTemperatureInd1 : 2;
        uint32_t bfTemperatureTr1 : 2;
        uint32_t bfTemperatureInd3 : 2;
        uint32_t bfTemperatureTr3 : 2;
        uint32_t bfTemperaturePCB1 : 2;
        uint32_t bfTemperaturePCB2 : 2;
        uint32_t bfReserved1 : 2;
        uint32_t bfReserved2 : 2;
        uint32_t bfReserved3 : 2;
        uint32_t bfReserved4 : 2;
        uint32_t bfReserved5 : 2;
    } bits;
} TPmBistTemperatureControl;

#pragma pack()

#endif // __INTERFACE_COPM_H__
