volatile int old;
volatile bool interruptFired;
void setup() {
	pinMode(2,  INPUT);
  	pinMode(13, OUTPUT);
  	Serial.begin(9600);
  	attachInterrupt(0, changeLED, CHANGE);
  	old = 1; interruptFired = false;
}
void loop() {	
  	delay(100);
  	if(interruptFired) {
      	Serial.println("Interrupt fired in the last 100ms");
      	interruptFired = false;
  	}
}

void changeLED() {
	int button = digitalRead(2);
  	old = button;
  	digitalWrite(13, !button);
  	interruptFired = true;
}