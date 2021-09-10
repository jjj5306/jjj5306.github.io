/** 정수론 수 복원하기 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct number {
	int num, count;
};

void find(vector <number>& res, int number) {
	for (int i = 0; i < res.size(); i++) 
		if (res[i].num == number) {
			res[i].count++;
			return;
		}
	res.push_back({ number, 1 });
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int temp;
		cin >> temp;
		vector <number> res;
		int i = 2;
		while (i <= temp) {
			if (temp % i == 0) {
				find(res, i);
				temp = temp / i;
			}
			else i++;
		}
		
		for (int i = 0; i < res.size(); i++) cout << res[i].num << " " << res[i].count << "\n";
	}
}