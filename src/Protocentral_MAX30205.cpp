//////////////////////////////////////////////////////////////////////////////////////////
//
//    Arduino library for the MAX30205 body temperature sensor breakout board
//
//    Author: Ashwin Whitchurch
//    Copyright (c) 2018 ProtoCentral
//
//    This software is licensed under the MIT License(http://opensource.org/licenses/MIT).
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
//   NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//   For information on how to use, visit https://github.com/protocentral/ProtoCentral_MAX30205
/////////////////////////////////////////////////////////////////////////////////////////

#include "Arduino.h"
#include <Wire.h>
#include "Protocentral_MAX30205.h"

float MAX30205::getTemperature(void)
{
	uint8_t readRaw[2] = {0};
	I2CreadBytes(sensorAddress, MAX30205_TEMPERATURE, &readRaw[0], 2); // read two bytes
	int16_t raw = readRaw[0] << 8 | readRaw[1];						   // combine two bytes
	temperature = raw * 0.00390625;									   // convert to temperature
	return temperature;
}

bool MAX30205::scanAvailableSensors(void)
{
	bool sensorFound = false;

	_wirePort->beginTransmission(MAX30205_ADDRESS1);
	if (_wirePort->endTransmission() == 0)
	{
		sensorAddress = MAX30205_ADDRESS1;
		sensorFound = true;
	}

	_wirePort->beginTransmission(MAX30205_ADDRESS2);
	if (_wirePort->endTransmission() == 0)
	{
		sensorAddress = MAX30205_ADDRESS2;
		sensorFound = true;
	}

	return sensorFound;
}

void MAX30205::shutdown(void)
{
	uint8_t reg = i2c_read_byte(sensorAddress, MAX30205_CONFIGURATION); // Get the current register
	i2c_write_byte(sensorAddress, MAX30205_CONFIGURATION, reg | 0x80);
}

void MAX30205::begin(void)
{
	i2c_write_byte(sensorAddress, MAX30205_CONFIGURATION, 0x00); // mode config
	i2c_write_byte(sensorAddress, MAX30205_THYST, 0x00);		 // set threshold
	i2c_write_byte(sensorAddress, MAX30205_TOS, 0x00);			 //
}

void MAX30205::begin(TwoWire &wirePort, bool init_bus, uint8_t address)
{
	_wirePort = &wirePort; // Grab which port the user wants us to use
	if (init_bus)
		_wirePort->begin(); // Begin the I2C port
	sensorAddress = address;
	begin();
	printRegisters();
}

void MAX30205::printRegisters(void)
{
	Serial.println(i2c_read_byte(sensorAddress, MAX30205_TEMPERATURE), BIN);
	Serial.println(i2c_read_byte(sensorAddress, MAX30205_CONFIGURATION), BIN);
	Serial.println(i2c_read_byte(sensorAddress, MAX30205_THYST), BIN);
	Serial.println(i2c_read_byte(sensorAddress, MAX30205_TOS), BIN);
}

// Wire.h read and write protocols
void MAX30205::i2c_write_byte(uint8_t address, uint8_t subAddress, uint8_t data)
{
	_wirePort->beginTransmission(address); // Initialize the Tx buffer
	_wirePort->write(subAddress);		   // Put slave register address in Tx buffer
	_wirePort->write(data);				   // Put data in Tx buffer
	_wirePort->endTransmission();		   // Send the Tx buffer
}

uint8_t MAX30205::i2c_read_byte(uint8_t address, uint8_t subAddress)
{
	uint8_t data; // `data` will store the register data
	_wirePort->beginTransmission(address);
	_wirePort->write(subAddress);
	_wirePort->endTransmission(false);
	_wirePort->requestFrom(address, (uint8_t)1);
	data = _wirePort->read();
	return data;
}

void MAX30205::I2CreadBytes(uint8_t address, uint8_t subAddress, uint8_t *dest, uint8_t count)
{
	_wirePort->beginTransmission(address); // Initialize the Tx buffer
	// Next send the register to be read. OR with 0x80 to indicate multi-read.
	_wirePort->write(subAddress);
	_wirePort->endTransmission(false);
	uint8_t i = 0;
	_wirePort->requestFrom(address, count); // Read bytes from slave register address
	while (_wirePort->available())
	{
		dest[i++] = _wirePort->read();
	}
}
