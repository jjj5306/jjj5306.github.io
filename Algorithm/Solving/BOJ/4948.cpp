/** 정수론 베르트랑 공준 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//n보다 크고 2n보다 작거나 같은 소수의 개수
	//n은 최대 123456
	vector <int> S(123456*2+1, 1);
	S[0] = -1;
	S[1] = -1;
	for (int i = 2; i < S.size(); i++) {
		if (S[i] != 1) continue;
		if ((i * i) > S.size()) break;
		for (int j = i * i; j < S.size(); j += i)
			S[j] = 0;
	}
	vector <int> res(9999, 0);

	int T;
	int count = 0;
	while (1) {
		int number;
		cin >> number;
		if (number == 0) break;
		for (int i = number+1; i <= 2 * number; i++) {
			if (S[i] == 1) (res[count])++;
		}
		count++;
	}
	for (int i = 0; res[i] != 0; i++) cout <<res[i] << "\n";
}