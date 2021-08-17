/** 매개 변수 탐색 랜선 자르기 **/
//다시 풀기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

ll getans(vector <ll> LAN, ll length) {
	ll count = 0;
	for (int i = 0; i < LAN.size(); i++) count += (LAN[i]/length);
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//길이가 다른 K개의 랜선을 N개의 길이가 같은 랜선으로 만들어야 한다. 이미 자른 랜선은 붙일 수 없다.
	//N개보다 많이 만들어도 된다.
	//N개 이상을 만들 수 있는 최대 길이를 찾자.

	ll K, N;
	cin >> K>> N;
	vector <ll> LAN(K);
	for (ll i = 0; i < K; i++) cin >> LAN[i];
	sort(LAN.begin(), LAN.end());

	ll left = 1;
	ll right = LAN.back();
	//랜선 길이의 범위를 1부터 가장 긴 길이로 우선 정한다.
	//각 길이별로 만들 수 있는 랜선의 개수를 구하고 그 개수가 N보다 작다면 랜선의 최소 범위를 늘리고
	//크다면 


	while (left != right) {
		//랜선 길이의 범위가 한 칸이 되면 그 때 left가 x이다.
		//적당한 랜선 길이를 랜선 길이 범위의 중간으로 정해서 체크한다.
		long long mid = (left + right + 1) / 2;
		ll res = getans(LAN, mid);
		//mid 길이로 랜선을 N개 이상 만들었다면 mid 길이도 답이 될 수 있고 이보다 길게도 될 수 있으므로
		//랜선 길이 범위를 mid와 같거나 크게 변형한다.
		if (res >= N) {
			left = mid;
		}
		// N개 이상 만들지 못했다면 랜선 길이를 더 줄여야 하므로 랜선 길이 범위를 mid보다 작게 변경한다.
		else {
			right = mid - 1;
		}
	}
	cout << left;

}
