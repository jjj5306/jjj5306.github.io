/** 정렬 통계학 **/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	//-4000 ~ 4000까지의 숫자를 저장할 배열을 만든다. 3999 초과 숫자로 만든다.
	//num[0]은 -4000의 숫자이다. num[i]는 i-4000의 숫자이다.
	vector <int> num(8002, 0);

	for (auto i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		num[temp + 4000]++;
	}

	vector <int> res;

	//평균
	int sum = 0;
	for (int i = 0; i < num.size(); i++)
		for (int j = 0; j < num[i]; j++)
			sum += (i - 4000);
	 res.push_back(round((float)sum / N));

	//중앙값
	int count = 0;
	for (int i = 0; i < num.size(); i++){
		for (int j = 0; j < num[i]; j++) {
			count++;
			if (count == (N + 1) / 2) {
				res.push_back(i-4000);
				break;
			}
		}
	}

	//최빈값
	vector <int> temp;
	count = 0;
	for (int i = 0; i < num.size(); i++) {
		if (count < num[i]) {
			temp.clear();
			temp.push_back(i - 4000);
			count = num[i];
		}
		else if (count == num[i])
			temp.push_back(i - 4000);
	}
	if (temp.size() == 1) res.push_back(temp.front());
	else res.push_back(temp[1]);

	//범위
	if (N == 1) res.push_back(0);
	else {
		int min = 4001, max = -4001;
		for (int i = 0; i < num.size(); i++) {
			if (num[i] != 0) {
				if (i - 4000 > max) max = i - 4000;
				if (i - 4000 < min) min = i - 4000;
			}
		}
		res.push_back(max - min);
	}
	
	for (auto i : res) cout << i << "\n";

}