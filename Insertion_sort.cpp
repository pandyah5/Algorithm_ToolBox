#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

int* insertion_sort(int* arr, int len){
	//  Initializing variables
	int i = 0;
	int* new_arr = (int*)malloc(sizeof(int) * len);
	
	// Creating a copy of the array
	for (int j = 0; j < len; j++){
		new_arr[j] = arr[j];
	}
	
	// Insertion sort
	while(i < len){
		int k = i, temp;
		while(i > 0 && new_arr[i] < new_arr[i - 1]){
			temp = new_arr[i - 1];
			new_arr[i - 1] = new_arr[i];
			new_arr[i] = temp;
			i--;
		}
		i = k + 1;
	}
	
	// Return sorted array
	return new_arr;
}

int main() {
	int* arr;
	*arr = 1; *(arr + 1) = 9; *(arr + 2) = 3; *(arr + 3) = 6; *(arr + 4) = 5; *(arr + 5) = 15;*(arr + 6) = 2;
	int len = 7;
	
	int* new_arr = insertion_sort(arr, len);
	for (int i = 0; i < len; i++){
		std::cout << *(new_arr + i) << ' ';
	}
	std::cout << '\n';
	return 0;
}