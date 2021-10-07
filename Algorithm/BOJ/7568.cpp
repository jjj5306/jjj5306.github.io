/** 브루트포스 알고리즘 덩치  **/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct person {
	int weight, height, grade=1;
};


int main() {

		int N, max = 0;
		cin >> N;
		vector <person> people(N);
		for (int i = 0; i < N; i++)
			cin >> people[i].weight >> people[i].height;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (people[i].height < people[j].height && people[i].weight < people[j].weight) people[i].grade++;
		for (int i = 0; i < N; i++)
		{
			cout << people[i].grade << " ";
		}
	}