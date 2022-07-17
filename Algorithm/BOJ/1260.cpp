/** 그래프 DFS와 BFS **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, V;
	cin >> N >> M >> V;
	
	vector<int> graph[N+1];
	for(int i=0; i<M; i++){
		int a, b, tmp;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i=1; i < N+1; i++){
        sort(graph[i].begin(), graph[i].end());
    }
	
	stack <int>s;
	queue <int>q;
	bool check[1001] = {false, }; //방문했는지 체크하는 배열
	bool check2[1001] = {false, };
	vector<int> dfs;
	vector<int> bfs;
	
	//DFS by stack
	s.push(V);
	while(!s.empty()){
		int cur = s.top();
		s.pop();
		
		if(!check[cur]) dfs.push_back(cur);
		check[cur] = true;
		
		for(int i=graph[cur].size()-1; i >= 0 ; i--)
			if(!check[graph[cur][i]]) s.push(graph[cur][i]);
	}
	
	//BFS by queue
	q.push(V);
	check2[V] = true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		bfs.push_back(cur);
		
		for(int i=0; i < graph[cur].size(); i++){
			if(!check2[graph[cur][i]]){
				q.push(graph[cur][i]);
				check2[graph[cur][i]] = true;
			}
		}
	}
	
	for(auto x : dfs)
		cout << x << " ";
	cout << "\n";
	for(auto x : bfs)
		cout << x << " ";
	
}