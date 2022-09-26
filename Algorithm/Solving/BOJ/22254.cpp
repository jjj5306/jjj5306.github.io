/** 매개 변수 탐색 공장 컨설턴트 호석 **/
//다시 풀기 pq 활용하기 좋음
#include<iostream>
#include<vector>
#include <queue>
#include<algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin >> N >> X;

	vector <int> time(N);
	for (auto& i : time) cin >> i;

	//공정 라인 개수를 처음에는 1개 ~ N개로 범위를 설정한다.
	//이 범위를 조정해가면서 최적화한다.
	int left = 1, right = N;
	while (left < right) {
		int mid = (left + right) / 2;

		//우선순위 큐에 mid개 만큼의 0을 push한다. pq의 각 칸이 line이다.
		priority_queue <int, vector<int>, greater<int>> pq;
		for (int i = 0; i < mid; i++) pq.emplace(0);
		//time의 원소들을 하나씩 우선순위 큐에서 pop한것에 더해서 push한다
		int flag = 0;
		for (auto i : time) {
			int top = pq.top()+i;
			pq.pop();
			//소요 시간이 X 이상인 경우 flag를 1로 만든다
			if (top > X) flag = 1;
			pq.emplace(top);
		}
		
		//소요시간이 X이하이면 공정 라인을 줄여도 될 수 있다.
		if (!flag) right = mid;
		//소요시간이 X보다 크다면 공정 라인을 늘려야 한다.
		else left = mid + 1;
	}
	cout << left;

}