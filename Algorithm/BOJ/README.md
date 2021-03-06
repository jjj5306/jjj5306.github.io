# 백준 문제풀이

- 처음에는 코드의 주석에만 설명을 써놔서 복습할 때 보려고 했지만 점점 의미가 흐려지는 것 같았다.
	오늘(22.07.13)을 기준으로 복습에 중점을 두어 문제를 풀면서 느낀점과 부족한 부분, 
	어려운 알고리즘을 도출해내는 생각의 과정을 정리할 것이다.
	
- 오늘 푼 문제들과 예전에 푼 문제들은 다시 풀면서 작성할 예정이다.

---

# 22.07.13

## 1003 피보나치 함수

- 이 문제는 생각보다 간단했다. 당연히 함수를 일일이 호출하면서 카운팅 하지 않을 것이라고 생각했다. 
	피보나치 함수가 수열인만큼 fib(0), fib(1)의 수도 수열로 연결되지 않을까 생각해서 직접 해보니 그랬다.
	그렇다면 다이나믹 프로그래밍을 쓰면 되겠다! 라는 생각이 들어서 바로 적용해보았다.
	
- 문제는 쉽게 풀었지만 브루트포스랑 다이나믹 프로그래밍 구분이 좀 어렵다. 기본 개념을 좀 더 공부해야겠다.

- [1003 피보나치 함수](./1003.cpp)


## 1764 듣보잡

- 문제를 보자마자 set을 이용해서 교집합을 구하면 되겠다고 생각했다. 그런데 실제로 구현하다보니 set을 사용하기가 힘들었다.
	
	
- set, map의 사용법에 대해 더 공부해야겠다.

- [1764 듣보잡](./1764.cpp)

## 17219 비밀번호 찾기

- 앞의 듣보잡 문제와 흐름이 거의 똑같았다. 똑같이 map공부의 필요성을 느꼈다.

- [17219 피보나치 함수](./17219.cpp)

---


# 22.07.14

## 11047 동전0

- 분할 가능한 배낭 문제와 거의 유사하다. 보자마자 그리디로 방향을 잡았다.

- 아무 생각 없이 입력받은 값들을 처음부터 탐색하면서 K이하의 최댓값을 찾는 알고리즘으로 짰다가 시간 초과가 떴다.

- 이분 탐색을 사용하거나 set을 사용하면 될 것 같아서 이분 탐색을 이용하였다.

- [11047 동전0](./11047.cpp)

---

# 22.07.16

## 2579 계단 오르기

- 오랜만에 dp문제를 풀어서 그런지 어려웠다. 문제를 읽고 완전탐색은 절대 아니고, 점화식 형태로 해당 계단 전의 것을 이용할 수 있을 것 같아서 dp로 방향을 잡았다.

- 처음에는 i번째 칸에 가려면 전칸 혹은 전전칸을 무조건 들러야한다는 사실에 초점을 맞춰서 `dp[i-1]`과 `dp[i-2]` 중 최댓값을 이용하려했다.
	그리고 세 칸 연속 올라가는 경우를 제외하기 위해 전 칸에서 올라오는게 최대인 경우 그 칸의 `count`값을 증가시켜 `count`값이 3이면 전전칸의 값을 사용하려 했다.
	
	- ```
		vector<pair<int, int>> dp(N);
	
		dp[0] = {stairs[0], 1};
		dp[1] = {dp[0].first + stairs[1], 2};	
		for(int i = 2; i<N; i++){
			//전 칸의 dp값을 사용하는 경우, count부터 체크한다. 전 칸과 전전 칸의 cost가 같은 경우 전전칸을 우선 사용한다.
			if(dp[i-1].second == 2 || dp[i-2].first >= dp[i-1].first)
				dp[i] = {dp[i-2].first + stairs[i], 1};
			else
				dp[i] = {dp[i-1].first + stairs[i], dp[i-1].second + 1};
		}
		cout << dp[N-1].first << "\n";
		```
		
	- 위의 방식대로 하니 무조건 첫 칸을 방문한다는 문제점이 있었다. 또 전칸과 전전칸으로만 케이스를 나누어 생각하다보니 예외처리를 고려해야했다.
		하지만 **전전칸에서 올라오는 경우와 전전전칸 -> 전칸 순으로 올라오는 경우**로 나누어 생각하니 깔끔했다.
		
- 이번 문제를 풀면서 느낀점은.. 방향을 잡는 것 까지는 좋지만 그 뒤가 성급하다는 점이었다. 좀 더 생각해봤으면 한 번에 풀었을 것 같다.

- [2579 계단오르기](./2579.cpp)

---

# 22.07.17

## 2606 바이러스

- 간단한 그래프 탐색문제다. 오랜만에 그래프 문제를 다루니 배운 내용들이 경질화가 잘 안된 느낌이다. 생각나는 탐색 알고리즘은 많지만 서로 기억이 섞여있는 느낌이었다. 
	
- 기초적인 알고리즘을 더 복습하고 정리도 하면서 잘 경질화 시켜야겠다. 물론 구현도 직접 해보면서 시간복잡도도 줄이려고 해봐야겠다.

- [2606 바이러스](./2606.cpp)

## 1260 DFS와 BFS

- 그래프 문제를 푼 김에 DFS, BFS의 결과를 출력하는 문제도 풀어보았다. 분명 몇 번 씩이나 전공 시간에 다 구현한 것들인데 오랜만에 다시 하려니 힘들었다.

- 기초가 많이 부족하다는걸 다시 한 번 깨달았다.

- [1260 DFS와 BFS](./1260.cpp)