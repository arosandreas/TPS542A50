/*
    TPS542A50 - An arduino library for the TPS542A50 current sensor
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY
 */

#ifndef TPS542A50_h

#define TPS542A50_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define TPS542A50_ADDRESS 0x60 // 000 AGND


// define ina registers
#define ID_REG 0x0
#define STATUS_REG 0x1
#define VOUT_ADJ1_REG 0x2
#define VOUT_ADJ2_REG 0x3
#define CONFIG1_REG 0x4
#define CONFIG2_REG 0x5

//--------------Address 0x0---------------------------------

//--------------Address 0x1---------------------------------
struct STATUS_REGISTER
{
    uint8_t PGOOD       : 1;               // 0
    uint8_t UV_FAULT    : 1;               // 1
    uint8_t OV_FAULT    : 1;               // 2
    uint8_t OC_FAULT    : 1;               // 3
    uint8_t OT_FAULT    : 1;               // 4
    uint8_t RESERVED    : 3;               // 5-7
};
union STATUS_REGISTER_U
{
    uint16_t all;
    struct STATUS_REGISTER bit;
};

//--------------Address 0x2---------------------------------

//--------------Address 0x3---------------------------------

//--------------Address 0x4---------------------------------
struct CONFIG1_REGISTER
{
    uint8_t FSW : 3;      // 0..2
    uint8_t COMP : 2;     // 3..4
    uint8_t RESERVED : 3; // 5..7
};
union CONFIG1_REGISTER_U
{
    uint16_t all;
    struct CONFIG1_REGISTER bit;
};

//--------------Address 0x5---------------------------------
struct CONFIG2_REGISTER
{
    uint8_t SS : 2;       // 0..1
    uint8_t FCCM : 1;     // 2
    uint8_t ILIM : 3;     // 3..5
    uint8_t RESERVED : 2; // 6..7
};
union CONFIG2_REGISTER_U
{
    uint16_t all;
    struct CONFIG2_REGISTER bit;
};

// All  registers
typedef struct TPS542A50Reg
{
    union STATUS_REGISTER_U reg1;
    union CONFIG1_REGISTER_U reg4;
    union CONFIG2_REGISTER_U reg5;
} TPS542A50Reg_t;

class TPS542A50
{
    int address;
    //float _convert2comp2float(uint64_t, uint16_t, float);
    //uint64_t _register40(byte reg);
    //uint32_t _register24(byte reg);
    uint8_t _register8(uint8_t);
    //uint16_t _register16(byte);
    void _register8(uint8_t, uint8_t);
    //void _register16(byte, uint16_t);
    //int _CS = 10;
    bool I2C = true;

public:
    TPS542A50Reg_t TPS542A50_Reg; 
    TPS542A50();
    //TPS542A50(int CS);
    //uint32_t read24(byte);
    //uint16_t read16(byte);
    //void write16(byte, uint16_t);
    void write8(uint8_t, uint8_t);
    uint8_t read8(uint8_t);

    //ID 0x0
    uint8_t getIC_Revision(); //

    //STATUS 0x1
    uint8_t getSTATUS_REG();
    boolean getPGOOD(); //
    boolean getUV_FAULT(); //
    boolean getOV_FAULT(); //
    boolean getOC_FAULT(); //
    boolean getOT_FAULT(); //

    // VOUT_ADJ1 0x2
    boolean setVOUT_ADJ_H(uint8_t value); //

    // VOUT_ADJ2 0x3
    boolean setVOUT_ADJ_L(uint8_t value); //

    // CONFIG1 0x4
    boolean setFSW(uint8_t value); //
    boolean setCOMP(uint8_t value); //

    // CONFIG2 0x5
    boolean setSS(uint8_t value);   //
    boolean setFCCM(uint8_t value); //
    boolean setILIM(uint8_t value); //

};

#endif