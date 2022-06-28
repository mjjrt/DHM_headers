// Team Urban, 28Jun2022 WK 
//
// This is a header file which does all the heavy lifting with the display.
// You can use it as follows:
// 1. Install the Adafruit_GFX and MCUFRIEND_kbv libraries.
// 2. Copy this header file into the same folder with the scetch you want to compile
// 3. Include this header file using 
/*
    #include "display.h"
*/
// 4. Set up the display using 
/*
    void setup()
    {
        DisplaySetup();
    }
*/
//  5. You can draw a number into the rectangle using 
/*
    void loop()
    {
        drawNumbertoScreen(number);
    }
*/

// Include required libraries
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>


// Pins for driving the screen
// CHECK ON HARDWARE BEFORE USING!
#define LCD_CS A3           // Chip Select on Analog 3
#define LCD_WR A1           // LCD Write on Analog 1
#define LCD_CD A2           // Command/Data on Analog 2
#define LCD_RD A0           // LCD Read on Analog 0

#define LCD_RESET A4    //LCD Reset on Analog 4


// Color Definitions to make life easier
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define ORANGE  0xFC40
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0XFFE0
#define WHITE   0xFFFF
#define PINK    0xE20C
#define PURPLE  0xA81F

// Display and Box Characteristics
#define DISPLAY_HEIGHT 320
#define DISPLAY_WIDTH 480
#define KASTEN_LINKS 175
#define KASTEN_OBEN 50


MCUFRIEND_kbv tft; // initialize the tft object


void DisplaySetup()
{
    // Sets up the Display for use, only needs to run once in void setup()

    uint16_t ID = tft.readID();      // read the display driver chip ID
    if (ID == 0xD3D3) ID = 0x9486; 

    tft.begin(ID);      // initializes the tft object to the driver in use
    //tft.setRotation(0);           // PORTRAIT    
    tft.setRotation(1);             // LANDSCAPE
    tft.fillScreen(BLACK);          // black background
    
    tft.drawRoundRect(KASTEN_LINKS, KASTEN_OBEN, 150, 100, 6, WHITE); // Centered white box: drawRoundRect(topleftcornerX, topleftcornerY, width, height, corner radius, border color)
}

void DisplayReset()
{
  // resets the display to default background
  tft.fillScreen(BLACK);
  tft.setCursor(0,0);
}


// Overloaded functions for drawing a number to the screen
#define BOX_INSIDE_OFFSET 20
void drawNumbertoScreen(String number)
{
    // Draws a white box with a number inside 

    //tft.fillScreen(BLACK);          // black background
    tft.fillRect(KASTEN_LINKS+BOX_INSIDE_OFFSET, KASTEN_OBEN+BOX_INSIDE_OFFSET, 150-2*BOX_INSIDE_OFFSET, 100-2*BOX_INSIDE_OFFSET, BLACK);
    
    // tft.drawRoundRect(KASTEN_LINKS, KASTEN_OBEN, 150, 100, 6, WHITE);
  	int16_t x1 = KASTEN_LINKS;
    int16_t y1 = KASTEN_OBEN;
  	uint16_t w, h;
  	
    tft.setTextColor(PINK); // sets the text color
    tft.setTextSize(4);     // sets the text size
    tft.setCursor(DISPLAY_WIDTH/2 - 30, 85); // set the cursor a little left of the middle of the box; makes it easier to make 2 and 3 digit numbers look nice
    // tft.setCursor(DISPLAY_WIDTH/2, 85);
    
    tft.print(number);  // Prints a number
}

void drawNumbertoScreen(char number)
{
    // Draws a white box with a number inside 

    //tft.fillScreen(BLACK);          // black background
    tft.fillRect(KASTEN_LINKS+BOX_INSIDE_OFFSET, KASTEN_OBEN+BOX_INSIDE_OFFSET, 150-2*BOX_INSIDE_OFFSET, 100-2*BOX_INSIDE_OFFSET, BLACK);
    
    // tft.drawRoundRect(KASTEN_LINKS, KASTEN_OBEN, 150, 100, 6, WHITE);
  	int16_t x1 = KASTEN_LINKS;
    int16_t y1 = KASTEN_OBEN;
  	uint16_t w, h;
  	
    tft.setTextColor(PINK); // sets the text color
    tft.setTextSize(4);     // sets the text size
    tft.setCursor(DISPLAY_WIDTH/2 - 30, 85); // set the cursor a little left of the middle of the box; makes it easier to make 2 and 3 digit numbers look nice
    // tft.setCursor(DISPLAY_WIDTH/2, 85);
    
    tft.print(number);  // Prints a number
}

void drawNumbertoScreen(int number)
{
    // Draws a white box with a number inside 

    //tft.fillScreen(BLACK);          // black background
    tft.fillRect(KASTEN_LINKS+BOX_INSIDE_OFFSET, KASTEN_OBEN+BOX_INSIDE_OFFSET, 150-2*BOX_INSIDE_OFFSET, 100-2*BOX_INSIDE_OFFSET, BLACK);
    
    // tft.drawRoundRect(KASTEN_LINKS, KASTEN_OBEN, 150, 100, 6, WHITE);
  	int16_t x1 = KASTEN_LINKS;
    int16_t y1 = KASTEN_OBEN;
  	uint16_t w, h;
  	
    tft.setTextColor(PINK); // sets the text color
    tft.setTextSize(4);     // sets the text size
    tft.setCursor(DISPLAY_WIDTH/2 - 30, 85); // set the cursor a little left of the middle of the box; makes it easier to make 2 and 3 digit numbers look nice
    // tft.setCursor(DISPLAY_WIDTH/2, 85);
    
    tft.print(number);  // Prints a number
}

#define BAR_HEIGHT 50
#define BAR_TOP DISPLAY_HEIGHT - BAR_HEIGHT
void drawBaronScreen(int length, int topleft)
{
  // draws a "loading..." style bar on screen
  for(int i = 0; i < length; i+=5)
  {
    tft.fillRect(0, topleft, i, BAR_HEIGHT, RED);
  }
}


#define LINEBOX_HEIGHT 110
#define LINEBOX_TOP DISPLAY_HEIGHT - LINEBOX_HEIGHT
#define LINE_HEIGHT 2
void drawLineBoxonScreen()
{
  // draws a line boxing in the lower quarter of the screen
  tft.drawFastHLine(0, LINEBOX_TOP, DISPLAY_WIDTH, WHITE);
  tft.drawFastHLine(0, LINEBOX_TOP+1, DISPLAY_WIDTH, WHITE);
  // tft.fillRect(0, LINEBOX_TOP, DISPLAY_WIDTH, LINE_HEIGHT, WHITE);
}


void drawHalfCircle(int x, int y, int radius, uint32_t color)
{
  // draws an upper half circle with a center x y and a radius
  tft.drawCircle(x, y, radius, color);
  tft.fillRect(x - 1.5*radius, y+1, 3*radius, 2*radius, BLACK);
}

#define MIDLINE LINEBOX_TOP + 50
#define TP 20
#define P 10
#define PQ 10
#define Q 10
#define QR 5
#define RS 5
#define S 5
#define ST 10
#define T 20
#define endpoint TP+PQ+Q+QR+RS+S+ST+ST+T

void drawSquigglyLine(int startPoint)
{
  // draws lineart in the style of an EKG plot
  tft.drawLine(startPoint, MIDLINE, TP, MIDLINE, WHITE); // TP 
  
  drawHalfCircle(TP+P/2, MIDLINE, P/2, WHITE); // P

  tft.drawLine(TP+P, MIDLINE, TP+PQ+Q, MIDLINE, WHITE); //PQ

  tft.drawLine(TP+PQ+Q, MIDLINE, TP+PQ+Q+QR, MIDLINE+10, WHITE); // Q

  tft.drawLine(TP+PQ+Q+QR, MIDLINE+10, TP+PQ+Q+QR+RS, MIDLINE-40, WHITE); // R

  tft.drawLine(TP+PQ+Q+QR+RS, MIDLINE-40, TP+PQ+Q+QR+RS+S, MIDLINE+20, WHITE); // S

  tft.drawLine(TP+PQ+Q+QR+RS+S, MIDLINE+20, TP+PQ+Q+QR+RS+S+ST, MIDLINE, WHITE); // ST

  tft.drawLine(TP+PQ+Q+QR+RS+S+ST, MIDLINE, TP+PQ+Q+QR+RS+S+ST+ST, MIDLINE, WHITE); // ST

  drawHalfCircle(TP+PQ+Q+QR+RS+S+ST+ST+T/2, MIDLINE, T/2, WHITE); // T

  tft.drawLine(endpoint, MIDLINE, 240, MIDLINE, WHITE);
}



#define BAR_HEIGHT 53
unsigned int RainbowColors[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
void drawRainbowonScreen()
{
  // divides the screen into 6 equal bars
  for(int row = 0; row < 6; row++)
  {
    tft.fillRect(0, row*BAR_HEIGHT, DISPLAY_WIDTH, BAR_HEIGHT, RainbowColors[row]);
    //for(int i = 0; i < DISPLAY_WIDTH; i++)
    // for(int n = 0; n < BAR_HEIGHT; n++)
    {
      // tft.drawFastHLine(0, row*BAR_HEIGHT+n, DISPLAY_WIDTH, RainbowColors[row]);
      // tft.fillRect(0, row*BAR_HEIGHT, i, BAR_HEIGHT, RainbowColors[row]);
    }
  }
}

#define MAX_HEIGHT 100
int calculateAnalogPosition(double value)
{
  // Calculates the y position of an Analog sample
  double ypos = DISPLAY_HEIGHT - (value/1024 * MAX_HEIGHT);
  return (int)ypos;
}

void drawAnalogStatePixel(int x, int y)
{
  // Draws a Pixel to the Screen in Position x, y 
  tft.drawPixel(x, y, WHITE);

}

// void drawAnalogStateLine(int x, int y, int xnew, int ynew)
// {
//   tft.drawLine(x, y, xnew, ynew, WHITE);
// }

void drawAnalogState(int AnalogPin)
{
  // Draws the state of an input pin on the display 
  int x = 0;
  while(x < DISPLAY_WIDTH)
  {
    double val = analogRead(AnalogPin);
    int y = calculateAnalogPosition(val);
    drawAnalogStatePixel(x, y);
    // Serial.print(x, DEC);
    // Serial.print(", ");
    // Serial.println(y, DEC);
    x++;
    delay(10);
  }
  tft.fillRect(0, DISPLAY_HEIGHT - MAX_HEIGHT, DISPLAY_WIDTH, MAX_HEIGHT, BLACK);
}