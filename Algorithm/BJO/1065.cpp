#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, count = 0, first, second, third;
    vector <int> hansu(1001, 1); //1~1000까지의 수는 일단 한수라는 의미로 1이 저장되어있다
    cin >> N;
    if (N < 100) count = N;
    else {
        for (int i = 100; i < 1001; i++)
        {
            first = i / 100;
            second = (i / 10) % 10;
            third = i % 10;
            if ((first + third) != 2 * second) //한수가 아니면 0으로 바꾼다
                hansu[i] = 0;
        }
        hansu[0] = 0;
        for (int i = 0; i < N + 1; i++) if (hansu[i]) count++;
    }
    cout << count;
}