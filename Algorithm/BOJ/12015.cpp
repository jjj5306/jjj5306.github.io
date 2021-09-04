/** DP 가장 긴 증가하는 부분 수열 2 **/
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

	vector<int> lis;

	for (auto& Ai : A) {
		auto it = lower_bound(lis.begin(), lis.end(), Ai);
		if (it == lis.end()) {
			lis.push_back(Ai);
		}
		else {
			*it = Ai;
		}

	}
	cout << lis.size();

}
