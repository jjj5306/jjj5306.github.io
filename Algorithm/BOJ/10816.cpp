/** 자료구조 숫자 카드 2 **/
//다시 풀기
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector <int> have_card(N);
    for (int i = 0; i < have_card.size(); i++) cin >> have_card[i];
    
    int M;
    cin >> M;
    vector <int> check_card(M);
    for (int i = 0; i < check_card.size(); i++) cin >> check_card[i];
    
    vector <int> res;

    sort(have_card.begin(), have_card.end());

    for (int i = 0; i < check_card.size(); i++) {
        //이분 탐색을 이용
        int first = 0, last = N - 1, count=0;

        while (first <= last) {
            int mid = (first + last + 1) / 2;
            if (check_card[i] < have_card[mid]) last = mid - 1;
            else if (check_card[i] > have_card[mid]) first = mid + 1;
            else {
                //찾은 경우
                count++;
                int temp = mid++;
                //현재 mid보다 큰 index 탐색
                while (have_card[mid] == check_card[i]) {
                    count++;
                    if (mid+1 >= have_card.size()) break;
                    mid++;
                }
                mid = temp;
                mid--;
                //현재 mid보다 작은 index 탐색
                while (have_card[mid] == check_card[i] ) {
                    count++;
                    if (mid-1 < 0) break;
                    mid--;
                }
                break;
            }
        }
        res.push_back( count);
    }

    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";

}