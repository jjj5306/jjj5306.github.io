/**  정수론 완전수 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int judge(int num) {
	if (num == 1) return -1;
	int result = 1;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
		{
			result = result + (num / i);
			if (i * i != num) result = result + i;
		}
	}
	if (result < num) return -1; //부족수
	else if (result == num) return 0;
	else return 1; //과잉수
}

int main() {
	int T, result;
	cin >> T;
	vector <int> number (T);
	for (int i = 0; i < T; i++) cin >> number[i];
	for (int i = 0; i < number.size(); i++) {
		result = judge(number[i]);
		if (result == -1) cout << "Deficient\n";
		else if (result == 0) cout << "Perfect\n";
		else cout << "Abundant\n";
	}
}