
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct coordinate {
	int x;
	int y;
};

int main() {
	int t, n, index = 0;
	char** arr;
	//t개의 case에 대해 test, 각 array의 size는 n*n
	cin >> t;
	while (t--) {
		n = 0;
		cin >> n;
		arr = new char*[n];
		for (int i =0;i < n;i++)
			arr[i] = new char[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
	

		coordinate star1, star2, star3, star4;
		int count;
		count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][j] == '*')
				{
					if (count == 0)
					{
						star1.x = i;
						star1.y = j;
						count++;
					}
					else if(count == 1)
					{
						star2.x = i;
						star2.y= j;
						break;
					}
				}

		//case 1 같은 행에 존재
		if (star1.x == star2.x){
			if (star1.x + 1 < n){
				star3.x = star1.x+1;
				star3.y = star1.y;
				star4.x = star2.x+1;
				star4.y = star2.y;
			}
			else {
				star3.x = star1.x - 1;
				star3.y = star1.y;
				star4.x = star2.x - 1;
				star4.y = star2.y;
			}
		}
		//case 2 같은 열에 존재 
		else if (star1.y == star2.y){
			if (star1.y + 1 < n) {
				star3.x = star1.x ;
				star3.y = star1.y + 1;
				star4.x = star2.x ;
				star4.y = star2.y + 1;
			}
			else {
				star3.x = star1.x;
				star3.y = star1.y - 1;
				star4.x = star2.x;
				star4.y = star2.y - 1;
			}
		}
		//case 3 대각선에 존재 
		else{
			star3.x = star2.x;
			star3.y = star1.y;
			star4.x = star1.x;
			star4.y = star2.y;
		}

		arr[star3.x][star3.y] = '*';
		arr[star4.x][star4.y] = '*';

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << arr[i][j];
			cout << "\n";
		}

		/*배열 할당 해제*/
		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete arr;
	}

}
