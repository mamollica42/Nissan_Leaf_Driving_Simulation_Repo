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

