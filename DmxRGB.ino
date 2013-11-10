/* 
 * Will Keyser
 * DMX512 to RGB interface
 * 2013
 */

// include the DMXSerial Library
#include <DMXSerial.h>

// define DMX Channels for Red, Green, and Blue
#define RedChannel    1;
#define GreenChannel  2;
#define BlueChannel   3;

// define constant pins for the LED driver MOSFETs
const int RedPin =    9;  // PWM output pin for Red Light.
const int GreenPin =  6;  // PWM output pin for Green Light.
const int BluePin =   5;  // PWM output pin for Blue Light.

// setup routine
void setup () {
  DMXSerial.init(DMXReceiver);
  
  // set some default values for each channel
  DMXSerial.write(RedChannel, 80);
  DMXSerial.write(GreenChannel, 0);
  DMXSerial.write(BlueChannel, 0);
  
  // enable pwm outputs
  pinMode(RedPin,   OUTPUT); // sets the digital pin as output
  pinMode(GreenPin, OUTPUT); // ^^^^
  pinMode(BluePin,  OUTPUT); // ^^^^
}

// main loop
void loop() {
  
  // read DMX values and then set pwm duty cycles (0-255)
  analogWrite(RedPin,   DMXSerial.read(RedChannel));
  analogWrite(GreenPin, DMXSerial.read(GreenChannel));
  analogWrite(BluePin,  DMXSerial.read(BlueChannel));
}

// WOOT!
