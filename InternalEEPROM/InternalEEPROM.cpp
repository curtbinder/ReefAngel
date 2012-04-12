/*
 * Copyright 2010 Curt Binder
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "InternalEEPROM.h"
#include <Globals.h>

// Byte Functions
uint8_t InternalEEPROMClass::MHOnHour_read()
{
    return read(Mem_B_MHOnHour);
}

void InternalEEPROMClass::MHOnHour_write(const uint8_t value)
{
    write(Mem_B_MHOnHour, value);
}

uint8_t InternalEEPROMClass::MHOnMinute_read()
{
    return read(Mem_B_MHOnMinute);
}

void InternalEEPROMClass::MHOnMinute_write(const uint8_t value)
{
    write(Mem_B_MHOnMinute, value);
}

uint8_t InternalEEPROMClass::MHOffHour_read()
{
    return read(Mem_B_MHOffHour);
}

void InternalEEPROMClass::MHOffHour_write(const uint8_t value)
{
    write(Mem_B_MHOffHour, value);
}

uint8_t InternalEEPROMClass::MHOffMinute_read()
{
    return read(Mem_B_MHOffMinute);
}

void InternalEEPROMClass::MHOffMinute_write(const uint8_t value)
{
    write(Mem_B_MHOffMinute, value);
}

uint8_t InternalEEPROMClass::StdLightsOnHour_read()
{
    return read(Mem_B_StdLightsOnHour);
}

void InternalEEPROMClass::StdLightsOnHour_write(const uint8_t value)
{
    write(Mem_B_StdLightsOnHour, value);
}

uint8_t InternalEEPROMClass::StdLightsOnMinute_read()
{
    return read(Mem_B_StdLightsOnMinute);
}

void InternalEEPROMClass::StdLightsOnMinute_write(const uint8_t value)
{
    write(Mem_B_StdLightsOnMinute, value);
}

uint8_t InternalEEPROMClass::StdLightsOffHour_read()
{
    return read(Mem_B_StdLightsOffHour);
}

void InternalEEPROMClass::StdLightsOffHour_write(const uint8_t value)
{
    write(Mem_B_StdLightsOffHour, value);
}

uint8_t InternalEEPROMClass::StdLightsOffMinute_read()
{
    return read(Mem_B_StdLightsOffMinute);
}

void InternalEEPROMClass::StdLightsOffMinute_write(const uint8_t value)
{
    write(Mem_B_StdLightsOffMinute, value);
}

uint8_t InternalEEPROMClass::DP1Timer_read()
{
    return read(Mem_B_DP1Timer);
}

void InternalEEPROMClass::DP1Timer_write(const uint8_t value)
{
    write(Mem_B_DP1Timer, value);
}

uint8_t InternalEEPROMClass::DP2Timer_read()
{
    return read(Mem_B_DP2Timer);
}

void InternalEEPROMClass::DP2Timer_write(const uint8_t value)
{
    write(Mem_B_DP2Timer, value);
}

uint8_t InternalEEPROMClass::LEDPWMDaylight_read()
{
    return read(Mem_B_LEDPWMDaylight);
}

void InternalEEPROMClass::LEDPWMDaylight_write(const uint8_t value)
{
    write(Mem_B_LEDPWMDaylight, value);
}

uint8_t InternalEEPROMClass::LEDPWMActinic_read()
{
    return read(Mem_B_LEDPWMActinic);
}

void InternalEEPROMClass::LEDPWMActinic_write(const uint8_t value)
{
    write(Mem_B_LEDPWMActinic, value);
}

uint8_t InternalEEPROMClass::ATOTimeout_read()
{
    return read(Mem_B_ATOTimeout);
}

void InternalEEPROMClass::ATOTimeout_write(const uint8_t value)
{
    write(Mem_B_ATOTimeout, value);
}

uint8_t InternalEEPROMClass::ATOHighTimeout_read()
{
    return read(Mem_B_ATOHighTimeout);
}

void InternalEEPROMClass::ATOHighTimeout_write(const uint8_t value)
{
    write(Mem_B_ATOHighTimeout, value);
}

uint8_t InternalEEPROMClass::ATOHourInterval_read()
{
    return read(Mem_B_ATOHourInterval);
}

void InternalEEPROMClass::ATOHourInterval_write(const uint8_t value)
{
    write(Mem_B_ATOHourInterval, value);
}

uint8_t InternalEEPROMClass::ATOHighHourInterval_read()
{
    return read(Mem_B_ATOHighHourInterval);
}

void InternalEEPROMClass::ATOHighHourInterval_write(const uint8_t value)
{
    write(Mem_B_ATOHighHourInterval, value);
}

uint8_t InternalEEPROMClass::MHDelay_read()
{
    return read(Mem_B_MHDelay);
}

void InternalEEPROMClass::MHDelay_write(const uint8_t value)
{
    write(Mem_B_MHDelay, value);
}

uint8_t InternalEEPROMClass::DP1OnHour_read()
{
    return read(Mem_B_DP1OnHour);
}

void InternalEEPROMClass::DP1OnHour_write(const uint8_t value)
{
    write(Mem_B_DP1OnHour, value);
}

uint8_t InternalEEPROMClass::DP1OnMinute_read()
{
    return read(Mem_B_DP1OnMinute);
}

void InternalEEPROMClass::DP1OnMinute_write(uint8_t value)
{
    write(Mem_B_DP1OnMinute, value);
}

uint8_t InternalEEPROMClass::DP2OnHour_read()
{
    return read(Mem_B_DP2OnHour);
}

void InternalEEPROMClass::DP2OnHour_write(const uint8_t value)
{
    write(Mem_B_DP2OnHour, value);
}

uint8_t InternalEEPROMClass::DP2OnMinute_read()
{
    return read(Mem_B_DP2OnMinute);
}

void InternalEEPROMClass::DP2OnMinute_write(const uint8_t value)
{
    write(Mem_B_DP2OnMinute, value);
}

uint8_t InternalEEPROMClass::T1Pointer_read()
{
    return read(T1Pointer);
}

void InternalEEPROMClass::T1Pointer_write(const uint8_t value)
{
    write(T1Pointer, value);
}

uint8_t InternalEEPROMClass::PWMSlopeStartD_read()
{
    return read(Mem_B_PWMSlopeStartD);
}

void InternalEEPROMClass::PWMSlopeStartD_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeStartD, value);
}

uint8_t InternalEEPROMClass::PWMSlopeEndD_read()
{
    return read(Mem_B_PWMSlopeEndD);
}

void InternalEEPROMClass::PWMSlopeEndD_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeEndD, value);
}

uint8_t InternalEEPROMClass::PWMSlopeDurationD_read()
{
    return read(Mem_B_PWMSlopeDurationD);
}

void InternalEEPROMClass::PWMSlopeDurationD_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeDurationD, value);
}

uint8_t InternalEEPROMClass::PWMSlopeStartA_read()
{
    return read(Mem_B_PWMSlopeStartA);
}

void InternalEEPROMClass::PWMSlopeStartA_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeStartA, value);
}

uint8_t InternalEEPROMClass::PWMSlopeEndA_read()
{
    return read(Mem_B_PWMSlopeEndA);
}

void InternalEEPROMClass::PWMSlopeEndA_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeEndA, value);
}

uint8_t InternalEEPROMClass::PWMSlopeDurationA_read()
{
    return read(Mem_B_PWMSlopeDurationA);
}

void InternalEEPROMClass::PWMSlopeDurationA_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeDurationA, value);
}

uint8_t InternalEEPROMClass::RFMode_read()
{
    return read(Mem_B_RFMode);
}

void InternalEEPROMClass::RFMode_write(const uint8_t value)
{
    write(Mem_B_RFMode, value);
}

uint8_t InternalEEPROMClass::RFSpeed_read()
{
    return read(Mem_B_RFSpeed);
}

void InternalEEPROMClass::RFSpeed_write(const uint8_t value)
{
    write(Mem_B_RFSpeed, value);
}

uint8_t InternalEEPROMClass::RFDuration_read()
{
    return read(Mem_B_RFDuration);
}

void InternalEEPROMClass::RFDuration_write(const uint8_t value)
{
    write(Mem_B_RFDuration, value);
}

uint8_t InternalEEPROMClass::PWMSlopeStart0_read()
{
    return read(Mem_B_PWMSlopeStart0);
}

void InternalEEPROMClass::PWMSlopeStart0_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeStart0, value);
}

uint8_t InternalEEPROMClass::PWMSlopeEnd0_read()
{
    return read(Mem_B_PWMSlopeEnd0);
}

void InternalEEPROMClass::PWMSlopeEnd0_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeEnd0, value);
}

uint8_t InternalEEPROMClass::PWMSlopeDuration0_read()
{
    return read(Mem_B_PWMSlopeDuration0);
}

void InternalEEPROMClass::PWMSlopeDuration0_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeDuration0, value);
}

uint8_t InternalEEPROMClass::PWMSlopeStart1_read()
{
    return read(Mem_B_PWMSlopeStart1);
}

void InternalEEPROMClass::PWMSlopeStart1_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeStart1, value);
}

uint8_t InternalEEPROMClass::PWMSlopeEnd1_read()
{
    return read(Mem_B_PWMSlopeEnd1);
}

void InternalEEPROMClass::PWMSlopeEnd1_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeEnd1, value);
}

uint8_t InternalEEPROMClass::PWMSlopeDuration1_read()
{
    return read(Mem_B_PWMSlopeDuration1);
}

void InternalEEPROMClass::PWMSlopeDuration1_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeDuration1, value);
}

uint8_t InternalEEPROMClass::PWMSlopeStart2_read()
{
    return read(Mem_B_PWMSlopeStart2);
}

void InternalEEPROMClass::PWMSlopeStart2_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeStart2, value);
}

uint8_t InternalEEPROMClass::PWMSlopeEnd2_read()
{
    return read(Mem_B_PWMSlopeEnd2);
}

void InternalEEPROMClass::PWMSlopeEnd2_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeEnd2, value);
}

uint8_t InternalEEPROMClass::PWMSlopeDuration2_read()
{
    return read(Mem_B_PWMSlopeDuration2);
}

void InternalEEPROMClass::PWMSlopeDuration2_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeDuration2, value);
}

uint8_t InternalEEPROMClass::PWMSlopeStart3_read()
{
    return read(Mem_B_PWMSlopeStart3);
}

void InternalEEPROMClass::PWMSlopeStart3_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeStart3, value);
}

uint8_t InternalEEPROMClass::PWMSlopeEnd3_read()
{
    return read(Mem_B_PWMSlopeEnd3);
}

void InternalEEPROMClass::PWMSlopeEnd3_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeEnd3, value);
}

uint8_t InternalEEPROMClass::PWMSlopeDuration3_read()
{
    return read(Mem_B_PWMSlopeDuration3);
}

void InternalEEPROMClass::PWMSlopeDuration3_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeDuration3, value);
}

uint8_t InternalEEPROMClass::PWMSlopeStart4_read()
{
    return read(Mem_B_PWMSlopeStart4);
}

void InternalEEPROMClass::PWMSlopeStart4_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeStart4, value);
}

uint8_t InternalEEPROMClass::PWMSlopeEnd4_read()
{
    return read(Mem_B_PWMSlopeEnd4);
}

void InternalEEPROMClass::PWMSlopeEnd4_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeEnd4, value);
}

uint8_t InternalEEPROMClass::PWMSlopeDuration4_read()
{
    return read(Mem_B_PWMSlopeDuration4);
}

void InternalEEPROMClass::PWMSlopeDuration4_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeDuration4, value);
}

uint8_t InternalEEPROMClass::PWMSlopeStart5_read()
{
    return read(Mem_B_PWMSlopeStart5);
}

void InternalEEPROMClass::PWMSlopeStart5_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeStart5, value);
}

uint8_t InternalEEPROMClass::PWMSlopeEnd5_read()
{
    return read(Mem_B_PWMSlopeEnd5);
}

void InternalEEPROMClass::PWMSlopeEnd5_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeEnd5, value);
}

uint8_t InternalEEPROMClass::PWMSlopeDuration5_read()
{
    return read(Mem_B_PWMSlopeDuration5);
}

void InternalEEPROMClass::PWMSlopeDuration5_write(const uint8_t value)
{
    write(Mem_B_PWMSlopeDuration5, value);
}

// Int Functions
int InternalEEPROMClass::WM1Timer_read()
{
    return read_int(Mem_I_WM1Timer);
}

void InternalEEPROMClass::WM1Timer_write(const int value)
{
    write_int(Mem_I_WM1Timer, value);
}

int InternalEEPROMClass::WM2Timer_read()
{
    return read_int(Mem_I_WM2Timer);
}

void InternalEEPROMClass::WM2Timer_write(const int value)
{
    write_int(Mem_I_WM2Timer, value);
}

int InternalEEPROMClass::FeedingTimer_read()
{
    return read_int(Mem_I_FeedingTimer);
}

void InternalEEPROMClass::FeedingTimer_write(int value)
{
    write_int(Mem_I_FeedingTimer, value);
}

int InternalEEPROMClass::LCDTimer_read()
{
    return read_int(Mem_I_LCDTimer);
}

void InternalEEPROMClass::LCDTimer_write(const int value)
{
    write_int(Mem_I_LCDTimer, value);
}

int InternalEEPROMClass::OverheatTemp_read()
{
    return read_int(Mem_I_OverheatTemp);
}

void InternalEEPROMClass::OverheatTemp_write(const int value)
{
    write_int(Mem_I_OverheatTemp, value);
}

int InternalEEPROMClass::HeaterTempOn_read()
{
    return read_int(Mem_I_HeaterTempOn);
}

void InternalEEPROMClass::HeaterTempOn_write(const int value)
{
    write_int(Mem_I_HeaterTempOn, value);
}

int InternalEEPROMClass::HeaterTempOff_read()
{
    return read_int(Mem_I_HeaterTempOff);
}

void InternalEEPROMClass::HeaterTempOff_write(int value)
{
    write_int(Mem_I_HeaterTempOff, value);
}

int InternalEEPROMClass::ChillerTempOn_read()
{
    return read_int(Mem_I_ChillerTempOn);
}

void InternalEEPROMClass::ChillerTempOn_write(const int value)
{
    write_int(Mem_I_ChillerTempOn, value);
}

int InternalEEPROMClass::ChillerTempOff_read()
{
    return read_int(Mem_I_ChillerTempOff);
}

void InternalEEPROMClass::ChillerTempOff_write(int value)
{
    write_int(Mem_I_ChillerTempOff, value);
}

int InternalEEPROMClass::PHMax_read()
{
    return read_int(Mem_I_PHMax);
}

void InternalEEPROMClass::PHMax_write(const int value)
{
    write_int(Mem_I_PHMax, value);
}

int InternalEEPROMClass::PHMin_read()
{
    return read_int(Mem_I_PHMin);
}

void InternalEEPROMClass::PHMin_write(const int value)
{
    write_int(Mem_I_PHMin, value);
}

int InternalEEPROMClass::DP1RepeatInterval_read()
{
	return read_int(Mem_I_DP1RepeatInterval);
}

void InternalEEPROMClass::DP1RepeatInterval_write(const int value)
{
	write_int(Mem_I_DP1RepeatInterval, value);
}

int InternalEEPROMClass::DP2RepeatInterval_read()
{
	return read_int(Mem_I_DP2RepeatInterval);
}

void InternalEEPROMClass::DP2RepeatInterval_write(const int value)
{
	write_int(Mem_I_DP2RepeatInterval, value);
}

int InternalEEPROMClass::SalMax_read()
{
    return read_int(Mem_I_SalMax);
}

void InternalEEPROMClass::SalMax_write(const int value)
{
    write_int(Mem_I_SalMax, value);
}

int InternalEEPROMClass::ATOExtendedTimeout_read()
{
    return read_int(Mem_I_ATOExtendedTimeout);
}

void InternalEEPROMClass::ATOExtendedTimeout_write(const int value)
{
    write_int(Mem_I_ATOExtendedTimeout, value);
}

int InternalEEPROMClass::ATOHighExtendedTimeout_read()
{
    return read_int(Mem_I_ATOHighExtendedTimeout);
}

void InternalEEPROMClass::ATOHighExtendedTimeout_write(const int value)
{
    write_int(Mem_I_ATOHighExtendedTimeout, value);
}

unsigned long InternalEEPROMClass::IMCheck_read()
{
    return read_dword(IMPointer);
}

void InternalEEPROMClass::IMCheck_write(const unsigned long value)
{
	write_dword(IMPointer, value);
}

// Private functions
uint8_t InternalEEPROMClass::read(uint8_t address)
{
    return eeprom_read_byte((unsigned char *) address);
}

void InternalEEPROMClass::write(uint8_t address, const uint8_t value)
{
    eeprom_write_byte((unsigned char *) address, value);
}

int InternalEEPROMClass::read_int(int address)
{
    return eeprom_read_word((const uint16_t *) address);
}

void InternalEEPROMClass::write_int(int address, const int value)
{
    eeprom_write_word((uint16_t *) address, (uint16_t) value);
}

uint32_t InternalEEPROMClass::read_dword(int address)
{
	return eeprom_read_dword((const uint32_t *)address);
}

void InternalEEPROMClass::write_dword(int address, const uint32_t value)
{
	eeprom_write_dword((uint32_t *) address, (uint32_t) value);
}

InternalEEPROMClass InternalMemory;
