EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "EuroShield T4 Adapter"
Date ""
Rev "1.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x14 J1
U 1 1 5F5FF9D8
P 2100 2350
F 0 "J1" H 2050 3200 50  0000 L CNN
F 1 "T3_Left" H 2050 3100 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical_NoSilk" H 2100 2350 50  0001 C CNN
F 3 "~" H 2100 2350 50  0001 C CNN
	1    2100 2350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x14 J2
U 1 1 5F601FF7
P 2850 2350
F 0 "J2" H 2768 3167 50  0000 C CNN
F 1 "T3_Right" H 2768 3076 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical_NoSilk_NoPin1" H 2850 2350 50  0001 C CNN
F 3 "~" H 2850 2350 50  0001 C CNN
	1    2850 2350
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x14 J3
U 1 1 5F6073A5
P 5300 2300
F 0 "J3" H 5380 2292 50  0000 L CNN
F 1 "T4_Left" H 5380 2201 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical_NoSilk" H 5300 2300 50  0001 C CNN
F 3 "~" H 5300 2300 50  0001 C CNN
	1    5300 2300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x14 J4
U 1 1 5F609CAC
P 6200 2350
F 0 "J4" H 6118 3167 50  0000 C CNN
F 1 "T4_Right" H 6118 3076 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical_NoSilk_NoPin1" H 6200 2350 50  0001 C CNN
F 3 "~" H 6200 2350 50  0001 C CNN
	1    6200 2350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1900 1850 1400 1850
Wire Wire Line
	1900 1950 1400 1950
Wire Wire Line
	1900 2050 1400 2050
Wire Wire Line
	1900 2150 1400 2150
Wire Wire Line
	1900 2250 1400 2250
Wire Wire Line
	1900 2350 1400 2350
Wire Wire Line
	1900 2450 1400 2450
Wire Wire Line
	1900 2550 1400 2550
Wire Wire Line
	1900 2650 1400 2650
Wire Wire Line
	1900 2750 1400 2750
Wire Wire Line
	1900 2850 1400 2850
Wire Wire Line
	1900 3050 1400 3050
Wire Wire Line
	3050 1750 3650 1750
Wire Wire Line
	3050 1950 3650 1950
Wire Wire Line
	3050 2050 3650 2050
Wire Wire Line
	3050 2150 3650 2150
Wire Wire Line
	3050 2250 3650 2250
Wire Wire Line
	3050 2350 3650 2350
Wire Wire Line
	3050 2450 3650 2450
Wire Wire Line
	3050 2550 3650 2550
Wire Wire Line
	3050 2650 3650 2650
Wire Wire Line
	3050 2750 3650 2750
Wire Wire Line
	3050 2850 3650 2850
Wire Wire Line
	3050 2950 3650 2950
Wire Wire Line
	3050 3050 3650 3050
Text Label 1400 1750 0    50   ~ 0
GND
Text Label 1400 1850 0    50   ~ 0
MIDI_IN
Text Label 1400 1950 0    50   ~ 0
MIDI_OUT
Text Label 1400 2050 0    50   ~ 0
BUTTON
Text Label 1400 2150 0    50   ~ 0
LED1
Text Label 1400 2250 0    50   ~ 0
LED2
Text Label 1400 2350 0    50   ~ 0
LED3
Text Label 1400 2450 0    50   ~ 0
LED4
Text Label 1400 2550 0    50   ~ 0
MOSI
Text Label 1400 2650 0    50   ~ 0
DSP_RST
Text Label 1400 2750 0    50   ~ 0
BCLK
Text Label 1400 2850 0    50   ~ 0
CS
Text Label 1400 2950 0    50   ~ 0
MCLK
Text Label 1400 3050 0    50   ~ 0
MISO
Text Label 3200 1750 0    50   ~ 0
VIN
Text Label 3200 1850 0    50   ~ 0
GND
Text Label 3200 1950 0    50   ~ 0
3.3V
Text Label 3200 2050 0    50   ~ 0
LRCLK
Text Label 3200 2150 0    50   ~ 0
DIN
Text Label 3200 2250 0    50   ~ 0
LO_POT
Text Label 3200 2350 0    50   ~ 0
UP_POT
Text Label 3200 2450 0    50   ~ 0
SCL
Text Label 3200 2550 0    50   ~ 0
SDA
Text Label 3200 2650 0    50   ~ 0
ENC_A
Text Label 3200 2750 0    50   ~ 0
ENC_B
Text Label 3200 2850 0    50   ~ 0
DSP_C_S
Text Label 3200 2950 0    50   ~ 0
SCK
Text Label 3200 3050 0    50   ~ 0
DOUT
Wire Wire Line
	5100 1800 4600 1800
Wire Wire Line
	5100 1900 4600 1900
Wire Wire Line
	5100 2000 4600 2000
Wire Wire Line
	5100 2100 4600 2100
Wire Wire Line
	5100 2200 4600 2200
Wire Wire Line
	5100 2300 4600 2300
Wire Wire Line
	5100 2400 4600 2400
Wire Wire Line
	5100 2500 4600 2500
Wire Wire Line
	5100 2600 4600 2600
Wire Wire Line
	5100 2700 4600 2700
Wire Wire Line
	5100 2800 4600 2800
Wire Wire Line
	5100 2900 4600 2900
Wire Wire Line
	5100 3000 4600 3000
Text Label 4600 1700 0    50   ~ 0
GND
Text Label 4600 1800 0    50   ~ 0
MIDI_IN
Text Label 4600 1900 0    50   ~ 0
MIDI_OUT
Text Label 4600 2000 0    50   ~ 0
BUTTON
Text Label 4600 2100 0    50   ~ 0
LED1
Text Label 4600 2200 0    50   ~ 0
LED2
Text Label 4600 2300 0    50   ~ 0
LED3
Text Label 4600 2400 0    50   ~ 0
LED4
Text Label 4600 2500 0    50   ~ 0
DIN
Text Label 4600 2600 0    50   ~ 0
DOUT
Text Label 4600 2700 0    50   ~ 0
DSP_RST
Text Label 4600 2800 0    50   ~ 0
CS
Text Label 4600 2900 0    50   ~ 0
MOSI
Text Label 4600 3000 0    50   ~ 0
MISO
Wire Wire Line
	6400 1750 7000 1750
Wire Wire Line
	6400 1950 7000 1950
Wire Wire Line
	6400 2150 7000 2150
Wire Wire Line
	6400 2250 7000 2250
Wire Wire Line
	6400 2350 7000 2350
Wire Wire Line
	6400 2450 7000 2450
Wire Wire Line
	6400 2550 7000 2550
Wire Wire Line
	6400 2650 7000 2650
Wire Wire Line
	6400 2750 7000 2750
Wire Wire Line
	6400 2850 7000 2850
Wire Wire Line
	6400 2950 7000 2950
Wire Wire Line
	6400 3050 7000 3050
Text Label 6550 1750 0    50   ~ 0
VIN
Text Label 6550 1850 0    50   ~ 0
GND
Text Label 6550 1950 0    50   ~ 0
3.3V
Text Label 6550 2150 0    50   ~ 0
DSP_C_S
Text Label 6550 2250 0    50   ~ 0
BCLK
Text Label 6550 2350 0    50   ~ 0
LRCLK
Text Label 6550 2450 0    50   ~ 0
SCL
Text Label 6550 2550 0    50   ~ 0
SDA
Text Label 6550 2650 0    50   ~ 0
ENC_A
Text Label 6550 2750 0    50   ~ 0
ENC_B
Text Label 6550 2850 0    50   ~ 0
LO_POT
Text Label 6550 2950 0    50   ~ 0
UP_POT
Text Label 6550 3050 0    50   ~ 0
SCK
Wire Wire Line
	1050 1750 1050 1850
Wire Wire Line
	1050 1750 1900 1750
$Comp
L power:GND #PWR0101
U 1 1 5F61D323
P 1050 1850
F 0 "#PWR0101" H 1050 1600 50  0001 C CNN
F 1 "GND" H 1055 1677 50  0000 C CNN
F 2 "" H 1050 1850 50  0001 C CNN
F 3 "" H 1050 1850 50  0001 C CNN
	1    1050 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 1850 4000 1950
Wire Wire Line
	3050 1850 4000 1850
$Comp
L power:GND #PWR0102
U 1 1 5F61F06B
P 4000 1950
F 0 "#PWR0102" H 4000 1700 50  0001 C CNN
F 1 "GND" H 4005 1777 50  0000 C CNN
F 2 "" H 4000 1950 50  0001 C CNN
F 3 "" H 4000 1950 50  0001 C CNN
	1    4000 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1700 4400 1800
Wire Wire Line
	4400 1700 5100 1700
$Comp
L power:GND #PWR0103
U 1 1 5F620B10
P 4400 1800
F 0 "#PWR0103" H 4400 1550 50  0001 C CNN
F 1 "GND" H 4405 1627 50  0000 C CNN
F 2 "" H 4400 1800 50  0001 C CNN
F 3 "" H 4400 1800 50  0001 C CNN
	1    4400 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 1850 7250 1950
Wire Wire Line
	6400 1850 7250 1850
$Comp
L power:GND #PWR0104
U 1 1 5F62275E
P 7250 1950
F 0 "#PWR0104" H 7250 1700 50  0001 C CNN
F 1 "GND" H 7255 1777 50  0000 C CNN
F 2 "" H 7250 1950 50  0001 C CNN
F 3 "" H 7250 1950 50  0001 C CNN
	1    7250 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5F63A646
P 4200 3450
F 0 "R1" V 3993 3450 50  0000 C CNN
F 1 "100" V 4084 3450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4130 3450 50  0001 C CNN
F 3 "~" H 4200 3450 50  0001 C CNN
	1    4200 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 3450 1050 3450
Wire Wire Line
	1050 3450 1050 2950
Wire Wire Line
	1050 2950 1900 2950
Wire Wire Line
	7150 2050 7150 3450
Wire Wire Line
	7150 3450 4350 3450
Wire Wire Line
	6400 2050 7150 2050
$EndSCHEMATC
