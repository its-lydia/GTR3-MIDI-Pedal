const int N_BUTTONS = 6;
const int buttonPin[N_BUTTONS] = { 15, 14, 16, 10, 9, 8 };
const int ledPin[N_BUTTONS] = { 2, 3, 4, 5, 6, 7 };
const int midiIDs[N_BUTTONS] =  { 23, 17, 18, 19, 20, 24 };

int buttonState[N_BUTTONS] = { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH };
int lastButtonState[N_BUTTONS] = { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH };
int buttonToggled[N_BUTTONS] = { LOW, LOW, LOW, LOW, LOW, LOW };

unsigned long lastDebounceTime[N_BUTTONS] = { 0 };
const unsigned long debounceDelay = 50;

