#include "FastLED.h"
#define num_leds_per_strip 5
CRGB leds[num_leds_per_strip];

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int hits = -1;
int prevButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, 13>(leds, num_leds_per_strip);   //define which pin to control led strip
  pinMode(buttonPin, INPUT_PULLUP);   // initialize the pushbutton pin as an input
}

void loop() {
  
  // check the status of the switch
  buttonState = digitalRead(buttonPin);

  // compare the switchState to its previous state
  if (buttonState != prevButtonState) {
    if (buttonState == LOW) {
     
      hits = hits + 1;

      if (hits > 4) {
        hits = -1;
        for(int i = 0; i < num_leds_per_strip; i++) {
          leds[i] = CRGB::Black;    // reset to off
          FastLED.show();
        }
      }
     
    }
  }
  Serial.println(hits);
  
  // save the current switch state as the last state 
  prevButtonState = buttonState;
    
  leds[hits] = CRGB::HotPink;
  FastLED.show();
  delay(10);
}
