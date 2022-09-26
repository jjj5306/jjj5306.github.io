/** 구현 알파벳 찾기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    cin >> S;
    //a~z까지 총 26개
    vector <int> res(26, -1);
    vector <char> list;
    int tag = 0;
    for (int i = 0; i < S.length(); i++) {
        tag = 0;
        for (int j = 0; j < list.size(); j++) {
            if (list[j] == S[i]) {
                tag = 1;
                break;
            }
        }
        if (!tag) {
            res[S[i] - 'a'] = i;
            list.push_back(S[i]);
        }
    }
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
}