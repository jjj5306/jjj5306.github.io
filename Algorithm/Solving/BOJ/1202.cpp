/**  그리디 보석도둑 **/

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	//보석 총 N개, 가방 K개
	int N, K;
	cin >> N >> K;
	

	pair<int, int> jewelry[300001];
	int bag[300001];
	
	for(int i=0; i<N; i++) cin >> jewelry[i].first >> jewelry[i].second;
	for(int i=0; i<K; i++) cin >> bag[i];
	
	//가방을 제일 낮은거부터 넣을 수 있는 보석 중 가장 가치가 큰거 넣기
	//보석 무게기준, 가방 오름차순 정렬
	sort(jewelry, jewelry+N);
	sort(bag, bag+K);
	
	priority_queue<int> pq;
	long long res = 0;
	int idx=0;
	for(int i=0; i<K; i++){
		//i번째 가방의 무게 제한에 충족하는 보석 중 가장 비싼거 넣기
		//idx번째 보석을 i번째에 넣을 수 있으면 i+1번째 가방에도 넣을 수 있으므로 초기화x    
		while(idx < N && jewelry[idx].first <= bag[i]) pq.push(jewelry[idx++].second);
		
		//pq에는 i번째 가방에 넣을 수 있는 보석 다 넣음. 루트에는 가장 비싼것이 있음
		if(!pq.empty()){
			res+=pq.top();
			pq.pop();
		}
	}
	cout << res << "\n";
}