/** 다이나믹 프로그래밍 계단 오르기 **/
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> stairs(N);
	for(int i=0; i<N; i++){
		int tmp;
		cin >> tmp;
		stairs[i] = tmp;
	}
	
	vector<int> dp(N);
	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
	for(int i = 3; i<N; i++)
		dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
	
	cout << dp[N - 1] << "\n";

	
}
