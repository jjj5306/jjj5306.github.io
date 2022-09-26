/** DP 가장 긴 증가하는 부분 수열 **/
//다시 풀기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	vector <int> A(N);
	for (auto& i : A) cin >> i;

	vector <int> B(N);
	B[0] = 1;

	for (int i = 1; i < N; i++) {
		//A[i]로 끝나는 부분 수열을 만든다. 
		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				//A[i]를 A[j]로 만든 수열 뒤에 붙일 수 있으면 B[i] = B[j] + 1이다. 그 값중 가장 최대를 사용해야한다.
				if (B[j] + 1 > temp) temp = B[j] + 1;
			}
			else
				if (1 > temp) temp = 1;
		}
		B[i] = temp;
	}

	sort(B.begin(), B.end());

	cout << B.back();
	
}
