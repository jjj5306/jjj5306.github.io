/** Dynamic Programming RGB거리 **/
//다시 풀어보기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* house[3];
	for (int i = 0; i < 3; i++) house[i] = new int[N+1];
	//0열은 사용하지 않는다. 
	//house[0][i]은 i번째 집을 빨간색으로 칠할 때 최소비용이다. 행은 순서대로 RGB이다.
	house[0][0] = 0;
	house[1][0] = 0;
	house[2][0] = 0;

	int cost[3];

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		//i번째 집이 빨간색으로 색칠되려면 전 집이 빨간색이 아니어야한다. 
		//따라서 house[1][i-1]과 house[2][i-1] 중 최솟값과 cost[0]을 더하면 된다.
		house[0][i] = min(house[1][i - 1], house[2][i - 1]) + cost[0];
		house[1][i] = min(house[0][i - 1], house[2][i - 1]) + cost[1];
		house[2][i] = min(house[1][i - 1], house[0][i - 1]) + cost[2];
	}

	cout << min(house[0][N], min(house[1][N], house[2][N]));


}