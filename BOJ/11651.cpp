/** 정렬 좌표 정렬하기2 **/
//구조체 연산자 재정의 연습하기 좋음
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class coo {
public:
	int x, y;
	bool operator<(const coo a) const{
		if (y == a.y) return x < a.x;
		else return y < a.y;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	multiset <coo> coos;
	for (int i = 0; i < N; i++) {
		coo temp;
		cin >> temp.x >> temp.y;
		coos.insert(temp);
	}

	for (auto i = coos.begin(); i != coos.end(); i++)
		cout << i->x <<" " <<i->y<<"\n";


}