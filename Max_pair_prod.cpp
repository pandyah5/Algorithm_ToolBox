#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int n = numbers.size();

    int max1 = 0, max2 = 0;
    long long min = 0;
    for (int first = 0; first < n; ++first){
        if (numbers[first] > numbers[max1]){
            max1 = first;
        }
    }

    // std::cout << numbers[max1] << "\n";

    for (int first = 0; first < n; ++first){
        if (numbers[first] > min && first != max1){
            max2 = first;
            min = numbers[max2];
        }
    }

    // std::cout << numbers[max2] << "\n";

    return (long long)numbers[max1] * (long long)numbers[max2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
