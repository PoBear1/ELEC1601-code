volatile int button_press;
void setup() {
	pinMode(2, INPUT);
  	pinMode(3, INPUT);
  	pinMode(10, OUTPUT);
  	pinMode(11, OUTPUT);
  	pinMode(12, OUTPUT);
  	pinMode(13, OUTPUT);
  	button_press = 0;
  	attachInterrupt(
    	digitalPinToInterrupt(2),
      	incrementButton, FALLING
    );
  	attachInterrupt(
    	digitalPinToInterrupt(3),
      	resetButton, FALLING
    );
}
void loop() {
  	switch(button_press) {
  		case 0:
      		digitalWrite(10, LOW);
      		digitalWrite(11, LOW);
      		digitalWrite(12, LOW);
      		digitalWrite(13, LOW);
      		break;
      	case 1:
      		digitalWrite(10, HIGH);
      		break;
      	case 2:
      		digitalWrite(11, HIGH);
      		break;
      	case 3:
      		digitalWrite(12, HIGH);
      		break;
      	case 4:
      		digitalWrite(13, HIGH);
      		break;
     	default:
      		digitalWrite(10, HIGH);
      		digitalWrite(11, HIGH);
      		digitalWrite(12, HIGH);
      		digitalWrite(13, HIGH);
      		delay(1000);
      		digitalWrite(10, LOW);
      		digitalWrite(11, LOW);
      		digitalWrite(12, LOW);
      		digitalWrite(13, LOW);
      		delay(1000);
    }
}
void incrementButton() {
	button_press++;
}
void resetButton() {
	button_press = 0;
}