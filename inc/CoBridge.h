#ifndef __INTERFACE_COBRIDGE_H__
#define __INTERFACE_COBRIDGE_H__

#include <stdint.h>

#pragma pack(1)

/// # 24xx Power Bridge (PWB)
///
/// CoBridge is an extension of CoPm and is specific for external converters.
///
/// | Object index | description                         | r/w | unit                | size / type            | persist |
/// |--------------|-------------------------------------|-----|---------------------|------------------------|---------|
/// | 2400[0..8]   | DC output voltage and current       | r   | 0.1V                | uint16                 |         |
/// |              |                                     |     | 0.1A                | uint16                 |         |
/// | 2401[0..8]   | Temperature and state               | r   | 0.1 °C              | uint8                  |         |
/// |              |                                     |     | state tab0          | uint8                  |         |
/// |              |                                     |     | state tab1          | uint8                  |         |
/// |              |                                     |     | state tab2          | uint8                  |         |
/// | 2402         | Interlink dc-contactor control      | r/w | \-                  | uint8                  |         |
/// | 2403         | Power module max output             | r/w | 0.1V                | uint16                 |         |
/// |              |                                     |     | 0.1A                | uint16                 |         |
/// | 2404         | Fan configuration                   | r/w | \                   | uint8                  |   X     |
/// | 2405         | Fan state                           | r/w | \                   | uint8,uint32           |         |
/// | 2406         | AC contactor group state            | r/w | \                   | uint8                  |         |
/// | 2407         | PDO entity to listen for            | r/w | \                   | uint8                  |   X     |
/// | 2410         | Power module address and group      | r   | pm address          | uint8                  |         |
/// |              |                                     |     | pm group address    | uint8                  |         |
/// | 2420         | Power module config type            | r/w | enum                | uint8                  |   X     |
/// | 2421         | Power module config topology        | r/w | nº outlets          | uint8                  |   X     |
/// |              |                                     |     | nº pm outlet1       | uint8                  |         |
/// |              |                                     |     | nº pm outlet2       | uint8                  |         |
/// | 2422         | Power module config group           | r/w | nº groups           | uint32                 |   X     |
/// |              |                                     |     | group0 mask         | uint32                 |         |
/// |              |                                     |     | group1 mask         | uint32                 |         |
/// | 2423         | Power module config offset          | r/w | uint8               | uint8                  |   X     |
/// |              |                                     |     | group1 mask         | uint32                 |         |
/// | 2424         | Power module capabilities           | r   | \                   | uint8                  |         |
/// | 2424[1]      | Power module max voltage capability | r/w | 0.1V                | uint16                 |   X     |
/// | 2424[2]      | Power module max current capability | r/w | 0.1A                | uint16                 |   X     |
/// | 2424[3]      | Power module max power capability   | r/w | 0.1kW               | uint16                 |   X     |
/// |              |                                     |     | max power           | uint16                 |   X     |
/// | 2440         | Power module update start           | w   | PfcDsp              | uint16                 |         |
/// |              |                                     |     | DcDcDsp             | uint16                 |         |
/// |              |                                     |     | CanDsp              | uint16                 |         |
/// | 2441         | Power module update state           | r   | state               | uint8                  |         |
/// |              |                                     |     | image index/error id| uint8                  |         |
/// |              |                                     |     | error detail        | uint16                 |         |
/// | 2442         | Power module update data frame      | w   | data fram byte 1    | uint8                  |         |
/// |              |                                     |     | data fram byte 2    | uint8                  |         |
/// |              |                                     |     | data fram byte 3    | uint8                  |         |
/// |              |                                     |     | data fram byte 4    | uint8                  |         |
/// | 2443         | Power module update data end        | w   | -                   | uint8                  |         |
/// | 2444         | Power module update mode            | w   | enum                | uint8                  |         |
/// |              |                                     |     |                     |                        |         |
/// | pdo1         | Device status                       | r   | \-                  | uint32                 |         |

#define PWB_SDO_PM_OUTPUT               0x2400
/// This read-only object contains the actual output voltage in steps of 0.1V and the actual output current
/// in steps of 0.1A.
///
/// The sub-index contains the index of the power module which the DC output voltage and current have been requested.
///
/// | Subindex | Description                          | r/w | unit   | UnitSize    |
/// |----------|--------------------------------------|-----|--------|-------------|
/// | 1..8     | DC output voltage and current of PM  | r   |  0.1V  | uint16      |
/// |          |                                      | r   |  0.1A  | uint16      |
///
/// Dc output voltage and current of PMx (Response for subindex 1 to 8):
///
/// | Offset   | Description         | Unit | UnitSize | Data Range    |
/// |----------|---------------------|------|----------|---------------|
/// | 0        | DC output current   | -    |  uint16  | 0 – 0xFFFF    |
/// | 2        | DC output voltage   | -    |  uint16  | 0 – 0xFFFF    |

typedef struct
{
    uint16_t    voltage;
    uint16_t    current;
}TPwbVI;

#define PWB_SDO_PM_STATUS               0x2401
/// This read-only object contains the temperature in steps of 1°C and the current state of every power module.
///
/// The sub-index contains the index of power module which the temperature and state have been requested.
///
/// | Subindex | Description                          | r/w | Unit       | UnitSize  |
/// |----------|--------------------------------------|-----|------------|-----------|
/// | 1..8     | temperature and state of PM          |  r  | 0.1 °C     | uint8     |
/// |          |                                      |  r  | state tab0 | uint8     |
/// |          |                                      |  r  | state tab1 | uint8     |
/// |          |                                      |  r  | state tab2 | uint8     |
///
/// Temperature and state of PMx (response for subindex 1 to 8):
///
/// | Offset   | Description         | Unit | UnitSize | Data Range    |
/// |----------|---------------------|------|----------|---------------|
/// | 0        | temperature         | -    |  uint8   | 0 – 0xFF      |
/// | 1        | state tab0          | -    |  uint8   | 0 – 0xFF      |
/// | 2        | state tab1          | -    |  uint8   | 0 – 0xFF      |
/// | 3        | state tab2          | -    |  uint8   | 0 – 0xFF      |
///
/// States are dependant of the manufacturer type of power module.
///
/// INFY power module state
///
/// |State index|Bit offset|Description                |Value                  |
/// |------------|----------|--------------------------|-----------------------|
/// |   0        |0         |DC output short circuit   |0: ok; 1: error        |
/// |            |1         |Reserved                  |                       |
/// |            |2         |Reserved                  |                       |
/// |            |3         |Reserved                  |                       |
/// |            |4         |In sleeping               |0: ok; 1: error        |
/// |            |5         |Reserved                  |                       |
/// |            |6         |Reserved                  |                       |
/// |            |7         |Reserved                  |                       |
/// |            |          |                          |                       |
/// |   1        |0         |Shutdown on DC side       |0: on; 1: off          |
/// |            |1         |Power module fault        |0: ok; 1: error        |
/// |            |2         |Power module protected    |0: ok; 1: error        |
/// |            |3         |FAN failure               |0: ok; 1: error        |
/// |            |4         |Temperature overhigh      |0: ok; 1: error        |
/// |            |5         |DC output overvoltage     |0: ok; 1: error        |
/// |            |6         |WALK-IN enabled           |0: disabled; 1: enabled|
/// |            |7         |Communication lost        |0: ok; 1: error        |
/// |            |          |                          |                       |
/// |   2        |0         |Power is limited          |0: ok; 1: error        |
/// |            |1         |Repeated module ID        |0: ok; 1: error        |
/// |            |2         |Unequal sharing current   |0: ok; 1: error        |
/// |            |3         |AC input phase lost       |0: ok; 1: error        |
/// |            |4         |AC input phase unbalanced |0: ok; 1: error        |
/// |            |5         |AC input under-voltage    |0: ok; 1: error        |
/// |            |6         |AC input over-voltage     |0: ok; 1: error        |
///
/// INCREASE power module state
///
/// |State index|Bit offset|Description                   |Value          |
/// |------------|----------|----------------------------|----------------|
/// |0           |0         |Power module shutdown       |0: on; 1: off   |
/// |            |1         |Power module fault          |0: ok; 1: fault |
/// |            |2         |Current is limited          |0: ok; 1: error |
/// |            |3         |FAN failure                 |0: ok; 1: error |
/// |            |4         |AC input overvoltage        |0: ok; 1: error |
/// |            |5         |AC input undervoltage       |0: ok; 1: error |
/// |            |6         |DC output overvoltage       |0: ok; 1: error |
/// |            |7         |DC output undervoltage      |0: ok; 1: error |
/// |            |          |                            |                |
/// |1           |0         |Protected as overcurrent    |0: ok; 1: error |
/// |            |1         |Protected as overtemperature|0: ok; 1: error |
/// |            |2         |Set to shutdown             |0: on; 1: off   |
/// |            |3-7       |Reserved                    |                |
/// |            |          |                            |                |
/// |2           |0-7       |Reserved                    |                |
///
/// UUGR power module state
///
/// |State index|Bit offset|Description                              |Value           |
/// |-----------|----------|-----------------------------------------|----------------|
/// |0          |0         |AC input overvoltage                     |0: ok; 1: error |
/// |           |1         |AC input undervoltage                    |0: ok; 1: error |
/// |           |2         |Protected as AC overvoltage              |0: ok; 1: error |
/// |           |3         |Pfc bus overvoltage                      |0: ok; 1: error |
/// |           |4         |Pfc bus undervoltage                     |0: ok; 1: error |
/// |           |5         |Pfc bus unbalanced                       |0: ok; 1: error |
/// |           |6         |DC output overvoltage                    |0: ok; 1: error |
/// |           |7         |Protected as DC overvoltage              |0: ok; 1: error |
/// |           |          |                                         |                |
/// |1          |0         |DC output undervoltage                   |0: ok; 1: error |
/// |           |1         |FAN failure                              |0: ok; 1: error |
/// |           |2         |Fan drive circuit fault                  |0: ok; 1: error |
/// |           |3         |Protected as ambient temperature         |0: ok; 1: error |
/// |           |4         |Ambient temperature too low              |0: ok; 1: error |
/// |           |5         |Protected as pfc temperature1            |0: ok; 1: error |
/// |           |6         |Protected as dc temperature1             |0: ok; 1: error |
/// |           |7         |Communication fault between pfc and dcdc |0: ok; 1: error |
/// |           |          |                                         |                |
/// |2          |0         |Pfc fault                                |0: ok; 1: error |
/// |           |1         |DcDc fault                               |0: ok; 1: error |
/// |           |2         |Dcdc shutdown                            |0: ok; 1: error |
/// |           |3-4       |Output loop status                       |                |
/// |           |5         |Dc output voltage unbalanced             |0: ok; 1: error |
/// |           |6         |Sn is the same                           |0: ok; 1: error |
/// |           |7         |bleed circuit fault                      |0: ok; 1: error |

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
            uint8_t bfPfcBusOvervoltage : 1;
            uint8_t bfPfcBusUndervoltage : 1;
            uint8_t bfPfcBusUnbalanced : 1;
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
            uint8_t bfFanDriveCircuitFault : 1;
            uint8_t bfProtectedAsAmbientTemperature : 1;
            uint8_t bfAmbientTemperatureTooLow : 1;
            uint8_t bfProtectedAsPfcTemperature1 : 1;
            uint8_t bfProtectedAsDcTemperature1 : 1;
            uint8_t bfCommunicationFaultBetweenPfcAndDcdc : 1;
        }bits;

        uint8_t data;
    }tab1;

    union
    {
        struct
        {
            uint8_t bfPfcFault : 1;
            uint8_t bfDcDcFault : 1;
            uint8_t bfDcdcShutdown : 1;
            uint8_t bfOutputLoopStatus : 2;
            uint8_t bfDcOutputVoltageUnbalanced : 1;
            uint8_t bfSnIsTheSame : 1;
            uint8_t bfbleedCircuitFault : 1;
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

#define PWB_SDO_INTERLINK_DC_CONTACTOR  0x2402
/// This object contains the requested action of the interlink DC contactor when it is written and the actual
/// status when it is read. When written the interlink DC contactor is switched on for a 10 seconds period.
///
/// The value written defines the behavior as follows:
///
/// | Value    | Action       |
/// |----------|--------------|
/// | 0        | forced off   |
/// | 1        | timed enable |
/// | 255      | forced enable|
///
/// Every write of a timed enable(1) resets the timer. Only when no new requests for timed enable are sent before
/// timeout period (10 seconds) expires, the contactor is switched off. The action ‘forced enable’ is
/// set only by a manual control for end-of-line testing.
///
/// The value read defines the behavior as follows:
///
/// | Value    | Action              |
/// |----------|---------------------|
/// | 0        | contactor is open   |
/// | 1        | contactor is closed |
/// | 2        | contactor has error  |

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

#define PWB_SDO_PM_MAX_OUTPUT           0x2403
/// This object contains the maximum of the (last) session voltage and current. It is used to decide the
/// operating mode ‘high’ (1000V) or ’low’ (500V)” for the ‘UUGR’ power module. Is shall be set before the
/// power module is enabled/controlled.
/// Note that the maximum current is not used at the moment.
///
/// The values in the command are defined as follows:
///
/// | Offset   | Description            | Unit | UnitSize  |
/// |----------|------------------------|------|-----------|
/// | 0        | Max of session voltage | 0.1V |  uint16   |
/// | 2        | Max of session current | 0.1A |  uint16   |

#define PWB_SDO_FAN_CONFIGURATION           0x2404
/// This object contains the configuration of the fan.
///
/// The definition is below
///
/// | Subindex | Description                          | r/w | UnitSize    |
/// |----------|--------------------------------------|-----|-------------|
/// | 0        | Configuration id                     | r/w | uint8       |
/// | 1        | Fan number in current configuration  | r   | uint8       |
///
/// Subindex 0 is used to derive a number of parameters like fan type (DC or AC),
/// fan feedback signal type (IO or PWM) and number of fans as below.
///
/// | Value    | Description                    |
/// |----------|--------------------------------|
/// | 0        | None, typically not be used    |
/// | 1        | HC_300A                        |

#define PWB_SDO_FANS_STATE                  0x2405
/// When written, it sets the states of the fans.
/// The size of the value is uint8.
///
/// Its definition is described as below
///
/// | Value | Description    |
/// |-------|----------------|
/// | 0     | stop  the fans |
/// | 1     | start the fans |
///
/// Remark: all the fans are controlled together when written.
///
/// When read, it gives the states of fans.
/// The size of the value is uint32.
/// The state of each fan uses 2 bits, max 16 fans are supported.
///
/// The definition is described as below
///
/// | Bits       | Description    | Value                                         |
/// |------------|----------------|-----------------------------------------------|
/// | 0:1        | state of fan 1 | 0: normal  1: reserved  2: reserved  3: error |
/// | 2:3        | state of fan 2 | 0: normal  1: reserved  2: reserved  3: error |
/// | ...        |                |                                               |
/// | 2n-2: 2n-1 | state of fan n | 0: normal  1: reserved  2: reserved  3: error |

#define PWB_SDO_GROUPS_AC_CONTACTORS          0x2406
/// This object contains the state of the AC relay for a group of power modules.
/// The size of the value is uint8.
///
/// When written, it sets the states of the AC relay on the power modules assigned to a certain group.
///
/// | bit    | description                   | value        |
/// |--------|-------------------------------|--------------|
/// |    0   | state of AC realy for group 1 | 0: off 1: on |
/// |    1   | state of AC realy for group 2 | 0: off 1: on |
/// |    ... | ...                           |              |
/// |    7   | state of AC realy for group 8 | 0: off 1: on |
///
/// When read, it gets the state of the AC relay on the power modules assigned to a certain group.
///
/// | bit    | description                   | value        |
/// |--------|-------------------------------|--------------|
/// |    0   | state of AC realy for group 1 | 0: off 1: on |
/// |    1   | state of AC realy for group 2 | 0: off 1: on |
/// |    ... | ...                           |              |
/// |    7   | state of AC realy for group 8 | 0: off 1: on |

#define PWB_SDO_CABINET_CONTROLLER 0x2407
/// Powerbridge should be aware of its cabinet node id to listen only relevant Ccb,
/// this object contains the controller to listen for i.e. the CCB PDO to register.
///
/// The size of the value is uint8.
///
/// When written, it sets the CAN controller to listen.
///
/// | Value | Description                                                                              |
/// |-------|------------------------------------------------------------------------------------------|
/// | 0     | Default, PWB register handle for both PDOs coming from CAN_ID_CCB and CAN_ID_CCB_CABINET |
/// | 1     | PWB register handle for PDOs coming from CCB3 i.e CAN_ID_CCB_CABINET                     |
///
/// When read, it gets the CAN controller to listen for
///
/// | Value | Description                                                                              |
/// |-------|------------------------------------------------------------------------------------------|
/// | 0     | Default, PWB register handle for both PDOs coming from CAN_ID_CCB and CAN_ID_CCB_CABINET |
/// | 1     | PWB register handle for PDOs coming from CCB3 i.e CAN_ID_CCB_CABINET                     |

#define PWB_SDO_PM_ADDRESS 0x2410
/// This object reads the power module address and group address
///
/// The values in the command are defined as follows:
///
/// | Offset   | Description            | Unit | UnitSize  |
/// |----------|------------------------|------|-----------|
/// | 0        | Pm address             | \    |  uint8    |
/// | 1        | Pm group address       | \    |  uint8    |

#define PWB_SDO_CONFIG_PM_TYPE          0x2420
/// This object defines the type of the power module(s) in the charger. For each type the
/// Power bridge implements the required specific control behavior.
///
/// When written, it sets the Power module type. New power module type will be used after restart of the power bridge.
/// When read, it returns the power module type configured at boot-up.
///
/// The following types are supported:
///
/// | Value | Description            | Vendor     |
/// |-------|------------------------|------------|
/// | 0     | None                   |            |
/// | 1     | INFY 500V/30A          |InfyPower   |
/// | 2     | INFY 750V/25A          |InfyPower   |
/// | 3     | INFY 1000V/25A         |InfyPower   |
/// | 4     | INCR 500V/30A          |Increase    |
/// | 5     | INCR 750V/25A          |Increase    |
/// | 6     | UUGR 1000V/30A         |UUGreenPower|
/// | 7     | ELPC 1000V/30A         |ELPCPower   |

enum TPwbPowerModuleType
{
    PWB_UNDEFINED = 0,
    PWB_INFY50030,
    PWB_INFY75025,
    PWB_INFY100025,
    PWB_INCR50030,
    PWB_INCR75025,
    PWB_UUGR100030,
    PWB_ELPC100030,
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
    case PWB_ELPC100030:  retValue = "Elpc,1000V/30A"; break;
    default: break;
    }

    return retValue;
}

#define PWB_SDO_CONFIG_PM_TOPOLOGY      0x2421
/// This object contains the actual number of groups and the number of power modules assigned
/// to a certain group.
/// It is required to configure the power topology especially when implementing dynamic power
/// distribution. One power bridge can manage one or 2 groups and the number of power modules
/// connected to a specific group shall be configured.
///
/// The values for a write request sub-index are defined as:
///
/// | Sub-Index | Description                                   | UnitSize | Data Range  |
/// |-----------|-----------------------------------------------|----------|-------------|
/// |0          | Number of groups                              | uint8    | 0 – 2       |
/// |1          | Number of power modules connected to group 1  | uint8    | 0 – 8       |
/// |2          | Number of power modules connected to group 2  | uint8    | 0 – 8       |

#define PWB_SDO_CONFIG_PM_GROUP         0x2422
/// This object contains a map of the group topology associated with the power modules in a charger.
/// A power module only belong to one group.
/// The values in the command are defined as follows:
///
/// | Sub-Index | Description                      | UnitSize |
/// |-----------|----------------------------------|----------|
/// | 0         | Number of groups                 | uint32   |
/// | 1         | Powe module bit mask in group 1  | uint32   |
/// | 2         | Powe module bit mask in group 2  | uint32   |
///
///
/// For Sub-Index 1 and 2 each bit represents a power module from 8...1. power module 1 will be the less significant bit.
/// If the bit is set the power module belongs to the group representing the sub-index.
/// If the bit is clear the power module not belong to the group representing the sub-index.
///
/// eg.
///
///     sub-index 0, 0x2 means there a two groups
///
///     sub-index 1, 0x07(0b 000 111) means power module 1, 2, 3 are belong to group 1.
///
///     sub-index 2, 0x38(0b 111 000) means power module 4, 5, 6 are belong to group 2 and 1, 2, 3 are not belong to group 2.
///

#define PWB_SDO_CONFIG_PM_OFFSET        0x2423
/// This object contains the offset from which the CAN node ID of external power modules is created.
///
/// The values in the command are defined as follows:
///
/// | Sub-Index | Description | UniSize |
/// |-----------|-------------|---------|
/// | 0         | Offset      | uint8   |
///
/// eg.
///
///     If the offset is set to 6, the CAN node ID of the power modules exposed by this power bridge
///     starts from CAN_ID_PWR + 6. (If no offset is set, by default, it starts from CAN_ID_PWR)
///
/// External power modules
/// ----------------------
///

#define PWB_SDO_CONFIG_PM_CAPABILITIES        0x2424
/// This read-write object is used to read-set the maximum output voltage, output current and output power capability.
///
/// The maximum output voltage, output current and output power for power modules are hard-coded in the powerbridge firmware.
/// The values should be configurable and stored by the powerbridge in order to cover all the cases in the near future.
/// And a lower value than default 30kW power capability can be configured by this object for a higher lifetime expectancy
/// as required for HVC. For example:
/// T365 (Pmax=30 kW, Vmax=920 V)
/// Marathor ( Pmax=22.5 kW, Vmax=1000 V)
///
/// During installation, the values should be configured as device.conf configuration. If the values are not configured,
/// the default values for power module output capability should be used. If the configuration values are out of the range
/// of default minimum and maximum capabilities that the power module provided, the error 'COR_INVALID_PARAM_VALUE' should
/// be returned. And the debug console command "cpi/powerport/caps" should be able to show the values. (See the details in
/// VSTS-24692, VSTS-24693 and VSTS-24696)
///
/// The values in the command are defined as follows:
///
/// | Sub-Index | Description                | Unit  | UnitSize  |
/// |-----------|----------------------------|-------|-----------|
/// | 0         | number of capability items | \     |  uint8    |
/// | 1         | Max voltage capability     | 0.1V  |  uint16   |
/// | 2         | Max current capability     | 0.1A  |  uint16   |
/// | 3         | Max power capability       | 0.1kW |  uint16   |
#define PWB_SDO_CONFIG_PM_CAPABILITIES_IDX_NUMBER  0
#define PWB_SDO_CONFIG_PM_CAPABILITIES_IDX_VOLTAGE 1
#define PWB_SDO_CONFIG_PM_CAPABILITIES_IDX_CURRENT 2
#define PWB_SDO_CONFIG_PM_CAPABILITIES_IDX_POWER   3

#define PWB_SDO_UPDATE_START            0x2440
/// This write-only object contains the version(s) numbers of the image(s) for updating external power modules.
/// When written, it starts the image update procedure of the external power modules.
///
/// The data is a vendor-specific version(s) numbers.
///
/// The values in the command are defined as follows:
///
/// For UUGreen
///
/// | Byte      | Description   | UnitSize |
/// |-----------|---------------|----------|
/// | 0:1       | PFC version   | uint16   |
/// | 2:3       | DCDC version  | uint16   |

typedef struct {
    union {
        struct {
            uint16_t High : 8;
            uint16_t Low : 8;
       }bits;

        uint16_t  value;
    }DcDcDsp;
    union {
        struct {
            uint16_t High : 8;
            uint16_t Low : 8;
        }bits;

        uint16_t  value;
    }PfcDsp;
}TPmSoftVersion;

#define PWB_SDO_UPDATE_STATUS           0x2441
/// This read-only object contains the update state of the external power modules.
///
/// The values in the command are defined as follows:
///
/// | Byte      | Description                      | UnitSize | Value                                             |
/// |-----------|----------------------------------|----------|---------------------------------------------------|
/// | 0         | state                            | uint8    | enum (TPwbUpdateState)                            |
/// | 1         | expectedImageIndex/error id      | uint8    |  0: done, 1~n: image index/enum (TPwbUpdateError) |
/// | 2:3       | error detail                     | uint16   | -                                                 |
///
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

    PUE_START_CAN_NOT_MATCH_PM_NUMBER,
    PUE_START_CAN_ERASE_NO_RESP ,
    PUE_START_CAN_ERASE_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_CAN_BOOTLOADER_NO_RESP,
    PUE_START_CAN_BOOTLOADER_UNEXPECTED_RESP_ADDR_ERROR,

    PUE_START_SECONDARY_NOT_MATCH_PM_NUMBER,
    PUE_START_SECONDARY_ERASE_NO_RESP,
    PUE_START_SECONDARY_ERASE_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_SECONDARY_BOOTLOADER_NO_RESP,
    PUE_START_SECONDARY_BOOTLOADER_UNEXPECTED_RESP_ADDR_ERROR,

    PUE_START_CAN_READ_VER_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_PRIMARY_READ_VER_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_SECONDARY_READ_VER_UNEXPECTED_RESP_ADDR_ERROR,

    PUE_START_CAN_ERASE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_CAN_BOOTLOADER_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_PRIMARY_ERASE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_PRIMARY_NOT_MATCH_PM_NUMBER,
    PUE_START_PRIMARY_ERASE_UNKNOWN_ERROR,
    PUE_START_PRIMARY_BOOTLOADER_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_PRIMARY_BOOTLOADER_UNKNOWN_ERROR,
    PUE_START_SECONDARY_ERASE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_SECONDARY_ERASE_UNKNOWN_ERROR,
    PUE_START_SECONDARY_BOOTLOADER_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_SECONDARY_BOOTLOADER_UNKNOWN_ERROR,

    PUE_START_CAN_READ_VER_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_PRIMARY_READ_VER_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_SECONDARY_READ_VER_UNEXPECTED_RESP_GROUP_ID_ERROR,

    PUE_START_CAN_READ_VER_SAME_ADDR_ERROR,
    PUE_START_CAN_READ_VER_UNKNOWN_ERROR,
    PUE_START_PRIMARY_READ_VER_SAME_ADDR_ERROR,
    PUE_START_PRIMARY_READ_VER_UNKNOWN_ERROR,
    PUE_START_SECONDARY_READ_VER_SAME_ADDR_ERROR,
    PUE_START_SECONDARY_READ_VER_UNKNOWN_ERROR,

    PUE_START_CAN_CHK_SOFT_STATE_NO_RESP,
    PUE_START_CAN_CHK_SOFT_STATE_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_CAN_CHK_SOFT_STATE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_CAN_CHK_SOFT_STATE_UNEXPECTED_RESP_SAME_ADDR_ERROR,
    PUE_START_CAN_CHK_SOFT_STATE_UNKNOWN_ERROR,
    PUE_START_PRIMARY_CHK_SOFT_STATE_NO_RESP,
    PUE_START_PRIMARY_CHK_SOFT_STATE_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_PRIMARY_CHK_SOFT_STATE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_PRIMARY_CHK_SOFT_STATE_UNEXPECTED_RESP_SAME_ADDR_ERROR,
    PUE_START_PRIMARY_CHK_SOFT_STATE_UNKNOWN_ERROR,
    PUE_START_SECONDARY_CHK_SOFT_STATE_NO_RESP,
    PUE_START_SECONDARY_CHK_SOFT_STATE_UNEXPECTED_RESP_ADDR_ERROR,
    PUE_START_SECONDARY_CHK_SOFT_STATE_UNEXPECTED_RESP_GROUP_ID_ERROR,
    PUE_START_SECONDARY_CHK_SOFT_STATE_UNEXPECTED_RESP_SAME_ADDR_ERROR,
    PUE_START_SECONDARY_CHK_SOFT_STATE_UNKNOWN_ERROR,

    PUE_DATA_PRIMARY_WRITE_NO_RESP = 51,
    PUE_DATA_PRIMARY_WRITE_FAILURE,
    PUE_DATA_PRIMARY_WRITE_UNKNOWN_ERROR,
    PUE_DATA_SECONDARY_WRITE_NO_RESP,
    PUE_DATA_SECONDARY_WRITE_FAILURE,
    PUE_DATA_SECONDARY_WRITE_UNKNOWN_ERROR,
    PUE_DATA_CAN_WRITE_NO_RESP,
    PUE_DATA_CAN_WRITE_FAILURE,
    PUE_DATA_PRIMARY_INVALID_SEQUENCE_NUMBER,
    PUE_DATA_SECONDARY_INVALID_SEQUENCE_NUMBER,
    PUE_DATA_CAN_INVALID_SEQUENCE_NUMBER,
    PUE_DATA_INVALID_SEQUENCE_NUMBER,

    PUE_END_PRIMARY_UPDATE_NO_RESP = 71,
    PUE_END_PRIMARY_UPDATE_FAILURE,
    PUE_END_PRIMARY_UPDATE_UNKNOWN_ERROR,
    PUE_END_PRIMARY_VERSION_NO_RESP,
    PUE_END_PRIMARY_WRONG_VERSION,
    PUE_END_PRIMARY_ADDRISOUTOFRANGE,
    PUE_END_PRIMARY_GROUPIDISOUTOFRANGE,
    PUE_END_PRIMARY_ADDRISSAME,
    PUE_END_PRIMARY_UNKNOWN_ERROR,
    PUE_END_SECONDARY_UPDATE_NO_RESP,
    PUE_END_SECONDARY_UPDATE_FAILURE,
    PUE_END_SECONDARY_UPDATE_UNKNOWN_ERROR,
    PUE_END_SECONDARY_VERSION_NO_RESP,
    PUE_END_SECONDARY_WRONG_VERSION,
    PUE_END_SECONDARY_UNKNOWN_ERROR,
    PUE_END_SECONDARY_ADDRISOUTOFRANGE,
    PUE_END_SECONDARY_GROUPIDISOUTOFRANGE,
    PUE_END_SECONDARY_ADDRISSAME,
    PUE_END_CAN_UPDATE_NO_RESP,
    PUE_END_CAN_UPDATE_FAILURE,
    PUE_END_CAN_VERSION_NO_RESP,
    PUE_END_CAN_WRONG_VERSION,
    PUE_END_CAN_UNKNOWN_ERROR,
    PUE_END_CAN_ADDRISOUTOFRANGE,
    PUE_END_CAN_GROUPIDISOUTOFRANGE,
    PUE_END_CAN_ADDRISSAME,
    PUE_END_NOT_GET_SERIAL_NUMBER,
    PUE_END_UNKNOWN_ERROR
};

#define PWB_SDO_UPDATE_DATA_FRAME       0x2442
/// This write-only object contains the next 4 bytes of the sequence of binary data that forms the image used
/// for update external power modules software.
///
/// The values in the command are defined as follows:
///
/// | Byte      | Description         | UnitSize |
/// |-----------|---------------------|----------|
/// | 0         | data frame byte 1   | uint8    |
/// | 1         | data frame byte 2   | uint8    |
/// | 2         | data frame byte 3   | uint8    |
/// | 3         | data frame byte 4   | uint8    |

#define PWB_SDO_UPDATE_DATA_END         0x2443
/// This write-only object is used to notify the end of the upgrade for a power module.
///
/// For some vendors, a vendor-CRC is optional in data section

#define PWB_SDO_UPDATE_MODE             0x2444
/// This object specifies the mode of the power module update, which is defined
/// as below
///
/// | Mode                | Description                                                                |
/// |---------------------|----------------------------------------------------------------------------|
/// | PUM_VERIFY_ADDR_NUM | Verify the addresses and number of the power modules before updating       |
/// | PUM_VERIFY_NUM      | Verify only the number of the power modules before updating                |
/// | PUM_VERIFY_NOTHING  | Don't verify the addresses nor number of the power modules before updating |
///
enum TPwbUpdateMode {
    PUM_VERIFY_ADDR_NUM = 0,
    PUM_VERIFY_NUM,
    PUM_VERIFY_NOTHING,
};

/// ### PDO1 status
///
/// |byte.bit|Description                    |Value              |
/// |--------|-------------------------------|-------------------|
/// |0.0     |Interlink contactors DC+ status|0: open; 1: closed |
/// |0.1     |Interlink contactors DC- status|0: open; 1: closed |
/// |0.2     |Outlet error                   |0: normal, 1: error|
/// |0.3     |Configuration error            |0: normal, 1: error|
/// |0.4     |Interlink contactors DC+ error |0: normal, 1: error|
/// |0.5     |Interlink contactors DC- error |0: normal, 1: error|
/// |0.6-4.7 |reserved                       |-                  |

typedef union
{
    struct
    {
        uint32_t m_bInterlinkDCPlusClose:1;
        uint32_t m_bInterlinkDCMinusClose:1;
        uint32_t m_bHasOutletError:1;
        uint32_t m_bHasConfigurationError:1;
        uint32_t m_bInterlinkDCPlusError:1;
        uint32_t m_bInterlinkDCMinusError:1;
        uint32_t m_unused:26;
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
