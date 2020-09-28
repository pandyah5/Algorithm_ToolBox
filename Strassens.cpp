#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

int** matrix_add(int** matrix1, int** matrix2, int n){
	int** res = (int**)malloc(sizeof(int*) * n);
	for (int k = 0; k < n; k++){
		res[k] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			res[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return res;
}

int** matrix_sub(int** matrix1, int** matrix2, int n){
	int** res = (int**)malloc(sizeof(int*) * n);
	for (int k = 0; k < n; k++){
		res[k] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			res[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	return res;
}

int** strassens_mat_mul(int** matrix1, int** matrix2, int n){
	if (n == 1){
		int** res = (int**)malloc(sizeof(int*) * 1);
		for (int k = 0; k < 1; k++){
			res[k] = (int*)malloc(sizeof(int) * 1);
		}
		res[0][0] = (matrix1[0][0]) * (matrix2[0][0]);
		return res;
	}
	if (n % 2 == 1){
		int org_dim = n;
		n++;
		int** mat1 = (int**)malloc(sizeof(int*) * n);
		for (int k = 0; k < n; k++){
			mat1[k] = (int*)malloc(sizeof(int) * n);
		}
		int** mat2 = (int**)malloc(sizeof(int*) * n);
		for (int k = 0; k < n; k++){
			mat2[k] = (int*)malloc(sizeof(int) * n);
		}
		for (int i = 0; i < org_dim; i++){
			for (int j = 0; j < org_dim; j++){
				mat1[i][j] = matrix1[i][j];
				mat2[i][j] = matrix2[i][j];
			}
		}
		for (int k = 0; k < n; k++){
			mat1[k][n-1] = 0;
			mat1[n-1][k] = 0;
			mat2[k][n-1] = 0;
			mat2[n-1][k] = 0;
		}
		return strassens_mat_mul(mat1, mat2, n);
	}
	int** a = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		a[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** b = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		b[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** c = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		c[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** d = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		d[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** e = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		e[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** f = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		f[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** g = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		g[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** h = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		h[k] = (int*)malloc(sizeof(int) * n/2);
	}
	
	for (int i = 0; i < n/2; i++){
		for(int j = 0; j < n/2;j++){
			a[i][j] = matrix1[i][j];
			b[i][j] = matrix1[i][j + n/2];
			c[i][j] = matrix1[i + n/2][j];
			d[i][j] = matrix1[i + n/2][j + n/2];
			e[i][j] = matrix2[i][j];
			f[i][j] = matrix2[i][j + n/2];
			g[i][j] = matrix2[i + n/2][j];
			h[i][j] = matrix2[i + n/2][j + n/2];
		}
	}
	
	int** p1 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		p1[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** p2 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		p2[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** p3 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		p3[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** p4 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		p4[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** p5 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		p5[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** p6 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		p6[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** p7 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		p7[k] = (int*)malloc(sizeof(int) * n/2);
	}
	
	p1 = strassens_mat_mul(a, matrix_sub(f, h, n/2), n/2);
	p2 = strassens_mat_mul(matrix_add(a, b, n/2), h, n/2);
	p3 = strassens_mat_mul(matrix_add(c, d, n/2), e, n/2);
	p4 = strassens_mat_mul(d, matrix_sub(g, e, n/2), n/2);
	p5 = strassens_mat_mul(matrix_add(a, d, n/2),matrix_add(e, h, n/2), n/2);
	p6 = strassens_mat_mul(matrix_sub(b, d, n/2),matrix_add(g, h, n/2), n/2);
	p7 = strassens_mat_mul(matrix_sub(a, c, n/2),matrix_add(e, f, n/2), n/2);
	
	free(a);free(b);free(c);free(d);free(e);free(f);free(g);free(h);
	int** m1 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		m1[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** m2 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		m2[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** m3 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		m3[k] = (int*)malloc(sizeof(int) * n/2);
	}
	int** m4 = (int**)malloc(sizeof(int*) * n/2);
	for (int k = 0; k < n/2; k++){
		m4[k] = (int*)malloc(sizeof(int) * n/2);
	}
	m1 = matrix_sub(matrix_add(p5, matrix_add(p4, p6, n/2), n/2), p2, n/2);
	m2 = matrix_add(p1, p2, n/2);
	m3 = matrix_add(p3, p4, n/2);
	m4 = matrix_sub(matrix_add(p1, p5, n/2), matrix_add(p3, p7, n/2), n/2);
	free(p1);free(p2);free(p3);free(p4);free(p5);free(p6);free(p7);
	
	int** res = (int**)malloc(sizeof(int*) * n);
	for (int k = 0; k < n; k++){
		res[k] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n/2; i++){
		for (int j = 0; j < n/2; j++){
			res[i][j] = m1[i][j];
			res[i][j + n/2] = m2[i][j];
			res[i + n/2][j] = m3[i][j];
			res[i + n/2][j + n/2] = m4[i][j];
		}
	}
	free(m1); free(m2); free(m3); free(m4);
	return res;
}

int main(){
	int** matrix = (int**)malloc(sizeof(int*) * 3);
	for (int i = 0; i < 3; i++){
		matrix[i] = (int*)malloc(sizeof(int) * 3);
	}
	int** matrix1 = (int**)malloc(sizeof(int*) * 3);
	for (int i = 0; i < 3; i++){
		matrix1[i] = (int*)malloc(sizeof(int) * 3);
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 5;
	matrix[1][0] = 3;
	matrix[1][1] = 4;
	matrix[1][2] = 1;
	matrix[2][0] = 2;
	matrix[2][1] = 1;
	matrix[2][2] = 2;
	
	matrix1[0][0] = 3;
	matrix1[0][1] = 1;
	matrix1[0][2] = 5;
	matrix1[1][0] = 2;
	matrix1[1][1] = 1;
	matrix1[1][2] = 3;
	matrix1[2][0] = 4;
	matrix1[2][1] = 1;
	matrix1[2][2] = 5;

	int** res = strassens_mat_mul(matrix, matrix1, 3);
	for (int i = 0; i < 3; i++){
		for(int j = 0; j < 3;j++){
			std::cout << res[i][j] << " ";
		}
		std::cout << '\n';
	}
	return 0;
}
