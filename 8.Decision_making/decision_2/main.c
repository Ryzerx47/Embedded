/*
 * main.c
 *
 *  Created on: 26-Jan-2026
 *      Author: pooja
 */


#include<stdio.h>
#include<stdint.h>

void wait(void);

int main(){

	float num1,num2;
	printf("Enter the first number \n");
	fflush(stdout);
	if((scanf("%f",&num1) == 0)){
	printf("Invalid input...\n");
	fflush(stdout);
	wait();
	return 0;
	}
	fflush(stdout);
	printf("Enter the second number \n");
	fflush(stdout);
	if((scanf("%f",&num2) == 0)){
	printf("Invalid input...\n");
	fflush(stdout);
	wait();
	return 0;
	}
	fflush(stdout);

	int32_t n1,n2;

	n1 = num1;
	n2 = num2;

	if(n1!=num1 || n2!= num2){
		printf("Comparing only the integer part\n");
		fflush(stdout);
	}
	if(n1==n2){
		printf("Numbers are equal\n");
		fflush(stdout);
	}
	else if(n1<n2){
		printf("n1 is less then n2\n");
		fflush(stdout);

	}
	else{
		printf("n2 is less then n1\n");
		fflush(stdout);
	}

}

void wait(void){

	printf("Press Enter key to exit the code \n");
	fflush(stdout);
	while(getchar() != '\n');

}

