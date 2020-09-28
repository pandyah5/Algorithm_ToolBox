#include <iostream>
#include <vector>
#include <algorithm>

// Fibonnacci algorithm - Fast

long long fast_fibo(int n){
    if (n <= 1)
        return n;
    int count = 0;
    long long next = 0, first = 0, sec = 1;
    while(count < n){
        next = first + sec;
        sec = first;
        first = next;
        count++;
    }
    return next;
}

// Fibonnacci algorithm - Slow

long long slow_fibo(int n){
    if (n <= 1){
        return n;
    }
    else{
        return slow_fibo(n - 1) + slow_fibo(n - 2);
    }
}

int main(){
    int n = 0;
    std::cin >> n;
    long long result = fast_fibo(n - 1);
    std::cout << result << '\n';
    result = slow_fibo(n - 1);
    std::cout << result;
}
