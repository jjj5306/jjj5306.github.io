/**  문자열 단어의 개수 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string str;
	getline(cin, str);

	if (str.empty())
	{
		cout << "0";
		return 0;
	}

	int res = 0, i=0;
	while (str[i] == (char)32) i++;

	res = 1;

	while (str[i] != NULL) {
		if (str[i] == (char)32) res++;
		i++;
	}
	if (str[str.length() - 1] == ' ') res--;
	cout << res;
}