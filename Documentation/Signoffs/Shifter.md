Gear Shifter Subsystem
--------------------------------------
### Function of the Subsystem
The gear shifter subsystem will capture the OEM signal from the gear shifter sensor by splicing into the wiring and storing the signal on a local microcontroller. 
### Specifications & Constraints
-	C1. Must use OEM gear shifter sensor
-	C2. OEM shifter sensor must send a detectable output signal for the shifter positions park, neutral, drive, and reverse.
-	C3. Shall receive the OEM gear shifter signal on a local microcontroller
-	C4. Must have local microcontroller that can be powered by a 12 V source
-	C5. Must have local microcontroller that can communicate with the master MCU via UART communication
-	C6. Must have local microcontroller that samples above or at twice the the measured normal frequency of 4.82 Hz from OEM gear shifter sensor to satisfy the Nyquist rate
-	C7. Must have local microcontroller capable of reading the measured 5 V digital output signal from the OEM shifter sensor
-	C8. Must have local microcontroller with at least 4 digital I/O pins to read the output signals coming from the OEM shifter signal
-	C9. Must have wires capable of handling 5 V to read the output signal from the OEM shifter sensor
-	C10. Must comply with IEEE 576-13 section on splicing wires and having loose wires.

### Wiring Schematic

![image](https://user-images.githubusercontent.com/117474540/218537096-3f4c387f-c6f8-4bcc-8415-3fbcfa5caa43.png)

###### _Figure 1: Splicing OEM wiring to a local microcontroller

### Testing 
For wire splicing to be effective, the signals coming from the wires of the gear shifter sensor would still need to be accurate even with the back half of the car being cut off.  As of now, the car can only go into park and neutral. To see if the car can go into drive and reverse, the OEM shifter sensor was tested was to see if the sensor still could send the appropriate output signal even if the car could not go into the desired gear. For testing, male to female jumper wires, an oscilloscope, and a DMM was used. The DMM was used to the voltage changes coming from the sensor and the oscilloscope was used to find the normal frequency of the voltage changes. The voltages measured on the DMM were 0 or 5 V.

![image](https://user-images.githubusercontent.com/117474540/214118110-98df866a-9546-4820-9726-7ace77302a40.png)

###### _Figure 2: Measuring the voltage of the output signals coming from the gear shifter sensor

## Analysis

### Nyquist
For the signal to be read properly by the local microcontroller, the Nyquist rate of the OEM shifter sensor needs to be determined to eliminate aliasing in reading the signal. This was done by using an oscilloscope to detect the fastest fall and rise of the signal created by the user coming from the OEM sensor. After measuring this, it was concluded that the normal frequency is 4.82 Hz. This value was found by using the oscilloscope's measurement tools. The Nyquist rate is double the normal frequency. This makes the Nyquist rate of the OEM shifter sensor 9.64 Hz. This means that the local microcontroller must have a sampling rate of 9.64 Hz or greater to have accurate readings.

![image](https://user-images.githubusercontent.com/117474540/218851650-a14fbdb5-8101-4e03-aa2f-a897401778ac.png)

###### _Figure 3: Measuring the falling edge of the OEM shifter signal going from 5 V to 0 V

![image](https://user-images.githubusercontent.com/117474540/218853925-beb80ac9-34bd-430e-97db-cd08230294b1.png)

###### _Figure 4: The measured values from the oscilloscope

### C1. Must use OEM gear shifter sensor
The output from the OEM shifter sensor is being captured so the sensor is being used.

### C2. OEM shifter sensor must send a detectable output signal for the shifter positions drive, park, reverse, and neutral
After measuring the voltages and changing the gears in the car, it was determined that system is an active low system. This was done by using a DMM to measure the output signals coming from the OEM gear shifter sensor. The red lead was connected to a pin and the black lead was connected to ground. Whenever the gear in the car was changed, the wire corresponding to the gear when from 5 V down to 0 V until you let go of the shifter position. Then it returned back to 5 V. This allowed for the conclusion of the signal being a digital signal [1]. Out of the 12 pins coming from the sensor, it was determined that pins 2, 3, 9, and 11 were able to represent park, neutral, drive, and reverse.

### C3. Shall receive the OEM gear shifter signal on a local microcontroller
The wires carrying the signal are being wire spliced to a microcontroller.

### C4. Must have local microcontroller that can be powered by a 12 V source
The Arduino Uno can be powered by a 12 V source unlike the Arduino Nano.

### C5. Must have local microcontroller that can communicate with the master MCU via UART communication
The master MCU is an Arduino Mega, so the Arduino Uno can communicate with it via UART communication.

### C6. Must have local microcontroller that samples above or at twice the the measured normal frequency of 4.82 Hz from OEM gear shifter sensor to satisfy the Nyquist rate
The sampling rate of a digital I/O pin from the Arduino Uno is 8 MHz, so the constraint of sampling at or above double the normal frequency of the OEM shifter sensor is met. A Nyquist rate of 9.64 Hz is easily met.

### C7. Must have local microcontroller capable of reading the measured 5 V digital output signal from the OEM shifter sensor
A digital port on the Arduino Uno can read up to a 5.5 V digital signal. Since the measured signal was 0 or 5 V, it was determined to be a digital signal [1].

![image](https://user-images.githubusercontent.com/117474540/218148902-82a6589f-edfd-4a09-9c5f-66c7c82917fb.png)

###### _Figure 5: Spice Diagram of Protection Circuit

Since the the max input voltage into a digital I/O port is 5.5 V, four 100 Ω resistors and four zener diodes with a breakdown voltage of 5.1 V will be used to protect the the microcontroller in case of a voltage spike. Once the breakdown voltage of the zener diode is reached, it will short circuit to neutral until the voltage is below the threshold of 5.1 V. This means that a voltage greater than 5.5 V cannot reach the microcontroller.

![image](https://user-images.githubusercontent.com/117474540/215919854-223f294b-a3c7-4141-a173-09ad79c67937.png)

###### _Figure 6: Output Voltage of Circuit with an Input Voltage of 15 V


### C8. Must have local microcontroller with at least 4 digital I/O pins to read the output signals coming from the OEM shifter signal
The Arduino Uno has 14 digital I/O pins.

### C9. Must have wires capable of handling 5 V to read the output signal from the OEM shifter sensor
Since the wires will be only handling 5 V, any sized wire could be used to carry the gear shifter's signal to the local microcontroller. 22 gauge wire will be used to splice into the OEM wires. 22 gauge wire is capable of handling 7 A, so it is more than capable of handling a digital voltage signal [2].

### C10. Must comply with IEEE 576-13 section on splicing wires and having loose wires.
This section of standards deal with the regulations and protocols around wire splicing that will be met when installing the Dorman wire splicing clip that meets regulations.

### BOM

| Part                         | Price    |
|:----------------------------:|:--------:|
| Dorman 22-18 Splicers 7 Pact | $4.49    |
| 22 Gauge Wire                | $14.99   |
| Arduino Uno                  | $25.00   |
|Diodes                        | $3.00    |
| 100 Ω Resistors              | $1.00    |
| Total                        | $48.48   |

### REFERENCES
[1] https://www.allaboutcircuits.com/textbook/direct-current/chpt-9/current-signal-systems/#:~:text=The%20most%20common%20current%20signal%20standard%20in%20modern,12%20milliamps%20representing%2050%20percent%2C%20and%20so%20on.

[2] https://www.rvandplaya.com/what-is-22-gauge-wire-used-for/
