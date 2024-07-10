#include "gps.h"
#include "imu.h"
#include "hall_switch.h"
#include <stdio.h>
#include <unistd.h>  // For sleep function

#define GPS_BUFFER_SIZE 1024
#define IMU_BUFFER_SIZE 16

int main(void) {
    char gpsBuffer[GPS_BUFFER_SIZE];
    uint8_t imuBuffer[IMU_BUFFER_SIZE];
    
    // 初始化硬件
    InitGPSUART();
    InitIMUI2C();
    InitHallSwitch();
    
    while (1) {
        // 读取并解析GPS数据
        int bytesRead = ReadGPSData(gpsBuffer, sizeof(gpsBuffer));
        if (bytesRead > 0) {
            gpsBuffer[bytesRead] = '\0';  // 添加字符串结束符
            ParseGPSData(gpsBuffer);
        }

        // 读取并解析IMU数据
        if (ReadIMUData(imuBuffer, sizeof(imuBuffer)) == sizeof(imuBuffer)) {
            ParseIMUData(imuBuffer);
        }

        // 读取霍尔开关状态
        if (ReadHallSwitch() == 0) {
            printf("Hall switch activated!\n");
        }

        // 添加适当的延时，避免过于频繁读取
        sleep(1);
    }
    return 0;
}
