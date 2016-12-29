

#include "Arduino.h"
#include <Wire.h>
#include "Protocentral_MAX30205.h"



int MAX30205::getTemperature(void){
    I2CreadBytes(MAX30205_ADDRESS,MAX30205_TEMPERATURE, *temp ,2);
	int16_t raw = data1 << 8 | data2;
    temp = (float)raw  * 0.00390625;
}

void MAX30205::shutdown(void){
  uint8_t reg = I2CreadByte(MAX30205_ADDRESS, MAX30205_MODE_CONFIG);  // Get the current register
  I2CwriteByte(MAX30205_ADDRESS, MAX30205_MODE_CONFIG, reg | 0x80);   
}

void MAX30205::begin(pulseWidth pw, ledCurrent ir, sampleRate sr){

 
  I2CwriteByte(MAX30205_ADDRESS, MAX30205_CONFIGURATION, 0x00); //mode config
  I2CwriteByte(MAX30205_ADDRESS, MAX30205_THYST , 		 0x00); // set threshold
  I2CwriteByte(MAX30205_ADDRESS, MAX30205_TOS, 			 0x00); //  
}

void MAX30205::printRegisters(void){
  Serial.println(I2CreadByte(MAX30205_ADDRESS, MAX30205_TEMPERATURE),  BIN);
  Serial.println(I2CreadByte(MAX30205_ADDRESS, MAX30205_CONFIGURATION),  BIN);
  Serial.println(I2CreadByte(MAX30205_ADDRESS, MAX30205_THYST), BIN);
  Serial.println(I2CreadByte(MAX30205_ADDRESS, MAX30205_TOS), BIN);

}

// Wire.h read and write protocols
void MAX30205::I2CwriteByte(uint8_t address, uint8_t subAddress, uint8_t data)
{
	Wire.beginTransmission(address);  // Initialize the Tx buffer
	Wire.write(subAddress);           // Put slave register address in Tx buffer
	Wire.write(data);                 // Put data in Tx buffer
	Wire.endTransmission();           // Send the Tx buffer
}

uint8_t MAX30205::I2CreadByte(uint8_t address, uint8_t subAddress)
{
	uint8_t data; // `data` will store the register data
	Wire.beginTransmission(address);         
	Wire.write(subAddress);	                 
	Wire.endTransmission(false);             
	Wire.requestFrom(address, (uint8_t) 1);  
	data = Wire.read();                      
	return data;                             
}

void MAX30205::I2CreadBytes(uint8_t address, uint8_t subAddress, uint8_t * dest, uint8_t count)
{
	Wire.beginTransmission(address);   // Initialize the Tx buffer
	// Next send the register to be read. OR with 0x80 to indicate multi-read.
	Wire.write(subAddress);     
	Wire.endTransmission(false);
	uint8_t i = 0;
	Wire.requestFrom(address, count);  // Read bytes from slave register address
	while (Wire.available())
	{
		dest[i++] = Wire.read(); 
	}
}
