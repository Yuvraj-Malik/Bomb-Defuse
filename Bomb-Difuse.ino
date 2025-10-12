const int ledPins[4] = {2, 3, 4, 5};
const int detectPins[4] = {6, 7, 8, 9};
int blinkCount[4] = {0, 0, 0, 0};

const int buzzerPin = 10;
bool gameActive = true;

void setup() {
  Serial.begin(9600);
 
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(detectPins[i], INPUT_PULLUP);
  }
  pinMode(buzzerPin, OUTPUT);

  Serial.println("Game starting... Watch the LEDs and remember the most frequent one!");
}

void loop() {
  if (gameActive) {
    for (int i = 0; i < 4; i++) {
      blinkCount[i] = 0;
    }
 
    int totalBlinks = 20;
    for (int i = 0; i < totalBlinks; i++) {
      int ledIndex = random(0, 4);
      blinkLED(ledIndex);
      blinkCount[ledIndex]++;
    }

    Serial.println("Blink counts:");
    for (int i = 0; i < 4; i++) {
      Serial.print("LED ");
      Serial.print(i);
      Serial.print(": ");
      Serial.println(blinkCount[i]);
    }

    Serial.println("Now remove the wire (or press the button) for the LED that blinked most!");

    bool answered = false;
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) {
      for (int i = 0; i < 4; i++) {
        if (digitalRead(detectPins[i]) == HIGH) {
          checkAnswer(i);
          answered = true;
          gameActive = false; // Stop game after answering
          break;
        }
      }
      if (answered) break;
    }

    if (!answered) {
      Serial.println("Time's up! No answer given.");
      playFailTone();
      gameActive = false; // Stop game if no answer in time
    }
  }
}

void blinkLED(int index) {
  digitalWrite(ledPins[index], HIGH);
  delay(300);
  digitalWrite(ledPins[index], LOW);
  delay(300);
}

void checkAnswer(int chosenIndex) {
  int maxIndex = 0;
  for (int i = 1; i < 4; i++) {
    if (blinkCount[i] > blinkCount[maxIndex]) {
      maxIndex = i;
    }
  }

  if (chosenIndex == maxIndex) {
    Serial.println("Correct! You picked the LED that blinked most.");
    playSuccessTone();
  } else {
    Serial.println("Wrong! That was not the most frequent LED.");
    playFailTone();
  }
}

void playSuccessTone() {
  tone(buzzerPin, 1000, 300);
  delay(300);
  tone(buzzerPin, 1500, 300);
  delay(300);
  noTone(buzzerPin);
}

void playFailTone() {
  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, 400, 300);
    delay(300);
    tone(buzzerPin, 200, 300);
    delay(300);
  }
  noTone(buzzerPin);
}
