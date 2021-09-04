/** DP 신나는 함수 실행  **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int a, b, c;
//3차원 배열을 사용하였다. 구조체 벡터를 이용하여 할 수 있을 것 같은데 쉽게 떠오르지 않는 점이 아쉽다.
int cache[21][21][21];

int w(int a, int b, int c) {
	if ((a <= 0 || b <= 0) || c <= 0) return 1;

	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

	//w(a, b, c)의 결과가 이미 캐시에 있다면 
	if (cache[a][b][c]) return cache[a][b][c];

	if ((a < b) && b < c) {
		cache[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return cache[a][b][c];
	}
	else {
		cache[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		return cache[a][b][c];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	while(1) {
		cin >> a >> b >> c;
		if ((a == -1 && b == -1) && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = "<<w(a, b, c) << "\n";
	}
}
