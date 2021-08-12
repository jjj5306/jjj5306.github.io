#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

int sum(vector <int> num) {
	int res = 0;
	for (int i = 0; i < num.size(); i++) res += num[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//n개의 비디오, k개의 포스트 모든 포스트의 비디오 길이는 같아야한다. 순서대로 들어가야한다
	int n, k;
	cin >> n >> k;
	vector <int> video(n);

	for (int i = 0; i < video.size(); i++) cin >> video[i];
	//n개의 원소를 k개의 set으로 나누고 각 set에서 원소의 합은 같아야 한다.
	vector <int> res(k, 0);
	vector <int> result(k, 0);

	if (k == 1) cout << "YES" << "\n" << n;
	else if (sum(video) % k != 0) {
		cout << "NO";
		return 0;
	}
	else {
		int temp = sum(video) / k;
		//각 집합의 원소의 합이 temp가 되게 설계하면됨
		int i = 0, start=0;
		while (i < k) {
			if (res[i] == temp) break;
			for (; start < n; start++) {
				if (res[i] == temp) {
					i++;
					break;
				}
				res[i] += video[start];
				result[i]++;
				if (res[i] > temp) {
					cout << "NO";
					return 0;
				}
			}
			
		}
		cout << "YES" << "\n";
		for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
	}
}