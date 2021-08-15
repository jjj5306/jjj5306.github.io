/** 구현 알람 시계 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int H, M;
    cin >> H >> M;
    if (M >= 45) M = M - 45;
    else {
        if (H == 0) H = 23;
        else H--;
        M=15 + M;
    }
    
    cout << H << " " << M;
}