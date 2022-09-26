/** 구현 팩토리얼 0의 개수 **/
//너무 간단하게 생각하지 말것...! 뒤에서부터 0을 세는 이유가 있지 않을까?
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//N!에서 뒤에서부터 0이아닌 숫자가 나올때까지 0 개수 구하기
	int N, res = 0;
	cin >> N;
	
	//N!에서 끝부분이 0이 나오려면 10^ 형태로 되어야한다. 이를 구하기위해 팩토리얼을 분해하여 팩토리얼을 구하는 과정에서 소인수분해를 진행하여 5의 개수를 센다.
	//1~500의 숫자만 소인수분해하면 되므로 2중 for문을 사용한다. 숫자가 더 클경우 에라토스 테네스의 체를 이용하면 될 것 같다.
	for(int i=2; i<=N; i++){
		//숫자 i 소인수분해하기
		int temp = i;
		for(int j=2; j <= i; j++){
			while(temp % j == 0){
				temp /= j;
				if(j == 5) res++;
			}
		}
	}
	
	cout << res << "\n";
}
