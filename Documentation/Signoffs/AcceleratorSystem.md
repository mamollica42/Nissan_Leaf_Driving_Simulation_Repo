Accelerator Pedal Position System
--------------------------------------
### Function of the Subsystem
This subsystem will obtain the gas pedals position and send this signal to a local microcontroller for processing. The local microcontroller will then send its position to the master microcontroller which tells the simulation the pedals position. 

### Specifications & Constraints
- Must use OEM gas pedal to meet customer expectations.
- Must send voltage at the range 0-5V that changes as the position changes to be read by the local microcontroller.
- Must have wires able to handle at least 5V and 20mA due to the expected voltage range 0-5V and expected current of 20mA.
- Shall have an accurate measure of the pedal postion of at least 1% accuracy to ensure the simulation is a accurate representation of real life. 
- Must not have any exposed or loose wire according to IEEE 3003.2  

### Wiring Schematic

![BrakePedalSchematic](https://user-images.githubusercontent.com/117474294/216156133-f74ab4dd-4ad5-4f1a-8e37-253d4cdc433d.png)

###### _Figure 1: OEM Wiring With Splice On Output Signals_

### Analysis
The reason for using the OEM wires and splicing them is because the pedal itself is pressed closed with no way to access the internals of the sensor. Another problem with installing an external sensor is that there is not a pivot point on the outside of the pedal to mount a sensor on. The only way to meassure the position with external would be a lidar sensor mounted to the wall measuring the distance of the pedal from the back. This would not be very accurate as well as could be hit or disrupted by the user. Therefore, the decision was to splice the existing output wires of the existing OEM sensors. There is a wiring diagram as well as the expected values of each wire one from Automotive Electricians Portal LLC [1] and one from Erwin Salarda [2]. The wiring diagram is shown in Figure 2 and the expected values are shown in Figure 3. The spliced wires which are connected to sensor 1 and sensor 2 will be giving vary voltages depending on how depressed the pedal is at that moment. We will then code the local MCU to observe this change in voltage and vary the cars acceleration as appropriate. When we are coding the local MCU we will get the min and max bounds and do a high number iterations between the two and bound them to an angle. The wires will be spliced with a Dorman 22-18 gauge quick splice terminal. This will splice the wires safe and keep the enclosed and not exposed or dangerous. We will also need some excess 22 gauge wire to put into the splicer. I am chosing 22 gauge wire since that is what the car already uses and it meets the specs by being able to handle 300 volts and 7 amps.    

![Screenshot 2023-01-26 133456](https://user-images.githubusercontent.com/117474294/214932846-6c566b33-5910-436a-a5ec-db32af85b6cc.png)

###### _Figure 2: The wiring diagram of the cruise control with the pedal position sensors at the bottom left_

![image](https://user-images.githubusercontent.com/117474294/203162462-ea3d0025-a9c0-4b51-aa64-806d46f55e12.png)

###### _Figure 3: The expected values of each wire for the accelerator_

### Testing 
The accelerator pedal has been tested by the Mechanical Engineering (ME) capstone team that has also been tasked to get data from the gas pedal to use in the simulation. They took out the pedal and took it to their lab and power the sensors with a power supply and measured the sensors output with a digital multimeter (DMM). Their results are shown in Figure 4. As shown in the picture there are two 5V supplied the pedal from the ECU to pins 3 and 2 and shown in the picture with red and wired in the car with white. The two grounds are shown shown in the picture as pins 5 and 6 with black and wired in the car with black. The two outputs from the senors are on pins 1 and 4 and are shown in the picture as green but are wired in the car with red. The correct pins and wire colors are also shown in Figure 2. The voltage range they got on the sensor at pin 1 is 0.367V - 2.250V from zero throttle to full throttle respectively. The voltage range from the sensor on pin 4 is 0.745V - 4.455V. With these ranges we will be able to set up a linear angle increase as the voltages increase in the coding of the local microcontroller. 

![ME gas pedal testing](https://user-images.githubusercontent.com/117474294/214936308-1026864d-be34-44cc-a997-a05aa78649e8.png)

###### _Figure 4: The data the ME team gathered from testing the accelerator pedal while hooked up to a DMM.

### BOM

| Part                         | Price    |
|:----------------------------:|:--------:|
| Dorman 22-18 splicers 7 pact | $4.49    |
| 22 gauge wire                | $14.99   |

note: tax not included


Sources:
[1] https://portal-diagnostov.com/en/2020/04/20/cruise-control-nissan-leaf-sv-2013-system-wiring-diagrams/

[2] https://erwinsalarda.com/nissan-accelerator-pedal-position-app-sensor/
