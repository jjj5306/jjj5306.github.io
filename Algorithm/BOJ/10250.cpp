/** 구현 ACM 호텔 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>  
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //각 층에 W개의 방이 있는 H층 건물 이를 H X W 형태 호텔이라함
    //방 호실은 YXX의 형태로 Y는 층 수 XX는 엘리베이터에서 센 숫자이다.
    //엘리베이터까지 거리보다 엘리베이터에서 걷는 거리가 짧은수록 선호 같으면 낮은층 선호

    int T;
    cin >> T;
    vector<int> res;
    while (T--) {
        int H, W, N;

        cin >> H >> W >> N;

        vector <int> result(H * W+1, -1);

        int i = 1;

        while (1) {
            if (i >= result.size()) break;

            for (int x = 1; x <= W; x++) {
                if (i >= result.size()) break;

                for (int y = 1; y <= H; y++) {
                    if (i >= result.size()) break;

                    if (x < 10)  result[i++] = stoi(to_string(y) + "0" + to_string(x));
                    else result[i++] = stoi(to_string(y) + to_string(x));
                }
            }
        }

        res.push_back(result[N]);
    }
    for (int i = 0; i < res.size(); i++) cout << res[i]<<"\n";

}