/*
 * main.c
 *
 *  Created on: 17-Mar-2026
 *      Author: pooja
 */

#include<stdio.h>
#include<stdint.h>

void swap(int *arr1, int *arr2, int s1,int s2);

int main(){
	int n1,n2,s1,s2;
	printf("Emter the size of arrays: \n");
	fflush(stdout);
	scanf("%d %d",&n1,&n2);
	int arr1[n1],arr2[n2];
	printf("Enter the element for 1st array:\n");
	fflush(stdout);
	for(int i =0;i<n1;i++){
		scanf("%d",&arr1[i]);
	}
	printf("Enter the element for 2nd array:\n");
	fflush(stdout);
	for(int i =0;i<n2;i++){
		scanf("%d",&arr2[i]);
	}
	s1 = sizeof(arr1)/sizeof(int);
	s2 = sizeof(arr2)/sizeof(int);

	swap(arr1,arr2,s1,s2);
	printf("After swapping \n");
	fflush(stdout);
	for(int i=0;i<n1;i++){
		printf("%d ",arr1[i]);
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
	for(int i=0;i<n2;i++){
		printf("%d ",arr2[i]);
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);

	return 0;

}


void swap(int *arr1, int *arr2, int s1,int s2){
	int temp;
	int s = s1>s2 ? s2:s1;
	for(int i=0;i<s;i++){
			temp = arr1[i];
			arr1[i] = arr2[i];
			arr2[i] = temp;

	}
}
