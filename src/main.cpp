#include <Arduino.h>

#include "RGBled.h"

#include "SignalOutput.h"

#define RELAYPIN 11
#define AMPPIN A2
#define SWPIN A3
boolean PINSTATE = 0;
uint8_t g_lastCableConnected = 0;

RGBled rgbled;

void setup()
{
  // put your setup code here, to run once:
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, LOW);
  pinMode(SWPIN, INPUT_PULLUP);
  rgbled.Begin();
  rgbled.SetGreen();
  rgbled.Refresh();
  // Some time for capacitor to charge
  delay(3000);
  signalOutput.setup();
  signalOutput.start();
  digitalWrite(RELAYPIN, 1);
}
float readCurrent()
{
  float val = 0;
  val = (analogRead(AMPPIN));                // read the input pin
  val = (val / 1024 * 5 - 2.5) / 0.4 * 1000; // read the input pin
  return val;
}
boolean readSwitch()
{
  return !digitalRead(SWPIN);
}

void loop()
{
  if (PINSTATE != readSwitch())
  {
    delay(500);
    digitalWrite(RELAYPIN, !readSwitch());
    PINSTATE = readSwitch();
  }
  rgbled.SetGreen();
  if (readCurrent() > 200)
  {
    rgbled.SetGreenBlink();
  };
  if (!readSwitch())
  {
    rgbled.SetBlue();
  }
  if (!signalOutput.isCableConnected())
  {
    rgbled.SetRed();
  }
  rgbled.Refresh();
}