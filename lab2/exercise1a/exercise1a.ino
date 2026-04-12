// C++ code
//
const int pin_A = 12;
const int pin_B = 11;
const int pin_C = 10;
const int pin_D = 9;
const int pin_E = 8;
const int pin_F = 7;
const int pin_G = 6;
int counter = 0;
void setup() {
	pinMode(pin_A, OUTPUT);
	pinMode(pin_B, OUTPUT);
	pinMode(pin_C, OUTPUT);
	pinMode(pin_D, OUTPUT);
	pinMode(pin_E, OUTPUT);
	pinMode(pin_F, OUTPUT);
	pinMode(pin_G, OUTPUT);
  	pinMode(3,	   INPUT);
  	attachInterrupt(digitalPinToInterrupt(3), update_counter, FALLING); 
}

void loop() {
  	bool a, b, c, d, e, f, g;
    switch(counter) {
      	case 0: a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 0; break;
      	case 1: a = 0; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0; break;
      	case 2: a = 1; b = 1; c = 0; d = 1; e = 1; f = 0; g = 1; break;
      	case 3: a = 1; b = 1; c = 1; d = 1; e = 0; f = 0; g = 1; break;
      	case 4: a = 0; b = 1; c = 1; d = 0; e = 0; f = 1; g = 1; break;
      	case 5: a = 1; b = 0; c = 1; d = 1; e = 0; f = 1; g = 1; break;
      	case 6: a = 1; b = 0; c = 1; d = 1; e = 1; f = 1; g = 1; break;
      	case 7: a = 1; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0; break;
      	case 8: a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 1; break;
      	case 9: a = 1; b = 1; c = 1; d = 0; e = 0; f = 1; g = 1; break;
      	default:a = 0; b = 0; c = 0; d = 0; e = 0; f = 0; g = 0;
    }
  	digitalWrite(pin_A, a);
  	digitalWrite(pin_B, b);
  	digitalWrite(pin_C, c);
  	digitalWrite(pin_D, d);
  	digitalWrite(pin_E, e);
  	digitalWrite(pin_F, f);
  	digitalWrite(pin_G, g);
	delay(10);
}

void update_counter() {
	counter++; counter %= 10;
}
