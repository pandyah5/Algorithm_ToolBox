#include <iostream>
#include <vector>

using namespace std;

vector<float> insertion_sort(const vector<float>& arr, int len){
	//  Initializing variables
	int i = 0;
	float* new_arr = new float[len];
	
	// Creating a copy of the array
	for (int j = 0; j < len; j++){
		new_arr[j] = arr[j];
	}
	
	// Insertion sort
	while(i < len){
		float k = i, temp;
		while(i > 0 && new_arr[i] < new_arr[i - 1]){
			temp = new_arr[i - 1];
			new_arr[i - 1] = new_arr[i];
			new_arr[i] = temp;
			i--;
		}
		i = k + 1;
	}

    vector<float> result;
    for(int i = 0; i < len; i++){
        result.push_back(new_arr[i]);
    }
	
    delete[] new_arr;
	// Return sorted array
	return result;
}

vector<float> bucket_sort(vector<float> arr, int len){
    vector<vector<float>> bucket_list;
    for(int i = 0; i < len; i++){
        vector<float> bucket;
        bucket_list.push_back(bucket);
    }

    for (int j = 0; j < len; j++){
        int index = (int)(arr[j] * len);
        bucket_list[index].push_back(arr[j]);
    }

    vector<float> result;
    for(int k = 0; k < len; k++){
        vector<float> temp = insertion_sort(bucket_list[k], bucket_list[k].size());
        result.insert(result.end(), temp.begin(), temp.end());
    }

    return result;
}

int main(void){

    vector<float> arr = {0.3, 0.1, 0.5, 0.7, 0.2, 0.6, 0.4, 0.9, 0.8, 0.85};

    vector<float> result = bucket_sort(arr, arr.size());

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}