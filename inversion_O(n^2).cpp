#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

int inversion(int arr[], int len){
	int sum = 0;
	for(int i = 0; i < len; i++){
		for(int j = i; j < len; j++){
			if (arr[i] > arr[j])
				sum++;
		}
	}
	return sum;
}

int main(){
	int arr[] = {3, 1, 2};
	std::cout << inversion(arr, 3) << '\n';
	return 0;
}