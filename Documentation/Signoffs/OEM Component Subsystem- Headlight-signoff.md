OEM Component Subsystem- Auto Light
------

## The function of the Auto Light Subsystem
The Master microcontroller will receive the output of the Nissan Leaf AutoLight in this part of the subsystem. Furthermore, the Master microcontroller will detect if the headlight is off, on, blinking, and high and low beams.

### Specification & constraints
   - Must detect high beam,low beam, left indicator, and right indicator
   - Must use OEM componets as the inputs
   - The signal input must not exceed 5V 
   
# Auto Light Wiring schematic
![opel2437](https://user-images.githubusercontent.com/101354063/205468261-7fca3396-009b-4eb8-9960-962065d22ac8.png)
### Figure 1: Headlamp(High and low Relay)

# Design: A Voltage divider from Auto Light to the Microcontroller
![Capture](https://user-images.githubusercontent.com/101354063/205472902-57cf6121-181d-4fe0-904c-63295cc9c374.PNG)


### Figure 2: Voltage divider

Analysis
-------
### Auto Light Wiring Diagram
The auto light wiring diagram shows the whole wiring for each component in the headlight of the Nissan Vehicle. However, the main focus are the Headlamp relays shown in Figure 1 and they link to the headlamps. This displays how the low beam and high beam functions operate and make the headlight indicate. The wiring diagram reveals that the battery is attached to the CPU through the relay showing that the relay receives power from the battery, but the current is operated by the CPU. The input from the battery is also connected to one side of the relay switch. This means that the input to the lamp and headlight should be 12 V. Also, figure 1 shows that their fuse connects to the output of the relay, and the fuse can take up to 10 amps. Overall, the key point is to see the headlamp relay, what is connected, and how it works. 

### Design Voltage 
From the information in Auto Light Wiring diagram, a method to detect the output of the relay can be created. The design shown in figure 2 is to splice and add a voltage divider to connect to the microcontroller. This process uses the 12 V potential that is sent to the lamp to illuminate the light to trigger a reaction on the microcontroller. 


Current through divider, total current through relay,  
--- still add more information(NOT done yet)




### Summary
Based on Research, the Auto light from Figure 1, and the Sylvania H13 XtraVision Halogen Headlight Bulb[1], the voltage going through the headlight is 12 volts, and the current is in the range of 4.0 to 4.7 amp. Furthermore, based on the information, I gather that the current won't affect the device, but the voltage will.


 


| Part   | Cost   | Qty|
|-------:|:------:|:--:|
| 1.8kohms| $0.10 |  4 |
|1.3K ohms| $0.10  | 4  |

reference
---------
[1]https://www.oreillyauto.com/detail/c/xtravision/sylvania-h13-xtravision-halogen-headlight-bulb-pack-of-2/syl5/h13xv2bp/v/a/128040/automotive-car-2014-nissan-leaf?q=headlight&pos=0

[2]https://ledlightinginfo.com/led-headlights-amps#:~:text=So%20the%20total%20amps%20drawn,pair%20would%20be%209.16%20amps.


