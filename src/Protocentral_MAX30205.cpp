//////////////////////////////////////////////////////////////////////////////////////////
//
//  Protocentral MAX30205 Arduino Library
//
//  Author: Ashwin Whitchurch
//  Copyright (c) 2018-2025 Protocentral Electronics
//
//  SPDX-License-Identifier: MIT
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//
//  For more information, visit https://github.com/Protocentral/Protocentral_MAX30205
//
//////////////////////////////////////////////////////////////////////////////////////////

#include "Protocentral_MAX30205.h"

MAX30205::MAX30205(uint8_t sensorAddress, TwoWire &wirePort) {
  this->sensorAddress = sensorAddress;
  _wire = &wirePort;
}

bool MAX30205::begin() {
  _wire->beginTransmission(sensorAddress);
  if (_wire->endTransmission() != 0) {
    return false;   // No device responded at this address
  }

  writeRegister(MAX30205_CONFIGURATION, 0x00);  // Continuous conversion, comparator mode
  writeRegister(MAX30205_THYST, 0x00);          // Hysteresis threshold
  writeRegister(MAX30205_TOS, 0x00);            // Over-temperature shutdown threshold
  return true;
}

bool MAX30205::scanAvailableSensors() {
  bool sensorFound = false;

  _wire->beginTransmission(MAX30205_ADDRESS1);
  if (_wire->endTransmission() == 0) {
    sensorAddress = MAX30205_ADDRESS1;
    sensorFound = true;
  }

  _wire->beginTransmission(MAX30205_ADDRESS2);
  if (_wire->endTransmission() == 0) {
    sensorAddress = MAX30205_ADDRESS2;
    sensorFound = true;
  }

  return sensorFound;
}

float MAX30205::getTemperature() {
  uint8_t raw[2] = {0};
  readRegisters(MAX30205_TEMPERATURE, raw, 2);  // Read the two temperature bytes

  int16_t value = (int16_t)((raw[0] << 8) | raw[1]);  // Combine MSB and LSB
  temperature = value * MAX30205_RESOLUTION;          // Convert to degrees Celsius
  return temperature;
}

float MAX30205::getTemperatureF() {
  return getTemperature() * 9.0f / 5.0f + 32.0f;
}

void MAX30205::shutdown() {
  uint8_t reg = readRegister(MAX30205_CONFIGURATION);   // Get the current configuration
  writeRegister(MAX30205_CONFIGURATION, reg | 0x80);    // Set the shutdown bit
}

void MAX30205::printRegisters() {
  Serial.println(readRegister(MAX30205_TEMPERATURE), BIN);
  Serial.println(readRegister(MAX30205_CONFIGURATION), BIN);
  Serial.println(readRegister(MAX30205_THYST), BIN);
  Serial.println(readRegister(MAX30205_TOS), BIN);
}

// ---------------------------------------------------------------------------
// Low-level I2C helpers
// ---------------------------------------------------------------------------

void MAX30205::writeRegister(uint8_t reg, uint8_t data) {
  _wire->beginTransmission(sensorAddress);  // Initialize the Tx buffer
  _wire->write(reg);                        // Put the register address in the Tx buffer
  _wire->write(data);                       // Put the data in the Tx buffer
  _wire->endTransmission();                 // Send the Tx buffer
}

uint8_t MAX30205::readRegister(uint8_t reg) {
  _wire->beginTransmission(sensorAddress);
  _wire->write(reg);
  _wire->endTransmission(false);
  _wire->requestFrom(sensorAddress, (uint8_t)1);
  return _wire->read();
}

void MAX30205::readRegisters(uint8_t reg, uint8_t *dest, uint8_t count) {
  _wire->beginTransmission(sensorAddress);
  _wire->write(reg);
  _wire->endTransmission(false);

  uint8_t i = 0;
  _wire->requestFrom(sensorAddress, count);
  while (_wire->available()) {
    dest[i++] = _wire->read();
  }
}
