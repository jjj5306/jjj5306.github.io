/** 정수론 GCD(n, k) = 1 **/
//정수론 종합적으로 연습하기 좋음. 다시 풀기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

/**************************************************************************************************
void serve(int n, vector<ll>& res) {
	for (ll i= 2; i <= n; i++) {
		if (res[i] != 0) continue;
		for (ll j = i; j <= n; j += i) res[j] = i;
	}
}

void prime_f(ll num, vector<ll>& res, vector<ll> S) {
	while (S[num] != num)
	{
		res.push_back(S[num]);
		num /= S[num];
	}
	res.push_back(S[num]);

}
***************************************************************************************************/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//자연수 n에 대해 GCD(n, k) = 1을 만족하는 자연수 1 ≤ k ≤ n 의 개수를 출력한다.
	ll n;
	cin >> n;

	//GCD(n, k) = 1이라는 뜻은 n, k는 서로소라는 뜻 즉 n의 서로소의 개수를 구하면 된다.
	//오일러 파이 함수를 이용하면 1부터 n까지 서로소의 개수를 알 수 있다.

	if (n == 1) cout << 1;
	else {
		/**************************************************************************************************
		//에라토스테네스의 체를 n까지 생성한다.
		//S[i]에는  소인수가 들어가고 S[i] = [i]이면 소수이다.
		vector<ll> S(n + 1, 0);
		serve(n, S);

		ll result = n;
		//먼저 n을 소인수분해해서 소수의 곱으로 나타내자. 소인수분해는 에라토스테네스의 체를 이용한다.
		vector <ll> prime;
		prime_f(n, prime, S);
		***************************************************************************************************/

		//에라토스테네스의 체를 사용하여 소인수분해를 하면 오버플로우가 뜬다. 
		//따라서 O(log n)짜리 그냥 소인수분해를 사용한다.

		vector <ll> prime;
		ll temp = n;
		for (ll i = 2; i * i <= temp; i++) {
			while (temp % i == 0) {
				temp /= i;
				prime.push_back(i);
			}
		}
		if (temp > 1) prime.push_back(temp);

		//소인수분해 한 결과에 대해서 오일러 파이 함수를 적용시킨다.
		ll result = n;
		sort(prime.begin(), prime.end());
		result *= (1.0 - 1.0 / (double)prime[0]);
		for (ll i = 1; i < prime.size();i++) {
			if (prime[i] != prime[i - 1]) result *= (1.0 - 1.0 / (double)prime[i]);
		}
		cout << result ;
	}

}