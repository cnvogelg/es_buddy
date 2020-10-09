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
	1400 2950 1900 2950
NoConn ~ 1400 1850
NoConn ~ 1400 1950
NoConn ~ 1400 2050
NoConn ~ 1400 2150
NoConn ~ 1400 2250
NoConn ~ 1400 2350
NoConn ~ 1400 2450
NoConn ~ 1400 2750
NoConn ~ 1400 2950
NoConn ~ 3650 1750
NoConn ~ 3650 2050
NoConn ~ 3650 2150
NoConn ~ 3650 2250
NoConn ~ 3650 2350
NoConn ~ 3650 2450
NoConn ~ 3650 2550
NoConn ~ 3650 2650
NoConn ~ 3650 2750
NoConn ~ 3650 3050
$Comp
L Connector_Generic:Conn_01x14 J3
U 1 1 5F8163A4
P 2100 4350
F 0 "J3" H 2050 5200 50  0000 L CNN
F 1 "T3_Left_B" H 2050 5100 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical_NoSilk" H 2100 4350 50  0001 C CNN
F 3 "~" H 2100 4350 50  0001 C CNN
	1    2100 4350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x14 J4
U 1 1 5F8163AA
P 2850 4350
F 0 "J4" H 2768 5167 50  0000 C CNN
F 1 "T3_Right_B" H 2768 5076 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical_NoSilk_NoPin1" H 2850 4350 50  0001 C CNN
F 3 "~" H 2850 4350 50  0001 C CNN
	1    2850 4350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1900 3850 1400 3850
Wire Wire Line
	1900 3950 1400 3950
Wire Wire Line
	1900 4050 1400 4050
Wire Wire Line
	1900 4150 1400 4150
Wire Wire Line
	1900 4250 1400 4250
Wire Wire Line
	1900 4350 1400 4350
Wire Wire Line
	1900 4450 1400 4450
Wire Wire Line
	1900 4550 1400 4550
Wire Wire Line
	1900 4650 1400 4650
Wire Wire Line
	1900 4750 1400 4750
Wire Wire Line
	1900 4850 1400 4850
Wire Wire Line
	1900 5050 1400 5050
Wire Wire Line
	3050 3750 3650 3750
Wire Wire Line
	3050 3950 3650 3950
Wire Wire Line
	3050 4050 3650 4050
Wire Wire Line
	3050 4150 3650 4150
Wire Wire Line
	3050 4250 3650 4250
Wire Wire Line
	3050 4350 3650 4350
Wire Wire Line
	3050 4450 3650 4450
Wire Wire Line
	3050 4550 3650 4550
Wire Wire Line
	3050 4650 3650 4650
Wire Wire Line
	3050 4750 3650 4750
Wire Wire Line
	3050 4850 3650 4850
Wire Wire Line
	3050 4950 3650 4950
Wire Wire Line
	3050 5050 3650 5050
Text Label 1400 3750 0    50   ~ 0
GND
Text Label 1400 3850 0    50   ~ 0
MIDI_IN
Text Label 1400 3950 0    50   ~ 0
MIDI_OUT
Text Label 1400 4050 0    50   ~ 0
BUTTON
Text Label 1400 4150 0    50   ~ 0
LED1
Text Label 1400 4250 0    50   ~ 0
LED2
Text Label 1400 4350 0    50   ~ 0
LED3
Text Label 1400 4450 0    50   ~ 0
LED4
Text Label 1400 4550 0    50   ~ 0
MOSI
Text Label 1400 4650 0    50   ~ 0
DSP_RST
Text Label 1400 4750 0    50   ~ 0
BCLK
Text Label 1400 4850 0    50   ~ 0
CS
Text Label 1400 4950 0    50   ~ 0
MCLK
Text Label 1400 5050 0    50   ~ 0
MISO
Text Label 3200 3750 0    50   ~ 0
VIN
Text Label 3200 3850 0    50   ~ 0
GND
Text Label 3200 3950 0    50   ~ 0
3.3V
Text Label 3200 4050 0    50   ~ 0
LRCLK
Text Label 3200 4150 0    50   ~ 0
DIN
Text Label 3200 4250 0    50   ~ 0
LO_POT
Text Label 3200 4350 0    50   ~ 0
UP_POT
Text Label 3200 4450 0    50   ~ 0
SCL
Text Label 3200 4550 0    50   ~ 0
SDA
Text Label 3200 4650 0    50   ~ 0
ENC_A
Text Label 3200 4750 0    50   ~ 0
ENC_B
Text Label 3200 4850 0    50   ~ 0
DSP_C_S
Text Label 3200 4950 0    50   ~ 0
SCK
Text Label 3200 5050 0    50   ~ 0
DOUT
Wire Wire Line
	1050 3750 1050 3850
Wire Wire Line
	1050 3750 1900 3750
$Comp
L power:GND #PWR?
U 1 1 5F8163E7
P 1050 3850
F 0 "#PWR?" H 1050 3600 50  0001 C CNN
F 1 "GND" H 1055 3677 50  0000 C CNN
F 2 "" H 1050 3850 50  0001 C CNN
F 3 "" H 1050 3850 50  0001 C CNN
	1    1050 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3850 4000 3950
Wire Wire Line
	3050 3850 4000 3850
$Comp
L power:GND #PWR?
U 1 1 5F8163EF
P 4000 3950
F 0 "#PWR?" H 4000 3700 50  0001 C CNN
F 1 "GND" H 4005 3777 50  0000 C CNN
F 2 "" H 4000 3950 50  0001 C CNN
F 3 "" H 4000 3950 50  0001 C CNN
	1    4000 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 4950 1900 4950
NoConn ~ 1400 3850
NoConn ~ 1400 3950
NoConn ~ 1400 4050
NoConn ~ 1400 4150
NoConn ~ 1400 4250
NoConn ~ 1400 4350
NoConn ~ 1400 4450
NoConn ~ 1400 4750
NoConn ~ 1400 4950
NoConn ~ 3650 3750
NoConn ~ 3650 4050
NoConn ~ 3650 4150
NoConn ~ 3650 4250
NoConn ~ 3650 4350
NoConn ~ 3650 4450
NoConn ~ 3650 4550
NoConn ~ 3650 4650
NoConn ~ 3650 4750
NoConn ~ 3650 5050
$EndSCHEMATC
