/** 수학 셀프넘버  **/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int find_next(int number) {
	int n1, n2, n3, n4, result;
	n1 = number / 1000; //천의 자리
	n2 = (number % 1000) / 100; //백의 자리
	n3 = (number % 100) / 10; //십의 자리
	n4 = number % 10; //일의 자리
	result = number + n1 + n2 + n3 + n4;
	if (result >= 10000) return -1; //결과가 10000이상이라면 -1을 리턴한다
	return result;
}

int main() {
	vector <int> numbers(10001, 1); 
	numbers[10000] = 0;
	//1~10000숫자가 있다. index의 각 숫자가 그 수를 뜻하며 값이 1이면 셀프 넘버임을 뜻한다. index 0은 사용하지 않는다
	numbers[0] = -1;
	for (int i = 1, temp = 1; temp < numbers.size(); i++, temp++)
	{
		i = temp;
		if (numbers[i] == 1) // 셀프 넘버이면 숫자 i로 만들 수 있는 숫자들을 모두 0으로 만든다.
		{
			while(1) {
				i = find_next(i);
				if (i == -1) break;
				numbers[i] = 0;
			} 
		}
	}
	for (int i = 1; i < numbers.size(); i++) if (numbers[i] == 1) cout << i << "\n";
}