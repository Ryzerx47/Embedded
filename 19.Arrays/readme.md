# Arrays in C – Swapping Elements Between Two Arrays

## Overview
Today I learned about **arrays in C** and how they can be manipulated using **functions and pointers**.  
This program demonstrates how to:

- Take array inputs from the user
- Determine array size using `sizeof`
- Pass arrays to a function
- Swap elements between two arrays using pointers
- Handle arrays of different sizes

---

## Concepts Learned

### 1. Arrays
An **array** is a collection of elements of the same data type stored in contiguous memory locations.

Example:

    int arr[5];

Each element can be accessed using an index:

arr[0], arr[1], arr[2], ...

### 2. Variable Length Arrays (VLA)

In this program, the size of arrays is provided by the user:

    int arr1[n1], arr2[n2];

This feature is called Variable Length Arrays (VLA), introduced in C99.

### 3. Finding Array Size Using sizeof

The size of the array is calculated using:

    s1 = sizeof(arr1) / sizeof(int);
    s2 = sizeof(arr2) / sizeof(int);


Explanation:

sizeof(arr1) → total memory occupied by array

sizeof(int) → size of one element

Dividing them gives the number of elements in the array

### 4. Passing Arrays to Functions

Arrays are passed to functions using pointers.

    void swap(int *arr1, int *arr2, int s1, int s2);

Here:

arr1 → pointer to first array

arr2 → pointer to second array

### 5. Swapping Elements Between Arrays

The program swaps elements between the two arrays index by index.

If the arrays have different sizes, swapping happens only until the minimum size.
    
    int s = s1 > s2 ? s2 : s1;

This ensures the program does not access memory outside the array bounds.

Program Flow

User enters sizes of two arrays.

User enters elements for both arrays.

Program calculates sizes using sizeof.

Arrays are passed to the swap() function.

Elements are swapped index by index.

The swapped arrays are printed.

C Program
    
    #include<stdio.h>
    #include<stdint.h>
    
    void swap(int *arr1, int *arr2, int s1,int s2);
    
    int main(){
    	int n1,n2,s1,s2;
    	printf("Enter the size of arrays: \n");
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
    	}
    
    	printf("\n");
    
    	for(int i=0;i<n2;i++){
    		printf("%d ",arr2[i]);
    	}
    
    	printf("\n");
    
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

  
Key Takeaways

Arrays store multiple elements of the same data type.

Arrays are passed to functions using pointers.

sizeof() helps determine array length.

When working with two arrays of different sizes, operations should only run until the minimum size.

Swapping can be efficiently implemented using a temporary variable.
