/** 구현 벌집 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>  
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    if (N == 1) cout << 1;
    else if (N == 2) cout << 2;
    else {
        vector <int> res;
        int i = 2, count = 1, temp;
        while (1) {
            res.push_back(i);
            if (i >= N) break;
            i += 6 * (count++);
        }
        for (int j = 1; j < res.size(); j++) {
            if (res[j] == N) temp = j;
            else if (res[j] > N) temp = j - 1;
        }
        cout << temp+2;
            
    }
 
}