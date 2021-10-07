/** 자료구조 프린터 큐 **/
//큐는 순회할 수 없다!
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

typedef struct docu {
	int order, importance;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	vector <int> res;
	while (T--) {
		int N, M, count=0;
		cin >> N >> M;
		deque <docu> q;
		for (auto i = 0; i < N;i++) {
			int temp;
			cin >> temp;
			q.push_back({ i, temp });
		}

		while (1) {
			//중요도 확인
			docu max = q[0];
			int temp=0;
			for (auto i = 1;i < q.size();i++)
				if (max.importance < q[i].importance) {
					max = q[i];
					temp = i;
				}

			if (max.order == M) {
				count++;
				res.push_back(count);
				break;
			}
			else {
				if (temp == 0) {
					count++;
					q.pop_front();
				}
				else {
					q.push_back(q.front());
					q.pop_front();
				}
			}
		}
	}

	for (auto i : res) cout << i << "\n";

}
