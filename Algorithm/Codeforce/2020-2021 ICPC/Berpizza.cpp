#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1 요청이 들어오면 value를 측정한다
2 요청이 들어오면 order순서에 따라 출력하고 tag를 1로바꾼다
3 요청이 들어오면 value순서에 따라 출력하고 tag를 1로바꾼다
*/
typedef struct customer{
	int order, value, tag=1;
};

inline int query2(vector <customer> cus) {
	int min;
	for (int i = 1; i < cus.size(); i++) 
		if (cus[i].tag == 0) {
			min = i;
			break;
	}
	for (int i = min+1; i < cus.size(); i++) 
		if (cus[i].tag == 0 && (cus[i].order < cus[min].order)) min = i;
	return min;
}

inline int query3(vector <customer> cus) {
	int max;
	for (int i = 1; i < cus.size(); i++)
		if (cus[i].tag == 0) {
			max = i;
			break;
		}
	for (int i = max + 1; i < cus.size(); i++)
		if (cus[i].tag == 0 && (cus[i].value > cus[max].value)) max = i;
	return max;
}


int main() {
	ios::sync_with_stdio(false);
	int q, i;
	cin >> q;
	vector <customer> cus ;
	cus.push_back(customer{ -1, -1, -1 });
	vector <int> result;
	int count = 1;

	while (q--) {
		cin >> i;
		if (i == 1) {
			int value;
			cin >> value;
			cus.push_back(customer{count, value, 0});
			count++;
		}
		else if (i == 2) {
			int tmp;
			tmp = query2(cus);
			result.push_back(cus[tmp].order);
			cus[tmp].tag = 1;
		}
		else{
			int tmp;
			tmp = query3(cus);
			result.push_back(cus[tmp].order);
			cus[tmp].tag = 1;
		}
	}
	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
}
