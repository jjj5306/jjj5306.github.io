#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//모든 경로(0, 0)제외에 장애물을 만들자고 체크한다.

typedef struct coordinates {
	int x;
	int y;
};

void make_ob(string str, coordinates& temp) {
	temp.x = 0;
	temp.y = 0;
	for (int i = 0; i < str.size(); i++) {
		switch (str[i]){
		case 'L': temp.x--;
			break;
		case 'R':temp.x++;
			break;
		case 'D':temp.y--;
			break;
		case 'U':temp.y++;
			break;
		}
	}
}

int check(coordinates obj, string str) {
	coordinates temp;
	temp.x = 0;
	temp.y = 0;
	for (int i = 0; i < str.size(); i++) {
		switch (str[i]) {
		case 'L': temp.x--;
			break;
		case 'R':temp.x++;
			break;
		case 'D':temp.y--;
			break;
		case 'U':temp.y++;
			break;
		}
		if ((temp.x == obj.x) && (temp.y == obj.y)) {
			switch (str[i]) {
			case 'L': temp.x++;
				break;
			case 'R':temp.x--;
				break;
			case 'D':temp.y++;
				break;
			case 'U':temp.y--;
				break;
			}
		}
	}
	if ((temp.x == 0) && (temp.y == 0)) return 1;
	return 0;

}

int main() {
	int T;
	int tag;
	cin >> T;
	vector <coordinates> res;
	while (T--) {
		tag = 0;
		string str;
		coordinates ob;
		ob.x = 0;
		ob.y = 0;
		cin >> str;
		for (int i = 1; i <= str.size(); i++) {
			make_ob(str.substr(0, i), ob);
			if (ob.x == 0 && ob.y == 0) continue;
			if (check(ob, str)) { 
				res.push_back(coordinates{ ob.x, ob.y });
				tag = 1;
				break;
			}
		}
		if (tag == 0) res.push_back(coordinates{ 0, 0 });
	}
	for (int i = 0; i < res.size(); i++) cout << res[i].x << " " << res[i].y<<"\n";
}