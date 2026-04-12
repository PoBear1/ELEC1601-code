void setup() {
  	// Initiate serial communication
  	// Set speed to 9600 baud (bits/sec)
  	// See http://arduino.cc/en/Serial/Begin for more details.
  	Serial.begin(9600);
}
void loop() {
  	// Write a message to serial port
  	Serial.print("Hello, Group 16!\n");
  	Serial.println("How are you finding today's lab?");
    while(Serial.available() == 0) {}
  	String x = Serial.readString();
  	// pause for one second
  	delay(1000);
}
// 1. what has changed? = newline not automatically added
// 2. what does Serial.print do? = does not add the trailing newline to end of string
// 3. what does '\n' do? = add the newline as a escape char
// 4. what do you think Serial.println does internally? = add the newline to the end
// essentially Serial.println(s) = Serial.print(s + '\n').