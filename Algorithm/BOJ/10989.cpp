/** 정렬 수 정렬하기 3 **/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	/* 아래의 set를 사용한 풀이는 천만개의 숫자를 입력받아 모두 저장하는 과정에서 메모리 초과가 뜬다.
	multiset <long long> num;
	for (long long i = 0; i < N;i++) {
		int temp;
		cin >> temp;
		num.insert(temp);
	}
	
	for (auto i = num.begin(); i != num.end(); i++)
		cout << *i << "\n";
	*/

	vector <int> num(10001, 0);
	for (long long i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		num[temp]++;
	}

	for (long long i = 0;i<num.size();i++) {
		for (long long j = 0; j < num[i]; j++)
			cout << i << "\n";
	}

}