/** 다이나믹 프로그래밍 Four Squares **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> dp(50000 + 1);
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;
	dp[5] = 2;
	for (int i = 6; i <= n; i++) {
		int min_res = 0;
		for (int j = 2; j * j <= i; j++) {
			if (min_res == 0 || dp[i - j * j] + 1 < min_res) min_res = dp[i - j * j] + 1;
		}
		dp[i] = min_res;
	}
	cout << dp[n];

}