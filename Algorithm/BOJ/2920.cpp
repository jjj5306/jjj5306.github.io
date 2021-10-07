/** 구현 음계 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector <int> note(8);
    string res;
    for (int i = 0; i < note.size(); i++) cin >> note[i];


    for (int i = 1; i <= note.size(); i++)
    {
        if (note[i-1] == i) res = "ascending";
        else {
            res.clear();
            break;
        }
    }
    if (res == "ascending") {
        cout << res;
        return 0;
    }

    for (int i = 0; i < note.size(); i++)
    {
        if (note[i] == 8-i) res = "descending";
        else {
            res.clear();
            break;
        }
    }
    if (res == "descending") {
        cout << res;
        return 0;
    }
    cout << "mixed";

}