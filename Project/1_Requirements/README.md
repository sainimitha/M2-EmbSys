# **AUTOMATIC WATERING PLANTS**

## **ABSTRACT**
As we know that plants are the essential part of our life. Plants always need good care for their growth. Plants may not survive when there is any deficiency of nutrition in the soil and environment. So, through this project we will make our gardens take care of itself. In this project the sensor we have used monitors the soil moisture and air temperature of the plants and then automatically it starts watering the plant on the basis of the data received from various sensors in our project. Maintenance and monitoring of our plants and gardens are important. We have to maintain the plants regularly so that they can also be prevented from pests. That is why this project helps the garden care for itself if someone is not present for their maintanance.

## **DESCRIPATION**
Plants play a vital role in maintaining the carbon dioxide and oxygen in air. Many plants die due to urbanization. But apart from it plants also die due to lack of maintenance. Gardening is a healthiest hobby anyone can adopt. But they need continuous care without break. So the main aim of this project is to provide proper care to the plants. This project will also ease the gardening. It is built using AVR Microcontroller and bunch of electronic sensors.. In this project we have used soil moisture sensor for calculating the moisture in the soil .The controller is interfaced with the LCD display where it displays the data received from various sensors. The controller is programmed using embedded C.

## **REQUIREMENTS**

- **HIGH LEVEL REQUIREMENTS**

|HLR_ID|High Level Requirements|
---|---|
|HLR01|It shall have a Microcontroller|
|HLR02|It shall have Sensors|
|HLR03|It shall have Switch|
|HLR04|It shall have a Display|

- **LOW LEVEL REQUIREMENTS**

|LLR_ID|Low Level Requirements|
---|---|
|HLR01_LLR01|It shall have a Microcontroller(ATmega32) to recieve/transmit the data|
|HLR02_LLR02|It shall have a Soil Moisture Sensor to detect the moisture in the soil|
|HLR02_LLR03|It shall have a Temperature and Humidity Sensor to detect the humidity in the air|
|HLR03_LLR04|It shall have a Relay Module which is used as an automatic switch|
|HLR03_LLR05|It shall have a LED which is uesd to blink when the switch ON|
|HLR04_LLR06|It shall have a 16x2 LCD which is used to display the moisture of the soil, humidity in the air|

## **COMPONENTS DESCRIPATION**

-  ###### Microcontroller
An integrated circuit that contains a microprocessor along with memory and associated circuits and those controls some or all the functions of an electronic device (such as a home appliance) or system.

- ##### ATmega32
The AVR microController is based on the advanced Reduced Instruction Set Computer (RISC) architecture. ATmega32 microController is a low power CMOS technology based controller. Due to RISC architecture AVR microcontroller can execute 1 million of instructions per second if cycle frequency is 1 MHz provided by crystal oscillator.

- ##### Temperature and Humidity Sensor
The DHT11 is a commonly used Temperature and humidity sensor that comes with a dedicated NTC to measure temperature and an 8-bit microcontroller to output the values of temperature and humidity as serial data.

- ##### Soil Moisture Sensor
The moisture sensor measures the volumetric water content of the soil with the help of a sensing probe which must be put into the soil. The sensor module operates between voltages of 3.3 V to 5V. 

- ##### LED
Light-emitting diode (LED) is a widely used standard source of light in electrical equipment. It has a wide range of applications ranging from your mobile phone to large advertising billboards.

- ##### Relay Module
A 5v relay is an automatic switch that is commonly used in an automatic control circuit and to control a high-current using a low-current signal. The input voltage of the relay signal ranges from 0 to 5V.

- ##### 16X2 LCD
LCD (Liquid Crystal Display) is a type of flat panel display which uses liquid crystals in its primary form of operation. LEDs have a large and varying set of use cases for consumers and businesses, as they can be commonly found in smartphones, televisions, computer monitors and instrument panels.

## **ADVANTAGES**
- Just the right amount of water will be released.
- The water will be directed to exactly where it is needed. 
- An automatic shut off can help to keep water usage to a minimum.
