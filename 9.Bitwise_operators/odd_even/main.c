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
	if((a&1)==0){
		printf("Its a even number\n");
		fflush(stdout);
	}
	else{
		printf("Its a odd number\n");
		fflush(stdout);
	}

}
