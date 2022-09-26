/** 자료구조 비밀번호 찾기 **/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	//map에다 사이트와 비밀번호를 저장하여 검색시 log n 만에 검색할 수 있게 한다.
	map<string, string> m;
	for(int i = 0; i < N; i++){
		string s1, s2;
		cin >> s1 >> s2;
		m.insert(make_pair(s1, s2));
	}
	
	vector<string> res;
	for(int i = 0; i < M; i++){
		string s1;
		cin >> s1;
		res.push_back(m.find(s1)->second);
	}
	
	for(auto x : res)
		cout << x << "\n";
}