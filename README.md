# es_buddy

EuroShield Buddy PCB Boards and Arduino Library.

The boards add support for a Teensy 4.0, a display board that can host
a TFT or OLED display via SPI and a rotary encoder board for extended input.

You can combine these boards as you like.

## Teensy 4.0 Adapter v1.1

This little adapter board allows to use a Teensy 4.0 board on your EuroShield 1 (short ES) eurorack module.

This is the required re-routing of the Pins:

| Teensy 3.x / EuroShield Pin | Teensy 4.x Pin | Description |
|-----------------------------|----------------|-------------|
| GND | GND | |
| 0 | 0 | Midi IN |
| 1 | 1 | Midi Out |
| 2 | 2 | Button on ES and on Rotary Encoder |
| 3 | 3 | LED 1 |
| 4 | 4 | LED 2 |
| 5 | 5 | LED 2 |
| 6 | 6 | LED 3 |
| 7 | 11 | SPI MOSI |
| 8 | 9 | Display Reset |
| 9 | 21 | Audio BCLK |
| 10 | 10 | SPI CS |
| 11 | 23 | Audio MCLK - A 100 Ohm Resistor is required here! |
| 12 | 12 | SPI MISO |

| Teensy 3.x / EuroShield Pin | Teensy 4.x Pin | Description |
|-----------------------------|----------------|-------------|
| VIN | VIN | |
| AGND | AGND | |
| 3.3V | 3.3V | |
| 23 | 20 | Audio LRCLK |
| 22 | 7 | Audio TX DIN |
| 21 | 15 | Lo Pot on ES |
| 20 | 14 | Hi Pot on ES |
| 19 | 19 | I2C SCL |
| 18 | 18 | I2C SDA |
| 17 | 17 | Rotary Encoder A |
| 16 | 16 | Rotary Encoder B |
| 15 | 22 | Display CMD/Data |
| 14 | 13 | SPI SCK |
| 13 | 8 | Audio RX DOUT |

All Pins are direclty connected expect Audio MCLK is connected via
a 100 Ohm resistor.

## Rotary Encoder Buddy Board v1.1

Add a rotary encoder with button to your Euroshield.

### BOM

| Symbol | Part | Description | Mouser No. |
|--------|------|-------------|------------|
| ROT1 | PEC12R-3220F-S0024 | Bourns Rotary Encoder | 652-PEC12R3220FS0024 |
| R1-R3 | SMD 0805 10k | 10k Resistor | 71-CRCW080510K0FKEAC |
