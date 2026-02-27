#include "MIDIUSB.h"
#include "usb_rename.h"
#include "gtr3_pedal.h"

USBRename dummy = USBRename("GTR3_Pedal");

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = { 0x0B, 0xB0 | channel, control, value };
  MidiUSB.sendMIDI(event);
}

void sendCommand(int state, int midiID) {
  switch (state) {
    case 0:
      controlChange(0, midiID, 0);
      MidiUSB.flush();
      break;
    case 1:
      controlChange(0, midiID, 127);
      MidiUSB.flush();
      break;
  }
}

void toggleButton(int index){
  sendCommand((buttonState[index] == LOW) ? 1 : 0, midiIDs[index]);
  handleLed(index, 1);
}

void switchButton(int index){
  if (buttonState[index] == HIGH) {
    buttonToggled[index] = !buttonToggled[index]; 
    sendCommand(buttonToggled[index] ? 1 : 0, midiIDs[index]);
  }
  handleLed(index, 2);
}

void handleLed(int index, int mode){
  switch(mode){
    //button mode = toggle
    case(1):
      digitalWrite(ledPin[index], (!buttonState[index] ? HIGH : LOW));
      break;

    //button mode = switch
    case(2):
      digitalWrite(ledPin[index], (buttonToggled[index] ? LOW : HIGH));
      break;
  }
}

void handleButton(int index, int mode){
  int reading = digitalRead(buttonPin[index]);

  if (reading != lastButtonState[index]){
    lastDebounceTime[index] = millis();
  }

  if ((millis() - lastDebounceTime[index]) > debounceDelay){
    if (reading != buttonState[index]) {
      buttonState[index] = reading;
      (mode == 1) ? toggleButton(index) : switchButton(index);
      handleLed (index, mode);
    }
  }
  lastButtonState[index] = reading;
}

void setup() {
  for (int i = 0; i < N_BUTTONS; i++){
    pinMode(buttonPin[i], INPUT_PULLUP);
    pinMode(ledPin[i], OUTPUT);
    buttonToggled[i] = LOW;
    digitalWrite(ledPin[i], LOW);
  } 

}

void loop() {
  for (int i = 0; i < N_BUTTONS; i ++){
    int mode = (i == 0 || i == 5) ? 1 : 2;
    handleButton(i, mode);
  }
}
