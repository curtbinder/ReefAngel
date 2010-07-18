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

#ifndef __REEFANGEL_JOYSTICK_H__
#define __REEFANGEL_JOYSTICK_H__

#include <WProgram.h>

class ReefAngel_JoystickClass
{

public:
	ReefAngel_JoystickClass();
	void Init();
	bool IsButtonPressed();
	bool IsUp();
	bool IsDown();
	bool IsRight();
	bool IsLeft();

private:
	void JoystickCenter();
	int CalV, CalH;
	unsigned long KeyKeep;
	byte KeyTurbo;
	byte KeyCount;
};

#endif  // __REEFANGEL_JOYSTICK_H__
