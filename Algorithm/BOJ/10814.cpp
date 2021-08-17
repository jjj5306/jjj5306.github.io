/** 정렬 수 나이순 정렬 **/
// 구조체 정렬 연습하기 좋음
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct cus {
	int age , order;
	string name;
};

bool operator<(cus a, cus b) {
	if (a.age == b.age) return a.order < b.order;
	return a.age < b.age;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 순으로 정렬

	vector <cus> customer(N);
	for (int i = 0; i < N; i++) {
		cin >> customer[i].age >> customer[i].name;
		customer[i].order = i;
	}

	sort(customer.begin(), customer.end());

	for (int j = 0; j < customer.size(); j++) cout << customer[j].age << " " << customer[j].name << "\n";

}