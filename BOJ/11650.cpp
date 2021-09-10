/** 정렬 수 좌표 정렬하기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct coordinate {
	int x, y;
};

bool operator<(coordinate a, coordinate b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//x가 증가하는 순으로, x가 같으면 y가 증가하는 순으로

	vector <coordinate> res(N);
	for (int i = 0; i < N; i++) cin >> res[i].x >> res[i].y;

	sort(res.begin(), res.end());

	for (int j = 0; j < res.size(); j++) cout << res[j].x << " " << res[j].y << "\n";

}