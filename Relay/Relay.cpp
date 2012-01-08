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

#include "Relay.h"
#include <Globals.h>
#include <Wire.h>

uint32_t LastStart;
byte DelayedOnPorts;
#ifdef RelayExp
byte DelayedOnPortsE[MAX_RELAY_EXPANSION_MODULES];
#endif  // RelayExp

RelayClass::RelayClass()
{
	RelayData = 0;
	RelayMaskOn = 0;
	RelayMaskOff = 0xff;
#ifdef RelayExp
	for ( byte EID = 0; EID < MAX_RELAY_EXPANSION_MODULES; EID++ )
	{
		RelayDataE[EID] = 0;
		RelayMaskOnE[EID] = 0;
		RelayMaskOffE[EID] = 0xff;
	}
#endif  // RelayExp
}

void RelayClass::On(byte ID)
{
    if ( ID < 9 ) bitSet(RelayData, ID-1);
#ifdef RelayExp
	if ( (ID > 10) && (ID < 89) )
	{
		byte EID = byte(ID/10);
		bitSet(RelayDataE[EID-1],(ID%10)-1);
	}
#endif  // RelayExp
}

void RelayClass::DelayedOn(byte ID, byte MinuteDelay)
{
	/*
	We need to see if the MinuteDelay since LastStart has elapsed before we can turn on our port

	Set the DelayedOnPorts flag indicating that it's a delayed on port
	*/
    if ( ID < 9 ) bitSet(DelayedOnPorts, ID-1);
#ifdef RelayExp
	if ( (ID > 10) && (ID < 89) )
	{
		byte EID = byte(ID/10);
		bitSet(DelayedOnPortsE[EID-1],(ID%10)-1);
	}
#endif  // RelayExp

	uint16_t x = MinuteDelay;
	x *= SECS_PER_MIN;
	if ( now()-LastStart > x )
	{
		On(ID);
	}
}

void RelayClass::Off(byte ID)
{
    if ( ID < 9 ) bitClear(RelayData, ID-1);
#ifdef RelayExp
	if ( (ID > 10) && (ID < 89) )
	{
		byte EID = byte(ID/10);
		bitClear(RelayDataE[EID-1],(ID%10)-1);
	}
#endif  // RelayExp
}

void RelayClass::AllOn()
{
	RelayData = 0xff;
#ifdef RelayExp
	for ( byte EID = 0; EID < MAX_RELAY_EXPANSION_MODULES; EID++ )
	{
		RelayDataE[EID] = 0xff;
	}
#endif  // RelayExp
}

void RelayClass::AllOff()
{
	RelayData = 0;
#ifdef RelayExp
	for ( byte EID = 0; EID < MAX_RELAY_EXPANSION_MODULES; EID++ )
	{
		RelayDataE[EID] = 0;
	}
#endif  // RelayExp
}

void RelayClass::Toggle(byte ID)
{
	if ( ID < 9 ) RelayData ^= 1 << (ID-1);
#ifdef RelayExp
	if ( (ID > 10) && (ID < 89) )
	{
		byte EID = byte(ID/10);
		RelayDataE[EID-1] ^= 1 << ((ID%10)-1);
	}
#endif  // RelayExp
}

void RelayClass::Set(byte ID, boolean Status)
{
	if (Status) On(ID); else Off(ID);
}


void RelayClass::Write()
{
    byte TempRelay = RelayData;
    TempRelay &= RelayMaskOff;
    TempRelay |= RelayMaskOn;

    Wire.beginTransmission(I2CExpander1);
    Wire.write(~TempRelay);   // MSB
    Wire.endTransmission();
#ifdef RelayExp
	for ( byte EID = 0; EID < MAX_RELAY_EXPANSION_MODULES; EID++ )
	{
		TempRelay = RelayDataE[EID];
		TempRelay &= RelayMaskOffE[EID];
		TempRelay |= RelayMaskOnE[EID];
		Wire.beginTransmission(I2CExpModule+EID);
		Wire.write(~TempRelay);  // MSB
		Wire.endTransmission();
	}
#endif  // RelayExp
}
