#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

int** matrix_mult(int** matrix1, int** matrix2, int n){
	int** res = (int**)malloc(sizeof(int*) * n);
	int add = 0;
	for (int i = 0; i < n; i++){
		res[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n;j++){
			for(int k = 0; k < n; k++){
				add += matrix1[i][k] * matrix2[k][j];
			}
			res[i][j] = add;
			add = 0;
		}
	}
	return res;
}

int main(){
	int** matrix = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++){
		matrix[i] = (int*)malloc(sizeof(int) * 2);
	}
	int** matrix1 = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++){
		matrix1[i] = (int*)malloc(sizeof(int) * 2);
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;
	
	matrix1[0][0] = 1;
	matrix1[0][1] = 0;
	matrix1[1][0] = 4;
	matrix1[1][1] = 2;

	int** res = matrix_mult(matrix, matrix1, 2);
	for (int i = 0; i < 2; i++){
		for(int j = 0; j < 2;j++){
			std::cout << res[i][j] << " ";
		}
		std::cout << '\n';
	}
	return 0;
}
