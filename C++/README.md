# Range based for

- 알아서 데이터 리스트를 순회할 수 있다.

  ```
  for (데이터 타입 elem : 데이터 리스트){
      elem을 이용한 모든 구문
  }
  ```

- range based for는 index정보가 존재하지 않는다. 단, index의 value의 정보는 존재한다.

- 자동으로 `elem`에 arr의 원소들이 복사되기 때문에 기본적으로 배열의 요소를 변경할 수 없다.
  ```
  for(int elem : v){
      elem += 100;
      cout << elem << " ";
  }
  ```
- range based for를 reference를 이용하여 복사 비용도 줄이고 배열의 원래 값을 변경할 수 있다.

  ```
  for(int& elem : arr){
      elem += 1;
  }
  ```

- `const`와 `reference`또한 함께 사용 가능 하다.
  ```
  for(const int& elem : arr){
      elem += 1;
  }
  ```
  위의 코드에서는 `elem`의 값을 변경하려 했기에 컴파일 에러가 뜬다.

---

# Auto

- 초깃값의 형식에 맞춰 인스턴스의 형식을 자동으로 결정한다.

  ```
  auto d = 5.0;
  auto i = 1 + 2;
  ```

- 함수 매개 변수와 함께 사용할 수 없다.

  ```
  void add(auto x, auto y){
      std::cout << x + y;
  }
  ```

  위 코드는 작동하지 않는다.

- `iterator`로 작동할 수 있다.

- `const`, `&`, `*`와 함께 사용할 수 있다.

  ```
  for(auto it = v.begin(); it != v.end(); ++it)
    *it *= 2;
  ```

- `range based for`에도 `const`, `&`와 함께 사용할 수 있다.

  ```
  for(const auto elem : v){

  }
  ```

---

# STL Container

## Vector

- Vector declaration

  - `vector<자료형> 변수명(숫자1, 숫자2)`과 같이 초기화하며 숫자1만큼 벡터를 생성 후 숫자2로 초기화한다.

  - `vector<자료형> 변수명[] = {, }`과 같이 2차원 벡터를 선언한다. 이 때 열은 고정이고 행은 변할 수 있다.

  - `vector<vector<자료형>> 변수명`과 같이 2차원 벡터를 선언할 수 있고 이 경우는 열과 행 모두 가변하다.

- Vecotr Iterators

  - `v.begin()` : 벡터 시작점의 주소 값을 반환한다.

  - `v.end()` : 벡터 벡터의 마지막 원소의 주소값을 반환한다.

  - `v.at(i)` : 벡터의 `i`번째 요소에 접근한다. 이 때 범위를 검사한다.

  - `v[i]` : 벡터의 `i`번째 요소에 접근하며 이 때 범위는 검사하지 않는다.

  - `v.front()` : 벡터의 첫 번째 값을 리턴한다.

  - `v.back()` : 벡터의 마지막 값을 리턴한다.

- Vector Element insert/erase

  - `v.push_back()` : 벡터의 복사생성자를 호출하여 새로운 메모리에 모든 값을 복사한 후 마지막에 새로운 요소를 추가한다.

  - `v.pop_back()` : 벡터의 마지막 원소를 제거한다.

  - `v.insert(삽입할 위치의 주소 값, 값)` : 삽입할 위치의 주소에 값을 삽입한다. 이 때도 `push_back()`과 같이 복사생성자를 호출한다.

  - `v.emplace(삽입할 위치의 주소 값, 값)` : `insert()`와 같은 역할을 하지만 복사생성자를 호출하지 않고 벡터 내부에서 값을 생성한다.

  - `v.emplace_back()` : `push_back()`과 같은 역할을 하지만 복사생성자를 호출하지 않는다.

  - `v.erase(index)` : `index`의 요소를 제거한다.

  - `v.erase(시작위치, 끝위치)` : 시작위치부터 끝위치까지의 요소들을 제거한다.

  - `v.clear()` : 벡터의 모든 요소를 지우고 벡터의 크기를 0으로 만든다.

- Vector Capacity

  - vector의 크기는 `size`와 `capacity` 두 개가 있는데, `size`는 벡터가 생성된 크기이며 `capacity`는 벡터의 최대 할당 크기이다.

  - `push`연산을 통해 벡터의 `size`가 `capacity`를 초과하면 `reallocate`가 발생하여 모든 값들을 새로운 메모리에 복사하는 과정이 일어난다. 이 과정에서 속도 저하가 일어나며 `capacity`를 설정해주는 함수들을 이용하여 `reallocate`를 막을 수 있다.

  - `clear()`로 벡터의 값들을 지우면 벡터의 요소들은 없어지지만 `capacity`는 여전히 남아있다. 따라서 `swap`을 이용하여 `capacity`또한 제거해줘야 한다.

    ```
    vector<int> v = {1, 2, 3, 4};
    v.clear();

    vector<int>().swap(v);
    ```

    이렇게 하면 아무것도 없는 벡터공간과 `swap`이 일어나 `capacity`를 없앨 수 있다.

  - `insert()`와 `erase`가 빈번히 일어나는 경우 벡터의 데이터를 하나하나 일일이 이동시킨 후 삽입/ 삭제가 일어나고 `reallocate` 또한 일어날 수 있어서 삽입과 삭제가 빈번한 경우 `list`나 `deque`를 사용하는 것이 낫다.

  - `v.empty()` : 벡터가 빈 공간이면 `true`를 아니라면 `flase`를 리턴한다.

  - `v.size()` : 벡터의 size를 리턴한다.

  - `v.capacity()` : 메모리 heap에 할당된 벡터의 최대크기를 반환한다.

  - `v.shrink_to_fit()` : `capacity`의 크기를 벡터의 실제 크기로 맞춘다.

---

## Deque

- `vector`의 경우 `size`가 `capacity`를 초과하는 경우 `reallocate`가 발생한다는 단점이 있었다. 하지만 `deque`에서는 여러 개의 메모리 블록을 할당하고 이들을 하나의 블록처럼 사용한다. 따라서 메모리가 부족하면 새로운 메모리 블록을 할당하여 `vector`의 단점을 보완하였다.

- `vector`과 같은 방식으로 초기화한다.

- `dq.assign(a, b)` : `b`를 `a`개 만큼 할당한다.

- `dq.push_front(value)` : deque의 제일 앞에 `value`를 삽입한다.

- `dq.pop_front()` : deque의 제일 앞의 원소를 제거한다.

- 나머지 메소드들은 `vector`과 비슷하게 작동한다.

---

## Stack

- `LIFO(Last In First Out)` 속성을 가진 자료구조이다. 책 쌓기처럼 가장 마지막에 `push`된 데이터가 `pop`된다.

- `front`에서 `push`, `pop` 모두 일어나며 `vector`과 비슷한 메서드를 사용한다.

---

## Queue

- `FIFO(First In First Out)` 속성을 가진 자료구조이다. 줄 서기처럼 먼저 `push`된 데이터가 `pop`된다.

- `front`에서 `pop`, `back`에서 `push`가 일어나며 `vector`과 비슷한 메서드를 사용한다.

---

## Priority_queue

- Priority_queue는 들어간 순서에 상관없이 우선순위가 높은 데이터가 먼저 나오는 자료구조이다.

- `priority_queue<자료형, container, compare>`로 정의한다.

- `container`는 디폴트로 `vector`을 사용한다. `deque`로 사용할 수 있다.

- `compare`는 디폴트로 `less`를 사용하며 이는 내림차순을 뜻한다. `greater`을 통해 오름차순으로 변경할 수 있다.

- `priority_queue<T, vector<T>, compare> pq;`와 같이 많이 사용하며 `T`는 구조체를 의미한다. 예를 들어 좌표계를 뜻하는 `coo` 구조체가 있다고 생각해보자.

  ```
  typedef struct coo{
    int x, y;
  }
  ```

  이 때 새로운 `compare`을 사용하기 위해 `compare` 구조체를 만들고 그 구조체에 대해 `()`연산자가 비교 연산자로 작용하게끔 만들자.

  ```
  typedef struct compare{
    bool operator()(coo &I, coo &C){
      if(I.x != C.x) return I.x < C.x;
      return I.y < C.y;
    }
  }
  ```

  이제 `compare`구조체에서 `()`연산자를 사용하면 `coo`구조체의 비교가 가능하다. 따라서 `priority_queue <coo, vector<coo>, compare> pq;`와 같이 사용할 수 있다.

- 나머지 메서드들은 `vector`과 비슷한 메서드를 사용하고 있다.

---

## Pair

- 두 객체를 하나의 객체로 묶어주는 클래스이다.

- `<utility>` 헤더에 존재한다.

- `pair<[type1], [type2]> p`와 같이 사용한다.

- `p.first` : pair의 `type1` 인자를 리턴한다.

- `p.second` : pair의 `type2` 인자를 리턴한다.

- `make_pair(변수1, 변수2)` : 변수1과 변수2가 들어간 pair를 만든다.

- pair 안에 `type`을 pair로 설정하여 여러 개를 묶을 수 있다.

---

## List

- 이중 연결 리스트이다.

- `at`이나 `[]`가 아닌 `iterator`을 통해서 `++`, `--`연산을 통해 원소를 접근한다.

- `lt.assing(a, b)` : `b`로 초기화된 `a`개의 list를 생성한다.

- `lt.insert(iter, k)` : `iter`가 가리키는 위치에 원소 `k`를 삽입한다.

- `lt.erase(iter)` : `iter`가 가리키는 원소를 삭제한다.

- `lt.remove(k)` : `k`와 같은 원소를 모두 삭제한다.

- `lt.remove_if(Predicate)` : 조건자에 해당하는 원소를 모두 제거한다.

- `lt.srot()` : `iterator`로 범위를 지정하여 오름차순으로 정렬한다. 비교자 함수를 정의하여 세 번째 인자로 사용할 수 있다. 이 경우 콜백함수와 비슷하게 사용하며 연산자 재정의를 통해 이루어진다.

  ```
  struct _RANKING_INFO_ {
    int  score;
    char strUserName[32];
                  bool operator<  ( const _RANKING_INFO_& rhs ) const
                  {
                       return score < rhs.score;
                   }
  };

  bool RankComp( const _RANKING_INFO_& lhs, const _RANKING_INFO_& rhs )
  {
      return lhs.score < rhs.score;   //오름차순 정렬
  };
  ```

  위의 예시로 보자면 구조체 `_RANKING_INFO_`에 대해 `<` 연산자를 재정의한대로 작동하게 만들고 `RankComp`함수에서 재정의한 연산자를 사용하게 한다. 이 함수를 `sort`의 세 번째 인자로 사용하면 사용자 정의 비교자를 통해 `sort`할 수 있다.

- `lt2.splice(iter, lt1)` : `lt2`에서 `iter`이 가리키는 곳에 `lt1`의 모든 원소를 잘라 붙인다.

- `lt2.splice(iter2, lt1, iter1)` : `lt2`에서 `iter2`가 가리키는 곳에 `lt1`의 `iter1`이 가리키는 원소를 잘라 붙인다. 이 때 네 번째 `iterator` 인자를 추가해서 `lt1`의 원소를 범위로 지정할 수 있다.

- `lt.merge(lt1)` : `lt1`을 `lt2`내부로 `merge sort`한다. 기본은 오름차순이고 두 번째 인자로 `sort`와 비슷하게 사용자 정의 비교자를 지정할 수 있다.

---

## Map

- `key` - `value`로 구성된 `balanced-binary-tree`이다.

- `key`와 `value`는 `pair` 객체 형태로 저장된다.

- `key`의 중복은 허용되지 않는다. `multimap`의 경우 중복 `key`를 허용한다.

- 삽입되면서 자동으로 정렬된다. 디폴트로 오름차순이다.

- `map<key type, value type> 변수이름(pred)`로 선언한다. 이 때 `pred`에 `less`를 주면 오름차순으로, `greater`을 주면 내림차순으로 정렬한다.

- 연산자 `[]`를 사용하여 원소를 추가, 수정이 가능하다.

  ```
  m[key] = val;
  ```

  `[]`를 사용하여 원소를 추가하는 경우 value가 새로 만들어진건지, 기존 값이 변경된건지 구분할 수 없다.

- `m.insert({1, 2})`와 같이 원소를 삽입할 수 있다.

  - 이 때 리턴값으로 `pair`을 반환한다.
  - 삽입 성공 시 첫 번째 `iterator`는 insert되어진 element의 iterator를 반환하고 두 번째 `iterator`는 true를 반환한다.

  - 삽입 실패 시 첫 번째 `iterator`는 중복된 key의 element의 iterator를 반환하고 두 번째 `iterator`는 false를 반환한다.

  - 이를 이용하여 삽입의 성공, 실패를 구분할 수 있다.

  - `m.insert(pair<int, int>(1, 2))`와 같이 insert할 수도있다.

- `m.count(k)` : 원소 `k`의 개수를 반환하며 주로 `multimap`에서 쓰인다.

- `m.erase(iter)` : `iter`이 가리키는 원소를 제거하고 다음 원소를 가리키는 iterator를 리턴한다.

- `m.find(k)` : `k`와 같은 `key`를 가진 원소의 iterator를 리턴한다. 존재하지 않는 경우 `end()`를 리턴한다.

- `m.upper_bound(k)` : `k`보다 큰 `key`들 중 가장 왼쪽에 있는 원소의 iterator를 리턴한다.

- `m.lower_bound(k)` : `k`보다 작은 `key`들 중 가장 오른쪽에 있는 원소의 iterator를 리턴한다.

- `m.equal_range(k)` : `first`로 `upper_bound(k)`를 `second`로 `lower_bound(k)`를 리턴한다.

---

## Set

- `map`과 거의 똑같지만 `value`는 존재하지 않고 `key`만 존재하는 `balanced-binary-tree`이다.

- `map`과 똑같은 메서드를 가진다.

---

## Set, Map에 구조체 및 객체 저장

- `set`과 `map`은 `balanced-binary-tree`이다. 따라서 `key`값은 대소비교가 가능해야한다.

- 클래스나 구조체 내부에 `operator<`를 재정의 하여 구조체 및 객체를 비교 가능하게 정의하면 `set`, `map`에 구조체 및 객체를 저장할 수 있다.

```
class Human
{
private:
    int age;
    int height;
public:
    Human(int _age, int _height) : age(_age), height(_height){}
    bool operator<(const Human& rhs) const    //이게 핵심!
    {
        if (age != rhs.age)
        {
            return age < rhs.age;
        }

        return height < rhs.height;
    }
};
```

- 비교 전용 구조체를 만들어 `()`연산자를 오버로딩하여 `set`, `map`에 넣을 구조체의 비교 기준을 정의한다. 그리고 `set` 사용 시 두 번째 파라미터로, `map`은 세 번째 파라미터로 비교 전용 구조체를 넘겨준다.

  ```
  struct Student {
    string name;
    int grade;
  };

  struct cmp {
    bool operator () (const Student& stu1, const Student& stu2) const {
        if (stu1.name == stu2.name)
            return stu1.grade < stu2.grade;
        return stu1.name < stu2.name;
    }
  };

  int main()
  {
    set<Student, cmp> students;

    students.insert({ "ryan", 5 });
    students.insert({ "muzi", 3 });
    students.insert({ "muzi", 1 });
    students.insert({ "apeach", 1 });
    students.insert({ "apeach", 1 });

    for (auto& stu : students)
        cout << stu.name << " : " << stu.grade << endl;
  }
  ```
