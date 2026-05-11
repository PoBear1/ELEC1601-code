#include <Servo.h> 
#include <deque>
#include <tuple>

std::deque<std::tuple<int, int, int, unsigned long>> last_moves;

Servo servoLeft; 
Servo servoRight; 

// Add task finished flag
bool taskFinished = false;

// left IR and IR LED
const int LeftirLedPin = 10;
const int LeftirReceiverPin = 11; 

// left LED
const int LeftredLedPin = A2; 

// front IR and IR LED
const int MidirLedPin = 6;
const int MidirReceiverPin = 7; 

// front LED
const int MidredLedPin = A1; 

// right IR and IR LED
const int RightirLedPin = 2;
const int RightirReceiverPin = 3;

// right LED
const int RightredLedPin = A0; 

void setup() 
{ 
    servoLeft.attach(13); 
    servoRight.attach(12); 

    pinMode(LeftirReceiverPin, INPUT); 
    pinMode(LeftirLedPin, OUTPUT);
    pinMode(LeftredLedPin, OUTPUT); 

    pinMode(MidirReceiverPin, INPUT); 
    pinMode(MidirLedPin, OUTPUT); 
    pinMode(MidredLedPin, OUTPUT);

    pinMode(RightirReceiverPin, INPUT); 
    pinMode(RightirLedPin, OUTPUT); 
    pinMode(RightredLedPin, OUTPUT); 

    // A3 is used in distance() as the LED display pin
    pinMode(A3, OUTPUT);

    Serial.begin(9600); 
} 

// use different frequency to detect and return accumulation
int distance(int ledPin, int receiverPin) 
{ 
    int dist = 0; 

    for (long f = 38000; f <= 42000; f += 1000) 
    { 
        // call irDetect to detect whether infrared reflection is received
        // at the current frequency, and accumulate the results
        dist += irDetect(f, ledPin, receiverPin, A3); 
    } 

    return dist; 
} 

void stopMotors() 
{ 
    servoRight.writeMicroseconds(1500); 
    servoLeft.writeMicroseconds(1500);
}

void loop() 
{ 
    if (taskFinished) 
    { 
        stopMotors(); 
        while (1); 
    } 

    int left_value = irDetect(38000, LeftirLedPin, LeftirReceiverPin, LeftredLedPin); 
    int mid_value = irDetect(40000, MidirLedPin, MidirReceiverPin, MidredLedPin);
    int right_value = irDetect(38000, RightirLedPin, RightirReceiverPin, RightredLedPin); 

    int left_distance = distance(LeftirLedPin, LeftirReceiverPin); 
    int right_distance = distance(RightirLedPin, RightirReceiverPin); 

    // stop: front, left, and right all detect obstacle
    if (mid_value == 0 && left_value == 0 && right_value == 0) 
    { 
        stopMotors(); 
        taskFinished = true;
    } 

    // right turn
    else if (mid_value == 0 && left_value == 0 && right_value != 0) 
    { 
        servoLeft.writeMicroseconds(1600);
        servoRight.writeMicroseconds(1600); 
        delay(280);

        servoLeft.writeMicroseconds(1640);
        servoRight.writeMicroseconds(1357); 
        delay(250); 

        servoLeft.writeMicroseconds(1540); 
        servoRight.writeMicroseconds(1540); 
        delay(500); 
    } 

    // left turn
    else if (mid_value == 0 && left_value != 0 && right_value == 0) 
    { 
        servoLeft.writeMicroseconds(1397); 
        servoRight.writeMicroseconds(1397);
        delay(280); 

        servoLeft.writeMicroseconds(1600); 
        servoRight.writeMicroseconds(1397); 
        delay(250); 

        servoLeft.writeMicroseconds(1457); 
        servoRight.writeMicroseconds(1457); 
        delay(500);
    } 

    // straight
    else if (mid_value == 0 && left_value != 0 && right_value != 0) 
    { 
        servoLeft.writeMicroseconds(1397); 
        servoRight.writeMicroseconds(1397); 
        delay(280); 

        servoLeft.writeMicroseconds(1600); 
        servoRight.writeMicroseconds(1397); 
        delay(250); 

        servoLeft.writeMicroseconds(1457); 
        servoRight.writeMicroseconds(1457); 
        delay(500); 
    } 

    // correction
    else 
    {
        if (left_distance <= 0) 
        { 
            servoLeft.writeMicroseconds(1530); 
            servoRight.writeMicroseconds(1530); 
            delay(90);
        } 
        else if (right_distance <= 0) 
        { 
            servoLeft.writeMicroseconds(1465);
            servoRight.writeMicroseconds(1465); 
            delay(90); 
        }

        servoLeft.writeMicroseconds(1600); 
        servoRight.writeMicroseconds(1397); 
    } 
} 

int irDetect(long frequency, unsigned int irLedPin, unsigned int irReceiverPin, unsigned int redLedPin) 
{ 
    tone(irLedPin, frequency); // send the IR signal
    delay(1); 

    noTone(irLedPin); 

    int ir = digitalRead(irReceiverPin); 

    if (ir == 0) // detect IR reflection
    {
        digitalWrite(redLedPin, 1); 
    }
    else 
    {
        digitalWrite(redLedPin, 0);
    }

    delay(1); 

    return ir;
}
