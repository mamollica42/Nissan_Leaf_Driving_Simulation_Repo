SPEEDOMETER SUBSYSTEM
--------------------
### Functions of the Subsystem
The speedometer subsystem must receive output from the current driving simulation and display the speed the user is going. A microcontroller will be used to pull the speed data from the MATLAB code and display it on a LCD screen.
### Specifications & Constraints
-	Microcontroller must be able to read data from MATLAB
-	Shall connect to the PC running the simulation to obtain simulator data
-	Shall display the speed at a refresh rate no slower than 100 ms	

The refresh rate of less than 100 ms was chosen based off the acceptable latency of modern video games being between 20 ms and 100 ms [1]. Since human reaction time is around 200 ms, this refresh rate would be undetectable by the user of the simulation.
### Schematic
##### 1. Wiring Schematic

![image](https://user-images.githubusercontent.com/117474540/205458447-3d4bf94d-3a07-4027-b8cf-cc1fce28f2ab.png)

_Figure 1. Wiring schematic for the Arduino Uno and the 3.5 Inch TFT Color LCD Screen 

### Analysis
-The 3.5 Inch TFT Color LCD Screen is designed to fit on an Arduino Uno. The UNO has proper connectivity via GPIO to the point where the user snaps the LCD screen on top of the UNO.

-Arduino Boards can read outputs directly from MATLAB. With the Arduino UNO REV3 being clocked at 16 MHz, the constraint of a refresh rate no slower than 100 ms can easily be met.

-The board will directly connect to the PC via USB 2.0 for long distance power and data transfer.

#### Microcontroller Selection

The Arduino UNO REV3 is clocked at 16 MHz, has 6 analog I/O pins, and 14 digital I/O pins. The board can be powered via battery, USB, or the VDD pin and can operate within a voltage range of 7-12 V. Each GPIO pin can supply up to 40 mA. The board can directly communicate with the PC via serial communication and can read data directly from MATLAB. This would allow the speed data to be continuously sent to the board with a refresh rate lower than 100 ms.

#### LCD Display Selection

The The 3.5 Inch TFT Color LCD Screen has 24 GPIO pins and can directly snap onto an Arduino UNO REV3. The 3.5" LCD screen can be programmed to display whatever the user wants and is plenty big enough to display the speed data from the simulation. With a module display area that contains 320x480 pixels, the team can add extra embellishments onto the screen to make the speed data that is displayed feel more appropriate to the car. With only one wire coming out of the display and Arduino, the LCD will not stand out and will feel appropriate to the interior of the car.

#### Mounting

The recommended max distance of a USB 2.0 cable is 16 feet. The PC running the simulator will be within 16 feet of the car so mounting the LED display in the desired position shall have no effect on transmission speeds.

### BOM

| Part        | Price    |
|:-----------:|:--------:|
| Arduino     | $27.60  |
| USB 2.0     | $ 7.60   |
| TFT Color LCD | $ 19.00|
| TOTAL       | $54.20   |

### REFERENCES

[1] https://www.bandwidthplace.com/the-importance-of-latency-in-online-gaming/

