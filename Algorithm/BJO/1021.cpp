/**  자료구조 회전하는 큐 **/

#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdlib>
using namespace std;

void go_left(deque <int> &queue, int &count) {
	queue.push_back(queue.front());
	queue.pop_front();
	++count;
}

void go_right(deque <int>& queue, int& count) {
	queue.push_front(queue.back());
	queue.pop_back();
	 ++count;
}

int find_index(deque <int>& queue, int& num) {
	for (int i = 0; i < queue.size(); i++) if (num == queue[i]) return i;
}


int main() {

	int N, M, count = 0;
	cin >> N >> M;
	deque <int> queue(N);
	deque <int> pop(M);
	
	for (int i = 0; i < M; i++)
		cin >> pop[i];
	
	for (int i = 0; i < N; i++)
		queue[i] = i+1;

	for (int i = 0; i < pop.size(); i++)
	{
		if(find_index(queue, pop[i]) < queue.size()- find_index(queue, pop[i])+1){
			while (queue[0] != pop[i]) go_left(queue, count);
		}
		else {
			while (queue[0] != pop[i]) go_right(queue, count);
		}
		queue.erase(queue.begin());
	}
	cout << count;
}