#include <Bounce2.h>

const byte SER = 8;
const byte LATCH = 9;
const byte CLK = 10;
const byte BUTTON = 2;

const byte DAY1 = B00000001;
const byte DAY2 = B00000011;
const byte DAY3 = B00000111;
const byte DAY4 = B00001111;
const byte DAY5 = B00011111;
const byte DAY6 = B00111111;
const byte DAY7 = B01111111;
const byte DAY8 = B11111111;

Bounce debounce = Bounce();

void setup()
{
  Serial.begin(9600);
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);
  debounce.attach(BUTTON);
  debounce.interval(5);

  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLK, MSBFIRST, B00000000);
  digitalWrite(LATCH, HIGH);

}

void loop()
{
  debounce.update();

  int butVal = debounce.read();

  if(butVal == LOW)
  {
       digitalWrite(SER,HIGH);
       digitalWrite(LATCH, LOW);
       digitalWrite(CLK, HIGH);
       digitalWrite(CLK, LOW);
       digitalWrite(LATCH, HIGH);
       digitalWrite(SER,LOW);
  }

}
