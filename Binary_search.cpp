#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

void bin_search(int* arr, int len, int target, int* pos){
	if (len == 1 && arr[0] != target){
		*pos = -1;
		return;
	}
	if (target == arr[len/2]){
		*pos += len/2;
		return;
	}
	else if (target < arr[len/2]){
		int new_arr[len/2];
		for (int i = 0; i < len/2; i++){
			new_arr[i] = arr[i];
		}
		bin_search(new_arr, len/2, target, pos);
		return;
	}
	else{
		*pos += (len - (len/2)) - 1;
		int new_arr[len - (len/2)];
		for (int i = len/2; i < len; i++){
			new_arr[i - (len/2)] = arr[i];
		}
		bin_search(new_arr, len - len/2, target, pos);
		return;
	}
}

int main(){
	int test_arr[] = {1, 12, 33, 45, 52, 76, 87, 98, 99};
	int pos = 0;
	bin_search(test_arr, 9, 76, &pos);
	std::cout << pos << " ";
	std::cout << '\n';
	return 0;
}
