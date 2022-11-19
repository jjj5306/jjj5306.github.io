/** 그래프 탐색 숨바꼭질 **/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 200001; // 수빈이와 동생의 위치는 최대 십만이지만 이동가능한 거리는 최대 이십만이다.
	
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int N, K;
	cin >> N >> K;
	
	if(N == K){
		cout << "0" << "\n";
		return 0;
	}
	
	int dp[MAX] = {0, };
	queue<int> q;
	q.push(N);
	dp[N] = 0;

	while(!q.empty()){
		//BFS로 탐색을 시작한다.
		int currunt_location = q.front();
		q.pop();
		//갈 수 있는 곳인지 먼저 판단한 후, 그 곳이 아직 방문하지 않은 곳인지 꼭 체크해줘야한다. 방문한 적이 있다면 다시 거친게 되므로 최단거리가 아니게 된다. 
		if(currunt_location-1 >= 0 && dp[currunt_location-1] == 0){
			//갈 수 있고 처음 방문하는 점이라면 큐에 추가하여 탐색한다.
			q.push(currunt_location-1);
			dp[currunt_location-1] = dp[currunt_location] + 1;
		}
		if(currunt_location+1 < MAX && dp[currunt_location+1] == 0){
			q.push(currunt_location+1);
			dp[currunt_location+1] = dp[currunt_location] + 1;
		}
		if(currunt_location*2 < MAX && dp[currunt_location*2] == 0){
			q.push(currunt_location*2);
			dp[currunt_location*2] = dp[currunt_location] + 1;
		}
		if(dp[K] != 0) break; //동생과 만나면 종료
	}
	
	cout << dp[K] << "\n";
}