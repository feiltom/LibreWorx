#include "Arduino.h"
#include "RGBled.h"


//0 - Green
//1 - GreenBlink
//2 - Blue
//3 - Red



RGBled::RGBled()
{
}

void RGBled::Begin()
{
  state=0;
  pixels = Adafruit_NeoPixel(1, 10, NEO_GRB + NEO_KHZ800);
  pixels.begin(); 
  pixels.clear(); 
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));
  pixels.show();
}
void RGBled::SetGreen()
{
  state=0;
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));
}
void RGBled::SetGreenBlink()
{
  state=1;
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));

}
void RGBled::SetBlue()
{
  state=2;
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
}
void RGBled::SetRed()
{
  state=3;
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
}
void RGBled::Refresh()
{
  if((((millis()/1000)% 2) > 0)&& (state==1)){pixels.clear(); }
  pixels.show();
}