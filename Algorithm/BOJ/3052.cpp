/** 구현 나머지 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector <int> num(10);
    vector <int> res;
    vector <int> list;
    for (int i = 0; i < 10; i++) cin >> num[i];
    for (int i = 0; i < num.size(); i++) res.push_back(num[i] % 42);

    int result = 0, tag=0;
    for (int i = 0; i < res.size(); i++) {
        tag = 0;
        for (int j = 0; j < list.size();j++) {
            if (list[j] == res[i]) {
                tag = 1;
                    break;
            }
        }
            if (!tag) {
                result++;
                list.push_back(res[i]);
            }
        
    }
    cout << result;
}