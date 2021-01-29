/*
  This file is part of the MachineControl library.
  Copyright (c) 2021 Arduino SA.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "MAX31865.h"


MAX31865Class::MAX31865Class(PinName cs) : _spi(SPI), _cs(cs) {
}

static SPISettings _spiSettings(1000000, MSBFIRST, SPI_MODE1);

bool MAX31865Class::begin(int wires) {
  _spi.begin();

  pinMode(_cs, OUTPUT);
  digitalWrite(_cs, HIGH);
  // sets 2 or 4 wire
  if (wires == THREE_WIRE) {
    writeByte(MAX31856_CONFIG_REG, (readByte(MAX31856_CONFIG_REG) | MAX31856_CONFIG_3_WIRE));
  } else {
  
    writeByte(MAX31856_CONFIG_REG, (readByte(MAX31856_CONFIG_REG) & MAX31856_CONFIG_WIRE_MASK));
  }

  // disable bias
  writeByte(MAX31856_CONFIG_REG, readByte(MAX31856_CONFIG_REG) & MAX31856_CONFIG_BIAS_MASK);

  // disable auto convert mode
  writeByte(MAX31856_CONFIG_REG, readByte(MAX31856_CONFIG_REG) & MAX31856_CONFIG_CONV_MODE_MASK);

  // clear fault
  writeByte(MAX31856_CONFIG_REG, (readByte(MAX31856_CONFIG_REG) & MAX31856_CONFIG_CLEAR_FAULT_CYCLE)| MAX31856_CONFIG_CLEAR_FAULT);

  // set filter frequency
  writeByte(MAX31856_CONFIG_REG, readByte(MAX31856_CONFIG_REG) & MAX31856_CONFIG_60_50_HZ_FILTER_MASK);

  return true;
}

void MAX31865Class::clearFault(void) {
  writeByte(MAX31856_CONFIG_REG, (readByte(MAX31856_CONFIG_REG) & MAX31856_CONFIG_CLEAR_FAULT_CYCLE) | MAX31856_CONFIG_CLEAR_FAULT);
}

uint8_t MAX31865Class::readFault(void) {
  return readByte(MAX31856_FAULT_STATUS_REG);
}

bool MAX31865Class::getHighThresholdFault(uint8_t fault) {
  if (fault & MAX31865_FAULT_HIGH_THRESH) {
    return true;
  }
  return false;
}

bool MAX31865Class::getLowThresholdFault(uint8_t fault) {
  if (fault & MAX31865_FAULT_LOW_THRESH) {
    return true;
  }
  return false;
}

bool MAX31865Class::getLowREFINFault(uint8_t fault) {

  if (fault & MAX31865_FAULT_LOW_REFIN) {
    return true;
  }
  return false;
}

bool MAX31865Class::getHighREFINFault(uint8_t fault) {

  if (fault & MAX31865_FAULT_HIGH_REFIN) {
    return true;
  }
  return false;
}

bool MAX31865Class::getLowRTDINFault(uint8_t fault) {

  if (fault & MAX31865_FAULT_LOW_RTDIN) {
    return true;
  }
  return false;
}

bool MAX31865Class::getVoltageFault(uint8_t fault) {
  if (fault & MAX31865_FAULT_OVER_UNDER_VOLTAGE) {
    return true;
  }
  return false;
}

float MAX31865Class::readTemperature(float RTDnominal, float refResistor) {
  float Z1, Z2, Z3, Z4, Rt, temp;

  Rt = readRTD();
  Rt /= 32768;
  Rt *= refResistor;


  Z1 = -RTD_A;
  Z2 = RTD_A * RTD_A - (4 * RTD_B);
  Z3 = (4 * RTD_B) / RTDnominal;
  Z4 = 2 * RTD_B;

  temp = Z2 + (Z3 * Rt);
  temp = (sqrt(temp) + Z1) / Z4;

  if (temp >= 0)
    return temp;

  // ugh.
  Rt /= RTDnominal;
  Rt *= 100; // normalize to 100 ohm

  float rpoly = Rt;

  temp = -242.02;
  temp += 2.2228 * rpoly;
  rpoly *= Rt; // square
  temp += 2.5859e-3 * rpoly;
  rpoly *= Rt; // ^3
  temp -= 4.8260e-6 * rpoly;
  rpoly *= Rt; // ^4
  temp -= 2.8183e-8 * rpoly;
  rpoly *= Rt; // ^5
  temp += 1.5243e-10 * rpoly;

  return temp;
}

uint32_t MAX31865Class::readRTD() {

  // clear fault
  writeByte(MAX31856_CONFIG_REG, (readByte(MAX31856_CONFIG_REG) & MAX31856_CONFIG_CLEAR_FAULT_CYCLE) | MAX31856_CONFIG_CLEAR_FAULT);

  // enable bias
  writeByte(MAX31856_CONFIG_REG, (readByte(MAX31856_CONFIG_REG) | MAX31856_CONFIG_BIAS_ON));
  delay(10);

  // ONE shot cOnfIg and make readings change with readByte
  writeByte(MAX31856_CONFIG_REG, readByte(MAX31856_CONFIG_REG) | MAX31856_CONFIG_ONE_SHOT);
  delay(65);

  //readings bytes
  uint16_t read = (readBytes(MAX31856_RTD_MSB_REG));
  read = read >>1;
  // disable bias
  writeByte(MAX31856_CONFIG_REG, readByte(MAX31856_CONFIG_REG) & (MAX31856_CONFIG_BIAS_MASK));

  return read;
}

uint8_t MAX31865Class::readByte(uint8_t addr) {
  addr &= 0x7F;
  uint8_t read = 0;
  digitalWrite(_cs, LOW);

  _spi.beginTransaction(_spiSettings);
  _spi.transfer(addr);
  _spi.transfer(&read,1);
  _spi.endTransaction();

  digitalWrite(_cs, HIGH);

  return read;
}

uint16_t MAX31865Class::readBytes(uint8_t addr) {
  digitalWrite(_cs, LOW);
  uint16_t read = 0x00;
  _spi.beginTransaction(_spiSettings);
  _spi.transfer(addr);
  int i;
  for (i = 0; i<2; i++) {
    read = read << 8;
    read |= _spi.transfer(0);
  }
  
  _spi.endTransaction();

  digitalWrite(_cs, HIGH);

  return read;
}

void MAX31865Class::writeByte(uint8_t addr, uint8_t data) {
  addr |= 0x80; // make sure top bit is set
  uint8_t buffer[2] = {addr, data};
  digitalWrite(_cs, LOW);

  _spi.beginTransaction(_spiSettings);
  _spi.transfer(buffer,2);

  _spi.endTransaction();

  digitalWrite(_cs, HIGH);
}
