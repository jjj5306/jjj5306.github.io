/** 다이나믹 프로그래밍 1, 2, 3 더하기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int T;
	cin >> T;
	
	//n = (n-1) + 1 = (n-2) +2 = (n-3) + 3이라는 점에서 dp를 이용할 수 있을 것 같았다.
	vector<int> dp(12);
	dp[0] = 0; //0은 사용 x
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i < 12 ; i++)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	
	vector<int> res;
	while(T--){
		int n;
		cin >> n;
		res.push_back(dp[n]);
	}
	
	for(auto x : res)
		cout << x << "\n";
}