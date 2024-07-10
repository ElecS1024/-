#include "gps.h"
#include <uart.h>   // 假设这是UART库的头文件
#include <stdio.h>
#include <string.h>

void InitGPSUART(void) {
    UART_Config uartConfig;
    uartConfig.baudRate = 9600;  // 根据GPS模块的波特率配置
    uartConfig.dataBits = UART_DATA_BITS_8;
    uartConfig.stopBits = UART_STOP_BITS_1;
    uartConfig.parity = UART_PARITY_NONE;
    UART_Init(UART_NUM_1, &uartConfig);
}

int ReadGPSData(char *buffer, int bufferSize) {
    return UART_Read(UART_NUM_1, buffer, bufferSize - 1);
}

void ParseGPSData(const char *nmeaSentence) {
    if (strncmp(nmeaSentence, "$GPRMC", 6) == 0) {
        char time[10], status, lat[10], ns, lon[11], ew, date[7];
        sscanf(nmeaSentence, "$GPRMC,%6s,%c,%9s,%c,%10s,%c,,,%6s", time, &status, lat, &ns, lon, &ew, date);
        printf("Time: %s\n", time);
        printf("Status: %c\n", status);
        printf("Latitude: %s %c\n", lat, ns);
        printf("Longitude: %s %c\n", lon, ew);
        printf("Date: %s\n", date);
    }
}
