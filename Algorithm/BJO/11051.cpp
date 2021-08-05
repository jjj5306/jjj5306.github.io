#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int modpow(int x, int y) {
	int p = x;
	int ret = 1;
	while (y) {
		if (y % 2) ret = (ret * p) % 10007;
		p = p * p % 10007;
		y /= 2;
	}
	return ret;
}


int modmul(int x, int y)
{
	return (x * y) % 10007;
}

int main() {
	// (N!/(K!)(N-K)!) % 10007 을 구하자
	vector <int> factorial(1001, 1);
	for (int i = 1; i < 1001; i++) factorial[i] = modmul(factorial[i - 1], i);
	int N, K;
	cin >> N >> K;
	int result = factorial[N];
	result = modmul(modpow(factorial[K], 10005), result);
	result = modmul(modpow(factorial[N-K], 10005), result);
	cout << result;
}