// improved version: only print on difference
// also turns on LED when button is pressed
// and does so only when change detected
// ------------------------------------------------------
// 1. what happens when you have delay(1000)?
// Answer: it will be unresponsive for a full second, LED will
// keep its state for that length
// 2. what happens when you decrease delay?
// Answer: responsiveness will increase, time that LED keeps 
// its state will shorten
// 3. What happens if you remove delay?
// Answer: The LED will basically only be off since it has higher
// delay than actual board
int old = 1;
void setup() {
	pinMode(2,  INPUT);
  	pinMode(13, OUTPUT);
  	Serial.begin(9600);
}
void loop() {
  	int button = digitalRead(2);
    // if(button == LOW) {
    //	Serial.print("Button is pressed. ");
    // } else {
    //	Serial.print("Button is not pressed. ");
    // }
    if(old != button) {
    	Serial.println("Button state changed");
  		digitalWrite(13, !button);
    } else {}
  	delay(100);
  	old = button;
}