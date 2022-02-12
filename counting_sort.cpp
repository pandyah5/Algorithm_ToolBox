#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void counting_sort(vector<int>& arr, int min, int max, int* res_array){

    // Make an empty array with size equal to the possible numbers between min and max
    int* temp_array = new int[(max - min) + 1];
    for (int i = 0; i < (max - min) + 1; i++){
        temp_array[i] = 0;
    }

    // Make the frequency array
    for (auto iter = arr.begin(); iter != arr.end(); iter++){
        temp_array[*iter - min] += 1;
    }

    // Make aggregate frequency array
    for (int i = 1; i < (max - min) + 1; i++){
        temp_array[i] += temp_array[i - 1];
    }

    cout << "Array C: ";
    for (int i = 0; i < (max - min) + 1; i++){
        cout << temp_array[i] << " ";
    }
    cout << endl;

    // Use the aggregate array to fill up the result
    for (int index = arr.size() - 1; index >= 0; index--){
        res_array[temp_array[arr[index] - min] - 1] = arr[index];
        temp_array[arr[index] - min] -= 1;
    }

    delete[] temp_array;
    temp_array = NULL;
}

int main(void){
    vector<int> array = {3, 7, 5, 3, 4, 6, 8, 10};

    cout << "Array A: ";
    for (auto iter = array.begin(); iter != array.end(); iter++){
        cout << *iter << " ";
    }

    cout << endl;

    int min = *min_element(array.begin(), array.end());
    int max = *max_element(array.begin(), array.end());

    // Initialize the result array
    int* res_array = new int[array.size() + 1];
    for (int i = 0; i < array.size(); i++){
        res_array[i] = 0;
    }

    counting_sort(array, min, max, res_array);

    cout << "Array B: ";
    for (int i = 0; i < array.size(); i++){
        cout << res_array[i] << " ";
    }

    cout << endl;

    delete[] res_array;
    res_array = NULL;

    return 0;
}