#include <Joystick.h>

Joystick_ Joystick;

// Zmienne
int clutch = A0;
int clutchValue = 0;
int clutchValuebyte1 = 0;
int clutchValuebyte2 = 0;

// Piny zmiany biegów (zmień te piny zgodnie z okablowaniem)
const int gear1Pin = 2;
const int gear2Pin = 3;
const int gear3Pin = 4;
const int gear4Pin = 5;
const int gear5Pin = 6;
const int gear6Pin = 7;
const int gear7Pin = 8;
const int reversePin = 9;

void setup() {
  // Inicjalizacja biblioteki joysticka
  Joystick.begin();

  // Ustawienie pinów zmiany biegów jako wejścia z włączonymi rezystorami pull-up
  pinMode(gear1Pin, INPUT_PULLUP);
  pinMode(gear2Pin, INPUT_PULLUP);
  pinMode(gear3Pin, INPUT_PULLUP);
  pinMode(gear4Pin, INPUT_PULLUP);
  pinMode(gear5Pin, INPUT_PULLUP);
  pinMode(gear6Pin, INPUT_PULLUP);
  pinMode(gear7Pin, INPUT_PULLUP);
  pinMode(reversePin, INPUT_PULLUP);
}

void loop() {
  // Sprzęgło
  clutchValue = analogRead(clutch);
  if (clutchValue >= 1) {
    clutchValuebyte1 = clutchValue / 4;
    clutchValuebyte2 = clutchValuebyte1 - 127;
  } else {
    clutchValuebyte2 = -127;
  }
  Joystick.setZAxis(clutchValuebyte2);
  delay(1); 

  // Zmiana biegów
  if (digitalRead(gear1Pin) == LOW) {
    Joystick.setButton(0, 1); // Bieg 1
  } else {
    Joystick.setButton(0, 0);
  }

  if (digitalRead(gear2Pin) == LOW) {
    Joystick.setButton(1, 1); // Bieg 2
  } else {
    Joystick.setButton(1, 0);
  }

  if (digitalRead(gear3Pin) == LOW) {
    Joystick.setButton(2, 1); // Bieg 3
  } else {
    Joystick.setButton(2, 0);
  }

  if (digitalRead(gear4Pin) == LOW) {
    Joystick.setButton(3, 1); // Bieg 4
  } else {
    Joystick.setButton(3, 0);
  }

  if (digitalRead(gear5Pin) == LOW) {
    Joystick.setButton(4, 1); // Bieg 5
  } else {
    Joystick.setButton(4, 0);
  }

  if (digitalRead(gear6Pin) == LOW) {
    Joystick.setButton(5, 1); // Bieg 6
  } else {
    Joystick.setButton(5, 0);
  }

  if (digitalRead(gear7Pin) == LOW) {
    Joystick.setButton(6, 1); // Bieg 7
  } else {
    Joystick.setButton(6, 0);
  }

  if (digitalRead(reversePin) == LOW) {
    Joystick.setButton(7, 1); // Bieg wsteczny
  } else {
    Joystick.setButton(7, 0);
  }

  delay(1);
}