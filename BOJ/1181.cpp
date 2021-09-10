/** 정렬 단어 정렬 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//N개의 문자열을 길이가 짧은 것부터, 길이가 같다면 사전 순으로 정렬한다.

	vector <string> words(N);
	for (int i = 0; i < N; i++) cin >> words[i];

	vector<string> res;
	res.push_back(words[0]);

	for (int i = 1; i < words.size(); i++) {
		for (int j = 0; j < res.size(); j++) {
			if (res[j] == words[i])
				break;
			else if (res[j].length() > words[i].length()) {
				//insert연산자는 마지막에 삽입을 할 수 없고 벡터의 size를 계속 증가시키므로 반복문을 돌릴때 조심해야한다.
				res.insert(res.begin() + j, words[i]);
				break;
			}
			else if (res[j].length() == words[i].length()) {
				// 문자열 간의 비교 연산자는 문자열의 길이가 같으면 사전순으로 뒤에 있을 때 크다고 판단한다.
				if (res[j] > words[i]) {
					res.insert(res.begin() + j, words[i]);
					break;
				}
				else if (j + 1 == res.size()) res.push_back(words[i]);
			}
			else if (j + 1 == res.size()) res.push_back(words[i]);
		}
	}

	for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";


}