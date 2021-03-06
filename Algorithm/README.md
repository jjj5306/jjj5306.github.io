# Algorithm

# 목차

[개요](#개요)  
[정수론](#정수론)  
[분할정복](#분할정복)  
[Dynamic Programming](#Dynamic-programming)  
[그래프](#그래프)  
[브루트포스 알고리즘](#브루트포스-알고리즘)

# 개요

- 이 챕터에서는, 내가 아는 기초적인 내용은 기록되지 않을 수 있고 모르는 내용을 중심적으로 정리한다.

- [알고리즘 공부, 어떻게해요?](https://baactree.tistory.com/52)

- 배경지식은 **알고리즘 문제해결전략**책으로 구현력과 문제해결능력은 **백준**에서 늘린다. 그 후 **코드포스**에서 문제해결능력을 집중적으로 높인다.

---

# 정수론

## 약수 찾기

- 어떤 정수 `n`에 대해 그 약수 `a`는 아래의 등식이 성립한다.
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

- 완전수  
  https://www.acmicpc.net/problem/14563  
   소스 코드 : [C++](./BOJ/14563.cpp)

- 소수 찾기  
  https://www.acmicpc.net/problem/1978  
   소스 코드 : [C++](./BOJ/1978.cpp)

---

## 소인수분해

- `약수 찾기`와 같은 알고리즘으로 약수를 찾되, 소인수가 발견되면 `n`을 그 소인수로 나눈다. 이 과정을 소인수가 $\sqrt n$이 될 때 까지 반복하고 마지막으로 `n`이 1보다 크면 그 때의 n 역시 소인수이다.

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

- 소인수분해  
  https://www.acmicpc.net/problem/11653  
   소스 코드 : [C++](./BOJ/11653.cpp)

---

## 에라토스테네스의 체

- $2$이상 $n$이하의 모든 소수를 구하는 알고리즘이다. $2$부터 $\sqrt n$까지 그 수의 모든 배수를 지워내는 알고리즘이다.

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

- 소수가 아닌 수를 지우는 과정에서 그 수를 지울 때 사용한 소인수를 기록한다. 그렇게되면 `i`번째 index의 값이 i이면 소수이다.

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

- 어려운 소인수분해  
   https://www.acmicpc.net/problem/16563  
  소스 코드 : [C++](./BOJ/16563.cpp)

- 수 복원하기  
   https://www.acmicpc.net/problem/2312  
  소스 코드 : [C++](./BOJ/2312.cpp)

- 에라토스테네스의 체  
   https://www.acmicpc.net/problem/2960  
  소스 코드 : [C++](./BOJ/2960.cpp)

- 암호 키  
   https://www.acmicpc.net/problem/1816  
  소스 코드 : [C++](./BOJ/1816.cpp)

- 골드바흐의 추측  
   https://www.acmicpc.net/problem/9020  
  소스 코드 : [C++](./BOJ/9020.cpp)

- 베르트랑 공준  
   https://www.acmicpc.net/problem/4948  
  소스 코드 : [C++](./BOJ/4948.cpp)

- 소수&팰린드롬  
  https://www.acmicpc.net/problem/1747

---

## 모듈러 연산

- 덧셈
  - (a + b)%p = (a%p + b%p)%p
- 뺄셈
  - (a - b)%p = (a%p - b%p + p)%p
- 곱셈
  - (a _ b)%p = ((a%p) _ (b%p))%p
- 나눗셈

  - 곱셈의 **역원**을 정의하여 사용한다.
  - 페르마의 소정리를 이용하면 `모들러 계`에서 $a \cdot a^{p-2} = 1 $이라는 수식을 얻을 수 있고 따라서 $a$의 역원은 $a^{p-2}$이다.
  - **분할 정복을 통한 거듭제곱**을 이용하여 $x^y$를 $MOD$로 나눈 나머지를 구하면 아래의 코드와 같이 구현할 수 있다.

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

---

## 유클리드 호제법

- 최소공약수 `GCD`를 일반적인 방법으로 2부터 두 자연수 중 작은 자연수까지 모두 나누어보면서 구하면 시간복잡도는 `O(N)`이 된다. 하지만 유클리드 호제법을 이용하면 시간복잡도를 `O(logN)`으로 줄일 수 있다.
- 2개의 자연수 A, B에 대해서 A와 B의 최대공약수는 B와 A % B 의 최대공약수와 같다. 정리하자면 아래와 같다.
  $$
    GCD(A, B) = GCD(B, A \% B)
  $$
  $$
    if A \% B = 0 \Rightarrow GCD = B
  $$
  $$
    else GCD(B, A\%B)
  $$

---

## 오일러 파이 함수

- $a^{\phi(n)} = 1$ $mod \ n$을 만족하는 $\phi(n)$ 을 \*_오일러 파이 함수`라고 하고_ 이는 $1$부터 $n$까지 $n$과 서로소인 수들의 개수이다.

- $p$가 소수이면 $\phi(p) = p-1$이다.

- $\phi(m)\phi(n) = \phi(mn)$의 곱셈적성질을 만족한다.

## 오일러 파이 함수의 계산

- $p$가 소수일 때 $\phi(p^k)$의 값을 보자. $p$가 소수이므로 $p^k$와 서로소가 아닌 수들은 반드시 $p$를 인수로 가져야 한다. 이런 수들은 $p^{k-1}$개가 있다. 따라서

  $$
  \phi(p^k) = p^k - p^{k-1}
  $$

  $\;\;\;\;\;\;\;\;\;\,$라는 결론을 얻는다.

- 위의 결론에서 모든 수를 소수의 곱으로 소인수분해 한 뒤 오일러 파이 함수가 곱셈적 함수임을 이용해서 계산할 수 있다. 아래의 `GCD(n, k) = 1` 문제의 주석을 잘 참고하면 이해하기 쉽다.  
  $\phi(a) = pie(p_1^{k_1}p_2^{k_2}\cdot\cdot\cdot p_n^{k_n})$

$\;\;\;\;\;\;\;\;\,\;\;\;\;\;\;\;\;= p_1^{k_1}(1 - \frac 1 {p^1})p_2^{k_2}(1 - \frac 1 {p^2})\cdot\cdot\cdot p_n^{k_n}(1 - \frac 1 {p^n})$

$\;\;\;\;\;\;\;\;\,\;\;\;\;\;\;\;\; = a(1 - \frac 1 {p^1})(1 - \frac 1 {p^2})\cdot\cdot\cdot (1 - \frac 1 {p^n}) $

## 관련문제

- GCD(n, k) = 1  
  https://www.acmicpc.net/problem/11689  
  소스 코드 : [C++](./BOJ/11689.cpp)

---

# 분할정복

## 매개 변수 탐색

- 최적화 문제를 결정 문제로 변형하는 이분 탐색 기법이다.
- 예를 들어 모든 구간에서 증가하는 함수 $f(x)$가 있다고 가정하자.

  - 최적화 문제 : $f(x) \geq t$인 가장 작은 정수 $x$를 구하라.

  이 문제를 풀려면 모든 $x$에 대해 확인해보는 방법을 가장 간단하게 떠올릴 수 있다. 그런데 이 최적화 문제를 **매개 변수 탐색**을 통해 결정 문제로 변형할 수 있다.

  - 결정 문제 : 어떤 정수 $x$에 대해 $f(x) \geq t$인가?

  이 문제는 훨씬 간단하고, $f(x)$는 모든 구간에서 증가한다. 따라서

  - $f(a) \geq t$이면 $a \leq b$인 모든 $b$에 대해 $f(b) \geq t$이다.

    - 이 때 $a$보다 큰 모든 정수 $b$는 가장 작은 정수 해 $x$가 될 수 없다.

  - 비슷하게 $f(a) \leq t$인 경우에도 $b \lt a $인 모든 $b$에 대해 $f(b) \lt t$이므로 $a$보다 작은 모든 정수는 $x$가 될 수 없다.

- 최적화 문제를 만났다면 $f(x)$를 설정할 수 있을지 생각해보자. 또 그 함수가 모든 구간에서 증가하거나 감소하는 경향을 보인다면 그 문제는 매개 변수 탐색을 활용할 수 있을 가능성이 높다. 매개 변수 탐색을 활용해야겠다는 생각이 들면 그 함수를 통해 답의 범위를 설정하고 범위의 중간값에 대해 답이 되는지 조사하면서 범위의 크기가 1이 될때까지 줄여나가자.

## 예시문제: 랜선 자르기

- 랜선을 $n$개 이상 만들 수 있는 가장 짧은 정수 길이 $x$를 찾는 문제이다.

  - $f(a)$: 단위 길이 $a$로 랜선을 자를 때 만들 수 있는 랜선 개수

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
   소스 코드 : [C++](./BOJ/22254.cpp)

- 휴게소 세우기  
  https://www.acmicpc.net/problem/1477  
   소스 코드 : [C++](./BOJ/1477.cpp)

- 폭탄제조  
  https://www.acmicpc.net/problem/2977

---

## 삼분 탐색

- **Unimodal**한 함수의 극대점을 찾는 방법이다. Unimodal이란 극대(소)점 하나를 중심으로 극대점보다 작은 구간에서 단조 증가하고 극대점보다 큰 구간에서 단조 감소하는 함수를 말한다.

- 삼분 탐색에서는 구간$[l, r]$을 셋으로 나눈 중간 지점들 $a = \frac {2l+r} 3$과 $b = \frac {l+2r} 3$를 잡고 $f(a)$와 $f(b)$를 비교한다.

  - $f(a) > f(b)$이면 극값은 b보다 왼쪽에 존재한다.

  - $f(a) < f(b)$이면 극값은 a보다 오른쪽에 존재한다.

  위의 조건들을 이용하면서 구간의 크기를 $2/3$로 줄여나갈 수 있다.

- 극대점이 유일하지 않고 기울기가 0인 극대 구간이 존재하는 함수가 주어질 수 있다.

  - 이 때는 삼분 탐색을 수행하면 극대 구간 중 한 점을 결과로 얻게된다.

  - 극대 구간 전체를 알려면 삼분 탐색을 통해 극대 구간의 한 점을 얻고 매개 변수 탐색으로 왼쪽 끝과 오른쪽 끝을 찾으면 된다.

## 관련문제

- 전봇대  
  https://www.acmicpc.net/problem/8986  
   소스 코드 : [C++](./BOJ/8986.cpp)

- 선분과 점  
  https://www.acmicpc.net/problem/11664  
   소스 코드 : [C++](./BOJ/11664.cpp)

- 민호와 강호  
  https://www.acmicpc.net/problem/11662  
   소스 코드 : [C++](./BOJ/11662.cpp)

---

# Dynamic Programming

## 동적 계획법

- 작은 문제의 해법을 큰 문제를 푸는 데에 이용하는 최적화 방법이다.

- 피보나치 수 구하기를 재귀함수로 구현해보자.

  ```
  int F(int x){
    if (x == 0) return 0;
    if (x == 1) return 1;
    else return F(x - 1) + F(x - 2);
  }
  ```

  - 이 코드는 $x = 40$정도로 커지면 답을 구하기 버겁다. 그 이유는 $F(x)$를 구할 때 $F$를 더 이상 쪼갤 수 없을 때 까지 $F(1)$을 호출하면서 수행 시간 또한 지수함수로 커지기 때문이다.

  - $F(5)$를 구한다고 가정해보자.  
    $F(5) = F(4) + F(3)$ 이다. 그런데 이 때 $F(4)$를 구할 때 $F(3)$이 또 사용된다. 이런식으로 모두 살펴보면 $F(2)$는 세 번, $F(1)$은 다섯 번이나 호출된다.

  - $F(x)$는 같은 $x$에 대해 언제 실행해도 같은 결과가 나온다. 따라서 아래의 코드와 같이 이미 구한 값을 캐시에 저장하고 다시 가져오자.

    ```
     #include<iostream>

     using namespace std;

      const int C_SIZE = 100;
     long long cache[C_SIZE];

     long long F(int x) {
         if (cache[x] != -1) return cache[x];

         if (x == 0) return cache[x] = 0;
         if (x == 1) return cache[x] = 1;
         else return cache[x] = F(x - 1) + F(x - 2);
     }

     int main() {
         for (int i = 0; i < C_SIZE; i++) cache[i] = -1;

         int x;
         cin >> x;
         cout << F(x);
     }
    ```

  - 위 코드로 $F(5)$를 구하면 함수의 호출 회수가 훨씬 줄어든 것을 확인할 수 있다.

  - 반복문을 이용해서 브루트포스 알고리즘 처럼 점화식대로 캐시 배열을 앞에서부터 채워나가도 된다.

    ```
      #include <iostream>
      #include <vector>
      using namespace std;

      int main(){
        int n;
        cin >> n;

        vector <long long> f(n+1);
        f[0] = 0;
        f[1] = 1;

        for(int i = 2; i <= n; i++)
          f[i] = f[i - 1] + f[i - 2];

        cout << f[n];
      }
    ```

- DP의 특성

  - 작은 부분 문제를 큰 문제를 해결할 때 사용한다. 따라서 **부분 문제가 중복**되는 경우 DP를 사용할 수 있다.

  - 위의 예시에서 캐시에 저장해놓고 나중에 사용하는 방법인 **메모이제이션**을 통해 계산 횟수를 크게 줄일 수 있다.

  - 어떤 부분 해($F(x)$)를 구하는 과정이 유일하고 다시 계산해도 변하지 않아야한다. 즉 **최적 부분 구조**를 가져야한다.

  - 문제의 해답을 **점화식**으로 표현할 수 있고, 그 점화식이 순환 참조하지 않아야 한다.

  - DP의 경우 많은 문제들을 다뤄보면서 익숙해지는 것이 중요하다.

---

## LIS

- **Longest lncreasing Subsequence**는 어떤 수열 $A$에서 가장 긴 증가하는 부분 수열을 구하는 문제이다. DP의 가장 대표적인 문제 중 하나이고 유사한 풀이를 적용할 수 있는 문제들이 많아서 공부해두면 좋다.

- DP를 사용하지 않고 각 원소를 최장 증가 수열에 포함하거나 하지 않는 경우를 모두 확인하면 $O(2^n)$이 걸린다.

- DP를 사용하여 $A[i]$를 마지막 원소로 가지는 가장 긴 부분수열의 길이를 구하여 배열 $B[i]$에 저장한다.

  - $A = [1, 5, 3, 4, 2, 6]$와 같은 수열이 있다고 가정하자.

  - $B[1] = 1$이고 $B[2]$부터는 기존에 증가하는 부분 수열들에 $A[i]$를 이어붙여 만들 수 있다.

  - 즉 $B[i]$는 $A[i] \gt A[j]$ 이면 $B[j] + 1$로, 아니라면 1로 설정하면서 $j$의 값을 $i부터 i-1$까지 늘려간다. 그 때 각 $j$에 따른 $B[i]$값 중 제일 큰 값이 $B[i]$이다.

  - $B = [1, 2, 2, 3, 2, 4]$이고 수열 $B$의 최대값이 최장 증가 수열의 길이가 된다. $i$에 대해 $j$를 모두 확인해야 하기에 시간 복잡도는 $O(n^2)$이다.

- DP를 통해 찾은 답을 출력해야 하는 경우가 있다. 위의 방법은 LIS의 길이는 구할 수 있지만 구체적인 경로는 알 수 없다. 경로를 **역추적**하는 방법을 알아보자.

  - 역추적 배열 $F$를 정의한다. 역추적 배열은 LIS를 만들 때 바로 이전 원소가 어디에 있었는지 저장한다.

  - $F[i]$는 $B[i] \gt 1$인 경우 즉 $A[i]$를 마지막 원소로하는 증가 부분 수열을 만들 때 $A[i]$가 어떤 부분 수열 뒤에 붙을 수 있는 경우에는 $B[i]$를 구할 때 참조한 이전 위치로 만들고 아니라면 -1로 만든다.

  - 수열 $B$의 최대값을 찾는다. 최대값의 index를 $x$라 하자. $i = x$라고 놓고 아래를 반복 시행한다.

    - $A[i]$를 최장 증가 수열의 마지막 원소로 저장한다.

    - $F[i]$에는 이전 원소의 위치가 저장되어 있으므로 $i = F[i]$를 수행한다.

    - 만약 $F[i] = -1$이면 $A[i]$는 최장 증가 수열의 첫 번째 원소이다. 따라서 루프를 종료한다.

  - 위의 과정을 거쳐 얻은 값들의 순서를 뒤집으면 최장 증가 수열을 얻을 수 있다.

- 길이별 배열로 변환

  - 위의 $O(n^2)$ 알고리즘에서 $B[i]$를 구할 때의 과정을 살펴보자.

  - $A = [1, 5, 3, 4, 2, 6]$의 배열에서 $B[4]$를 구하는 과정을 살펴보자. $A[2] = 5$이고, 이는 $A[4]$보다 크므로 무시한다. $A[3] = 3$이고, 이는 $A[4]$보다 작으므로 $A[3]$뒤에 $A[4]$를 붙일 수 있다.

  - 이 때 잘 보면 $A[2]$ 뒤에 다음 원소를 붙이면 ${1, 5, x}$이 되고 $A[3]$ 뒤에 붙이면 ${1, 3, x}$가 된다. $x$뒤에 어떤 원소가 얼마나 오던 $A[3]$뒤에 원소를 붙이는 것이 더 긴 LIS를 만들 수 있다.

  - 일반화하면 $B[i] = B[j]$이고 $A[i] \lt A[j]$이면, 새로운 원소를 $A[i]$ 뒤에 붙이는 경우만 따지면 된다. 따라서 $B[i]$가 같은 원소들에 대해 $A[i]$가 가장 작은 것들만 남겨도 된다.

  - 위의 특성을 통해 $i = 1$부터 지금까지 발견된 가장 긴 증가 수열 길이까지 $C[i]$는 $B[j] = i$인 $j$에 대해 $A[j]$중 최솟값이라고 정의하자.

  - 수열 $A, B$를 4번째 원소까지 처리한 후 수열 $C = [1, 3, 4]$이다. 여기서 나머지 원소들도 처리해보자.

    - $A[5] = 2$. 이는 C[1]보다 크기에 최대 길이가 2인 증가 수열을 만들 수 있다. 따라서 $C[2]를 갱신한다. 그러나 $C[2]$보다 작기 때문에 $C[2]$이후의 원소를 갱신할 수 없다.

    - $A[6] = 6$. 이는 $C$의 모든 원소들 보다 크다. 따라서 $C[4] = 6$을 추가한다. 그러면 $C = [1, 2, 4, 6]$이고 LIS의 길이는 4이다.

- 이분 탐색을 통한 $O(n\;log\,n)$ DP

  - 위에서 만든 **길이별 최적 해 배열** $C$는 **단조 증가**하고 원소를 갱신할 때 **하나씩만** 갱신한다는 특성이 있다.

  - 위의 두 특성을 이용해서 $A$의 어떤 원소 $x$를 $C$에 배치할 때 **이분 탐색**을 통해 매번 $O(log\,n)$으로 배치할 위치를 결정할 수 있다. 이 작업을 반복하면 $O(n\;log\,n)$만에 LIS를 구할 수 있다.

  - $A$의 원소들을 차례로 살펴보면서 판단하자.

    - $C$에 $A[i]$이상인 값이 있다면 $C$에서 그 위치를 $A[i]$로 대체하자.

    - 없다면 $C$의 끝에 $A[i]$를 넣는다.

  - 위의 과정들을 반복한 뒤 $C$의 크기가 LIS의 길이이다.

## 관련 문제

- 피보나치 수 5  
  https://www.acmicpc.net/problem/10870  
   소스 코드 : [C++](./BOJ/2747.cpp)

- 피보나치 수  
  https://www.acmicpc.net/problem/2747  
   소스 코드 : [C++](./BOJ/2747.cpp)

- 피보나치 수 2  
  https://www.acmicpc.net/problem/2748  
   소스 코드 : [C++](./BOJ/2747.cpp)

- 가장 긴 증가하는 부분 수열  
  https://www.acmicpc.net/problem/11053  
   소스 코드 : [C++](./BOJ/11053.cpp)

- 가장 긴 증가하는 부분 수열 4  
  https://www.acmicpc.net/problem/14002  
   소스 코드 : [C++](./BOJ/14002.cpp)

- 가장 긴 증가하는 부분 수열 2  
  https://www.acmicpc.net/problem/12015  
   소스 코드 : [C++](./BOJ/12015.cpp)

- 신나는 함수 실행  
  https://www.acmicpc.net/problem/9184  
   소스 코드 : [C++](./BOJ/9184.cpp)

- 정수 삼각형  
  https://www.acmicpc.net/problem/1932  
   소스 코드 : [C++](./BOJ/1932.cpp)

- 연속합  
  https://www.acmicpc.net/problem/1912  
   소스 코드 : [C++](./BOJ/1912.cpp)

- 구간 합 구하기 4  
  https://www.acmicpc.net/problem/11659  
   소스 코드 : [C++](./BOJ/11659.cpp)

- 구간 합 구하기 5  
  https://www.acmicpc.net/problem/11660  
   소스 코드 : [C++](./BOJ/11660.cpp)

- 1로 만들기  
  https://www.acmicpc.net/problem/1463  
   소스 코드 : [C++](./BOJ/1463.cpp)

- 1로 만들기 2  
  https://www.acmicpc.net/problem/12852  
   소스 코드 : [C++](./BOJ/12852.cpp)

- LCS  
  https://www.acmicpc.net/problem/9251  
   소스 코드 : [C++](./BOJ/9251.cpp)

---

# 그래프

## 그래프 기초

- **연결 그래프**란 모든 간선에서 다른 모든 간선으로 가는 경로가 존재하는 그래프이다.

- 그래프의 탐색은 `DFS`나 `BFS`를 사용한다.

- **DFS 깊이 우선 탐색**

  - 먼저 방문한 정점에 다른 노드가 연결되어있으면 그 정점을 바로 탐색한다.

  - 스택에 방문한 노드를 넣고, 다른 연결된 노드가 있으면 그 노드를 방문하면서 스택에 넣는다. 다른 연결된 노드가 없다면, **스택에 있는 이전 정점으로 돌아간다.**

  - 보통 DFS가 BFS보다 약간 더 빠르다.

- **BFS 너비 우선 탐색**

  - 방문하는 정점에서 연결된 노드들을 큐에 넣는다. 큐에 있는 내용들을 차례로 방문하면서 연결된 노드들을 큐에 넣는것을 반복한다.

  - 최단 경로를 탐색할 때 사용한다.

## 관련 문제

- 바이러스  
  https://www.acmicpc.net/problem/2606  
   소스 코드 : [C++](./BOJ/1463.cpp)
