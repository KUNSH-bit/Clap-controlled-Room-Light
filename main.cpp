const int soundPin = 2;
const int relayPin = 8;

bool lightState = false;

unsigned long firstClapTime = 0;
unsigned long lastTriggerTime = 0;

const unsigned long clapWindow = 700;
const unsigned long cooldown = 1000;

bool waitingForSecondClap = false;

void setup() {
  pinMode(soundPin, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, HIGH);
}

void loop() {

  bool soundDetected = digitalRead(soundPin) == HIGH;

  if (soundDetected && millis() - lastTriggerTime > cooldown) {

    if (!waitingForSecondClap) {
      firstClapTime = millis();
      waitingForSecondClap = true;
    }
    else {
      if (millis() - firstClapTime <= clapWindow) {

        lightState = !lightState;

        if (lightState) {
          digitalWrite(relayPin, LOW);
        }
        else {
          digitalWrite(relayPin, HIGH);
        }

        waitingForSecondClap = false;
        lastTriggerTime = millis();
      }
      else {
        firstClapTime = millis();
      }
    }

    while (digitalRead(soundPin) == HIGH) {
      delay(5);
    }
  }

  if (waitingForSecondClap &&
      millis() - firstClapTime > clapWindow) {
    waitingForSecondClap = false;
  }
}
