/** 자료구조 최소 힙 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	vector<int> res;
	
	while(N--){
		int x;
		cin >> x;
		if(x > 0) pq.push(x);
		else {
			if(pq.empty())
				res.push_back(0);
			else{
				res.push_back(pq.top());
				pq.pop();
			}
		}
			 
	}

	for(auto x : res) cout << x << "\n";
}