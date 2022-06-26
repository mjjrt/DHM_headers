#include "buttonArray.h"
#include "display.h"

int UserButton = 0;

char Keys[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '*', '#'};

void setup() {
  // initialize the LED pins as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(A8, INPUT);

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);

  // initialize the pushbutton pins as an input:
  ButtonSetup();
  
  // initialize the display
  DisplaySetup();
  drawLineBoxonScreen();
  drawNumbertoScreen( String(180) );
  delay(1000);
  drawNumbertoScreen( String(54) );
  delay(1000);
  drawNumbertoScreen( "LO" );
  delay(1000); 
  drawNumbertoScreen( "HI" );
  delay(1000);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);

}

void loop() {
  
  // read the state of the pushbutton array:
  UserButton = CheckButtonStates();

  // drawNumbertoScreen( Keys[UserButton] );


  if (UserButton != -1){
    drawNumbertoScreen( Keys[UserButton] );
  }
}
