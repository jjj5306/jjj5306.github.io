/** 백트래킹 N-Queen  **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

const int MAX = 15;
int chess[MAX];
//체스판에 퀸을 한 행에 하나씩만 둔다. 따라서 굳이 이차원 배열을 사용하지 않고 2, 2에 퀸을 두려면 chess[2]=2와 같은 식으로 사용하는 것이 훨씬 공간을 절약할 수 있다.
int N;
int res=0;

bool isPromising(int row){
	//row행에 놓은 퀸이 유망한지 판단한다.
	
	for(int col=0; col<row; col++){
		//현재까지 놓은 퀸 중 같은 열이나 대각선상에 위치하는지 판단한다. 
		//방금 row행에 퀸을 놓았으므로 당연히 row행 전까지만 체크하면 된다. 당연하게도 같은 행에 퀸이 있는지는 체크할 필요 없다.
		if(chess[row] == chess[col] || row-col == abs(chess[row] - chess[col])) return 0;
	}
	//걸리지 않았다면 유망한 것이다.
	return 1;
}

void nQueen(int row){
	if(row == N){
		//마지막 행까지 성공적으로 퀸을 뒀다면 row가 N이 되게되고 그렇다면 경우의 수 하나를 찾은 것이다.
		res++;
		return;
	}
	
	for(int col=0; col<N; col++){
		//row행 col열에 퀸을 둔다.
		chess[row] = col;
		//놓은 퀸이 유망한지 판단한다. 유망하다면 다음 행에 대해 퀸을 두어본다.
		//한 행에 하나의 퀸만 두었으므로 퀸을 두는 과정에서 가지치기가 일어났다고 생각할 수 있다. 
		if(isPromising(row)) nQueen(row+1);
		//유망하지 않다면 col을 하나 늘려 row행 다음 열에 대해 퀸을 놓아본다.
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	
	nQueen(0);
	cout << res << "\n";
	
}
