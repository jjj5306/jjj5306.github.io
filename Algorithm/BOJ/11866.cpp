/** 자료구조 요세푸스 문제 0 **/
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    deque <int> result;
    deque <int> people(N);
    for (int i = 0; i < people.size(); i++) people[i] = i + 1;
    //덱에는 1부터 N까지가 들어있다. front부터 차례로 pop push(front)를 하되 K번째인 경우 push는 하지 않는다

    int count = 1;
    while (people.size() != 1) {
        if (count == K) {
            result.push_back(people.front());
            people.pop_front();
            count = 1;
        }
        else {
            people.push_back(people.front());
            people.pop_front();
            count++;
        }
    }
    result.push_back(people[0]);

    cout << "<"<<result[0];
    for (int i = 1; i < result.size(); i++) cout <<", "<< result[i];
    cout << ">";
  

}