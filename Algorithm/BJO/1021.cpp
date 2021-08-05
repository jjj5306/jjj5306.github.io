#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

void go_left(vector <int> &queue, int* count) {
	for (int i = 0; i < queue.size(); i++)
		queue[i] = (queue[i] + 1) % queue.size();
	(*count)++;
}

void go_right(vector <int> &queue, int* count) {
	for (int i = 0; i < queue.size(); i++)
		if ((--queue[i]) == 0) queue[i] = queue.size();
	(*count)++;
}

int main() {

	int N, M, count = 0;
	cin >> N >> M;
	vector <int> queue(N);
	vector <int> pop(M);
	
	for (int i = 0; i < M; i++)
		cin >> pop[i];
	
	for (int i = 0; i < N; i++)
		queue[i] = i+1;

	for (int i = 0; i < pop.size(); i++)
	{
		if (abs(pop[i] - 1) < abs((int)(queue.size() - pop[i] + 1))) {
			while (queue[0] != pop[i]) go_left(queue, &count);
		}
		else {
			while (queue[0] != pop[i]) go_right(queue, &count);
		}

		for (int j = i+1; j < pop.size(); j++)
		{
			for (int m = 0; m < queue.size(); m++)
			{
				if (pop[j] == queue[m]) 
				{
					pop[j] = m;
					m = queue.size();
				}
			}
		}
		
		queue.erase(queue.begin());

		for (int m = 0; m < queue.size(); m++)
			queue[m] = m + 1;
	}

	cout << count;
}