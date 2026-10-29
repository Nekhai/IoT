const int btn = 7;
const int redLed = 2;
const int greenLed = 3;
const int orangeLed = 4;

int state = 0;

void setup() {
    pinMode(btn, INPUT);
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(orangeLed, OUTPUT);
}

void loop() {
    int buttonState = digitalRead(btn);

    while (buttonState == HIGH) {
        int currentBtnState = digitalRead(btn);
        if (currentBtnState == LOW) {
            return;
        };

        state = (state >= 3) ? 1 : ++state;
        switchLed();

        delay(300);
    }

    state = 0;
    switchLed();
}

void switchLed() {
    digitalWrite(redLed,   (state == 1) ? HIGH : LOW);
    digitalWrite(orangeLed, (state == 2) ? HIGH : LOW);
    digitalWrite(greenLed,  (state == 3) ? HIGH : LOW);
}
