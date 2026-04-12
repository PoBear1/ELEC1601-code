void setup() {
	pinMode(10, OUTPUT);
}
void loop() {
	digitalWrite(10, HIGH); // Pin 10 will be high, from description earlier of the circuit diagram, this will turn the LED on
  delay(1000);			// wait for a second
	digitalWrite(10, LOW);  // Pin 10 will be low, from description earlier of the circuit diagram, this will turn the LED off
	delay(1000);			// wait for a second
}