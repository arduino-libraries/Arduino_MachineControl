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
#include "time.h"
#include "mbed_mktime.h"
#include "Wire.h"
#define RTC_INT PB_9
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

  void setEpoch();
  void setEpoch(uint8_t years, uint8_t months, uint8_t days, uint8_t hours, uint8_t minutes, uint8_t seconds);
  void setEpoch(time_t seconds);
  time_t getEpoch();

void enableAlarm();
void disableAlarm();
void clearAlarm();
void setMinuteAlarm(uint8_t minutes);
void disableMinuteAlarm();
void setHourAlarm(uint8_t hours);
void disableHourAlarm();
void setDayAlarm(uint8_t days);
void disableDayAlarm();


private:
  void writeByte(uint8_t regAddres, uint8_t data);
  uint8_t readByte(uint8_t regAddres);
};

#endif
