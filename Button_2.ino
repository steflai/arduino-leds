#include "FastLED.h"
#define num_leds_per_strip 5
CRGB leds[num_leds_per_strip];

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin1 =  13;      // the number of the LED pin
//const int ledPin2 = 12;
//const int ledPin3 = 11; 


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int hits = 0;
int prevButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  // initialize the LED pins as an output:
  //pinMode(ledPin1, OUTPUT);
  //pinMode(ledPin2, OUTPUT);
  //pinMode(ledPin3, OUTPUT);
  
  FastLED.addLeds<NEOPIXEL, 4>(leds, NUM_LEDS_PER_STRIP);   //define which pin to control led strip
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  
      // check the status of the switch
  buttonState = digitalRead(buttonPin);

  // compare the switchState to its previous state
  if (buttonState != prevButtonState) {
    if (buttonState == LOW) {
     
      hits = hits + 1;

      if (hits > 3) {
        hits = 0;
      }
     
    }
  }
  Serial.println(hits);
  
  // save the current switch state as the last state 
  prevButtonState = buttonState;
    
  if (hits == 0) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
  if (hits == 1) {
    digitalWrite(ledPin1, HIGH);
  }
    if (hits == 2) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  }
    if (hits == 3) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    }
  delay(10);
}
