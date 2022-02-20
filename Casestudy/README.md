# AIR CONDITIONER

## INTRODUCTION
 Air conditioning can be defined as the treatment of indoor air in order to control certain conditions required for human comfort. The desirable conditions may be temperature, humidity, dust particle level, odour level, and air motion.

## REQUIREMENTS

* ## High Level Requirements

     |HLR(ID)|High Level Requirements|
     ---|---|
     |HLR01|Remote controls|
     |HLR02|How accuracy the controller receives data|
     |HLR03|Input power|
     |HLR04|Connectivity|
     |HLR05|Spontaneity output|

* ## Low Level Requirements

     |LLR(ID)|Low Level Requirements|
     ---|---|
     |LLR01_HLR01|Temperature sensor|
     |LLR02_HLR01|Humidity sensor|
     |LLR03_HLR01|Input Motor speed|
     |LLR04_HLR01|Led Blinking|
     |LLR05_HLR02|Microcontroller|
     |LLR06_HLR03|Power Management|
     |LLR07_HLR04|Bluetooth Module|
     |LLR08_HLR04|ZigBee|
     |LLR09_HLR05|Buzzer|
     |LLR10_HLR05|Display(LCD)|
     |LLR11_HLR05|Compressor|

## SYSTEM DESIGN
![IMG-20220218-WA0006](https://user-images.githubusercontent.com/77672209/154807400-fc5f94b5-f260-4e7f-a2ad-eaa1d8d1f99c.jpg)

## SUB - SYSTEM DESIGN
* #### Temperature Sensor
![Temperature sensor](https://user-images.githubusercontent.com/77672209/154807494-4863bfcd-5aad-4c3d-8bd2-2184af73f30d.jpg)

* #### Humidity Sensor
![Humidity sensor](https://user-images.githubusercontent.com/77672209/154807545-407b77a1-3b36-4629-97bd-2e8a81069f8f.jpg)

* #### LED
![LED drive circuit-Page-2](https://user-images.githubusercontent.com/77672209/154807591-baf37480-2bf8-45a8-8c20-ca953a4f54c7.jpg)

* #### Bluetooth
![Bluetooth solution-Page-3](https://user-images.githubusercontent.com/77672209/154807629-5e668d81-379d-44a1-a2e2-258de07d2976.jpg)

* #### ZigBee
![Zigbee-Page-2](https://user-images.githubusercontent.com/77672209/154807656-5ab67058-79e5-49d8-a935-28adbda6eb1d.jpg)

* #### Power Management Unit 
![power management unit-Page-2](https://user-images.githubusercontent.com/77672209/154807689-b82bd09b-a782-441a-bfa7-93ad7accef96.jpg)

* #### Buzzer
![Zigbee-Page-2](https://user-images.githubusercontent.com/77672209/154807711-a5eff76e-409c-48d4-99a0-ef170a312b1a.jpg)

* #### LCD Display
![Bluetooth solution-Page-4](https://user-images.githubusercontent.com/77672209/154807734-8f040dee-0636-4822-a2f4-dece8867dc55.jpg)

* #### Compressor
![compressor-Page-2](https://user-images.githubusercontent.com/77672209/154807750-e033992c-fee7-499e-a3b2-a9b883a7e5ca.jpg)

## COMPONENTS DESCRIPTION

* #### Microcontroller
An integrated circuit that contains a microprocessor along with memory and associated circuits and that controls some or all of the functions of an electronic device (such as a home appliance) or system.

* #### Bluetooth
Bluetooth is an open wireless technology standard for transmitting fixed and mobile electronic device data over short distances.

* #### ZigBee
ZigBee is an open global standard for wireless technology designed to use low-power digital radio signals for personal area networks.

* #### DAC
Digital-to-Analog Converter (DAC) is a device for converting Digital signals into corresponding Analog signals.

* #### ADC
Analog-to-Digital Converter (ADC) is a device for converting Analog signals into corresponding Digital signals.

* #### LCD
LCD (Liquid Crystal Display) is a type of flat panel display which uses liquid crystals in its primary form of operation. LEDs have a large and varying set of use cases for consumers and businesses, as they can be commonly found in smartphones, televisions, computer monitors and instrument panels.

* #### Octo-Coupler
Opto-coupler is an electronic component that transfers electrical signals between two isolated circuits. Optocoupler also called Opto-isolator, photo coupler or optical isolator.

* #### Motor
a device that changes electricity or fuel into movement and makes a machine work

* #### Memory
Memory is an important part of embedded systems. The cost and performance of an embedded system heavily depends on the kind of memory devices it utilizes.

* #### RAM
 Random access memory (RAM) is a computer's short-term memory, which it uses to handle all active tasks and apps. It is a hardware device generally located on the motherboard of a computer and acts as an internal memory of the CPU. 

* #### ROM
ROM, which stands for read only memory, is a memory device or storage medium that stores information permanently. It is also the primary memory unit of a computer along with the random-access memory (RAM). It is called read only memory as we can only read the programs and data stored on it but cannot write on it. 

* #### Power Management Unit
The PMU is a microcontroller, or integrated circuit, that controls the power functions of Macintosh computers. Though it is not a large component, the PMU contains several parts, including memory, software, firmware, and its own CPU. 

* #### Moto Driver
The motor driver IC is an integrated circuit chip used as a motor controlling device in autonomous robots and embedded circuits. 

* #### Temperature Sensor
A temperature sensor is a device that is designed to measure the degree of hotness or coolness in an object. The working of a temperature meter depends upon the voltage across the diode. 

* #### Humidity sensor
Humidity sensors are electronic devices enabling you to measure the environment’s humidity and convert the data into a corresponding electrical signal that can be used for different purposes.

* #### LED
Light-emitting diode (LED) is a widely used standard source of light in electrical equipment. It has a wide range of applications ranging from your mobile phone to large advertising billboards.

## SUB – SYSTEM TESTING
|Test_ID|Sub-System Test Cases|
---|---|
|TC01|Verify the functionality of the on/off button.|
|TC02|Verify if it’s working in every temperature setting.|
|TC03|Verify the minimum temperature that can be achieved by the AC.|
|TC04|Verify the maximum temperature that can be achieved by the AC.|
|TC05|Verify LED is on or not and bulb Blink Or Not when Plug in.|
|TC06|Verify if the different AC fan speeds, work correctly.|
|TC07|Verify Humidity sensor in different climate change (Moisture, Dry).|
|TC08|Verify Bluetooth device range when it is highly covered (Remote).|
|TC09|Verify Bluetooth device range when it is partially covered (Remote).
|TC10|Verify the response time between the AC remote and the AC.|
|TC11|Verify the Timer is working or not.|
|TC12|Verify Power Management unit status for high voltage.|
|TC13|Verify Power Management unit status for low voltage.|
|TC14|Verify Buzzer when turned ON/OFF.|
|TC15|Verify the information Displayed in the display panel is correct or not.|
|TC16|Verify if the display isn’t too bright or too dark.|
|TC17|Verify Compressor Motor Speed when High Voltage.|
|TC18|Verify Compressor Motor Speed when Low Voltage.|
|TC19|Verify that cooling in extra big size room.|
|TC20|Verify that cooling in extra small size room.|

## SYSTEM TESTING
|TEST_ID|System Test cases|
---|---|
|TC01|Verify the remote controls.|
|TC02|Verify how accurately Microcontroller receives data.|
|TC03|Verify Bluetooth, ZigBee connectivity.|
|TC04|Verify the Output response.|

