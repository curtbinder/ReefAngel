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

#include "RA_PWM.h"
#include <Globals.h>
#include <Wire.h>

RA_PWMClass::RA_PWMClass()
{
    // initialize variables
    ActinicPWMValue = 0;
    DaylightPWMValue = 0;
}

void RA_PWMClass::SetActinic(byte value)
{
    analogWrite(actinicPWMPin, value*2.55);
    ActinicPWMValue = value;

}

void RA_PWMClass::SetDaylight(byte value)
{
    analogWrite(daylightPWMPin, value*2.55);
    DaylightPWMValue = value;
}

#ifdef PWMEXPANSION
void RA_PWMClass::Expansion(byte cmd, byte data)
{
	Wire.beginTransmission(8);  // transmit to device #8, consider having this user defined possibly
	Wire.send('$');				// send the $$$
	Wire.send('$');
	Wire.send('$');
	Wire.send(cmd);				// send the command
	Wire.send(data);			// send the data
	Wire.endTransmission();		// stop transmitting
	if (cmd<PWM_EXPANSION_CHANNELS) ExpansionChannel[cmd]=data;
}

void RA_PWMClass::ExpansionPercentage(byte cmd, byte data)
{
	Wire.beginTransmission(8);  // transmit to device #8, consider having this user defined possibly
	Wire.send('$');				// send the $$$
	Wire.send('$');
	Wire.send('$');
	Wire.send(cmd);				// send the command
	Wire.send(int(2.55*data));	// send the data
	Wire.endTransmission();		// stop transmitting
	if (cmd<PWM_EXPANSION_CHANNELS) ExpansionChannel[cmd]=data;
}

void RA_PWMClass::ExpansionSetPercent(byte p)
{
	// loop through all 6 channels and send the value
	for ( byte a = 0; a < PWM_EXPANSION_CHANNELS; a++ )
	{
		Expansion(a, int(2.55*p));
	}
}

void RA_PWMClass::ExpansionWrite()
{
	for ( byte a = 0; a < PWM_EXPANSION_CHANNELS; a++ )
	{
		ExpansionPercentage(a,ExpansionChannel[a]);
	}	
}

#endif  // PWMEXPANSION
