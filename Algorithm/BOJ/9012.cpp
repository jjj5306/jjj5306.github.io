/** 자료구조 괄호 **/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    vector <string> res;

    while (T--) {
        int tag = 0;
        string str;
        cin >> str;

        queue <char> que;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') que.push(str[i]);
            else {
                if (!que.empty()) {
                    que.pop();
                }
                else {
                    tag = 1;
                    break;
                }
            }
        }
        if (!que.empty()) tag = 1;

        if (!tag) res.push_back("YES");
        else res.push_back("NO");
    }
    
    for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";

}