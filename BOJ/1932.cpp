/** DP 정수 삼각형  **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//triangle[i][j]는 i-1층의 j-1번째 칸이다.
long long triangle[501][501];
long long res[501][501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//0층부터 시작해서 N층에는 N+1개의 원소가 있다.
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];
	
	//triangle[i][j]는 triangle[i+1][j]와 triangle[i+1][j+1]로 접근할 수 있다.
	//res[i][j]는 triangle[i][j]까지 도달할 수 있는 최대 정수 합을 의미한다.
	res[0][0] = triangle[0][0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) res[i][j] = res[i - 1][j] + triangle[i][j];
			else if (j == i) res[i][j] = res[i - 1][j-1] + triangle[i][j];
			else res[i][j] = max(res[i - 1][j - 1], res[i - 1][j]) + triangle[i][j];
		}
	}
	
	//res의 N-1행의 열들 중 최대 값이 답이다.
	int max = 0;
	for (int i = 1; i < N; i++)
		if (res[N - 1][max] < res[N - 1][i]) max = i;
	cout << res[N - 1][max];

}
