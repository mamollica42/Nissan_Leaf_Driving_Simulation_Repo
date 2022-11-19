SPEEDOMETER SUBSYSTEM
--------------------
### Functions of the Subsystem
The speedometer subsystem must receive output from the current driving simulation and display the speed the user is going. A microcontroller will be used to pull the speed data from the MATLAB code and display it on 4-digit a 7-segment display.
### Specifications & Constraints
-	Microcontroller must be compatible with MATLAB
-	Must be able to display the speed at which the user is going in the simulator
-	Shall connect to the PC running the simulation
-	Shall display the speed in real-time
-	Shall be powered by the PC	
### Schematic
##### 1. Pinouts

![image](https://user-images.githubusercontent.com/117474540/202864081-4325652c-c3de-4a34-bf38-b649f1cd59cb.png)

_Figure 1. Pinout of Arduino Uno_

![image](https://user-images.githubusercontent.com/117474540/202864050-6e376c04-8fbd-40f2-bc74-d78c4ec03fb3.png)

_Figure 2. Pinout of TM1637 4-digit 7-segment display_

##### 2. Wiring Schematic

![image](https://user-images.githubusercontent.com/117474540/202863610-1f4f66dd-5dce-49d9-b17f-d742b2c2202e.png)

_Figure 3. Wiring diagram for the Arduino Uno and 4-digit 7-segment display_

### Analysis
#### Microcontroller Selection

The Arduino UNO REV3 is clocked at 16 MHz, has 6 analog I/O pins, and 14 digital I/O pins. The board can be powered via battery, USB, or the VDD pin and can operate within a voltage range of 7-12 V. Each GPIO pin can supply up to 40 mA. The board can directly communicate with the PC via serial communication and is MATLAB compatible. This would allow the speed data to be continuously sent to the board in real time.

#### LED Display Selection

The TM1637 4-digit 7-segment display has 4 connection pins that are used to show a numerical number. Two pins are used for power, one pin is used for the clock, and the other pin is used for the digital signal. The display can operate at 3.3-5 V and can draw up to 80 mA.  By looking at Figure 3, pin 3 of the Arduino will be used for the clock, and pin 2 will be used to send the digital signal. The 5 V pin will be used for the power supply and the GND pin will be used for ground. Arduino has a TM1637 library with built in functions that would allow for streamlined operation of the display.

#### Mounting

The recommended max distance of a USB 2.0 cable is 16 feet. The PC running the simulator will be within 16 feet of the car so mounting the LED display in the desired position shall have no effect on transmission speeds.

### BOM

| Part        | Price    |
|:-----------:|:--------:|
| Arduino     | $27.60  |
| USB 2.0     | $ 7.60   |
| Jumper Wires | $5.00   |
| TOTAL       | $40.20   |
