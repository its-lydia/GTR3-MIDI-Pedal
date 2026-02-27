# Arduino Midi Footswitch
A Midi Footswitch designed to work with the GTR3 plugin

## Overview
The pedal features **6 footswitches and 6 LEDs** and is designed to send **MIDI Control Change (CC) messages** to control the **Waves GTR3 plugin (or standalone)**.

With this pedal, you can:  
- Switch between **guitar presets** in GTR3  
- Turn individual **effects or pedals ON/OFF** within GTR3  

Currently each button sends a **fixed MIDI Control Change message**.

## Hardware requirements
- [1 Arduino Pro Micro](https://www.aliexpress.com/item/1005007703648261.html?spm=a2g0o.order_list.order_list_main.116.16ea18023OEC0j)
- [6 Momentary footswitches](https://www.aliexpress.com/item/1005004646906063.html?spm=a2g0o.order_list.order_list_main.121.16ea18023OEC0j)
- [6 LEDs (5 mm)](https://www.aliexpress.com/item/1005005708510866.html?spm=a2g0o.order_list.order_list_main.106.16ea18023OEC0j)
- [6 5mm LED holders (5 mm)](https://www.aliexpress.com/item/1005002248561990.html?spm=a2g0o.order_list.order_list_main.91.16ea18023OEC0j)
- [6 220 Ohms resistors](https://www.aliexpress.com/item/1005007714306585.html?spm=a2g0o.order_list.order_list_main.126.16ea18023OEC0j)
- [1 Hammond enclosure (or any type of enclosure)](https://www.aliexpress.com/item/1005006612598260.html?spm=a2g0o.order_list.order_list_main.80.16ea18023OEC0j)
- [1 Solderable Breadboard (4 x 6 cm)](https://www.aliexpress.com/item/1005006304713536.html?spm=a2g0o.order_list.order_list_main.101.16ea18023OEC0j)
- 1 USB-C to USB data cable
- Soldering equipment
- [Soldering wire (24AWG)](https://www.aliexpress.com/item/1005004336218242.html?spm=a2g0o.order_detail.order_detail_item.3.754ff19csiuzUS)

## Wiring diagram


![wiring-diagram](https://github.com/user-attachments/assets/963e21e7-3f2d-402c-857e-c0da90e0e194)

## Setup
This project uses the **Arduino-USB-Rename** available [here](https://github.com/mon/Arduino-USB-Rename).

It also requires the **MIDIUSB** library available [here](https://github.com/arduino-libraries/MIDIUSB). You can also install it via the Arduino IDE with the library manager.

1. Connect the pedal to the computer via USB
   - If the code is already flashed, skip to step 3
2. Open the Arduino IDE
   - Select the Arduino Micro board under Tools -> Board -> Arduino AVR Boards
   - Select the COM Port under Tools -> Port
   - Verify and Upload the code
3. Launch GTR3
4. Go to File -> Preferences

   ![setup-1](https://github.com/user-attachments/assets/129f27a4-cab3-4b98-b883-ba33722e2563)


5. Check the GTR3_Pedal under Active MIDI inputs

   ![setup-2](https://github.com/user-attachments/assets/de9b5af0-b08e-46fe-84ca-1d6fd033a169)

## Mapping effects via MIDI
1. Right click on the effect(s) you want to control in GTR3
2. Click Learn

   ![mapping](https://github.com/user-attachments/assets/3936fa2f-a8b7-4c8f-afdb-5459ffa7222d)


3. Press the footswitch on the pedal you want to assign to that effect

Multiple effects can be mapped to the same footswitch if you want to toggle them together.

For a full guide on MIDI mapping and controlling multiple parameters, see the [**Waves GTR3 ToolRack Manual**](https://assets.wavescdn.com/pdf/plugins/gtr3-toolrack.pdf)

## Removing a MIDI Mapping
1. Right-click on the effect

   ![clear](https://github.com/user-attachments/assets/807716ab-dac2-449b-94a3-192c3709f437)


2. Click Clear or Cancel Learn, depending on your situation



## Tips
- Make sure the pedal is plugged in before opening GTr3, so it appears in the MIDI inputs
- If GTR3 doesn't detect the pedal, try re-flashing the Arduino code and reconnecting

**That's it, you're ready to rock !**

## Final Product
   ![final-product](https://github.com/user-attachments/assets/b1ff2041-3e6d-4c94-9ec1-ff941c683dcc)

## Upcoming Features & Upgrades
1. **Bank Support**  
   - Switch between multiple banks to expand the number of presets and effects accessible from the 6 buttons.  

2. **Custom MIDI IDs per Button**  
   - Assign specific MIDI Control Change (CC) numbers or Program Change (PC) messages to each button for full control of GTR3 presets and effects.  

3. **LCD Display**  
   - Add an LCD screen on the footswitch to show:
     - Current **mode** of each button (momentary or toggle)
     - Assigned **MIDI ID**    
     - Active **bank**  

4. **Long Press & Multi-Action Support**  
   - Perform multiple MIDI actions per button, triggered by short or long presses.  

These upgrades will make the pedal fully customizable, more versatile for live performance, and easier to use without referencing external documentation.
