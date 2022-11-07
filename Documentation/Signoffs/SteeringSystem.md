STEERING WHEEL SUBSYSTEM
------------------------
### Function of the Subsystem
The Steering Wheel subsytem shall recieve the input of the Nissan Leaf steering wheel into a sensor
embedded into the steering column of the vehicle. The sensor will measure the steering angle and send
the data into a local microcontroller which will interpret the data and relay it to the simulation.

### Specifications & Constraints
- Must measure angle of rotation of the steering wheel
- Must use the Nissan Leaf OEM steering wheel as the input
- Angle Shall be no more than 960 degrees to the left and right (2 and 2/3 rotations)
- Error of the angle must be within 1% of the true steering angle

The simulation requires an input for the steering angle of the vehicle. In the Nissan Leaf, the steering
is limited to 2 and 2/3 rotations from the center point to each clockwise and counter-clockwise direction.
Therefore, the angle measured must be limited to 960 degrees in each direction. Due to the broader impact 
accuracy constraint, the error of the angle sensed must be within 1% of the true angle to prevent false
representation of the steering.

### Schematic
1. Model


2. Wiring Schematic


![image](https://user-images.githubusercontent.com/100802413/200068429-52157dad-0227-41ef-b2f6-d8c828e3f391.png)


![image](https://user-images.githubusercontent.com/100802413/200068789-5da2dbed-f9f1-4354-88d4-3102560d388f.png)


### Analysis
1. Objective

The objective of this design is to measure the degree of the steering wheel. To achieve the objective is by install a Rotary encode near the steering column.

2. Rotary Encoder

Position sensors such as rotary encoders will determine the rotating shafts. In response to rotational movement, it generates an electrical signal, either analog or digital.

2.1 Rotary Encoder Functionality

The rotary encoder features a disk with evenly spaced contact zones that link to the common pin C and two separate contact pins, A and B. When the disk rotates, A and B contact the common pin and produce two square wave output signals shown below.

![image](https://user-images.githubusercontent.com/100802413/200368531-224a7058-f5ef-4dff-aec7-045677b9f0cd.png)

2.2 Feasibility

The two output signals of the encoder, A and B, have a certain behavior that is useful for determining the rotational angle. That is, output A always leads output B from the perspective of motion to the right, and output A always trails output B from the perspective of motion to the left. The phase difference of each signal is 90 degrees in the positive or negative direction. This allows clockwise and counter-clockwise motion to be detected simply by examining the leading signal. Addtionally, the rotary encoder has 360 degrees of rotation, so there is no limit to the number of rotations in either direction that can be measured.

![image](https://user-images.githubusercontent.com/100802413/200377873-b847810c-9c7c-4f60-a6b4-c8aa6b95f3ac.png)

_Clockwise Motion_

![image](https://user-images.githubusercontent.com/100802413/200378017-c3d1d804-847d-441c-83e7-9236c77a80c6.png)

_Counter-clockwise Motion_

Encoders differ by their PPR (Pulses per Revolution) as well as their ability to maintain their current state when powered off. There are two main types of encoders: Incremental and Absolute. Incremental encoders output changes in the position instantly but does not keep track of the current position. Absolute encoders maintain the position regardless of power being supplied. For the purpose of measuring the angle of steering, an incremental encoder is all that is necessary because the previous position is of no use to the simulation.

3. Angular Rotation

To select the appropriate rotary encoder, the PPR value must be enough to measure each steering position accurately. The equation below is used to capture the angle in degrees based on the PPR and the pulses:
      
      A = (P/PPR) * 360

where P is the number of pulses, PPR is the Pulses per Revolution, and A is the angle in degrees.

4. Encoder Selection

This steering wheel design will use an E6B2-CWZ1X increment rotary encoder or an increment rotary encoder around 1000 PPR. The E6B2-CWZ1X increment rotary encoder has a max frequency of 100 kHz. Since the team knows that max frequency, we can reverse engineer and find the Nyquist. The max Nyquist rev is 100 rev/s, and to satisfy the max, Nyquist is 50 rev/s. Also, fulfilling the max Nyquist will eliminate the sampling aliasing.

### BOM
