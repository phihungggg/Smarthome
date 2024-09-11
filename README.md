# ESP8266 & Raspberry Pi3 Hand Gesture Controlled LED and Fan

## Overview

A smart home system where an ESP8266 controls an LED and a fan based on hand gesture signals detected by a Raspberry Pi 3 using a camera. The system also includes physical buttons for manual control.

## Components

- **ESP8266**: Controls LED and fan.
- **Raspberry Pi 3**: Detects hand gestures via a camera and sends signals to the ESP8266.
- **Camera**: Connected to Raspberry Pi for gesture detection.
- **LED & Fan**: Controlled by the ESP8266.
- **Physical Buttons**: For manual control of LED and fan.

## Usage

- **Gesture Control**: The Raspberry Pi detects hand gestures with the camera and sends control signals to the ESP8266 to toggle the LED and fan.
- **Button Control**: Physical buttons connected to the ESP8266 allow manual toggling of the LED and fan.

## Installation

1. **ESP8266**: Connect the LED, fan, and buttons to the GPIO pins.
2. **Raspberry Pi 3**: Connect the camera and set up the gesture detection software.

## License

Licensed under the MIT License.
