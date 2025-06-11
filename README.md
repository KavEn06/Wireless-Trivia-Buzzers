# Wireless-Trivia-Buzzers
### What is it?
There will be four buzzer boxes and one main box. Each buzzer box will represent a team (Teams A, B, C, and D) and will have four buttons, one for each player. The main box will house a screen that allows the host to see which player buzzed in first and will also include a reset button to clear all buzzes. For the time being, I plan to include two modes. The first mode allows only one player per team to buzz in, any player from the team can buzz, but only the first buzz from that team will register. The second mode is a free-for-all, where all 16 players can buzz in individually, regardless of their team.


### Backstory 
Basically this idea came to me while me and a couple of friends were practicing for a trivia competition that my school's Classics club hosts semi-annually (with other neighboring schools). I realised that many other schools didn't have the funds to buy the "official" buzzers that all the other schools use, which means that they just end up using some horrible online version, which are very dependent on how good your wifi is. Moreover, these buzzers we're SO HEAVY and annoying to set up that half the time my friends and I didn't even bother practicing because we were too lazy to set up the buzzers and get an actual competition environment going. 

## Architecture & Features 
### Hardware
- **Display:** 16x2 LCD With an I2C Module
- **Chip:** ESP32
- **Audio:**
  - **DAC:** MAX98357A
  - **Speakers:** 2W Speakers
- **Power:** 9V Battery or USB-C 

## Pictures 
### 3D Model 
![image](https://github.com/user-attachments/assets/e28ae017-b513-4b40-aab7-b06232eab597)

### Wiring Diagram
![image](https://github.com/user-attachments/assets/8b03c6c4-4ca9-46d7-a5f0-7e7be569c1c8)

### PCBs 
Buzzer Box 
![image](https://github.com/user-attachments/assets/8a144d44-c1fa-4a74-a6e0-8566e701df20)

Main Box 
![image](https://github.com/user-attachments/assets/e3c7e530-1372-4cdb-bb72-d670ad8c960f)

## BOM 
| Item                          | Purpose     | Source                                                                 | Price    | Inventory         |
|-------------------------------|-------------|------------------------------------------------------------------------|----------|--------------------|
| 5x ESP32 (38 Pin) Dev Board   | Controller  | [Link](https://www.aliexpress.us/item/3256806817804532.html)           | $32.10   | Owned              |
| 16x2 LCD with I2C Module      | Output      | [Link](https://www.aliexpress.us/item/3256806005226720.html)           | $3.47    | Owned              |
| Speakers                      | Output      | [Link](https://www.aliexpress.us/item/3256806149654656.html)           | $2.99    | Owned              |
| 5 LEDS                        | Output      | [Link](https://www.aliexpress.us/item/2251832691865341.html)           | $2.53    | Owned              |
| MAX98357A                     | Output      | [Link](https://www.aliexpress.us/item/3256806882501011.html)           | $2.53    | Owned              |
| 17x Push Buttons              | Input       | [Link](https://www.aliexpress.us/item/4000097252595.html)              | $10.25   | Owned              |
| 16x Charger Wires (Any work) | Input       | [Link](https://www.aliexpress.us/item/3256806607225844.html)           | $14.43   | Owned              |
| Micro SD Card Module          | Input       | [Link](https://www.aliexpress.us/item/3256806271288305.html)           | $1.28    | Highway Provided   |
| 5x USB-C Port                 | Input       | [Link](https://www.aliexpress.us/item/3256805808963508.html)           | $4.11    | Owned              |
| 5x 9V Battery                 | Power       | [Link](https://www.amazon.com/Amazon-Basics-Performance-Batteries/dp/B00MH4QM1S) | $12.69   | Highway Provided   |
| 5x 9V Battery Connector       | Power       | [Link](https://www.aliexpress.us/item/3256803502287504.html)           | $2.21    | Owned              |
| 5x DC - DC Buck Converter     | Power       | [Link](https://www.aliexpress.us/item/3256807145249789.html)           | $4.65    | Highway Provided   |
| 5x 3 Way (SPDT) Switch        | Switch      | [Link](https://www.aliexpress.us/item/3256806160134969.html)           | $3.29    | Highway Provided   |
| 2.54mm Headders               | Connector   | [Link](https://www.aliexpress.us/item/3256805470972473.html)           | $3.12    | Highway Provided   |
| Buzzer Box PCB                | PCB         | JLCPCB                                                                 | $15.00   | Highway Provided   |
| Main Box PCB                  | PCB         | JLCPCB                                                                 | $15.00   | Highway Provided   |
| **Total:**                    |             |                                                                        | **$129.65** |                    |
| **Total (Highway Provided):**|             |                                                                        | **$55.03**  |                    |
