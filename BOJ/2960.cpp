/** 정수론 에라토스테네스의 체 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	vector <int> order(N+1, 0);
	int num = 1;
	for (int i = 2; i < order.size(); i++) {
		if (order[i] == 0) {
			for (int j = i; j < order.size(); j += i) {
				if (order[j] == 0) {
					if (num == K) {
						cout << j;
						return 0;
					}
					order[j] = num++;
				}
			}
		}
	}

}
