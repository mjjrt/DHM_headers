# Digital Heart Monitor Extension Board

This repo contains header files for use with the breakout shield used in the 'Medical Technology - Selected Digital Topics' lab course.

## About this 
This repo contains four important things:
```
buttonArray.h
display.h
button/
examples/
```
About the first two, see the following paragraph.
`button` contains a small library of two files, which is in essence an implementation of the Arduino Button library, but with an object oriented approach. The `Button` class can be implemented in an array, which makes initialization of more than a few buttons _really_ easy.

## Usage 
The header files, if placed in the same directory as the Arduino `.ino` file, can be included with:
```
#include "buttonArray.h"
#include "display.h"
```

They are written to specifically work with the following hardware:
- 3.5" UNO 320x480 TFT Display Module (Driver: ILI0486);
- 12 Buttons, wired normally high.

## Credit
These header files were written during my work as an assistant for the 'Medical Technology - Selected Digital Topics' lab course for the Biomedical Engineering Masters Program in the 2022 summer term at Lübeck University of Applied Sciences.

## LICENSE
The files are published under the following MIT License:

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


