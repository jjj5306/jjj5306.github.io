/** 구현 팰린드롬수 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector <string> res;

	string num;
	while(1)
	{
		cin >> num;
		if (num == "0") break;
		string temp(num);
		reverse(num.begin(), num.end());
		if (temp == num) res.push_back("yes");
		else res.push_back("no");
	}
	for (int i = 0; i < res.size(); i++) cout << res[i]<<"\n";
}