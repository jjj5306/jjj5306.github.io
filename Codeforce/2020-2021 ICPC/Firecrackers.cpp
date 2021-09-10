#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, n, m, a, b;
	cin >> t;
	vector <int> result;
	int res = 0;
	while (t--) {
		cin >> n >> m >> a >> b;
		res = 0;
		// n:복도의 길이 m: 폭약 수 a : 강도 위치 b : 경호원 위치 
		vector <int> s(m);
		for (int i = 0; i < m; i++) cin >> s[i];
		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());
		for (int i = 0; i < m; i++) {
			if ((s[i] < (b - a) + (a - 1) && s[i] != -1) && a != b) {
				res++;
				b--;
				s[i] = -1;
			}
		}
		result.push_back(res);

		//(경찰 위치 - 강도 위치)+(강도 위치 -1)-1 과 같거나 작은 폭탄이 있는지 체크
		// 있으면 res[t]+=1하고 경찰위치 -1 없으면 종료
	}

	for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
}