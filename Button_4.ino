#include "FastLED.h"
#define num_leds_per_strip 5
CRGB leds1[num_leds_per_strip];
CRGB leds2[num_leds_per_strip];
CRGB leds3[num_leds_per_strip];
CRGB leds4[num_leds_per_strip];
CRGB leds5[num_leds_per_strip];

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;     // define the pushbutton pins
const int buttonPin2 = 3; 
const int buttonPin3 = 4;
const int buttonPin4 = 5; 
const int buttonPin5 = 6;

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int hits1 = -1;
int prevButtonState1 = HIGH;

int buttonState2 = 0;         // variable for reading the pushbutton status
int hits2 = -1;
int prevButtonState2 = HIGH;

int buttonState3 = 0;         // variable for reading the pushbutton status
int hits3 = -1;
int prevButtonState3 = HIGH;

int buttonState4 = 0;         // variable for reading the pushbutton status
int hits4 = -1;
int prevButtonState4 = HIGH;

int buttonState5 = 0;         // variable for reading the pushbutton status
int hits5 = -1;
int prevButtonState5 = HIGH;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, 13>(leds1, num_leds_per_strip);//define which pin to control led strip
  FastLED.addLeds<NEOPIXEL, 12>(leds2, num_leds_per_strip);
  FastLED.addLeds<NEOPIXEL, 11>(leds3, num_leds_per_strip);
  FastLED.addLeds<NEOPIXEL, 10>(leds4, num_leds_per_strip);
  FastLED.addLeds<NEOPIXEL, 9>(leds5, num_leds_per_strip);
  pinMode(buttonPin1, INPUT_PULLUP);   // initialize the pushbutton pin as an input
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
}


void loop() {
  //BUTTON 1
    // check the status of the switch
    buttonState1 = digitalRead(buttonPin1);
  
    // compare the switchState to its previous state
    if (buttonState1 != prevButtonState1) {
      if (buttonState1 == LOW) {
       
        hits1 = hits1 + 1;
  
        if (hits1 > 4) {
          hits1 = -1;
          for(int i = 0; i < num_leds_per_strip; i++) {
            leds1[i] = CRGB::Black;    // reset to off
            FastLED.show();
          }
        }
       
      }
    }
 
    
    // save the current switch state as the last state 
    prevButtonState1 = buttonState1;
      
    leds1[hits1] = CRGB::HotPink;
    FastLED.show();


  //BUTTON 2
    // check the status of the switch
    buttonState2 = digitalRead(buttonPin2);
  
    // compare the switchState to its previous state
    if (buttonState2 != prevButtonState2) {
      if (buttonState2 == LOW) {
       
        hits2 = hits2 + 1;
  
        if (hits2 > 4) {
          hits2 = -1;
          for(int i = 0; i < num_leds_per_strip; i++) {
            leds2[i] = CRGB::Black;    // reset to off
            FastLED.show();
          }
        }
       
      }
    }

    
    // save the current switch state as the last state 
    prevButtonState2 = buttonState2;
      
    leds2[hits2] = CRGB::HotPink;
    FastLED.show();
 

  //BUTTON3
    // check the status of the switch
    buttonState3 = digitalRead(buttonPin3);
  
    // compare the switchState to its previous state
    if (buttonState3 != prevButtonState3) {
      if (buttonState3 == LOW) {
       
        hits3 = hits3 + 1;
  
        if (hits3 > 4) {
          hits3 = -1;
          for(int i = 0; i < num_leds_per_strip; i++) {
            leds3[i] = CRGB::Black;    // reset to off
            FastLED.show();
          }
        }
       
      }
    }

    
    // save the current switch state as the last state 
    prevButtonState3 = buttonState3;
      
    leds3[hits3] = CRGB::HotPink;
    FastLED.show();


    //BUTTON 4
    // check the status of the switch
    buttonState4 = digitalRead(buttonPin4);
  
    // compare the switchState to its previous state
    if (buttonState4 != prevButtonState4) {
      if (buttonState4 == LOW) {
       
        hits4 = hits4 + 1;
  
        if (hits4 > 4) {
          hits4 = -1;
          for(int i = 0; i < num_leds_per_strip; i++) {
            leds4[i] = CRGB::Black;    // reset to off
            FastLED.show();
          }
        }
       
      }
    }

    
    // save the current switch state as the last state 
    prevButtonState4 = buttonState4;
      
    leds4[hits4] = CRGB::HotPink;
    FastLED.show();


    //BUTTON 5
    // check the status of the switch
    buttonState5 = digitalRead(buttonPin5);
  
    // compare the switchState to its previous state
    if (buttonState5 != prevButtonState5) {
      if (buttonState5 == LOW) {
       
        hits5 = hits5 + 1;
  
        if (hits5 > 5) {
          hits5 = -1;
          for(int i = 0; i < num_leds_per_strip; i++) {
            leds5[i] = CRGB::Black;    // reset to off
            FastLED.show();
          }
        }
       
      }
    }

    
    // save the current switch state as the last state 
    prevButtonState5 = buttonState5;
      
    leds5[hits5] = CRGB::Blue;
    FastLED.show();
    delay(10);
}
