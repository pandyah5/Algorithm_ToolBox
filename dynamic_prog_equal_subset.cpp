#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#define NUMS 4

int input[NUMS] = {1,5,11,5};   
int goal;
set <int> target;

int check_target(){
    for(auto iter = target.begin(); iter != target.end(); iter++){
        if(*iter == goal){
            return 1;
        }
    }
    return 0;
}

int equal_subset(){
    int i = 0;
    for (i = 0; i < NUMS; i++){
        if (target.size() == 0){
            target.insert(0);
            target.insert(input[i]);
            continue;
        }
        set <int> temp;
        for(auto iter = target.begin(); iter != target.end(); iter++){
            temp.insert(*iter);
            temp.insert(*iter + input[i]);
        }
        target = temp;

        if (check_target() == 1){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int i;
    for(i = 0; i < NUMS; i++){
        goal += input[i];
    }

    if (goal % 2 == 1){
        cout << "Not possible\n";
        return 0;
    }

    goal = goal/2;

    if (equal_subset() == 1){
        cout << "Possible\n";
    }
    else{
        cout << "Not possible!\n";
    }

    return 0;
}