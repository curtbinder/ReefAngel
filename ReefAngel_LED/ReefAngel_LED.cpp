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

#include "ReefAngel_LED.h"
#include <ReefAngel_Globals.h>

ReefAngel_LEDClass::ReefAngel_LEDClass()
{
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

//void ReefAngel_LEDClass::On()
//{
//	digitalWrite(ledPin, HIGH);
//}
//
//void ReefAngel_LEDClass::Off()
//{
//	digitalWrite(ledPin, LOW);
//}