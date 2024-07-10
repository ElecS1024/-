#ifndef GPS_H
#define GPS_H

#include <stdint.h>

void InitGPSUART(void);
int ReadGPSData(char *buffer, int bufferSize);
void ParseGPSData(const char *nmeaSentence);

#endif // GPS_H
