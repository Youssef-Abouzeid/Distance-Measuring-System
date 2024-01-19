Project Title: Ultrasonic Distance Measurement System with ATmega32

Description:
This repository contains the implementation of a distance measurement system using an ultrasonic sensor (HC-SR04) and an ATmega32 microcontroller with a frequency of 8MHz. The project follows a layered architecture model, consisting of GPIO, ICU, LCD, and Ultrasonic drivers.

### System Requirements:
1. ATmega32 Microcontroller with a frequency of 8MHz.
2. Ultrasonic sensor HC-SR04 for distance measurement.
3. 4x16 LCD for displaying distance values.

### Layered Architecture Model:
1. **GPIO Driver:**
   - Utilizes the GPIO driver implemented in the course.
  
2. **ICU Driver:**
   - Utilizes the ICU driver implemented in the course.
   - Configures ICU with frequency F_CPU/8, detecting the rising edge as the first edge.
   - `ICU_init` and `ICU_setCallBack` functions called inside `Ultrasonic_init` function.

3. **LCD Driver:**
   - Utilizes the LCD driver implemented in the course with 8-bits data mode.
   - Connects LCD control pins and 8-bits data pins as specified.

4. **Ultrasonic Driver:**
   - Implements a full ultrasonic driver using the ATmega32 ICU driver.
   - Contains the following functions:
      - `void Ultrasonic_init(void)`: Initializes the ICU driver, sets up the ICU callback function, and configures the trigger pin as an output through the GPIO driver.
      - `void Ultrasonic_Trigger(void)`: Sends the trigger pulse to the ultrasonic sensor.
      - `uint16 Ultrasonic_readDistance(void)`: Initiates the measurement by triggering the pulse and returns the measured distance in centimeters.
      - `void Ultrasonic_edgeProcessing(void)`: Callback function called by the ICU driver to calculate the high time (pulse time) generated by the ultrasonic sensor.

### Project Hardware Connections:
- ATmega32 Microcontroller with 8MHz frequency.
- Ultrasonic sensor HC-SR04 connected to appropriate GPIO pins.
- 4x16 LCD connected to specified control pins and data bus.

### How to Use:
1. Clone the repository.
2. Set up the hardware connections as described in the project documentation.
3. Build and upload the code to the ATmega32 microcontroller.
4. Monitor the distance measurements displayed on the connected 4x16 LCD.

Feel free to refer to the provided documentation and source code for a detailed understanding of the implementation and hardware connections.

Note: Refer to the "HC-SR04 Ultrasonic MT Student Tutorial" PDF file for additional information on interfacing with the HC-SR04 sensor.
