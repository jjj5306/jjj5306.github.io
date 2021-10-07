#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector <int> segment(4);
	vector <int> result;
	while (t--) {
		for (int i = 0; i < segment.size(); i++) cin >> segment[i];
		sort(segment.begin(), segment.end());
		result.push_back(segment[0] * segment[2]);
	}
	for (int i = 0; i < result.size(); i++) cout <<result[i]<<"\n";
}
