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
## 관련문제  
  * 완전수    
https://www.acmicpc.net/problem/14563   
  소스 코드 : [C++](./BOJ/14563.cpp) 

  * 소수 찾기    
https://www.acmicpc.net/problem/1978   
  소스 코드 : [C++](./BOJ/1978.cpp) 
***
## 소인수분해
* `약수 찾기`와 같은 알고리즘으로 약수를 찾되, 소인수가 발견되면 `n`을 그 소인수로 나눈다. 이 과정을 소인수가 $\sqrt n$이 될 때 까지 반복하고 마지막으로 `n`이 1보다 크면 그 때의 n 역시 소인수이다.
## 관련문제
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
* 에라토스테네스의 체를 사용한 소인수분해
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
## 관련문제  
  * 어려운 소인수분해   
   https://www.acmicpc.net/problem/16563   
  소스 코드 : [C++](./BOJ/16563.cpp)

  * 수 복원하기    
   https://www.acmicpc.net/problem/2312   
  소스 코드 : [C++](./BOJ/2312.cpp)

  * GCD(n, k) = 1   
   https://www.acmicpc.net/problem/11689   


  * 에라토스테네스의 체   
   https://www.acmicpc.net/problem/2960   
  소스 코드 : [C++](./BOJ/2960.cpp)

  * 암호 키   
   https://www.acmicpc.net/problem/1816   
  소스 코드 : [C++](./BOJ/1816.cpp)

  * 골드바흐의 추측   
   https://www.acmicpc.net/problem/9020   
  소스 코드 : [C++](./BOJ/9020.cpp)

  * 베르트랑 공준   
   https://www.acmicpc.net/problem/4948   
  소스 코드 : [C++](./BOJ/4948.cpp)

  * 소수&팰린드롬   
   https://www.acmicpc.net/problem/1747
***
## 모듈러 연산
* 덧셈
  - (a + b)%p = (a%p + b%p)%p
* 뺄셈
  - (a - b)%p = (a%p - b%p + p)%p
* 곱셈
  - (a * b)%p = ((a%p) * (b%p))%p
* 나눗셈
  - 곱셈의 `역원`을 정의하여 사용한다. 
  - `페르마의 소정리`를 이용하면 `모들러 계`에서 $a \cdot a^{p-2} = 1 $이라는 수식을 얻을 수 있고 따라서 $a$의 역원은  $a^{p-2}$이다.
  - `분할 정복을 통한 거듭제곱`을 이용하여 $x^y$를 $MOD$로 나눈 나머지를 구하면 아래의 코드와 같이 구현할 수 있다.

  ```
  using ll = long long;
  const ll MOD = (ll)1e9 + 7ll;
  //문제에서 제시한 소수를 사용

  ll modpow(ll x, ll y) {
    ll p = x;
    ll ret = 1;
    while (y) {
      if (y % 2) ret = (ret * p) %   MOD;
      p = p * p % MOD;
      y /= 2;
      }

      return ret;
  }
  ```
  - 위의 함수를 통해 모듈러 나눗셈을 구현하면 
  ```
  ll modinv(ll x) {
    return modpow(x, MOD - 2);
  }
  ```
***
## 모듈러 연산의 구현
  - 기초 연산을 함수로 구현하여 사용한다. 
  ```
  const long long MOD = 998244353;

  long long madd(long long a, long long b) {
    return (a + b) % MOD;
  }
  
  long long msub(long long a, long long b) {
    return (a - b + MOD) % MOD;
  }
  
  long long mmul(long long a, long long b) {
    return (a * b) % MOD;
  }
  ```
## 관련문제
  - 괄호    
  https://www.acmicpc.net/problem/10422

  - 가짜 소수    
  https://www.acmicpc.net/problem/4233

  - 이항 계수와 쿼리    
  https://www.acmicpc.net/problem/13977

***
# 분할정복
## 매개 변수 탐색
  * 내용
## 관련문제
  - 공유기 설치    
  https://www.acmicpc.net/problem/2110

  - 공장 컨설턴트 호석    
  https://www.acmicpc.net/problem/22254

  - 휴게소 세우기    
  https://www.acmicpc.net/problem/1477

  - 폭탄제조    
  https://www.acmicpc.net/problem/2977

***
## 삼분 탐색
  * 내용
## 관련문제

***
## 인터랙티브
  *
## 관련문제

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

