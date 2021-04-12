#ifndef __DS3231_H__
#define __DS3231_H__

#include <stdint.h>

typedef struct
{
	uint8_t sec, min, hour, mday, mon, wday;
	uint16_t year;
} DateTime;

DateTime *rtc_get_datetime(DateTime *dt);
void rtc_set_datetime(DateTime *dt);
void ds3231_get_temperature(int8_t *i, uint8_t *f);

#endif /* __DS3231_H__*/
