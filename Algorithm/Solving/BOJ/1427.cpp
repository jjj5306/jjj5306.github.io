/** 정렬 소트인사이드 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string>
using namespace std;

vector<int> ChToInt(vector<char> &num){
	vector<int> res;
	for(auto x : num) res.push_back(x-'0');
	return res;
}


void swap(vector<int>& arr, int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int partition(vector<int>& arr, int start, int end){
	int x = arr[end]; //기준 원소
	int i = start-1; //p~i까지는 기준보다 큰 원소들
	for(int j=start; j < end; j++){ //i+1~j까지는 기준보다 작은 원소들, j+1~end까지는 정렬되지않은 원소들
		if(arr[j] > x){ //기준원소보다 크면 p~i구간에 넣어야한다.
			//arr[j]를 arr[i+1]과 바꿔서 j를 p~i에 들어가게한다.
			swap(arr, j, ++i);
		}
	}
	//기준원소를 자기보다 작아지기 시작한 곳인 i+1에 넣는다.
	swap(arr, i+1, end);
	return i+1;
}


void QuickSort(vector<int>& arr, int start, int end){
	if(start < end){
		int mid = partition(arr, start, end);
		QuickSort(arr, start, mid-1);
		QuickSort(arr, mid+1, end);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<char> num;
	string s;
	cin >> s;
	
	for(int i=0; i<s.length(); i++) num.push_back(s[i]);
	
	vector<int> res = ChToInt(num);
	QuickSort(res, 0, s.size()-1);
	for(auto x : res) cout << x;
	
}
