## Manual Oil Dispenser

This project is desired to fill bottles or containers with mustard oil of desired input weight by reading value of weighing scale and utilising the signal produced as input in our microcontroller (Arduino Mega)

PS- I have used RS232 communication and it is based on very old technology and required lot of research and 2 guys on arduino forum helped me out to make this possible within one week!! Reference - (https://forum.arduino.cc/index.php?topic=590774.0)

I am planning to add flow sensor and pump in version 3.0

- Initial stage AKA V1.0
  - Started as scratch project and planned to utilise RS232 signals from weighing scale and fill containers with help of desired weight
  - Struggled with RS232 communication with arduino which was a hassle as it is old technology and no documentation was available on internet.
  - Posted my problem on arduino forum and obtained solution within one week!
  - Made air-tight container with industrial grade buttons
  
- Version 2.0
  - I made connector which required 4 different wires and was difficult sometimes as wires came loose!
  - Changed this problem by adding DJ speaker style connector.
  - Wiring was a mess, Re-Wired the stuff and changed connectors.
  - Added I2C in LCD to bring down cluttering of wires!
  
- Version 3.0 (Beta Version)
  - Planning to add flow meter and pump for more precise filling!
  
# Parts Required:
- For Manual Input:
  - Arduino Mega
  - 16X2 LCD Display (Optionally I2C or OLED display)
  - 5v Relay
  - 12v Solenoid Valve
  - 10k Ω potentiometer
  - 1N4148 diode (Back EMF Protection) (Relay contains one, so not so necessarly required!)
  - 220Ω resistors
  - 1k Ω resistors
  - Wiring
  - Basic Equipments like soldering iron, plyers and others
  
# Using RS232 communication

This was a great deal to me work with RS232 communication as it is more retro style technology and no documentation was available!

RS232 to TTL converter which has MAX3232 IC helps to get analog signals as per baudrate provided by weighing machine manufacturer (Manufacturer did not helped me out and gave me no documentation regarding anything!!)

Wasted 5 days with faulty RS232 to TTL converter! Ordered a new converter which had THT MAX3232 IC and worked smoothly, got it working within few hours!!
  
Weight from weighing machine was in format like + 000.000 KG so got rid of the gaps and +, KG which is not required in comparing to input weight!

#
