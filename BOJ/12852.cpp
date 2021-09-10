/** DP 1로 만들기 2 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long N;
	cin >> N;

	vector <long long> cache(N + 1, 0);
	//F에는 cache를 만드는데 사용한 이전 위치를 기록한다.
	vector <long long> F(N + 1, 0);
	F[1] = 0;
	if (N > 1) {
		cache[2] = 1;
		F[2] = 1;
	}
	if (N > 2) {
		cache[3] = 1;
		F[3] = 1;
	}

	for (long long i = 4; i <= N; i++) {
		if (i % 6 == 0) {
			if (cache[i / 2] <= cache[i / 3] && cache[i / 2] <= cache[i - 1]) {
				cache[i] = cache[i / 2] + 1;
				F[i] = i / 2;
			}
			else if (cache[i / 3] <= cache[i / 2] && cache[i / 3] <= cache[i - 1]) {
				cache[i] = cache[i / 3] + 1;
				F[i] = i / 3;
			}
			else if (cache[i - 1] <= cache[i / 2] && cache[i - 1] <= cache[i / 3]) {
				cache[i] = cache[i-1] + 1;
				F[i] = i-1;
			}
		}
		else if (i % 2 == 0) {
			if (cache[i / 2] <= cache[i - 1]) {
				cache[i] = cache[i / 2] + 1;
				F[i] = i / 2;
			}
			else {
				cache[i] = cache[i - 1] + 1;
				F[i] = i - 1;
			}
		}
		else if (i % 3 == 0) {
			if (cache[i / 3] <= cache[i - 1]) {
				cache[i] = cache[i / 3] + 1;
				F[i] = i / 3;
			}
			else {
				cache[i] = cache[i - 1] + 1;
				F[i] = i - 1;
			}
		}
		else{
			cache[i] = cache[i - 1] + 1;
			F[i] = i - 1;
		}	
	}

	cout << cache[N] << "\n";

	while (N != 0) {
		cout << N << " ";
		N = F[N];
	}

}