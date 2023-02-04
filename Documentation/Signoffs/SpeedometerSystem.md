SPEEDOMETER SUBSYSTEM
--------------------
### Functions of the Subsystem
The speedometer subsystem must receive output from the driving simulation and display the speed the user is going. A microcontroller will be used to export the speed data from the simulator and display it on a screen inside the car.
### Specifications & Constraints
- Data must exit the PC running the simulator
-	Microcontroller must be able to read speed data from the simulator while it is running
-	Shall be powered by the PC running the simulator
-	Shall display the speed data in an appropriate manner inside the car

### Schematic
##### 1. Screen to Microcontroller Connection

![image](https://user-images.githubusercontent.com/117474540/205758564-ffde40c5-9775-4cfe-a78d-28c376bdf988.png)

_Figure 1. A photograph of the LCD snapping onto the Arduino Uno [1]

##### 2. Wiring Schematic

![image](https://user-images.githubusercontent.com/117474540/216127475-511a63b1-875b-450a-8510-a35084af7384.png)

_Figure 2. Schematic for the 3.5 Inch TFT Color LCD Screen Plugging into the Arduino Uno

### Analysis

#### Microcontroller Selection

The Arduino UNO REV3 is clocked at 16 MHz, has 6 analog I/O pins, and 14 digital I/O pins. The board can be powered via battery, USB, or the VDD pin and can operate within a voltage range of 7-12 V. Arduino can directly communicate with the simulator that runs on MATLAB via serial communication with a USB 2.0. For the simulator to send data to the Arduino, serial.write() functions will be inserted into the simulator code to continuously send speed data to the Arduino. For the Arduino to receive and display the speed data, serial.read() functions will be used. Once the speed data is obtained, it will be appropriately displayed on a screen inside the car. This would allow for the speed data to be on the Arduino Uno in a programming language other than MATLAB which confirms the constraint of the data exiting the simulator. The Arduino will be powered by the PC running the simulator. 

#### LCD Display Selection

The The 3.5 Inch TFT Color LCD Screen has 28 pins and can directly snap onto an Arduino UNO REV3. The 3.5" LCD screen can be programmed to display whatever the user wants and is plenty big enough to display the speed data from the simulation. With a module display area that contains 320x480 pixels, the team can add extra embellishments onto the screen to make the speed data that is displayed feel more appropriate to the car.

#### Mounting

The recommended max distance of a USB 2.0 cable is 16 feet. The PC running the simulator will be within 16 feet of the car so mounting the LED display in the desired position shall have no effect on transmission speeds. To keep the the immersive feel of the inside of the car, the LCD will be mounted exactly where the current speedometer display is located. The stock display will be removed and be replaced with a new mount that will mimic the current one. The new one will of be able to communicate with MATLAB and pull the speed data from the simulator.

![image](https://user-images.githubusercontent.com/117474540/215832669-89579faa-cde7-400d-ae63-a6a877984600.png)

_Figure 3. The mounting for the Uno in the Car 

![image](https://user-images.githubusercontent.com/117474540/215867130-0e203977-f486-433f-9da6-c88cc64bec3f.png)

_Figure 4. The face plate for the mount

The back of the mount will be screwed in to replace the old speedometer display. The face plate will allow for only the LCD screen to be seen by the user of the simulator and will be screwed directly where the old speedometer display was located. All of this should allow for immersive experience for the simulator by not creating an eye sore that sticks out from the rest of the car. The green pieces from the above digrams will be 3D printed in black to blend in with the rest of the components in the car. The pink piece is the Arduino and the yellow piece is the display.

### BOM

| Part        | Price    |
|:-----------:|:--------:|
| Arduino     | $27.60  |
| USB 2.0     | $ 7.60   |
| TFT Color LCD | $ 19.00|
| TOTAL       | $54.20   |

### REFERENCES
[1] https://www.amazon.com/Treedix-Display-Screen-Arduino-Mega2560/dp/B0872S57HG

