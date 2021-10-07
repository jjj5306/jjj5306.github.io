/** 구현 집합 **/
//어렵게 생각하지 말기
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int M;
	cin >> M;
	bool num[21] = { 0, };

	while (M--) {
		string cmd;
		cin >> cmd;

		if (cmd == "add") {
			int x;
			cin >> x;
			num[x] = 1;
		}
		else if (cmd == "remove") {
			int x;
			cin >> x;
			num[x] = 0;
		}
		else if (cmd == "check") {
			int x;
			cin >> x;
			cout<<num[x]<<"\n";
		}
		else if (cmd == "toggle") {
			int x;
			cin >> x;
			if (num[x]) num[x] = 0;
			else num[x] = 1;
		}
		else if (cmd == "all") {
			fill(num+1, num + 21, 1);
		}
		else {
			fill(num+1, num+21, 0);
		}
	}

}