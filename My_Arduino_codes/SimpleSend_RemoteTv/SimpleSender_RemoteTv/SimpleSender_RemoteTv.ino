/*
 * SimpleSender.cpp
 *
 *  Demonstrates sending IR codes in standard format with address and command
 *  An extended example for sending can be found as SendDemo.
 *
 *  Copyright (C) 2020-2021  Armin Joachimsmeyer
 *  armin.joachimsmeyer@gmail.com
 *
 *  This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.
 *
 *  MIT License
 */
#include <Arduino.h>

#define IR_SEND_PIN         13

//#define SEND_PWM_BY_TIMER
//#define USE_NO_SEND_PWM

#include <IRremote.h>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    /*
     * The IR library setup. That's all!
     */
    IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}

/*
 * Set up the data to be sent.
 * For most protocols, the data is build up with a constant 8 (or 16 byte) address
 * and a variable 8 bit command.
 * There are exceptions like Sony and Denon, which have 5 bit address.
 */

uint16_t sAddress1 = 0x40;
uint8_t sCommand1 = 0x1B;//mudar canal
uint8_t sRepeats1 = 1;

uint16_t sAddress2 = 0x40;
uint8_t sCommand2 = 0x12;//desligar
uint8_t sRepeats2 = 4;

void loop() {


    delay(10000);
  
    /*
     * Print current send values
     */
    Serial.println();
    Serial.print(F("Send now: address=0x"));
    Serial.print(sAddress1, HEX);
    Serial.print(F(" command=0x"));
    Serial.print(sCommand1, HEX);
    Serial.print(F(" repeats="));
    Serial.print(sRepeats1);
    Serial.println();

    //Serial.println(F("Send NEC with 16 bit address"));

    // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(sAddress1, sCommand1, sRepeats1);
	
	  delay(3000);

 /*
     * Print current send values
     */
    Serial.println();
    Serial.print(F("Send now: address=0x"));
    Serial.print(sAddress1, HEX);
    Serial.print(F(" command=0x"));
    Serial.print(sCommand1, HEX);
    Serial.print(F(" repeats="));
    Serial.print(sRepeats1);
    Serial.println();

    //Serial.println(F("Send NEC with 16 bit address"));

    // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(sAddress1, sCommand1, sRepeats1);
  
    delay(3000);

     /*
     * Print current send values
     */
    Serial.println();
    Serial.print(F("Send now: address=0x"));
    Serial.print(sAddress1, HEX);
    Serial.print(F(" command=0x"));
    Serial.print(sCommand1, HEX);
    Serial.print(F(" repeats="));
    Serial.print(sRepeats1);
    Serial.println();

    //Serial.println(F("Send NEC with 16 bit address"));

    // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(sAddress1, sCommand1, sRepeats1);
  
    delay(3000);
    
    /*
     * Print current send values
     */
    Serial.println();
    Serial.print(F("Send now: address=0x"));
    Serial.print(sAddress1, HEX);
    Serial.print(F(" command=0x"));
    Serial.print(sCommand1, HEX);
    Serial.print(F(" repeats="));
    Serial.print(sRepeats1);
    Serial.println();

    //Serial.println(F("Send NEC with 16 bit address"));

    // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(sAddress1, sCommand1, sRepeats1);
  
    delay(5000);
	
	 /*
     * Print current send values
     */
    Serial.println();
    Serial.print(F("Send now: address=0x"));
    Serial.print(sAddress2, HEX);
    Serial.print(F(" command=0x"));
    Serial.print(sCommand2, HEX);
    Serial.print(F(" repeats="));
    Serial.print(sRepeats2);
    Serial.println();

   //// Serial.println(F("Send NEC with 16 bit address"));

    // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
   IrSender.sendNEC(sAddress2, sCommand2, sRepeats2);

    /*
     * If you cannot avoid to send a raw value directly like e.g. 0xCB340102 you must use sendNECRaw()
     */
   //Serial.println(F("Send NECRaw 0xED12BF40"));
  // IrSender.sendNECRaw(0xED12BF40, sRepeats2);
    /*
     * Increment send values
     * Also increment address just for demonstration, which normally makes no sense
     */
    //sAddress += 0x0101;
    //sCommand += 0x11;
    //sRepeats++;
    // clip repeats at 4
    //if (sRepeats > 4) {
    //    sRepeats = 4;
    //}

    delay(5000);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
}
