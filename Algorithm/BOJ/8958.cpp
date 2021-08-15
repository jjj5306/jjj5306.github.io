/** 구현 OX퀴즈 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    vector <int> result;
    while (T--) {
        string str;
        cin >> str;
        int temp=0, res = 0;
        for (int i = 0; i < str.length(); i++)
            if (str[i] == 'O') {
                temp++;
                res += temp;
            }
            else temp = 0;
        result.push_back(res);
    }
    for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
}