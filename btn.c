#define BUTTON_PIN 14
#define LED_PIN 25

int buttonCount = 0;
int buttonState = HIGH;
int lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    Serial.begin(115200);

    digitalWrite(LED_PIN, LOW);
}

void loop() {
    int reading = digitalRead(BUTTON_PIN);

    if (reading != buttonState) {
        buttonState = reading;

        if (buttonState == LOW) {
            buttonCount++;

            digitalWrite(LED_PIN, buttonCount % 2);

            Serial.print("Button clicked: ");
            Serial.println(buttonCount);

            Serial.print("Led: ");
            Serial.println(buttonCount % 2);
        }
    }

    lastButtonState = reading;
}
