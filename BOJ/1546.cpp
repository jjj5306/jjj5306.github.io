/** 구현 두 수 비교하기 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int number, max;
	cin >> number;

	vector <float> res(number);
	for (int i = 0; i < res.size(); i++) cin >> res[i];
	vector <float> temp(res);

	sort(temp.begin(), temp.end());
	reverse(temp.begin(), temp.end());

	for (int i = 0; i < res.size(); i++) 
		if (res[i] == temp[0]) {
			max = i;
			break;
		}
	max = res[max];
	for (int i = 0; i < res.size(); i++) res[i] = res[i] / max * 100;
	float result = 0;
	for (int i = 0; i < res.size(); i++) result += res[i];
	cout << result / number;
}