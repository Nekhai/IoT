int BUZZER_PIN = 14;

// Musical notes
#define E4 330
#define G4 392
#define A4 440
#define B4 494
#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784
#define AS4 466

int melody[] = {
    E5, E5, 0, E5, 0, C5, E5, G5, 0, G4,
    C5, 0, G4, 0, E4, 0, A4, B4, AS4, A4,
    G4, E5, G5, A5, F5, G5, E5, C5, D5, B4
  };

int durations[] = {
    120, 120, 120, 120, 120, 120, 120, 240, 120, 240,
    180, 120, 180, 120, 180, 120, 120, 120, 120, 120,
    160, 160, 160, 120, 120, 120, 120, 120, 120, 240
  };

void playNote(int frequency, int duration) {
    if (frequency == 0) {
        noTone(BUZZER_PIN);
        delay(duration);
    } else {
        tone(BUZZER_PIN, frequency, duration);
        delay(duration * 1.3);
        noTone(BUZZER_PIN);
    }
}

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);

    for (int i = 0; i < 30; i++) {
        playNote(melody[i], durations[i]);
    }
}

void loop() {
}
