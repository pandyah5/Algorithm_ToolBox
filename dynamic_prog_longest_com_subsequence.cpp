#include <iostream>
#include <string>

#define NUM_SPACE 2
#define DEBUG 1 // Turn it to 0 to not print memo matrices

using namespace std;

// string input1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
// string input2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

string input1 = "ABCDEFG";
string input2 = "ABABCG";

int** memo_matrix;

// Helper functions
int max(int num1, int num2){
    if (num1 > num2)
        return num1;
    else
        return num2;
}

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
    for (p = 0; p < input1.length() + 1; p++){
        for (q = 0; q < input2.length() + 1; q++){
            len = num_len(memo_matrix[p][q]);
            int pad_before = (NUM_SPACE - len)/2;
            int pad_after = NUM_SPACE - len - pad_before + 1;
            if (len > 1 || memo_matrix[p][q] > 0){
                pad_before++;
            }
            for(k = 0; k <= pad_before; k++){
                cout << " ";
            }
            cout << memo_matrix[p][q];
            for(k = 0; k < pad_after; k++){
                cout << " ";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << "---x---" << endl;
}


// Main DP function

int longest_common_subsequence(int first, int sec){

    //Check the memo
    if (DEBUG)
        print_memo();

    if (memo_matrix[first][sec] != -1){
        return memo_matrix[first][sec];
    }

    // Base cases
    if((input1.length() - first) == 0 || (input2.length() - sec) == 0){
        memo_matrix[first][sec] = 0;
        return 0;
    }
    if(input1.length() == first + 1 && input2.length() == sec + 1){
        if (input1[first] == input2[sec]){
            memo_matrix[first][sec] = 1;
            return 1;
        }
        else{
            memo_matrix[first][sec] = 0;
            return 0;
        }
    }

    // Calculate recusrsively
    int res;
    if (input1[first] == input2[sec]){
        res = 1 + longest_common_subsequence(first + 1, sec + 1);
        memo_matrix[first][sec] = res;
        return res;
    }
    else{
        res = max(longest_common_subsequence(first + 1, sec), longest_common_subsequence(first, sec + 1));
        memo_matrix[first][sec] = res;
        return res;
    }

    // Code should not reach here
    return -1;
}

int main (void){

    memo_matrix = (int**)malloc((input1.length() + 1) * sizeof(int*));

    int i, j;
    for (i = 0; i < input1.length() + 1; i++){
        memo_matrix[i] = (int*)malloc((input2.length() + 1) * sizeof(int));
    }

    for(i = 0; i < input1.length() + 1; i++){
        for (j = 0; j < input2.length() + 1; j++){
            memo_matrix[i][j] = -1;
        }
    }

    // for(i = 0; i < input1.length() + 1; i++){
    //     memo_matrix[i][0] = 0;
    //     memo_matrix[0][i] = 0;
    // }

    cout << "The longest sequence is of length: " << longest_common_subsequence(0, 0) << endl;
    return 0;
}