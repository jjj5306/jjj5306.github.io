/** 구현 부녀회장이 될테야 **/
//이차원 배열 연습하기 좋음
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>  
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    vector <int> res;
    //a층 b호에 살려면 a-1층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와야한다.
    //k층 n호에는 몇 명이 살까
    //0층 i호에는 i명이 산다

    while (T--) {
        int k, n;
        cin >> k >> n;
        int** array = new int* [k+1];
        for (int i = 0; i < k + 1; i++) array[i] = new int[n + 1];

        for (int col = 1; col <= n; col++) array[0][col] = col;

        for (int row = 1; row <= k; row++) {
            for (int col = 1; col <= n; col++) {
                if (col == 1) {
                    array[row][col] = 1;
                }
                else {
                    int temp = 0;
                    for (int i = 1; i <= col; i++) temp += array[row - 1][i];
                    array[row][col] = temp;
                }
            }
        }
        res.push_back(array[k][n]);

        for (int i = 0; i < k+1; ++i) delete[] array[i]; 
        delete[] array;
    }
    for (int i = 0; i < res.size(); ++i) cout << res[i] << "\n";
}