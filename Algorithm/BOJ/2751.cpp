/** 정렬 수 정렬하기 2 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> numbers(N);
	for(int i=0;i<N;i++) cin >> numbers[i];

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < N; i++) cout << numbers[i] << "\n";

}