/** 브루트포스 알고리즘 분해합 **/
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
    
    for (int i = 0; i < N; i++) {
        int n1, n2, n3, n4, n5, n6, n7;
        int temp = i;
        n1 = temp / 1000000;
        temp %= 1000000;

        n2 = temp / 100000;
        temp %= 100000;

        n3 = temp / 10000;
        temp %= 10000;

        n4 = temp / 1000;
        temp %= 1000;

        n5 = temp / 100;
        temp %= 100;

        n6 = temp / 10;
        temp %= 10;

        n7 = temp / 1;
        if (i + n1 + n2 + n3 + n4 + n5 + n6 + n7 == N)
        {
            cout << i;
            return 0;
        }
   
    }
    cout << 0;
    

}