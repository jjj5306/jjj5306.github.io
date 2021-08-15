/** 정수론 최대공약수와 최소공배수 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int A, B, max, min;
	cin >> A >> B;

	//최대 공약수
	int i = 1;
	while (i <= A && i <= B) {
		if (A % i == 0 && B % i == 0) min = i;
		i++;
	}


	//최소 공배수
	int tempA = A, tempB = B;
	while (tempA != tempB) {
		if (tempA > tempB) tempB += B;
		else if (tempA < tempB)tempA += A;
		else break;
	}
	max = tempA;

	cout<<min<<"\n"<< max;


}