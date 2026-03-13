/*
 * main.c
 *
 *  Created on: 06-Mar-2026
 *      Author: pooja
 */


#include<stdio.h>

struct Data{
	char a;
	int b;
	char c;
	short d;
};

struct Data_1{
	char a;
	int b;
	char c;
	short d;
}__attribute__((packed));

int main(){

	struct Data Data1 = {0xaa,0x12345678,0x12,0x1345};;
	struct Data_1 Data2 = {0xaa,0x12345678,0x12,0x1345};

	printf("Data is %d",Data1.a);
	printf("Data is %d",Data2.a);

// 	Data1 = {0xa,0x1234,0x1,0x13};


}
