/*
 * main.c
 *
 *  Created on: 11-Mar-2026
 *      Author: pooja
 */



#include <stdint.h>
#include<stdio.h>


struct dataset{
	char a;
	int b;
	char c;
	short d;
};

void Display(struct dataset *ptr);


int main(void){
	struct dataset data;
	data.a = 0x11;
	data.b = 0x12345678;
	data.c = 0x22;
	data.d = 0x5678;
	Display(&data);

	//uint8_t *ptr = (uint8_t*)&data;
	//ptr = 0x55;
	/*
	 * with above statement we can change the first element but as its aligned
	 * and padding is done further cannot be done by not knowing the addresses
	 * so to make it easy we use struct pointer
	 */
	struct dataset *pdata;
	pdata = &data;
	pdata->a = 0x55;
	pdata ->b = 0x87654321;
	pdata ->c = 0x12;
	pdata ->d = 0x8888;
	Display(&data);

	 for(;;);
}


void Display(struct dataset *ptr){
	printf("1st element of data = %hhX\n",ptr->a);
	fflush(stdout);
	printf("2nd element of data = %X\n",ptr->b);
	fflush(stdout);
	printf("3rd element of data = %hhX\n",ptr->c);
	fflush(stdout);
	printf("4th element of data = %hX\n",ptr->d);
	fflush(stdout);


}
