/** 매개 변수 탐색 휴게소 세우기 **/
#include<iostream>
#include<vector>
#include <queue>
#include<algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, L;
	cin >> N >> M >> L;
	
	vector <int> rest(N);
	for (auto& i : rest) cin >> i;
	sort(rest.begin(), rest.end());
	//M개를 더 지어서 휴게소가 없는 구간의 길이의 최댓값을 최소로 하자.

	//휴게소가 없는 구간의 간격을 0 ~ rest.back()-rest.front()로 정하자.
	//그 간격에 대해 지을 수 있는 휴게소의 개수를 구해가면서 범위를 줄여나가면 된다.
	//이 때 휴게소간의 간격이 다른 경우는 생각하지 않아도 된다. 
	//어차피 구간의 길이의 최댓값을 최소로 하려면 구간의 길이를 같게 정해야한다.

	int left = 1, right = L;

	while (left < right) {
		int mid = (left + right ) / 2;
		
		int count = 0; //현재까지 설치한 휴게소의 수이다.

		//먼저 0번째 휴게소와 거리0 사이의 휴게소도 체크해보자.
		if(rest[0] % mid == 0) count += rest[0] / mid - 1;
		else count += rest[0] / mid;

		//i번째와 i-1번째 휴게소 사이의 거리에 몇 개의 휴게소를 설치할 수 있는지 구해보자.
		for (int i = 1; i < rest.size(); i++) {
			if ((rest[i] - rest[i - 1]) % mid == 0) count += (rest[i] - rest[i - 1]) / mid - 1;
			else count += (rest[i] - rest[i - 1]) / mid;
		}

		//마지막 휴게소와 고속도로의 끝 사이의 휴게소도 체크해야한다.
		if ((L - rest.back()) % mid == 0) count += (((L - rest.back()) / mid)-1);
		else  count += (L - rest.back()) / mid ;
		
		//설치한 휴게소의 수가 M이하라면 간격을 줄여야할 수 있다.
		if (count <= M) right = mid;
		//설치한 휴게소의 수가 M보다 크다면 간격을 늘려야 한다.
		else left = mid + 1;

	}
	cout << left;


}