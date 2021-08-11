/** 구현  방 번호 **/
//다시 풀기 6과 9가 섞여있을 때 언제 최대인지 판단하는 알고리즘을 생각해내기 힘들다 
// 6의 개수 + 9의 개수를 2로 나눈 결과의 반올림을 사용하는 알고리즘은 다른 사람의 코드를 보고 알았다
// 그 알고리즘을 보고 나서도 짠 코드가 너무 더럽다
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

inline vector<int> serve(int N) {
	vector <int> number;
	int temp = N;

	number.push_back(temp / 100000);
	temp = N % 100000;
	number.push_back(temp / 10000);
	temp = N % 10000;
	number.push_back(temp / 1000);
	temp = N % 1000;
	number.push_back(temp / 100);
	temp = N % 100;
	number.push_back(temp / 10);
	temp = N % 10;
	number.push_back(temp);
	
	return number;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	if (N == 1000000) {
		cout << 6;
		return 0;
	}
	
	if (N) {
		//방 번호 N에 대해서 각 자릿수별로 분리해서 벡터에 넣는다.
		vector <int> number = serve(N);
		vector <int> count(10, 0);

		//몇 자릿수인지 저장한다
		int digit;
		//수에서 6의 개수와 9의 개수를 저장한다
		int count_6=0, count_9=0;

		for (int i = 0; i < number.size(); i++) {
			if (number[i] != 0) {
				digit = 6 - i;
				break;
			}
		}
		reverse(number.begin(), number.end()); 
		// number[i]는 i < digit인 경우 유효한 수이다.

		//유효한 수 중 6, 9를 제외한 제일 많이 나타나는 수의 개수와 
		//6의 개수와 9의 개수를 더한 것을 반으로 나눈 것의 올림 중 최댓값이 답이다
		for (int i = 0; i < digit; i++)
		{
			if (number[i] == 6) count_6++;
			if (number[i] == 9) count_9++;
			count[number[i]]++;
		}
		count[6] = 0;
		count[9] = 0;
		sort(count.begin(), count.end());
		reverse(count.begin(), count.end());

		int res = count[0];
		if (res < (int)(ceil((count_6 + count_9) / 2.0))) res = (int)(ceil((count_6 + count_9) / 2.0));
		
		cout << res;

	}
	else {
		cout << 1;
	}
	
}