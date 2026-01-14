# Arduino-bilar (Arduino Cars)

This project contains the code for simple Arduino Uno R3 driven cars designed to teach coding in real programming languages to less experienced people. The project provides an easy-to-use library that simplifies controlling motors, servos, and sensors for educational purposes.

## Installation

To use this library with your Arduino projects, you need to install the Drive library in your Arduino libraries folder:

1. Locate your Arduino folder in your Documents directory:
   - **Windows**: `C:\Users\YourUsername\Documents\Arduino\`
   - **Mac**: `/Users/YourUsername/Documents/Arduino/`
   - **Linux**: `/home/YourUsername/Documents/Arduino/`

2. Inside the Arduino folder, create a `libraries` folder if it doesn't already exist.

3. Copy the entire `Drive` folder from this repository into the `libraries` folder.

The final path should look similar to:
```
User/Documents/Arduino/libraries/Drive/
```

4. Restart the Arduino IDE if it was open.

5. You can now include the library in your sketches with: `#include <Drive.h>`

## Hardware Setup

The Drive library uses the following pin configuration for the Arduino Uno R3:

- **INPUT_FWD** (Pin 12): Forward motor control
- **INPUT_REV** (Pin 10): Reverse motor control
- **ENABLE_PIN** (Pin 3): Motor speed control (PWM)
- **SERVO_PIN** (Pin 11): Servo motor for steering
- **PUSH_PIN** (Pin 8): Push button for obstacle detection

## Getting Started

Every Arduino sketch using the Drive library should include these basic steps:

```cpp
#include <Drive.h>

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  carInit();              // Initialize the car
}

void loop() {
  // Your code here
}
```

## Function Reference

### Setup and Initialization

#### `carInit()`
Initializes all pins and the servo motor. **This function must be called in the `setup()` function before using any other Drive functions.**

### Movement Functions

#### `fwd(int speed)`
Moves the car forward at a specified speed.
- **Parameters**: 
  - `speed`: Motor speed from 0 to 100 (0 = stopped, 100 = maximum speed)
- **Example**: `fwd(75);` // Move forward at 75% speed

#### `rev(int speed)`
Moves the car in reverse at a specified speed.
- **Parameters**: 
  - `speed`: Motor speed from 0 to 100 (0 = stopped, 100 = maximum speed)
- **Example**: `rev(50);` // Move backward at 50% speed

#### `stopCar()`
Stops the car immediately by setting motor speed to 0.
- **Example**: `stopCar();`

### Steering Functions

#### `turnL(int deg)`
Turns the steering servo to the left by a specified angle.
- **Parameters**: 
  - `deg`: Turn angle from 0 to 90 degrees (0 = straight, 90 = maximum left turn)
- **Example**: `turnL(45);` // Turn left 45 degrees

#### `turnR(int deg)`
Turns the steering servo to the right by a specified angle.
- **Parameters**: 
  - `deg`: Turn angle from 0 to 90 degrees (0 = straight, 90 = maximum right turn)
- **Example**: `turnR(30);` // Turn right 30 degrees

#### `turnS()`
Centers the steering to go straight.
- **Example**: `turnS();`

### Obstacle Detection Functions

#### `push()`
Checks if the push button (obstacle sensor) is pressed.
- **Returns**: `true` if button is pressed, `false` otherwise
- **Example**: 
  ```cpp
  if (push()) {
    stopCar();
  }
  ```

#### `fwdUntilPush(int speed)`
Moves the car forward at a specified speed until the push button is pressed, then stops automatically.
- **Parameters**: 
  - `speed`: Motor speed from 0 to 100
- **Example**: `fwdUntilPush(60);` // Move forward at 60% speed until obstacle detected

#### `stopIfPush()`
Checks if the push button is pressed and stops the car if it is.
- **Example**: `stopIfPush();`

#### `revIfPush(int speed)`
If the push button is pressed, stops the car, waits briefly, then reverses at the specified speed for 1 second.
- **Parameters**: 
  - `speed`: Motor speed from 0 to 100
- **Example**: `revIfPush(50);` // Back up at 50% speed if obstacle detected

### Utility Functions

#### `delaySec(int sec)`
Pauses the program for a specified number of seconds.
- **Parameters**: 
  - `sec`: Number of seconds to delay
- **Example**: `delaySec(3);` // Wait for 3 seconds

## Example Usage

Here's a simple example that demonstrates basic car control:

```cpp
#include <Drive.h>

void setup() {
  Serial.begin(115200);
  carInit();
}

void loop() {
  fwdUntilPush(75);    // Move forward at 75% speed until obstacle detected
  delaySec(5);         // Wait 5 seconds
  turnL(90);           // Turn left 90 degrees
  delaySec(3);         // Wait 3 seconds
  turnR(90);           // Turn right 90 degrees
  delaySec(3);         // Wait 3 seconds
  turnS();             // Center steering
  delaySec(2);         // Wait 2 seconds
}
```

## Project Structure

- **Drive/**: Arduino library folder containing the Drive.h and Drive.cpp files
- **Cars/**: Example sketch for basic car control
- **Test/**: Test sketch demonstrating library features
- **circuit.svg**: Circuit diagram for hardware setup

## Learning Resources

This project is designed for educational purposes. To get the most out of it:

1. Start with the simple examples in the Cars and Test folders
2. Experiment with different speed values and turn angles
3. Combine functions to create interesting movement patterns
4. Use the Serial Monitor (115200 baud) to see debug output from the car

## Troubleshooting

- **Car doesn't move**: Make sure you called `carInit()` in the `setup()` function
- **Serial Monitor shows nothing**: Check that the baud rate is set to 115200
- **Library not found**: Verify the Drive folder is in the correct location (`Documents/Arduino/libraries/Drive/`)
- **Unexpected behavior**: Try adjusting the `MAX_TURN` constant in Drive.cpp if steering angles need calibration

## License

This project is intended for educational use.
