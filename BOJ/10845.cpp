/** 자료구조 큐 **/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //queue stl은 사용하지 않고 구현해보자.
    vector <int> queue;
    //front+1에서 pop, back+1에서 push
    int front = -1, back=-1;

    int N;
    cin >> N;
    while (N--) {
        string order;
        cin >> order;
        if (order == "push") {
            back++;
            int X;
            cin >> X;
            queue.push_back(X);
        }
        else if (order == "pop") {
            if (front == back) {
                cout << -1 << "\n";
            }
            else {
                cout << queue[++front] << "\n";
            }
        }
        else if (order == "size") {
            cout <<  back-front << "\n";
        }
        else if (order == "empty") {
            if (front == back) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(order == "front"){
            if (front == back) cout << -1 << "\n";
            else cout << queue[front+1] << "\n";
        }
        else {
            if (front == back) cout << -1 << "\n";
            else cout << queue[back] << "\n";
        }
    }


}