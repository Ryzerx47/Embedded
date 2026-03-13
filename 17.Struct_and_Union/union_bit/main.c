/*
 * main.c
 *
 *  Created on: 13-Mar-2026
 *      Author: pooja
 */


/*
 * main.c
 *
 *  Created on: 11-Mar-2026
 *      Author: pooja
 */

#include<stdio.h>
#include<stdint.h>
union packet{
	uint32_t packvalue;
struct {
	uint32_t crc :2;
	uint32_t status:1;
	uint32_t payload:12;
	uint32_t bat:3;
	uint32_t sensor:3;
	uint32_t long_add:8;
	uint32_t short_add:2;
	uint32_t addr_mode:1;
}value;
};

int main(){
	union packet pack;
	printf("Enter the packetvalue \n");
	fflush(stdout);
	scanf("%x",&pack.packvalue);

	printf("1st element of data = %X\n",pack.value.crc);
	fflush(stdout);
	printf("1st element of data = %X\n",pack.value.status);
	fflush(stdout);
	printf("1st element of data = %X\n",pack.value.payload);
	fflush(stdout);
	printf("1st element of data = %X\n",pack.value.bat);
	fflush(stdout);
	printf("1st element of data = %X\n",pack.value.sensor);
	fflush(stdout);
	printf("1st element of data = %X\n",pack.value.long_add);
	fflush(stdout);
	printf("1st element of data = %X\n",pack.value.short_add);
	fflush(stdout);
	printf("1st element of data = %X\n",pack.value.addr_mode);
	fflush(stdout);

	printf("Size of struct is %d",sizeof(pack));

}
