/*
 * main.c
 *
 *  Created on: 09-Jan-2026
 *      Author: pooja
 */
#include <stdio.h>

int main(void){
	char x = 100;
	printf("Value of x = %d \n",x);
	printf("Address of x %p \n",(void*)&x);
	char* p_address = &x;
	char data = *p_address;
	printf("read value from pointer address %d \n",data);
	*p_address = 65;
	printf("Written value %d",x);


	return 0;
}

