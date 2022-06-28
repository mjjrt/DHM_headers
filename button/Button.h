#pragma once

// #include <Arduino.h>

class Button{
    
private:
    int _pin;
    bool _state;
    bool _has_changed;
    unsigned long _ignore_until;
    uint32_t _delay;

public:
    Button(){
      _delay = 100;
    };

public:
    void setup(int pin);
    bool read();
    bool has_changed();
    bool pressed();

};