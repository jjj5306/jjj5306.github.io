/** 브루트포스 알고리즘 체스판 다시 칠하기 **/
//이중포인터 연습하기 좋음
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int case_white(char** chess, int row, int col) {
	int res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {//백을 칠해야함
				if (chess[row + i][col + j] == 'B') res++;

			}
			else {//흑을 칠해야함
				if (chess[row + i][col + j] == 'W') res++;
			}
		}
	}
	return res;
}

int case_black(char** chess, int row, int col) {
	int res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {//흑을 칠해야함
				if (chess[row + i][col + j] == 'W') res++;

			}
			else {//백을 칠해야함
				if (chess[row + i][col + j] == 'B') res++;
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//M*N크기의 보드에서 8*8 크기의 체스판을 만들고 다시 칠해야 하는 정사각형 개수의 최솟값을 구하자.
	int M, N;
	cin >> N >> M;
	//행의 개수 N 열의 개수 M
	
	char** chess = new char*[N];
	for (int i = 0; i < N; i++) chess[i] = new char[M];
	//chess[N][M]과 같다
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> chess[i][j];
	int res = 65;
	
	for (int row = 0; row <= N-8; row++)
		for (int col = 0; col <= M-8; col++) {
			//chess[row][col]을 가장 왼쪽 위로 정한다.
			//0, 0을 시작점으로 정해서 판단.
			int c_w = case_white(chess, row, col), c_b = case_black(chess, row, col);
			if (c_w <= c_b && c_w < res) res = c_w;
			else if (c_w > c_b && c_b < res) res = c_b;
		}

	for (int i = 0; i <N; ++i) delete[] chess[i];
	delete[] chess;
	cout << res;


}