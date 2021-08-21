/** 자료구조 스택 **/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //stack stl은 사용하지 않고 구현해보자.
    vector <int> stack;
    int top = -1; //top+1에 push하고 top에 있는 원소를 pop한다.

    int N;
    cin >> N;
    while (N--) {
        string order;
        cin >> order;
        if (order == "push") {
            top++;
            int X;
            cin >> X;
            stack.push_back(X);
        }
        else if (order == "pop") {
            if (top == -1) {
                cout << -1 << "\n";
            }
            else {

                cout << stack[top] << "\n";
                stack.pop_back();
                top--;
            }
        }
        else if (order == "size") {
            cout << top + 1 << "\n";
        }
        else if (order == "empty") {
            if (top == -1) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else{
            if (top == -1) cout << -1 << "\n";
            else cout << stack[top]<< "\n";
        }
    }


}