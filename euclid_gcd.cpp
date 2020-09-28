#include <iostream>
#include <vector>

long long gcd_fast(long long a, long long b){
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else{
        return gcd_fast(b, a%b);
    }
}

int main(){
    long long a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << gcd_fast(a, b);
    return 0;
}
