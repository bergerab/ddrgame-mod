#include "Keyboard.h"
#include "Mouse.h"

const int upButton = 2;
const int downButton = 3;
const int leftButton = 4;
const int rightButton = 5;
const int topLeftButton = 6;
const int topRightButton = 7;

char upButtonState = 0;
char downButtonState = 0;
char leftButtonState = 0;
char rightButtonState = 0;
char topLeftButtonState = 0;
char topRightButtonState = 0;

void setup() {
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(topLeftButton, INPUT_PULLUP);
  pinMode(topRightButton, INPUT_PULLUP);
  
  Keyboard.begin();
}

void handleKey(const int button, const char c, char *state) {
  char newState = digitalRead(button);
  if (newState != *state) {
    if (newState == LOW) {
      Keyboard.press(c);
    } else {
      Keyboard.release(c);
    }
    *state = newState;
  }
}

void loop() {
  handleKey(upButton, KEY_UP_ARROW, &upButtonState);
  handleKey(downButton, KEY_DOWN_ARROW, &downButtonState);
  handleKey(leftButton, KEY_LEFT_ARROW, &leftButtonState);
  handleKey(rightButton, KEY_RIGHT_ARROW, &rightButtonState);
  handleKey(topRightButton, KEY_RETURN, &topRightButtonState);
  handleKey(topLeftButton, KEY_ESC, &topLeftButtonState);
}
