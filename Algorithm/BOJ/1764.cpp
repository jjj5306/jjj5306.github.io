/** 자료구조 듣보잡 **/
//다시풀기, 어떻게하면 배운 자료구조를 써먹을까?
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	//듣도 못한 사람을 저장한다. 이 때 set을 활용한다.
	set<string> a;
	set<string> res;
	int count = 0;
	
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		a.insert(s);
	}
	
	//보도 못한 사람을 하나 입력받고, set a에서 있는지 바로 검색한다. 이 때 검색 속도를 높이기 위해 set을 사용하였다.
	for(int i = 0; i < M; i++){
		string s;
		cin >> s;
		if(a.find(s) != a.end()){
			count++;
			res.insert(s);
		}
	}
	
	cout << count << "\n";
	for(auto x : res ){
		cout << x << "\n";
	}
}