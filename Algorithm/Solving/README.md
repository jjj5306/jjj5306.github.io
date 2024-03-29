# 문제풀이

- 처음에는 코드의 주석에만 설명을 써놔서 복습할 때 보려고 했지만 점점 의미가 흐려지는 것 같았다.
	오늘(22.07.13)을 기준으로 복습에 중점을 두어 문제를 풀면서 느낀점과 부족한 부분, 
	어려운 알고리즘을 도출해내는 생각의 과정을 정리할 것이다.
	
- 새로 푼 문제들과 예전에 푼 문제들은 다시 풀면서 작성할 예정이다.

# 22.11.09

## BOJ 1202 보석도둑

- 가치가 가장 높은 보석을 넣을 수 있는 가방 중 무게 제한이 제일 작은 가방에 넣어야 한다고 생각하고 접근했다. 가방에 보석을 최대 하나만 넣을 수 있으므로 복잡하게 생각할 것 없이 그리디로 접근하면 될 것 같았다.
  
- 모든 가방을 사용할 수 있다면 사용하는 것이 좋으므로 가방을 기준으로 무게가 가장 낮은 가방부터 넣을 수 있는 최대 가치 보석을 넣으면 된다.  

- 그렇지만 그냥 냅다 구현하면 메모리 제한때문에 vector도 못쓰고 시간 초과도 뜬다. 따라서 일차원 pair 배열을 사용해주었다. 그리고 시간 제한에 걸리는 부분이 가방 무게 제한에 걸리지 않는 보석 중 가장 가치가 큰 보석을 구할 때 오래 걸렸다.   
  이 부분을 우선순위 큐를 이용하여 O(K\*N^2)에서 O(K\*Nlog N)으로 줄여 해결했다. 포인트는 idx번째 보석을 i번째에 넣을 수 있으면 i+1번째에도 넣을 수 있으므로 idx는 초기화할 필요가 없다는 부분이다.
  

# 22.11.01

## BOJ 9184 신나는 함수 실행

- 기본적인 dp문제이다.

- 삼차원 배열을 이용해서 풀었다. 구조체를 이용하면 공간을 더 절약할 수 있을 줄 알았는데 그럼 더 오래걸릴것 같다.

- 피보나치랑 거의 유사해서 쉽게 풀었다.

## BOJ 1932 정수 삼각형

- 삼각형을 누적합으로 바꾸면 될 것 같았는데 맞았다.

- 메모이제이션만 잘 기억하면 되는 쉬운 문제였다.

## BOJ 1912 연속합

- LIS랑 큰 차이점을 모르겠다. LIS를 잘 정리해뒀더니 풀이가 바로 생각났다.

## BOJ 11660 구간 합 구하기 5

- 이 문제도 결국 메모이제이션이다. 어렵게 생각하지 말고 누적합을 저장한 배열이 여러 개 이어붙어 있다 생각하면 해결하기 쉽다.

# 22.10.13

## BOJ 1427 소트인사이드

- 정렬들을 공부한 후 풀었다. 문자열을 정수로 쪼개서 정렬하면 되는 문제이다. 

- 좀 보기좋게 짜고싶어서 변수 이름도 알아보기 쉽게하고, 함수도 한 번에 한 동작만 수행하도록 하였다. 쉬운 문제이지만 내 손으로 구현하니 뿌듯하다.

- 퀵 정렬을 직접 짤 때는 구간을 미리 나눠두니 전혀 헷갈리지 않았다. 예를 들어 start ~ i는 기준보다 작은 원소들, i+1~j는 기준보다 큰 원소들 이런식으로 하니 내 손으로 직접 짜기가 쉬운 것 같다.

- 문자열을 정수로 쪼개는 것도 꽤 겁먹었는데 잘 모르는 함수를 사용하려 하지 않고 기본 로직을 이용하니 훨씬 쉬웠다. '1'을 1로 변경하고 싶으면 '1'-'0'을 하면 된다! 알파벳도 숫자로 바꿀 수 있다.

# 22.07.27

## BOJ 11279 최대 힙

- 우선순위 큐와 힙을 공부한 후 풀어보았다. 생각보다 예외 처리를 많이 해줘야해서 까다로웠다.

	- 0번쨰 index를 사용하지 않아서 첫 번째 원소와 관련되어 삭제, 삽입을 할 때 신경써줘야했다.
	
	- 삭제를 할 때 자식이 있는지 체크하고, 왼쪽, 오른쪽 중 큰 자식을 삭제해야 한다.
	
- 기본적인 쉬운 자료구조도 막상 구현해보니 까다로웠다. 기초가 더 필요한 것 같다.

- [11279 최대 힙](./BOJ/11279.cpp)

## BOJ 1927 최소 힙

- 이번에는 stl을 사용해서 구현해보았다. 확실히 훨씬 쉽다. 시간도 훨씬 단축되었다.

- 우선순위큐 stl을 사용하다 보니 생각난 것인데, 구조체 등을 사용할 때 연산자 재정의 하는 부분이 꽤 헷갈려서 실전에 나오면 당황할 것 같다. 공부해야겠다.

- [1927 최소 힙](./BOJ/1927.cpp)

# 22.07.21

## BOJ 9461 파도반 수열

- 다이나믹 프로그래밍 문제이다. 이 문제 또한 감이 안잡혀서 손으로 먼저 수열을 계산해보았다. 손으로 계산하다보니 논리적으로 이해가 되지는 않았지만
	`dp[n] = dp[n-2] + dp[n-3]`이라는 점화식을 알게되었다.
	
- 논리적으로 이 점화식이 왜 나왔는지 이해하려 했지만 실패했다. 수학적으로 계산하여 이 식을 떠올리려면 많이 어려울 것 같았다. 직접 나열하면서 규칙을 찾는 방식도 연습해야겠다.

- 점화식을 도출한 뒤에는 굉장히 수가 빠르게 커지므로 `long long`만 사용해주면 됐다.

- [9461 파도반 수열](./BOJ/9461.cpp)


# 22.07.20

## BOJ 9095 1, 2, 3 더하기

- 다이나믹 프로그래밍 문제이다. 처음 보고 어떻게 풀지 당황했다. 체감상 당황하면 다이나믹 프로그래밍이라서 살짝 그쪽으로 생각을 하고 있었다.
		
	- `n = (n-1) + 1 = (n-2) + 2 = (n-3) + 3 ` 이라는 식을 생각해내고 다이나믹 프로그래밍으로 방향을 잡았다.
	
	- 처음에는 `dp[n] = dp[n-1] + dp[n-2] + dp[n-3]`을 바로 사용하면 안되는 줄 알았다. 중복이 생기고 순서가 뒤섞이고 이러면 꼬인다고 생각했다.
	
	- 다시생각해보니 위의 식을 바로 사용해도 문제가 없었다. 5를 예로 들어 4의 항인 `1+1+2` 뒤에 1을 붙이면 3의 항인 `1+1+1` 뒤에 2를 붙이는것과 중복이 생긴다고 생각했는데, `1+1+2`를 고정하고 뒤에 숫자 1만 붙인다고 생각하면 꼬일 일이 없었다.
	
- dp로 방향을 잡는 거 까지는 나쁘지 않았는데 그 뒤에서 또 꼬였다. dp문제는 끝까지 긴장을 유지하지 않으면 시간을 많이 잡아먹는 것 같다.

- [9095 1, 2, 3 더하기](./BOJ/9095.cpp)


# 22.07.17

## BOJ 2606 바이러스

- 간단한 그래프 탐색문제다. 오랜만에 그래프 문제를 다루니 배운 내용들이 경질화가 잘 안된 느낌이다. 생각나는 탐색 알고리즘은 많지만 서로 기억이 섞여있는 느낌이었다. 
	
- 기초적인 알고리즘을 더 복습하고 정리도 하면서 잘 경질화 시켜야겠다. 물론 구현도 직접 해보면서 시간복잡도도 줄이려고 해봐야겠다.

- [2606 바이러스](./BOJ/2606.cpp)

## BOJ 1260 DFS와 BFS

- 그래프 문제를 푼 김에 DFS, BFS의 결과를 출력하는 문제도 풀어보았다. 분명 몇 번 씩이나 전공 시간에 다 구현한 것들인데 오랜만에 다시 하려니 힘들었다.

- 기초가 많이 부족하다는걸 다시 한 번 깨달았다.

- [1260 DFS와 BFS](./BOJ/1260.cpp)


# 22.07.16

## BOJ 2579 계단 오르기

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

- [2579 계단오르기](./BOJ/2579.cpp)

---

# 22.07.14

## BOJ 11047 동전0

- 분할 가능한 배낭 문제와 거의 유사하다. 보자마자 그리디로 방향을 잡았다.

- 아무 생각 없이 입력받은 값들을 처음부터 탐색하면서 K이하의 최댓값을 찾는 알고리즘으로 짰다가 시간 초과가 떴다.

- 이분 탐색을 사용하거나 set을 사용하면 될 것 같아서 이분 탐색을 이용하였다.

- [11047 동전0](./BOJ/11047.cpp)



# 22.07.13

## BOJ 1003 피보나치 함수

- 이 문제는 생각보다 간단했다. 당연히 함수를 일일이 호출하면서 카운팅 하지 않을 것이라고 생각했다. 
	피보나치 함수가 수열인만큼 fib(0), fib(1)의 수도 수열로 연결되지 않을까 생각해서 직접 해보니 그랬다.
	그렇다면 다이나믹 프로그래밍을 쓰면 되겠다! 라는 생각이 들어서 바로 적용해보았다.
	
- 문제는 쉽게 풀었지만 브루트포스랑 다이나믹 프로그래밍 구분이 좀 어렵다. 기본 개념을 좀 더 공부해야겠다.

- [1003 피보나치 함수](./BOJ/1003.cpp)


## BOJ 1764 듣보잡

- 문제를 보자마자 set을 이용해서 교집합을 구하면 되겠다고 생각했다. 그런데 실제로 구현하다보니 set을 사용하기가 힘들었다.
	
	
- set, map의 사용법에 대해 더 공부해야겠다.

- [1764 듣보잡](./BOJ/1764.cpp)

## BOJ 17219 비밀번호 찾기

- 앞의 듣보잡 문제와 흐름이 거의 똑같았다. 똑같이 map공부의 필요성을 느꼈다.

- [17219 피보나치 함수](./BOJ/17219.cpp)
