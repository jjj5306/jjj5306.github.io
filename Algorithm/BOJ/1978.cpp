/** 정수론  소수 찾기 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;


int main() {
	int T, result=0, tag=0;
	cin >> T;
	vector <int> number(T);
	for (int i = 0; i < T; i++) cin >> number[i];
	for (int i = 0; i < number.size(); i++) {
		tag = 0;
		if (number[i] == 1) continue;
		for (int n = 2; n * n <= number[i]; n++) {
			if (number[i] % n == 0) {
				tag = 1;
				break;
			}
		}
		if(!tag) result++;
	}
	cout << result;
}