/** 매개 변수 탐색 공유기 설치 **/
//다시 풀기
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//집 N개가 수직선 위에 있고 집에 공유기 C개를 설치하려 한다.
	//인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려 한다.
	//가장 가까운 두 공유기 사이의 최대 거리를 출력한다.

	int N, C;
	cin >> N >> C;
	vector<int> wifi(N); 
	for (auto& i : wifi) cin >> i;
	sort(wifi.begin(), wifi.end());
	
	//간격의 범위를 1부터 최대로 설정한 뒤 그 간격으로 설치 가능한 공유기 수를 구한다.
	int left = 1, right = wifi.back() - wifi.front();
	while (left != right) {
		//가능한 간격의 범위가 1이되면 그때의 간격이 답이다.
		int mid = (left + right + 1) / 2;
		//범위의 중간을 mid로 설정하고 이를 통해 비교한다.

		int count = 1; // 첫 번째 집에 설치하고 설치된 공유기 수를 count라한다.
		int last_pos = wifi[0];
		for (int i = 0; i < N; i++) {
			//i번째 집과 그 전에 공유기를 설치한 집의 간격이 간격의 범위의 중간 값보다 크거나 같으면
			//i번째 집에 공유기를 설치한다.
			if (wifi[i] - last_pos >= mid) {
				count++;
				last_pos = wifi[i];
			}
		}

		//설치된 공유기의 수가 C와 같으면 그 간격이 답일 수 있고 혹은 간격을 더 키워도 답일 수 있다.

		//만약 지금 설치된 공유기의 수가 C와 같고 간격 또한 지금이 최대지만 간격의 범위가 1이 아니라도
		//반복문을 더 돌면서 범위를 조정하면서 판단할 것이다. 최종 답은 결국 간격의 범위가 1일때 나타난다.

		//설치된 공유기 수가 C보다 큰 경우에도 간격이 더 큰 범위에 답이 존재 할 것이다.
		//따라서 설치된 공유기 수가 C와 같거나 큰 경우 간격의 범위의 시작점을 더 늘린다.
			if (count >= C) left = mid;
			//설치된 공유기 수가 C보다 작은 경우는 간격을 더 줄여야한다.
			else right = mid - 1;
		}
        
	cout << left;

}