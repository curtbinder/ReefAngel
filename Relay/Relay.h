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

#ifndef __RELAY_H__
#define __RELAY_H__

#include <Globals.h>

class RelayClass
{
public:
	RelayClass();
	void On(byte ID);
	void DelayedOn(byte ID, byte MinuteDelay);
	void Off(byte ID);
	void AllOn();
	void AllOff();
	void Toggle(byte ID);
	void Set(byte ID, boolean Status);
	void Write();
	inline boolean Status(byte Port)  { return bitRead((RelayData & RelayMaskOff) | RelayMaskOn,Port-1); }

	byte RelayData;
	byte RelayMaskOn;
	byte RelayMaskOff;
#ifdef RelayExp
	byte RelayDataE[MAX_RELAY_EXPANSION_MODULES];
	byte RelayMaskOnE[MAX_RELAY_EXPANSION_MODULES];
	byte RelayMaskOffE[MAX_RELAY_EXPANSION_MODULES];
#endif  // RelayExp
};

#endif  // __RELAY_H__
