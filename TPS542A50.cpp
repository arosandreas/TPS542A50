/*
    TPS542A50 - An arduino library for the TPS542A50 current sensor
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY
 */

#include <Wire.h>
#include "TPS542A50.h"

/*
TPS542A50::TPS542A50()
{
    address = TPS542A50_ADDRESS;
}
*/

TPS542A50::TPS542A50()
{
    address = TPS542A50_ADDRESS;
    I2C = true;
}


/*
TPS542A50::TPS542A50(int CS)
{
    _CS = CS;
    I2C = false;
    SPI.begin();
    pinMode(_CS, OUTPUT);
    digitalWrite(_CS, HIGH);
}
*/


uint8_t TPS542A50::_register8(uint8_t reg)
{
    Wire.beginTransmission(address);
    Wire.write(reg);
    Wire.endTransmission();

    Wire.requestFrom(address, 1);
    return Wire.read();
}

void TPS542A50::_register8(uint8_t reg, uint8_t regdata)
{
    Wire.beginTransmission(address);
    Wire.write(reg);
    Wire.write(regdata);
    Wire.endTransmission();
}

uint8_t TPS542A50::read8(uint8_t reg)
{
    return (_register8(reg));
}

void TPS542A50::write8(uint8_t reg, uint8_t value)
{
    _register8(reg, value);
}

//ID 0x0
uint8_t TPS542A50::getIC_Revision(){
    return (_register8(ID_REG));
}

//STATUS 0x1

uint8_t TPS542A50::getSTATUS_REG()
{
    return (_register8(STATUS_REG));
}

boolean TPS542A50::getPGOOD(){
    TPS542A50_Reg.reg1.all = _register8(STATUS_REG);
    return (TPS542A50_Reg.reg1.bit.PGOOD);
}
boolean TPS542A50::getUV_FAULT(){
    TPS542A50_Reg.reg1.all = _register8(STATUS_REG);
    return (TPS542A50_Reg.reg1.bit.UV_FAULT);
}
boolean TPS542A50::getOV_FAULT(){
    TPS542A50_Reg.reg1.all = _register8(STATUS_REG);
    return (TPS542A50_Reg.reg1.bit.OV_FAULT);
}
boolean TPS542A50::getOC_FAULT(){
    TPS542A50_Reg.reg1.all = _register8(STATUS_REG);
    return (TPS542A50_Reg.reg1.bit.OC_FAULT);
}
boolean TPS542A50::getOT_FAULT(){
    TPS542A50_Reg.reg1.all = _register8(STATUS_REG);
    return (TPS542A50_Reg.reg1.bit.OT_FAULT);
}

// VOUT_ADJ1 0x2
boolean TPS542A50::setVOUT_ADJ_H(uint8_t value){
    _register8(VOUT_ADJ1_REG, value);
    return (1);
} 

// VOUT_ADJ2 0x3
boolean TPS542A50::setVOUT_ADJ_L(uint8_t value){
    _register8(VOUT_ADJ2_REG, value);
    return (1);
}

// CONFIG1 0x4
boolean TPS542A50::setFSW(uint8_t value){
    TPS542A50_Reg.reg4.all = _register8(CONFIG1_REG);
    TPS542A50_Reg.reg4.bit.FSW = value;
    _register8(CONFIG2_REG, TPS542A50_Reg.reg4.all);
    return (1);
}
boolean TPS542A50::setCOMP(uint8_t value){
    TPS542A50_Reg.reg4.all = _register8(CONFIG1_REG);
    TPS542A50_Reg.reg4.bit.COMP = value;
    _register8(CONFIG2_REG, TPS542A50_Reg.reg4.all);
    return (1);
}

// CONFIG2 0x5
boolean TPS542A50::setSS(uint8_t value){
    TPS542A50_Reg.reg5.all = _register8(CONFIG2_REG);
    TPS542A50_Reg.reg5.bit.SS = value;
    _register8(CONFIG2_REG, TPS542A50_Reg.reg5.all);
    return (1);
}
boolean TPS542A50::setFCCM(uint8_t value){
    TPS542A50_Reg.reg5.all = _register8(CONFIG2_REG);
    TPS542A50_Reg.reg5.bit.FCCM = value;
    _register8(CONFIG2_REG, TPS542A50_Reg.reg5.all);
    return (1);
}
boolean TPS542A50::setILIM(uint8_t value){
    TPS542A50_Reg.reg5.all = _register8(CONFIG2_REG);
    TPS542A50_Reg.reg5.bit.ILIM = value;
    _register8(CONFIG2_REG, TPS542A50_Reg.reg5.all);
    return (1);
}



