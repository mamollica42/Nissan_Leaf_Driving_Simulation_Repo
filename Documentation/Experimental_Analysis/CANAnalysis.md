# CAN Capturing Subsystem Experimental Analysis
-------------------------------------
## I. Specifications & Constraints
1. Must capture information from CAN bus at no less than 10 Hz
2. Must store CAN bus data neatly and in a readable manner on the PC
3. Shall not interfere with the functionality with any other subsystem
4. Shall receive power from the PC
5. Must be able to store up to 2048 different CAN Messages
6. PC must have at least 28 Kb of storage space for CAN data

## II. Analysis
### SC1
CAN messages must be captured at no less than 10 Hz which is equivalent to 10 messages per second. In other words, every 100 ms, a CAN message must be sent to the PC.

      10 msg / 1 sec = 10 msg per sec ==> 1 msg per 0.1 sec ==> 1 msg per 100 msec
Therefore, for this subsytem to meet the first constraint, the time it takes between 2 messages being captured on the PC must be less than or equal 100 msec as seen in the recorded data table below.
###### Table 1
| |Time Stamp|CAN Message|Time Difference from previous|
|----|----------|----------------|---------------|
|1|13:03:10.603|0x2DE000000000000FFFF|N/A|
|2|13:03:10.603|0x285FFFFFFFF000030B3|< 1 msec|
|3|13:03:10.627|0x60D0006000000000000|24 msec|
|4|13:03:10.627|0x1CC00000541|< 1 msec|
|5|13:03:10.627|0x285FFFFFFFF000031B4|< 1 msec|
|6|13:03:10.627|0x3550000000020006000|< 1 msec|
|7|13:03:10.627|0x30002|< 1 msec|
|8|13:03:10.660|0x2A00000000000C|33 msec|
|9|13:03:10.660|0x1CC00000572|< 1 msec|
|10|13:03:10.660|0x2457FF8011A33007FF3|< 1 msec|

As seen in Table 1 above, the time between each message is 33 msec or less in all cases, meeting the 10 Hz requirement.

### SC2
The CAN data is stored in an excel file, which is a well-known and highly professional software tool used to display and analyze data. Below is an example of the storage format in an excel sheet.

![image](https://user-images.githubusercontent.com/100802413/227805812-e94e070b-0b82-4b7a-8e5f-1055efe9329e.png)

_Figure 1: CAN Bus Data Excel Formatting_

This storage method distinguishes the different messages being captured as well as parses the message ID from the rest of the message packet for extra readability.

### SC3
This subsystem is not connected to any other part of the vehicle and does not use any parts that are shared by any other subsystem exept the PC. This subsystem is connected to a single USB port of the PC and does not inhibit connectivity of the Master MCU to the same PC as this uses a different USB port. Therefore, this subsystem does not interfere with the functionality of any other subsystem.

### SC4
The CAN Bus Shield and Arduino that make up the subsystem are connected directly to the PC via USB which provides power.

### SC5
An excel sheet is capable of storing information in up to 65,536 rows, which greatly exceeds the 2048 maximum requirement for storage.

            2048 << 65536

### SC6
The PC has a 256 GB SSD and currently has 51.8 GB of free space which greatly exceeds the minimum requirement of 28 Kb of storage space.

            51.8 GB >> 28 Kb
            
## III. Conclusion
Because each of the 6 specifications and constraints listed above have been met, the subsystem is confirmed to function as designed.

