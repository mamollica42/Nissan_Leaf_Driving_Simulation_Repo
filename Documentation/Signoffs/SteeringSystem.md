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

_2D-Model of Gear and Encoder Connection_

![image](https://user-images.githubusercontent.com/100802413/200971713-41b91541-980b-4e55-9a2c-9e852589094b.png)

_3D-Model of Gear and Encoder Connection_

##### 2. Wiring Schematic


![image](https://user-images.githubusercontent.com/100802413/200903742-825de5d3-3bc1-40d5-83c7-1e14c02fa940.png)

_Rotary Encoder Pinout_

![image](https://user-images.githubusercontent.com/100802413/200881810-5902fe09-6d5b-472e-89ba-e14607246b68.png)

_Arduino UNO Pinout_


### Analysis
##### 1. Objective

The objective of this design is to measure the angle of the steering wheel in degrees. To achieve the objective is by install a Rotary encode near the steering column.

##### 2. Rotary Encoder

Position sensors such as rotary encoders will determine the rotating shafts. In response to rotational movement, it generates an electrical signal, either analog or digital.

###### 2.1 Rotary Encoder Functionality

The rotary encoder features a disk with evenly spaced contact zones that link to the common pin C and two separate contact pins, A and B. When the disk rotates, A and B contact the common pin and produce two square wave output signals shown below.

![image](https://user-images.githubusercontent.com/100802413/200368531-224a7058-f5ef-4dff-aec7-045677b9f0cd.png)

###### 2.2 Feasibility

The two output signals of the encoder, A and B, have a certain behavior that is useful for determining the rotational angle. That is, output A always leads output B from the perspective of motion to the right, and output A always trails output B from the perspective of motion to the left. The phase difference of each signal is 90 degrees in the positive or negative direction. This allows clockwise and counter-clockwise motion to be detected simply by examining the leading signal. Addtionally, the rotary encoder has 360 degrees of rotation, so there is no limit to the number of rotations in either direction that can be measured.

![image](https://user-images.githubusercontent.com/100802413/200377873-b847810c-9c7c-4f60-a6b4-c8aa6b95f3ac.png)

_Clockwise Motion_

![image](https://user-images.githubusercontent.com/100802413/200378017-c3d1d804-847d-441c-83e7-9236c77a80c6.png)

_Counter-clockwise Motion_

Encoders differ by their PPR (Pulses per Revolution) as well as their ability to maintain their current state when powered off. There are two main types of encoders: Incremental and Absolute. Incremental encoders output changes in the position instantly but does not keep track of the current position. Absolute encoders maintain the position regardless of power being supplied. For the purpose of measuring the angle of steering, an absolute encoder is necessary because the previous position is important to the realitic use of a steering wheel. This way, no matter what position the wheel is left off, the measured angle will be accurate and not reset to zero degrees.

##### 3. Angular Rotation

To select the appropriate rotary encoder, the CPR value must be enough to measure each steering position accurately. The equation below is used to capture the angle in degrees based on the CPR and the counts:
      
      A = (C/CPR) * 360       (1)

where C is the number of counts, CPR is the Counts per Revolution, and A is the angle in degrees.

Similarly, the accuracy of the angle is highly important to the selection of an encoder. To find the output sensitivy of the encoder, the following equation is used:
     
     D = 360/(Resolution * 2)       (2)

where D is the degrees of accuracy and Resolution is the how many data bits. 

##### 4. Encoder Selection

This steering wheel design will use a TRD-NA1024NW absolute rotary encoder with a resolution of 1024. The Encoder has a max frequency of 20 kHz, a voltage rating of 12 to 24 VDC, and a maximum current consumption of 70 mA. Given the maximum frequency of 20 kHz, the sampling rate must be at least 40 kHz to satify the Nyquist Theorem. Using equation 2 above, the degrees of accuracy for this encoder is 0.176 degrees which means it is capable of measuring the angle of the steering wheel up to 20% of a degree. The TRD-NA1024NW has 10 data bits, a VDD pin, and a GND pin. This requires a microcontroller with at least 10 digital GPIO pins and that can supply the current of up to 70 mA to the rotary encoder.

##### 5. Microcontroller Selection

The Arduino UNO REV3 is clocked at 16 MHz, has 14 digital I/O pins, and 6 analog I/O pins. The board can be powered via battery, USB, or the VDD pin and can operate within a voltage range of 7-12 V. Each GPIO pin can supply up to 40 mA, but normally operates at 20 mA per pin. Given that the encoder requires 10 digital pins, the Arduino UNO can support that requirement and still have leftover pins for communication. Addtionally, the power supplied to the encoder will be supplied by the power system to avoid any possible damage to the microcontroller.

##### 6. Connectivity

The rotary encoder must be connected to the steering column such that the rotation of the wheel can be properly mapped to the encoder. This will be done using a gear system with an 8:3 gear ratio. This value is based on the 960 degree rotation of the Nissan Steering Wheel having to be mapped to the 360 degree rotation of the encoder. The below equation helps analytically verify this calculation:

      Driven/Driving = 960/360 = 8/3 ==> 8:3    (3)
      
The steering wheel is already limited to the 960 degree range by Nissan. This means that the steering wheel physically is unable to exceed 960 degrees of rotation from the left boundary to the right boundary. Therefore, mapping its rotation using the 8:3 gear ratio will also make it physically impossible for the rotation of the encoder to exceed 360 degrees as desired. The TRD-NA1024NW is a 1024 resolution encoder, meaning it displays 1024 unique outputs per revolution. For each turn of the encoder, 0.176 degrees will be measured allowing the angle to be extremely precise. Additionally, by attaching the gear system to the steering column, the OEM steering wheel can be used as the input to the encoder.  

### BOM

| Part        | Price    |
|:-----------:|:--------:|
| Encoder     | $352.00  |
| Arduino     | $27.60   |
| TOTAL       | $379.60  |
