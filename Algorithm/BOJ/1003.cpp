/** 다이나믹 프로그래밍 피보나치 함수 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>  
#include <utility>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    int temp = T;
	//N은 0~40
	
	pair<int, int> p[41]; //인자는 차례대로 fib(0), fib(1) 호출 수
	p[0].first = 1;
	p[0].second = 0;
	p[1].first = 0;
	p[1].second = 1;
	
	for(int i = 2; i < 41; i++){
		p[i].first = p[i-1].first + p[i-2].first;
		p[i].second = p[i-1].second + p[i-2].second;
	}
	
	vector<pair<int, int>> res;
 	
    while (T--) {
		int N;
		cin >> N;
		res.push_back(make_pair(p[N].first, p[N].second));
	}
	
	for(int i = 0; i < temp; i++) cout << res[i].first << " " << res[i].second << "\n";
}