#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class RGBled
{
  public:
    RGBled();
    void Begin();
    void SetGreen();
    void SetGreenBlink();
    void SetBlue();
    void SetRed();
    void Refresh();
  private:
    int state;
    Adafruit_NeoPixel pixels;
};
