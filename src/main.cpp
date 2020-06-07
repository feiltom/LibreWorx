#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif

#define LEDPIN 10
#define RELAYPIN 11
#define AMPPIN A2
#define SWPIN A3

Adafruit_NeoPixel pixels(1, LEDPIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
void setup() {
    Serial.begin(9600);
  Serial.println("Start");       // affichage décimal

  // put your setup code here, to run once:
    pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    pinMode(RELAYPIN, OUTPUT);
digitalWrite(RELAYPIN, LOW);
pinMode (SWPIN, INPUT_PULLUP);


}
float readCurrent()
{
  float val = 0;
  val = (analogRead(AMPPIN));  // read the input pin
  val = (val/1024*5-2.5)/0.4*1000;  // read the input pin
  return val;
}
boolean readSwitch()
{
  return !digitalRead(SWPIN);
}

void loop() {
  // put your main code here, to run repeatedly:

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<1; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 0, 150));
    digitalWrite(RELAYPIN, LOW);
 if((millis() % 2000) > 1000){pixels.clear(); } else {pixels.show();  }


  Serial.println(readSwitch());          
  Serial.println(readCurrent());          
    delay(DELAYVAL); // Pause before next pass through loop
  }
}