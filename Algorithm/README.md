# Algorithm
# 목차
* [개요](#개요)
* [정수론](#정수론)
* [분할정복](#분할정복)
* [Dynamic Programming](#Dynamic-programming)
* [자료구조](#자료구조)
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
```
  vector<int> factorize(int n) {
  //여기서 변수 n은 지역 변수, 즉 원래 n의 복사본
  vector<int> ret;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n /= i;
      ret.push_back(i);
    }
  }
  if (n > 1) ret.push_back(n);
  return ret;
  }
```

## 관련문제
***
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

## 관련문제  
  * 어려운 소인수분해   
   https://www.acmicpc.net/problem/16563   
  소스 코드 : [C++](./BOJ/16563.cpp)

  * 수 복원하기    
   https://www.acmicpc.net/problem/2312   
  소스 코드 : [C++](./BOJ/2312.cpp)

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

## 유클리드 호제법
* 최소공약수 `GCD`를 일반적인 방법으로 2부터 두 자연수 중 작은 자연수까지 모두 나누어보면서 구하면 시간복잡도는 `O(N)`이 된다. 하지만 유클리드 호제법을 이용하면 시간복잡도를 `O(logN)`으로 줄일 수 있다.
* 2개의 자연수 A, B에 대해서 A와 B의 최대공약수는 B와 A % B 의 최대공약수와 같다. 정리하자면 아래와 같다.
$$ 
  GCD(A, B) = GCD(B, A \% B)    
$$
$$
  if A \% B = 0 \Rightarrow GCD = B
$$
$$
  else GCD(B, A\%B)
$$
***

## 오일러 파이 함수
  * $a^{\phi(n)} = 1 \ \ \ \ \ \ \ mod \ n$을 만족하는 $\phi(n)$ 을 `오일러 파이 함수`라고 하고, 이는 $1$부터 $n$까지 $n$과 서로소인 수들의 개수이다.
  * $p$가 소수이면 $\phi(p) = p-1$이다.
  * $\phi(m)\phi(n) = \phi(mn)$의 곱셈적성질을 만족한다.

## 오일러 파이 함수의 계산
  * $p$가 소수일 때 $\phi(p^k)$의 값을 보자. $p$가 소수이므로 $p^k$와 서로소가 아닌 수들은 반드시 $p$를 인수로 가져야 한다. 이런 수들은 $p^{k-1}$개가 있다. 따라서    
  $$
  \phi(p^k) = p^k - p^{k-1}
  $$
$\;\;\;\;\;\;\;\;\;\,$라는 결론을 얻는다.
  * 위의 결론에서 모든 수를 소수의 곱으로 소인수분해 한 뒤 오일러 파이 함수가 곱셈적 함수임을 이용해서 계산할 수 있다. 아래의 `GCD(n, k) = 1` 문제의 주석을 잘 참고하면 이해하기 쉽다.
$\phi(a) = pie(p_1^{k_1}p_2^{k_2}\cdot\cdot\cdot p_n^{k_n})$  

$\;\;\;\;\;\;\;\;\,\;\;\;\;\;\;\;\;= p_1^{k_1}(1 - \frac 1 {p^1})p_2^{k_2}(1 - \frac 1 {p^2})\cdot\cdot\cdot p_n^{k_n}(1 - \frac 1 {p^n})$  

$\;\;\;\;\;\;\;\;\,\;\;\;\;\;\;\;\; = a(1 - \frac 1 {p^1})(1 - \frac 1 {p^2})\cdot\cdot\cdot (1 - \frac 1 {p^n}) $

## 관련문제
  * GCD(n, k) = 1   
   https://www.acmicpc.net/problem/11689   
   소스 코드 : [C++](./BOJ/11689.cpp)
***

# 분할정복
## 매개 변수 탐색
  * 최적화 문제를 결정 문제로 변형하는 이분 탐색 기법이다. 
  * 예를 들어 모든 구간에서 증가하는 함수 $f(x)$가 있다고 가정하자.
    * 최적화 문제 : $f(x) \geq t$인 가장 작은 정수 $x$를 구하라.    

    이 문제를 풀려면 모든 $x$에 대해 확인해보는 방법을 가장 간단하게 떠올릴 수 있다. 그런데 이 최적화 문제를 `매개 변수 탐색`을 통해 결정 문제로 변형할 수 있다.
      * 결정 문제 : 어떤 정수 $x$에 대해 $f(x) \geq t$인가?

     이 문제는 훨씬 간단하고, $f(x)$는 모든 구간에서 증가한다. 따라서
     * $f(a) \geq t$이면 $a \leq b$인 모든 $b$에 대해 $f(b) \geq t$이다.
       - 이 때 $a$보다 큰 모든 정수 $b$는 가장 작은 정수 해 $x$가 될 수 없다.

      * 비슷하게 $f(a) \leq t$인 경우에도 $b \lt a $인 모든 $b$에 대해 $f(b) \lt t$이므로 $a$보다 작은 모든 정수는 $x$가 될 수 없다.
  * 최적화 문제를 만났다면 $f(x)$를 설정할 수 있을지 생각해보자. 또 그 함수가 모든 구간에서 증가하거나 감소하는 경향을 보인다면 그 문제는 매개 변수 탐색을 활용할 수 있을 가능성이 높다. 매개 변수 탐색을 활용해야겠다는 생각이 들면 그 함수를 통해 답의 범위를 설정하고 범위의 중간값에 대해 답이 되는지 조사하면서 범위의 크기가 1이 될때까지 줄여나가자. 

## 예시문제: 랜선 자르기
* 랜선을 $n$개 이상 만들 수 있는 가장 짧은 정수 길이 $x$를 찾는 문제이다. 
  * $f(a)$: 단위 길이 $a$로 랜선을 자를 때 만들 수 있는 랜선 개수

  위와 같이 정의하면 우리는 $f(x) \geq n$인 가장 큰 정수 해 $x$를 찾으면 된다. 이 때 $a \leq b$이면 항상 $f(a) \geq f(b)$이므로 랜선 길이 범위를 정의해서 매개 변수 탐색을 통해 $x$를 찾을 수 있다. 자세한 방법은 주석을 참고하자.

## 관련문제
  - 랜선 자르기    
  https://www.acmicpc.net/problem/1654    
   소스 코드 : [C++](./BOJ/1654.cpp)

  - 공유기 설치    
  https://www.acmicpc.net/problem/2110    
   소스 코드 : [C++](./BOJ/2110.cpp)

  - 공장 컨설턴트 호석    
  https://www.acmicpc.net/problem/22254

  - 휴게소 세우기    
  https://www.acmicpc.net/problem/1477

  - 폭탄제조    
  https://www.acmicpc.net/problem/2977

***
## 삼분 탐색
***
* 내용
## 관련문제
***
* 
***
## 인터랙티브
  *
## 관련문제

***
# Dynamic Programming
## 이론 정리
## 관련 문제
***
# 자료구조
## 이론 정리
## 관련 문제
***

# 브루트포스 알고리즘
## 이론 정리
## 관련 문제
***

