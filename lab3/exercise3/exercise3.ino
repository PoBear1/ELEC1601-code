#include <Servo.h>
Servo left;
Servo right;
int ccwtop = 1600;
int ccwmid = 1600;
int cwtop = 1400;
int cwmid = 1400;
void setup() {
	left.attach(13);
  	right.attach(12);
  	// moving forwards == left = CCW, right = CW
  	// moving backward == left = CW,  left  = CCW
  	// moving left	   == left = CW,  right = CW
  	// moving right	   == left = CCW, right = CCW
  	left.writeMicroseconds(ccwtop);
  	right.writeMicroseconds(cwtop);
  	Serial.begin(9600);
}
void loop() {
	int a = analogRead(A0);
  	int b = analogRead(A1);
  	Serial.println("A0 reading: " + String(a) + ", A1 reading: " + String(b));
    if(a < 400 && b > 400) {
        left.writeMicroseconds(ccwmid);
        right.writeMicroseconds(ccwmid);
      	delay(3000);
    } else if(b < 400 && a > 400) {
        left.writeMicroseconds(cwmid);
        right.writeMicroseconds(cwmid);
      	delay(3000);
    } else {}
  	left.writeMicroseconds(ccwtop);
  	right.writeMicroseconds(cwtop);
}