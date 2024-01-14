# Morse Code Translator

## Overview
This Arduino-based Morse Code translator reads text input from a serial connection and converts it into Morse code. The converted code is then output as sound using a buzzer.

## Features
- Text-to-Morse Conversion: Converts input text into Morse code.
- Sound Output: Outputs Morse code as beeps using a buzzer.
- Serial Communication: Receives text input through serial communication.

## Hardware Requirements
- Arduino Board (e.g., Arduino Uno)
- Buzzer
- Jumper wires
- Breadboard (optional)
- LED (optional)

## Setup
### Hardware Setup
- Connect the buzzer to pin 12 on the Arduino board.
- Ensure proper power supply and grounding.
- Connect the LED  bulb parallel to the buzzer pins. (optional)

### Software Setup
- Upload the provided code to the Arduino board using the Arduino IDE.
- Open the Serial Monitor in the Arduino IDE to send text input.

## Usage
1. Enter text into the Arduino IDE's Serial Monitor.
2. The Arduino reads the input and converts it into Morse code.
3. The Morse code is output as a series of beeps from the buzzer.

## Customization
- Modify the `morseMap` array to change Morse code mappings.
- Adjust beep and delay durations in `beepDot` and `beepDash` for different sound patterns.

## Troubleshooting
- **No Sound**: Ensure the buzzer is properly connected and the correct pin is specified.
- **Incorrect Morse Code**: Check the `morseMap` array and handling of spaces in `sentenceToCode`.
- **Serial Issues**: Verify the correct COM port and baud rate in the Arduino IDE.
