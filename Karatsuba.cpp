#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std; 

unsigned long int karatsuba_mult(unsigned long int num1, unsigned long int num2){
	if (num1 < 10 || num2 < 10)
		return num1 * num2;
	else{
		unsigned long int len, len1 = 0, len2 = 0, a = 0, b = 0, c = 0, d = 0;
		if (num1 != 0)
			len1 = (log10(num1)) + 1;
		if (num2 != 0)
			len2 = (log10(num2)) + 1;
		
		len = max(len1, len2);
		
		a = (num1 / pow(10, ceil(len / 2)));
		b = num1 - a * pow(10, ceil(len / 2));
		c = (num2 / pow(10, len / 2));
		d = num2 - c * pow(10, len / 2);
		
		unsigned long int prod1 = karatsuba_mult(a, c);
		unsigned long int prod2 = karatsuba_mult(b, d);
		unsigned long int prod3 = karatsuba_mult(a+b, c+d);
		return pow(10, 2 * ceil(len/2))*prod1 + pow(10, ceil(len/2))*(prod3 - prod1 - prod2) + prod2; 
	}
} 

int main() {
	int n, m;
	std::cin >> n;
	std::cin >> m;
	std::cout << "The result is: " << karatsuba_mult(n, m) << '\n';
	return 0;
}
