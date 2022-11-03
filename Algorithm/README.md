# Algorithm

# 개요

**Introduction To Algorithms 3rd Edition**를 바탕으로 수업시간에 다룬 내용들을 정리하였다. 

## 22.07.21

# Algorithm Analysis

## 알고리즘 분석

- 매개변수(parameter)는 문제에서 언급된 할당되지 않은 변수들이다.

  - 문제 : _단조증가 순서로 n개 정수의 리스트 S를 정리하시오._  
    매개변수 : `n`, `S`

- 실체(instance)는 매개변수에 실제로 할당된 값이다.

  - 문제 : _단조증가 순서로 n개 정수의 리스트 S를 정리하시오._  
    실체 : `n = 6`, `S = [10, 7, 11, 5, 13]`

- **알고리즘**이란 어떤 수학적으로 엄밀히 정의된 문제를 풀기 위한 **유한한 절차와 방법**이다.

## 알고리즘의 실험적 분석

- 주어진 알고리즘을 소스코드로 구현한 다음, 실제 환경에서 동작시켜 실제 실행 시간을 측정하여 분석한다.

  - C언어에서는 `clock()`이라는 함수를 이용해서 측정 가능하다.

- **실험적 분석의 문제점**

  - 알고리즘을 실제 구현해야한다.

  - 두 알고리즘의 성능을 비교할 때, 기본적으로 명시된 것들(하드웨어 사양) 및 측정할 수 없는 다양한 외부 요인들로 인해 정확한 비교가 힘들다.

## 알고리즘의 이론적 분석

- 알고리즘을 실제 수행 시간이 아닌, high-level에서 이론적으로 기술하는 방법이다.

- 사용하는 **하드웨어 및 소프트웨어와 무관하게 알고리즘의 성능을 표현한다.**

- 이론적 분석을 통해 구한 알고리즘 수행 시간을 시간 복잡도라 한다.

- 단일 연산들(숫자를 변수에 대입, 두 정수 사이의 사칙 연산 등등)은 입력 크기와는 무관하게 **상수 시간**이 소모된다.

## Big-Oh notation

- 실제 성능에서 복잡한 알고리즘일수록 기본 연산들의 속도차이는 거의 무의미하고 **입력 사이즈에 비례해서 해당 함수가 어느 정도로 수행 시간이 증가하는가**가 중요하다.

- Big-Oh notation은 입력크기 `n`에 대해 최악의 경우 걸리는 시간이다.

- Omega Notation은 입력크기 `n`에 대해 최고의 경우 걸리는 시간이다.

- Theta Notation은 입력크기 `n`에 대해 평균적으로 걸리는 시간이다.

- n!은 `Strling's approximation`에 의해 O(n^n)으로 취급한다.

- 시간 복잡도는 알고리즘을 보면서 계속 연습하는 방법이 제일 이해가 쉬웠다. 

	- 예를 하나만 들자면, for문으로 n사이즈의 배열에 대해 print와 같은 명령을 실행했다면 이 알고리즘은 O(n)이다.
	
## 마스터 정리
  
- 시간 복잡도를 구하는 방법은 여러가지 존재하지만 마스터 정리는 알아두면 좋을 것 같다.

	- `T(n) = aT(n/b) + f(n)`과 같은 모양을 가진 점화식에 대해 **마스터 정리**를 사용할 수 있다.

-  `h(n) = n^(log b a)`이라 하자.

  	1. h(n)이 더 무거우면 h(n)이 수행 시간을 결정한다.

  	2. f(n)이 더 무거우면 f(n)이 수행 시간을 결정한다.

  	3. h(n)과 f(n)이 같은 무게이면, h(n)과 log n의 곱이 수행 시간이 된다.
  

## 22.07.24

# 힙과 우선순위 큐

## 힙

- 최대 힙은 **완전 이진 트리**이고, 부모가 **항상 자식보다 큰** 자료구조이다.

  - 완전 이진 트리란, 마지막 레벨을 제외하고 모든 레벨의 노드가 다 채워져있고 마지막 레벨은 **왼쪽부터 채워지는 트리이다.**
  
  - 최소 힙은 반대로 부모가 항상 자식보다 작다.
  
 - 힙은 완전 이진 트리의 특성상 부모와 자식의 index가 명확해서 배열을 사용한다.
 
	- `A[i]`의 부모는 `A[i/2]`이고 왼쪽 자식은 `A[2*i]` 오른쪽 자식은 `A[2*i + 1]`이다.
  
 - 힙은 **힙 특성 유지하기**(heapify), **힙 만들기**(buildHeap), **삽입**(insert), **삭제**(delete)만 알면 된다. 


## 힙 구현

- **힙 특성 유지하기**(heapify)
 	
	- 배열 `A`에 대해 `i`번째 원소를 최대힙의 루트가 되게한다. *아래는 퍼수도 코드이다.*
	```
	heapify(A, i){
		l = A[i].left
		r = A[i].right
		if(l < A.size && A[l] > A[i])
			max = l
		else max = i
		if(r < A.size && A[r] > A[max])
			max = r
		if(largest != i){
			swap(A[i], A[max])
			heapify(A, max)
			}
	}
	```
	
	- `heapify`는 상수시간이 걸리고 최악의 경우에도 힙의 높이인 `log n`만큼 호출하므로 시간복잡도는 **log n**이다.
	
- **힙 만들기**(buildHeap)
	
	- `heapify`를 리프를 제외한 노드들에 대해 수행하면 된다.
	```
	buildHeap{
		for(i = A.size/2; i > 0; i--)
			heapify(A, i)
	}
	```
	
	- `heapify`를 `n/2`번 호출하므로 시간복잡도는 **nlog n**이다.
	
	- `insert`를 `n`번 호출해서 힙을 만드는 경우도 있다. 이 방법을 더 자주 쓰는 것 같다. 시간 복잡도는 똑같이 **nlog n**이다.	

- **삽입**(insert)  

	- 삽입할 노드를 가장 마지막에 삽입하고, 부모와 교환하면서 힙 특성을 맞춰주면 된다.  
	```
	insert(A, x){
		//n은 현재 힙 사이즈+1 (0번째는 사용 x)
		A[++n] = x;
		for(i = n; i > 1; i /= 2){
			if(A[i] > A[i/2]) swap(A[i], A[i/2])
			else break
		}
	 }
	```
	
	- 시간 복잡도는 **nlog n**이다.
	
- **삭제**(delete)

	- 루트를 삭제하고, 마지막 원소를 루트 위치로 이동시킨 뒤 다시 특성을 유지시킨다.
	```
	delete(A){
		A[1] = A[n]
		A[n--] = 0
		for(i = 1; i < n;){
			if(A[i] > A[i*2] && A[i] > A[i*2+1])
				break;
			else if(A[i] < A[i*2]){
				swap(A[i], A[i*2])
				i *= 2
			}else{
				swap(A[i], A[i*2])
				i = i*2 + 1
			}
		}
	}
	```
	
	- 시간 복잡도는 **nlog n**이다.
	
- 힙 관련 문제는 우선순위 큐 관련 문제를 풀면서 같이 공부하는게 나을 것 같다.

## 22.07.27

## 우선순위 큐

- 우선순위 큐는 들어간 순서에 상관없이 우선순위가 높은 데이터가 먼저나오는 자료구조이다.

- 우선순위 큐는 배열, 연결리스트, 힙으로 구현할 수 있고 보통 힙으로 구현한다.

	- 배열이나 연결리스트로 구현할 경우 삽입의 시간복잡도가 O(n)이 나오고 힙으로 구현하면 O(log n)이 나온다.
	
- 기본적으로 우선순위 큐는 원소를 추가하는 **insert**, 가장 우선순위가 높은 원소를 제거하고 반환하는 **pull**연산을 지원해야한다.

## 관련문제

- 우선순위 큐의 구현은 힙과 거의 동일하므로 바로 문제를 푸는 편이 나아보인다.

- [최대 힙 구현](./Solving/README.md/#11279-최대-힙)

- [최소 힙 구현](./Solving/README.md/#1927-최소-힙)

## 22.10.12

# Sorting

## 정렬 알고리즘

- | 알고리즘  | 최악의 경우 수행시간 | 평균 수행시간       |
  | --------- | -------------------- | ------------------- |
  | 삽입 정렬 | Theta(n^2)        | Theta(n^2)       |
  | 병합 정렬 | Theta(n \log n)   | Theta(n \log n)  |
  | 힙 정렬   | O(n \log n)       | ----             |
  | 퀵 정렬   | Theta(n^2)        | Theta(n \log n)  |
  | 계수 정렬 | Theta (k + n)     | Theta (k + n)    |
  | 기수 정렬 | Theta (d(n + k))  | Theta (d(n + k)) |
  | 버킷 정렬 | Theta(n^2)        | Theta (n)        |

## Basic Sorting Algorithms

### 선택정렬(Selection Sort)

  - 최소 원소를 찾고, 최소 원소를 제일 앞으로 보내는 것을 반복하면서 정렬한다.

  - `for`루프를 `(n-1) + (n-2) + (n-3) + ... + 2 + 1` 과 같이 반복하므로 시간복잡도는 O(n^2)이다.
  
  - c++로 구현  
  ```
  for(int i=0; i<arr.size()-1; i++){
  	int min_index = i;
  	for(int j=i+1; j<arr.sieze(); j++)
		if(arr[max_index] < arr[j]) min_index = j;
	swap(max_index, i);
  }
  ```

### 버블정렬(Bubble Sort)

  - 배열을 탐색하면서 이웃한 원소와 계속 비교하면서 순서가 잘못되어있으면 교환한다. 가장 큰 원소를 뒤로 보낸다.

  - 시간복잡도는 선택정렬과 같다.
  
  - c++로 구현  
  ```
  for(int i=0; i<arr.size()-1; i++){
  	for(int j=0; j<arr.sieze()-i-1; j++){
		if(arr[j] > arr[j+1]) swap(j ,j+1);
		swap(j, j+1);
		}
  }
  ```

### 삽입정렬(Insertion Sort)  

  - 이미 정렬된 배열에 정렬되지 않은 배열의 원소를 하나씩 더해서 정렬된 배열 하나로 만든다.

  - `arr = [29, 10, 14, 37, 13]`을 정렬해보자.

    1. 정렬된 배열 `res`에 `29` 삽입  
       `res = [29, null]`

    2. `res`에 `10` 삽입  
       `res = [10, 29]`

    3. `res`에 `14` 삽입   
       `res = [10, 14, 29]`

    ... 위의 과정을 반복한다. 실제로는 값이 복사되면서 삽입된다.

  - 시간 복잡도는 배열이 역으로 정렬되어있는 Worst case에서 1 + 2 + ... + (n-2) + (n-1) = Theta(n^2), 배열이 이미 정렬되어있는 Best case에서 1 + 1 + ... + 1 = Theta(n), 따라서 Average case에서는 (n^2 + n)/2 = n^2이다.

  - c++로 구현  
  ```
  for(int i=1; i<arr.size();i++){
    //i-1번째 배열까지는 정렬된 배열이다.
  	int temp = arr[i]; //i번째 원소를 정렬된 배열에 삽입한다.
	for(int j=i-1; j>=0; j--){
		if(arr[j] > temp) a[j+1] = a[j]; //삽입할곳이 더 앞에 있으면 j번째 원소를 한칸 뒤로 민다.
		else break; //삽입할 곳을 찾으면 j 다음칸에 삽입하면 된다.
	}
	arr[j+1] = temp;
  }
  ```

### 힙정렬(Heap Sort)

- 최대힙을 구성하고, 루트를 힙의 마지막 원소와 교환한다. 마지막 원소를 제외하고 나머지 원소에 대해 다시 힙을 만들고 교환하는 과정을 반복한다.

- 퍼수도코드로 구현  
 ```
 Build_Max_Heap(A) //최대힙 구성
 for(int i=A.size; i>1; i--){
 	swap(1, i); //루트와 힙의 마지막 원소 교환
	A.size--;
	//루트노트들 제외하고는 모두 힙 특성에 맞으므로 루트만 맞게하면 된다.
	heapify(A, 1);
 }
 ```
 
- log n의 heapify를 최대 n번 호출하므로 시간복잡도는 nlog n이다.

### 퀵정렬(Quick Sort)

- 평균적으로 가장 좋은 성능을 가졌다. 기준 원소를 잡고 기준 원소를 기준으로 양쪽으로 재배치하면서 정렬한다.

- 퀵정렬 또한 **Divide-and-conquer**을 이용한다.

  - **분할** : 배열 `A[p .. r]`을 두 개의 부분 배열 `A[p .. q - 1]` `A[q + 1 .. r]`로 분할한다. 전자는 `A[q]`보다 작거나 같은 원소를, 후자는 `A[q]`보다 크거나 같은 원소를 배치한다.

  - **정복** : 퀵 정렬을 재귀 호출해서 두 부분 배열을 정렬한다.

  - **결합** : 부분 배열이 이미 정렬되어 있으므로 저절로 합쳐져 있다.

- 구현  
  ```
  QuickSort(A, p, r){
     if(p < r)
    	q = Partition(A, p, r)
    	QUICKSORT(A, p, q-1)
    	QUICKSORT(A, q+1, r)
   }
   ```

  이 때 `PARTITION`은 쉽게 말해 배열 `A`의 원소들을 `A[r]`을 기준으로 양쪽으로 재배치하고 `A[r]`의 위치를 리턴하는 함수이다.  

  ```
  Partition(A, p, r){
    x = A[r]
    i = p - 1
    for(j = p; j < r; j++)
      if(A[j] <= x){
	    //기준원소보다 작으므로 p~i 구간에 들어가야한다. 따라서 기준원소보다 작은 배열이 한 칸 늘었으므로 i를 늘려준다.
        i++
		//A[i]는 기준원소보다 작은 배열의 마지막 부분인데, 위에서 ++을 해줬으므로 기준원소보다 큰 배열의 시작 부분이다. 
		//A[j]는 p~i구간에 넣어야하는 원소이므로 둘이 바꿔준다.
        SWAP(A[i], A[j])
	   }
	//마지막으로 기준원소는 기준원소보다 작은 원소의 다음칸, 즉 i+1에 넣어준다.
    SWAP(A[i+1], A[r])
    return i + 1
  }
  ```
  
  x는 기준 원소이다. i는 x보다 작은 원소들을 **분할한 배열의 끝을 가리키는 포인터**이다. 즉, p\~i까지는 x보다 작은 것들로 분할되어있다.  
  또 j는 x보다 큰 원소들을 분할한 배열의 끝 다음칸을 가리키는 포인터이다. i\~j는 x보다 큰 것들로 분할되어있다. 따라서 j\~r까지는 아직 분할하지 않은 공간이다.

- **시간 복잡도**

  - 시간복잡도는 분할하는 모습을 마치 트리처럼 생각하면 편하다.

  - **평균 수행 시간** : 가장 이상적인 경우로, 분할이 항상 반반씩 균등될 때 분할되는 모습이 완전 이진트리이므로 Theta(nlog n)이다.

  - **최악의 경우 수행 시간** : 이미 정렬이 되어 한 쪽에 다 몰리도록 분할될 때 한쪽으로 치우쳐진 트리의 모습이므로 heta(n^2)이다.

### 병합 정렬(Merge Sort)

- 배열을 원소를 하나씩만 가진 배열이 될 때 까지 모두 분해하고 차례로 병합시켜나가면서 정렬하는 방법이다.

- ```
	mergeSort(A[], p, r){
		if(p<r){
			q = (p+r)/2
			mergeSort(A, p, q)
			mergeSort(A, q+1, r)
			//원소가 하나씩으로 잘게 조갠 후 다시 정렬하면서 병합한다.
			merge(p, r)
		}
	}
	```
	정렬되어있는 배열 A[p...q]와 A[q+1...r]을 병합하여 A[p...r]을 만든다.
	```
	merge(start, end){
		mid = (start+end)/2
		i = left
		j = mid+1
		res_index = left
		
		while(i<=mid && j<=right){
			if(arr[i] > arr[j])
				//arr[i]가 더 크면 arr[j]를 먼저 결과에 넣는다.
				result[res_index++] = arr[j++]
			else
				result[res_index++] = arr[i++]
		}
		
		//배열을 일단 탐색후 왼쪽 리스트나 오른쪽 리스트에 남은 값이 있으면 그냥 넣어주면 끝이다.
		if(i > mid){
			while(j <= right){
				result[res_index++] = arr[j++]
			}
		}else{
			while(i <= mid){
				result[res_index++] = arr[i++]
			}
		}
		
	}
	```
	i부터는 정렬되지않은 왼쪽 배열이고, j부터는 정렬되지않은 오른쪽 배열이다. 그 둘을 병합하면 된다.
	
	
## 22.10.13	

## 선형시간 정렬

- 특정 상황에서 비교를 하지 않고 정렬을 함으로써 O(n)시간내에 정렬을 할 수 있다.

### 계수정렬(Counting Sort)

- 원소의 값이 한정적으로 `0 ~ k`의 자연수로 제한되어 있는 경우 사용 가능하다.

- 각 입력원소 `x`에 대해 x보다 작은 원소의 개수를 센다. 그리고 원소 x의 위치를 정한다. 

  - 예를 들어 `x`보다 작은 원소가 17개라면 `x`를 18번째 자리에 위치시킨다.

- 입력 배열 A와 출력을 저장할 배열 B, 임시 작업 공간 배열 C를 사용한다.

- 구현  

```
CountingSort(A, B, k){
  vector<int> C(k, 0);
  for j=1 to A.length
  	C[A[j]]++;
  //C[i]는 값이 i인 원소의 개수이다.

  for j=1 to k
  	C[j]+=C[j-1];
  //C[i]는 이제 값이 i보다 작거나 같은 원소의 개수이다.

  //따라서 C[A[j]]는 j보다 작거나 같은 원소의 개수이고 배열은 0부터 시작하므로 
  //C[A[j]-1이 정렬된 배열에서 A[j]가 들어갈 위치이다.
  for j=A.length-1 down to 0{
  	B[C[A[j]]-1] = A[j];
	//A[j]를 하나 배치했으므로, A[j]보다 같거나 작은 원소의 개수도 하나 줄어든다.
	C[A[j]]-;
	}
}
```

## 22.10.16

### 기수정렬(Radix Sort)

- 자릿수의 값 별로 정렬을 한다. 문자열, 정수를 빠른 시간내에 정렬할 수 있는 것은 장점이지만 부동 소숫점은 정렬할 수 없는 것이 단점이다.

- 10진수라면 각 열은 10개의 버킷을 사용하여, 가장 낮은 자리부터 숫자를 차례대로 버킷에 담으면서 정렬한다.

  - 예를 들어 [222, 96, 123, 1, 23, 5, 2, 17, 28]을 정렬하자.  
  
    **1의 자릿수 기준으로 정렬**  
    [1], [222, 2], [123, 23], [5], [96], [17], [28]  

    **10의 자릿수 기준으로 정렬**
    [1, 2, 5], [17], [222, 123, 23, 28], [96]  

    **100의 자릿수 기준으로 정렬**  
    [1, 2, 5, 17, 23, 28, 96], [123], [222]

- 구현  

```
RadixSort(A){
	int max = A.getMax(); //배열A에서 최댓값을 얻는다.
	int res[A.size()]; //결과를 저장할 배열
	for(int exp = 1; max/exp>0; exp*=10)
		// 여기서의 countingSort는 일반적인 계수정렬은 아니고, 각 자리수별로 버킷에 저장하여 정렬하는 특수한 방식이다.
		countingSort(A, res, exp);
}

countingSort(A, B, exp){
	int bucket[10] = {0, };
	for(int i=0; i<n; i++)
		//exp자릿수에 해당하는 count 증가
		bucket[(A[i]/exp) % 10]++;

	//일반적인 계수정렬을 위한 누적합 구하기
	for(int i=1; i<10; i++)
		bucket[i]+= bucket[i-1];
		
	for(i=A.size()-1 down to 0){
		B[bucket[(A[i]/exp) % 10] -1] = A[i]
		bucket[(arr[i]/exp) % 10]--;
	}
}
```

- 구현을 하면서 따라해보니 좀 헷갈렸는데, 그냥 정렬을 하는게 아니라, `(A[i]/exp)%10`이 A[i]의 exp자릿수라는 것을 기억하고 이를 기준으로 정렬한다고 생각하니 편했다.

- 계수정렬을 이용하는 이유는 계수 정렬은 k 이하의 수만 할 수 있는데 기수정렬은 자릿수의 정렬을 다루다보니 9이하의 정수를 정렬하는 것과 같아서 가장 효율적인 계수정렬을 이용한다.

- 기수정렬은 MSD와 LSD를 모두 이용할 수 있다. 

  - 큰 자릿수부터 정렬하는 MSD는 점진적으로 정렬을 완성해가므로 **중간에 정렬이 완료될 수 있다**는 장점이 있다.

  - 하지만 MSD는 **모든 데이터에 일괄적인 과정을 거치게 할 수 없다** 즉, 224, 232와 같이 두번째 단계에서 이미 결정되었지만 자리를 바꾸는 경우가 발생한다.  
   그렇기에 중간에 데이터를 점검해야하고, 이 때문에 구현의 난이도가 LSD에 비해 놓고 성능의 이점이 사라질 수 있다.

# 기본 자료구조

## 스택

- 스택은 가장 최근에 삽입된 원소가 삭제되는 **LIFO**구조이다. 스택의 `top`에서 원소의 삽입과 삭제가 일어난다.

- **Stack-Empty**  
```
Stack-Empty(S){
  if(S.top==-1) return 1;
  else return 0;
}
```

- **Push**
```
Push(S, x){
  S.top++;
  S[S.top] = x;
}
```

- **Pop**  
```
Pop(S){
  S.top--;
  return S[S.top+1];
}
```

## 큐

- 큐는 가장 먼저 삽입된 원소가 먼저 삭제되는 **FIFO**구조이다. 큐의 `front`에서 삭제가 일어나고 `rear`에서 삭제가 일어난다.

- 큐를 그냥 배열로 사용하게되면 큐가 메모리에서 마치 빙하처럼 점점 이동한다는 문제점이 생긴다. 이 문제를 해결한 **원형 큐**가 존재한다.

- **isEmpty**
```
isEmpty(Q){
  if(Q.front == Q.rear) return 1;
  else return 0;
}
```

- **isFull**
```
isFull(Q){
  if(Q.front == (Q.rear+1)%Q.size) return 1;
  else return 0;
}
```

- **enQueue**
```
enQueue(Q, x){
  if(isFull(Q)) resize(Q);
  rear = ++rear%Q.size;
  Q[rear] = x;
}
```

- **resize** 큐가 가득 차있는 상태에서 큐에 값을 더 넣으려면 크기가 더 큰 큐를 생성해서 기존의 값을 복사해주어야한다.  
```
resize(Q){
  oldQ = Q;
  new Q.size = 2*oldQ.size;
  for(i =0 ~ oldQ.size-1)
  	Q.enQueue(oldQ[i]);
}
```

- **deQueue**  
```
deQueue(Q){
  if(!isEmpty(Q)){
    returnVal = Q[front];
    ++front%Q.size();
	return returnVal;
  }
  return 0;
}
```

## 22.10.17

# 해시테이블

## 직접 주소 테이블

- 직접 주소 테이블에서는 key에 key와 같은 value가 맵핑되는 방식이다.

- 구현

  ```
  Direct-Address-Search(T, k){
    return T[k];
  } 

  Direct-Address-Insert(T, x){
    T[x] = x;
  }

  Direct-Address-Delete(T, x){
    T[x] = null;
  }

  ```

- 직접 주소 테이블은 전체 집합 중 실제 저장되는 키들의 집합 비율이 낮은 경우 할당된 대부분의 공간은 낭비된다는 단점이 있다.  

- 이 문제를 해결하기 위해 해쉬 함수를 사용하여 보완한다.

## 해시테이블

### 해시 함수

- 해시 함수란 임의의 길이의 데이터를 고정된 길이의 데이터로맵핑하는 함수이다.

  - 해시 함수는 다양하게 존재하지만 간단하게 나머지 연산자를 사용할 수 있다.  
  
    ```
    hashFuntion(x){
      return x % 10;
    }
    
    ```
	
- 해시 함수를 이용하면 간편하게 데이터를 맵핑시킬 수 있지만 충돌이 일어날 수 있다.

### 체이닝에 의한 충돌 해결

- 마치 연결리스트처럼 같은 해시값으로 매핑되는 값을 연결시켜 줌으로써 해결할 수 있다.

- 구현
  ```
  Chained_Hash_Insert(T, x){
    T[hashFuntion(x)]의 맨 앞에 x 삽입
  }
  
  Chained_Hash_Search(T, k){
    T[hashFuntion(k)]에서 키 k를 가지는 원소 검색
  }
  
  Chained_Hash_Delete(T, x){
    T[hashFuntion(x)]에서 x 삭제
  }
  ```
  
- 체이닝보다 더 좋은 해결 방법은 **최대한 충돌이 안나는 해시 함수를 만드는 것**이다.

## 개방 주소화 방법

- 또 다른 충돌을 해결하는 방법으로 개방주소화방법이 있다.

- 체이닝으로 충돌을 해결하면 포인터를 사용해야한다. 하지만 개방 주소화 방법으로 포인터를 사용하지않고 그만큼의 공간을 테이블 저장공간으로 사용할 수 있다.

- 개방 주소화 방법에서 삽입을 하기 위해서는 키를 저장할 빈 공간을 찾을때까지 테이블을 조사해야한다. 그러므로 테이블이 완전 가득 차면 충돌을 해결할 수 없다는 단점이 있다.

- **HashInsert** 삽입은 해당 원소의 해시값에 원소가 들어있으면 바로 다음칸에 삽입하는 방식이다.
  ```
  HashInert(T, k){
    hashFunction=0;
	for(i=0 to table_size){
	  int j = hashFunction(k);
	  if(T[j] == null]) T[j] = k;
	  else j++;
	}
  }
  ```
  
- **HashSearch** 검색은 삽입과 비슷하게 하지만, 해시값 다음 값이 null이 되는 순간 테이블에 원소가 없는것이다.
  ```
  HashSearch(T, k){
    for(int i=0, j = hashFunction(k); T[j] != null || i < T.size(); i++, j++){
	  if(T[j]==k) return j;
	}
  }
  ```

- Delete도 Search와 똑같이 값을 찾고, 삭제하되 뒤에 개방 주소때문에 삽입된 값들이 있으면 땡겨주기만 하면 된다.

## 22.10.23

# Search Tree Ⅰ

## 이진 트리 순회

### 중위 순회(inorder traversal)

- LVR방식으로 순회가 이루어진다.

1. 왼쪽 끝까지 이동하면서 내려가고 그 노드를 방문한다.

2. 오른쪽 자식 노드로 이동한 뒤 1.을 반복한다. 오른쪽 노드가 없으면 3.으로 간다.

3. 이전 노드로 되돌아가서 실행한다.

- ![binary_tree.png](./img/binary_tree.png)  
  위의 트리에서 inorder을 한 결과는 `A / B * C * D + E`이다.

- 재귀호출과 스택으로 구현할 수 있다.

- 스택으로 구현  
  ```
  inorder(node){
    if(!node) return;
	
    stack<treeNode *> s;
	s.push(node); //트리노드 스택에 삽입
	vector<string> res;
	
	while(node != null || !s.empty()){
	  while(node != null){
	    s.push(node);
		node = node.left;
	  }
	  node = s.pop();
	  res.push_back(node.key);
	  node = node.right;
	}
  }
  ```
  
- 재귀호출로 구현
  ```
  inorder(root){
    inorder(root.left);
	res.push_back(root.key);
	inorder(root.right);
  }
  ```
  
### 전위 순회(preorder traversal)

- VLR방식으로 순회가 이루어진다.

- 스택으로 구현
  ```
  preorder(node){
    if(!node) return;
    stack<treeNode *> s;
	vector<string> res;
	
	while(!s.empty() || node != null){
	  if(!s.empty()) node = s.pop();
	  while(node != null){
	    res.push_back(node.key);
		if(node.right) s.push(node.right);
		node = node.left;
	  }
	}
  }
  ```


- 재귀호출로 구현
  ```
  preorder(root){
    res.psuh_back(root.key);
	preorder(root.left);
	preorder(root.right);
  }
  ```
  
### 후위 순회(postorer traversal)

- LRV방식으로 순회가 이루어진다.

- 스택으로 구현, 조금 복잡하니 재귀호출로 구현하자.
  ```
  postorder(node){
    if(!node) return;
    stack<treeNode *> s;
	vector<string> res;
	
	s.push(node); //루트 스택에 삽입
	treeNode* prev = null;
	while(!s.empty()){
	 node = s.top();
	 if(prev == null || prev.left == node || prev.right == node){ //최초 실행이거나 이전에 아래 코드를 실행했을 때 node를 탐색하지 않은 경우
	   if(node.left) s.push(node.left);
	   else if(node.right) s.push(node.right);
	   //자식이 있으면 왼쪽자식을 우선으로 스택에 넣는다. 자식이 없으면 그 노드를 탐색하면 된다.
	   else{
	     s.pop();
		 res.push_back(node.key);
	   }
	 }else if(node.left == prev){ //이전 실행에서 탐색한 노드가 부모의 왼쪽 자식인 경우
	   if(node.right) s.push(node.right)
	   else{
	     s.pop();
		 res.push_back(node.key);
	   }
	 }else if(node.right == prev){ //이전 실행에서 탐색한 노드가 부모의 오른쪽 자식인 경우 현재 노드를 탐색하면 된다.
	   	 s.pop();
	     res.push_back(node.key);
	 }
	}
	prev = node;
  }
  ```
  
- 재귀호출로 구현  
  ```
  postorder(root){
	postorder(root.left);
	postorder(root.right);
	res.psuh_back(root.key);
  }
  ```
  
## Terms

- **record** : 개체에 대해 수집된 모든 정보를 포함하고 있는 저장 단위

  - ex : 사람의 레코드 : 주민번호, 이름, 집주소, 전화번호, ...

- **field** : 레코드에서 각각의 정보를 나타내는 부분

  - ex : 사람의 레코드에서 주민번호 필드, 이름 필드, ...

- **search key** : 다른 레코드와 중복되지 않는 각 레코드를 대표하는 필드, 하나의 필드일 수도 있고, 두 개 이상의 필드로 이루어질 수도 있다.

- **search tree** : 각 노드가 규칙에 맞는 키를 가지고 있고, 이를 통해 레코드가 저장된 위치를 알 수 있다.

## Binary Search Tree

- **이진 검색 트리는 다음의 특성을 만족한다.**

  - **각 노드의 키 값은 모두 다르다.**

  - **각 노드는 최대 두 개의 자식만 갖는다.**

  - **임의의 노드의 키 값은 왼쪽 자식의 키 값보다 크고, 오른쪽 자식의 키 값보다 작다.**

  - 이진 검색 트리의 **서브 트리도 이진 검색 트리를 유지한다.**

### 이진 검색 트리에서의 검색

- 구현

  ```
   treeSearch(root, key){
     if(root = null || root.key = key) return root;
     if(key < root.key) return treeSearch(root.left, key);
     else return treeSearch(root.right, key);
   }
  ```

### 이진 검색 트리에서의 삽입

- 삽입 후 루트 노드의 포인터를 리턴한다. `r`노드를 생성하고, 경로를 따라 내려가면서 삽입할 위치를 찾아서 삽입한다.

- 구현
  ```
  treeInsert(root, x){
    //빈 트리일 경우 루트를 r로하고 리턴한다.
    if(root == null){
      r.key = x;
      r.left = null;
      r.right = null;
      return r;
    }
    if(x < root.key){
      root.left = treeInsert(root.left, x);
      return root;
    }
    else{
      root.right = treeInsert(root.right, x);
      return root;
    }
  }
  ```

- 이진 검색 트리에서의 균형이 이상적으로 잡혀 있으면 최악의 경우에도 **O(log n)**(perfect-binary-tree의 경우)이고, 균형이 맞지 않는 최악의 경우에는 **O(n)** (한 쪽으로만 노드가 삽입된 경우)이다. 평균적으로는 **O(log n)** 이다.

### 이진 검색 트리에서의 삭제

1. `key`가 리프 노드이면, `key`의 부모의 자식 노드를 `key`에서 `null`로 바꾸면 된다.

2. `key`가 자식 노드를 하나만 가지고 있으면, `key`의 자식 노드를 `key`의 자리로 상승시킨다.

3. `key`가 자식 노드를 두 개 가지고 있으면, `key`의 **오른쪽 서브트리의 최소원소 노드** _(왼쪽 서브트리의 최대원소 노드도 가능하다.)_ `min`를 찾고 `min`과 `key`의 위치를 바꾼 뒤 `key`를 삭제한다.

- 구현
  ```
  treeDelete(root, key){
   if(root == null) return root;
   if(key < root.key) root.left = treeDelete(root.left, x);
   else if(key > root.key) root.right = treeDelete(root.right, x);
   else{
     //리프노드인 경우
	 if(root.left == null && root.right == null) return null;
	 else if(root.left == null){
	   //왼쪽자식이 없으면 오른쪽 자식 올리기
	   treeNode* temp = root.right;
	   free(root);
	   return temp;
	 }else if(root.right == null){
	   treeNode* temp = root.left;
	   free(root);
	   return temp;
	 }else{
	   //자식 둘 다 있는 경우
	   treeNode* min = root.right;
	   while(min.left != null) min = min.left;
	   root.key = min.key; //오른쪽 서브트리의 최소노드를 부모로 만든다. 이 과정은 최소노드를 오른쪽 서브트리에서 삭제하는 것과 같다.
	   root.right = deleteNode(root.right, min.key);
	 }
   }
   return root;
  }
  ```

- 시간 복잡도는 삽입과 비슷하게 **O(log n)** ~ **O(n)** 이다.

- 이진 검색 트리는 운이 나쁘면 트리의 모양의 균형이 깨져서 노드의 검색, 삽입, 삭제에 Theta(n)이 소요될 수 있다. **이를 해결하기 위해 균형이 잘 맞도록 구성하는 트리를 생각해보자.**


## 22.10.25

# Red-Black Tree

## Red-Black Tree의 특성

- 다음의 레드블랙 특성을 만족하는 이진 검색 트리를 레드블랙 트리라 한다.

1. 루트노드는 블랙이다.

2. 모든 리프노드는 블랙이다.

   -  이 때 리프 노드는 일반적인 리프 노드가 아니라 T.nil을 가리키고 T.nil은 루트 노드를 가리키고있다.
  
3. 노드가 레드이면 그 노드의 자식은 반드시 블랙이다.

4. 루트 노드에서 임의의 리프 노드에 이르는 경로들은 모드 같은 수의 블랙노드를 포함한다.

![red_balck_tree](./img/red_black_tree.PNG)

## 레드블랙 트리에서의 삽입

- 기본적으로 이진 검색 트리와 같으며 삽입되는 노드는 항상 레드이다.

- 삽입되는 노드의 부모가 블랙이면 그냥 삽입하면 된다.

- 삽입되는 노드의 부모가 레드이면 아래와 같이 케이스를 나누어서 처리한다.

  1. 부모의 형제가 레드인경우, Color Flip을 통해 할아버지와, 부모, 부모의 형제의 색을 바꾼다.

     - 이 때, 할아버지의 색을 레드로 바꾸게 되는데, 또 레드 노드가 두 개가 생길 수 있으므로 재귀적으로 부모가 검은색이거나 루트에 도달할 떄 까지 검사해줘야 한다. 

  2. 부모의 형제가 블랙이면 Restructuring을 수행한다.

     - Restructuring은 새로운 노드(N), 부모 노드(P), 조상 노드(G)를 오름차순으로 정렬한다. 그리고 셋 중 중간값을 부모로 만들고 색을 바꾼다.

- 3, 1, 5, 7, 6 순으로 삽입될 때 최종 레드블랙 트리의 구성 과정을 예시로 살펴보자.\

![red_black_tree_insert](./img/red_black_tree_insert.PNG)

## Red-Balck Tree 분석

- 키가 총 `n`개인 레드블랙 트리의 최대 깊이는 **O(log n)** 이다.

  - 루트에서 임의의 리프에 이르는 경로의 블랙 노드는 모두 블랙 노드로 이루어져 있어도 **log n + 1**을 넘을 수 없다.  
    또 레드노드는 두 개 연속으로 존재할 수 없으므로 임의의 리프에 이르는 총 길이는 **2\*(log n + 2)** 를 넘을 수 없다.


## 22.10.27

# Dynamic Programming

## 동적 계획법

- 동적 계획법은 분할정복 기법과 같이 부분 문제의 해를 결합해 문제를 해결하는 방법이다.

  - 분할정복 알고리즘은 서로 겹치지않는 부분 문제로 분할하고 재귀적으로 해결한 후, 해결 결과를 결합하여 원래 문제를 해결한다.  
  그러나 동적 계획법은 부분 문제가 서로 중복될 때, 적용하여 공유되는 부분 문제의 해를 테이블에 저장함으로써 각 부분 문제를 풀 때마다  
  다시 계산하는 일을 피할 수 있다.

### 피보나치 수 구하기

- 피보나치 함수를 재귀함수로 구현해보자.

  ```
  int F(int x){
  if (x == 0) return 0;
  if (x == 1) return 1; 
  else return F(x - 1) + F(x - 2);
  }
  ```
 
- 이 코드는 `x = 40`정도로 커지면 답을 구하기 버겁다. 그 이유는 F(x)를 구할 때 F를 더 이상 쪼갤 수 없을 때 까지 F(1)을 호출하면서 수행 시간 또한 지수함수로 커지기 때문이다.

- F(5)를 구한다고 가정해보자. F(5) = F(4) + F(3) 이다. 그런데 이 때 F(4)를 구할 때 F(3)이 또 사용된다. 이런식으로 모두 살펴보면 F(2)는 세 번, F(1)은 다섯 번이나 호출된다.
 
 - F(x)는 같은 x에 대해 언제 실행해도 같은 결과가 나온다. 따라서 아래의 코드와 같이 이미 구한 값을 캐시에 저장하고 다시 가져오는 방식으로 코딩할 수 있다.

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

  - 위 코드로 F(5)를 구하면 함수의 호출 회수가 훨씬 줄어든 것을 확인할 수 있다.

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

## DP의 특성

- 작은 부분 문제를 큰 문제를 해결할 때 사용한다. 따라서 **부분 문제가 중복**되는 경우 DP를 사용할 수 있다.

- 위의 예시에서 캐시에 저장해놓고 나중에 사용하는 방법인 **메모이제이션**을 통해 계산 횟수를 크게 줄일 수 있다.

- 어떤 부분 해를 구하는 과정이 유일하고 다시 계산해도 변하지 않아야한다. 즉 **최적 부분 구조**를 가져야한다.

- 문제의 해답을 **점화식**으로 표현할 수 있고, 그 점화식이 순환 참조하지 않아야 한다.

- DP의 경우 많은 문제들을 다뤄보면서 익숙해지는 것이 중요하다.


## LIS

- **Longest lncreasing Subsequence**는 어떤 수열 `A`에서 가장 긴 증가하는 부분 수열을 구하는 문제이다. DP의 가장 대표적인 문제 중 하나이고 유사한 풀이를 적용할 수 있는 문제들이 많아서 공부해두면 좋다.

- DP를 사용하지 않고 각 원소를 최장 증가 수열에 포함하거나 하지 않는 경우를 모두 확인하면 O(2^n)이 걸린다.

- DP를 사용하여 `A[i]`를 마지막 원소로 가지는 가장 긴 부분수열의 길이를 구하여 배열 `B[i]`에 저장한다.

### LIS 길이 구하기

- `A = [1, 5, 3, 4, 2, 6]`와 같은 수열이 있다고 가정하자.

- `B[1] = 1`이고 `B[2]`부터는 기존에 증가하는 부분 수열들에 `A[i]`를 이어붙여 만들 수 있다.

- 즉 `B[i]`는 `j`가 1부터 i-1까지 커지며 `A[i] > A[j]` 이면 `B[j] + 1`로, 아니라면 1로 설정한다. 이 때 각 `j`에 따른 `B[i]`값 중 제일 큰 값이 `B[i]`이다.

- `B = [1, 2, 2, 3, 2, 4]`이고 수열 `B`의 최대값이 최장 증가 수열의 길이가 된다. `i`에 대해 `j`를 모두 확인해야 하기에 시간 복잡도는 `O(n^2)`이다.  
  ![lis_length](./img/LIS1.PNG)
  

### LIS 출력하기

- 역추적을 통해 출력할 수 있다. 

1. 역출력 배열 `F`를 정의한다. 역추적 배열은 LIS를 만들 때 바로 이전 원소가 어디에 있었는지 저장한다.

   - `F[i]`는 B[i] > 1인 경우 즉, `A[i]`를 마지막 원소로하는 증가 부분 수열을 만들 때 `A[i]`가 어떤 부분 수열 뒤에 붙을 수 있는 경우에는  
   `B[i]`를 구할 때 참조한 이전 위치로 만들고 아니라면 -1로 만든다.

2. 수열 `B`의 최대값을 찾는다. 최대값의 index를 `x`라 하자. `i = x`라고 놓고 아래를 반복 시행한다.

    2-1.`A[i]`를 최장 증가 수열의 마지막 원소로 저장한다.

    2-2. `F[i]`에는 이전 원소의 위치가 저장되어 있으므로 `i = F[i]`를 수행한다.

    2-3. 만약 `F[i] = -1`이면 `A[i]`는 최장 증가 수열의 첫 번째 원소이다. 따라서 루프를 종료한다.

  - 위의 과정을 거쳐 얻은 값들의 순서를 뒤집으면 최장 증가 수열을 얻을 수 있다.  
  ![lis_print](./img/LIS2.PNG)


### 길이별 배열로 변환

- 위의 알고리즘에서 `A = [1, 5, 3, 4, 2, 6]`의 배열에서 `B[4]`를 구하는 과정을 살펴보자. `A[2] = 5`이고, 이는 `A[4]`보다 크므로 패스한다.   
  `A[3] = 3`이고, 이는 `A[4]`보다 작으므로 `A[3]`뒤에 `A[4]`를 붙일 수 있다.  
  이 때 잘 보면 `A[2]` 뒤에 다음 원소를 붙이면 `{1, 5, x}`이 되고 `A[3]` 뒤에 붙이면 `{1, 3, x}`가 된다. `x`뒤에 어떤 원소가 얼마나 오던 `A[3]`뒤에 원소를 붙이는 것이 더 긴 LIS를 만들 수 있다.

- 위의 특성을 일반화하면 `B[i] = B[j]`이고 `A[i] < A[j]`이면, 새로운 원소를 `A[i]` 뒤에 붙이는 경우만 따지면 된다. 따라서 `B[i]`가 같은 원소들에 대해 `A[i]`가 가장 작은 것들만 남겨도 된다.

  - `C[i]`를 `B[j]=i`인 `j`에 대해 `A[j]`중 최솟값이라고 하자. i=1~지금까지의 LIS길이이다. 즉 `C[i]`는 lis길이가 `i`인 배열 중 lis 가장 끝에 올 수 있는 가장 작은 원소이다.
  
  - 수열 `A, B`를 4번째 원소까지 검사한 후 배열 `C`는  `[1, 3, 4]`이다. 여기서 나머지 원소들도 처리해보자.

    - `A[5] = 2`. 이는 C[1]보다 크기에 최대 길이가 2인 증가 수열을 만들 수 있다. 따라서 `C[2]`를 갱신한다. 그러나 `C[2]`보다 작기 때문에 `C[2]`이후의 원소를 갱신할 수 없다.

    - `A[6] = 6`. 이는 `C`의 모든 원소들 보다 크다. 따라서 `C[4] = 6`을 추가한다. 그러면 `C = [1, 2, 4, 6]`이고 LIS의 길이는 4이다.
  ![lis_trans](./img/LIS3.PNG)

## 22.11.01

### LIS nlog n으로 풀기

- 길이별 배열로 변환하여 LIS를 구하면 O(n^2)이 걸린다. 그런데 위 알고리즘에서 배열 C에 원소를 삽입할 때 이분탐색을 이용하면 O(nlog n)으로 해결할 수 있다.  
  가장 긴 증가하는 부분 수열 2  
  https://www.acmicpc.net/problem/12015  
  
- 기본적인건 길이별 배열로 변환 알고리즘과 같다.  
  
    1. 현재 탐색하는 원소 A[i]가 C의 어떤 원소보다 크다면 가장 뒤에 삽입한다.
	
	2. 그렇지 않다면 배열C에서 A[i]보다 큰 수가 처음으로 나온 index를 **이분 탐색을 이용하여**찾고 A[i]로 바꾼다.  
	이 때 c++을 이용한다면 `lower_bound`를 이용할 수 있다.
	
- 구현 

  ```
  lis(){
    for(int i=0; i<N; i++) cin >> A[i];
	
	C.push_back(A[0]);
	current_index = 0;
	for(int=1; i<N; i++){
	  if(C.[current_index] < arr[i]){
	    C.push_back(arr[i])
		current_index++;
	  }else{
		C[lower_bound(C.begin(), C.end(), arr[i])-C.begin()] = arr[i];
	  }
	}
  }
  ```
  
  lower_bound 구현 실제로는 iterator을 반환한다.
  ```
  int lower_bound(vector<int>& arr, int key){
    int st = 0;
	int ed = arr.size()-=1;
	ine mid;
	
	while(ed > st){
	  int mid = (st+ed)/2;
	  if(key > arr[mid]) st = mid + 1;
	  else ed = mid;
	}
	return ed;
  }
  ```

## LCS

- Longest Common Subsequence는 최장 공통 부분 문자열이다. Subsequence는 SubString과는 다른 개념이다.  
  SubString은 연속된 부분 문자열이고 Subsequence는 **연속되지 않은 부분 문자열**이다. 단 연속되지 않아도 될 뿐이지 무조건 증가해야한다.  
  예를 들어 `A C A Y K P`, `C A P C A K`의 SubString은 `CA`이고 Subsequence는 `ACAK`이다.
  
### LCS 특성  
  
- string1의 사이즈는 m, string2의 사이즈는 n, lcs의 사이즈는 k이다.  
  
  1. string1[m] == string2[n]이면, lcs[k] == string1[m] == string2[n]이고 m-1까지의 string1과 n-1까지의 string2는 k-1까지의 lcs이다.  
  
  2. string1[m] != string2[n]이고 lcs[k] != string1[m]이면, lcs가 m-1까지의 string1과 string2의 lcs이다.  
  
  3. string1[m] != string2[n]이고 lcs[k] != string2[n]이면, lcs가 string1과 n-1까지의 string2의 lcs이다.  
  
  위의 특성들을 가지고 점화식을 도출할 수 있다.
  
### LCS 점화식

- lcs[i][j] =  
  if(i == 0 || j == 0) **0**  
  else if(i>0 && j>0 && string1[i] == string2[i]) **lcs[i-1][j-1]+1**  
  else **max(lcs[i][j-1], lcs[i-1][j])**

- 조금 더 풀어서 설명하자면, 먼저 i 혹은 j가 0인경우를 0으로 다 채운다.  
  그리고 string1[i]와 string2[i]가 같으면 자연스레 i-1까지 탐색했을 때 lcs길이에서 1을 더한 것이다.  
  다른 경우에는 어차피 다르므로 lcs길이를 늘릴 수 없으므로 더 긴 쪽을 선택하면 된다.
  

## 0/1 배낭 문제

- 배낭 문제는 무게 제한이 50인 배낭에 세 개의 물건을 넣는데, 가치 합이 최대가 되면 되는 문제이다. 0/1베낭 문제는 물건을 쪼개서 놓을 수 없기 때문이다.   
  ![dp_knapsack](./img/knapsack.PNG)
  
- `dp[i, w]`는 i번쨰 까지의 물건을 선택하고 w의 무게 제한으로 가능한 최대 가치이다. 이 때 `dp[i][w]`는  

    1. i==0 혹은 w==0 => 0이다.
	
	2. i번째 물건의 무게가 무게 제한을 초과하는 경우 => dp[i-1][w]이다. 즉 마지막에 넣은 물건 하나를 빼면 된다.
	
	3. i번째 물건의 무게가 초과하지 않는 경우 => 넣지 않았을 때 즉, dp[i-1][w]와 넣었을 때 dp[i-1][w-w[i]] + p[i] 중 최댓값을 고르면 된다.


## 관련 문제

- 피보나치 수 5  
  https://www.acmicpc.net/problem/10870  
   소스 코드 : [C++](./Solving/BOJ/2747.cpp)

- 가장 긴 증가하는 부분 수열  
  https://www.acmicpc.net/problem/11053  
   소스 코드 : [C++](./Solving/BOJ/11053.cpp)   

- 가장 긴 증가하는 부분 수열 4    
  https://www.acmicpc.net/problem/14002  
   소스 코드 : [C++](./Sovling/BOJ/14002.cpp)

- 신나는 함수 실행  
  https://www.acmicpc.net/problem/9184  
   소스 코드 : [C++](./Solving/BOJ/9184.cpp)

- 정수 삼각형  
  https://www.acmicpc.net/problem/1932  
   소스 코드 : [C++](./Solving/BOJ/1932.cpp)

- 연속합  
  https://www.acmicpc.net/problem/1912  
   소스 코드 : [C++](./Solving/BOJ/1912.cpp)

- 구간 합 구하기 4  
  https://www.acmicpc.net/problem/11659  
   소스 코드 : [C++](./Solving/BOJ/11659.cpp)

- 구간 합 구하기 5  
  https://www.acmicpc.net/problem/11660  
   소스 코드 : [C++](./Solving/BOJ/11660.cpp)

- 1로 만들기 2  
  https://www.acmicpc.net/problem/12852  
   소스 코드 : [C++](./Solving/BOJ/12852.cpp)



## 22.11.03

# 그리디 알고리즘

## 그리디 알고리즘이란

- 그리디 알고리즘은 항상 각 단계에 있어 탐욕적으로 가장 좋을 거라 생각되는 선택을 하는 알고리즘이다. 

- 그리디 알고리즘이 잘 작동하는 문제는 **greedy choice property**와 **optimal substructure**라는 두 가지 조건이 만족된다.

  1. Greedy Choice Property : 앞의 선택이 이후의 선택에 영향을 주지 않는다.
  
  2. Optimal Substructure : 문제에 대한 최종 해결 방법은 부분 문제에 대한 최적 문제 해결 방법으로 구성된다.
  
- 위의 조건이 성립하지 않는 경우, 그리디 알고리즘으로 해를 구할 수 없다. 또한, 위의 조건이 성립하더라도 최적해를 찾으려면 엄밀한 증명이 필요하다.

- 그런데 어떤 특별한 구조 **매트로이드** 구조에서는 그리디 알고리즘이 언제나 최적해를 찾아낸다. 매트로이드는 여러 곳에서 발견되기 때문에 그리디 알고리즘의 활용도를 높여준다.


## 활동 선택 문제

- 활동 선택 문제는 공유 자원 하나를 서로 배타적으로 사용해야 하는 여러 개의 활동이 주어졌을 때 가장 좋은 스케줄을 짜는 문제이다.

- 예를 들어 한 강의실에서 여러 수업을 할 때 한 번에 가장 많은 수업을 할 수 있는 경우를 고르는 것이다.

### 활동 선택 문제 예시

- ![greedy_schduling](./img/greedy_schduling.PNG)  

  위의 사진에서 Si는 시작시간, Fi는 종료시간이다. 이 때 가장 많은 수업을 할 수 있는 경우를 찾는 것이다.
  
- 이 문제는 dp를 통해 풀 수 있다. 예를 들어 S[1,8]을 A1이 종료된 후부터, A8이 시작하기 전 활동들의 집합이라 하고 S[1,8]중 최적의 조합을 B[1,8]이라 하자. 이 때 B[1,8]은 {A3, A6}이라할 수 있다.  
  B[1,8]에서 A6을 고르면 B[1,6]과 B[6,8]의 개수와 A6 한 개를 더하면 A6을 골랐을 때 최적 해이며, 다른 것을 골랐을 때도 생각해주면 된다.  
  위처럼 dp를 사용해서 해결하면 모든 부분 문제의 해를 구해야 한다.
  
- 그런데 이 문제는 그리디 알고리즘으로 최대한 일찍 끝나는 수업들을 구하면 된다. 이제 우리는 활동 선택 문제가 매트로이드임을 알았으므로 이런 구조의 문제가 나오면 그리디를 써먹을 수 있다.



(https://www.zerocho.com/category/Algorithm/post/584b979a580277001862f182)








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