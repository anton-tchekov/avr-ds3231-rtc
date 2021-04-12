#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "twi.h"
#include "ds3231.h"

char *days[] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
char *months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
	"Aug", "Sep", "Oct", "Nov", "Dec" };

int main(void)
{
	uint8_t old_sec = 0;
	char buf[96];
	DateTime dt;
	twi_init();
	dt.year = 2019;
	dt.mon = 5;
	dt.mday = 15;
	dt.hour = 2;
	dt.min = 54;
	dt.sec = 0;
	dt.wday = 3;
	rtc_set_datetime(&dt);
	for(;;)
	{
		rtc_get_datetime(&dt);
		if(dt.sec != old_sec)
		{
			old_sec = dt.sec;
			sprintf(buf, "Date: %s, %d %s %d %02d:%02d:%02d\n",
				days[dt.wday - 1], dt.mday, months[dt.mon - 1], dt.year,
				dt.hour, dt.min, dt.sec);

			/* Send buf by UART */
		}
	}

	return 0;
}
