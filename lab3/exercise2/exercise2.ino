#include <Servo.h>
Servo left;
Servo right;
int mov{2};
void setup() {
	left.attach(13);
  	right.attach(12);
  	// moving forwards == left = CCW, right = CW
  	// moving backward == left = CW,  left  = CCW
  	// moving left	   == left = CW,  right = CW
  	// moving right	   == left = CCW, right = CCW
  	switch(mov) {
      	case 0:
            left.writeMicroseconds(1600);
            right.writeMicroseconds(1400);
     		break;
      	case 1:
            left.writeMicroseconds(1400);
            right.writeMicroseconds(1600);
     		break;
      	case 2:
            left.writeMicroseconds(1400);
            right.writeMicroseconds(1400);
     		break;
     	default:
            left.writeMicroseconds(1600);
            right.writeMicroseconds(1600);
  	}
  	delay(3000);
}
void loop() {
  	left.writeMicroseconds(1500);
  	right.writeMicroseconds(1500);
}