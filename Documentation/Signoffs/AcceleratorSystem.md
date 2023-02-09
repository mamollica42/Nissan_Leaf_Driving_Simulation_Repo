Accelerator Pedal Position System
--------------------------------------
### Function of the Subsystem
This subsystem will obtain the gas pedals position and send this signal to a local microcontroller for processing. The local microcontroller will then send its position to the master microcontroller which tells the simulation the pedals position. 

### Specifications & Constraints
- 1. Must use OEM gas pedal to meet customer expectations.
- 2. Must send voltage at the range 0-5V that changes as the position changes to be read by the local microcontroller.
- 3. Must have wires able to handle at least 5V and 20mA due to the expected voltage range 0-5V and expected current of 20mA.
- 4. Shall have an accurate measure of the pedal postion of at least 1% accuracy to ensure the simulation is a accurate representation of real life. 
- 5. Must not have any exposed or loose wire according to IEEE Std 576-13.  

### Wiring Schematic

![BrakePedalSchematic](https://user-images.githubusercontent.com/117474294/217087668-75f8f196-f3cc-4efa-ba06-ad668866a8ed.png)

###### _Figure 1: OEM Wiring With Splice On Output Signals of Gas and Brake pedals_

### Analysis
#### 1. Must use OEM gas pedal to meet customer expectations.
  Customer does not want external pedal installed to car.
#### 2. Must send voltage at the range 0-5V that changes as the position changes to be read by the local microcontroller.
  The sensor that measures the position will be an analog signal with voltage range 0-5V that can be read by most microcontrollers. In this case a external sensor will not be added since there is a accelerator pedal position sensor(APPS) that sends an analog signal to the engine controller module(ECM) that will be wire spliced to the local microcontroller.
#### 3. Must have wires able to handle at least 5V and 20mA due to the expected voltage range 0-5V and expected current of 20mA.
  22 AWG wire will be selected for the splicing since it can handle 300V and 7A.
#### 4. Shall have an accurate measure of the pedal postion of at least 1% accuracy to ensure the simulation is a accurate representation of real life.
  Arduino boards convert the 0-5V analog signal to a digital signal with 1024 bits so 5/1024 means 4.88mV per step.  The smallest range of voltage we tested was 1.883V which has 1.883V/0.00488V to get 376.6 steps for this range of voltage. The accuracy then is 1/376.6 = 0.27%.
#### 5. Must not have any exposed or loose wire according to IEEE Std 576-13. 
  This section of the IEEE standards tell you the safe practices of wire splicing which I will follow when install the Dorman wire splicing clips.

![Screenshot 2023-01-26 133456](https://user-images.githubusercontent.com/117474294/214932846-6c566b33-5910-436a-a5ec-db32af85b6cc.png)

###### _Figure 2: The wiring diagram of the cruise control with the pedal position sensors at the bottom left[1]_

![image](https://user-images.githubusercontent.com/117474294/203162462-ea3d0025-a9c0-4b51-aa64-806d46f55e12.png)

###### _Figure 3: The expected values of each wire for the accelerator[2]_

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
