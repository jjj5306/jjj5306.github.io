/** 삼분 탐색 전봇대 **/
//다시 풀기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

ll getans(vector <ll> pole, ll a) {
	ll count = 0;
	for (int i = 1; i < pole.size(); i++) {
		/*기존의 코드는 아래의 것인데, 더 깔끔한 방법을 찾았다.
		if (pole[i] - pole[i - 1] == a) continue;
		else {
			count += abs(pole[i] - (pole[i - 1] + a));
			pole[i] = pole[i - 1] + a;
		}
		*/
		count += abs(a * i - pole[i]);
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//이웃한 두 전봇대 사이 거리가 일정하도록 옮긴다.
	//이동해야하는 전봇대들의 거리의 합이 최소가 되야한다.
	//이웃한 두 전봇대 사이의 거리가 답일 때 전봇대들의 거리의 합이 최소가 된다.
	//이웃한 두 전봇대 사이의 거리가 답보다 크거나 작으면 전봇대들의 거리의 합이 최소보다 항상 크다.

	ll N;
	cin >> N;
	vector <ll> pole(N);
	for (auto& i : pole) cin >> i;
	sort(pole.begin(), pole.end());

	//이웃한 두 전봇대 사이의 거리를 범위로 정하자.
	//right의 범위를 더 좋은 방식으로 조절할 수 있을 것 같다.
	ll left = 0, right = pole.back()+1;
	ll a, b;

	while (left < right) {
		a = (left + left + right) / 3;
		b = (left + right + right) / 3;
		ll res_a = getans(pole, a);
		ll res_b = getans(pole, b);

		//cout << left << " " << right << " " << a << " " << b << " " << res_a << " " << res_b << endl;

		//res_a <= res_b인 경우 극소점은 b보다 왼쪽에 존재한다.
		if (res_a <=  res_b) right = b;
		//res_a > res_b인 경우 극소점은 a보다 오른쪽에 존재한다.
		else  left = a+1;
	}
	cout << getans(pole, left);
}
