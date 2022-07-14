/** 그리디 동전0 **/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	
	//배낭 문제와 비슷하다. 그리디로 쉽게 해결할 수 있다.
	//그냥 벡터를 이용해서 처음부터 순회하면서 그리디하게 해결하면 시간초과가 뜬다.
	//이분탐색을 이용하거나 set을 이용하면 될 것 같다. 자료의 입력이 있어서 이분탐색이 더 빠를 것 같았다.
	vector<int> coin(N, 0);
	for(int i = 0; i < N; i++){
		int tmp;
		cin >> tmp;
		coin[i] = tmp;
	}
	
	int res = 0;
	while(K > 0){
		auto x = lower_bound(coin.begin(), coin.end(), K);
		if(*x == K){
			res++;
			K = 0;
			break;
		}else{
			res++;
			K -= *(--x);
		}
	}
	
	cout << res << "\n";
}