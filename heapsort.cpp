#include <iostream>
#include <vector>

using namespace std;

void heapify (vector<int>& heap, int index, int len){
    int max_index = index;
    if (2*index + 1 < len && heap[2*index + 1] > heap[max_index]){
        max_index = 2*index + 1;
    }
    if (2*index + 2 < len && heap[2*index + 2] > heap[max_index]){
        max_index = 2*index + 2;
    }

    if (index == max_index){
        return;
    }

    int temp = heap[max_index];
    heap[max_index] = heap[index];
    heap[index] = temp;

    return heapify(heap, max_index, len);
}

void print_vec(const vector<int>& heap){
    int i = 0;
    while (i < heap.size()){
        cout << heap[i] << " ";
        i++;
    }
    cout << endl;
    return;
}

void buildheap(vector<int>& heap){
    for(int i = int(heap.size() / 2) + 1; i >= 0; i--){
        heapify(heap, i, heap.size());
    }
}

void heapsort(vector<int>& array, int last){
    if (last <= 0){
        return;
    }

    int temp = array[0];
    array[0] = array[last];
    array[last] = temp;

    heapify(array, 0, last);
    heapsort(array, last - 1);
    return;
}

int main(void){
    vector<int> array;
    array.push_back(5);
    array.push_back(2);
    array.push_back(1);
    array.push_back(4);
    array.push_back(6);
    array.push_back(3);

    print_vec(array);

    buildheap(array);
    heapsort(array, array.size() - 1);

    print_vec(array);

    return 0;
}