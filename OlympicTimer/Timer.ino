#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//Buttons
int const startButton = 2;
int const stopButton = 3;
int const resetButton = 10;

//Lichter
int const blauesLicht = 1;
int const rotesLicht = 13;
int const gruenesLicht = 11;

int const timeToWait = 100;
int startTime;

void setup() {
  //Buttons
  pinMode(startButton, INPUT);
  pinMode(stopButton, INPUT);
  pinMode(resetButton, INPUT);

  //Lichter
  pinMode(rotesLicht, OUTPUT);
  pinMode(gruenesLicht, OUTPUT);
  pinMode(blauesLicht, OUTPUT);

  //set values
  digitalWrite(rotesLicht, LOW);
  digitalWrite(gruenesLicht, LOW);
  digitalWrite(blauesLicht, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("OlympicTimer");

}

//Methode startet Timer
void startMyTimer() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Timer started");
  startTime = millis();
}

//Methode beendet Timer
void endMyTimer() {
  String result = (String)(((float) millis() - startTime) * 0.001);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ended with:" + result + "s");
}

void loop() {

  //Start Button
  if (digitalRead(startButton) == HIGH) {
    delay(timeToWait);

    startMyTimer();

    digitalWrite(rotesLicht, LOW);
    digitalWrite(gruenesLicht, HIGH);
    digitalWrite(blauesLicht, LOW);
    delay(timeToWait);
  }

  //Stop Button
  if (digitalRead(stopButton) == HIGH) {
    delay(timeToWait);

    endMyTimer();

    digitalWrite(rotesLicht, HIGH);
    digitalWrite(gruenesLicht, LOW);
    digitalWrite(blauesLicht, LOW);
    delay(timeToWait);
  }
  //Reset Button
  if (digitalRead(resetButton) == HIGH) {
    delay(timeToWait);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Timer reseted");

    digitalWrite(blauesLicht, HIGH);
    digitalWrite(gruenesLicht, LOW);
    digitalWrite(rotesLicht, LOW);

    delay(timeToWait);
    delay(5000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OlympicTimer");

    
  }

}
