/** 문자열 단어 공부 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	vector <int> res(1000, 0);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < 'a') {
			str[i] += ('a'-'A');
		}
		res[str[i] - 'a']++;
	}
	vector <int> temp(res);
	sort(temp.begin(), temp.end());
	reverse(temp.begin(), temp.end());
	if (temp[0] == temp[1]) {
		cout << "?";
		return 0;
	}
	
	for (int i = 0; i < res.size(); i++) {
		if (res[i] == temp[0]) cout << (char)(i+'A');
	}

	
}