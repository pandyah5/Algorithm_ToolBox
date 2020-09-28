#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

int* bubble_sort(int* arr_org, int len){
	//  Initializing variables
	int j = 1, temp = 0;
	int* arr = (int*)malloc(sizeof(int) * len);
	
	// Creating a copy of the array
	for (int i = 0; i < len; i++){
		arr[i] = arr_org[i];
	}
	
	// Bubble sort
	while(j != 0){
		j = 0;
		for (int i = 0; i + 1 < len; i++){
			if (arr[i] > arr[i + 1]){
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				j++;
			}
		}
	}
	
	// Return sorted array
	return arr;
}

int main() {
	int* arr;
	*arr = 1; *(arr + 1) = 9; *(arr + 2) = 3; *(arr + 3) = 6; *(arr + 4) = 5; *(arr + 5) = 15;*(arr + 6) = 2;
	int len = 7;
	
	int* new_arr = bubble_sort(arr, len);
	for (int i = 0; i < len; i++){
		std::cout << *(new_arr + i) << ' ';
	}
	std::cout << '\n';
	return 0;
}