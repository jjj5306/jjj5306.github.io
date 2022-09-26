/** 자료구조 나는야 포켓몬 마스터 이다솜 **/
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//도감에 수록되어 있는 포켓몬의 수 N과 맞춰야 하는 문제의 수 M
	int N, M;
	cin >> N >> M;
	
	map <string, int> mp;
	string book[100000 + 1];
	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		mp.insert({ temp, i});
		book[i] = temp;
	}

	vector <string> res;
	
	while (M--) {
		string str;
		cin >> str;
		if(isdigit(str[0])) {
			int num = stoi(str);
			cout << book[num] << "\n";
		}
		else {
			cout << (mp.find(str)->second) << "\n";
		}
	}
}
