/** 자료구조 최대 힙 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int cur = 0;
vector<int>h (100001);

void swap(int a, int b){
	int tmp = h[a];
	h[a] = h[b];
	h[b] = tmp;
}

void insert(int x){
	h[++cur] = x;
	for(int i=cur; i>1; i/=2)
		if(h[i] > h[i/2]) swap(i, i/2);
		else break;
}

int pull(){
	if(cur == 0) return 0;
	if(cur == 1) return h[cur--];
	
	int rt = h[1], flag;
	h[1] = h[cur--];
	
	for(int i=1; i<cur;){
		flag = 0;
		if(h[i] < h[2*i] && 2*i <= cur){
			//i번째의 왼쪽 자식 존재, 왼쪽 자식이 더 큼
			flag = 1;
			if(h[2*i] < h[2*i+1] && 2*i <= cur)
				//i번쨰의 오른쪽 자식 존재, 오른쪽 자식이 가장 큼
				flag = 2;
		}else if(h[i] < h[2*i+1] && 2*i+1 <= cur)
			//i번째 오른쪽 자식 존재, 오른쪽 자식만 부모보다 큼
			flag = 2;
		
			
		if(flag == 0) break;
		if(flag == 1) {
			swap(i, i*2);
			i*=2;
		}
		else{
			swap(i, i*2+1);
			i = i*2+1;
		}
	}
	return rt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int N;
	cin >> N;
	h[0] = -1;
	
	vector<int> res;
	
	while(N--){
		int x;
		cin >> x;
		if(x > 0) insert(x);
		else res.push_back(pull());
			 
	}

	for(auto x : res) cout << x << "\n";
}