/** 구현 직사각형에서 탈출 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>  
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;
    if (w - x < x) x = w - x;
    if (h - y < y) y = h - y;

    if (x > y) cout <<  y;
    else cout << x;

}