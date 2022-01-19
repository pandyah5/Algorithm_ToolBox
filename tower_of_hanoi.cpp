#include <iostream>
#include <stack>

using namespace std;

void move(stack<int>& from, stack<int>& to, stack<int>& other, int num){
    if (num == 0){
        return;
    }

    move(from, other, to, num - 1);
    to.push(from.top());
    from.pop();
    move(other, to, from, num - 1);
    return;
}

int main (void){
    stack<int> A;
    A.push(3);
    A.push(2);
    A.push(1);

    stack<int> B;
    stack<int> C;

    move(A, B, C, 3);
    
    cout << "A: ";
    while(!A.empty()){
        cout << A.top() << " ";
        A.pop();
    }
    cout << endl;

    cout << "B: ";
    while(!B.empty()){
        cout << B.top() << " ";
        B.pop();
    }
    cout << endl;

    cout << "C: ";
    while(!C.empty()){
        cout << C.top() << " ";
        C.pop();
    }
    cout << endl;

    return 0;
}
