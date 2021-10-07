/** 정수론 암호 키 **/
//다시 풀기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 1e6 + 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	//에라토스테네스의 체 생성
	vector <ll> S(MAX + 1, 0);
	for (int i = 2; i < S.size(); i++) {
		if (S[i] != 0) continue;
		for (int j = i; j < S.size(); j += i) S[j] = i;
	}

	//소수 목록 생성
	vector <ll> prime;
	for (int i = 2; i < S.size(); i++) if (S[i] == i) prime.push_back(i);


	vector <string> res;

	while (T--) {
		ll code;
		int flag = 0;
		cin >> code;
		for(int i=0;i<prime.size();i++){
			if (code % prime[i] == 0) {
				res.push_back("NO");
				flag = 1;
				break;
			}
		}
		if(!flag) res.push_back("YES");
	}
	for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";
}