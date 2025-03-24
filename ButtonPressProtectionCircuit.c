#include <Arduino.h>

constexpr int BTN_PIN = 2;
constexpr unsigned long WAIT_AFTER_PRESS = 10000;
constexpr unsigned long DEBOUNCE_DELAY = 50;

enum class Status { OFF, ON, PROTECTED };

Status state = Status::OFF;
bool lastButtonReading = HIGH;
bool debouncedButtonReading = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long pressedAt = 0;
unsigned long protectedStart = 0;

bool isButtonPressed() {
  bool reading = digitalRead(BTN_PIN);
  unsigned long currentTime = millis();
  if (reading != lastButtonReading) {
    lastDebounceTime = currentTime;
    lastButtonReading = reading;
  }
  if (currentTime - lastDebounceTime >= DEBOUNCE_DELAY) {
    debouncedButtonReading = reading;
  }
  return debouncedButtonReading == LOW;
}

void setup() {
  Serial.begin(115200);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void updateState() {
  bool buttonPressed = isButtonPressed();
  unsigned long now = millis();
  if (state == Status::OFF && buttonPressed) {
    state = Status::ON;
    pressedAt = now;
    Serial.println("STATUS: ON");
  }
  else if (state == Status::ON && !buttonPressed) {
    state = Status::PROTECTED;
    protectedStart = now;
    float duration = (now - pressedAt) / 1000.0;
    Serial.print("pressed for ");
    Serial.println(duration, 1);
    Serial.println("STATUS: PROTECTED");
    Serial.print("Will remain in PROTECTED for ");
    Serial.print(WAIT_AFTER_PRESS / 1000);
    Serial.println(" seconds");
  }
  else if (state == Status::PROTECTED && (now - protectedStart >= WAIT_AFTER_PRESS)) {
    state = Status::OFF;
    Serial.println("STATUS: OFF");
  }
}

void loop() {
  updateState();
  delay(10);
}
