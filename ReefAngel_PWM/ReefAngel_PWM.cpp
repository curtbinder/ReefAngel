/*
 * Copyright 2010 Reef Angel / Roberto Imai
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

 /*
  * Updated by:  Curt Binder
  * Updates Released under Apache License, Version 2.0
  */

#include "ReefAngel_PWM.h"
#include <ReefAngel_Globals.h>
#include <Wire.h>

ReefAngel_PWMClass::ReefAngel_PWMClass()
{
    // initialize variables
    ActinicPWMValue = 0;
    DaylightPWMValue = 0;
#ifdef PWMEXPANSION
	for ( byte a = 0; a < PWM_EXPANSION_CHANNELS; a++ )
	{
		ExpansionChannel[a] = 0;
	}
#endif  // PWMEXPANSION
}

void ReefAngel_PWMClass::SetActinic(byte value)
{
    analogWrite(actinicPWMPin, value*2.55);
    ActinicPWMValue = value;

}

void ReefAngel_PWMClass::SetDaylight(byte value)
{
    analogWrite(daylightPWMPin, value*2.55);
    DaylightPWMValue = value;
}

byte ReefAngel_PWMClass::ActinicPWMSlope(byte MinuteOffset)
{
	int onTime=NumMins(InternalMemory.StdLightsOnHour_read(),InternalMemory.StdLightsOnMinute_read())-(MinuteOffset*60);
	int offTime=NumMins(InternalMemory.StdLightsOffHour_read(),InternalMemory.StdLightsOffMinute_read())+(MinuteOffset*60);
	SetActinic(PWMSlope(
			onTime/60,
			onTime%60,
			offTime/60,
			offTime%60,
			InternalMemory.PWMSlopeStartA_read(),
			InternalMemory.PWMSlopeEndA_read(),
			InternalMemory.PWMSlopeDurationA_read(),
			ActinicPWMValue
			));
}

byte ReefAngel_PWMClass::DaylightPWMSlope(byte MinuteOffset)
{
	int onTime=NumMins(InternalMemory.StdLightsOnHour_read(),InternalMemory.StdLightsOnMinute_read())-(MinuteOffset*60);
	int offTime=NumMins(InternalMemory.StdLightsOffHour_read(),InternalMemory.StdLightsOffMinute_read())+(MinuteOffset*60);
	SetDaylight(PWMSlope(
			onTime/60,
			onTime%60,
			offTime/60,
			offTime%60,
			InternalMemory.PWMSlopeStartD_read(),
			InternalMemory.PWMSlopeEndD_read(),
			InternalMemory.PWMSlopeDurationD_read(),
			DaylightPWMValue
			));
}

byte ReefAngel_PWMClass::ActinicPWMSlope()
{
	SetActinic(PWMSlope(
			InternalMemory.StdLightsOnHour_read(),
			InternalMemory.StdLightsOnMinute_read(),
			InternalMemory.StdLightsOffHour_read(),
			InternalMemory.StdLightsOffMinute_read(),
			InternalMemory.PWMSlopeStartA_read(),
			InternalMemory.PWMSlopeEndA_read(),
			InternalMemory.PWMSlopeDurationA_read(),
			ActinicPWMValue
			));
}

byte ReefAngel_PWMClass::DaylightPWMSlope()
{
	SetDaylight(PWMSlope(
			InternalMemory.StdLightsOnHour_read(),
			InternalMemory.StdLightsOnMinute_read(),
			InternalMemory.StdLightsOffHour_read(),
			InternalMemory.StdLightsOffMinute_read(),
			InternalMemory.PWMSlopeStartD_read(),
			InternalMemory.PWMSlopeEndD_read(),
			InternalMemory.PWMSlopeDurationD_read(),
			DaylightPWMValue
			));
}

/*
byte ReefAngel_PWMClass::ActinicPWMParabola(byte MinuteOffset)
{
	int onTime=NumMins(InternalMemory.StdLightsOnHour_read(),InternalMemory.StdLightsOnMinute_read())-(MinuteOffset*60);
	int offTime=NumMins(InternalMemory.StdLightsOffHour_read(),InternalMemory.StdLightsOffMinute_read())+(MinuteOffset*60);
	SetActinic(PWMParabola(
			onTime/60,
			onTime%60,
			offTime/60,
			offTime%60,
			InternalMemory.PWMSlopeStartA_read(),
			InternalMemory.PWMSlopeEndA_read(),
			ActinicPWMValue
			));
}

byte ReefAngel_PWMClass::DaylightPWMParabola(byte MinuteOffset)
{
	int onTime=NumMins(InternalMemory.StdLightsOnHour_read(),InternalMemory.StdLightsOnMinute_read())-(MinuteOffset*60);
	int offTime=NumMins(InternalMemory.StdLightsOffHour_read(),InternalMemory.StdLightsOffMinute_read())+(MinuteOffset*60);
	SetDaylight(PWMParabola(
			onTime/60,
			onTime%60,
			offTime/60,
			offTime%60,
			InternalMemory.PWMSlopeStartD_read(),
			InternalMemory.PWMSlopeEndD_read(),
			DaylightPWMValue
			));
}

byte ReefAngel_PWMClass::ActinicPWMParabola()
{
	SetActinic(PWMParabola(
			InternalMemory.StdLightsOnHour_read(),
			InternalMemory.StdLightsOnMinute_read(),
			InternalMemory.StdLightsOffHour_read(),
			InternalMemory.StdLightsOffMinute_read(),
			InternalMemory.PWMSlopeStartA_read(),
			InternalMemory.PWMSlopeEndA_read(),
			ActinicPWMValue
			));
}

byte ReefAngel_PWMClass::DaylightPWMParabola()
{
	SetDaylight(PWMParabola(
			InternalMemory.StdLightsOnHour_read(),
			InternalMemory.StdLightsOnMinute_read(),
			InternalMemory.StdLightsOffHour_read(),
			InternalMemory.StdLightsOffMinute_read(),
			InternalMemory.PWMSlopeStartD_read(),
			InternalMemory.PWMSlopeEndD_read(),
			DaylightPWMValue
			));
}
*/

#ifdef PWMEXPANSION
voie ReefAngel_PWMClass::SetChannel(byte Channel, byte Value)
{
	if ( Channel < PWM_EXPANSION_CHANNELS) ExpansionChannel[Channel] = Value;
}

void ReefAngel_PWMClass::Expansion(byte cmd, byte data)
{
	Wire.beginTransmission(I2CPWM);  // transmit to device #2, consider having this user defined possibly
	Wire.write('$');				// send the $$$
	Wire.write('$');
	Wire.write('$');
	Wire.write(cmd);				// send the command
	Wire.write(data);			// send the data
	Wire.endTransmission();		// stop transmitting
	if (cmd < PWM_EXPANSION_CHANNELS) ExpansionChannel[cmd]=data;
}

void ReefAngel_PWMClass::ExpansionSetPercent(byte p)
{
	// loop through all 6 channels and send the value
	for ( byte a = 0; a < PWM_EXPANSION_CHANNELS; a++ )
	{
		Expansion(a, int(2.55*p));
	}
}

void ReefAngel_PWMClass::ExpansionWrite()
{
	for ( byte a = 0; a < PWM_EXPANSION_CHANNELS; a++ )
	{
		Expansion(a, int(ExpansionChannel[a]*2.55));
	}
}

#endif  // PWMEXPANSION
