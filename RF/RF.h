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

#ifndef __RF_H__
#define __RF_H__

#include <Globals.h>

class RFClass
{
public:
	RFClass();
	boolean UseMemory;
	byte Mode;
	byte Speed;
	byte Duration;
	byte RadionChannels[6];
	void SetMode(byte mode, byte speed, byte duration);
	byte RFCheck();
	inline byte GetChannel(byte channel) {return RadionChannels[channel];}
	void RadionWrite();
private:
};

#endif  // __RF_H__
