/** 자료구조 균형잡힌 세상 **/
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

	deque <string> res;
	while (1) {
		deque <char> temp;
		string s;
		int flag = 0;
		getline(cin, s);
		if (s == ".") break;
		for (auto i : s) {
			if (i == '(' || i == '[')  temp.push_back(i);
			else if (i == ')') {
				if (temp.empty() || temp.back() != '(') {
					flag = 1;
					break;
				}
				else temp.pop_back();
			}
			else if (i == ']') {
				if (temp.empty() || temp.back() != '[') {
					flag = 1;
					break;
				}
				else temp.pop_back();
			}
		}
		if (flag) res.push_back("no");
		else if(!temp.empty()) res.push_back("no");
		else res.push_back("yes");
	}

	for (auto i : res) cout << i << "\n";

}