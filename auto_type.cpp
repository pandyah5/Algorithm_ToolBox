
using namespace std;

int return_fun(){
	return 4.07;
}
#include <iostream>

int main(void){
	auto var1 = 1;
	auto y = var1;
	cout << "Enter a number: ";
	cin >> y;
	cout << "The square of the number is: " << y*y << endl << endl;
	int num = return_fun();
	cout << num << endl;
	return 2514;
}
