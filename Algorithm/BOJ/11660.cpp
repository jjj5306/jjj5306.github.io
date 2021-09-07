/** DP 구간 합 구하기 5 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector <vector <int>> table(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> table[i][j];

	//sum[i][j] = table에서 i행 0열부터 j열까지의 합이다.
	vector <vector <int>> sum(N, vector<int>(N));
	sum[0][0] = table[0][0];

	//먼저 0열부터 채우자.
	for (int i = 1; i < N; i++)
		sum[i][0] = table[i][0];

	for (int i = 0; i < N; i++)
		for (int j = 1; j < N; j++)
			sum[i][j] = sum[i][j-1] + table[i][j];
	
	vector <int> res;
	
	while (M--) {
		int x1, y1, x2, y2, result=0;
		cin >> x1 >> y1 >> x2 >> y2;
		//0행0열부터 시작하므로 모두 1씩 빼준다. 이제 table[x1][y1]에서 table[x2][y2]까지 합을 구하면 된다.
		x1--;
		y1--;
		x2--;
		y2--;

		//x1행에서 y1열부터 y2열까지 합을 구한다. x1행이 x2행이 될 때 까지 더한다.
		while (x1 <= x2) {
			if (y1 == 0) result += sum[x1][y2];
			else result += sum[x1][y2] - sum[x1][y1 - 1];
			x1++;
		}
		res.push_back(result);
	}

	for (auto r : res) cout << r << "\n";

}
