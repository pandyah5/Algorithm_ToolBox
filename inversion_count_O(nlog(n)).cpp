#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

int* merge_sort(int arr[], int len){
	// Base condition
	if (len < 2)
		return arr;
		
	// Binary split
	int middle = len / 2;
	int* array1 = (int*)malloc(sizeof(int) * middle);
	int* array2 = (int*)malloc(sizeof(int) * (len - middle));
	int* array3 = (int*)malloc(sizeof(int) * len);
	
	for (int i = 0; i < middle; i++)
		array1[i] = arr[i];
	for (int i = middle; i < len; i++)
		array2[i - middle] = arr[i];
		
	// Recursion call
	array1 = merge_sort(array1, middle);
	array2 = merge_sort(array2, len - middle);
	
	// Merging output arrays
	int i = 0, j = 0, k = 0;
	while (i < middle && j < len - middle){
		if (array1[i] < array2[j]){
			array3[k] = array1[i];
			i++;
			k++;
		}
		else{
			array3[k] = array2[j];
			j++;
			k++;
		}
	}
	if (i == middle){
		while(k < len){
			array3[k] = array2[j];
			j++;
			k++;
		}
	}
	else{
		while(k < len){
			array3[k] = array1[i];
			i++;
			k++;
		}
	}
	
	// Returning merged arrays
	return array3;
}

// Creating a structure to store array, and invertion count
typedef struct NewArray{
	int* arr;
	int invert = 0;
} newArray;

int merge_compare(int arr1[], int arr2[], int len1, int len2){
	// Applyingg merge sort
	arr1 = merge_sort(arr1, len1);
	arr2 = merge_sort(arr2, len2);
	
	// Counting inversions
	int total = 0;
	int i = 0, j = 0;
	while(i < len1){
		if (arr1[i] <= arr2[j]){
			i++;
		}
		else if (j < len2){
			total += len1 - i;
			j++;
		}
		else{
			i = len1;
		}
	}
	return total;
}

newArray invert_fast(newArray input, int len){
	
	// Base case when length is one
	if (len == 1){
		return input;
	}
	
	// Splitting array in two parts
	int *arr1 = (int*)malloc(sizeof(int) * (len/2));
	int *arr2 = (int*)malloc(sizeof(int) * (len - (len/2)));
	for (int i = 0; i < len/2; i++){
		arr1[i] = input.arr[i];
	}
	
	for (int i = len/2; i < len; i++){
		arr2[i - (len/2)] = input.arr[i];
	}
	
	newArray temp1;
	temp1.arr = arr1;
	temp1.invert = 0;
	
	newArray temp2;
	temp2.arr = arr2;
	temp2.invert = 0;
	
	// Adding invertion count for: Merge + Left + Right
	input.invert += merge_compare(temp1.arr, temp2.arr, len/2, len - (len/2));
	input.invert += invert_fast(temp1, len/2).invert;
	input.invert += invert_fast(temp2, len - (len/2)).invert;
	
	// Returning newArray struct with array and inversion count
	newArray res;
	res.invert = input.invert;
	res.arr = arr1;
	memcpy(res.arr + len/2, arr2, sizeof(arr2));
	return res;
}

int main(){
	int arr[] = {8, 4, 2, 1};
	newArray input;
	input.arr = arr;
	input.invert = 0;
	newArray out = invert_fast(input, 4);
	std::cout << "RESULT: " << out.invert << '\n';
	return 0;
}
