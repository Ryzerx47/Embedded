
#include <stdint.h>
#include<stdio.h>

int main(void){
	uint8_t volatile data1;
	uint8_t volatile data2;

	 data1 = 50;

	 data2= data1;

	 data2=data1;
	 //this line is not required and is redundant and the compiler can skip this line
	 //o0 this line is compiled
	//in o1 optimization none of the lines as the variables are not used all are seen as redundant
	//after using volatile the lines are compiled in o1;
	 //so by invoking volatile we tell the compiler to not optimize the variables

	 for(;;);
}
