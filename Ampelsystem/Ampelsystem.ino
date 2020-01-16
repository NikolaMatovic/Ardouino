int const LEDrot = 1;
int const pinButtonRot = 2;

int const LEDblau = 3;
int const pinButtonBlau = 4;

int const LEDgruen = 5;
int const pinButtonGruen = 6;

int const motionSensor = 7;

int const timeToWait = 100;
boolean wasGreen = false;

void setup() {
  initialisieren();
}

void loop() {
  //rote leuchte
  if (digitalRead(pinButtonRot) == HIGH) {
    buttonLogic(LEDrot);
  }
  //blaue leuchte
  if (digitalRead(pinButtonBlau) == HIGH) {
    buttonLogic(LEDblau);
  }
  //gruene leuchte
  if (digitalRead(pinButtonGruen) == HIGH) {
    buttonLogic(LEDgruen);
  }

  //motion sensor
  if (digitalRead(motionSensor) == HIGH) {
    digitalWrite(LEDgruen, HIGH);
    digitalWrite(LEDblau, LOW);
    digitalWrite(LEDrot, LOW);
    wasGreen = !wasGreen; //hilfsvariable für den else fall
    delay(5000);
  } else if (digitalRead(motionSensor ) == LOW && wasGreen) {
    wasGreen = !wasGreen;
    digitalWrite(LEDgruen, LOW);
    digitalWrite(LEDblau, HIGH);
    delay(1000);
    digitalWrite(LEDblau, LOW);
    digitalWrite(LEDrot, HIGH);
    delay(timeToWait);
    delay(timeToWait);
  }
}

//In dieser Methode werden die Komponenten beim Ardouino initialisiert
void initialisieren() {
  pinMode(LEDrot, OUTPUT);
  pinMode(pinButtonRot, INPUT);

  pinMode(LEDblau, OUTPUT);
  pinMode(pinButtonBlau, INPUT);

  pinMode(LEDgruen, OUTPUT);
  pinMode(pinButtonGruen, INPUT);

  pinMode(pinButtonGruen, INPUT);
  digitalWrite(LEDrot, HIGH);
}

void buttonLogic(int ledPin) {
  delay(timeToWait);
  if (digitalRead(ledPin) == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
  delay(timeToWait);
}
