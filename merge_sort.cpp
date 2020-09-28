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

int main() {
	int* arr;
	*arr = 1; *(arr + 1) = 9; *(arr + 2) = 3; *(arr + 3) = 6; *(arr + 4) = 5; *(arr + 5) = 15;*(arr + 6) = 2;
	int len = 7;
	
	int* new_arr = merge_sort(arr, len);
	for (int i = 0; i < len; i++){
		std::cout << *(new_arr + i) << ' ';
	}
	std::cout << '\n';
	return 0;
}
