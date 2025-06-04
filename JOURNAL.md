---
title: "Wireless Trivia Buzzers"
author: "KavEn06"
description: "Wireless trivia buzzers that can have up to a team of 4. They're designed to be portable, which means that you can take them anywhere you want!!!"
created_at: "2025-05-24"
---

# Buzzer Creation Journal 
## 05-24-2025: Planning 
### Backstory (kinda)
Basically this idea came to me while me and a couple of friends were practicing for a trivia competition that my school's Classics club hosts semi-annually (with other neighboring schools). I realised that many other schools didn't have the funds to buy the "official" buzzers that all the other schools use, which means that they just end up using some horrible online version, which are very dependent on how good your wifi is. Moreover, these buzzers we're SO HEAVY and annoying to set up that half the time my friends and I didn't even bother practicing because we were too lazy to set up the buzzers and get an actual competition environment going. 


### What is it?
There will be four buzzer boxes and one main box. Each buzzer box will represent a team (Teams A, B, C, and D) and will have four buttons—one for each player. The main box will house a screen that allows the host to see which player buzzed in first and will also include a reset button to clear all buzzes. For the time being, I plan to include two modes. The first mode allows only one player per team to buzz in—any player from the team can buzz, but only the first buzz from that team will register. The second mode is a free-for-all, where all 16 players can buzz in individually, regardless of their team.


### Tech
* All 4 buzzer boxes and the main box will be controlled by an ESP-32 and will communicate with each other using ESPNOW
* All the boxes will be battery powered (now that I type this, I realise that a USB-C port would be nice so that the buzzers have another power source)
* Each buzzer box will have four LEDs that light up depending on which player buzzes in
* For the screen on the main box, it will be a 16x2 LCD with an I2C module

![image](https://github.com/user-attachments/assets/6ec0af28-5e6d-420f-bcab-68f780e055d8)

### Things Todo
* Deciding if implementing speakers into the main box is feasible
* What type of battery to use (AA or rechargeable)
* Designing the PCB
* Deciding how I want the boxes to look (maybe like an old Mac or just a plain old box to house the electronics)
* Designing the enclosures

**Total time spent: 4h**


## 05-25-2025: Circuit Design & BOM 
### Circuit Design (Changes) 
* Implemented 9V power source (stepped down to 5V) and 5V USB-C input, controlled by a SPDT switch
* Added MAX98357A amp, 2 speakers and a micro SD card module (so that the buzzer can actually "buzz" when a player buzzes in)

![image](https://github.com/user-attachments/assets/8b03c6c4-4ca9-46d7-a5f0-7e7be569c1c8)


### BOM (Unfinished) 
| Item                                       | Purpose    | Source | Price |
|--------------------------------------------|------------|--------|-------|
| 5x ESP32 (38 Pin) Dev Board                | Controller |        |       |
| 16x2 LCD with I2C Module                   | Output     |        |       |
| Speakers                                   | Output     |        |       |
| 17x Push Buttons                           | Input      |        |       |
| 16x Charger Wires (Any work)               | Input      |        |       |
| Micro SD Card Module                       | Input      |        |       |  
| 5x 9V Battery                              | Power      |        |       |
| 5x 9V Battery Connector                    | Power      |        |       |
| 5x DC - DC Buck Converter                  | Power      |        |       |
| 5x 3 Way (SPDT) Switch                     | Switch     |        |       |
| 4x Buzzer Box PCB                          | PCB        |        |       |
| 1x Main Box PCB                            | PCB        |        |       |

### Things Todo
* Designing the 2 PCBS on KiCAD
* Making the enclosures
* Coding the main and buzzer boxes

**Total time spent: 2.5h**

## 05-27-2025: Buzzer Box PCB 
### KiCAD
* Learned how to use KiCAD for the first time and created the PCB for the buzzer box
![image](https://github.com/user-attachments/assets/8a144d44-c1fa-4a74-a6e0-8566e701df20)

**Total time spent: 2h**


## 06-04-2025: More Circuit Design 
### Main Buzzer PCB
- Finished the main buzzer PCB and made sure that the SD module, MAX98357A, and DC-DC buck converter can all fit in the same footprint as the PCB (so it doesn't take up any extra room in the box)
- I didn't bother with silkscreen art for the main box, as both sides have markings that show where the other boards connect to
- The normal buzzer PCBs didn't get silkscreen because I was just too dead to learn it after spending 2 hours trying to figure my way through KiCAD 💀💀💀
- On a separate note, this PCB, I learned how to make custom symbols and footprints 
![image](https://github.com/user-attachments/assets/e3c7e530-1372-4cdb-bb72-d670ad8c960f)
(The connectors for the SD card module are on the back of the board on the same side that the 9V battery is going to be on)

### Things Todo
- I have to make 2 simple boxes to house the components for both types of boxes
- I have already started on some basic ESP-NOW code to get various boxes working between each other, but I still have to implement the actual buzzer rules
- For the code for the main box, I have to add code to read files from the SD card and play it through the speakers
- Then I can submit my application!!!!!! 

**Total time spent: 2h**
