/** 자료구조 카드2 **/
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //1번이 제일 위로 1번부터 N번 카드가 있다.
    //제일 위에 있는 카드를 버리고 제일 위에 있는 카드를 제일 아래로 옮기는 것을 반복한다
    //가장 마지막에 남는 카드는?

    int N;
    cin >> N;
    deque <int> cards(N);
    for (int i = 0; i < N; i++) cards[i] = i + 1;

    int top = 0;
    while (cards.size() != 1) {
        cards.pop_front();
        cards.insert(cards.begin() + cards.size(), cards[0]);
        cards.pop_front();
    }
    cout << cards[0];
   
}