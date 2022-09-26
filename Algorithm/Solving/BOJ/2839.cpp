/** 구현 설탕 배달 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//정확하게 N킬로그램 배달
	//봉지는 3킬로그램과 5킬로그램짜리가 있다.
	//최대한 적은 봉지로 N킬로그램을 만들자. 만들 수 없다면 -1 출력

	int N;
	cin >> N;
	int res = 0;
	int count_5, count_3;
	//5의 배수로 가장 가까이 접근한다.
	count_5 = N / 5;
	if ((N % 5) % 3 == 0) cout << count_5 + (N % 5) / 3;
	else {
		for (int i = count_5 - 1; i >= 0; i--) 
			if ((N - 5 * i) % 3 == 0) {
				cout << i + (N - 5 * i) / 3;
				return 0;
			}
		cout << -1;
	}
	


}