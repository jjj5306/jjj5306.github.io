/** 자료구조 덱 **/
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //deque stl은 사용하지 않고 구현해보자.
    deque <int> deque;

    int N;
    cin >> N;
    while (N--) {
        string order;
        cin >> order;
        if (order == "push_front") {
            int X;
            cin >> X;
            deque.push_front(X);
        }
        else  if (order == "push_back") {
            int X;
            cin >> X;
            deque.push_back(X);
        }
        else if (order == "pop_front") {
            if (deque.size() == 0) {
                cout << -1 << "\n";
            }
            else {
                cout << deque.front() << "\n";
                deque.pop_front();
            }
        }
        else if (order == "pop_back") {
            if (deque.size() == 0) {
                cout << -1 << "\n";
            }
            else {
                cout << deque.back() << "\n";
                deque.pop_back();
            }
        }
        else if (order == "size") {
            cout << deque.size() << "\n";
        }
        else if (order == "empty") {
            cout << deque.empty() << "\n";
        }
        else if (order == "front") {
            if (deque.empty()) cout << -1 << "\n";
            else cout << deque.front() << "\n";
        }
        else {
            if (deque.empty()) cout << -1 << "\n";
            else cout <<deque.back() << "\n";
        }
    }


}