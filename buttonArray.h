// Team Urban, 28Jun2022 WK
// 
// A header file to make life easier with the button array, which consists of discrete buttons.
// This library treats these buttons as an Array.

#include <Button.h> // Uses the popular Arduino Button Library

#define NUM_BUTTONS 12
const int buttonPins[] = {34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 52, 53}; // Button Pins 

const int ledPin1 = 44;      // the numbers of the LED pins
const int ledPin2 = 45;

// Create button objects
Button button1( buttonPins[0] );
Button button2( buttonPins[1] );
Button button3( buttonPins[2] );
Button button4( buttonPins[3] );
Button button5( buttonPins[4] );
Button button6( buttonPins[5] );
Button button7( buttonPins[6] );
Button button8( buttonPins[7] );
Button button9( buttonPins[8] );
Button button0( buttonPins[9] );
Button buttonstar( buttonPins[10] );
Button buttonhash( buttonPins[11] );


void ButtonSetup()
{
  // sets up the buttons
  button1.begin();
  button2.begin();
  button3.begin();
  button4.begin();
  button5.begin();
  button6.begin();
  button7.begin();
  button8.begin();
  button9.begin();
  button0.begin();
  buttonstar.begin();
  buttonhash.begin();
}

int CheckButtonStates()
{ 
  // Checks buttons sequentially and returns their index. 
  // Can be run in a loop; as the <Button.h> library implements debouncing.
  if (button1.pressed())
    return 0;
  else if (button2.pressed())
    return 1;
  else if (button3.pressed())
    return 2; 
  else if (button4.pressed())
    return 3;
  else if (button5.pressed())
    return 4;
  else if (button6.pressed())
    return 5;
  else if (button7.pressed())
    return 6;
  else if (button8.pressed())
    return 7;
  else if (button9.pressed())
    return 8;
  else if (button0.pressed())
    return 9;
  else if (buttonstar.pressed())
    return 10;
  else if (buttonhash.pressed())
    return 11;

  else return -1; // Default: Be careful when using this library to index into an array of types. 
                  // Index "-1" WILL produce a segmentation fault.
}