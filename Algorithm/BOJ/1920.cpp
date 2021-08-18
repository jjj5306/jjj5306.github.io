/** 구현 수 찾기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;

    cin >> N;
    vector <ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    cin >> M;
    vector <ll> X(M);
    for (ll i = 0; i < M; i++) cin >> X[i];

    vector <ll> res(M, 0);
    //X의 원소들이 A에 있는지 체크한다.

    for (int x = 0; x < M; x++) {
        int flag = 0;
        int first = 0, last = N-1;
         while(first <= last){
            int mid = (first + last + 1) / 2;
            if (A[mid] == X[x]) {
                res[x] = 1;
                flag = 1;
                break;
            }
            else if (A[mid] > X[x]) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
         }
         if (!flag) res[x] = 0;
  }


    for (ll i = 0; i < M; i++) cout << res[i] << "\n";

}