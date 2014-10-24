#include <Servo.h>

Servo myservo;

int ledPin = 13;
int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
int joyPin2 = 1;                 // slider variable connecetd to analog pin 1
int value1 = 0;                  // variable to read the value from the analog pin 0
int value2 = 0;                  // variable to read the value from the analog pin 1

void setup() {
    pinMode(ledPin, OUTPUT);              // initializes digital pins 0 to 7 as outputs
    Serial.begin(9600);
    myservo.attach(8);
}

int treatValue(int data) {
    return data;
}

int mapOutput(int in)
{
    int min_val = 30;
    int max_val = 150;
    int diff = max_val - min_val;
    double r = in;
    r *= double(diff) / 1000.;
    r += min_val;
    if (r > max_val) {
        r = max_val;
    }
    if (r < min_val) {
        r = min_val;
    }
    return int(r);
}

void loop() {
    // reads the value of the variable resistor
    value1 = analogRead(joyPin1);
    // this small pause is needed between reading
    // analog pins, otherwise we get the same value twice
    /*delay(100);*/
    // reads the value of the variable resistor
    value2 = analogRead(joyPin2);

    myservo.write(mapOutput(value1));
}
