#include <iostream>
#include <bits/stdc++.h>

#define NUM_MATRIX 5
#define NUM_SPACE 10

using namespace std;

// If matrices are: 50x100, 100x30, 30x200, 200x10, 10x10
// p_array is [50, 100, 30, 200, 10, 10]

// Input
int p_array[NUM_MATRIX + 1] = {10, 100, 20, 50, 10, 100};
// 50x100, 100x10, 10x10

// For memoization
int mult[NUM_MATRIX][NUM_MATRIX] = {0};

// For retracing the answer
int k_mat[NUM_MATRIX-1][NUM_MATRIX-1] = {0};

int num_len(int num){
    int count = 0;
    while (num != 0){
        num = num/10;
        count += 1;
    }
    return count;
}

void print_memo(){
    int p, q, k, len;
    cout << "Printing memo:" << endl;
    for (p = 0; p < NUM_MATRIX; p++){
        for (q = 0; q < NUM_MATRIX; q++){
            len = num_len(mult[p][q]);
            int pad_before = (NUM_SPACE - len)/2;
            int pad_after = NUM_SPACE - len - pad_before + 1;
            if (len > 1){
                pad_before++;
            }
            for(k = 0; k <= pad_before; k++){
                cout << " ";
            }
            cout << mult[p][q];
            for(k = 0; k < pad_after; k++){
                cout << " ";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << "---x---" << endl;
}

int matrix_chain(){
    int i;
    for (i = 0; i < NUM_MATRIX; i++){
        mult[i][i] = 0;
    }

    int start;
    int end;

    int chain_length;
    for (chain_length = 2; chain_length <= NUM_MATRIX; chain_length++){
        for (start = 1; start <= NUM_MATRIX - chain_length + 1; start++){
            end = chain_length + start - 1;
            //cout << "HEHE " << start << " - " << end << endl;
            mult[start - 1][end - 1] = INT_MAX;
            int iter;
            int q;
            for (iter = start; iter <= end - 1; iter++){
                q = mult[start - 1][iter - 1] + mult[iter][end - 1] + p_array[start-1]*p_array[iter]*p_array[end];
                //cout << start << " - " << iter << " - " << end << " - " << q << endl;
                if (q < mult[start-1][end-1]){
                    mult[start-1][end-1] = q;
                    k_mat[start-1][end-1] = iter;
                }
                print_memo();
            }
        }
    }

    return 0;
}

int main(void){
    matrix_chain();
    cout << mult[0][NUM_MATRIX - 1] << endl;
    return 0;
}