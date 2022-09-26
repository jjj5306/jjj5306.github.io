/** DP LCS **/
//다시 풀기, 풀이를 떠올리기 상당히 어려웠다. 재귀 호출로 푸는 편이 훨씬 쉽다.
//https://hini7.tistory.com/68 참고해서 품
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string s1, s2;
int cache[1001][1001];
//뒤에서부터 구하는 방식으로 for문으로 풀 수 있을것같은데 떠올리기 힘들다.

int LCS(int p1, int p2) {
	//캐시를 사용하지 않고도 구현할 수 있지만 시간을 줄이기 위해 메모이제이션을 사용한다.
	//이미 구한 캐시의 경우 그 값을 리턴
	if (cache[p1][p2] != -1)
		return cache[p1][p2];

	//각 포인터가 string보다 큰 곳을 가리키는 경우 종료
	if (p1 >= s1.length() || p2 >= s2.length())
		return 0;

	//각 포인터가 string의 끝을 가리키는 경우 그 끝 문자가 같던 다르던 0을 리턴하기에 따로 체크해준다.
	if (p1 == s1.length() - 1 && p2 == s2.length() - 1) {
		cache[p1][p2] = (s1[p1] == s2[p2]);
		return cache[p1][p2];
	}

	int max_res;
	//현재 포인터가 가리키는 문자의 값이 같다면 포인터를 각 1씩 증가시킨 string으로 구한 LCS + 1이다.
	if (s1[p1] == s2[p2])
		max_res = LCS(p1 + 1, p2 + 1) + 1;

	//현재 포인터가 가리키는 문자의 값이 다르다면 s1의 포인터를 1씩 증가시켜 LCS를 구하거나
	//s2의 포인터를 1씩 증가시켜 LCS의 구한 것 중 최대값이다.
	else
		max_res = max(LCS(p1 + 1, p2), LCS(p1, p2 + 1));
	cache[p1][p2] = max_res;
	return max_res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1 >> s2;
	//현재 포인터가 가리키고 있는 변수의 값이 다르다면 
	//s1의 포인터를 1 증가 혹은 s2의 포인터를 1 증가시켜서 비교할 수 있다.
	
	//현재 포인터가 가리키고 있는 변수의 값이 같다면
	//s1, s2의 포인터를 각각 1씩 증가시킨 LCS길이 + 1과 같다.

	fill(&cache[0][0], &cache[1000][1001], -1);

	cout << LCS(0, 0);
	
}