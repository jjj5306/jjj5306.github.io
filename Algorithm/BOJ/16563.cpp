/** 정수론 어려운 소인수분해 **/
//다시풀기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	//1~5000000 숫자에 대해 에라토스 테네스의 체 생성
	//s[i]에는 소인수가 들어가고 S[i] = i면 소수이다
	vector <int> S(5000001, 0); 
	for (int i = 2;i<S.size();i++) {
		if(S[i] != 0) continue;		
		for (int j = i; j < S.size(); j += i) S[j] = i;
	}

	while (T--) {
		int temp;
		vector <int> res;
		cin >> temp;
		while(temp > 1){
			res.push_back(S[temp]);
			temp = temp / S[temp];
		}
		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) cout <<res[i] <<" ";
		cout << "\n";
	}
}