# range based for
* 알아서 데이터 리스트를 순회할 수 있다.
  ```
  for (데이터 타입 elem : 데이터 리스트){
      elem을 이용한 모든 구문
  }
  ```

* `range based for`는 `index`정보가 존재하지 않는다. 단, `index`의 `value`의 정보는 존재한다.

* 자동으로 `elem`에 `arr`의 원소들이 복사되기 때문에 기본적으로 배열의 요소를 변경할 수 없다.
  ```
  for(int elem : v){
      elem += 100;
      cout << elem << " ";
  }
  ```
  
* `range based for`를 `reference`를 이용하여 복사 비용도 줄이고 배열의 원래 값을 변경할 수 있다.
  ```
  for(int& elem : arr){
      elem += 1;
  }
  ```

* `const`와 `reference`또한 함께 사용 가능 하다.
  ```
  for(const int& elem : arr){
      elem += 1;
  }
  ```
  위의 코드에서는 `elem`의 값을 변경하려 했기에 컴파일 에러가 뜬다.
***
# Auto
* 초깃값의 형식에 맞춰 인스턴스의 형식을 자동으로 결정한다.
  ```
  auto d = 5.0;
  auto i = 1 + 2;
  ```

* 함수 매개 변수와 함께 사용할 수 없다.
  ```
  void add(auto x, auto y){
      std::cout << x + y;
  }
  ```
  위 코드는 작동하지 않는다.

* `iterator`로 작동할 수 있다.

* `const`, `&`, `*`와 함께 사용할 수 있다.
  ```
  for(auto it = v.begin(); it != v.end(); ++it)
    *it *= 2;
  ```

* `range based for`에도 `const`, `&`와 함께 사용할 수 있다.
  ```
  for(const auto elem : v){

  }
  ```
***
# STL Container
## Vector
* `Vector declaration`
  * `vector<자료형> 변수면(숫자1, 숫자2)`과 같이 초기화하며 숫자1만큼 벡터를 생성 후 숫자2로 초기화한다.

  * `vector<자료형> 변수명[] = {, }`과 같이 2차원 벡터를 선언한다. 이 때 열은 고정이고 행은 변할 수 있다.

  * `vector<vector<자료형>> 변수명`과 같이 2차원 벡터를 선언할 수 있고 이 경우는 열과 행 모두 가변하다.

* `Vecotr Iterators`
  * `v.begin()` : 벡터 시작점의 주소 값을 반환한다.

  * `v.end()` : 벡터 벡터의 마지막 원소의 주소값을 반환한다.

  * `v.at(i)` : 벡터의 `i`번째 요소에 접근한다. 이 때 범위를 검사한다.

  * `v[i]` : 벡터의 `i`번째 요소에 접근하며 이 때 범위는 검사하지 않는다.

  * `v.front()` : 벡터의 첫 번째 값을 리턴한다.

  * `v.back()` : 벡터의 마지막 값을 리턴한다.

* `Vector Element insert/erase`
  * `v.push_back()` : 벡터의 복사생성자를 호출하여 새로운 메모리에 모든 값을 복사한 후 마지막에 새로운 요소를 추가한다.

  * `v.pop_back()` : 벡터의 마지막 원소를 제거한다.

  * `v.insert(삽입할 위치의 주소 값, 값)` : 삽입할 위치의 주소에 값을 삽입한다. 이 때도 `push_back()`과 같이 복사생성자를 호출한다.

  * `v.emplace(삽입할 위치의 주소 값, 값)` : `insert()`와 같은 역할을 하지만 복사생성자를 호출하지 않고 벡터 내부에서 값을 생성한다.

  * `v.emplace_back()` : `push_back()`과 같은 역할을 하지만 복사생성자를 호출하지 않는다.

  * `v.erase(index)` : `index`의 요소를 제거한다.

  * `v.erase(시작위치, 끝위치)` : 시작위치부터 끝위치까지의 요소들을 제거한다.

  * `v.clear()` : 벡터의 모든 요소를 지우고 벡터의 크기를 0으로 만든다.

* `Vector Capacity`
  * vector의 크기는 `size`와 `capacity` 두 개가 있는데, `size`는 벡터가 생성된 크기이며 `capacity`는 벡터의 최대 할당 크기이다. `push`연산을 통해 벡터의 `size`가 `capacity`를 초과하면 `reallocate`가 발생하여 모든 값들을 새로운 메모리에 복사하는 과정이 일어난다. 이 과정에서 속도 저하가 일어나며 `capacity`를 설정해주는 함수들을 이용하여 `reallocate`를 막을 수 있다.

  * `clear()`로 벡터의 값들을 지우면 벡터의 요소들은 없어지지만 `capacity`는 여전히 남아있다. 따라서 `swap`을 이용하여 `capacity`또한 제거해줘야 한다.
    ```
    vector<int> v = {1, 2, 3, 4};
    v.clear();

    vector<int>().swap(v);
    ```
    이렇게 하면 아무것도 없는 벡터공간과 `swap`이 일어나 `capacity`를 없앨 수 있다.

  * `insert()`와 `erase`가 빈번히 일어나는 경우 벡터의 데이터를 하나하나 일일이 이동시킨 후 삽입/ 삭제가 일어나고 `reallocate` 또한 일어날 수 있어서 삽입과 삭제가 빈번한 경우 `list`나 `deque`를 사용하는 것이 낫다.

  * `v.empty()` : 벡터가 빈 공간이면 `true` 아니라면 `flase` 리턴

  * `v.size()` : 벡터의 size 리턴

  * `v.capacity()` : 메모리 heap에 할당된 벡터의 최대크기 반환

  * `v.shrink_to_fit()` : `capacity`의 크기를 벡터의 실제 크기로 맞춘다.


