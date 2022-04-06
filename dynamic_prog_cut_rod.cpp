#include <iostream>

using namespace std;

int price_list[30] = {3, 1, 10, 4, 1, 1, 2, 3, 2, 1, 6, 7, 8, 2, 1, 6, 9, 2, 7, 5, 3, 1, 10, 4, 1, 1, 2, 3, 2, 1};
int memo[31] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int max(int num1, int num2){
    if (num1 > num2)
        return num1;
    else
        return num2;
}

int cut_rod_naive(int num){
    if(num <= 0)
        return 0;
    int q = -999;
    int i;
    for(i = num; i > 0; i--){
        q = max(q, price_list[i - 1] + cut_rod_naive(num - i));
    }
    // cout << "Num: " << num << " q: " << q << endl;
    return q;
}

int cut_rod_dp(int num){
    //cout << num << endl;
    memo[0] = 0;
    if(num <= 0)
        return 0;
    if (memo[num] != -1){
        return memo[num];
    }
    else{
        int q = -999;
        int i;
        for(i = num; i > 0; i--){
            q = max(q, price_list[i - 1] + cut_rod_dp(num - i));
        }
        memo[num] = q;
        //cout << "Num: " << num << " q: " << q << endl;
        return q;
    }
}

int cut_rod_dp_bottum_up(int num){
    memo[0] = 0;
    
    int i;
    int j;
    int q = -999;
    
    for(j = 1; j <= num; j++){
        q = -999;
        for(i = 1; i <= j; i++){
            q = max(q, price_list[i - 1] + memo[j - i]);
        }
        memo[j] = q;
    }
    return memo[num];
}

int main()
{
    
    int i = 0;
    for (i = 0; i < 20; i++){
        cout << price_list[i] << " ";
    }
    cout << endl;
    
    // Stress testing
    
    for (int j = 0; j < 20; j++){
        if (cut_rod_dp(j) == cut_rod_naive(j)){
            cout << j << " passed" << endl;
        }
        else{
            cout << j << " failed" << endl;
        }
    }
    
    
    return 0;
}
