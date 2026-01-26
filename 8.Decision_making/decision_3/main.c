/*
 * main.c
 *
 *  Created on: 26-Jan-2026
 *      Author: pooja
 */
#include<stdio.h>
#include<stdint.h>

int main(){
	uint64_t income,tax;
	double temp;

	printf("Enter the income\n");
	fflush(stdout);
	scanf("%lf",&temp);

	income = (uint64_t) temp;

	if(income<=9525){
		tax = income * 0;
		printf("Tax payable is =%I64d\n",tax);
		fflush(stdout);
	}
	else if(income>9525 && income <= 38700){
		tax = income * 0.12;
		printf("Tax payable is =%I64d\n",tax);
				fflush(stdout);
	}
	else if(income>38700 && income <= 82500){
		tax = income * 0.22;
		printf("Tax payable is =%I64d\n",tax);
				fflush(stdout);
	}
	else{
		tax = (income * 0.32)+1000;
		printf("Tax payable is =%I64u\n",tax);
				fflush(stdout);
	}
	return 0;
}
