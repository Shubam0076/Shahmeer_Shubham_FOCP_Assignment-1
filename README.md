# DELIVERY DRONE SIMULATOR
## A Project by:
* Muhammad Shahmeer Shaheedi (565007) – Logic Designer & Tester
* Shubham Kumar (571672) – Programmer & Git Manager


<ins>**Project Overview:**</ins>
The code presented deals with a delivery drone, allowing it to make its own decisions based on weather patterns and other, later stated conditions. To be more specific, it will choose whether to delay the expedition, conduct the delivery normally, recharge, or cancel the mission and mark it as a failure altogether. It seems to be an interesting solution to optimize delivery businesses by introducing automated machines that make choices on their own to ensure the safety of the package, and even save time, considering the fact that the drone will be able to avoid the daily on-ground traffic. Along with this, it will save the company money that usually goes into hiring and paying manpower, allowing them to cut on labor costs (operational costs might not reduce significantly, though).

<ins>**Program Design/Logic:**</ins>
We allowed the system to pick random numbers to simulate real-world problems in this case. For example, we had one random number picker to simulate weather conditions (sunny, windy, or rainy) and also one to determine if there will be an obstacle in the drone’s regular route, causing the device to reroute and drain more battery for one trip.

Then, as for the main function, where we let nature and chance run their due time, we used a for loop for 3 deliveries. The loop was nested with if-else statements, each depicting the steps the drone takes automatically. For clear, sunny weather, the delivery goes normally, giving us a battery drain of 10-25 percent per trip. If the conditions are windy, and the battery is below 40 percent, the drone goes back to the station to recharge. If the weather is rainy, the delivery gets delayed. Furthermore, the presence of an obstacle in the pre-determined route causes the drone too reroute, which of course results in additional 5% battery loss.  

The flowchart for each weather-based decision made is presented below. Keep in mind that this is only one iteration of 3, which is why there is an arrow going back from END to START. This indicates the end of the prior loop/iteration and the start of a new one. Once again, this is purely based on environmental conditions. Had we made a flowchart representing all the possibilities in the code (e.g the presence of obstacles, system malfunctions, and user-commanded recharging session), it would have been a large and messy flowchart with several junctions of crisscrossing arrows and blocks so small it would be difficult to read their contents. However, we are open to the possibility of a larger, but easy to follow flowchart. The flowchart is present below:


<ins>**Execution Instruction:**</ins>
To run the code/commands, we obviously resorted to C++ and the C++ compiler, the use of which was taught during the course prior to the assignment. 

We made a few assumptions while carrying out this program. For example, whenever the user gave the instruction of battery recharging, the battery would always fill up/ reach 100 percent. Moreover, we assumed that the presence of an obstacle will always add an extra battery drain of 5%. Also, we made the random seed use the current time (time since epoch). 

When the program is run, the viewer initially sees a welcome message like so:
