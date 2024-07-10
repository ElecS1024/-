#include "imu.h"
#include <i2c.h>   // 假设这是I2C库的头文件
#include <stdio.h>

void InitIMUI2C(void) {
    I2C_Config i2cConfig;
    i2cConfig.freq = I2C_FREQ_400K;
    I2C_Init(I2C_NUM_1, &i2cConfig);
}

int ReadIMUData(uint8_t *buffer, int bufferSize) {
    return I2C_Read(I2C_NUM_1, IMU_I2C_ADDRESS, buffer, bufferSize);
}

void ParseIMUData(const uint8_t *data) {
    int16_t ax = (data[0] << 8) | data[1];
    int16_t ay = (data[2] << 8) | data[3];
    int16_t az = (data[4] << 8) | data[5];
    int16_t gx = (data[6] << 8) | data[7];
    int16_t gy = (data[8] << 8) | data[9];
    int16_t gz = (data[10] << 8) | data[11];
    printf("Accel: [%d, %d, %d]\n", ax, ay, az);
    printf("Gyro: [%d, %d, %d]\n", gx, gy, gz);
}
