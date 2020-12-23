/*
  This file is part of the MachineControl library.
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

#ifndef _PCF8563T_H_INCLUDED
#define _PCF8563T_H_INCLUDED

#include "Arduino.h"
#include "mbed.h"
#include "Wire.h"

class PCF8563TClass {

public:
  PCF8563TClass();
  bool begin();
  void setYears(uint8_t years);
  void setMonths(uint8_t months);
  void setDays(uint8_t days);
  void setHours(uint8_t hours);
  void setMinutes(uint8_t minutes);
  void setSeconds(uint8_t seconds);

  uint8_t getYears();
  uint8_t getMonths();
  uint8_t getDays();
  uint8_t getHours();
  uint8_t getMinutes();
  uint8_t getSeconds();

private:
  void writeByte(uint8_t regAddres, uint8_t data);
  uint8_t readByte(uint8_t regAddres);
};

#endif
