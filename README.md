# 4-Wheeled Object Controlled by Flex Sensor and Microcontrollers

## Overview

This project involves a 4-wheeled object that is controlled using two microcontrollers. The system is designed to move in different directions based on the input from a flex sensor. One microcontroller handles the flex sensor, while the other manages the LCD, motors, and IR sensor. The communication between the microcontrollers allows the object to respond to the flex sensor’s readings, displaying the voltage and direction on an LCD and moving the wheels accordingly.

## Components

- **Flex Sensor**: Detects the angle and provides corresponding voltage values.
- **Microcontroller 1**: Connected to the flex sensor, transmits voltage values.
- **Microcontroller 2**: Connected to the LCD, motors, and IR sensor, receives voltage values and controls the movement.
- **LCD Display**: Shows the voltage and the detected direction.
- **Motors**: Drive the wheels of the object.
- **IR Sensor**: Used for obstacle detection and avoidance.

## Functionality

1. **Flex Sensor Angles and Corresponding Actions**:
    - **0°**: Motors stop.
    - **45°**: Motors move forward.
    - **90°**: Motors move backward.

2. **Process Flow**:
    - The flex sensor detects the angle and outputs a corresponding voltage.
    - Microcontroller 1 reads the voltage from the flex sensor.
    - Microcontroller 1 transmits the voltage value to Microcontroller 2.
    - Microcontroller 2 interprets the voltage value to determine the direction:
        - **0° (Voltage Value X)**: Display "Stop" on the LCD, motors stop.
        - **45° (Voltage Value Y)**: Display "Forward" on the LCD, motors move forward.
        - **90° (Voltage Value Z)**: Display "Backward" on the LCD, motors move backward.
    - The LCD displays the voltage and the direction.
    - The motors adjust their movement based on the direction.

## Usage

1. **Setup**:
    - Connect the flex sensor to Microcontroller 1.
    - Connect the LCD, motors, and IR sensor to Microcontroller 2.
    - Establish communication between the two microcontrollers.

2. **Operation**:
    - Power on the system.
    - Adjust the flex sensor to one of the three angles (0°, 45°, 90°).
    - Observe the LCD for voltage and direction display.
    - The motors will move the object in the indicated direction.

## Future Enhancements

- Integrate additional sensors for more precise control and obstacle detection.
- Implement wireless communication between the microcontrollers.
- Enhance the display to show more detailed information and diagnostics.
