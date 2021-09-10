/** DP 연속합 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <int> seq(n);
	for (auto& i : seq) cin >> i;

	//res[i] = seq[i]로 끝나는 수열의 합 중 최대값 이 저장된다.
	vector <int> res(n);
	res[0] = seq[0];

	//res[i-1]은 seq[i-1]로 끝나는 수열의 합 중 최대값이 있으므로 
	//res[i]는 res[i-1] + seq[i](seq[i]이전의 원소를 더하는 것이 더 큰 경우)
	//seq[i](seq[i]이전의 원소를 더하지 않는 것이 더 큰 경우) 중 최대값을 사용하면 된다.
	for (int i = 1; i < n; i++){
		res[i] = max(res[i - 1] + seq[i], seq[i]);
	}

	sort(res.begin(), res.end());

	cout << res.back();
}
