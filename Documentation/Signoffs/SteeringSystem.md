STEERING WHEEL SUBSYSTEM
------------------------
### Function of the Subsystem
The Steering Wheel subsytem shall recieve the input of the Nissan Leaf steering wheel into a sensor
embedded into the steering column of the vehicle. The sensor will measure the steering angle and send
the data into a local microcontroller which will interpret the data and relay it to the simulation.

### Specifications & Constraints
- Must measure angle of rotation of the steering wheel
- Must use the Nissan Leaf OEM steering wheel as the input
- Angle shall be no more than 960 degrees from the left boundary to the right boundary (2 and 2/3 rotations)
- Error of the angle must be within 1% of the true steering angle
- Must not lose steering position when power is cycled
- System must be small enough to fit in the area of the vehicle without interfering with the driver or other subsytems

The simulation requires an input for the steering angle of the vehicle. In the Nissan Leaf, the steering
is limited to 2 and 2/3 rotations from the center point to each clockwise and counter-clockwise direction.
Therefore, the angle measured must be limited to 960 degrees in each direction. Due to the broader impact 
accuracy constraint, the error of the angle sensed must be within 1% of the true angle to prevent false
representation of the steering.

### Schematic
##### 1. Model


![image](https://user-images.githubusercontent.com/100802413/200971670-3beca395-ed8c-400a-b166-59c4ad6b9142.png)

_Figure 1: 2D-Model of Gear and Encoder Connection_

![image](https://user-images.githubusercontent.com/100802413/200971713-41b91541-980b-4e55-9a2c-9e852589094b.png)

_Figure 2: 3D-Model of Gear and Encoder Connection_

##### 2. Wiring Schematic

![image](https://user-images.githubusercontent.com/100802413/202778335-03551d16-b805-4bf0-b12f-0724f2eec5a0.png)

_Figure 3: Encoder Connection to MCU_


### Analysis
##### 1. Angular Rotation

To select the appropriate rotary encoder, the CPR value must be enough to measure each steering position accurately. The equation below is used to capture the angle in degrees based on the CPR and the counts:
      
      A = (C/CPR) * 360       (1)

where C is the number of counts, CPR is the Counts per Revolution, and A is the angle in degrees.

Similarly, the accuracy of the angle is highly important to the selection of an encoder. To find the output sensitivy of the encoder, the following equation is used:
     
     D = 360/(Resolution)       (2)

where D is the degrees of accuracy and Resolution is the how many data bits. 

##### 2. Encoder Selection

This steering wheel design will use a TRD-NA1024NW absolute rotary encoder with a resolution of 1024. The Encoder a voltage rating of 12 to 24 VDC, and a maximum current consumption of 70 mA. Using equation 2 above, the degrees of accuracy for this encoder is 0.356 degrees which means it is capable of measuring the angle of the steering wheel up to 20% of a degree. The TRD-NA1024NW has 10 data bits, a VDD pin, and a GND pin. This requires a microcontroller with at least 10 digital GPIO pins and that can supply the current of up to 70 mA to the rotary encoder.

The encoder has 1024 unique 10-bit outputs than will be read into the MCU. The output of the encoder changes on rotation of the knob. The knob of the encoder will be connected to a gear system that is mounted to the steering column of the vehicle so that the steering wheel rotation will rotate the knob. Each 10-bit output will increment or decrement a count variable in the MCU code depending on the driection of rotation. That count will be used to calculate the angle of the wheel using equation 1 above.

##### 3. Microcontroller Selection

The Arduino UNO REV3 is clocked at 16 MHz, has 14 digital I/O pins, and 6 analog I/O pins. The board can be powered via battery, USB, or the VDD pin and can operate within a voltage range of 7-12 V. Each GPIO pin can supply up to 40 mA, but normally operates at 20 mA per pin. Given that the encoder requires 10 digital pins, the Arduino UNO can support that requirement and still have leftover pins for communication. Addtionally, the power supplied to the encoder will be supplied by the power system to avoid any possible damage to the microcontroller.

##### 4. Connectivity

The rotary encoder must be connected to the steering column such that the rotation of the wheel can be properly mapped to the encoder. This will be done using a gear system with an 8:3 gear ratio. This value is based on the 960 degree rotation of the Nissan Steering Wheel having to be mapped to the 360 degree rotation of the encoder. The below equation helps analytically verify this calculation:

      Driven/Driving = 960/360 = 8/3 ==> 8:3    (3)
      
The steering wheel is already limited to the 960 degree range by Nissan. This means that the steering wheel physically is unable to exceed 960 degrees of rotation from the left boundary to the right boundary. Therefore, mapping its rotation using the 8:3 gear ratio will also make it physically impossible for the rotation of the encoder to exceed 360 degrees as desired. The TRD-NA1024NW is a 1024 resolution encoder, meaning it displays 1024 unique outputs per revolution. For each turn of the encoder, 0.356 degrees will be measured allowing the angle to be extremely precise. Additionally, by attaching the gear system to the steering column, the OEM steering wheel can be used as the input to the encoder. 

##### 5. Calculations

![image](https://user-images.githubusercontent.com/100802413/202805894-4c042fc8-f71d-490f-8039-ac412f45bafb.png)

_Figure 4: Gear Ratio and Angle calculation Analysis_

![image](https://user-images.githubusercontent.com/100802413/202862273-5f44f45a-ed0a-4e65-bb63-7dd475245d4e.png)

_Figure 5: MATLAB Verfication for all possible Angles_

### BOM

| Part        | Price    |
|:-----------:|:--------:|
| Encoder     | $352.00  |
| JT-035D     | $13.00   | (Mounting Bracket)
| Arduino     | $27.60   |
| TOTAL       | $392.60  |
