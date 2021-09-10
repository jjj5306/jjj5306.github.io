/** 매개 변수 탐색 나무 자르기 **/
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> N >> M;
	
	vector <long long> tree(N);
	for (long long& i : tree) cin >> i;

	//가능한 나무 높이를 초기 범위 1~max로 설정한다.
	sort(tree.begin(), tree.end());


	long long left = 0, right = tree.back();
	while (left != right) {
		long long mid = (left + right + 1) / 2, height=0;
		//나무 높이를 mid로 하여 잘랐을 때 얻을 수 있는 높이를 구하자.
		for (long long i : tree) {
			if (i - mid > 0) height += i - mid;
		}
		//cout << left<<" " << right<<" " << mid<<" " << height << endl;
		//만약 height가 M보다 작다면 자르는 길이를 더 줄여야한다
		if (height < M) right = mid - 1;
		//height가 M이랑 같거나 크다면 자르는 길이를 더 늘려야한다
		else left = mid ;
	}
	cout << left;
}
