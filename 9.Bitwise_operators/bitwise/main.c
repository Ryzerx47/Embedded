/*
 * main.c
 *
 *  Created on: 28-Jan-2026
 *      Author: pooja
 */

#include<stdio.h>
#include<stdint.h>

int main(){
	int a,b,c;
	printf("Enter the 2 numbers\n");
	fflush(stdout);
	scanf("%d %d",&a,&b);
	c = a&b;
	printf("Bitwise And = %d \n",c);
	fflush(stdout);
	c = a|b;
	printf("Bitwise Or = %d \n",c);
	fflush(stdout);
	c = a^b;
	printf("Bitwise Xor = %d \n",c);
	fflush(stdout);
	c = ~a;
	printf("Bitwise Not = %d \n",c);
	fflush(stdout);
}
