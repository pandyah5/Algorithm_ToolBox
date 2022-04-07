#include <iostream>

using namespace std;

#define NUMS 6

int input[NUMS] = {6, 2, 1, 2, 4, 5};

int dict[NUMS][2];

void print_memo(){
    for (int i = 0; i < NUMS; i++){
        for (int j = 0; j < 2; j++){
            cout << dict[i][j] << " ";
        }
        cout << endl;
    }
    cout << " --- " << endl;
}

void init_memo(){
    for (int i = 0; i < NUMS; i++){
        for (int j = 0; j < 2; j++){
            dict[i][j] = -1;
        }
    }
}

int max(int num1, int num2){
    if (num1 > num2)
        return num1;
    else
        return num2;
}

int odd_even(int index, int even){
    print_memo();

    if (dict[index][even] != -1){
        return dict[index][even];
    }

    int case1 = odd_even(index + 1, even);
    int case2;
    if (even)
        case2 = input[index] + odd_even(index + 1, !even);
    else
        case2 = -input[index] + odd_even(index + 1, !even);

    int res = max(case1, case2);
    dict[index][even] = res;
    return res;
}

int main(void){

    init_memo();

    int max_ammount = odd_even(0, 1);

    cout << max_ammount << endl;

    return 0;
}