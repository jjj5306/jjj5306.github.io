# Algorithm
# 목차
* [개요](#개요)
* [정수론](#정수론)
* [자료구조](#자료구조)
* [Dynamic Programming](#Dynamic-programming)
* [브루트포스 알고리즘](#브루트포스-알고리즘)
***
# 개요
* [알고리즘 공부, 어떻게해요?](https://baactree.tistory.com/52)
* 배경지식은 `알고리즘 문제해결전략`책으로 구현력과 문제해결능력은 `백준`에서 늘린다. 그 후 `코드포스`에서 문제해결능력을 집중적으로 높인다.
* [C++ stl 사용 팁](../C++/stl.md)
***
# 정수론
## 약수 찾기
* 어떤 정수 `n`에 대해 그 약수 `a`는 아래의 등식이 성립한다.
$$ 1 \leq a \leq \sqrt n $$ 
따라서 아래의 알고리즘과 같이 약수를 찾을 수 있다.
```
vector<int> getdivs(int n) {
  vector<int> ret;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
    ret.push_back(n / i);
    if (i * i != n) ret.push_back(i);
    }
  }
  sort(ret.begin(),ret.end());
  return ret;
  }
```
* 관련문제  
  * 완전수    
https://www.acmicpc.net/problem/14563   
  소스 코드 : [C++](./BOJ/14563.cpp) 
  * 소수 찾기    
https://www.acmicpc.net/problem/1978   
  소스 코드 : [C++](./BOJ/1978.cpp) 
***
## 소인수분해
* `약수 찾기`와 같은 알고리즘으로 약수를 찾되, 소인수가 발견되면 `n`을 그 소인수로 나눈다. 이 과정을 소인수가 $\sqrt n$이 될 때 까지 반복하고 마지막으로 `n`이 1보다 크면 그 때의 n 역시 소인수이다.
* 관련문제
  * 소인수분해    
https://www.acmicpc.net/problem/11653   
  소스 코드 : [C++](./BOJ/11653.cpp)
***
## 에라토스테네스의 체
* $2$이상 $n$이하의 모든 소수를 구하는 알고리즘이다. $2$부터 $\sqrt n$까지 그 수의 모든 배수를 지워내는 알고리즘이다. 
```
vector<int> sieve(int N) {
    vector<int> prime(N, 1);
    prime[0] = prime[1] = 0;
    for (int i = 0; i < N; i++) {
      if (prime[i] == 0) continue;
      if ((i * i) > prime.size()) break;
      for (int j = i * i; j < prime.size(); j += i) {
        prime[j] = 0;
        }
    }
    return prime;
}
```
***
## 에라토스테네스의 체를 사용한 소인수분해
* 소수가 아닌 수를 지우는 과정에서 그 수를 지울 때 사용한 소인수를 기록한다. 그렇게되면 `i`번째 index의 값이 i이면 소수이다.
```
vector<int> sieve(int n) {
  vector<int> S(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (S[i] != 0) continue;
    for (int j = i; j <= n; j += i) S[j] = i;
  }
  return S;
}
```
* 관련문제  
  * 어려운 소인수분해   
   https://www.acmicpc.net/problem/16563   
  
  * 수 복원하기    
   https://www.acmicpc.net/problem/2312   

  * GCD(n, k) = 1   
   https://www.acmicpc.net/problem/11689   

  * 에라토스테네스의 체   
   https://www.acmicpc.net/problem/2960   

  * 암호 키   
   https://www.acmicpc.net/problem/1816   

  * 골드바흐의 추측   
   https://www.acmicpc.net/problem/9020   

  * 베르트랑 공준   
   https://www.acmicpc.net/problem/4948   

  * 소수&팰린드롬   
   https://www.acmicpc.net/problem/16563   

  

***
# 자료구조
## 이론 정리
## 관련 문제
***
# Dynamic Programming
## 이론 정리
## 관련 문제
***
# 브루트포스 알고리즘
## 이론 정리
## 관련 문제
***

