# Clap Controlled Room Light

An Arduino-based home automation project that uses a sound sensor and relay to control a room light with a double-clap gesture.

## Features

* Double-clap detection
* Toggle light ON/OFF using a relay
* Adjustable clap detection window
* Cooldown to reduce accidental triggers
* Built using Arduino and a sound sensor

## Components

* Arduino Nano
* KY-037 sound sensor
* 5V relay module
* Jumper wires
* Light/load

## Connections

| Component        | Arduino |
| ---------------- | ------- |
| Sound Sensor VCC | 5V      |
| Sound Sensor GND | GND     |
| Sound Sensor DO  | D2      |
| Relay VCC        | 5V      |
| Relay GND        | GND     |
| Relay IN         | D8      |

## How It Works

The Arduino monitors the sound sensor for a clap.

A single clap starts a short detection window. If a second clap is detected within that window, the Arduino toggles the relay state.

```text
Clap 1 → Start Timer → Clap 2 → Toggle Relay → Light ON/OFF
```

This prevents the light from responding to every individual sound.

## Configuration

The time allowed between the two claps can be adjusted in the code:

```cpp
const unsigned long clapWindow = 700;
```

The sound sensor's sensitivity can also be adjusted using the potentiometer on the sensor module.

## Limitations

The KY-038/KY-037 detects sound intensity rather than specifically recognizing a clap. Loud sounds may therefore trigger the sensor. The double-clap requirement helps reduce accidental activation but does not completely eliminate it.

## Future Improvements

* More accurate clap recognition
* Adjustable sensitivity through software
* Three-clap activation
* Bluetooth control
* Wi-Fi control using ESP32
* Mobile application integration
* Multiple appliance control

## Project Status

Working Arduino implementation. Hardware behavior depends on the sound sensor and relay module used.

## Safety

For mains-powered lights, use a properly rated and enclosed relay module. Mains wiring should be handled by a qualified adult or electrician. Do not work with exposed mains connections.
