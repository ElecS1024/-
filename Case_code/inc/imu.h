#ifndef IMU_H
#define IMU_H

#include <stdint.h>

void InitIMUI2C(void);
int ReadIMUData(uint8_t *buffer, int bufferSize);
void ParseIMUData(const uint8_t *data);

#endif // IMU_H
