void setup() {
 	Serial.begin(9600);
}

void loop() {
	int x = analogRead(A0);
  	Serial.println("Pin A0 value: " + String(x));
}