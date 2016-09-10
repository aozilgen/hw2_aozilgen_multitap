#if defined(ARDUINO)
SYSTEM_MODE(MANUAL);
#endif //sets cloud functionality to manual

void setup() {
  WiFi.off(); //turn off WiFi
  pinMode (D6, INPUT_PULLUP);
  pinMode (D5, INPUT_PULLUP);
  pinMode (D4, INPUT_PULLUP);
  pinMode (D3, INPUT_PULLUP);
  pinMode (A6, INPUT_PULLUP);
  pinMode (A5, INPUT_PULLUP);
  pinMode (A4, INPUT_PULLUP);
  Serial.begin(9600);      // open the serial port at 9600 bps
}

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

// Constant -- this will not change

const int bounceTime = 50;

// Variables -- these will change

int counter = 0;
int buttonIndex;
int buttonPress = LOW;
int buttonConfirm;
int lastButtonState = HIGH;
int buttonState;
char arraySelect[6];

void loop() {
  // Define the array of characters to be used on the first button press.
  if (counter == 0) {
    if (digitalRead(D6) == LOW) {
      int buttonRead = digitalRead(D6);
      delay(bounceTime);
      buttonConfirm = digitalRead(D6);
      if (buttonConfirm == buttonRead) {
        arraySelect[0] = 'g';
        arraySelect[1] = 'h';
        arraySelect[2] = 'i';
        arraySelect[3] = 'j';
        arraySelect[4] = 'k';
        arraySelect[5] = 'l';
        delay(100);
        counter = 1;
      }
    }
    else if (digitalRead(A6) == LOW) {
      int buttonRead = digitalRead(A6);
      delay(bounceTime);
      buttonConfirm = digitalRead(A6);
      if (buttonConfirm == buttonRead) {
        arraySelect[0] = 'a';
        arraySelect[1] = 'b';
        arraySelect[2] = 'c';
        arraySelect[3] = 'd';
        arraySelect[4] = 'e';
        arraySelect[5] = 'f';
        delay(100);
        counter = 1;
      }
    }
    else if (digitalRead(D5) == LOW) {
      int buttonRead = digitalRead(D5);
      delay(bounceTime);
      buttonConfirm = digitalRead(D5);
      if (buttonConfirm == buttonRead) {
        arraySelect[0] = 's';
        arraySelect[1] = 't';
        arraySelect[2] = 'u';
        arraySelect[3] = 'v';
        arraySelect[4] = 'w';
        arraySelect[5] = 'x';
        delay(100);
        counter = 1;
      }
    }
    else if (digitalRead(A5) == LOW) {
      int buttonRead = digitalRead(A5);
      delay(bounceTime);
      buttonConfirm = digitalRead(A5);
      if (buttonConfirm == buttonRead) {
        arraySelect[0] = 'm';
        arraySelect[1] = 'n';
        arraySelect[2] = 'o';
        arraySelect[3] = 'p';
        arraySelect[4] = 'q';
        arraySelect[5] = 'r';
        delay(100);
        counter = 1;
      }
    }
    else if (digitalRead(D4) == LOW) {
      int buttonRead = digitalRead(D4);
      delay(bounceTime);
      buttonConfirm = digitalRead(D4);
      if (buttonConfirm == buttonRead) {
        arraySelect[0] = '5';
        arraySelect[1] = '6';
        arraySelect[2] = '7';
        arraySelect[3] = '8';
        arraySelect[4] = '9';
        arraySelect[5] = '0';
        delay(100);
        counter = 1;
      }
    }
    else if (digitalRead(A4) == LOW) {
      int buttonRead = digitalRead(A4);
      delay(bounceTime);
      int buttonConfirm = digitalRead(A4);
      if (buttonConfirm == buttonRead) {
        arraySelect[0] = 'y';
        arraySelect[1] = 'z';
        arraySelect[2] = '1';
        arraySelect[3] = '2';
        arraySelect[4] = '3';
        arraySelect[5] = '4';
        delay(100);
        counter = 1;
      }
    }
    else if (digitalRead(D3) == LOW) {
      int buttonRead = digitalRead(D3);
      delay(bounceTime);
      int buttonConfirm = digitalRead(D3);
      if (buttonConfirm == buttonRead) {
        arraySelect[0] = ' ';
        arraySelect[1] = ',';
        arraySelect[2] = '.';
        arraySelect[3] = '!';
        arraySelect[4] = '?';
        arraySelect[5] = ':';        
        delay(100);
        counter = 1;
      }
    }
  }

  // Define index of letter based on second press

  else if (counter == 1) {
    if (digitalRead(D6) == LOW) {
      int buttonRead = digitalRead(D6);
      delay(bounceTime);
      buttonConfirm = digitalRead(D6);
      if (buttonConfirm == buttonRead) {
        buttonIndex = 1;
        Serial.print(arraySelect[buttonIndex]);
        delay(100);
        counter = 0;
      }
    }
    else if (digitalRead(A6) == LOW) {
      int buttonRead = digitalRead(A6);
      delay(bounceTime);
      buttonConfirm = digitalRead(A6);
      if (buttonConfirm == buttonRead) {
        buttonIndex = 0;
        Serial.print(arraySelect[buttonIndex]);
        delay(100);
        counter = 0;
      }
    }
    else if (digitalRead(D5) == LOW) {
      int buttonRead = digitalRead(D5);
      delay(bounceTime);
      buttonConfirm = digitalRead(D5);
      if (buttonConfirm == buttonRead) {
        buttonIndex = 3;
        Serial.print(arraySelect[buttonIndex]);
        delay(100);
        counter = 0;
      }
    }
    else if (digitalRead(A5) == LOW) {
      int buttonRead = digitalRead(A5);
      delay(bounceTime);
      buttonConfirm = digitalRead(A5);
      if (buttonConfirm == buttonRead) {
        buttonIndex = 2;
        Serial.print(arraySelect[buttonIndex]);
        delay(100);
        counter = 0;
      }
    }
    else if (digitalRead(D4) == LOW) {
      int buttonRead = digitalRead(D4);
      delay(bounceTime);
      buttonConfirm = digitalRead(D4);
      if (buttonConfirm == buttonRead) {
        buttonIndex = 5;
        Serial.print(arraySelect[buttonIndex]);
        delay(100);
        counter = 0;
      }
    }
    else if (digitalRead(A4) == LOW) {
      int buttonRead = digitalRead(A4);
      delay(bounceTime);
      int buttonConfirm = digitalRead(A4);
      if (buttonConfirm == buttonRead) {
        buttonIndex = 4;
        Serial.print(arraySelect[buttonIndex]);
        delay(100);
        counter = 0;
      }
    }
    else if (digitalRead(D3) == LOW) {
      int buttonRead = digitalRead(D3);
      delay(bounceTime);
      int buttonConfirm = digitalRead(D3);
      if (buttonConfirm == buttonRead) {
        delay(100);
        counter = 0;
      }
    }
  }
}
