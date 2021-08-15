/** 구현 직각삼각형 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>  
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector <int> res(3);
    while (1) {
        cin >> res[0] >> res[1] >> res[2];
        if ((res[0] == 0 && res[1] == 0) && res[2] == 0) break;
        sort(res.begin(), res.end());
        if (res[0] * res[0] + res[1] * res[1] == res[2] * res[2]) cout << "right"<<"\n";
        else cout << "wrong"<<"\n";
    }


}