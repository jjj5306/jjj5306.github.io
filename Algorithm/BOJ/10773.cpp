/** 자료구조 제로 **/
#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;
	
	long long res=0;
	deque <int> num;
	int temp;

	for (int i = 0; i < K; i++) {
		cin >> temp;
		if (temp == 0) num.pop_back();
		else num.push_back(temp);
	}

	for (auto i : num) res += i;

	cout << res;
	

}