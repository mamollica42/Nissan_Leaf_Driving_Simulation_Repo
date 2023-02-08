Gear Shifter Subsystem
--------------------------------------
### Function of the Subsystem
The gear shifter subsystem will capture the OEM signal from the gear shifter sensor by splicing into the wiring and storing the signal on a local microcontroller. 
### Specifications & Constraints
-	Must use OEM gear shifter sensor
-	Must not have any exposed or loose wires according to NESC standard
-	Shall have 100% accuracy due to the capturing of the output signal of the OEM shifter sensor
-	Shall receive the OEM gear shifter signal on a local microcontroller
-	Must have local microcontroller that can be powered by a 12 V source
-	Must have local microcontroller that can communicate with the master MCU via UART communication
-	Must have local microcontroller that samples above or at 9.64 Hz which is the sampling rate of the OEM gear shifter sensor
-	Must have local microcontroller with at least 4 digital I/O pins to read the output signals coming from the OEM shifter signal
-	Must have wires capable of handling 5 V to read the output signal from the OEM shifter sensor

### Wiring Schematic

![image](https://user-images.githubusercontent.com/117474540/217615966-11a77825-dd9b-4a19-aa28-2a6a6862672c.png)

###### _Figure 1: Splicing OEM wiring to a local microcontroller

### Initial Approach
The reason for choosing the wire splicing is because it is the cheapest way to get an immersive experience for the driving simulator. Installing third party sensors could result in clutter around the gear shifter and inaccuracy of the system due to human interference or improper sensor installation. With wiring splicing, there will be no excess sensors and clutter, and the system will have 100% accuracy because the cars actual signal will be captured and stored. The signal will be stored on a local microcontroller and then sent to the master microcontroller. The local microcontroller will read the 5 or 0 V signal from the wires and send what gear the car is in to the master microcontroller. This will be done with C code. The reason for the local microcontroller is to not bog down one massive microcontroller and potentially slow down processing speeds. 

For wire splicing to be effective, the signals coming from the wires of the gear shifter sensor would still need to be accurate even with the back half of the car being cut off.  As of now, the car can only go into park and neutral. To see if the car can go into drive and reverse, more testing was needed to see if the sensor still could send the appropriate output signal even if the car could not go into the desired gear. To test this, male to female jumper wires, an oscilloscope, and a DMM was used. A wiring diagram online was found with specific gears labeled corresponding to the PIN and color wire. Before testing, the colors and pins were confirmed, so all that was left was to see if the shifter worked without the back half of the car and to confirm that the gears matched the pins.

![image](https://user-images.githubusercontent.com/117474540/214118110-98df866a-9546-4820-9726-7ace77302a40.png)

###### _Figure 2: Measuring the voltage of the output signals coming from the gear shifter sensor

## Analysis

### Testing
After measuring the voltages and changing the gears in the car, it was determined that system is an active low system. This was done by using a DMM to measure the output signals coming from the OEM gear shifter sensor. The red lead was connected to a pin and the black lead was connected to ground. Whenever the gear in the car was changed, the wire corresponding to the gear when from 5 V down to 0 V until you let go of the shifter position. Then it returned back to 5 V. This allowed for the conclusion of the signal being a digital signal [1]. Out of the 12 pins coming from the sensor, it was determined that pins 2, 3, 9, and 11 were able to represent the 4 gears of the car. The local microcontroller would need 4 digital I/O pins to detect the signal from the 4 pins of the sensor. Even though the car could not be put into drive and reverse, the gear shifter would still send an appropriate signal if you moved the shifter accordingly. The car would resort to neutral if you tried to put it in reverse or drive, but the sensor still worked properly. Due to this, wire splicing would be sufficient for sensing what gear the user is selecting.

### Nyquist
For the signal to be read properly by the local microcontroller, the Nyquist rate of the OEM shifter sensor needs to be determined to eliminate aliasing in reading the signal. This was done by using an oscilloscope to detect the fastest fall and rise of the signal created by the user coming from the OEM sensor. After measuring this, it was concluded that the normal frequency is 4.82 Hz. The Nyquist rate is double the normal frequency. This makes the Nyquist rate of the OEM shifter sensor 9.64 Hz. This means that the local microcontroller must have a sampling rate of 9.64 Hz or greater to have accurate readings.

![image](https://user-images.githubusercontent.com/117474540/216787104-d54d6424-3914-43a2-ac9b-0463fb6eaf0f.png)

###### _Figure 3: Measuring the falling edge of the output signal coming from the gear shifter sensor

### Microcontroller Selection
The Arduino UNO REV3 is clocked at 16 MHz, has 6 analog I/O pins, 14 digital I/O pins, and can communicate with other Arduinos via UART communication. The board can be powered via battery, USB, or the VDD pin and can operate within a voltage range of 7-12 V. The power subsystem will supply the UNO with 12 V. The master MCU is an Arduino Mega, so the Arduino Uno can communicate with it via UART communication. The sampling rate of a digital I/O pin from the Arduino Uno is 8 MHz, so the constraint of the Nyquist rate of 9.64 Hz or greater is met. The microcontroller has at least 4 digital I/O pins, so the 4 pins of the OEM sensor can be read. The max input voltage into a digital I/O port is 5.5 V, so voltage protection will be needed to ensure that this threshold will not be crossed. Since a digital I/O port does not draw or sink more current than it can handle, current protection will not be needed. 

![image](https://user-images.githubusercontent.com/117474540/216136883-7d28a09f-101c-4502-a12e-633c129e9a33.png)

###### _Figure 4: Spice Diagram of Protection Circuit

Since the the max input voltage into a digital I/O port is 5.5 V, four 100 Ω resistors and four zener diodes with a breakdown voltage of 5.1 V will be used to protect the the microcontroller in case of a voltage spike. Once the breakdown voltage of the zener diode is reached, it will short circuit to neutral until the voltage is below the threshold of 5.1 V. This means that a voltage greater than 5.5 V cannot reach the microcontroller.

![image](https://user-images.githubusercontent.com/117474540/215919854-223f294b-a3c7-4141-a173-09ad79c67937.png)

###### _Figure 5: Output Voltage of Circuit with an Input Voltage of 15 V

### Wire and Splicer Selection
Since the wires will be only handling 5 V, any sized wire could be used to carry the gear shifter's signal to the local microcontroller. 22 gauge wire will be used to splice into the OEM wires. 22 gauge wire is capable of handling 7 A, so it is more than capable of handling a digital voltage signal [2]. The wires will be relatively close to the Arduino, so it will not play any noticeable part in slowing the sensing capabilities of the MCU. 

### BOM

| Part                         | Price    |
|:----------------------------:|:--------:|
| Dorman 22-18 Splicers 7 Pact | $4.49    |
| 22 Gauge Wire                | $14.99   |
| Arduino Uno                  | $25.00   |
| Solderable Breadboard        | $6.00    |
|Diodes                        | $3.00    |
| 100 Ω Resistors              | $1.00    |
| Total                        | $51.48   |

### REFERENCES
[1] https://www.allaboutcircuits.com/textbook/direct-current/chpt-9/current-signal-systems/#:~:text=The%20most%20common%20current%20signal%20standard%20in%20modern,12%20milliamps%20representing%2050%20percent%2C%20and%20so%20on.

[2] https://www.rvandplaya.com/what-is-22-gauge-wire-used-for/
