/** 다이나믹프로그래밍 피보나치 수  **/
#include<iostream>
using namespace std;

const int C_SIZE = 100;
long long cache[C_SIZE];

long long F(int x) {
    if (cache[x] != -1) return cache[x];
    
     if (x == 0) return cache[x] = 0;
     if (x == 1) return cache[x] = 1;
     else return cache[x] = F(x - 1) + F(x - 2);
}

int main() {
    for (int i = 0; i < C_SIZE; i++) cache[i] = -1;

    int x;
    cin >> x;
    cout << F(x);
}