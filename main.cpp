/* TPS542A50
Andreas Jonsson

*/

#include <Arduino.h>
#include <Wire.h>
#include "TPS542A50.h"

#define EN (5)
#define PGM (6)

TPS542A50 dcdc1; // initialize dcdc1 for i2c

void  setup()
{
  delay(100);
  Wire.begin();
  Serial.begin(9600);
  delay(100);
  pinMode(EN,OUTPUT);
  pinMode(PGM, OUTPUT);
  Serial.println(F("DISABLE DCDC1"));
  digitalWrite(EN,0);  //disable tps542a50
  digitalWrite(PGM,1);  //enable program mode
  delay(2000);
  Serial.println(F("RESTARTED"));
  Serial.print(F("getIC_Revision: "));
  Serial.println(dcdc1.getIC_Revision(), HEX);
  Serial.print(F("getSTATUS_REG: "));
  Serial.println(dcdc1.getSTATUS_REG(), HEX);

  //configure tps542a50
  dcdc1.setFSW(0x3);
  dcdc1.setCOMP(0x1);
  dcdc1.setSS(0x1);
  dcdc1.setFCCM(0x1);
  dcdc1.setILIM(0x3);
  delay(2000);

  Serial.println(F("ENABLE DCDC1"));
  digitalWrite(PGM, 0);
  digitalWrite(EN, 1);
  delay(3000);
  
  while (1){
    //Serial.println(F("MARGIN HIGH"));
    dcdc1.setVOUT_ADJ_H(0X01);
    dcdc1.setVOUT_ADJ_L(0X66);
    delay(100);
    //Serial.println(F("MARGIN LOW"));
    dcdc1.setVOUT_ADJ_H(0XFE);
    dcdc1.setVOUT_ADJ_L(0X9A);
    delay(100);
  }

}

void loop()
{
  

}