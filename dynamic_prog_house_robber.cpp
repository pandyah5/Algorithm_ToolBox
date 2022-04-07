#include <iostream>

#define NUMS 10

using namespace std;

int houses[10] = {2, 5, 1, 7, 8, 2, 10, 1, 9, 4};
int memo[10] = {-1};

int max(int num1, int num2){
    if (num1 > num2)
        return num1;
    else
        return num2;
}

void print_memo(){
    int i;
    for(i = 0; i < NUMS; i++){
        cout << memo[i] << " ";
    }
    cout << endl;
    return;
}

int max_ammount(){
    int i;
    for (i = NUMS - 1; i >= 0; i--){
        if (i + 2 < NUMS){
            memo[i] = max(houses[i] + memo[i + 2], memo[i + 1]);
        }
        else{
            if (i == NUMS - 2)
                memo[i] = max(houses[i], memo[i + 1]);
            else
                memo[i] = houses[i];
        }
        print_memo();
    }
    return memo[0];
}

int main(void){

    int res = max_ammount();

    cout << "The max ammount is: " << res << endl;

    return 0;
}