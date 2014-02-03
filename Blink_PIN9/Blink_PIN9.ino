/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13; //board led (pin 13)

int alt_LED = 9; //wired led (pin 9 + gnd)

// the setup routine runs once when you press reset:
void setup() 
{
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  
  // set up pin 9 for output
  pinMode(alt_LED, OUTPUT);
}  
  
  // the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(250);               // wait for a second

  // send power out of pin 9 at high
  digitalWrite(alt_LED, HIGH);
  // wait for 500ms
  delay(500);
  // send power out of pin 9 at low
  digitalWrite(alt_LED, LOW);
  // wait for 250ms
  delay(250);
  
}
