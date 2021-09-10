/** 정수론 소수 구하기 **/
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;
	//M이상 N이하의 소수 모두 출력
	//에라토스테네스의 체 생성
	vector <int> s(N + 1, 0);
	s[0] = 1;
	s[1] = 1;
	for (int i = 2; i < s.size(); i++) {
		if (s[i] != 0) continue;
		for (int j = 2*i; j < s.size(); j += i) {
			s[j] = 1;
		}
	}
	
	vector <int> res;
	for (auto i = M; i < s.size(); i++) if (s[i] == 0) res.push_back(i);

	for (auto i : res) cout << i << "\n";

}
