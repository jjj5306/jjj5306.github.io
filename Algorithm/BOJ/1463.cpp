/** DP 1로 만들기 **/
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
	if (N > 1) cache[2] = 1;
	if (N > 2) cache[3] = 1;
	for (long long i = 4; i <= N; i++) {
		if (i % 6 == 0) 
			cache[i] = min(min(cache[i / 3] + 1, cache[i / 2] + 1), cache[i - 1] + 1);
		else if (i % 2 == 0)
			cache[i] = min(cache[i / 2] + 1, cache[i - 1] + 1);
		else if (i % 3 == 0)
			cache[i] = min(cache[i / 3] + 1, cache[i - 1] + 1);
		else
			cache[i] = cache[i - 1] + 1;
	}

	cout << cache[N] << endl;

}
