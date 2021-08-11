/** 정수론 골드바흐의 추측**/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	//5000까지 에라토스테네스의 체 생성
	vector <int> S(10001, 1);
	S[0] = -1;
	S[1] = -1;
	for (int i = 2; i < S.size(); i++) {
			if (S[i] != 1) continue;
			if ((i * i) > S.size()) break;
			for (int j = i*i; j < S.size(); j += i)
				S[j] = 0;
		}
	vector <int> res;

	while (T--) {
		int number;
		cin >> number;
		int res1=9999999, res2=0;
		for (int i = 2; i * 2 <= number; i++) {
			if (S[i] == 1 && S[number - i] == 1) //i와 number-i가 소수라면 
			{
				if (abs(2 * i - number) < abs(res1 - res2)) {
					res1 = i;
					res2 = number - i;
				}
			}
		}
		res.push_back(res1);
		res.push_back(res2);
	}
	for (int i = 0; i < res.size(); i += 2) {
		if(res[i] > res[i+1]) cout << res[i+1] << " " << res[i] << "\n";
		else cout << res[i] << " " << res[i + 1] << "\n";
	}
}