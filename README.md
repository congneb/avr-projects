# AVR Projects

This repository contains example projects for AVR microcontrollers. The goal is to provide practical, well-documented examples for learning and experimenting with AVR devices.

## Overview

AVR microcontrollers are widely used in embedded systems, hobbyist electronics, and educational projects. This repo showcases a variety of sample projects demonstrating how to use AVR chips for different applications.

## Contents

- Basic input/output examples
- Peripheral interfacing (UART, SPI, I2C, etc.)
- Timers, interrupts, and PWM usage
- Sensor and actuator integration
- Application-level projects (LED effects, motor control, etc.)

## Getting Started

1. **Clone this repository:**
   ```sh
   git clone https://github.com/congneb/avr-projects.git
   ```

2. **Prerequisites:**
   - AVR toolchain (e.g., avr-gcc, avrdude)
   - Supported AVR development board or breadboard setup

3. **Building and Flashing:**
   - Navigate to the desired project directory and follow its instructions.
   - Typical build command:
     ```sh
     make
     ```
   - Flash to your AVR device using:
     ```sh
     avrdude -p <partno> -c <programmer> -U flash:w:main.hex
     ```

## Project Structure

```
avr-projects/
  ├── project1/
  ├── project2/
  ├── ...
  └── README.md
```

Each project folder includes:
- `main.c` or equivalent source file(s)
- Makefile or build instructions
- Documentation (if necessary)

## Contributing

Contributions are welcome! Feel free to submit pull requests with new example projects, bug fixes, or improvements.

## License

This repository is licensed under the MIT License.

---

Happy hacking with AVR!
