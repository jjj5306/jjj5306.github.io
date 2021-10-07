/** 브루트포스 알고리즘 영화감독 숌 **/
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

	int count = 0;
	vector <int> res;
	string result = "0";

	while (count != N) {
		int temp = 0, tag = 0;
		for (int i = 0;i< result.length();i++) {
			if (result[i] == '6') {
				temp++;
			}
			else temp = 0;
			if (temp >= 3) {
				tag = 1;
				break;
			}
		}
		if (tag) {
			res.push_back(stoi(result));
			result = to_string(stoi(result) + 1);
			count++;
		}
		else {
			result = to_string((stoi(result) + 1));
		}
	}

	cout << res[N-1];

}