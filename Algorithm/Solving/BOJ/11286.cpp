/** 우선순위 큐 절댓값 힙 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;
/**********************************************************************************************
int heap_cur_idx = 0;
vector<int>min_heap (100001);
vector<int>res;

void heap_swap(int a, int b){
	int tmp = min_heap[a];
	min_heap[a] = min_heap[b];
	min_heap[b] = tmp;
}

void insert_heap(int x){
	min_heap[++heap_cur_idx] = x;
	//현재 idx부터 부모로 올라가면서 절대값이 작은 값을 점점 위로 보낸다
	for(int idx = heap_cur_idx; idx > 1; idx /= 2){
		if(abs(min_heap[idx]) < abs(min_heap[idx/2])) heap_swap(idx, idx/2);
		else if(abs(min_heap[idx]) == abs(min_heap[idx/2])) {
			if(min_heap[idx] < min_heap[idx/2])
				heap_swap(idx, idx/2);
		}
		else break;
		
	}
}

int deletion_heap(){
	if(heap_cur_idx == 0) return 0;
	int return_val = min_heap[1];
	min_heap[1] = min_heap[heap_cur_idx--];
	for(int idx = 1; idx <= heap_cur_idx; idx *= 2){
		//루트에서부터 가장 밑으로 내려가면서 절대값이 작은 값을 위로 보내되 밑으로 내려갈 경로를 잘 선택해야함.
		//idx번째의 자식이 없다.
		if(2*idx > heap_cur_idx) return return_val;
		//idx번째의 왼쪽 자식만 존재한다.
		if(2*idx+1 > heap_cur_idx){
			if(abs(min_heap[idx]) > abs(min_heap[idx*2])) heap_swap(idx, idx*2);
			else if(abs(min_heap[idx]) == abs(min_heap[idx*2])) 
					if(min_heap[idx] > min_heap[idx*2]) 
						heap_swap(idx, idx*2);
			idx *= 2;		
		}
		//idx번째의 오른쪽 자식도 존재하지만 왼쪽 자식이 더 작다.
		else if(abs(min_heap[idx*2]) < abs(min_heap[idx*2+1]) || ((abs(min_heap[idx*2]) == abs(min_heap[idx*2+1]) && (min_heap[idx*2] < min_heap[idx*2+1])))){
			if(abs(min_heap[idx]) > abs(min_heap[idx*2])) 
					heap_swap(idx, idx*2);
			else if(abs(min_heap[idx]) == abs(min_heap[idx*2])) 
					if(min_heap[idx] > min_heap[idx*2]) 
						heap_swap(idx, idx*2);
			idx *= 2;	
		}
		//idx번째의 오른쪽 자식이 더 작다.
		else{
			if(abs(min_heap[idx]) > abs(min_heap[idx*2+1])) 
					heap_swap(idx, idx*2+1);
			else if(abs(min_heap[idx]) == abs(min_heap[idx*2+1])) 
					if(min_heap[idx] > min_heap[idx*2+1]) 
						heap_swap(idx, idx*2+1);
			idx *= 2;
		}
	}
	return return_val;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	while(N--){
		int x;
		cin >> x;
		if(x) insert_heap(x);
		else res.push_back(deletion_heap());
	}
	for(auto x : res) cout << x << "\n";
}
***************************************************************************************/

struct comp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

void Solution(int n)
{
	priority_queue< int, vector<int>, comp > pq;

	while (n--)
	{
		int Command; cin >> Command;

		if (Command == 0)
		{
			if (pq.empty())
			{
				cout << '0' << '\n';
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(Command);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	Solution(n);

	return 0;
}