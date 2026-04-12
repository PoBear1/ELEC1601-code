// C++ code
//
#include <Servo.h>
const int pin_servo = 5;
Servo servo5;
bool flip = false;
int counter = 0;
void setup() {
	pinMode(pin_servo, OUTPUT);
  	servo5.attach(pin_servo);
}

void loop() {
	servo5.write(counter);
    counter += (flip?-1:1) * 10;
  	if(counter == 150) {flip = true;}
  	if(counter == 0) {flip = false;}
	delay(100);
}
