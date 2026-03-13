/*
 * main.c
 *
 *  Created on: 12-Mar-2026
 *      Author: pooja
 */

#include<stdio.h>
#include<stdint.h>

union addr{
	uint16_t short_add;
	uint32_t long_add;
};

int main(){
	union addr a;
	a.short_add = 0x1111;
	a.long_add = 0x55558888;

	printf("Short address is %x",a.short_add);
	fflush(stdout);
	printf("Long address is %x",a.long_add);
	fflush(stdout);

	return 0;
}
/*
 * here we see that even though short address is of 1111
 * but while printing it shows 8888 as long add value is overridden in union
 * so in union a single element can be used at a given time
 * its useful when elements are mutually exclusive
 */
