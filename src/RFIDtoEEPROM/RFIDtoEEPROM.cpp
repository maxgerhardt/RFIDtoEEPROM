// MIT License

// Copyright (c) 2022 Gauthier Dandele

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#if !defined(ARDUINO_ARCH_RP2040)

#include <RFIDtoEEPROM.h>

/*!
    @brief Constructor for RFIDtoEEPROM library.
    @param byteNumber the number of bytes contained in the RFID Card.
*/
RFIDtoEEPROM::RFIDtoEEPROM(uint8_t byteNumber) : Card(byteNumber)
{
  _local = true;
}

#if defined(ESP32) || defined(ESP8266)

#include <EEPROM.h>

/*!
    @brief Set the EEPROM emulation size.
    @param eepromSize The EEPROM size in Byte!!!
*/
void RFIDtoEEPROM::begin(uint32_t eepromSize)
{
  EEPROM.begin(eepromSize);
  _maxCards = min(((EEPROM.length() - 1) / _byteNumber), 255);
}

#endif // ESP32 || ESP8266

#endif // !ARDUINO_ARCH_RP2040
