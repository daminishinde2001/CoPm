
// When updating the interface do update the description ICD also
// ...\OpsFs\07. Projects\05. Charger SW\03. Design\Shared\ICD_Terra_Canopen_objects.doc

#ifndef __INTERFACE_COPM_H__
#define __INTERFACE_COPM_H__

#include <stdint.h>

#define PM_SDO_CONV_ENABLE                     0x2100
#define PM_SDO_CONV_STATUS                     0x2101
enum {
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
#define PM_SDO_CONV_TEMP                       0x2104
#define PM_SDO_AC_INPUT_U                      0x2105
#define PM_SDO_AC_INPUT_I                      0x2106
#define PM_SDO_DC_OUTPUT_U                     0x2107
#define PM_SDO_DC_OUTPUT_I                     0x2108
#define PM_SDO_DC_OUTPUT_U_SETPOINT            0x2109
#define PM_SDO_DC_OUTPUT_I_SETPOINT            0x210a
#define PM_SDO_DC_OUTPUT_I_SLOPE_LIMIT         0x210b

#define PM_SDO_CAPABILITIES                    0x2110
#define PM_SDO_CAPABILITIES_NR_OF_ELEMENTS_IDX      0
#define PM_SDO_CAPABILITIES_VERSION_IDX             1
#define PM_SDO_CAPABILITIES_AC_U_MIN_MAX_IDX        2
#define PM_SDO_CAPABILITIES_AC_I_MIN_MAX_IDX        3
#define PM_SDO_CAPABILITIES_DC_U_MIN_MAX_IDX        4
#define PM_SDO_CAPABILITIES_DC_I_MIN_MAX_IDX        5
#define PM_SDO_CAPABILITIES_TEMP_MIN_MAX_IDX        6
#define PM_SDO_CAPABILITIES_POWER_MAX_IDX           7

#define PM_SDO_COOLING_PARAMETERS              0x2117
#define PM_SDO_COOLING_PARMS_NR_OF_ELEMENTS_IDX     0
#define PM_SDO_COOLING_PARMS_VERSION_IDX            1
#define PM_SDO_COOLING_PARMS_TOPOLOGY_IDX           2
#define PM_SDO_COOLING_PARMS_AIRFLOW_IDX            3
#define PM_SDO_COOLING_PARMS_MIN_FAN_PWM_IDX        4

#define PM_SDO_CURRENT_TRANSFER_RATIO          0x211a
#define PM_SDO_NUMBER_OF_PHASES                0x211b

#pragma pack(1)
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
#pragma pack()

#endif // __INTERFACE_COPM_H__
