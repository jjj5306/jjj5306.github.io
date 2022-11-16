# Algorithm

# 목차

[개요](#개요)  
[정수론](#정수론)  
[분할정복](#분할정복)  
[Dynamic Programming](#Dynamic-programming)  
[그래프](#그래프)  
[브루트포스 알고리즘](#브루트포스-알고리즘)

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






# Search Tree Ⅱ

## B-tree

- B-트리는 디스크나 다른 보조 기억 장치에서 잘 동작하도록 설계된 균형 잡힌 검색 트리이다.

- 주 기억장치는 보조 기억장치의 연속된 데이터 블록을 페이지 단위로 처리한다. 그런데 이 때 보조 기억장치에 접근하는 시간이 주 기억장치에서 연산을 처리하는 속도에 비해 훨씬 오래걸린다.

- B-트리는 이진 트리와는 다르게 부모가 가질 수 있는 자녀의 수가 **분기**로 제한되어 있다. 이를 통해 트리의 기대 높이를 낮출 수 있다. 이를 통해 보조 기억장치에 접근하는 횟수를 줄일 수 있는데, 예시를 통해 살펴보자.

  - 키를 십억개 이상 저장할 수 있는 1001의 분기 인자와 높이가 2인 B-트리가 있다. 그렇다면 루트를 메인메모리에 항상 상주시키고, 이 트리에서 어떤 키든지 찾는데 두 번의 디스크 접근으로 해당 키의 레코드가 있는 위치를 찾을 수 있다.

## B-트리의 개념

- B-트리는 **다음의 성질들은 만족한다.**

  - 루트를 제외한 모든 노드는 **(floor)(k/2) ~ k**개의 키를 갖는다.

    - `k`개의 키를 가지면, `k+1`개의 자식을 가질 수 있다.

  - 모든 리프 노드는 같은 깊이를 갖는다.

- `k`개의 키에대해 `k+1`개의 자식은 각 키의 사이값을 뜻한다. 즉 `k0`의 왼쪽 자식은 `k0`보다 작고, `k0`의 오른쪽 자식은 `k0`보다 크고 `k1`보다 작다.

- B-트리는 분기의 수를 가능한 늘리되, 각 노드가 채울 수 있는 최대 키 개수의 반 이상의 키는 채우도록 한다.

- B-Tree의 노드는 자신의 **키와 페이지**를 값으로 갖는다. 또 한 레벨에서 `k-1`개의 키, `k`개의 자식, 부모 노드의 페이지 번호의 정보를 갖고, 이를 토대로 최대한 디스크 한 블록이 수용할 수 있는 크기로 `k`값을 결정한다. 아래의 그림은 참고하자.

  ![B_tree_k_select_img](B_tree_k_select_img.png)

  - 예를 들어, `k-1`개의 키에대해, 디스크의 한 블록이 8192바이트, 키가 16바이트, 페이지 번호가 4바이트를 가진다고 가정하자.  
    그렇다면 `4(부모노드의 페이지) + 4(자식 하나의 페이지) + 24 * (k-1)(k-1개의 키에 대한 자식 페이지와 본인 키, 페이지) <= 8192(페이지 최대 바이트)`를 만족하는 가장 큰 `k`값으로 선택하면 된다.

## B-Tree에서의 접근

- 페이지 번호를 가리키는 $p_i$를 통해 접근할 수 있다.

  1. $p_i$는 페이지를 가리키고 있는 포인터이다. 따라서 $p_i$가 가리키는 페이지를 통째로 메인 메모리로 가져온다.

  2. 그 후 해당 레코드를 찾아서 처리한다.

- 기본적으로는 이진 검색 트리와 원리가 같다.  
  B-트리는 최대 `k`개의 키를 가질 수 있으므로 $key_{i-1} < x < key_i$인 두 키를 찾아서 분기할 자식을 구한다. 분기한 후에는 재귀적으로 검색을 수행한다.

## B-Tree에서의 삽입

- 먼저 알고리즘의 대략적인 흐름을 살펴보자. 키 `x`를 삽입한다.

  1. `x`를 삽입할 리프노드 `r`을 찾는다.

  2. 노드 `r`에 삽입할 수 있으면 삽입하고 종료한다.

  3. `r`에 삽입할 수 없다면, 형제 노드를 확인하고 형제 노드에 키를 하나 넘기고 종료한다.

  4. 형제 노드에 여유가 없다면 키를 부모에게 넘기고 노드를 두 개로 분리한다.

  - 이 때 부모 노드에게 넘기는 과정에서 오버플로우가 생기면 부모 노드에 대해 split를 수행하여 재귀적으로 해결한다.

- 위의 내용들에 대한 퍼수도코드를 살펴보자.

  ```C
  BTreeInsert(t, x){
    x를 삽입할 리프 노드 r을 찾는다.;
    x를 r에 삽입한다.;

    if(r에 오버플로우 발생) clearOverflow(r);
  }

  clearOverFlow(r){
    if(r의 형제 중 여유가 있는 노드가 있음) r의 키 하나를 넘긴다.;
    else {
      r을 분할하고 가운데 키를 부모에게 넘긴다.
      if(부모 노드에 오버플로우 발생) clearOverflow(r.p);
    }
  }
  ```

- 그림을 예시로 살펴보자.
  ![B_tree_insertion_img1](B_tree_insertion_img1.png)
  ![B_tree_insertion_img2](B_tree_insertion_img2.png)
  ![B_tree_insertion_img3](B_tree_insertion_img3.png)
  ![B_tree_insertion_img4](B_tree_insertion_img4.png)
  ![B_tree_insertion_img5](B_tree_insertion_img5.png)

## B-Tree에서의 삭제

- 먼저 알고리즘의 대략적인 흐름을 살펴보자. 키 `x`를 삭제한다.

  1. `x`를 찾는다.

  2. `x`가 리프노드가 아니라면 `x`의 직후원소 `y`를 가진 리프노드를 찾아 `x`, `y`를 바꾼다.

  3. 리프노드에서 `x`를 제거한다.

  4. `x`제거 후 언더플로우가 발생하면 재귀적으로 해결한다.

- 위의 내용들에 대한 퍼수도코드를 살펴보자.

  ```C
  BTreeDelete(t, x, v){
    if(v가 리프 노드가 아님){
      x의 직후원소 y를 가진 리프 노드를 찾는다.;
      x와 y를 바꾼다.;
    }
    리프 노드 r에서 x를 제거한다.;
    if(r에서 언더플로우 발생) celanUnderflow(r);
  }

  cleanUnderflow(r){
    if(r의 형제 중 키를 하나 내놓을 수 있는 여유를 가진 노드가 있음) r에게 키 전달;
    else{
      r의 형제 노드와 r에게 영향을 주는 부모를 r쪽으로 병합한다.;
      if(r의 부모 노드에 언더플로우 발생) clearUnderflow(r.p);
    }
  }
  ```

- 그림을 예시로 살펴보자.
  ![B_tree_delete_img1](B_tree_delete_img1.png)
  ![B_tree_delete_img2](B_tree_delete_img2.png)
  ![B_tree_delete_img3](B_tree_delete_img3.png)

## B-tree 분석

- d진 검색 트리가 균형을 아주 잘 맞추면 높이가 $\log _d n$에 근접한다.

- B-tree는 최대 `d`개의 자식을, 최소 `(floor)d/2`개의 자식을 가져야 한다. 따라서 최악의 경우의 높이는 최대 $\log _{(floor)(d/2)} n$ 이다.

- B트리의 작업 수행시간은 디스크의 접근 횟수를 기준으로 한다.

- B트리의 작업 성능은 검색에 **O(log n)** 이 든다.  
  삽입에는 성공하는 경우 상수 시간이, 실패하는 경우 **O(log n)** 이 든다. 삭제도 마찬가지이다.