/** 구현 크로아티아 알파벳 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string croatia;
	cin >> croatia;
	int res = 0;
	for (int i = 0; i < croatia.size(); i++) {
		if (croatia.substr(i, 3) == "dz=") {
			i += 2;
			res++;
		}
		else if (croatia.substr(i, 2) == "c=") {
			i++;
			res++;
		}
		else if (croatia.substr(i, 2) == "c-") {
			i++;
			res++;
		}
		else if (croatia.substr(i, 2) == "d-") {
			i++;
			res++;
		}
		else if (croatia.substr(i, 2) == "lj") {
			i++;
			res++;
		}
		else if (croatia.substr(i, 2) == "nj") {
			i++;
			res++;
		}
		else if (croatia.substr(i, 2) == "s=") {
			i++;
			res++;
		}
		else if (croatia.substr(i, 2) == "z=") {
			i++;
			res++;
		}
		else res++;
	}
	cout << res;
}