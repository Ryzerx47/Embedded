/*
 * main.c
 *
 *  Created on: 02-Mar-2026
 *      Author: pooja
 */

#include<stdio.h>
#include<stdint.h>

struct carModel{
	uint32_t carnumber;
	int price;
	int max_speed;
	float weight;
};

int main(void){


	struct carModel BMW = {2021,15000,220,1330};
	struct carModel Ford = {4031,35000,160,1900.96}; //c89 method where order is important

	/*
	carModel BMW = {.carnumber=2021,.price = 15000, .max_speed = 220, .weight = 1330 };
	carModel Ford = {.carnumber=4031,.price = 35000, .max_speed = 160, .weight = 1900.96 };
	c99 method where we use dot operator to specify but here order doesnt matter
	*/
	printf("The details of Car BMW are\n");
	printf("CarNo: %u \n Car_Price: %d \nCar_Max_Speed: %d \n Car_weight: %f",BMW.carnumber,BMW.price,BMW.max_speed,BMW.weight);
	printf("CarNo: %u \n Car_Price: %d \nCar_Max_Speed: %d \n Car_weight: %f",Ford.carnumber,Ford.price,Ford.max_speed,Ford.weight);
	return 0;
}
