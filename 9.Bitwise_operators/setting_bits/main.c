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
	printf("the number is %d\n",(a|0x90));
	fflush(stdout);

}
