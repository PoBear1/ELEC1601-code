// improved version: only print on difference
int old = 1;
void setup() {
  	// declare pin 2 as input
	pinMode(2,  INPUT);
 	// init serial
  	Serial.begin(9600);
}
void loop() {
  	int button = digitalRead(2);
    if(old != button) {
    	Serial.println("Button state changed");
    }
  	delay(1000);
  	old = button;
}
// 1. predict what will happen: if button is down when on reading
// time, then will read 0 since voltage does not flow to pin 2 
// instead it flows to ground
// if button not pushed then read 1 since voltage only flows to 
// pin 2