/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define ENC_A 6 //these need to be digital input pins
#define ENC_B 7
bool started = false;
int timer = 0;
int start_time = 0;

#include "pitches.h"
int melody[] = {
  NOTE_G3 
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  1
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(0, INPUT);
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
 
  lcd.print("Timer value:");
  
}

void loop() {
  
  if (digitalRead(0) == LOW){
    started = true;
    start_time = millis()/1000;
  }
  if(started) {
    int current = millis()/1000 - start_time;
    lcd.clear();
    lcd.print("Time Left:");
    lcd.setCursor(0, 1);
    int remaining = timer - current;
    lcd.print(remaining);

    if(remaining <= 0){
      

      for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
  
      started = false;
    }
    
  } else {
     lcd.setCursor(0, 1);
     static unsigned int counter4x = 0;      //the SparkFun encoders jump by 4 states from detent to detent
     static unsigned int counter = 0;
     static unsigned int prevCounter = 0;
     int tmpdata;
     tmpdata = read_encoder();
     if( tmpdata) {
       counter4x += tmpdata;
       counter = counter4x/4;
       if (prevCounter != counter){
         lcd.clear();

         lcd.print("Timer value:");
         lcd.setCursor(0, 1);
         lcd.print(counter);
         timer = counter;
        }
        prevCounter = counter;
     }
  
  }
  
}

int read_encoder()
{
  static int enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0  };
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
 
 
}
