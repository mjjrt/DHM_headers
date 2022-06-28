// Arduino Due Analog PWM Test
#include "Button.h"

const int PinArr[12] = {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44};
Button arr[12];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i<12; i++)
  {
    arr[i].setup(PinArr[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 12; i++)
  {
    if (arr[i].pressed())
    {
      Serial.println(i);
    }
  }
}
