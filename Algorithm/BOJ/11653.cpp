/** 정수론 소인수분해 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector <int> res;
	if (N == 1) return 0;

	for (int i = 2; i <= N; i++)
	{
		if (N % i == 0) {
			res.push_back(i);
			N = N / i;
			i=1;
		}
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) cout << res[i]<<"\n";
	return 0;
}