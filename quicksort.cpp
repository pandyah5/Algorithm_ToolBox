#include <iostream>

using namespace std;

void quicksort(int* array, int left, int right);
int shuffle(int*, int, int);

int main(void){
    int array[10];
    for (int i = 0; i < 10; i++){
        cout << "Enter element number " << i + 1 << ": ";
        cin >> array[i];
        cout << endl;
    }
    quicksort(array, 0, 9);
    cout << endl << "The sorted array is: " << endl;
    for (int i = 0; i < 10; i++){
        cout << array[i] << " ";
    }
    return 0;
}

void quicksort(int* array, int left, int right){
    int pivot;
    pivot = shuffle(array, left, right);
    if (pivot > left){
        quicksort(array, left, pivot - 1);
    }
    if (pivot < right){
        quicksort(array, pivot + 1, right);
    }
}

int shuffle(int* array, int left, int right){
    int p_loc = left, i = left + 1;
    for (i = left + 1; i <= right; i++){
        if (array[i] <= array[p_loc]){
            p_loc++;
            int temp = array[i];
            array[i] = array[p_loc];
            array[p_loc] = temp;
        }
    }
    int temp = array[p_loc];
    array[p_loc] = array[left];
    array[left] = temp;
    return p_loc;
}
