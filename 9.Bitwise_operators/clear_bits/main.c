/*
 * main.c
 *
 *  Created on: 28-Jan-2026
 *      Author: pooja
 */
/*
 * main.c
 *
 *  Created on: 28-Jan-2026
 *      Author: pooja
 */

#include<stdio.h>
#include<stdint.h>

int main(){
	int a;
	printf("Enter the number \n");
	fflush(stdout);
	scanf("%d",&a);
	printf("On clearing the bits 4,5,6th we get %d \n",(a&0x8F));
	fflush(stdout);
	//with using both & and ~ where its easier to know the value with help of left shift
	// we know 4,5,6 bit to clear so continous bits will be (111)in binary will be = 7
	// so to adjust it to 4th bit we use left shift that is 7<<4;
	printf("On clearing the bits 4,5,6th we get %d \n",(a&~(7<<4)));
	fflush(stdout);
}


