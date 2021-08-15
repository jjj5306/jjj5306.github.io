/** 구현 X보다 작은 수 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, X;
    cin >> N>>X;
    vector <int> A(N);
    for (int i = 0; i < A.size(); i++) cin >> A[i];

    vector <int> res;

    for (int i = 0; i < A.size(); i++) if (A[i] < X) res.push_back(A[i]);

    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";


}