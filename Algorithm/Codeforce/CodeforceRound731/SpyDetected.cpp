#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int t, n, index=0;
	int* arr;
	//t개의 case에 대해 test, 각 array의 length는 n, 배열에서 index번째 원소만 다르다
	cin >> t;
	while(t--)
	{
		n = 0;
		index = 0;
		cin >> n;
		arr = new int[n];
		for (int j = 0; j < n; j++)
			cin >> arr[j];
		int pre=0, cur=1, next=2;
		while (1)
		{
			if (arr[pre] == arr[cur] && arr[cur] == arr[next])
			{
				pre++;
				cur++;
				next++;
			}
			else if (arr[pre] != arr[cur] && arr[pre] != arr[next]) {
				index = pre;
				break;
			}
			else if (arr[cur] != arr[pre] && arr[cur] != arr[next]) {
				index = cur;
				break;
			}
			else {
				index = next;
				break;
			}
		}
		cout << index+1 << "\n";
	}
}