/*
 * main.c
 *
 *  Created on: 21-Jan-2026
 *      Author: pooja
 */

#include<stdio.h>

int main(){
	int age;
	printf("Enter the age\n");
	fflush(stdout);
	scanf("%d",&age);
	fflush(stdout);
	if(age>=18){
		printf("Elgible for vote");
	}
	return 0;
}

