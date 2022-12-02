Accelerator Pedal Position System
--------------------------------------
### Function of the Subsystem
The accelerator pedal position system will take the OEM signal from the pedal by splicing into the signal wires and input them to the local microcontroller. The local microcontroller will then calculate the position based the change of the voltage from the OEM hall effect sensor.

### Specifications & Constraints
- Must ues OEM accelerator pedal 
- Must not have any exposed or loose wires according to NESC standard
- Shall send position signal to local MCU

### Wiring Schematic

![gad_pedal_schematic](https://user-images.githubusercontent.com/117474294/203157554-6f31356a-0b6b-437b-bd89-67dbbb3276de.png)

###### _Figure 1: OEM Wiring With Splice On Output Signals_

### Analysis
The reason for using the OEM wires and splicing them is because the pedal itself is pressed closed with no way to access the internals of the sensor. Another problem with installing an external sensor is that there is not a pivot point on the outside of the pedal to mount a sensor on. The only way to meassure the position with external would be a lidar sensor mounted to the wall measuring the distance of the pedal from the back. This would not be very accurate as well as could be hit or disrupted by the user. Therefore, the decision was to splice the existing output wires of the existing OEM sensors. There is a wiring diagram as well as the expected values of each wire from Erwin Salarda [1]. The wiring diagram is shown in Figure 2 and the expected values are shown in Figure 3.
The spliced wires which are connected to sensor 1 and sensor 2 will be giving vary voltages depending on how depressed the pedal is at that moment. We will then code the local MCU to observe this change in voltage and vary the cars acceleration as appropriate. When we are coding the local MCU we will get the min and max bounds and do a high number iterations between the two and bound them to an angle. The wires will be spliced with a Dorman 22-18 gauge quick splice terminal. This will splice the wires safe and keep the enclosed and not exposed or dangerous. We will also need some excess 22 gauge wire to put into the splicer.     

![image](https://user-images.githubusercontent.com/117474294/203162245-375a00ff-f4f9-429c-835d-8896e2790e6c.png)

###### _Figure 2: The wiring diagram of the accelerator pedal position sensors_

![image](https://user-images.githubusercontent.com/117474294/203162462-ea3d0025-a9c0-4b51-aa64-806d46f55e12.png)

###### _Figure 3: The expected values of each wire for the accelerator_

### BOM

| Part                         | Price    |
|:----------------------------:|:--------:|
| Dorman 22-18 splicers 7 pact | $4.49    |
| 22 gauge wire                | $14.99   |

note: tax not included


Sources:
[1] https://erwinsalarda.com/nissan-accelerator-pedal-position-app-sensor/
