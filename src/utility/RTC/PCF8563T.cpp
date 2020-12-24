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

#include "PCF8563T.h"

#define PCF8563T_ADDRESS        0x51
#define PCF8563T_STATUS_2_REG   0X01
#define PCF8563T_VL_SECONDS_REG 0X02
#define PCF8563T_MINUTES_REG    0x03
#define PCF8563T_HOURS_REG      0X04
#define PCF8563T_DAYS_REG       0x05
#define PCF8563T_MONTHS_REG     0x07
#define PCF8563T_YEARS_REG      0x08

// allarm managemet
#define PCF8563T_MINUTE_ALARM_REG 0x09
#define PCF8563T_MINUTE_ALARM_AE_M_MASK 0x80
#define PCF8563T_MINUTE_ALARM_ON 0x7F

#define PCF8563T_HOUR_ALARM_REG 0x0A
#define PCF8563T_HOUR_ALARM_AE_H_MASK 0x80
#define PCF8563T_HOUR_ALARM_ON 0x7F

#define PCF8563T_DAY_ALARM_REG 0x0B
#define PCF8563T_DAY_ALARM_AE_D_MASK 0x80
#define PCF8563T_DAY_ALARM_ON 0x7F

#define PCF8563T_TIMER_CONTROL_REG 0X0E
#define PCF8563T_TIMER_CONTROL_ON 0x80
#define PCF8563T_TIMER_CONTROL_OFF 0x7F

#define PCF8563T_STATUS_2_AIE_MASK 0x02
#define PCF8563T_STATUS_2_CLEAR_INT 0xF7
#define PCF8563T_STATUS_2_INT_OFF 0x7d

PCF8563TClass::PCF8563TClass()
{
}

bool PCF8563TClass::begin()
{
  Wire1.begin(); // join i2c bus

  Wire1.beginTransmission(PCF8563T_ADDRESS);
  if (!Wire1.endTransmission()) {
    return true;
  }
  return false;
}

void PCF8563TClass::setYears(uint8_t years) { 
  uint8_t dec = years / 10;
  uint8_t unit = years - (dec * 10);
  writeByte(PCF8563T_YEARS_REG, ((dec << 4) + unit));
}

void PCF8563TClass::setMonths(uint8_t months) {
  uint8_t offset = 0;
  if (months > 9) {
    offset = 6;
  }
  writeByte(PCF8563T_MONTHS_REG, months + offset);
}

void PCF8563TClass::setDays(uint8_t days) {
  uint8_t dec = days / 10;
  uint8_t unit = days - (dec * 10);
  writeByte(PCF8563T_DAYS_REG, ((dec << 4) + unit));
}

void PCF8563TClass::setHours(uint8_t hours) { 
  uint8_t dec = hours / 10;
  uint8_t unit = hours - (dec * 10);
  writeByte(PCF8563T_HOURS_REG, ((dec << 4) + unit)); //check formula on datasheet val + 6 * (val / 10)
}

void PCF8563TClass::setMinutes(uint8_t minutes) {
  uint8_t dec = minutes / 10;
  uint8_t unit = minutes - (dec * 10);
  writeByte(PCF8563T_MINUTES_REG, ((dec << 4) + unit));
}

void PCF8563TClass::setSeconds(uint8_t seconds) {
  uint8_t dec = seconds / 10;
  uint8_t unit = seconds - (dec * 10);
  writeByte(PCF8563T_VL_SECONDS_REG, ((dec << 4) + unit));
}

uint8_t PCF8563TClass::getYears() {
  uint8_t years = readByte(PCF8563T_YEARS_REG);
  return (years & 0x0F) + ((years >> 4)*10);
}

uint8_t PCF8563TClass::getMonths() {
  uint8_t months = readByte(PCF8563T_MONTHS_REG) & 0x1F;
  if(months > 9) {
    return months - 6;
  } else {
    return months;
  }
}

uint8_t PCF8563TClass::getDays() {
  uint8_t days = readByte(PCF8563T_DAYS_REG);
  return (days & 0x0F) + ((days >> 4)*10);
}

uint8_t PCF8563TClass::getHours() {
  uint8_t hours = readByte(PCF8563T_HOURS_REG) & 0x3F;
  return (hours & 0x0F) + ((hours >> 4)*10);
}

uint8_t PCF8563TClass::getMinutes() {
  uint8_t minutes = (readByte(PCF8563T_MINUTES_REG)) & 0x7F ;
  return (minutes & 0x0F) + ((minutes >> 4)*10);
}

uint8_t PCF8563TClass::getSeconds() {
  uint8_t seconds = readByte(PCF8563T_VL_SECONDS_REG) & 0x7F;
  return (seconds & 0x0F) + ((seconds >> 4)*10);
}


void PCF8563TClass::setEpoch() {
  struct tm time;
  time.tm_sec = getSeconds();
  time.tm_min = getMinutes();
  time.tm_hour = getHours();
  time.tm_mday = getDays();
  time.tm_mon = getMonths() - 1;
  time.tm_year = getYears() + 100;
  time_t seconds;
  _rtc_maketime(&time, &seconds, RTC_FULL_LEAP_YEAR_SUPPORT);
  set_time(seconds);
}

void PCF8563TClass::setEpoch(time_t seconds) {
  struct tm time;
  _rtc_localtime(seconds, &time, RTC_FULL_LEAP_YEAR_SUPPORT);

  setSeconds(time.tm_sec);
  setMinutes(time.tm_min);
  setHours( time.tm_hour);
  setDays(time.tm_mday);
  setMonths(time.tm_mon + 1);
  setYears((time.tm_year - 100));
  set_time(seconds);
}


void PCF8563TClass::setEpoch(uint8_t years, uint8_t months, uint8_t days, uint8_t hours, uint8_t minutes, uint8_t seconds) {
  struct tm time;
  time_t utcsec;

  time.tm_sec = seconds;
  time.tm_min = minutes;
  time.tm_hour = hours;
  time.tm_mday = days;
  time.tm_mon = months - 1;
  time.tm_year = years + 100;  // year since 1900

  _rtc_maketime(&time, &utcsec,RTC_FULL_LEAP_YEAR_SUPPORT);
  set_time(utcsec);
}

time_t PCF8563TClass::getEpoch() {
  struct tm time;
  time_t seconds;

  time.tm_sec = getSeconds();
  time.tm_min = getMinutes();
  time.tm_hour = getHours();
  time.tm_mday = getDays();
  time.tm_mon = getMonths() - 1;
  time.tm_year = getYears() + 100;  // year since 1900

  _rtc_maketime(&time, &seconds, RTC_FULL_LEAP_YEAR_SUPPORT);
  return seconds;
}

void PCF8563TClass::enableAlarm() {
  writeByte(PCF8563T_STATUS_2_REG, (readByte(PCF8563T_STATUS_2_REG) & PCF8563T_STATUS_2_CLEAR_INT) | PCF8563T_STATUS_2_AIE_MASK);
}

void PCF8563TClass::disableAlarm() {
   writeByte(PCF8563T_STATUS_2_REG, (readByte(PCF8563T_STATUS_2_REG) & PCF8563T_STATUS_2_INT_OFF));
}

void PCF8563TClass::clearAlarm() {
  writeByte(PCF8563T_STATUS_2_REG, (readByte(PCF8563T_STATUS_2_REG) & PCF8563T_STATUS_2_CLEAR_INT) | PCF8563T_STATUS_2_AIE_MASK);
}

void PCF8563TClass::setMinuteAlarm(uint8_t minutes) {
  uint8_t dec = minutes / 10;
  uint8_t unit = minutes - (dec * 10);
  uint8_t min_alarm = PCF8563T_MINUTE_ALARM_ON & ((dec << 4) + unit);
  writeByte(PCF8563T_MINUTE_ALARM_REG , min_alarm);
}

void PCF8563TClass::disaleMinuteAlarm() {
  writeByte(PCF8563T_MINUTE_ALARM_REG, readByte(PCF8563T_MINUTE_ALARM_REG) | PCF8563T_MINUTE_ALARM_AE_M_MASK);
}

void PCF8563TClass::setHourAlarm(uint8_t hours) {
  uint8_t dec = hours / 10;
  uint8_t unit = hours - (dec * 10);
  uint8_t hour_alarm = PCF8563T_HOUR_ALARM_AE_H_MASK & ((dec << 4) + unit);
  writeByte(PCF8563T_HOURS_REG, hour_alarm); //check formula on datasheet val + 6 * (val / 10)
}

void PCF8563TClass::disaleHourAlarm() {
  writeByte(PCF8563T_HOUR_ALARM_REG, readByte(PCF8563T_HOUR_ALARM_REG) | PCF8563T_HOUR_ALARM_AE_H_MASK);
}

void PCF8563TClass::setDayAlarm(uint8_t days) {
  uint8_t dec = days / 10;
  uint8_t unit = days - (dec * 10);
   uint8_t day_alarm = PCF8563T_DAY_ALARM_ON & ((dec << 4) + unit);
  writeByte(PCF8563T_DAY_ALARM_REG, day_alarm);
}

void PCF8563TClass::disaleDayAlarm() {
  writeByte(PCF8563T_DAY_ALARM_REG, readByte(PCF8563T_DAY_ALARM_REG) | PCF8563T_DAY_ALARM_AE_D_MASK );
}

void PCF8563TClass::writeByte(uint8_t regAddres, uint8_t data) {
  Wire1.beginTransmission(PCF8563T_ADDRESS);
  Wire1.write(regAddres);
  Wire1.write(data);
  Wire1.endTransmission();
}

uint8_t PCF8563TClass::readByte(uint8_t regAddres) {
  Wire1.beginTransmission(PCF8563T_ADDRESS);
  Wire1.write(regAddres);  // Day Register
  Wire1.endTransmission();
  Wire1.requestFrom(PCF8563T_ADDRESS, 1);

  return Wire1.read();
}