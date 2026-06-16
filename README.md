# AirPoint-ESP32-Mouse
This is an easy ESP32 Air mouse project which uses BLE (Bluetooth Low Energy) for connecting to any other devices like Laptop, PC, Smart TVs, Projectors, and even mobiles and tablets. So we can say that its universal Air mouse.


<details>
<summary>Bill of Materials (BOM)</summary>

| Item | Purpose | Source | Cost |
|------|---------|---------|------|
| ESP32 Dev Module | Main microcontroller | Amazon | $5.70 |
| 12x12mm Tactile Push Buttons (x4) | Left click, right click, scroll up, scroll down | Amazon | $0.87 |
| TP4056 Charging Module | Battery charging | Amazon | $1.32 |
| 3.7V Li-ion Battery (18650) | Power source | Amazon | $4.14 |
| MPU6050 Accelerometer/Gyroscope | Motion detection | Amazon | $3.00 |
| PLA Filament | 3D printed enclosure | Amazon | $7.25 |
| PCB | Custom circuit board | JLCPCB | $6.40 |
| **TOTAL COST** |  |  | **$25.39** |

</details>
 

Wiring diagram:-

<img width="934" height="385" alt="PCB circuit" src="https://github.com/user-attachments/assets/052d1143-b23f-4908-9af7-053f22d302bb" />


Once completing the circuit diagram and coding, I was wondering if it works, so I made a prototype version of AirPoint with breadboard.

<img width="2448" height="3264" alt="IMG20260417190248" src="https://github.com/user-attachments/assets/01dea107-ed69-4367-83c6-f93a2724b5ab" />
<img width="3264" height="2448" alt="IMG20260416180500" src="https://github.com/user-attachments/assets/32916d1b-e715-46dd-b6b5-91c561d1e330" />


Now the thing was, It worked perfectly but I had powered it with USB Cable and I wanted such battery which would give more power and for long time, so I started working on it.

<img width="2448" height="3264" alt="IMG20260418193315" src="https://github.com/user-attachments/assets/caa2fff8-9b8d-487c-bf15-0959aa506be2" />

And now, I was going to use the 18650 li-ion battery 3.7v with 3000mAh and Tp4056 charging module for charging which perfectly worked fine. 


Now the time was to make my own custom case for it, So I started designing one and it looked like this...

<img width="724" height="378" alt="Screenshot 2026-05-28 190233" src="https://github.com/user-attachments/assets/bcb52a59-0352-4e69-b305-e6b144a4f502" />

If you want, you can even change the colours of the case accordingly, as I have provided the file of CAD, you can now print the case with ease.


Now the thing is, I am using breadboard for the final project and you can too but if you are feeling lazy then you can use PCB too, so I have provided the PCB gerber files and it may cost around 6-7$ (Depends from where you are buying it,I used JLC PCB), This is how the PCB will look like...

<img width="1055" height="428" alt="Screenshot 2026-05-03 164901676767" src="https://github.com/user-attachments/assets/7a0e02cb-05e7-42db-b3b4-ddc42c9a0f82" />

(NOTE :- If you are really using PCB for project then do remember to attach wires from switch to the PCB as the PCB will be at the bottom of the case and Switch may not reach the sufficient height.)


That's it!!, You just created your own ESP32 based Air Mouse and now you are ready to use it. 


How to use it? 
Turn on the bluetooth of device(ex- phone or smart TV), and connect the device with AirPoint, You will see that the cursor is moving by the AirPoint, the upper two buttons are RMB and LMB, and the bottom and verticle buttons are for scrolling.


Goal:
For how long are we using the mouse which just rubs against the surface, to be futurastic, I made my own custom air mouse, AirPoint.


Here's the zine page of my Project....

<img width="1398" height="2000" alt="Airpoint (1)" src="https://github.com/user-attachments/assets/b7ca039f-89c4-4329-a894-f8dfcfdb7a6b" />

see ya!!!! :)
