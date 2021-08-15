/** 구현 문자열 반복 **/
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
    vector <string> result;
    while (T--) {
        string str, res="";
        int R;
        cin >> R >> str;
        for (int i = 0; i < str.length(); i++)
            for (int j = 0; j < R; j++)
                res =res+ str[i];

        result.push_back(res);

    }
    for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
}