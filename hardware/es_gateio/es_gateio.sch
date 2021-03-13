EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "ES Gate I/O"
Date "2021-03-12"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x06 J1
U 1 1 60608272
P 2300 1850
F 0 "J1" H 2380 1842 50  0000 L CNN
F 1 "MOD_IN" H 2380 1751 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 2300 1850 50  0001 C CNN
F 3 "~" H 2300 1850 50  0001 C CNN
	1    2300 1850
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J2
U 1 1 60609C5A
P 2300 4550
F 0 "J2" H 2380 4542 50  0000 L CNN
F 1 "MOD_OUT" H 2380 4451 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 2300 4550 50  0001 C CNN
F 3 "~" H 2300 4550 50  0001 C CNN
	1    2300 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 6060AA8E
P 1950 2300
F 0 "#PWR04" H 1950 2050 50  0001 C CNN
F 1 "GND" H 1955 2127 50  0000 C CNN
F 2 "" H 1950 2300 50  0001 C CNN
F 3 "" H 1950 2300 50  0001 C CNN
	1    1950 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 6060AAD5
P 1950 5000
F 0 "#PWR06" H 1950 4750 50  0001 C CNN
F 1 "GND" H 1955 4827 50  0000 C CNN
F 2 "" H 1950 5000 50  0001 C CNN
F 3 "" H 1950 5000 50  0001 C CNN
	1    1950 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 4850 1950 4850
Wire Wire Line
	1950 4850 1950 5000
Wire Wire Line
	2100 2150 1950 2150
Wire Wire Line
	1950 2150 1950 2300
$Comp
L power:+3.3V #PWR03
U 1 1 6060C530
P 1950 1500
F 0 "#PWR03" H 1950 1350 50  0001 C CNN
F 1 "+3.3V" H 1965 1673 50  0000 C CNN
F 2 "" H 1950 1500 50  0001 C CNN
F 3 "" H 1950 1500 50  0001 C CNN
	1    1950 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1650 1950 1650
Wire Wire Line
	1950 1650 1950 1500
$Comp
L power:+5V #PWR02
U 1 1 6060D877
P 1600 4200
F 0 "#PWR02" H 1600 4050 50  0001 C CNN
F 1 "+5V" H 1615 4373 50  0000 C CNN
F 2 "" H 1600 4200 50  0001 C CNN
F 3 "" H 1600 4200 50  0001 C CNN
	1    1600 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 4750 1600 4750
Wire Wire Line
	1600 4750 1600 4200
Wire Wire Line
	2100 1750 1150 1750
Wire Wire Line
	2100 1850 1150 1850
Wire Wire Line
	2100 1950 1150 1950
Wire Wire Line
	2100 4450 1150 4450
Wire Wire Line
	2100 4550 1150 4550
Wire Wire Line
	2100 4650 1150 4650
Text Label 1150 1750 0    50   ~ 0
DIN
Text Label 1150 1850 0    50   ~ 0
JIN_T
Text Label 1150 1950 0    50   ~ 0
JIN_TN
Text Label 1150 4450 0    50   ~ 0
DOUT
Text Label 1150 4550 0    50   ~ 0
JOUT_T
Text Label 1150 4650 0    50   ~ 0
JOUT_TN
NoConn ~ 1150 4650
Wire Wire Line
	1150 1950 1150 2150
Wire Wire Line
	1150 2150 1950 2150
Connection ~ 1950 2150
$Comp
L Device:R R1
U 1 1 6061086D
P 3900 2000
F 0 "R1" V 3693 2000 50  0000 C CNN
F 1 "47k" V 3784 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3830 2000 50  0001 C CNN
F 3 "~" H 3900 2000 50  0001 C CNN
	1    3900 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 60610F79
P 4600 2300
F 0 "R2" H 4530 2254 50  0000 R CNN
F 1 "47k" H 4530 2345 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4530 2300 50  0001 C CNN
F 3 "~" H 4600 2300 50  0001 C CNN
	1    4600 2300
	-1   0    0    1   
$EndComp
$Comp
L Device:R R3
U 1 1 606114C3
P 4950 1500
F 0 "R3" H 5020 1546 50  0000 L CNN
F 1 "10k" H 5020 1455 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4880 1500 50  0001 C CNN
F 3 "~" H 4950 1500 50  0001 C CNN
	1    4950 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:D D1
U 1 1 60611BBF
P 4350 2000
F 0 "D1" H 4350 1784 50  0000 C CNN
F 1 "1N4148" H 4350 1875 50  0000 C CNN
F 2 "Diode_SMD:D_MiniMELF" H 4350 2000 50  0001 C CNN
F 3 "~" H 4350 2000 50  0001 C CNN
	1    4350 2000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 60617E31
P 4600 2600
F 0 "#PWR07" H 4600 2350 50  0001 C CNN
F 1 "GND" H 4605 2427 50  0000 C CNN
F 2 "" H 4600 2600 50  0001 C CNN
F 3 "" H 4600 2600 50  0001 C CNN
	1    4600 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 6061866C
P 4950 2600
F 0 "#PWR09" H 4950 2350 50  0001 C CNN
F 1 "GND" H 4955 2427 50  0000 C CNN
F 2 "" H 4950 2600 50  0001 C CNN
F 3 "" H 4950 2600 50  0001 C CNN
	1    4950 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2000 3350 2000
Wire Wire Line
	4050 2000 4200 2000
Wire Wire Line
	4500 2000 4600 2000
Wire Wire Line
	4600 2150 4600 2000
Connection ~ 4600 2000
Wire Wire Line
	4600 2000 4650 2000
Wire Wire Line
	4600 2450 4600 2600
Wire Wire Line
	4950 2200 4950 2600
Wire Wire Line
	4950 1800 4950 1750
$Comp
L power:+3.3V #PWR08
U 1 1 6061AE0F
P 4950 1200
F 0 "#PWR08" H 4950 1050 50  0001 C CNN
F 1 "+3.3V" H 4965 1373 50  0000 C CNN
F 2 "" H 4950 1200 50  0001 C CNN
F 3 "" H 4950 1200 50  0001 C CNN
	1    4950 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 1200 4950 1350
Wire Wire Line
	4950 1750 5750 1750
Connection ~ 4950 1750
Wire Wire Line
	4950 1750 4950 1650
Text Label 3350 2000 0    50   ~ 0
JIN_T
Text Label 5600 1750 0    50   ~ 0
DIN
$Comp
L Device:R R4
U 1 1 60623EE1
P 4300 4650
F 0 "R4" V 4093 4650 50  0000 C CNN
F 1 "10k" V 4184 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4230 4650 50  0001 C CNN
F 3 "~" H 4300 4650 50  0001 C CNN
	1    4300 4650
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 60625266
P 5350 4300
F 0 "R6" V 5143 4300 50  0000 C CNN
F 1 "1k" V 5234 4300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5280 4300 50  0001 C CNN
F 3 "~" H 5350 4300 50  0001 C CNN
	1    5350 4300
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 606261BE
P 4950 4000
F 0 "R5" H 4880 3954 50  0000 R CNN
F 1 "47k" H 4880 4045 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4880 4000 50  0001 C CNN
F 3 "~" H 4950 4000 50  0001 C CNN
	1    4950 4000
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 6062B325
P 4950 3700
F 0 "#PWR0101" H 4950 3550 50  0001 C CNN
F 1 "+5V" H 4965 3873 50  0000 C CNN
F 2 "" H 4950 3700 50  0001 C CNN
F 3 "" H 4950 3700 50  0001 C CNN
	1    4950 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3700 4950 3850
Wire Wire Line
	4950 4150 4950 4300
Wire Wire Line
	5200 4300 4950 4300
Connection ~ 4950 4300
Wire Wire Line
	4950 4300 4950 4450
Wire Wire Line
	5500 4300 6050 4300
Wire Wire Line
	4150 4650 3550 4650
Text Label 3550 4650 0    50   ~ 0
DOUT
Text Label 5750 4300 0    50   ~ 0
JOUT_T
$Comp
L power:GND #PWR0102
U 1 1 6062EB2E
P 4950 5000
F 0 "#PWR0102" H 4950 4750 50  0001 C CNN
F 1 "GND" H 4955 4827 50  0000 C CNN
F 2 "" H 4950 5000 50  0001 C CNN
F 3 "" H 4950 5000 50  0001 C CNN
	1    4950 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4850 4950 5000
Wire Wire Line
	4450 4650 4650 4650
$Comp
L Transistor_BJT:MMBT3904 Q2
U 1 1 606350FF
P 4850 4650
F 0 "Q2" H 5041 4696 50  0000 L CNN
F 1 "MMBT3904" H 5041 4605 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5050 4575 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4850 4650 50  0001 L CNN
	1    4850 4650
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q1
U 1 1 60638A13
P 4850 2000
F 0 "Q1" H 5041 2046 50  0000 L CNN
F 1 "MMBT3904" H 5041 1955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5050 1925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4850 2000 50  0001 L CNN
	1    4850 2000
	1    0    0    -1  
$EndComp
NoConn ~ 2100 2050
NoConn ~ 2100 4350
$EndSCHEMATC
