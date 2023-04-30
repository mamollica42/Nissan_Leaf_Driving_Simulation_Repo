# Lessons Learned
----------
### Michael Mollica
1. The overall project approach of tapping into existing sensors worked tremendously well. Additionally, the steering system using a rotary encoder was a fantastic approach to capturing steering angle. However, our initial choice of local MCUs for each subsystem did not go well. This was a failure and ended up being almost completely void by the end of the project. The subsystem breakdown and organization was a success regardless of the modifications made to the design choices.
2. The largest unanticipated problem was the UART communication with 4 MCUs. This was almost never working properly and should have never been the approach to the system design in the first place. The other slight problem was the shifter debouncing when switching from neutral to drive or reverse. This was discovered late in the process of experimentation but was able to be fixed with some software changes.
3. I would make the system dependent on a single MCU for each subsystem because of the issues with UART. This was the most avoidable issue, but also the biggest setback in our project.
4. Some best practices I have learned through this project is to heavily document and comment code, keep all old and new versions of code, keep track of all experimental results, and never assume something will work without testing it.
5. Do not expect everything to work how it was designed. There is so many extraneous errors and mistakes that can occur when physically connecting devices and when designing complex systems. Always have a backup plan and always test your devices extensively.
6. I have learned to program in Arduino much better than I had early in college. I have also learned a lot more about how serial communication works and its proper use.

### Brett Harden
1.
2.
3.
4.
5.
6.

### Chase Colotta
1.
2.
3.
4.
5.
6.

### Gerardo Mateo
1.  Overall, as a group, we were able to accomplish the project. At the start of the semester, there were some challenges in understanding the project goal. Eventually, the group understood its goal by working hard and being patient. Furthermore, both technical and organization meet the requirement that the team wanted. However, during the planning of the subsystem, we were able to break down and find the right equipment for each subsystem. Although each sensor worked perfectly, the local MCU did not, so the team decided to reduce the number to one. On the other hand, each of the new modifications to the project helped to improve and complete our project.
2. The unanticipated problem that occurred in my subsystem was that it needed a pull-down resistor. Because of this, Arduinos were unable to determine the ground state. However, the major unanticipated problem was that simulation was not working since the group needed it to put data into the simulation. However, the group was aware that we were able to extract data from the sensor.
3. If I were to start over, I would do more research and finish the assignment early. In addition, a better understanding of how the sign-off work early would help reduce stress and time waste.
4.  Communication with teammates and asking for help when needed are the best practices I picked up. Furthermore, documenting information and commenting on your code makes it easier to understand what you're doing and where you're stopping. Also, giving good detail on what your subsystem does will help you in the future.
5. The word of wisdom I would give is to do your research early and have a backup plan for each subsystem or whole project. Also, save other information even if you don't need it because it could help you in the future. Also, the major wisdom is communicating with the team and helping each other if needed. However, alway expect the unexpect in each subsystem or project.
6. What I learn from the project is to communicate with the team and document information in good detail for others to understand what I'm doing. Also, I learned to plan on a wiring diagram and show the connection of the circuit that I'm creating. Overall, I learned how to plan early in the project and how to document each piece of information I gather.

### Ethan Powers
1. Overall, I think the project went well. Tapping into the OEM sensors of the car proved to be the most successful way to capture all of the inputs. The main failure for the project was the intention of using 3 local MCUs. The master MCU could only handle UART communication for one local MCU, so this proved to be a major problem. Steering and pedals were changed to send inputs to master MCU, so the problem was fixed. Having everything organized in github made the completion of the project much easier.
2. An unanticipated problem was the simulator not working. This led to the team to not be able to send inputs and receive outputs from it. This didn't play a huge portion in the success of the project, but it would have been exciting to see the car talking with the simulator. The other unanticipated problem was mentioned in the answer for question 1.
3. I would do more research before trying to complete the conceptual design. The conceptual design differed completley from the end product. This ended up in more work for sign offs. This made the sign off portion of the class a lot more stressful.
4. The best practices I picked up on were to make sure to document everything you change in the project and make sure that your subsystem works before permanently installing hardware. 
5. Do your research early and get ahead early. The more deadlines you make, the easier your life is.
6. I learned how to program with Arduino and experiment with wiring diagrams to confirm that they are true. 
