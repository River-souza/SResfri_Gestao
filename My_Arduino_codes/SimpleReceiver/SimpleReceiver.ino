/*
   SimpleReceiver.cpp

   Demonstrates receiving NEC IR codes with IRrecv

    Copyright (C) 2020-2021  Armin Joachimsmeyer
    armin.joachimsmeyer@gmail.com

    This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.

    MIT License
*/

/*
   Specify which protocol(s) should be used for decoding.
   If no protocol is defined, all protocols are active.
*/
//#define DECODE_DENON
//#define DECODE_SHARP        // the same as DECODE_DENON
//#define DECODE_JVC
//#define DECODE_KASEIKYO
//#define DECODE_PANASONIC    // the same as DECODE_KASEIKYO
//#define DECODE_LG
//#define DECODE_NEC
//#define DECODE_SAMSUNG
//#define DECODE_SONY
//#define DECODE_RC5
//#define DECODE_RC6

//#define DECODE_BOSEWAVE
//#define DECODE_LEGO_PF
//#define DECODE_MAGIQUEST
//#define DECODE_WHYNTER

//#define DECODE_HASH         // special decoder for all protocols

#include <Arduino.h>

/*
   Define macros for input and output pin etc.
*/
#include "PinDefinitionsAndMore.h"

#include <IRremote.h>

void setup() {
  Serial.begin(115200);
  // Just to know which program is running on my Arduino
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

  /*
     Start the receiver, enable feedback LED and take LED feedback pin from the internal boards definition
  */
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);

  Serial.print(F("Ready to receive IR signals at pin "));
  Serial.println(IR_RECEIVE_PIN);
}

void loop() {
  /*
     Check if received data is available and if yes, try to decode it.
     Decoded result is in the IrReceiver.decodedIRData structure.

     E.g. command is in IrReceiver.decodedIRData.command
     address is in command is in IrReceiver.decodedIRData.address
     and up to 32 bit raw data in IrReceiver.decodedIRData.decodedRawData
  */
  if (IrReceiver.decode()) {

    // Print a short summary of received data
    IrReceiver.printIRResultShort(&Serial);
    Serial.println();
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      // We have an unknown protocol here, print more info
      //IrReceiver.printIRResultRawFormatted(&Serial, true);

      Serial.println(IrReceiver.decodedIRData.decodedRawData);
    }
    if (IrReceiver.decodedIRData.decodedRawData == 455417325) {
      Serial.println("ligar/desligar");
    } else if (IrReceiver.decodedIRData.decodedRawData == 2567064699) {
      Serial.println("oscilar");
    } else if (IrReceiver.decodedIRData.decodedRawData == 2608548755) {
      Serial.println("temp. 18");
    } else if (IrReceiver.decodedIRData.decodedRawData == 3603776341) {
      Serial.println("temp. 19");
    } else if (IrReceiver.decodedIRData.decodedRawData == 114091001) {
      Serial.println("temp. 20");
    } else if (IrReceiver.decodedIRData.decodedRawData == 3067323969) {
      Serial.println("temp. 21");
    } else if (IrReceiver.decodedIRData.decodedRawData == 1379560245) {
      Serial.println("temp. 22");
    } else if (IrReceiver.decodedIRData.decodedRawData == 2603847627) {
      Serial.println("temp. 23");
    } else if (IrReceiver.decodedIRData.decodedRawData == 3294599685) {
      Serial.println("temp. 24");
    } else if (IrReceiver.decodedIRData.decodedRawData == 1952865357) {
      Serial.println("temp 25");
    } else if (IrReceiver.decodedIRData.decodedRawData == 1650297241) {
      Serial.println("temp 26");
    } else if (IrReceiver.decodedIRData.decodedRawData == 3741359527) {
      Serial.println("temp ");
    } else if (IrReceiver.decodedIRData.decodedRawData == 251674187) {
      Serial.println("temp 28");
    } else if (IrReceiver.decodedIRData.decodedRawData == 3204907155) {
      Serial.println("temp 29");
    } else if (IrReceiver.decodedIRData.decodedRawData == 3116709729) {
      Serial.println("temp 30");
    } else if (IrReceiver.decodedIRData.decodedRawData == 46029815) {
      Serial.println("temp 31");
    } else if (IrReceiver.decodedIRData.decodedRawData == 736781873) {
      Serial.println("temp 32");
    }

    Serial.println();

    /*
       !!!Important!!! Enable receiving of the next value,
       since receiving has stopped after the end of the current received data packet.
    */
    IrReceiver.resume(); // Enable receiving of the next value

    /*
       Finally, check the received data and perform actions according to the received command
    */

  }
}
