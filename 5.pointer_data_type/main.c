/*
 * main.c
 *
 *  Created on: 12-Jan-2026
 *      Author: pooja
 */
#include <stdio.h>

long long int data = 0x123456789ABCDEFF;
int main(){

	unsigned char *paddress_1 = (unsigned char*)&data;
	paddress_1 =(unsigned char*)&data;
	printf("Value at %p is %x\n",paddress_1,*paddress_1);

	int *paddress_2 = (int*)&data;
	paddress_2 =(int*)&data;
	printf("Value at %p is %x\n",paddress_2,*paddress_2);

	unsigned short *paddress_3 = (unsigned short*)&data;
	paddress_3 =(unsigned short*)&data;
	printf("Value at %p is %x\n",paddress_3,*paddress_3);

	long long *paddress_4 = &data;
	paddress_4 =(long long*)&data;
	printf("Value at %p is %I64x\n",paddress_4,*paddress_4);

	return 0;

}

