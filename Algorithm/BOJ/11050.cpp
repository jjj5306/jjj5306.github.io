/** 구현 이항 계수 1 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

inline int factorial(int num) {
	int res=1;
	for (int i = 2; i <= num; i++) res *= i;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	cout << factorial(N) / (factorial(K) * factorial(N - K));
}