/** 구현 Hashing **/
//모들러 연산 연습하기 좋음 L이 클때
//다시풀기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//a부터 1 할당
	//수열의 각 항마다 고유한 계수를 부여한다,
	//항 번호에 해당하는 만큼 특정한 숫자를 거듭제곱해서 곱해준 다음 더한다 M으로 모들러얀산한다

	int L;
	const int r = 31, M = 1234567891;
	cin >> L;
	string str;
	cin >> str;

	long long result = 0;
	long long weight = 1; //자리의 무게수만큼 r을 곱함

	for (int i = 0; i < str.length(); i++) {
		//result의 마지막에 mod는 각 더하는 요소들을 mod한 것과 같다.
		result = (result + (str[i] - 'a' + 1) * weight) % M;
		//result를 계산할 때 weight만큼 곱하고 mod하는 것은 미리 곱할 weight에 mod하는 것과 같다.
		weight = (r * weight)%M;

	}
	cout << result;

}