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
