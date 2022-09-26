/** 구현 숫자의 개수 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A, B, C;
    cin >> A >> B >> C;
    int res = A * B * C;
    string str = to_string(res);
    vector <int> result(10, 0);

    for (int i = 0; i < str.length(); i++) result[str[i]-'0']++;
    for (int i = 0; i < result.size(); i++) cout<<result[i] <<"\n";

}