/*
  This file is part of the AutomationCarrier library.
  Copyright (c) 2020 Arduino SA.

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

#ifndef _MAX31855_H_
#define _MAX31855_H_

#include <Arduino.h>
#include <mbed.h>
#include <SPI.h>

#define PROBE_K 0
#define PROBE_J 1

class MAX31855Class {
public:
  MAX31855Class(PinName cs = NC, SPIClass& spi = SPI);

  int begin();
  void end();

  float readTemperature(int type = PROBE_K);
  float readReferenceTemperature(int type = PROBE_K);

private:
  uint32_t readSensor();

  PinName _cs;
  SPIClass* _spi;
  SPISettings _spiSettings;
};

extern MAX31855Class THERM;

#endif
