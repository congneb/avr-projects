#include <avr/io.h>
#include <util/delay.h>

#define MPU6050_ADDR 0x68

void i2c_init() {
  TWSR = 0;
  TWBR = 72; // Set SCL frequency to ~100kHz
  TWCR = (1 << TWEN);
}

void i2c_start() {
  TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
  while (!(TWCR & (1 << TWINT)));
}

void i2c_stop() {
  TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT);
}

void i2c_write(uint8_t data) {
  TWDR = data;
  TWCR = (1 << TWEN) | (1 << TWINT);
  while (!(TWCR & (1 << TWINT)));
}

uint8_t i2c_read_ack() {
  TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
  while (!(TWCR & (1 << TWINT)));
  return TWDR;
}

uint8_t i2c_read_nack() {
  TWCR = (1 << TWEN) | (1 << TWINT);
  while (!(TWCR & (1 << TWINT)));
  return TWDR;
}

void mpu6050_init() {
  i2c_start();
  i2c_write(MPU6050_ADDR << 1);
  i2c_write(0x6B); // Power management register
  i2c_write(0);    // Wake up MPU6050
  i2c_stop();
}

int16_t read_accel_x() {
  i2c_start();
  i2c_write(MPU6050_ADDR << 1);
  i2c_write(0x3B); // ACCEL_XOUT_H
  i2c_start();
  i2c_write((MPU6050_ADDR << 1) | 1);
  uint8_t high = i2c_read_ack();
  uint8_t low = i2c_read_nack();
  i2c_stop();
  return (high << 8) | low;
}

int main() {
  i2c_init();
  mpu6050_init();

  int16_t ax = read_accel_x();
  // Do something with ax
  float ax_g = ax / 16384.0;
  _delay_ms(500);
}  
