/** 브루트포스 알고리즘 마인크래프트 **/
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//N * M 집터, 가장 왼쪽 위의 좌표는 (0, 0)
	//1 : (i, j)의 가장 위의 블록을 제거하여 인벤토리에 넣는다. 2초 소모
	//2 : 인벤토리의 블록을 꺼내 (i, j)에 넣는다. 1초 소모
	//최소 시간과 그 경우 땅 높이 출력
	//처음에는 인벤토리에 B개의 블록이 있다. 
	//땅 높이는 256 초과 불가 음수 불가
	//전체 높이를 0~256으로 만들 때 까지의 time을 측정하자.

	int N, M, B;
	cin >> N >> M >> B;

	vector <vector <int>> v(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> v[i][j];

	int time = -1, height = 0, res=-1;
	
	int B_temp = B;

	while (height <= 256) {
		//인벤토리 초기화
		B = B_temp;

		int flag = 0, time_temp=0;
		for (int i = 0;  i < N; i++)
			for (int j = 0;  j < M; j++) {
				 if (v[i][j] < height) {
					 //블럭을 쌓는 경우
					B -= (height - v[i][j]);
					time_temp += (height - v[i][j]);
				}
				else if (v[i][j] > height){
					 //블럭을 제거하는 경우
					B += (v[i][j] - height);
					time_temp += 2*((v[i][j] - height));
				}
			}
		//인벤터리에 블럭에 음수 개인 경우 즉 다 쌓지 못해서 해당 height는 만들 수 없는 경우는 그냥 패스
		if (B < 0) {
			height++;
			continue;
		}
		//해당 height가 기존 가장 빨랐던 시간보다 빠른 경우
		if (time < 0 || time > time_temp) {
			time = time_temp;
			res = height;
		}
		//해당 height가 기존 시간과 같은 경우 더 높은 height로 저장
		else if (time == time_temp) {
			if (res < height) {
				time = time_temp;
				res = height;
			}
		}
		height++;
	}
	cout << time << " " << res;
}
