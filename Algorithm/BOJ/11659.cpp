/** DP 구간 합 구하기 4 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >>M;

	vector <int> num(N);
	for (auto& i : num) cin >> i;
	vector <int> res;
	//sum[i] = num[0]+num[1] + ... + num[i]가 저장되어 있다.
	vector <int> sum(N); 
	sum[0] = num[0];
	for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + num[i];
	}

	while (M--) {
		int i, j;
		cin >> i >> j;
		i--;
		j--;
		//i번째 수부터 j번째 수까지 합을 구하라.
		//sum[j] = num[0] + ... + num[i] + ... + num[j]
		//sum[i-1] = num[0] + ... + num[i-1]
		if (i == 0) res.push_back(sum[j]);
		else  res.push_back(sum[j] - sum[i - 1]);
	}

	for (auto r : res) cout << r << "\n";

}
