/*
 * main.c
 *
 *  Created on: 26-Jan-2026
 *      Author: pooja
 */

#include<stdio.h>
#include<stdint.h>

int main(){
	 char shape;
	 float h,b,a,area=0;
	 printf("Enter the shape to find the area: \n");
	 fflush(stdout);
	 scanf("%s",&shape);

	 switch(shape){
	 case 't':
		 printf("Enter the height and base of Traingle\n");
		 fflush(stdout);
		 scanf("%f,%f",&h,&b);
		 area = (h*b)/2;
		 printf("Area = %f",area);
		 break;
	 case 'z':
		 printf("Enter the height and both sides of Trapizoid \n");
		 fflush(stdout);
		 scanf("%f,%f,%f",&h,&a,&b);
		 area = ((a+b)/2)*h;
		 printf("Area = %f",area);
		 break;
	 case 'c':
		 printf("Enter the radius of the circle \n");
		 fflush(stdout);
		 scanf("%f",&a);
		 area = 3.14*a*a;
		 printf("Area = %f",area);
		 break;
	 case 's':
		 printf("Enter the side of Square \n");
		 fflush(stdout);
		 scanf("%f",&a);
		 area = a*a;
		 printf("Area = %f",area);
		 break;
	 case 'r':
		 printf("Enter the  both sides of Rectangle\n");
		 fflush(stdout);
		 scanf("%f,%f",&a,&b);
		 area = a*b;
		 printf("Area = %f",area);
		 break;
	 default:
		 printf("Invalid shape....\n");
		 fflush(stdout);
	 }

}
