OEM Component Subsystem- Auto Light
------

## The function of the Auto Light Subsystem
The Master microcontroller will receive the output of the Nissan Leaf AutoLight in this part of the subsystem. Furthermore, the Master microcontroller will detect if the headlight is off, on, blinking, and high and low beams.

### Specification & constraints
   - Must detect the auto light high beams, low beams, and left and right indicators with a voltage of no more than 5 volts and a current below 40 milliamps.
   - Must use OEM componets as the inputs
   - The signal input from the autolight must not exceed 5 V 
   - Implement a way to protect the signal from the input voltage varying from 10 V to 15 V
   - Current to the signal must be less than 1 percent of the current to the light
   - Prevent interference among signals through isolation methods
   
## Auto Light Wiring schematic
![opel2437](https://user-images.githubusercontent.com/101354063/205468261-7fca3396-009b-4eb8-9960-962065d22ac8.png)
#### Figure 1: Headlamp(High and low Relay)
<br/>

### Auto Light Wiring Diagram


Description
-------
- The auto light wiring diagram shows the whole wiring for each component in the headlight of the Nissan vehicle. However, the main focus are the headlamp relays shown in Figure 1 and they link to the headlamps. This displays how the low beam and high beam functions operate and make the headlight indicate. The wiring diagram reveals that the battery is attached to the CPU through the relay showing that the relay receives power from the battery, but the current is operated by the CPU. The input from the battery is also connected to one side of the relay switch. This means that the input to the lamp and headlight should be 12 V. Also, Figure 1 shows that their fuse connects to the output of the relay, and the fuse can take up to 10 amps. Overall, the key point is to see the headlamp relay, what is connected, and how it works. 



## Design: A Voltage divider from Auto Light to the Microcontroller
<br/>

![image](https://user-images.githubusercontent.com/101354063/217676523-7f8043a6-731e-4d1f-a5c7-12568f081fe7.png)

##### Figure 2: Voltage Divder with Opto-isolation

#### Usage of OEM componets as the inputs 

--------
- From the information in Auto Light Wiring diagram, a method to detect the output of the relay can be created. The design shown in Figure 2 is to splice and add a voltage divider to connect to the microcontroller. This process uses the 12 V potential that is sent to the lamp to illuminate the light to trigger a reaction on the microcontroller. 


### The detection of the auto light high beams, low beams, and left and right indicators and Current to the signal must be less than 1 percent of the current to the light
------


![LVT 817](https://user-images.githubusercontent.com/101354063/206586290-37ae6b0b-b3ca-41a7-96c7-75b4382fc6b4.PNG)
##### Figure 3: From the optoisolator Datasheet
<br/>

- The design behind the voltage divider is to reduce the auto light voltage to no more than 5 V and have a current of less than 1% of the current to the light. This constraint on current is to prevent any exceedance in the limits of the original hardware and wire ratings that could cause overload or failure on the car.

 - The current through the light is 4.79 A.
 
 - The 40 ma forward current was chose for this design to drive led inside of  optoisolator
 
 - which makes the limit to the voltage divider 47.9 mA. 
  
 - 40 mA is decided to be a limit for the safety of the devices added and not exceed the constraint.
 -  assuming that the input voltage could vary from 10 to 15 V

    -  $Max \ Resistance: 375 \ ohms = {15V \over  \ 40 \ mA }$

    - $R1 : 250 \ ohms = {10V \over  \ 40  mA}$  

    - $R2 : 375 \ ohms = {250 \ ohms + R2}$   
       $R2 : R2=375 \ ohms -250 \ ohms=125 \ ohms $ 
  
   - The average active voltage applied should be approximately 12 V. Thus, the limit should not be exceeded.

### Implement a way to protect the signal from the input voltage varying from 10 V to 15 V
----
![image](https://user-images.githubusercontent.com/101354063/217674389-7f9200ca-acbb-4a72-8b39-0717c201a001.png)
##### Figure 4: 40 mA Fuse

-  40 mA fuse will be installed to protect against any extreme voltage spikes outside of the 10 to 15 V range that would cause overcurrents. The LTV-817 optoisolator was chosen based on the threshold voltage of 1.2 V, and the maximum current constraint of 40 mA is less than the limit for the LTV-817 at 50 mA. According to the analysis of the design voltage divider and fuse, the protection of the signal from input voltages varying from 10V to 15V comes from a voltage divider, while the protection of current from a current spikes comes from a 40 mA fuse.

![image](https://user-images.githubusercontent.com/101354063/217659683-3dc1bfb6-31d2-4884-b90e-631a909418e3.png)
##### Figure 5: Voltage Divder

- the design with only a voltage divider has a potential risk due to the chance of a voltage spike reaching the microcontroller and interference from other signals. 
 - ### The analysis of Voltage divider (10 V to 15 V)

   Vout = Vin ${ R2 \over R1+R2}$

   5V = 12V ${ 125 \ ohms \over 250 \ ohms  + 125 \ ohms}$

   $Total \ Resistance: 375 \ ohms = {250 \ ohms +125 \ ohms}$ 

   $Max \ current: 40\ mA = {15V \over 375 \ ohms }$

   $Min \ current: 26.67\ mA = {10V \over 375 \ ohms }$

   Test different voltages going through Voltage Divider(0 to 15)

   ![image](https://user-images.githubusercontent.com/101354063/206635438-b9d504b8-7e54-471c-8ddc-083a5be3e416.png)

   Test different voltages going through Voltage Divider(10 to 15)

   ![image](https://user-images.githubusercontent.com/101354063/206637463-7d53790e-b779-426a-9310-c4f548f22864.png)
 



- This design shows the vulnerability to signal interferece through the shared ground terminal and the ability for the current to backfeed onto another divider. 
- The voltage divider prevents the chance of the signal voltage to exceed the limit of 5 V due to a spike in the input voltage on the lamp node. The design was modified to include optoisolators to remidy the hazards of both constraints as shown in Figure 2.
- Optoisolators operate on a threshold voltage and are not reliant on current. This means that it can operate on very small currents as long as the voltage meets the minimum requirement. 

### A prevention of interference among signals through isolation methods
___


The optoisolator will take the reduced voltage from the Nissan Vehicle and convert it into a light signal. Then a photosensor will detect the light signal and allow the 5 V to pass through the pin of the microcontroller. The LED that is used to trigger the photosensor also prevents any backfeed current from false triggering a signal. This isolates both systems so that the voltage to the lights does not have a direct path to the signal input. With the microcontroller being used for the 5 V supply in the signal, there should not be a voltage spike to the controller since it would have to be generated by the controller. 

 
## Master microcontroller communication

A wire will be connected directly to the optoisolator to the digital pin of the master microcontroller. The microcontroller receives voltage from themselves into digital pins, and the optoisolator controls whether the voltage passes through or not based on whether the auto light is on or off. Also, the master microcontroller has availible GPIO pins to shorten the delay of input into the communication network with less items to pass through. With the voltage being either 5 V or 0, the microcontroller will use the digital GPIO pins to read the voltage.


### Summary
The voltage going through the headlight is 12 volts and the current is in the range of 4.0 to 4.7 amp based on research using the auto light diagram from Figure 1 and the Sylvania H13 XtraVision Halogen Headlight Bulb [1]. Furthermore, based on the information, the conclusion can be drawn that the current won't affect the optoisolator, but the voltage will.
 

| Part   | Cost   | Qty| total|
|-------:|:------:|:--:|:----:|
|250 ohms| $1.060 |  5 |$5.30 | 
|125 ohms| $0.70  |  5 |$3.50|
|LTV-817*| $0.24  | 10 | $2.40|
|Fuseholders|$0.86| 5  | $4.30|
|40mA fuse| $2.67 | 6  | $16.02|

*4 are required. It is the same cost for 10 as it is 6. This provides extras in the event of multiple isolators failing.


reference
---------
[1]https://www.oreillyauto.com/detail/c/xtravision/sylvania-h13-xtravision-halogen-headlight-bulb-pack-of-2/syl5/h13xv2bp/v/a/128040/automotive-car-2014-nissan-leaf?q=headlight&pos=0

[2]https://ledlightinginfo.com/led-headlights-amps#:~:text=So%20the%20total%20amps%20drawn,pair%20would%20be%209.16%20amps.

[3]https://optoelectronics.liteon.com/upload/download/DS-70-96-0016/LTV-8X7%20series%20201610%20.pdf



