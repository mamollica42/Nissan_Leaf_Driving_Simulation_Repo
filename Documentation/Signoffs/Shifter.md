Gear Shifter Subsystem
--------------------------------------
### Function of the Subsystem
The gear shifter subsystem will capture the OEM signal from the gear shifter sensor by splicing into the wiring and storing the signal on a local microcontroller. 
### Specifications & Constraints
-	Must use OEM gear shifter sensor
-	Must not have any exposed or loose wires according to NESC standard
-	Shall transmit the gear shifter data at a refresh rate no slower than 100 ms
-	Shall have the same accuracy as the OEM gear shifter sensor
-	Shall store the signal on a local microcontroller

### Wiring Schematic

![image](https://user-images.githubusercontent.com/117474540/214115430-fef84ac0-757d-4dbc-8ce5-b38dcb3c5fe4.png)

###### _Figure 1: Splicing OEM wiring to a local microcontroller

### Analysis
The reason for choosing the wire splicing is because it is the cheapest way to get an immersive experience for the driving simulator. Installing third party sensors could result in clutter around the gear shifter and inaccuracy of the system due to human interference or improper sensor installation. With wiring splicing, there will be no excess sensors and clutter, and the system will have 100% accuracy because the cars actual signal will be captured and stored. The signal will be stored on a local microcontroller and then sent to the master microcontroller. The local microcontroller will read the inputs from the wires and send what gear the car is in to the master microcontroller. This wil be done with C code. The reason for the local microcontroller is to not bog down one massive microcontroller and potentially slow down processing speeds. 

### Testing
For wire splicing to be effective, the signals coming from the wires of the gear shifter sensor would still need to be accurate even with the back half of the car being cut off.  As of now, the car can only go into park and neutral. To see if the car can go into drive and reverse, more testing was needed to see if the sensor still could send the appropriate output signal even if the car could not go into the desired gear. To test this, male to female jumper wires and a DMM was used. A wiring diagram online was found with specific gears labeled corresponding to the PIN and color wire. Before testing, the colors and pins were confirmed, so all that was left was to see if the shifter worked without the back half of the car and to confirm that the gears matched the pins.

![image](https://user-images.githubusercontent.com/117474540/214118110-98df866a-9546-4820-9726-7ace77302a40.png)

###### _Figure 2: Measuring the voltage of the output signals coming from the gear shifter sensor

After measuring the voltages and changing the gears in the car, it was determined that system is an active low system. Whenever the gear in the car was changed, the wire corresponding to the gear when from 5 V down to 0 V for a cycle then returned back to 5 V.The current of the signal was at or less than 20 mA for all the testing. This allowed for the conclusion of the signal being a digital signal [1].   Even though the car could not be put into drive and reverse, the gear shifter would still send an appropriate signal if you moved the shifter accordingly. The car would resort to neutral if you tried to put it in reverse or drive, but the sensor still worked properly. Due to this, wire splicing would be sufficient for sensing what gear the car is in.

### Microcontroller Selection
The Arduino UNO REV3 is clocked at 16 MHz, has 6 analog I/O pins, and 14 digital I/O pins. The board can be powered via battery, USB, or the VDD pin and can operate within a voltage range of 7-12 V. With a refresh rate of 16 MHz, the gear shifter data can be sent in real time due to human reaction time being slower than 100 ms. While the detection of signal will be at the same speed of the car, the transmission of the data to the master microcontroller will be faster than human detection to give an immersive feel to the simulator. 4 digital I/O pins will be used to capture the 4 different gears the car can be in. Since the max input from the wires will be 5 V, the Arduino will be able to handle the inputs coming from the car. Since the digital signal is being pulled directly off an OEM sensor, the Arduino will have the same overvoltage protection from the ECU as the OEM sensor [2]. The microcontroller will be powered by the power system that is still yet to be designed.

### Wire and Splicer Selection
Since the wires will be only handling 5 V with little to no current, any sized wire could be used to carry the gear shifter's signal to the local microcontroller. 22 gauge wire will be used to splice into the OEM wires because that is the wire size of the actual wires. 22 gauge wire is capable of handling 7 A, so it is more than capable of handling a signal with a very small current [3]. 

### BOM

| Part                         | Price    |
|:----------------------------:|:--------:|
| Dorman 22-18 Splicers 7 Pact | $4.49    |
| 22 Gauge Wire                | $14.99   |
| Arduino Uno                  | $25.00   |
| Total                        | $44.48   |

### REFERENCES
[1] https://www.allaboutcircuits.com/textbook/direct-current/chpt-9/current-signal-systems/#:~:text=The%20most%20common%20current%20signal%20standard%20in%20modern,12%20milliamps%20representing%2050%20percent%2C%20and%20so%20on.

[2] https://www.analog.com/en/technical-articles/active-highvoltage-transient-protectors-trump-conventional-approaches-in-automotive-electronics.html

[3] https://www.rvandplaya.com/what-is-22-gauge-wire-used-for/
