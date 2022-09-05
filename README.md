# TheRealTemperature
Project for 5th semester subject Internet of Things. 

## Description
The aim of the project is to create the thermometer showing the current outdoor temperature based on the measurements from two sides of the building - one measurement is taken in the sun, whilst the second - in the shade. Project was realized with the use of Arduino Uno as the main device displaying the temperature and two NodeMCUs as devices measuring it. 

## Technologies used
- **NodeMCU**: measures temperature and sends it to ThingSpeak
- **ThingSpeak**: collects data from NodeMCUs
- **Python**: takes data from ThingSpeak and forwards it to Arduino Uno by sending the data to the Serial to which Arduino is connected to
- **Arduino**: calculates the temperature and displays it on a screen
