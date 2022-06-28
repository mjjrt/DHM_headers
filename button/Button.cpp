#include "Button.h"

#include <Arduino.h>

#define PRESSED 0

void Button::setup(int pin){
    _pin = pin;
    
    pinMode(_pin, INPUT_PULLUP);
}

bool Button::read(){
    if (_ignore_until > millis())
	{
		// ignore any changes during this period
	}
	
	// pin has changed 
	else if (digitalRead(_pin) != _state)
	{
		_ignore_until = millis() + _delay;
		_state = !_state;
		_has_changed = true;
	}
	
	return _state;
}

bool Button::has_changed()
{
	if (_has_changed)
	{
		_has_changed = false;
		return true;
	}
	return false;
}

// has the button gone from off -> on
bool Button::pressed()
{
	return (read() == PRESSED && has_changed());
}
