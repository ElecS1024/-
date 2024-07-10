#include "hall_switch.h"
#include <gpio.h>   // 假设这是GPIO库的头文件

void InitHallSwitch(void) {
    GPIO_SetDir(HALL_SWITCH_PIN, GPIO_DIR_IN);
    GPIO_EnableInt(HALL_SWITCH_PIN, GPIO_INT_FALLING_EDGE);
}

int ReadHallSwitch(void) {
    return GPIO_Read(HALL_SWITCH_PIN);
}
