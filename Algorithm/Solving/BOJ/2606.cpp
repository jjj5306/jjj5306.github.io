/** 그래프 바이러스 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//한 노드로부터 도달가능한 노드의 수를 세는것과 같다.
	int N, M;
	cin >> N >> M;
	
	//그래프는 탐색만 하면되므로 배열이 아닌 벡터의 배열로 linked list 형태로 구현한다.
	vector<int> graph[N+1];
	for(int i=0; i<M; i++){
		int a, b, tmp;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	stack <int>s;
	bool check[101] = {false, }; //방문했는지 체크하는 배열
	int res = 0;
	
	s.push(1);
	check[0] = check[1] = true;
	while(!s.empty()){
		int cur = s.top();
		s.pop();
		res++;
		for(int i=0; i < graph[cur].size(); i++){
			if(check[graph[cur][i]]) continue;
			check[graph[cur][i]] = true;
			s.push(graph[cur][i]);
		}
	}
	cout << --res;
	
}