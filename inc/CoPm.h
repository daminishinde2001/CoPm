#ifndef __INTERFACE_COPM_H__
#define __INTERFACE_COPM_H__

#include <stdint.h>

#pragma pack(1)

/// # 21xx Power Converter (DCB)
/// | Object index | description                    | r/w | unit   | size / type            | persist |
/// |--------------|--------------------------------|-----|--------|------------------------|---------|
/// | 2100         | power convertor enable         | r/w | \-     | uint16                 |         |
/// | 2101         | power convertor status         | r   | \-     | uint16                 |         |
/// | 2102         | Power converter V/I status     | r   | \-     | uint16                 |         |
/// | 2103         | PFC errors                     | r   | \-     | uint16                 |         |
/// | 2104         | Temperature headroom           | r   | 0.1 °C | int16                  |         |
/// | 2105         | Defect reason                  | r   |        | uint16                 |         |
/// | 2106         | Last error/status              | r   |        | uint16                 |         |
/// | 2107         | DC output voltage              | r   | 0.1V   | uint16                 |         |
/// | 2108         | DC output current              | r   | 0.1A   | uint16                 |         |
/// | 2109         | DC output voltage setpoint     | r/w | 0.1V   | uint16                 |         |
/// | 210a         | DC output current setpoint     | r/w | 0.1A   | uint16                 |         |
/// | 210b         | DC current slope               | r/w | 0.1A/s | uint16                 |         |
/// | 210c         | DC voltage slope               | r/w | 0.1V/s | uint16                 |         |
/// | 210d         | Voltage setpoint offset        | r/w | mV     | uint16                 |         |
/// | 210e         | Convertor is enabled           | r/w |        | uint16                 | X       |
/// | 2110 [0..x]  | Capabilities                   | r   |        |                        |         |
/// | 2111 [0..9]  | Measurements V/I               | r   |        |                        |         |
/// | 2112 [0..11] | Measurements temperature       | r   | 0.1 °C |                        |         |
/// | 2113         | Fan speed                      | r/w | %      | uint8                  |         |
/// | 2114         | Fan tacho                      | r   | rpm    | uint16                 |         |
/// | 2116 [0..4]  | Temperature predictions        | r   | 0.1 °C |                        |         |
/// | 2117 [0..4]  | Cooling parameters             | r/w |        |                        | X       |
/// | 211a         | Current transfer ratio         | r   | \*256  | uint16                 |         |
/// | 211b         | Number of input phases         | r   |        | uint16                 |         |
/// | 2130 [0..24] | None volatile statistics       | r/w |        | uint32                 |         |
/// | 2131         | Can statistics                 | r/w |        | uint32                 |         |
/// | 2132         | I2C statistics                 | r/w |        | uint32                 |         |
/// | 2133         | Temperature control statistics | r/w |        | uint32                 |         |
/// | 2134         | Power control statistics       | r/w |        | uint32                 |         |
/// | 2135         | Main statistics                | r/w |        | uint32                 |         |
/// | 2136         | Stack room                     | r/w |        | uint32                 |         |
/// | 2137         | RS232 statistics               | r/w |        | uint32                 |         |
/// | 2138         | PFC comm statistics            | r/w |        | uint32                 |         |
/// | 2139         | Eeprom statistics              | r/w |        | uint32                 |         |
/// | 2141 [0..6]  | BIST results                   | r   |        | uint32                 |         |
/// |              |                                |     |        |                        |         |
/// | 2150         | Power board version            | r/w | String | 4                      | X       |
/// | 2151         | NTC board version              | r/w | String | 4                      | X       |
/// | 2152         | Production date                | r/w |        | uint32                 | X       |
/// | 2153         | Power module serial            | r/w |        | uint32                 | X       |
/// | 2154         | Obsolete: DCB serial           | r/w |        | uint32                 | X       |
/// | 2155         | DCB HW version                 | r/w | String | 4                      | X       |
/// | 2156         | CAN ID                         | r/w |        | uint8                  | X       |
/// | 2157         | CAN termination enable         | r/w |        | uint8                  | X       |
/// | 2158         | Converter type                 | r/w |        | uint16                 | X       |
/// | 2159         | HW components identifiers      | r/w |        | uint16                 | X       |
/// | 215a         | Calibration parameters         | r/w |        | uint16                 | X       |
/// | 215b         | 4epy code of whole assembly    | r/w |        | uint32                 | X       |
/// | 215c         | Hardware ID                    | r/w |        | uint8                  | X       |
/// |              |                                |     |        |                        |         |
/// | 21e0         | Debug variable address         | r/w |        | uint32                 |         |
/// | 21e1         | Debug variable value           | r/w |        | float                  |         |
/// | 21e2[]       | Regulation parameter           | r/w |        | several                |         |
/// | 21e3[]       | Open Loop variables            | r/w |        | several                |         |
/// |              |                                |     |        |                        |         |
/// | 21f0         | Analog debug select            |     |        |                        |         |
/// | 21f1         | Snapshot number                |     |        |                        |         |
/// | 21f2         | Tweak values NV                |     |        |                        |         |
/// | 21f3         | Tweak values VOL               |     |        |                        |         |
/// |              |                                |     |        |                        |         |
/// | 2ff3         | Read eeprom                    | r   |        | uint16                 |         |
/// | 2ff4         | Write eeprom                   | w   |        | uint16                 |         |
/// | 2ff5         | Disable protections            | w   |        | uint16                 |         |
/// |              |                                |     |        |                        |         |
/// | 2ffe         | Watchdog test                  | w   |        |                        |         |
/// | 2fff         | Board reset                    | w   |        |                        |         |
/// |              |                                |     |        |                        |         |
/// | 8000         | Frequency                      |     |        |                        |         |
/// | 8001         | Dead time                      |     |        |                        |         |
/// | 8002         | Gate enable                    |     |        |                        |         |
/// | 8003         | Dumpload                       |     |        |                        |         |
/// | 8004         | OPV level                      |     |        |                        |         |
/// |              |                                |     |        |                        |         |
/// | 8010         | ADC raw                        |     |        |                        |         |
/// |              |                                |     |        |                        |         |
/// | 8020         | Control bus                    |     |        |                        |         |
/// |              |                                |     |        |                        |         |
/// | 1800 [5]     | tpdo1 event timer              | r/w | ms     | uint16                 |         |
/// | tpdo1        | output and status objects      | r   | \-     | 2107, 2108, 2104, 2101 |         |
/// | tpdo2        | Snapshot buffer dump           | r   |        |                        |         |
/// | tpdo3        | Constraint change message      | r   |        |                        |         |

#define PM_SDO_CONV_ENABLE                     0x2100
/// This object can be used to enable a power converter
///
/// write:
///
/// | Value  | Description              |
/// |--------|--------------------------|
/// | 0      | Converter off            |
/// | 1      | Converter enable         |
/// | 4      | Start built-in self test |
/// | 6      | Clear errors             |
/// | others | reserved                 |
///
/// Note: Self test can only be started when converter is in the off/error state
/// (not when running)
///
/// read:
///
/// | Value  | Description (state)                                         |
/// |--------|-------------------------------------------------------------|
/// | 0      | Converter off                                               |
/// | 1      | Converter running                                           |
/// | 2      | Converter error                                             |
/// | 3      | Converter in self test                                      |
/// | 4      | Converter defect (see defect reason register for more info) |
/// | 5      | Waiting for PFC to be ready (1 phase module)                |
/// | 6      | Waiting for PFC to be idle (1 phase module)                 |
/// | 7      | Wrong config (some eeprom fields not properly set)          |
/// | others | reserved                                                    |


enum TPmConverterControl
{
    PM_CONVERTER_OFF = 0,
    PM_CONVERTER_ENABLE = 1,
    PM_CONVERTER_START_SELF_TEST = 4,
    PM_CONVERTER_CLEAR_ERRORS = 6
};
#define PM_SDO_CONV_STATUS                     0x2101
/// This object can be used to read the power converter status
///
/// Low power converter status; ResConvDsp/10kW.
///
/// | bit    | description                     | value                     | board        |
/// |--------|---------------------------------|---------------------------|--------------|
/// | 0      | charger on                      | 0: off; 1: on             |              |
/// | 1      | global error flag               | 0: ok;  1: error          |              |
/// | 2      | input over voltage detect       | 0: ok;  1: error          |              |
/// | 3      | input under voltage detect      | 0: ok;  1: error          |              |
/// | 4      | output over voltage detect      | 0: ok;  1: error          |              |
/// | 5      | output under voltage detect     | 0: ok;  1: error          |              |
/// | 6      | fan failure                     | 0: ok;  1: error          | Digital only |
/// | 7      | over temperature detect         | 0: ok;  1: error          |              |
/// | 8      | input over current protect      | 0: ok;  1: error          | Digital only |
/// | 9      | output over current             | 0: ok;  1: error          | Digital only |
/// | 10     | auxiliary supply voltage detect | 0: ok;  1: error          | Digital only |
/// | 11     | interlock                       | 0: ok;  1: fault          | Digital only |
/// | 12     | reset detected                  | 0: ok;  1: reset detected | Digital only |
/// | 13     | Setpoint time out               | 0: ok;  1: time out       | Digital only |
/// | 14     | Setpoint not met                | 0: ok;  1: fault          | Digital only |
/// | 15     | PFC error                       | 0: ok;  1: fault          | Digital only |
/// | 16     | Dumpload too hot                | 0: ok;  1: fault          | Digital only |
/// | 17     | Dumpload error                  | 0: ok;  1: fault          | Digital only |
/// | 18     | CAN ID error (duplicate)        | 0: ok;  1: fault          | Digital only |
/// | 19     | Input current difference        | 0: ok;  1: fault          | Digital only |
/// | 20     | Eeprom error                    | 0: ok;  1: fault          | Digital only |
/// | others | reserved                        |                           |              |
///
/// High power converter status; DcbBuckBoost/50kW.
///
/// | bit    | description                                               | value                     | board        |
/// |--------|-----------------------------------------------------------|---------------------------|--------------|
/// | 0      | charger on                                                | 0: off; 1: on             |              |
/// | 1      | global error flag                                         | 0: ok;  1: error          |              |
/// | 2      | input over voltage detect                                 | 0: ok;  1: error          |              |
/// | 3      | input under voltage detect                                | 0: ok;  1: error          |              |
/// | 4      | output over voltage detect                                | 0: ok;  1: error          |              |
/// | 5      | setpoint failure. Voltage or current higher then setpoint | 0: ok;  1: error          |              |
/// | 6      | fan failure                                               | 0: ok;  1: error          | Digital only |
/// | 7      | over temperature detect                                   | 0: ok;  1: error          |              |
/// | 8      | coil current protect                                      | 0: ok;  1: error          | Digital only |
/// | 9      | output over current                                       | 0: ok;  1: error          | Digital only |
/// | 10     | hardware over-current protect                             | 0: ok;  1: error          | Digital only |
/// | 11     | interlock                                                 | 0: ok;  1: fault          | Digital only |
/// | 12     | fault discharge circuit                                   | 0: ok;  1: reset detected | Digital only |
/// | 13     | load dump                                                 | 0: ok;  1: time out       | Digital only |
/// | 14     | unused                                                    | 0: ok;  1: fault          | Digital only |
/// | 15     | fault fuse                                                | 0: ok;  1: fault          | Digital only |
/// | others | reserved                                                  |                           |              |

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

inline const char* PmStatus2String(int PmStatus)
{
    const char* retValue = "Undefined";

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

#define PM_SDO_CONV_VI_STATUS                  0x2102
/// This object can be used to read the V/I status
///
/// | bit    | Description                  | Value                                |
/// |--------|------------------------------|--------------------------------------|
/// | 0      | input current 1 OCP          | 0: ok; 1: error                      |
/// | 1      | input current 2 OCP          | 0: ok; 1: error                      |
/// | 2      | input current 3 OCP          | 0: ok; 1: error                      |
/// | 3      | input voltage 1 OVP          | 0: ok; 1: error                      |
/// | 4      | input voltage 2 OVP          | 0: ok; 1: error                      |
/// | 5      | input voltage 3 OVP          | 0: ok; 1: error                      |
/// | 6      | input voltage 1 UVP          | 0: ok; 1: error                      |
/// | 7      | input voltage 2 UVP          | 0: ok; 1: error                      |
/// | 8      | input voltage 3 UVP          | 0: ok; 1: error                      |
/// | 9      | Output voltage (after diode) | 0: ok; 1: error                      |
/// | 10     | Bus voltage (before diode)   | 0: ok; 1: error                      |
/// | 11     | output current               | 0: ok; 1: error                      |
/// | 12..13 | Converter mode               | 0: CC; 1: CV; 2: input current limit |
/// | 14     | reserved, should be 0        |                                      |
/// | 15     | reserved, should be 0        |                                      |
/// | others | reserved                     |                                      |
///
/// Error means that the signal has exceeded a threshold. This means that RMS or
/// peak value (or both) exceeded a threshold. Some signals also have a minimum
/// threshold (e.g. input voltage for UVP).
///
/// If one of these bits is set, then also one (or more) of the status flags in the
/// status registers (2101) is set.

#define PM_SDO_PFC_ERRORS                      0x2103
/// This object can be used to read the PFC errors
///
/// See PFC documentation

#define PM_SDO_CONV_TEMP                       0x2104
/// This object can be used to read the temperature headroom
///
/// This object contains the actual temperature headroom until OTP in steps of 0.1
/// °C. Also the current derating type that the receiver should apply when
/// requesting a current supply.
///
/// | Bit           | Description                                               |
/// |---------------|-----------------------------------------------------------|
/// | 0..9          | Temperature headroom                                      |
/// | 14..15        | Current derate algorithm                                  |
/// | Derating type | Description                                               |
/// | 0             | No derating                                               |
/// | 1             | Slope 1: 25..5 °C headroom -\> 100%..10% current (linear) |
/// | 2             | Slope 2: immediate -\> current 0A                         |
/// | others        | reserved                                                  |

#define PM_SDO_DEFECT_REASON                   0x2105
/// This object can be used to read the defect reason
///
/// When the defect reason is not equal to zero, then the converter will not operate
/// as one or more vital functions do not work properly.
///
/// | ID     | Description                    |
/// |--------|--------------------------------|
/// | 0      | No defect                      |
/// | 1      | Eeprom defect                  |
/// | 2      | Dumpload defect (safety issue) |
/// | others | reserved                       |

#define PM_SDO_LAST_REASON                     0x2106
/// This object can be used to read the last errors after clearing the errors

#define PM_SDO_DC_OUTPUT_U                     0x2107
/// This read-only object contains the actual output voltage in steps of 0.1V.

#define PM_SDO_DC_OUTPUT_I                     0x2108
/// This read-only object contains the actual output current in steps of 0.1A.

#define PM_SDO_DC_OUTPUT_U_SETPOINT            0x2109
/// This object contains the output voltage setpoint in steps of 0.1V.

#define PM_SDO_DC_OUTPUT_I_SETPOINT            0x210a
/// This object contains the output current setpoint, in steps of 0.1A.

#define PM_SDO_DC_OUTPUT_I_SLOPE_LIMIT         0x210b
/// This object contains the output current slope limit, in steps of 0.1A/s.
///
/// Default value = 30 A/s.
///
/// The output current can’t rise (or fall) faster than this setting.

#define PM_SDO_DC_OUTPUT_V_SLOPE_LIMIT         0x210c
/// This object contains the output voltage slope limit, in steps of 0.1V/s. Default
/// value = 500 V/s.

#define PM_SDO_VOLTAGE_SETPOINT_OFFSET         0x210d
/// This object contains the value which is added to the voltage setpoint. The unit
/// is in mV. This can be used for controlling the output current when more parallel
/// converters are working in CV mode (to balance the current in such a way that all
/// modules deliver the same current).

#define PM_SDO_CONV_INHIBIT                    0x210e
/// This object set a Power converter to disabled/inhibited
///
/// | subindex | Description                                               | r/w | unit | size/type |
/// |----------|-----------------------------------------------------------|-----|------|-----------|
/// | 0        | Number of elements                                        | r   | \-   | uint8     |
/// | 1        | Power convertor is disabled by trigger                    | r/w | \-   | uint16    |
/// | 2        | Power convertor is disabled because it was not discovered | r/w | \-   | uint16    |
/// | others   | reserved                                                  |     |      |           |
///
/// These values are persistent.

#define PM_SDO_COMV_INHIBIT_NR_OF_ELEMENTS_IDX      0
#define PM_SDO_COMV_INHIBIT_ON_USER_REQUEST_IDX     1
#define PM_SDO_COMV_INHIBIT_NOT_DISCOVERED_IDX      2

#define PM_SDO_CAPABILITIES                    0x2110
/// This read-only object contains the design limits of the power module. Sub-index
/// 1 of this object contains a version number for the definition of the remainder
/// of this object. For version 1, the definition is according to the table below:
///
/// | subindex | Description                  | r/w | unit   | size/type      |
/// |----------|------------------------------|-----|--------|----------------|
/// | 0        | number of elements           | r   | \-     | uint8          |
/// | 1        | object-version               | r   | \-     | uint8          |
/// | 2        | input voltage min, max (RMS) | r   | 0.1V   | uint16, uint16 |
/// | 3        | input current min, max (RMS) | r   | 0.1A   | uint16, uint16 |
/// | 4        | DC output voltage min, max   | r   | 0.1V   | uint16, uint16 |
/// | 5        | DC output current min, max   | r   | 0.1A   | uint16, uint16 |
/// | 6        | Temperature min, max         | r   | 0.1 C  | int16, int16   |
/// | 7        | Max power delivery           | r   | 0.1 kW | uint16         |
/// | others   | reserved                     |     |        |                |
///
/// When the size is 6 (sub-index 0) the max. power delivery is assumed to be
/// 10kWh. This configuration is used by the Analog Control Board (ACB).
/// When the size is 7, the max. power delivery is defined. This configuration
/// is used by the Digital Control Board or (DCB).

#define PM_SDO_CAPABILITIES_NR_OF_ELEMENTS_IDX      0
#define PM_SDO_CAPABILITIES_VERSION_IDX             1
#define PM_SDO_CAPABILITIES_AC_U_MIN_MAX_IDX        2
#define PM_SDO_CAPABILITIES_AC_I_MIN_MAX_IDX        3
#define PM_SDO_CAPABILITIES_DC_U_MIN_MAX_IDX        4
#define PM_SDO_CAPABILITIES_DC_I_MIN_MAX_IDX        5
#define PM_SDO_CAPABILITIES_TEMP_MIN_MAX_IDX        6
#define PM_SDO_CAPABILITIES_POWER_MAX_IDX           7

#define PM_SDO_MEASUREMENTS                    0x2111
/// This object reads all the measurements
///
/// | subindex | Description                              | r/w | unit | size/type |
/// |----------|------------------------------------------|-----|------|-----------|
/// | 0        | number of elements                       | r   | \-   | uint8     |
/// | 1        | Input current 1                          | r   | 0.1A | uint16    |
/// | 2        | Input current 2                          | r   | 0.1A | uint16    |
/// | 3        | Input current 3                          | r   | 0.1A | uint16    |
/// | 4        | Input voltage 1                          | r   | 0.1V | uint16    |
/// | 5        | Input voltage 2                          | r   | 0.1V | uint16    |
/// | 6        | Input voltage 3                          | r   | 0.1V | uint16    |
/// | 7        | Output voltage (after diode              | r   | 0.1V | uint16    |
/// | 8        | Bus voltage (before diode); same as 2107 | r   | 0.1V | uint16    |
/// | 9        | Output current; same as 2108             | r   | 0.1A | uint16    |
/// | others   | reserved                                 |     |      |           |

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
/// This object reads the temperature measurements
///
/// Low-power resonant-converter
///
/// | subindex | Description        | r/w | unit   | size/type |
/// |----------|--------------------|-----|--------|-----------|
/// | 0        | number of elements | r   | \-     | uint8     |
/// | 1        | IGBT1              | r   | 0.1 °C | uint16    |
/// | 2        | Rectifier1         | r   | 0.1 °C | uint16    |
/// | 3        | IGBT3              | r   | 0.1 °C | uint16    |
/// | 4        | Output diode       | r   | 0.1 °C | uint16    |
/// | 5        | Inductor1          | r   | 0.1 °C | uint16    |
/// | 6        | Transformer1       | r   | 0.1 °C | uint16    |
/// | 7        | Inductor3          | r   | 0.1 °C | uint16    |
/// | 8        | Transformer3       | r   | 0.1 °C | uint16    |
/// | 9        | DCB                | r   | 0.1 °C | uint16    |
/// | 10       | DCB                | r   | 0.1 °C | uint16    |
/// | 11       | DSP                | r   | 0.1 °C | uint16    |
/// | others   | reserved           |     |        |           |
///
/// High-power buck-boost converter.
///
/// | subindex | Description        | r/w | unit   | size/type |
/// |----------|--------------------|-----|--------|-----------|
/// | 0        | number of elements | r   | \-     | uint8     |
/// | 1        | Coil               | r   | 0.1 °C | uint16    |
/// | 2        | MA                 | r   | 0.1 °C | uint16    |
/// | 3        | MB                 | r   | 0.1 °C | uint16    |
/// | 4        | Cpu                | r   | 0.1 °C | uint16    |
/// | others   | reserved           |     |        |           |

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
/// This object set the fan speed
///
/// Normally, the cooling fan speed is automatically controlled by the Power Module
/// itself. Writing a value to this object will overrule the automatic control when
/// a higher speed is set by this object. If no value is received for 600 seconds,
/// the automatic control value will be used. This object is write only.

#define PM_SDO_FAN_TACHO                       0x2114
/// This object reads the actual measured fan speed in RPM.

#define PM_SDO_TEMPERATURE_PREDICTIONS         0x2116
/// This object reads the temperature predictions
///
/// | Subindex | Description        | r/w | unit   | size/type |
/// |----------|--------------------|-----|--------|-----------|
/// | 0        | number of elements | r   | \-     | uint8     |
/// | 1        | Inductor core 1    | r   | 0.1 °C | uint16    |
/// | 2        | Inductor coil 1    | r   | 0.1 °C | uint16    |
/// | 3        | Inductor core 2    | r   | 0.1 °C | uint16    |
/// | 4        | Inductor coil 2    | r   | 0.1 °C | uint16    |
/// | 5        | Inductor core 3    | r   | 0.1 °C | uint16    |
/// | 6        | Inductor coil 3    | r   | 0.1 °C | uint16    |
/// | 7        | Transformer core 1 | r   | 0.1 °C | uint16    |
/// | 8        | Transformer coil 1 | r   | 0.1 °C | uint16    |
/// | 9        | Transformer core 2 | r   | 0.1 °C | uint16    |
/// | 10       | Transformer coil 2 | r   | 0.1 °C | uint16    |
/// | 11       | Transformer core 3 | r   | 0.1 °C | uint16    |
/// | 12       | Transformer coil 3 | r   | 0.1 °C | uint16    |
/// | others   | reserved           |     |        |           |

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
/// This object reads the Cooling parameters
///
/// | Subindex | Description                                    | r/w | unit | size/type |
/// |----------|------------------------------------------------|-----|------|-----------|
/// | 0        | number of elements                             | r   | \-   | uint8     |
/// | 1        | Version number of cooling parameter definition | r   | \-   | uint8     |
/// | 2        | Ventilation topology (air direction):          | r   |      | uint16    |
/// |          | 0: front to back                               |     |      |           |
/// |          | 1: impinging (from the middle to sides)        |     |      |           |
/// |          | 2: undefined (mapped to front to back in dcb)  |     |      |           |
/// | 3        | Airflow                                        | r   | m3/h | uint16    |
/// | others   | reserved                                       |     |      |           |
///
/// These values are stored in Eeprom.

#define PM_SDO_COOLING_PARMS_NR_OF_ELEMENTS_IDX     0
#define PM_SDO_COOLING_PARMS_VERSION_IDX            1
#define PM_SDO_COOLING_PARMS_TOPOLOGY_IDX           2
#define PM_SDO_COOLING_PARMS_AIRFLOW_IDX            3
#define PM_SDO_COOLING_PARMS_MIN_FAN_PWM_IDX        4

#define PM_SDO_CURRENT_TRANSFER_RATIO          0x211a
/// This object reads the Current transfer ratio
///
/// This SDO returns a number that represents the ratio between input and output
/// current. The maximum input current is a known number (e.g. 16A). The maximum DC
/// output current is maximum input current \* current transfer ratio. The current
/// transfer ratio is \*256 to make it a fixed point number for the SDO. So maximum
/// DC output current = Max Iin \* (current transfer ratio / 256).
///
/// The power module calculates the CTR as follows:
///
/// CTR = (Vac(min) / Vdc ) \* Efficiency \* a
///
/// Where:
///
/// Vac min: the minimum input RMS voltage (of all input stages) e.g. 390Vac
///
/// a: 1 for single phase, and *sqrt*(3) for 3 phase
///
/// Vdc: output voltage (before output diode)

#define PM_SDO_NUMBER_OF_PHASES                0x211b
/// This object can be used to write and read the number of phase the grid connection has

#define PM_SDO_NV_STATISTICS                   0x2130
/// This object reads or writes the Non-volatile statistics
///
/// All values are 32bit. Values can also be written (to reset for example)
///
/// | Subindex | Description                               | unit       |
/// |----------|-------------------------------------------|------------|
/// | 0        | number of elements                        | \-(uint8)  |
/// |          | *System*                                  | All uint32 |
/// | 1        | Total uptime                              | Hours      |
/// | 2        | Total power time                          | ¼ Hours    |
/// | 3        | Number of cold starts                     |            |
/// | 4        | Number of Resets                          |            |
/// | 5        | Number of power activations (enables)     |            |
/// | 6        | Number of AC input voltage activations    |            |
/// | 7..16    | Reserved                                  |            |
/// |          | *Temperatures*                            | All uint32 |
/// | 17       | Minimum temperature headroom              |            |
/// | 18       | Number of OTPs                            |            |
/// | 19       | Max temperature IGBT1                     | 0.1 °C     |
/// | 20       | Max temperature Rectifier1                | 0.1 °C     |
/// | 21       | Max temperature IGBT3                     | 0.1 °C     |
/// | 22       | Max temperature Diode                     | 0.1 °C     |
/// | 23       | Max temperature Inductor 1                | 0.1 °C     |
/// | 24       | Max temperature Transformer 1             | 0.1 °C     |
/// | 25       | Max temperature Inductor 3                | 0.1 °C     |
/// | 26       | Max temperature Transformer 3             | 0.1 °C     |
/// | 27       | Max temperature DCB sensor 1              | 0.1 °C     |
/// | 28       | Max temperature DCB sensor 2              | 0.1 °C     |
/// | 29       | Min temperature DCB sensor 1              | 0.1 °C     |
/// | 30       | Min temperature DCB sensor 2              | 0.1 °C     |
/// | 31       | Max temperature CPU (not implemented yet) | 0.1 °C     |
/// | 32..37   | Reserved for other temperatures           |            |
/// |          | *Signals*                                 | All uint32 |
/// | 38       | Number of OVPs in                         |            |
/// | 39       | Number of OVPs out                        |            |
/// | 40       | Number of UVPs in                         |            |
/// | 41       | Number of UVPs out                        |            |
/// | 42       | Number of OCPs in                         |            |
/// | 43       | Number of OCPs out                        |            |
/// | 44       | Number of AUX UVPs                        |            |
/// | 45       | Maximum input voltage 1 (RMS)             | 0.1 V      |
/// | 46       | Maximum input voltage 2 (RMS)             | 0.1 V      |
/// | 47       | Maximum input voltage 3 (RMS)             | 0.1 V      |
/// | 48       | Maximum input current 1 (RMS)             | 0.1 A      |
/// | 49       | Maximum input current 2 (RMS)             | 0.1 A      |
/// | 50       | Maximum input current 3 (RMS)             | 0.1 A      |
/// | 51       | Maximum output voltage                    | 0.1 V      |
/// | 52       | Maximum output current                    | 0.1 A      |
/// | 53       | Number of OCPs by HW detection            |            |
/// | 54       | Number of OVPs out by HW detection        |            |
/// | 55..60   | Reserved                                  |            |
/// |          | *Faults*                                  | All uint32 |
/// | 61       | ADC I2C errors (temperature measurement)  |            |
/// | 62       | PFC faults (single phase module)          |            |
/// | 63       | Setpoint not met faults                   |            |
/// | 64       | Setpoint time out faults                  |            |
/// | 65       | Fan errors                                |            |
/// | 66..71   | Reserved                                  |            |
/// |          | *Built in self test*                      | All uint32 |
/// | 72       | Number of tests                           |            |
/// | 73       | Number of fails                           |            |
/// | 74       | Vin 1 max RMS                             | 0.1 V      |
/// | 75       | Vin 2 max RMS                             | 0.1 V      |
/// | 76       | Vin 3 max RMS                             | 0.1 V      |
/// | 77       | Vin 1 min RMS                             | 0.1 V      |
/// | 78       | Vin 2 min RMS                             | 0.1 V      |
/// | 79       | Vin 3 min RMS                             | 0.1 V      |
/// | 80       | I in 1 max RMS                            | 0.1 A      |
/// | 81       | I in 2 max RMS                            | 0.1 A      |
/// | 82       | I in 3 max RMS                            | 0.1 A      |
/// | 83       | I in 1 min RMS                            | 0.1 A      |
/// | 84       | I in 2 min RMS                            | 0.1 A      |
/// | 85       | I in 3 min RMS                            | 0.1 A      |
/// | 86       | I out 1 max                               | 0.1 A      |
/// | 87       | I out 2 max                               | 0.1 A      |
/// | 88       | I out 3 max                               | 0.1 A      |
/// | 89       | I out 1 min                               | 0.1 A      |
/// | 90       | I out 2 min                               | 0.1 A      |
/// | 91       | I out 3 min                               | 0.1 A      |
/// | 92       | Maximum resonance tank phase              |            |
/// | 93       | Minimum resonance tank phase              |            |
/// | 94       | Maximum dead time                         |            |
/// | 95       | Minimum dead time                         |            |
/// | 96       | Dumpload current max                      | 0.1 A      |
/// | 97       | Dumpload current min                      | 0.1 A      |
/// | 98       | Last failed result General                |            |
/// | 99       | Last failed result Temperature            |            |
/// | 100      | Last failed result Channel 1              |            |
/// | 101      | Last failed result Channel 2              |            |
/// | 102      | Last failed result Channel 3              |            |
/// | others   | reserved                                  |            |

#define PM_SDO_CAN_STATISTICS                  0x2131
/// This object reads the CAN statistics
/// -------------------
///
/// | subindex | Description                                    | Unit      |
/// |----------|------------------------------------------------|-----------|
/// | 0        | number of elements                             | \-(uint8) |
/// | 1        | Number of packets sent                         | uint32    |
/// | 2        | Number of unicast packets received             | uint32    |
/// | 3        | Number of broadcast packets received           | uint32    |
/// | 4        | Number of TX queue full                        | uint32    |
/// | 5        | Number of RX queue full                        | uint32    |
/// | 6        | Number of CAN errors                           | uint32    |
/// | 7        | Reserved                                       | uint32    |
/// | 8        | Number of TX timeouts                          | uint32    |
/// | 9        | Last Error (snapshot of HW error register)     | uint32    |
/// | 10       | Can status (state number of the state machine) | uint32    |
/// | 11       | Reset count                                    | uint32    |
/// | 12       | Reserved                                       | uint32    |
/// | 13       | PDO1 packets received                          | uint32    |
/// | others   | reserved                                       |           |

#define PM_SDO_I2C_STATISTICS                  0x2132
/// This object reads the I2C statistics
///
/// | subindex | Description                   | unit      |
/// |----------|-------------------------------|-----------|
/// | 0        | number of elements            | \-(uint8) |
/// | 1        | Number of I2C messages queued | uint32    |
/// | 2        | Number of queue full          | uint32    |
/// | 3        | Number of I2C time outs       | uint32    |
/// | 4        | Number of I2C NACKS           | uint32    |
/// | 5        | I2C Resets                    | uint32    |
/// | 6        | Read success                  | uint32    |
/// | 7        | Write success                 | uint32    |
/// | 8        | Read errors                   | uint32    |
/// | 9        | Write errors                  | uint32    |
/// | 10       | Current state                 | uint32    |
/// | 11       | Command register              | uint32    |
/// | 12       | Status register               | uint32    |
/// | others   | reserved                      |           |

#define PM_SDO_TEMPERATURE_CTRL_STATISTICS     0x2133
/// This object reads the Temperature control statistics
///
/// | Subindex | Description                           | unit      |
/// |----------|---------------------------------------|-----------|
/// | 0        | number of elements                    | \-(uint8) |
/// | 1        | Number of I2C ADC init errors         | uint32    |
/// | 2        | Number of I2C temperature read errors | uint32    |
/// | 3        | ADC inits                             | uint32    |
/// | 4        | Current fan PWM speed                 | uint32    |
/// | 5        | Current state                         | uint32    |
/// | 6        | ADC communication errors              | uint32    |
/// | others   | reserved                              |           |

#define PM_SDO_SYSTEM_STATISTICS               0x2135
/// This object reads the System statistics
/// ----------------------
///
/// | subindex | Description                                      | unit      |
/// |----------|--------------------------------------------------|-----------|
/// | 0        | number of elements                               | \-(uint8) |
/// | 1        | Up time since last reboot [seconds]              | uint32    |
/// | 2        | Max control execution time [11.11 ns units]      | uint32    |
/// | 3        | Max background execution time [11.11 ns units]   | uint32    |
/// | 4        | Min background execution time [11.11 ns units]   | uint32    |
/// | 5        | Converter errors                                 | uint32    |
/// | 6        | Number of PFC glitches suppressed (1 phase only) | uint32    |
/// | others   | reserved                                         |           |

#define PM_SDO_BIST_RESULTS                    0x2141
/// This object reads the BIST result (ResonantConverter)
/// ------------------------------------
///
/// The Built in Self test can only be activated when the converter is not in the
/// active state.
///
/// Note that the power module is not responsive for about 10 seconds after the test
/// was started. So when polling this SDO there will be no response for about 10
/// seconds. After 10 seconds the test should be finished.
///
/// | subindex | Description                     | r/w | Unit | size/type |
/// |----------|---------------------------------|-----|------|-----------|
/// | 0        | number of elements              | r   | \-   | uint8     |
/// | 1        | Global board test result1       | R   |      | uint32    |
/// | 2        | Global board test result2       | R   |      | uint32    |
/// | 3        | Temperature test results        | R   |      | uint32    |
/// | 4        | Converter channel1 test results | R   |      | uint32    |
/// | 5        | Converter channel2 test results | R   |      | uint32    |
/// | 6        | Converter channel3 test results | R   |      | uint32    |
/// | others   | reserved                        |     |      |           |
///
/// Global results1 (Subindex 1):
///
/// | **bit** | **Description**                                 |                                    |
/// |---------|-------------------------------------------------|------------------------------------|
/// | 0       | Total test result                               | 0: busy 1: failed: 3: passed       |
/// | 2       | Eeprom presence                                 | 0: not tested 1: failed: 3: passed |
/// | 4       | Fan                                             | 0: not tested 1: failed: 3: passed |
/// | 6       | LEM reference                                   | 0: not tested 1: failed: 3: passed |
/// | 8       | DC bus voltage zero                             | 0: not tested 1: failed: 3: passed |
/// | 10      | DC output current zero                          | 0: not tested 1: failed: 3: passed |
/// | 12      | Dumpload current zero                           | 0: not tested 1: failed: 3: passed |
/// | 14      | Aux 15V detected (voltage for the controls)     | 0: not tested 1: failed: 3: passed |
/// | 16      | Aux 12V detected (voltage for the external ADC) | 0: not tested 1: failed: 3: passed |
/// | 18      | External SPI ADC                                | 0: not tested 1: failed: 3: passed |
/// | 20      | DC output current                               | 0: not tested 1: failed: 3: passed |
/// | 22      | DC bus voltage                                  | 0: not tested 1: failed: 3: passed |
/// | 24      | DC output voltage                               | 0: not tested 1: failed: 3: passed |
/// | 26      | DC capacitors                                   | 0: not tested 1: failed: 3: passed |
/// | 28      | DC bus                                          | 0: not tested 1: failed: 3: passed |
/// | 30      | Grid connection                                 | 0: not tested 1: failed: 3: passed |
///
/// Global results2 (Subindex 2):
///
/// | **bit** | **Description**          |                                    |
/// |---------|--------------------------|------------------------------------|
/// | 0       | CPLD interlock           | 0: not tested 1: failed: 3: passed |
/// | 2       | CPLD OVP                 | 0: not tested 1: failed: 3: passed |
/// | 4       | CPLD OCP                 | 0: not tested 1: failed: 3: passed |
/// | 6       | CPLD reset               | 0: not tested 1: failed: 3: passed |
/// | 8       | DC output voltage zero   | 0: not tested 1: failed: 3: passed |
/// | 10      | Reserved                 | 3                                  |
/// | 12      | Dumpload discharge speed | 0: not tested 1: failed: 3: passed |
/// | 14      | Dumpload current sense   | 0: not tested 1: failed: 3: passed |
/// | 16      | Dumpload power limit     | 0: not tested 1: failed: 3: passed |
/// | 18      | DC output OVP            | 0: not tested 1: failed: 3: passed |
/// | 20      | DC bus leakage           | 0: not tested 1: failed: 3: passed |
/// | 22      | Reserved                 | 3                                  |
/// | 24      | Reserved                 | 3                                  |
/// | 26      | Reserved                 | 3                                  |
/// | 28      | Reserved                 | 3                                  |
/// | 30      | Reserved                 | 3                                  |
///
/// Temperature results (Subindex 3):
///
/// | **Bit** | **Description**       |                                    |
/// |---------|-----------------------|------------------------------------|
/// | 0       | Temperature ADC (I2C) | 0: not tested 1: failed: 3: passed |
/// | 2       | NTC IGBT1             | 0: not tested 1: failed: 3: passed |
/// | 4       | NTC Rectifier1        | 0: not tested 1: failed: 3: passed |
/// | 6       | NTC IGBT3             | 0: not tested 1: failed: 3: passed |
/// | 8       | NTC output diode      | 0: not tested 1: failed: 3: passed |
/// | 10      | NTC Inductor1         | 0: not tested 1: failed: 3: passed |
/// | 12      | NTC Transformer1      | 0: not tested 1: failed: 3: passed |
/// | 14      | NTC Inductor3         | 0: not tested 1: failed: 3: passed |
/// | 16      | NTC Transformer3      | 0: not tested 1: failed: 3: passed |
/// | 18      | NTC PCB1              | 0: not tested 1: failed: 3: passed |
/// | 20      | NTC PCB2              | 0: not tested 1: failed: 3: passed |
/// | 11..31  | Reserved              | 3                                  |
///
/// Converter channel results for channel 1/2/3 (Subindex 4/5/6):
///
/// | **bit** | **Description**        |                                    |
/// |---------|------------------------|------------------------------------|
/// | 0       | LEM zero               | 0: not tested 1: failed: 3: passed |
/// | 2       | Reserved               | 3                                  |
/// | 4       | DC output current zero | 0: not tested 1: failed: 3: passed |
/// | 6       | AC voltage             | 0: not tested 1: failed: 3: passed |
/// | 8       | AC current             | 0: not tested 1: failed: 3: passed |
/// | 10      | dVdt circuit           | 0: not tested 1: failed: 3: passed |
/// | 12      | Resonant circuit       | 0: not tested 1: failed: 3: passed |
/// | 14      | DC output current      | 0: not tested 1: failed: 3: passed |
/// | 16      | DC output voltage      | 0: not tested 1: failed: 3: passed |
/// | 18      | Reserved               | 3                                  |
/// | 20      | Reserved               | 3                                  |
/// | 22      | Reserved               | 3                                  |
/// | 24      | Reserved               | 3                                  |
/// | 26      | Reserved               | 3                                  |
/// |         | Reserved               | 3                                  |

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

#define PM_SDO_BIST_MEASUREMENTS_CHANNEL_1     0x2142
/// This object reads the BIST measurement for Channel 1 (ResonantConverter)
/// -----------------------------------------------
///
/// After the BIST has finished, the results of the active channel tests are found
/// in this object.
///
/// Converter channel measurements for channel 1 (**all READ-ONLY**)
///
/// | **subidx** | **Description**                    |                                     |
/// |------------|------------------------------------|-------------------------------------|
/// | 0          | Number of entries in this object   | 10 (uint8)                          |
/// | 1          | Abort flags channel test (uint32)  |                                     |
/// | 2          | Abort flags dumpload test (uint32) |                                     |
/// |            | **Low bytes (uint16)**             | **High bytes (uint16)**             |
/// | 3          | Bus voltage (end) [\*10 V]         | Output voltage (end) [\*10 V]       |
/// | 4          | Input voltage (RMS) [\*10 V]       | Duration charge from 0 to 500V [ms] |
/// | 5          | Input current Average [mA]         | Input current maximum [mA]          |
/// | 6          | Output current Average [mA]        | Output current maximum [mA]         |
/// | 7          | Discharge time [ms]                | Weak discharge time [ms]            |
/// | 8          | Dumpload current [mA]              | Dumpload start current [mA]         |
/// | 9          | Dumpload start setpoint [mA]       | Start voltage dumpload [\*10 V]     |
/// | 10         | Measured output capacity [uF]      | Reserved                            |
/// | others     | reserved                           |                                     |
///
/// Abort flags:
/// InputUvp:             0x00000001
/// InputOvp:             0x00000002
/// InputOCP:             0x00000004
/// OutputOCP:            0x00000008
/// NoOutput:             0x00000010
/// Timeout:              0x00000020
/// HwOCP:                0x00000040
/// HwOVP:                0x00000080
/// HwUVP:                0x00000100
/// HwInterlock:          0x00000200
/// DumploadPowerProtect: 0x00010000
/// DumploadOCP:          0x00020000
/// DumploadTooFast:      0x00040000
/// DumploadTimeout:      0x00080000
/// DumploadLeakage:      0x00100000

#define PM_SDO_BIST_MEASUREMENTS_CHANNEL_2     0x2143
/// This object reads the BIST measurement for Channel 2 (ResonantConverter)
/// -----------------------------------------------
///
/// After the BIST has finished, the results of the active channel tests are found
/// in this object.
///
/// Converter channel measurements for channel 2 (**all READ-ONLY**)
///
/// | **subidx** | **Description**                    |                                     |
/// |------------|------------------------------------|-------------------------------------|
/// | 0          | Number of entries in this object   | 10 (uint8)                          |
/// | 1          | Abort flags channel test (uint32)  |                                     |
/// | 2          | Abort flags dumpload test (uint32) |                                     |
/// |            | **Low bytes (uint16)**             | **High bytes (uint16)**             |
/// | 3          | Bus voltage (end) [\*10 V]         | Output voltage (end) [\*10 V]       |
/// | 4          | Input voltage (RMS) [\*10 V]       | Duration charge from 0 to 500V [ms] |
/// | 5          | Input current Average [mA]         | Input current maximum [mA]          |
/// | 6          | Output current Average [mA]        | Output current maximum [mA]         |
/// | 7          | Discharge time [ms]                | Weak discharge time [ms]            |
/// | 8          | Dumpload current [mA]              | Dumpload start current [mA]         |
/// | 9          | Dumpload start setpoint [mA]       | Start voltage dumpload [\*10 V]     |
/// | 10         | Measured output capacity [uF]      | Reserved                            |
/// | others     | reserved                           |                                     |
///
/// Abort flags:
/// InputUvp:             0x00000001
/// InputOvp:             0x00000002
/// InputOCP:             0x00000004
/// OutputOCP:            0x00000008
/// NoOutput:             0x00000010
/// Timeout:              0x00000020
/// HwOCP:                0x00000040
/// HwOVP:                0x00000080
/// HwUVP:                0x00000100
/// HwInterlock:          0x00000200
/// DumploadPowerProtect: 0x00010000
/// DumploadOCP:          0x00020000
/// DumploadTooFast:      0x00040000
/// DumploadTimeout:      0x00080000
/// DumploadLeakage:      0x00100000

#define PM_SDO_BIST_MEASUREMENTS_CHANNEL_3     0x2144
/// This object reads the BIST measurement for Channel 3 (ResonantConverter)
/// -----------------------------------------------
///
/// After the BIST has finished, the results of the active channel tests are found
/// in this object.
///
/// Converter channel measurements for channel 3 (**all READ-ONLY**)
///
/// | **subidx** | **Description**                    |                                     |
/// |------------|------------------------------------|-------------------------------------|
/// | 0          | Number of entries in this object   | 10 (uint8)                          |
/// | 1          | Abort flags channel test (uint32)  |                                     |
/// | 2          | Abort flags dumpload test (uint32) |                                     |
/// |            | **Low bytes (uint16)**             | **High bytes (uint16)**             |
/// | 3          | Bus voltage (end) [\*10 V]         | Output voltage (end) [\*10 V]       |
/// | 4          | Input voltage (RMS) [\*10 V]       | Duration charge from 0 to 500V [ms] |
/// | 5          | Input current Average [mA]         | Input current maximum [mA]          |
/// | 6          | Output current Average [mA]        | Output current maximum [mA]         |
/// | 7          | Discharge time [ms]                | Weak discharge time [ms]            |
/// | 8          | Dumpload current [mA]              | Dumpload start current [mA]         |
/// | 9          | Dumpload start setpoint [mA]       | Start voltage dumpload [\*10 V]     |
/// | 10         | Measured output capacity [uF]      | Reserved                            |
/// | others     | reserved                           |                                     |
///
/// Abort flags:
/// InputUvp:             0x00000001
/// InputOvp:             0x00000002
/// InputOCP:             0x00000004
/// OutputOCP:            0x00000008
/// NoOutput:             0x00000010
/// Timeout:              0x00000020
/// HwOCP:                0x00000040
/// HwOVP:                0x00000080
/// HwUVP:                0x00000100
/// HwInterlock:          0x00000200
/// DumploadPowerProtect: 0x00010000
/// DumploadOCP:          0x00020000
/// DumploadTooFast:      0x00040000
/// DumploadTimeout:      0x00080000
/// DumploadLeakage:      0x00100000

#define PM_SDO_DCB_VERSION                     0x2150
/// This object reads or writes the DCB version
///
/// Version of the control board (4 bytes ASCII char). Can also be written (to store
/// in Eeprom)
///

#define PM_SDO_NTC_BOARD_VERSION               0x2151
/// This object reads or writes the NTC board version
///
/// Version of the NTC board (4 bytes ASCII char). Can also be written (to store in
/// Eeprom)
///

#define PM_SDO_PROD_DATE                       0x2152
/// This object reads or writes the Production date
///
/// Production date. This is an UINT32. Can also be written (to store in Eeprom).
///
/// Low byte: day
/// Second byte: month
/// High bytes: year
///
/// Example: 19th of December 2013 = 0x07DD0C13
///

#define PM_SDO_ASM_SERIAL                      0x2153
/// This object reads or writes the Assembly serial
///
/// Serial number of the total power module assembly. This is an UINT32. Can also be
/// written (to store in Eeprom).
///

#define PM_SDO_DCB_SERIAL                      0x2154
/// This object reads or writes the DCB serial
///
/// Serial number of the DCB board. This is an UINT32. Can also be written (to store
/// in Eeprom).
///

#define PM_SDO_DCB_HW_VERSION                  0x2155
/// This object reads or writes the DCB HW version
///
/// Version of the DCB board (4 bytes ASCII char). Can also be written (to store in
/// Eeprom)
///

#define PM_SDO_CAN_ID                          0x2156
/// This object reads the CAN ID
///
/// The CAN ID. Can also be written (to store in Eeprom). This is normally stored in
/// Eeprom by the discovery process. But can be overruled by this object.
///

#define PM_SDO_CAN_TERMINATION_ENABLE          0x2157
/// This object reads or writes the CAN termination enable
///
/// The CAN terminated enable flag. Can also be written (to store in Eeprom). This
/// is normally stored in Eeprom by the discovery process. But can be overruled by
/// this object.

#define PM_SDO_CONVERTER_TYPE                  0x2158
/// This object will set a the correct converter type, according to the following enumeration:
///
/// | value  | description                                                                      |
/// |--------|----------------------------------------------------------------------------------|
/// | 0      | 3 phase EU                                                                       |
/// | 1      | single phase (US)                                                                |
/// | 2      | 3 phase (US)                                                                     |
/// | 3      | 3 phase GB 600Vdc (China)                                                        |
/// | 4      | Poseidon                                                                         |
/// | 5      | Marathon                                                                         |
/// | 6      | Poseidon 60Hz                                                                    |
/// | 7      | Marathon 60Hz                                                                    |
/// | 8      | 3 phase cost down (EU and US)                                                    |
/// | 9      | Marathon 60 Hz with maximum output current 116 A instead of 125 A (ELAM request) |
/// | 10     | 3 phase cost down high voltage(EU and US)                                        |
/// | 11     | 1 phase VESTA                                                                    |
/// | 12     | 3 phase VESTA NAM                                                                |
/// | others | reserved                                                                         |

typedef enum
 {
     E_CONV_TYPE_3P_ESMERALDA = 0,
     E_CONV_TYPE_1P_MAGELLAN,
     E_CONV_TYPE_3P_480VAC,
     E_CONV_TYPE_3P_600VDC,
     E_CONV_TYPE_3P_POSEIDON,
     E_CONV_TYPE_3P_MARATHON,
     E_CONV_TYPE_3P_POSEIDON_60Hz,
     E_CONV_TYPE_3P_MARATHON_60Hz,
     E_CONV_TYPE_3P_ESMERALDA_CC,
     E_CONV_TYPE_3P_MARATHON_US_60Hz,
     E_CONV_TYPE_3P_ESMERALDA_HV,
     E_CONV_TYPE_1P_VESTA,
     E_CONV_TYPE_3P_VESTA_NAM
 } tConverterType;

#define PM_SDO_HW_COMPONENTS                   0x2159
/// This object reads or writes the Hardware components
///
/// | Sub idx | Description     |
/// |---------|-----------------|
/// | 0       | Number of items |
/// | 1       | Silicon type    |
/// | 2       | Magnetic type   |
/// | 3       | Heatsink type   |
/// | others  | reserved        |
///
/// Silicon type
///
/// | **Number** | **Type**                                                                                                        |
/// |------------|-----------------------------------------------------------------------------------------------------------------|
/// | **0**      | Undefined                                                                                                       |
/// | **1**      | Esmeralda: Input rect: GBPC3512W, IGBT: APT46GA90JD40, Output rect: VBE55-06 SOT227, Output diode: DSI 2x55-12A |
/// | **2**      | Magellan                                                                                                        |
/// | **3**      | Idem as 1, but with leaded output rectifier instead of SOT227                                                   |
/// | **4**      | Idem as 1, but with 1200V IGBT                                                                                  |
/// | others     | reserved                                                                                                        |
/// | **0xFFFF** | Undefined                                                                                                       |
///
/// Magnetic type
///
/// | **Number** | **Type**                                                                           |
/// |------------|------------------------------------------------------------------------------------|
/// | **0**      | Undefined                                                                          |
/// | **1**      | Esmeralda: 37µH Inductor and 1:1 transformer or 45 uH inductor for US power module |
/// | **2**      | Magellan: 37µH Inductor and 1:1 transformer and 100µH boost inductor               |
/// | **3**      | Denza: 28µH Inductor and 1:1.3 transformer                                         |
/// | others     | reserved                                                                           |
/// | **0xFFFF** | Undefined                                                                          |
///
/// Heatsink type:
///
/// TBD

#define PM_SDO_CALIBRATION_PARM                0x215a
/// This object reads or writes the Calibration parameters
///
/// For more accurate output current and voltage some calibrations values are used
/// (offset and gain).
///
/// | Sub idx | Description     | Unit      |
/// |---------|-----------------|-----------|
/// | 0       | Number of items |           |
/// | 1       | Voltage offset  | 0.1V      |
/// | 2       | Voltage gain    | 1/16384 V |
/// | 3       | Current offset  | 0.1V      |
/// | 4       | Current gain    | 1/16384 A |
/// | others  | reserved        |           |

#define PM_SDO_4EPY_CODE                       0x215b
/// this object reads or writes the 4EPY code of whole assembly
///
/// The 4EPY code has the following format: 4EPYxxxxxx-y Rev z
///
/// Where:
/// \- xxxxxx is a 6 digit decimal number
/// \- y is number between 0 and 99
/// \-z is a character between ‘A’ and ‘Z’
///
/// The 4EPY code is programmed in to eeprom with a 32bit decimal number. This 32bit
/// decimal should be formatted as follows:
///
/// | **Bit**    | **Field**                          |
/// |------------|------------------------------------|
/// | **0..19**  | Xxxxxx 6 digit decimal number part |
/// | **20..26** | Y, decimal number after the dash   |
/// | **27..31** | Revision = ASCII(Z) – 0x40         |
///
/// In formula: Eeprom value = xxxxxx + (y \* 2\^20) + ((ASCII(z) – 0x40) \* 2\^27)
///
/// Example: 4EPY550011-1 RevB = 135816315

#define PM_SDO_HW_ID                           0x215c
/// This object reads or writes the Hardware ID
///
/// This is a one byte number identifying the hardware.

#define PM_SDO_DBG_VAR_ADDRESS                 0x21e0
/// This object reads or writes the Debug variable address (BuckBoost)
///
/// This SDO object is used for real-time debugging of the buck-boost firmware.
///
/// It is a 4-byte numeric that identifies a RAM address. The value can be read
/// using object 21e1.
///
/// | Value  | Description                 | Format |
/// |--------|-----------------------------|--------|
/// | 0      | Number of items             | uint32 |
/// | 1      | Address of debug variable 1 | hex8   |
/// | 2      | Address of debug variable 2 | hex8   |
/// | 3      | Address of debug variable 3 | hex8   |
/// | 4      | Address of debug variable 4 | hex8   |
/// | 5      | Address of debug variable 5 | hex8   |
/// | 6      | Address of debug variable 6 | hex8   |
/// | others | reserved                    |        |
///

#define PM_SDO_DBG_VAR_VALUE                   0x21e1
/// This object reads or writes the Debug variable value (BuckBoost)
///
/// This SDO object is used for real-time debugging of the buck-boost firmware.
///
/// It is a float number, in IEEE 754 standard representation, which is the value of
/// a variable of the firmware.
///
/// | Value  | Description               | Format |
/// |--------|---------------------------|--------|
/// | 0      | Number of items           | uint32 |
/// | 1      | Value of debug variable 1 | float  |
/// | 2      | Value of debug variable 2 | float  |
/// | 3      | Value of debug variable 3 | float  |
/// | 4      | Value of debug variable 4 | float  |
/// | 5      | Value of debug variable 5 | float  |
/// | 6      | Value of debug variable 6 | float  |
/// | others | reserved                  |        |
///
/// In order to read the variable value on sub-index \<i\>, the related address must
/// be written first on the related sub-index \<i\> on object 21e0.
///
/// **Example:**
///
/// | Index | Sub | Value       | Write                                                                        |
/// |-------|-----|-------------|------------------------------------------------------------------------------|
/// | 21e0  | 1   | 00-00-CB-C0 | sets debug variable 1 RAM address to 00-00-CB-C0.                            |
/// | 21e0  | 2   | 00-00-C8-A0 | sets debug variable 2 RAM address to 00-00-C8-A0.                            |
/// | 21e1  | 1   | 42-C9-17-0A | writes 42-C9-17-0A (hex representation of float value 100.545)               |
/// |       |     |             | in the RAM location stored in Object 21e0[1] (00-00-CB-C0 in example above). |
/// | 21e1  | 2   | 41-A4-5C-29 | writes 41-A4-5C-29 (hex representation of float value 20.545)                |
/// |       |     |             | in the RAM location stored in Object 21e0[2] (00-00-C8-A0 in example above). |
///
/// | Index | Sub | Value       | Read                                                                                       |
/// |-------|-----|-------------|--------------------------------------------------------------------------------------------|
/// | 21e0  | 1   | 00-00-CB-C0 | The RAM address of debug variable 1 is 00-00-CB-C0.                                        |
/// | 21e0  | 2   | 00-00-C8-A0 | The RAM address of debug variable 1 is 11-12-13-14                                         |
/// | 21e1  | 1   | 42-C9-17-0A | The value of variable in the RAM location stored in Object 21e0[1]                         |
/// |       |     |             | (00-00-CB-C0 in example above) is 42-C9-17-0A (hex representation of float value 100.545). |
/// | 21e1  | 2   | 41-A4-5C-29 | The value of variable in the RAM location stored in Object 21e0[2]                         |
/// |       |     |             | (00-00-C8-A0 in example above) is 41-A4-5C-29 (hex representation of float value 20.545).  |

#define PM_SDO_REGULATION_PARM                 0x21e2
/// This object reads or writes the Regulation parameter (BuckBoost)
///
/// The regulation parameters of the buck-boost power-module.
///
/// | Value  | Description                                 | Format |
/// |--------|---------------------------------------------|--------|
/// | 0      | Number of items                             | uint32 |
/// | 1      | Value of regulation parameter KP Voltage PI | float  |
/// | 2      | Value of regulation parameter KI Voltage PI | float  |
/// | 3      | Value of regulation parameter KP Current PI | float  |
/// | 4      | Value of regulation parameter KI Current PI | float  |
/// | others | reserved                                    |        |
///

#define PM_SDO_OPEN_LOOP_PARM                  0x21e3
/// This object reads or writes the Open Loop parameters (BuckBoost)
///
/// The parameters used by the open loop control of the buck-boost power-module.
///
/// | Value  | Description                  | Format |
/// |--------|------------------------------|--------|
/// | 0      | Number of items              | uint32 |
/// | 1      | Open loop - power on         | uint32 |
/// | 2      | Open loop - buck duty cycle  | float  |
/// | 3      | Open loop - boost duty cycle | float  |
/// | 4      | Open loop - phase 1 on/off   | uint32 |
/// | 5      | Open loop - phase 2 on/off   | uint32 |
/// | 6      | Open loop - phase 3 on/off   | uint32 |
/// | others | reserved                     |        |
///

#define PM_SDO_ANALOG_DBG_OUTPUT_SELECT        0x21f0
/// This object sets the Analog debug output select
/// -------------------------------
///
/// There are two analog debug output ports for internal signal measurements. This
/// object determines which internal signals are connected to the two debug outputs.
/// The low bytes determine what is on debug port 1, the high byte for debug port 2.
///

#define PM_SDO_SNAPSHOT_NUMBER                 0x21f1
/// This object sets the Snapshot number
///
/// From some internal signals or debug buffers (oe Eeprom) a snapshot can be made
/// and will be dumped via PDO2. Writing to this object starts the snapshot process.
///
/// | Value  | Description                       |
/// |--------|-----------------------------------|
/// | 0      | Input current 1                   |
/// | 1      | Input current 2                   |
/// | 2      | Input current 3                   |
/// | 3      | Input voltage 1                   |
/// | 4      | Input voltage 2                   |
/// | 5      | Input voltage 3                   |
/// | 6      | Output voltage                    |
/// | 7      | Bus voltage                       |
/// | 8      | Output current                    |
/// | 9      | Throttle signal (from outer loop) |
/// | 10     | Freq ctr1                         |
/// | 11     | Freq ctr2                         |
/// | 12     | Freq ctr3                         |
/// | others | reserved                          |
///

#define PM_SDO_TWEAK_VALUES_NV                 0x21f2
/// This object Tweak values NV
///
/// No information about the content of this sdo.
///

#define PM_SDO_TWEAK_VAKUES_VOL                0x21f3
/// This object Tweak values VOL
///
/// No information about the contents of this sdo.
///

#define PM_SDO_READ_EEPROM                     0x2ff3
/// This object is used to Read Eeprom
///
/// The sub index specifies the Eeprom address divided by 4. The result are 4 bytes.
/// Sub index can be between 0x00 and 0xff (1 kB Eeprom).
///

#define PM_SDO_WRITE_EEPROM                    0x2ff4
/// This object is used to Write Eeprom
///
/// The sub index specifies the Eeprom data to be written. The value of this object
/// (UINT16) specifies the address.
///

#define PM_SDO_DISABLE_PROTECTIONS             0x2ff5
/// This objects Disables protections
///
/// This write-only object can be used to disable protections. After 30 seconds, the
/// protections are enabled again unless another “Disable protection” message is
/// received. Use for testing only!
///
/// | **Bit nr** | **Flag**                                    |
/// |------------|---------------------------------------------|
/// | 0          | Disable Over Temperature Protection         |
/// | 1          | Disable AC input Under Voltage Protection   |
/// | 2          | Disable fan check                           |
/// | 3          | Disable “Setpoint not met” protection       |
/// | 4          | Disable DC output Under Voltage Protection  |
/// | 5          | Disable AC input current balance protection |
/// | 6          | Disable setpoint timeout protection         |
/// | others     | reserved                                    |
///

#define PM_SDO_WATCHDOG_TEST                   0x2ffe
/// This object set a  Watchdog test
///
/// Writing to this object holds the program in a halt state. The watchdog should
/// reset the CPU.
///

#define PM_SDO_BOARD_RESET                     0x2fff
/// This object causes a Board reset
///
/// Writing to this object holds the program in a halt state. The watchdog should
/// reset the CPU.
///

#define PM_SDO_FREQUENCY                       0x8000
/// This object is for debug purposed
///
/// Frequency
///

#define PM_SDO_DEAD_TIME                       0x8001
/// This object is for debug purposed
///
/// 8001 Dead Time
///

#define PM_SDO_GATE_ENABLE                     0x8002
/// This object is for debug purposes.
///
/// 8002 Gate enable

#define PM_SDO_DUMPLOAD                        0x8003
/// This object is for debug purposes
///
/// 8003 Dumpload
///

#define PM_SDO_OVER_VOLTAGE_PROTECTION_LVL     0x8004
/// This object is for debug purposes
///
/// 8004 Over Voltage Protection level
///

#define PM_SDO_ADC_RAW                         0x8010
/// This object is for debug purposes
///
/// 8010 ADC raw
///

#define PM_SDO_CONTROL_BUS                     0x8020
/// This object is for debug purposes
///
/// 8020 Control bus
///


#define PM_PDO_STATUS                          PDO_1
/// Contains the following objects: 2107, 2108, 2104, 2101
///
/// Message layout:
///
/// |           | **Byte1**  | **Byte2**  | **Byte3**            | **Byte4**    | **Byte5**  | **Byte6**  | **Byte7**  | **Byte8**  |
/// |-----------|------------|------------|----------------------|--------------|------------|------------|------------|------------|
/// | **SDO**   | 2107 (LSB) | 2107 (MSB) | 2108 (LSB)           | 2108 (MSB)   | 2104 (LSB) | 2104 (MSB) | 2101 (LSB) | 2101 (MSB) |
/// | **Descr** | Voltage    | Current    | Temperature headroom | Status flags |            |            |            |            |
///
/// Only the lower 16 bits of the status bits are reported.

struct PM_PDO_1
{
    uint16_t    m_voltage;
    uint16_t    m_current;
    int16_t     m_temperature;
    TPmStatus   m_status;
};
#define PM_SDO_CONV_TEMP_MASK   0x3FF

#define PM_PDO_SIGNAL_MEASUREMENT              PDO_2
/// A chunk of data is dumped with this PDO. Every PDO message contain 4 words of
/// data. The dump starts with a defined start marker (4 bytes) and with a
/// multiplier (2 bytes) and divider (2 bytyes) so the receiving application can
/// convert these values to their original units.

#define PM_PDO_CONSTRAINT                      PDO_3
/// When the device cannot perform at its design capability defined by 2110, this
/// message identifies which of the capabilities cannot be met and for which
/// set-points should be adapted to prevent performance errors.
///
/// The first byte of the payload identifies which constraint is transmitted. The
/// following are used:
///
/// | Type | Description        |
/// |------|--------------------|
/// | 0    | Current constraint |
/// | ..   | reserved           |
///
/// **0 Current constraint**
///
/// >   A current constraint message contains a new (sub) range for the dc-output
/// >   current (min, max) defined with 2110[5] and the current transfer ratio as
/// >   defined by 211a.
///
/// | Offset | Description               | Unit  | Size   |
/// |--------|---------------------------|-------|--------|
/// | 1      | Minimum dc-output current | 0.1A  | uint16 |
/// | 3      | Maximum dc-output current | 0.1A  | uint16 |
/// | 5      | Current transfer ratio    | \*256 | uint16 |

#define PM_CONSTRAINT_TYPE_DC_CURRENT              0
struct TPmConstraintDcCurrent {
    uint16_t    min;
    uint16_t    max;
    uint16_t    ctr;
};

struct TPmConstraint {
    uint8_t     type;
    union {
        TPmConstraintDcCurrent dc_current;
    };
};
// Test results definitions
#define PM_TR_NOT_TESTED                           0U
#define PM_TR_TEST_FAILED                          1U
#define PM_TR_RESERVED                             2U
#define PM_TR_TEST_PASSED                          3U

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
