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

#include "RF.h"
#include <Globals.h>
#include <Wire.h>

RFClass::RFClass()
{
	UseMemory=true;
}

void RFClass::SetMode(byte mode, byte speed, byte duration)
{
    Wire.beginTransmission(I2CRF); // transmit to device #16
    Wire.write('$');              // sends $
    Wire.write('$');              // sends $
    Wire.write('$');              // sends $
    Wire.write(mode);              // sends mode
    Wire.write(speed);              // sends speed
    Wire.write(duration);              // sends duration
    Wire.endTransmission();    // stop transmitting
    if (mode<Slave_Start)
    {
    	Mode=mode;
    	Speed=speed;
    	Duration=duration;
    }
}

byte RFClass::RFCheck()
{
    Wire.requestFrom(I2CRF,1);
    if (Wire.available())
    {
        return Wire.read();
    }
}

void RFClass::RadionWrite()
{
	for (byte a=0;a<RF_CHANNELS;a++)
	{
		SetMode(Radion, RadionChannels[a]*2, a);
	}
	SetMode(Radion,0,Radion_Ready);
}

