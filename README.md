
# MaxPico

**WARNING: This code is currently work in progress and is being tested with a breadboard set up for a Raspberry Pi Pico with SD card reader, OLED screen, buttons and 3.5mm headphone jack connected by Dupont jumper wires alone at present.**

**MaxPico is based on [MaxDuino](https://github.com/rcmolina/MaxDuino) and the [TzxDuino Reloaded](https://github.com/arananet/TzxDuino-Reloaded) project**

* v1.00 Initial release will be adding in Pico support using the [Arduino Pico](https://github.com/earlephilhower/arduino-pico) board support from Earle F Philhower
* v1.01 Remove all other hardware code leaving just Raspberry Pi Pico

## How to setup Arduino IDE

### Dependencies (tested versions shown - newer versions may not work)
#### Board Manager
Raspberry Pi Pico/RP2040 - v2.2.2 - by Earle Philhower

#### Libraries
RPI_PICO_TimerInterrupt - v1.1.1 - by Khoi Hoang

### Set up board
Change board to "Raspberry Pi Pico" and change "USB Stack" to "Adafruit TinyUSB".

When uploading sketch, first unplug and re-plug the Pico with BOOTSEL held down (this puts in file mode) - COM port not required (except for debugging with serial monitor)

## Default GPIO pins (that cannot be changed in pinSetup.h)
*OLED Display (on I2C1 - default I2C)*
* GP4 - SDA
* GP5 - SCL

*SD Card Reader (on SPI0 - default SPI)*
* GP16 - RX
* GP17 - CS - Can be changed in pinSetup.h but best left unchanged (CS for the default SPI)
* GP18 - SCK
* GP19 - TX

## What has been tested?
* Logos
* Fonts
* SD card reading
* OLED 0.96" yellow/blue display (OLED_1306_128_64)
* Menu system - including changing motor control and baud rate
* File browsing
* CDT files playing on real Amstrad CPC464 hardware - *I am currently experiencing some noise issues which prevents custom loader games from working, which is probably just my hardware setup on a breadboard!*
* Pause / resume / change block

## What has NOT been tested?
* Other displays
* EEPROM emulation
* Other system testing (e.g. ZX Spectrum)
* More....
