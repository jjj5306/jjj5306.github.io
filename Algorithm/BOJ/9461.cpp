/** 다이나믹 프로그래밍 파도반 수열 **/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	
	int T;
	cin >> T;
	
	vector<long long> dp(101);
	dp[1] = dp[2] = dp[3] = 1;
	for(int i=4; i<101; i++)
		dp[i] = dp[i-2] + dp[i-3];
	
	vector<long long> res;
	
	while(T--){
		int x;
		cin >> x;
		res.push_back(dp[x]);
	}
	
	for(auto x : res)
		cout << x << "\n";
	
}