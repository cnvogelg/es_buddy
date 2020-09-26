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
$Comp
L Connector_Generic:Conn_01x08 J3
U 1 1 5F6FC656
P 2100 3950
F 0 "J3" H 2180 3942 50  0000 L CNN
F 1 "OLED" H 2180 3851 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2100 3950 50  0001 C CNN
F 3 "~" H 2100 3950 50  0001 C CNN
	1    2100 3950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x10 J4
U 1 1 5F6FD99A
P 4100 4000
F 0 "J4" H 4180 3992 50  0000 L CNN
F 1 "TFT" H 4180 3901 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical" H 4100 4000 50  0001 C CNN
F 3 "~" H 4100 4000 50  0001 C CNN
	1    4100 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 3650 1400 3650
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
	3900 3800 3300 3800
Wire Wire Line
	3900 3900 3300 3900
Wire Wire Line
	3900 4000 3300 4000
Wire Wire Line
	3900 4100 3300 4100
Wire Wire Line
	3900 4200 3300 4200
Wire Wire Line
	3900 4300 3300 4300
Wire Wire Line
	3900 4400 3300 4400
Text Label 1400 3650 0    50   ~ 0
3.3V
Text Label 1400 3750 0    50   ~ 0
GND
NoConn ~ 1400 3850
Text Label 1400 3950 0    50   ~ 0
MOSI
Text Label 1400 4050 0    50   ~ 0
SCK
Text Label 1400 4150 0    50   ~ 0
CS
Text Label 1400 4250 0    50   ~ 0
DSP_C_S
Text Label 1400 4350 0    50   ~ 0
DSP_RST
Text Label 3300 3600 0    50   ~ 0
GND
Text Label 3300 3700 0    50   ~ 0
3.3V
Text Label 3300 3800 0    50   ~ 0
DSP_RST
Text Label 3300 3900 0    50   ~ 0
DSP_C_S
NoConn ~ 3300 4000
Text Label 3300 4100 0    50   ~ 0
CS
Text Label 3300 4200 0    50   ~ 0
MOSI
Text Label 3300 4300 0    50   ~ 0
SCK
Text Label 3300 4400 0    50   ~ 0
MISO
Text Label 3300 4500 0    50   ~ 0
LITE
Wire Wire Line
	3100 4500 3100 3700
Wire Wire Line
	3100 3700 3900 3700
Wire Wire Line
	3100 4500 3900 4500
$Comp
L power:GND #PWR0103
U 1 1 5F71177F
P 2850 3700
F 0 "#PWR0103" H 2850 3450 50  0001 C CNN
F 1 "GND" H 2855 3527 50  0000 C CNN
F 2 "" H 2850 3700 50  0001 C CNN
F 3 "" H 2850 3700 50  0001 C CNN
	1    2850 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5F711CB4
P 1050 3850
F 0 "#PWR0104" H 1050 3600 50  0001 C CNN
F 1 "GND" H 1055 3677 50  0000 C CNN
F 2 "" H 1050 3850 50  0001 C CNN
F 3 "" H 1050 3850 50  0001 C CNN
	1    1050 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 3850 1050 3750
Wire Wire Line
	1050 3750 1900 3750
Wire Wire Line
	2850 3600 2850 3700
Wire Wire Line
	2850 3600 3900 3600
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
$EndSCHEMATC
