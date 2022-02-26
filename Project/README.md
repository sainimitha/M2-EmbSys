# **TEMPERATURE BASED FAN SPEED CONTROLLER**

## **ABSTRACT**
This project is a standalone automatic fan speed controller that controls the speed of an electric fan according to our requirement. Use of embedded technology makes this closed loop feedback control system efficient and reliable. Microcontroller (ATMega328) allows dynamic and faster control. Microcontroller is the heart of the circuit as it controls all the functions.
The temperature sensor LM35 senses the temperature and converts it into an electrical signal, which is applied to the microcontroller. The sensed temperature values are simultaneously displayed on the LCD panel. The microcontroller drives motor driver to control the fan speed. This project uses regulated 12V, 2A power supply. This project is useful in process industries for maintenance and controlling of Boilers temperature.


## **INTRODUCTION**
Nowadays, the humankind is moving towards the new technologies by replacing the manual operations to automatically controlled devices. One of the basic requirements of the people during hot weather is a cooling fan. But, the speed of the fan can be controlled by manual operation using a manual switch namely fan regulator or dimmer. By turning the dimmer, the fan speed can be altered. It can be watched in some places like where the temperature is high during the morning though the temperature falls radically at night time. The users do not understand the difference in temperature. So to overcome the speed of the fan here is a solution to vary according to temperature. This concept is particularly applicable for areas like where temperature changes radically during day and night time. This project will convert the manual fan into automatic fans. The automatic fans will change their speed according to the temperature in the room.The temperture is displed on LCD Diaplay.


## **REQUIREMENTS**

- **HIGH LEVEL REQUIREMENTS**

  |HLR_ID|High level Description|
  ---|---|
  |HLR01|It shall have a Sensor|
  |HLR02|It shall have a Microcontroller|
  |HLR03|It shall have a Fan|
  |HLR04|It shall have a Display|

- **LOW LEVEL REQUIREMENTS**

  |LLR_ID|Low level Description|
  ---|---|
  |HLR01_LLR01|It shall have a Temperature sensor(LM35) to measure the temperature of the room|
  |HLR02_LLR02|It shall have a Microcontroller(ATmega328) to recieve/transmit the data|
  |HLR03_LLR03|It shall have a Motor Driver to drive the motor|
  |HLR03_LLR04|It shall have a Motor to Spin the fan|
  |HLR04_LLR05|It shall have a LCD Display(16X2) to display the temperture of the room| 



## **BLOCK DIAGRAM**

![Block_Diagram](https://user-images.githubusercontent.com/82401251/155829374-2bc50693-b53f-44f0-a7a2-493ad50f98e9.jpg)


## **SYSTEM DESIGN**
![System_Design](https://user-images.githubusercontent.com/82401251/155829407-d175228f-532f-43ff-a1e6-623fe86b6f96.jpg)


## **SUB-SYSTEM DESIGN**

- ###### Temperature Sensor
![Temp_sensor](https://user-images.githubusercontent.com/82401251/155829430-69dfbdf4-8e18-479d-82a5-5890bdd63461.jpg)

- ###### Motor Driver
![Motor_Driver](https://user-images.githubusercontent.com/82401251/155829441-028f8f0d-8781-414c-803c-7326ae053076.jpg)

- ###### DC motor
![DC_Motor](https://user-images.githubusercontent.com/82401251/155829443-ef79445e-574d-4c23-baef-0e214194746f.jpg)

- ###### LCD Display
![LCD_Display](https://user-images.githubusercontent.com/82401251/155829447-29c77360-9d51-42b6-aefa-786347ccd581.jpg)

## **COMPONENT DESCRIPTION**

-  ###### Microcontroller
An integrated circuit that contains a microprocessor along with memory and associated circuits and those controls some or all the functions of an electronic device (such as a home appliance) or system.

-  ###### Temperature Sensor
A temperature sensor is a device that is designed to measure the degree of hotness or coolness in an object. The working of a temperature meter depends upon the voltage across the diode.

- ###### DC Motor
A DC motor is an electrical machine that converts electrical energy into mechanical energy. In a DC motor, the input electrical energy is the direct current which is transformed into the mechanical rotation.

- ###### Motor Driver
The motor driver IC is an integrated circuit chip used as a motor controlling device in autonomous robots and embedded circuits. A motor driver is undoubtedly something that makes the motor move as per the given instructions or the inputs (high and low).

- ###### LCD
LCD (Liquid Crystal Display) is a type of flat panel display which uses liquid crystals in its primary form of operation. LEDs have a large and varying set of use cases for consumers and businesses, as they can be commonly found in smartphones, televisions, computer monitors and instrument panels

## **ADVANTAGES**
- It is economical and easy to handle
- Fan runs automatically
- It is easy to install in heat dissipating devices to cool them down
- Saves energy by turning off fan automatically at room temperature

## **APPLICATIONS**
- It can be used to control the temperature of devices, rooms, electronic components, etc
- It can be used as cooling pads for laptops or computers
- This device is used for cooling the car engine.