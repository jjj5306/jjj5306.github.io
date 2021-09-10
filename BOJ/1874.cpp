/** 자료구조 스택 수열 **/
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector <int> req(n);
	vector <string> res;
	int count = 0, flag = 0;
	stack <int> s;
	for (auto& i : req) cin >> i;
	for (auto& i : req) {
		//스택에 현재까지 들어간 수보다 만들어야 할 수가 작다면 pop하면서 확인
		if (count > i) {
			while (!s.empty()&&s.top() != i) {
				res.push_back("-");
				s.pop();
			}
			if (s.empty()) {
				cout << "NO";
				return 0;
			}
			else {
				res.push_back("-");
				s.pop();
			}
		}
		//스택에 현재까지 들어간 수보다 만들어야 할 수가 크다면 그 수까지 push
		else if (count < i) {
			while (count != i) {
				count++;
				res.push_back("+");
				s.push(count);
			}
			res.push_back("-");
			s.pop();
		}
	}

	for (auto i : res) cout << i << "\n";
}
