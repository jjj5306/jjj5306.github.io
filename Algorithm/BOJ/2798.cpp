/** 브루트포스 알고리즘 블랙잭 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // N장의 카드 중 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력하라.
    //N M이 주어지고 둘째 줄에 카드에 쓰여있는 수가 주어진다.

   int N, M;
    cin >> N >> M;

    vector <int> card(N);
    for (int i = 0; i < card.size(); i++) cin >> card[i];

    int count = 0, res=0;

        for (int i = 0; i < card.size() - 2; i++) 
            for (int j = i + 1; j < card.size() - 1; j++) 
                for (int k = j + 1; k < card.size(); k++)
                {
                    if (card[i] + card[j] + card[k] > M)  continue;
                    else if (card[i] + card[j] + card[k] == M) {
                        res = card[i] + card[j] + card[k];
                        goto RES;
                    }
                    else if (res < card[i] + card[j] + card[k])
                        res = card[i] + card[j] + card[k];
                }

    RES:
    cout << res;
}