/*

  Melody

  Plays a melody

  circuit:

  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone

*/

#include "pitches.h"

// notes in the melody:
int melody[] = {

  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_E4, 0, NOTE_D4, NOTE_E4,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  8, 8, 8, 4, 4, 4, 8, 10, 8, 2
};

void play() {

  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 10; thisNote++) {

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
}


//BBUUTTOONN STUFF
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 10;     // the number of the pushbutton pin
const int secondButton = 11;
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int secondState = 0;         // variable for reading the second pushbutton status


void setup() {
  // play();

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(secondButton, INPUT);


}

void loop() {

  // no need to repeat the melody.


  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  secondState = digitalRead(secondButton);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && secondState == HIGH) {
    play();
  } else if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else if (secondState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
