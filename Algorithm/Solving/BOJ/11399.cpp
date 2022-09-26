/** 그리디 알고리즘 ATM **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector <int> P(N);
	for(int i = 0; i < N; i++) cin >> P[i];
	
	//정렬한 후 그리디로 가장 작은거부터 누적합을 구하면 될 것 같다.
	sort(P.begin(), P.end());
	for(int i = 1; i < N; i++)
		P[i] += P[i-1];
	
	int res = 0;
	for(int i = 0; i < N; i++)	res += P[i];
	
	cout << res;
}
