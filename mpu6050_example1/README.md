# MPU6050 - Accelerometer example

## Overview

MPU6050: Combines a 3-axis gyroscope and 3-axis accelerometer.

## Explain

### i2c_read_nack()

it's the last byte we want to read from the I2C device during that transaction.

🧠 ACK vs NACK in I2C Reads
ACK (Acknowledge): Sent by the master to tell the slave “I want to keep reading more bytes.”

NACK (Not Acknowledge): Sent by the master to say “I’m done reading, stop transmitting.”

### i2c_write(0x6B)

Power management register

0x6B is the address of the Power Management 1 register in the MPU6050.

By default, when the MPU6050 powers up, it is in sleep mode to conserve energy.

Writing 0 to this register clears the sleep bit (bit 6), effectively waking up the sensor.

### Convert raw data to g value

To convert it into g (gravitational acceleration units), you need to apply the sensor’s sensitivity scale.

The MPU6050 has selectable ranges: ±2g, ±4g, ±8g, ±16g.

Default after reset: ±2g.

In ±2g mode, the sensitivity is 16384 LSB/g (Least Significant Bits per g).

Full range = 4g (from −2g to +2g).

Total digital steps = 65,536.

Steps per g = 65536/4=16384

So: 1𝑔 = 16384 raw units

    𝑎𝑥(𝑔)=𝑎𝑥/16384

If you change the range, the divisor changes:

    ±2g → 16384
    
    ±4g → 8192
    
    ±8g → 4096
    
    ±16g → 2048

The MPU6050 has a 16-bit ADC for the accelerometer.

That means raw readings range from −32768 to +32767.

Depending on the sensitivity setting (±2g, ±4g, ±8g, ±16g), the full-scale range is divided across those 65,536 possible values.

### I2C Repeated Start

when you want to read from a specific register inside a device like the MPU6050.

You call i2c_start() twice because the first sets the register pointer (write mode), and the second switches to read mode without releasing the bus. This is the correct I²C procedure for register-based devices like the MPU6050.

That why we have to call 2 time i2c_start() on this function: 

    int16_t read_accel_x() { 
    i2c_start(); 
    i2c_write(MPU6050_ADDR << 1); 
    i2c_write(0x3B); // ACCEL_XOUT_H 
    i2c_start();
    ...

- First i2c_start() → Write phase

You begin communication with the MPU6050.

Send the device address with the write bit (0).

Then send the register address (0x3B = ACCEL_XOUT_H).

This tells the sensor: “I want to read starting from this register.”

- Second i2c_start() → Repeated start (read phase)

Instead of stopping, you issue another start condition (called a repeated start).

Now you send the device address again, but with the read bit (1).

This switches the bus direction: the MPU6050 will start sending data back to you.

You then read the high byte (ACK) and the low byte (NACK).
