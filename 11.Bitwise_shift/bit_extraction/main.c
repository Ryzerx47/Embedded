/*
 * main.c
 *
 *  Created on: 30-Jan-2026
 *      Author: pooja
 */
#include<stdio.h>
#include<stdint.h>

int main(){
	uint16_t data =  0xb410;
	//to extract the data from bits 9 to 14
	// first we will shift the data by 9 position to right
	// so that the 9th bit will be the lsb so it makes easier to extract

	uint8_t temp = data>>9;
	/*now that the data is shifted we will mask the value and use bitwise and
	 * mask value will be 0x003f because its 0000 0000 0011 1111
	 * which has 6 bits that can extract the data we need
	 */

	uint8_t output = temp & 0x003f;

	printf("the extracted part is %u \n",output);
	fflush(stdout);
	//to print in hex format
	printf("The extracted part in hex 0x%X\n",output);
	fflush(stdout);
}

