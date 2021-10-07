/** 구현 달팽이는 올라가고 싶다 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//높이가 V미터인 나무 막대를 올라가고 낮에는 A미터 올라가고 밤에는 B미터 떨어진다.
	int A, B, V;
	cin >> A >> B >> V;

	int res;
	if (V <= A) res = 1;
	//V-A보다 같거나 크게까지 도착한다음 +1만하면된다 V-A / A-B의 올림이 필요
	else if ((V - A) % (A - B) == 0) res = (V - A) / (A - B) + 1;
	else res = (V - A) / (A - B) + 2;
	cout << res;
	
}