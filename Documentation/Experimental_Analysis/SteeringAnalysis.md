Steering Experimental Analysis
----
### Specifications & Constraints
- Must measure angle of rotation of the steering wheel
- Must use the Nissan Leaf OEM steering wheel as the input
- Angle shall be no less than 960 degrees from the left boundary to the right boundary (2 and 2/3 rotations)
- Error of the angle must be within 1 degree of the true steering angle
- Must not lose steering position when power is cycled
- System must be small enough to fit in the area of the vehicle without interfering with the driver or other subsytems
### Analysis
#### SC1
The main function of the steering subsystem is to capture the angle of the steering wheel. Using an absolute rotary encoder, angle is a function of the resolution of the encoder and its current position.
    
    Angle = (Position / Resolution) * 360

where angle is in degrees, and resolution is 1024 for the 10-bit rotary encoder. This function is programed in the Master MCU using the following code:

    angle = (pos/1024)*360;
    
However, the programming alone does not provide the exact angle we are trying to measure. The gear system is in place to map the 360 degree rotation to the 1200 degree rotation of the steering wheel. This gear system was originally designed to be an 8:3 gear ratio based on the previously assumed 960 degrees of rotation of the steering wheel. Although, after some testing, the team discovered that the steering wheel has a 1200 degree of rotation, which must be accounted for with a 10:3 gear ratio. So at the time being, the angle is being measured but it is incorrect in all cases as the gear system must be changed. The new gear design should be ready to be installed in the next week or less.
#### SC2
The Nissan Leaf steering wheel is the input device of the steering subsystem. The rotary encoder measuring the changes in position of the steering wheel is mounted to the steering column of the vehicle so that turning the wheel will rotate the steering column and update the value on the Master MCU.
#### SC3 -> _Modified to "Angle shall be no less than 1200 degrees from the left boundary to the right boundary (3 and 1/3 rotations)"_
Currently, this constraint is also not being met due to the incorrect gear ratio mentioned previously. During testing, when the wheel is moved from the far left boundary to the far right boundary, the steering angle rolls over back to 0 before the right boundary is met. Therefore, we are not able to measure the entire 1200 degrees of motion.
#### SC4
The error in the steering angle is another constraint that is not met due to the incorrect gear ratio. That is, the error is much greater than 1 degree in all cases except when the angle is zero. Because our gear ratio accounts for a total rotation of 960 degrees and the steering wheel exhibits 1200 degrees of rotation, every angle measured is off by a factor of 3/4 (960/1200). This issue should be immeadiately resolved with the installation of the new gear system.
#### SC5
The absolute encoder was chosen to meet this requirement as one of its fundamental properties is that its position is known regardless of being powered. So, in every reboot of the power to the overall system, the steering angle is displayed at whatever its last position was.
##### Table 1
| |Output when Powered|Output when Power is Recycled|
|--|---------|----------|
|1|259.10|259.10|
|2|253.48|253.48|
|3|261.21|261.21|
|4|280.20|280.20|
|5|290.04|290.04|
|6|300.23|300.23|
|7|311.84|311.84|
|8|318.52|318.52|
|9|320.98|320.98|
|10|326.95|326.95|
#### SC6
The rotatry encoder, gear system, and mounts fit into the vehicle without interfering with the driver or other subsystems nearby. Therefore, this constraint has been properly met.
### Conclusion
The gear system being unproperly sized is causing all of the issues with this subsystem. Fortunately, this fix has already been addressed and the new gear system will be implemented within a week or less from the time of this submission. Once the new gear system is installed, the testing will begin again to comfirm that the subsytem has met all specifications and requirements. So, from an electrical standpoint, all parts of the subsystem are operating exaclty as desired. However, the mechanical portion of this subsystem is causing incorrect data to be fed into the system.
