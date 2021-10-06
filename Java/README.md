# Java

Java의 정석을 바탕으로 공부하였다. 다른 프로그래밍언어를 어느정도 다루어 봤다는 전제로 자바에서 다른 내용들이나 헷갈릴 수 있을 내용들을 위주로 작성하였다.

# 목차

[자바를 시작하기 전에](#자바를-시작하기-전에)  
[변수](#변수-Variable)  
[연산자](#연산자Operator)  
[조건문과 반복문](#조건문과-반복문)  
[배열](#배열-Array)  
[객체지향 프로그래밍Ⅰ](#객체지향-프로그래밍Ⅰ)  
[객체지향 프로그래밍 Ⅱ](#객체지향-프로그래밍-Ⅱ)  
[예외처리](#예외처리)  
[java.lang패키지와 유용한 클래스](#java.lang패키지와-유용한-클래스)

# 자바를 시작하기 전에

## JVM(Java Virtual Machine)

- JVM은 자바를 실행하기 위한 가상 기계이다. 컴퓨터 속의 컴퓨터로 자바로 작성된 **모든** 어플리케이션은 모두 JVM에서만 실행된다.

- 일반적인 애플리케이션은 OS를 거쳐 바로 하드웨어로 전달된다. 하지만 자바애플리케이션은 JVM을 거치고 실행 시에 코드가 해석되기 때문에 속도가 느리다.

- 일반 애플리케이션은 바로 OS와 맞붙어 있기에 OS종속적이다. 하지만 자바애플리케이션은 JVM을 이용하기에 OS에 맞는 JVM만 있으면 어떤 OS에서도 실행 가능하다.

## VS Code에 JDK 설치하기

- [link](https://niceman.tistory.com/198)를 참고하여 설치를 진행하였다.

- JDK의 bin 디렉터리에 있는 파일들을 살펴보자.

  - `javac.exe` : 자바 컴파일러, 자바소스코드를 바이트코드로 컴파일한다.

  - `java.exe` : 자바 인터프리터, 컴파일러가 생성한 바이트코드를 해석하고 실행한다.

  - `javap.exe` : 역어셈블러, 컴파일된 클래스파일을 원래의 소스로 변환한다.

  - `javadoc.exe` : 자동 문서 생성기, 소스파일에 있는 주석을 이용하여 Java API문서와 같은 형식의 문서를 자동으로 생성한다.

  - `jar.exe` : 압축프로그램, 클래스파일과 프로그램의 실행에 관련된 파일을 jar파일로 압축하거나 압축해제한다.

## 자바 프로그램 실행하기

- 먼저 `Hello.java`를 작성한다. 윈도우의 경우 cmd를 열어 `javac Hello.java`를 입력하면 `Hello.class`가 생성된다. `java Hello`를 통해 이제 소스코드가 실행된다.

- 자바에서 모든 코드는 반드시 클래스 안에 존재해야 한다. 유사한 기능들의 코드가 그룹을 이루고 클래스를 형성한다.

- 클래스를 작성하는 방법은 키워드 `class`다음에 클래스의 이름을 적고 `{}` 안에 코드를 작성하면 된다.

- C언어와 비슷하게 `main`메서드부터 실행하며 모든 클래스가 `main`메서드를 가질 필요는 없지만 하나의 자바 애플리케이션에는 `main`메서드를 포함한 클래스가 반드시 하나는 있어야 한다. 자바 애플리케이션을 실행할 때는 `java.exe` 다음에 `main`메서드를 포함한 클래스의 이름을 적어야 한다.

  - `main`메서드는 `public static void main (String[] args)`와 같이 선언해야한다. 이는 `java.exe`에 의해 호출될 수 있도록 미리 약속한 부분이다.

- 하나의 소스파일에 여러 개의 클래스를 정의할 수 있다. 하지만 이 때 소스파일의 이름은 반드시 `public class`의 이름과 같아야 한다. `public class`가 없다면 소스파일의 이름은 소스파일 내의 어떤 클래스의 이름으로 해도 된다.

- 하나의 소스파일에 둘 이상의 `public class`가 존재해선 안된다.

## 자바프로그램의 실행과정

- 콘솔에서 `java Hello` 명령을 실행하면 내부적인 진행 순서는 다음과 같다.
  1. 프로그램의 실행에 필요한 클래스를 로드한다.
  2. 클래스파일을 검사한다.
  3. 지정된 클래스에서 main을 호출한다.

---

# 변수 Variable

## 변수의 선언과 초기화

- 변수의 선언, 초기화 방법은 C언어와 같다.

## 변수의 명명규칙

1. 대소문자가 구분되며 길이에 제한이 없다.
2. 예약어를 사용해선 안 된다.
3. 숫자로 시작해서는 안 된다.
4. 특수문자는 `_`와 `$`만 허용된다.

- 다음의 규칙들은 자바 프로그래머들에게 권장되는 규칙이다.
  1. 클래스의 이름의 첫 글자는 항상 대문자로 한다.
     - 변수와 메서드는 소문자로 한다.
  2. 여러 단어로 이루어진 이름은 단어의 첫 글자를 대문자로 한다.
     - StringBuffer ...
  3. 상수의 이름은 모두 대문자로 한다. 띄어쓰기는 `_`로 구분한다.

## 참조형 변수

- 변수의 타입은 기본형 변수와 참조형 변수로 나뉜다.

  - 기본형 변수는 **실제 값**을 저장한다.

  - 참조형 변수는 C의 포인터처럼 어떤 값이 저장되어 있는 **주소**를 값으로 갖는다. 단, C와 달리 참조형 변수간의 연산은 할 수 없다.

- 참조형 변수를 선언할 때는 변수의 타입으로 클래스의 이름을 사용하므로 클래스의 이름이 참조변수의 타입이 된다.

- `classname variablename`과 같이 선언하며 이 때 변수의 타입이 기본형이 아닌 것들은 **모두 참조변수**이다.

## 기본형 변수

- 기본형 변수는 C++와 비슷하게 `boolean`, `char`, `byte`, `short`, `int`, `long`, `float`, `double`를 지원한다.

- `boolean`은 참, 거짓을 저장하며 나머지 자료형들과 연산과 변환이 불가능하다.

- 기본 자료형의 크기는 모두 외워두자.  
  boolean : 1 byte  
  char : 2 byte  
  byte : 1 byte  
  short : 2 byte  
  int : 4 byte  
  long : 4 byte  
  float : 4 byte  
  double : 8 byte

## 상수와 리터럴

- `final` 키워드로 상수를 선언할 수 있다.  
  `final int MAX = 10;`

- 이 때 `MAX`를 상수라 하고, `10`을 리터럴이라 한다.

- 리터럴을 저장할 때 `1_000`과 같이 `_`를 중간에 넣어서 자릿수를 구분할 수 있다.

- 리터럴 또한 타입을 정할 수 있다. 접미사로 `L` 또는 `l`을 붙이면 정수형 `long`타입이 되고 `f`, `d`를 붙이면 실수형 `float`, `double` 타입이 된다.

  - 리터럴 타입을 지정하지 않으면 정수형의 경우 `long`타입으로, 실수형의 경우 `double`타입이 디폴트로 지정된다. 이 때 `float pi = 3.14;`와 같이 사용하면 `float` 변수에 `double` 리터럴을 저장하므로 컴파일 에러가 발생한다.

  - 16진수 표기는 접두사 `0x`를, 8진수는 `0`을 붙인다. 2진수는 `0b`를 붙인다.

## 문자 리터럴과 문자열 리터럴

- 문자열 객체를 지원하며 덧셈 연산자로 문자열을 결합할 수 있다.

  - 이 때 문자열과 결합되는 다른 **모든 타입**은 문자열로 변환한다.

  - 이를 이용해서 `(int)7`을 `7 + ""`과 같이 실행하여 문자열 7로 바꿀 수 있다.

  - ```
    String name = "Java";
    String str = name + 16.0;
    ```
    위의 코드에서 `str`을 출력하면 `Java16.0`이 출력된다.

## 임의의 값 생성하기

- `Math.random()`을 사용하면 0.0 이상 1.0 미만의 double 값을 리턴한다. 따라서 0 ~ 9 사이의 정수형 난수를 만드려면 `(int)Math.random() * 10`과 같이 사용하면 된다.

## 출력 - printf()

- `println()`을 사용하여 출력하면 변수의 값을 그대로 출력하고 자동으로 줄바꿈을 한다. 그러나 실수를 소수점 둘째자리까지 출력한다던가, 정수를 16진수로 출력하는 등 변수의 타입과는 다른 형식으로 출력하고 싶을 때 `printf`를 이용할 수 있다.

- `printf`는 C언어와 같은 형식으로 사용하며 형식 지정자 또한 같다.  
  %b : 불리언 형식  
  %d : 10진수 정수
  %o : 8진수 정수  
  %x : 16진수 정수  
  %f : 부동 소수점 실수  
  %e : 지수 표현  
  %c : 문자  
  %s : 문자열  
  2진수 출력은 지원하지 않으므로 따로 메서드를 사용해야 한다.

- `%5d`와 같이 사용하면 필드 5칸을 확보해서 오른쪽 정렬하여 출력한다.  
  `%-5d`와 같이 사용하면 필드 5칸을 확보해서 왼쪽 정렬하여 출력한다.  
  `%05d`와 같이 사용하면 필드 5칸을 확보해서 공백을 0으로 채워 출력한다.  
  `%14.10f`와 같이 사용하면 전체 14자리 중 소수점 아래 10자리만 출력한다.  
  `%.8s`와 같이 사용하면 문자열을 왼쪽에서 8글자만 출력한다.

- 형식 지정자 `%x`와 `%o`에 `#`을 사용하면 접두사 `0x`와 `0`을 붙여서 출력한다.

- C언어에서는 `char`타입을 `%d`로 출력할 수 있지만 자바에서는 꼭 형변환 후에 출력해야 한다.

## 입력 - Scanner

- `Scanner`클래스를 이용하여 화면에서 입력받을 수 있다.

- `import java.util.*;`과 같이 사용하여 `Scanner`클래스를 사용할 수 있다.

- `Scanner sc = new Scanner(System.in);`과 같이 `Scanner`객체를 생성한다.

- 주요 메소드

  - next( ) : 문자열을 띄어쓰기로 구분하여 리턴한다.

  - nextLine( ) : `\n`이 나오기 전까지의 문자열을 모두 리턴한다. `\n`은 버린다.

  - nextInt( ) : 정수를 띄어쓰기로 구분하여 리턴한다. 다른 타입에 대해서도 `nexttypename`으로 사용 가능하다. 마지막에 들어오는 `\n`은 무시하므로 버퍼를 비워줘야 한다.

    - `sc.nextLine();`와 같이 사용하면 버퍼를 비울 수 있다.

  - close( ) : `Scanner`의 사용을 종료한다. 마지막에 꼭 붙여주자.

  - hasNext( ) : 현재 입력된 토큰이 있으면 true, 아니면 새로운 입력이 들어올 때 까지 기다린다. 터미널이 종료되면 종료된다.

## 정수형의 표현형식과 범위

- 모든 정수형은 부호있는 정수이므로 가장 왼쪽의 비트를 부호 비트로 사용한다. 따라서 n비트 정수형 자료형은 $-2^{n-1}$ ~ $2^{n-1} - 1$의 값을 표현할 수 있다.
  - 그러므로 다뤄야할 정수가 `int`의 범위(약 $\pm 20$억)를 넘어간다면 `long`를 사용할 수 있다.

---

# 연산자 Operator

## 연산자의 우선순위와 결합규칙

- 논리 연산자 `AND`는 `OR`보다 우선순위가 높으므로 둘 다 사용되는 경우 괄호를 사용하자.

- 대입연산자의 경우 결합규칙이 오른쪽에서 왼쪽이다. 따라서 `x = y = 3`과 같은 문장이 가능하다.

## 연산자와 형변환

- 같은 정수형, 실수형 변수더라도 크기가 다른 타입끼리 연산을 하는 경우 꼭 결과를 명시적으로 형변환해주자.

  ```
  int a = 1_000_000;
  int b = 2_000_000;

  long c = a * b; //잘못된 문장
  long c = (long)a * b //옳은 문장
  ```

- 정수형 숫자들의 연산 결과는 기본적으로 `int`기 때문에 연산의 결과가 `int`의 범위를 넘는 경우 `long a = 1_000_000 * 1_000_000L`과 같이 사용해야 한다.

- 정수형 나눗셈의 경우 무조건 **버림**한다. 이를 **반올림**으로 바꾸려면 0.5를 더하고 나눠주면 된다.

  - 버림 예시

    ```
    float pi = 3.141592f;
    float shortPi = (int)(pi * 1000) / 1000f;
    ```

  - 반올림 예시
    ```
    float pi = 3.141592f;
    float shorPi = (int)(pi * 1000 + 0.5) / 1000.0;
    ```

- `float`타입과 `double`타입을 비교할 때는 정밀도 차이에 의해 많은 오류가 발생할 수 있다. 따라서 꼭 `double`타입을 `float`타입으로 변환하여 비교해야 한다.
  - `float`타입을 `double`타입으로 변경하면 그저 가수를 늘리고 0으로 채울 뿐이므로 정밀도는 전혀 향상되지 않는다.

## 문자열 비교

- `==`을 사용해서 비교할 수 있다. `==`을 사용하는 경우 객체의 문자열을 비교하는 것이 아닌, 객체가 완전히 같은지만 비교하기 때문에 같은 문자열이라도 `new`를 사용했는지, 아닌지에 따라 결과가 달라지기에 권장하지 않는다.

- `equals()`메서드를 사용하면 쉽게 비교할 수 있다.
  - `s1.equals(s2);`와 같이 사용하며 문자열이 같으면 `true`를 아니라면 `false`를 리턴한다.

## 비트연산자

- `|` : OR연산자  
  `&` : AND연산자, 1로 AND를 한 비트만 뽑아낼 수 있다.  
  `^` : XOR연산자, 같은 값을 두고 XOR을 사용하면 원래 값을 리턴한다.  
  `~` : 비트 전환 연산자  
  `<<` : 왼쪽으로 비트 이동, 빈자리는 0으로 채워진다.

  - `x << n`은 $x * 2^n$과 같다.

  `>>` : 오른쪽으로 비트 이동, 빈자리는 0으로 채워진다.  
   \* `x >> n`은 $x / 2^n$과 같다.

---

# 조건문과 반복문

## switch문의 제약조건

- `switch`문의 조건식 결과는 정수 또는 문자열이어야 한다.

- `case`문의 값은 정수 상수만 가능하며, 중복되지 않아야 한다.

## 향상된 for문

- `for-each`또한 지원한다. C++의 `ranged-for-loop`와 사용법은 같다.

  - ```
    for(int i : arr){

    }
    ```

## 이름 붙은 반복문

- 알고리즘을 짜다보면 중첩된 반복문을 한 번에 break하고싶은 상황이 생긴다. 이 때 반복문에 이름을 붙이고 break문이나 continue문에 이름을 붙여서 한 번에 중단할 수 있다.
  - ```
    class named-for{
      public static void main(String[] args){
        Loop1 : for(int i = 2; i <= 9; i++){
              for(int j = 1; j <= 9; j++){
                if(j == 5) break Loop1;
              System.out.printLn(i+j);
              }
        }
      }
    }
    ```

---

# 배열 Array

## 배열의 선언과 생성

- `타입[] 변수이름;`과 같이 배열을 선언한다.

  - `int[] score;`

- `변수이름 = new 타입[길이]`와 같이 배열을 생성한다.

  - `score = new int[5];`

  - `int[] score = new int[5];`도 가능하다.

- 기본적으로 0으로 초기화된다.

- 배열의 길이는 0이어도 된다.

- `배열 이름.length` : 배열의 길이 리턴

## 배열의 길이 변경하기

1. 더 큰 배열을 새로 생성한다.

2. 기존 배열의 내용을 새로운 배열에 복사한다.

- 위의 과정을 통해 배열의 길이를 변경할 수 있지많 많은 비용이 발생한다.

## 배열의 초기화

- 기본적으로 배열을 생성할 때 초기화할 수 있다. 하지만 이 경우 `new int[]`는 생략할 수 없다.

  - ```
    int[] score;
    score = new int[]{50, 60, 70};
    ```

- 배열의 선언과 생성을 동시에 할 때는 `new int[]`를 생략할 수 있다.

  - ```
    int []score = new int[]{50, 60, 70};
    int []score2 = {50, 60, 70};
    ```

- 메서드를 호출해야하는 경우 `new int[]`를 생략할 수 없다.

  - ```
    int res = add(new int[]{10, 20, 30});
    ```

## 배열의 출력

- 배열이 가리키는 값이 아닌, 배열 자체를 출력하면 `타입@주소`의 형식으로 출력된다.

  - `[I@14318bb`와 같이 출력되며 `[I`는 1차원 int배열이라는 뜻이고 뒤의 숫자는 16진수이다.

  - 예외적으로 `println`을 통해 char형 배열 자체를 출력하면 각 요소가 구분자없이 문자열처럼 출력된다.

- `Arrays.toString(배열이름)` 메서드는 배열의 요소들을 `[arr[1], arr[2], ...]`과 같이 만들어서 리턴하므로 출력할 때 이용하기 편하다.

  - ```
    int[] Arr = {10, 20, 30, 40};
    System.out.println(Arrays.toString(Arr));
    ```
    과 같이 사용하면 `[10, 20, 30, 40]`이 출력된다.

## 배열의 복사

- ```
  int[] arr = new int[5];
  int[] tmp = new int[arr.length*2];
  for(int i=0;i < arr.length;i++)
    tmp[i] = arr[i];

  arr = temp;
  ```

  위와 같이 배열의 길이를 늘려서 복사할 수 있으며 `arr = tmp`는 참조변수 `arr`이 새로운 배열을 가리키게 한다.

- `System.arraycopy()`를 사용하는 것이 더 효율적이다.
  `System.arraycopy(num, 0, newNum, 0, num.length);`  
  위와 같이 사용하면 배열`num[0]`에서 배열`newNum[0]`으로 `num.length`만큼 복사한다는 듯이다.

## String 클래스

- 문자배열로도 초기화할 수 있다.

  - ```
    char[] chArr = {'A', 'B'};
    String str = new String(chArr);
    ```

- String클래스는 char배열에 메서드를 추가한 객체이다.

- String객체는 읽을 수만 있고 내용을 변경할 수 없다. 그저 새로운 내용의 문자열을 생성할 수 있다.

- String클래스의 간단한 메서드만 보자.

  - `char charAt(int index)` : 문자열에서 해당 index에 있는 문자를 반환한다.

  - `String substring(int from, int to)` : 문자열에서 `from ~ to`범위의 문자열을 반환한다. 이 때 `to`는 범위에 포함되지 않는다.

  - `boolean equals(Object obj)` : 문자열의 내용이 obj와 같은지 확인한다.

  - `char[] toCharArray()` : 문자열을 char배열로 변환해서 반환한다.

## String배열의 초기화

- String은 기본적으로 null로 초기화된다.

- String은 클래스이므로 `String[] name = new String[2]`만 수행하면 `name`이라는 참조변수 배열(사이즈 2)만 생성 되었다. 따라서

  ```
  String[] name = new String[2];
  name[0] = new String("Kim");
  ```

  과 같이 초기화해야하지만 간략하게 초기화하는 방법이 허용된다.

  ```
  String[] name = new String[2];
  name[0] = "Kim";
  ```

- String 또한 문자열이 저장되어있는 주소를 저장하는 참조형 변수이다. "따라서 `name[0]`에는 `"Kim"`을 가리키는 주소가 저장되어있고 거기로 가면 `"Kim"`이 있는 주소가 저장되어있다. 이는 C의 이중포인터와 비슷한 방법이라 이해하면 된다.

## 커맨드 라인을 통해 입력받기

- 프로그램을 실행할 때 클래스 이름 뒤에 공백문자로 구분하여 여러 개의 문자열을 프로그램에 전달할 수 있다.

  - main메서드가 담긴 클래스의 이름 뒤에 문자열을 전달할 수 있고, 이는 main메서드 내에서 `args`로 전달하는 String배열에 전달되는 것이다.

  - `c:\jdk1.8\work\ch5>hava MainTest abc 123` 과 같이 사용하면 `args[0] = "abc"`이고 `args[1] = "123"`이다.

    - 이 때 문자열 "123"을 숫자 123으로 바꾸려면 `int num = Integer.parseInt("123");`과 같이 할 수 있다.

# 다차원 배열

## 2차원 배열의 선언

- `타입[][] 변수이름;`과 같이 선언한다.

  - `int[][] score;`

- `타입 변수이름[][];`으로도 선언할 수 있다.

  - `int score[][];`

- 참조 변수를 선언한 뒤 `new`로 생성해야 한다.

  - `int score[][] = new int[2][3];`

## 향상된 for문을 통한 2차원 배열 접근

- ```
  for(int[] i : score)
    for(int j : i)
      ...
  ```
  과 같이 사용한다. 이 때 `int[]`를 사용하므로써 배열의 한 행에 접근한다.

## 가변 배열

- 자바에서는 다차원 배열을 **배열의 배열**의 형태로 처리한다. 따라서 각 행마다 열의 길이를 다르게 선언할 수 있다.

  - ```
    int[][] score = new int[2][];
    score[0] = new int[3];
    score[1] = new int[5];
    ```

    더 간략하게도 생성할 수 있다.

  - ```
    int[][] score = {
      {100, 100, 100}
    , {1, 2, 3, 4, 5}
    };
    ```

---

# 객체지향 프로그래밍Ⅰ

## 인스턴스의 생성과 사용

- ```
  클래스명 변수명;
  변수명 = new 클래스명();
  ```

  과 같이 인스턴스를 생성할 수 있다.

  - `Tv t;`를 수행하면 `Tv`클래스 타입의 참조변수 `t`를 선언한다. 이 때 `t`는 아직 인스턴스를 가리키지 않으므로 비어있다.

  - `t = new Tv();`를 수행하면 `Tv`클래스의 인스턴스를 메모리의 빈 공간에 생성하고 참조변수 `t`가 그 메모리를 가리킨다.

  - ```
    Tv t1 = new Tv();
    Tv t2 = new Tv();
    ```
    위의 코드를 실행하면 `Tv`클래스의 인스턴스가 서로 다른 공간에 두 개가 생성된다. 그리고 `t2 = t1;`을 하면 참조변수 `t2`가 `t1`이 가리키는 메모리 영역을 가리키게 된다. 따라서 기존에 `t2`가 가리키고 있던 메모리 영역은 접근할 수 없다.

## 객체 배열

- `Tv[] tvArr = new Tv[3];`과 같이 객체 배열을 생성할 수 있다. 이 때 `tvArr`은 아직 참조변수 배열만 생성 된 것이다. 따라서 각 원소는 **참조변수의 기본값인 null**로 초기화된다.

- ```
  Tv[] tvArr = new Tv[3];
  for(int i=0;i<tvArr.length;i++)
    tvArr[i] = new Tv();
  ```
  혹은
  ```
  Tv[] tvArr = new Tv[3];
  Tv tvArr = {new Tv(),
              new Tv(),
              new Tv()};
  ```
  와 같이 객체 배열을 생성하여 사용할 수 있다.

## 멤버 변수

- 인스턴스 변수

  - 클래스 영역에 선언되며, 클래스의 인스턴스를 생성할 때 만들어진다.

- 클래스 변수

  - 클래스 영역에 `static`을 붙여 선언된 변수이다. 인스턴스에 소속되지 않고 모든 인스턴스가 공통으로 사용한다. 따라서 클래스가 메모리에 올라가면 생성된다.

  - `Variables` 클래스의 클래스 변수 `cv`를 사용하려면 `Variables.cv`와 같이 사용한다.

- 지역변수

  - 클래스 영역 이외에 메서드, 생성자, 초기화 블럭 내부 등에 선언된 변수이다.

---

## JVM의 메모리 구조

- 메서드 영역

  - 프로그램 실행 중 어떤 클래스가 사용되면, 해당 클래스파일을 읽어서 분석하여 클래스 데이터를 메서드 영역에 저장한다. 클래스변수 또한 이 영역에 저장된다.

- 힙

  - 인스턴스들이 힙에 생성된다. 메서드가 작업을 마치면 할당되었던 공간은 반환되어 비어진다.

  - 호출스택의 제일 위에 있는 메모리가 현재 실행 중인 메서드이다.

  - 메서드를 호출한 순서대로 아래에 깔린다.

## 기본형 매개변수와 참조형 매개변수

- 기본형 매개변수는 값을 읽기만 할 수 있다.

- 참조형 매개변수는 값을 읽고 쓸 수 있다.

- 기본형 매개변수를 메서드에 매개변수로 사용하면 값의 복사만 일어나서 그 매개변수를 변경해도 원본은 변경되지 않는다.

- 반환타입이 **참조형**이면 메서드가 **객체의 주소**를 반환한다는 것을 의미한다.

## 클래스 멤버와 인스턴스 멤버간의 참조와 호출

- 같은 클래스에 속한 멤버들끼리는 별도의 인스턴스 생성 없이도 서로를 참조, 호출이 가능하다.

  - 단, 클래스멤버가 인스턴스 멤버를 참조, 호출하려면 인스턴스를 생성해야 한다.

  - 인스턴스 멤버가 존재하는 시점에는 클래스 멤버가 항상 존재한다.

  - 클래스 멤버가 존재하는 시점에는 인스턴스 멤버가 **존재하지 않을** 수 있다.

- `MenberCall`이라는 클래스를 생성하고 그 인스턴스 메소드 `instanceMethod`를 사용해보자.

  - ```
    MemberCall c = new MemberCall();
    int result = c.instanceMethod();
    ```
    위의 방법 말고도 익명의 객체를 생성해서 바로 대입할 수 있다.
    ```
    int result = new MemberCall().instanceMethod();
    ```
    단 위의 방법은 참조변수를 선언하지 않았기 때문에 생성된 `MemberCall`객체는 더 이상 사용할 수 없다.

## 가변인자와 오버로딩

- 가변인자는 `타입... 변수명`과 같이 선언하며 매개변수를 동적으로 지정할 수 있게 한다.

- 가변인자 외에도 매개변수가 더 있다면 가변인자를 매개변수 중 가장 마지막에 선언해야 한다.

- 가변인자를 이용하다보면 오버로딩된 메서드끼리 명확하게 구분이 되지 않는 경우가 있다. 이 경우들을 조심해야 한다.

## 생성자

- 인스턴스가 생성될 때 자동으로 호출된다.

- 클래스 내에 선언되며, **생성자의 이름은 클래스의 이름과 같아야 한다.** 또 **생성자는 리턴 값이 없다.**

- 생성자 또한 오버로딩이 가능하므로 하나의 클래스에 여러 개의 생성자가 존재할 수 있다.

- `Card c = new Card();`를 수행하면 일어나는 단계는 다음과 같다.

  1. 연산자 `new`에 의해 `heap`메모리에 `Card`클래스의 인스턴스가 생성된다.

  2. 생성자 `Card()`가 호출되어 수행된다.

  3. 연산자 `new`의 결과로 생성된 `Card`인스턴스의 주소가 반환되어 참조변수 `c`에 저장된다.

- 아무 생성자도 만들지 않으면 컴파일러가 기본적으로 아무 동작도 수행하지 않고 아무 매개변수도 받지 않는 **기본 생성자**를 추가한다.

  - 따라서 매개변수를 받는 생성자를 만들고 인스턴스를 생성할 때 매개변수를 주지 않으면 기본 생성자가 없기에 에러가 난다.

## 생성자에서 다른 생성자 호출하기

1. 호출할 생성자의 이름으로 클래스이름 대신 **this**를 사용한다.

2. 한 생성자에서 다른 생성자를 호출할 때는 반드시 첫 줄에서만 호출이 가능하다.

   위의 두 조건을 만족하면 생성자 간에도 서로 호출이 가능하다.

- ```
  class Car{
    String color;
    String gearType;
    int door;

    Car(String color){
      this(color, "auto", 4);
    }

    Car(String color, String gearType, int door){
      this.color = color;
      this.gearType = gearType;
      this.door = door;
    }
  }
  ```

  - 원래 클래스의 멤버 변수들을 초기화할 때는
    ```
    Car(String c, String g, int d){
      color = c;
      gearType = g;
      door = d;
    }
    ```
    위와 같이 `this`키워드를 사용하지 않고도 초기화 할 수 있다. 하지만 지역 변수와 멤버 변수의 이름이 둘 다 `color`로 같은 경우 `this`키워드를 사용하면 멤버 변수를, 그냥 사용하면 지역 변수를 지정한다.

- `this()`는 생성자이고 `this`는 멤버 변수를 지정하는 키워드이다.

## 생성자를 이용한 인스턴스의 복사

- ```
  Car(Car c){
    color = c.color;
    gearType = c.gearType;
    door = c.door;
  }
  ```
  위와 같이 복사 생성자를 정의하여 사용할 수 있다. `Object`클래스에 정의된 `clone`메서드를 사용하는 방법도 간편하다.

## 변수의 초기화

- 멤버변수와 배열의 초기화는 선택적이지만, **지역변수의 초기화는 필수적이다.**

## 초기화 블럭

- ```
  Car(){
    count++;
    serialNo = count;
    color = "White";
  }
  Car(String color){
    count++;
    serialNo = count;
    this.color = color;
  }
  ```

  위와 같은 상황에서 `count++`과 `serialNo = count`의 경우 다른 생성자인데도 같은 문장이 중복되었다. 이런 상황에서 인스턴스 블럭에 초기화 블럭을 넣어주면 생성자 호출 전에 공통된 초기화를 먼저 진행한다.

  - ```
    {
      count++;
      serialNo = count;
    }
    Car(){
      ...
    }
    ...
    ```

- 클래스 초기화 블럭 또한 사용 가능하며 일반 인스턴스 초기화 블럭 앞에 `static`키워드를 붙이면 된다.

## 멤버변수의 초기화 시기와 순서

- 클래스변수는 클래스가 처음 로딩될 때 단 한 번 초기화 된다.

  - **기본값 -> 명시적초기화 -> 클래스 초기화 블럭**과 같은 순서로 이루어진다.

- 인스턴스변수는 인스턴스가 생성될 때마다 각 인스턴스별로 초기화가 이루어진다.

  - **기본값 -> 명시적초기화 -> 인스턴스 초기화 블럭 -> 생성자**와 같은 순서로 이루어진다.

---

# 객체지향 프로그래밍 Ⅱ

## 클래스 상속

- 부모 클래스를 `Parent`라 하고 상속받으려는 자식 클래스를 `Child`라 하면 아래와 같이 사용한다.

  ```
  class Child extends Parent{
    ...
  }
  ```

- C++과는 다르게 **생성자와 초기화 블럭은 상속되지 않는다.** 멤버만 상속된다.

- **단일 상속**만 허용한다. 즉 조상은 하나만 허용된다.

- Child **is-a** Parent라 한다.

## 클래스 포함

- 한 클래스의 멤버변수로 다른 클래스 타입의 참조변수를 선언하는 것이 클래스 포함관계이다.

- 원을 표현하는 `Circle`클래스를 정의하자.

  ```
  calss Circle {
    int x;
    int y;
    int r;
  }
  ```

  그리고 좌표상의 점을 다루는 `Point`클래스가 다음과 같이 있다고 하자.

  ```
  class Point{
    int x;
    int y;
  }
  ```

  `Point`클래스를 사용해서 `Circle`클래스를 다음과 같이 바꿀 수 있다.

  ```
  class Circle{
    Point c = new Point();
    int r;
  }
  ```

- Circle **has-a** Point라 한다.

- ```
  Point p = new Point(150, 150);
  Circle c = new Circle(p, 50);
  ```
  위와 같은 문장을 줄여서 아래와 같이 사용할 수 있다.
  ```
  Circle c = new Circle(new Point(150, 150), 50);
  ```

## Object클래스

- `Object`클래스는 모든 클래스 상속계층도의 최상위에 있는 조상클래스이다. 다른 클래스로부터 상속을 받지 않는 클래스는 컴파일러가 자동으로 `extends Object`를 추가한다.

## 오버라이딩

- 조상 클래스의 메서드를 재정의하여 자손 클래스가 사용하는 것이다.

- 재정의할 메서드는 **이름, 매개변수, 반환타입이 모두 같아야 한다.**

- 접근 제어자를 **조상 클래스보다 좁은 범위로 변경할 수 없다.**

- 예외는 **조상 클래스보다 많이 선언할 수 없다.**

- 인스턴스 메서드를 static메서드로 또는 그 반대로 변경할 수 없다.

## super

- `super`는 자손 클래스에서 조상 클래스로부터 상속받은 멤버를 참조하는데 사용되는 참조 변수이다.

- `this`처럼 상속받은 멤버와 자신의 멤버가 이름이 같을 때 사용한다.

- `static`메서드에서는 `this`와 `super`모두 사용할 수 없다.

- `super.조상 메서드`처럼 메서드에도 사용 가능하다.

## super()

- `this()`처럼 조상 클래스의 생성자를 호출하는 생성자이다.

- 자손 클래스의 생성자 첫 줄에는 반드시 조상 클래스의 생성자를 호출해야 한다. 그렇지 않으면 컴파일러는 자동으로 생성자의 첫 줄에 `super();`를 삽입한다.

  - 컴파일러가 자동으로 초기화해주지만 조상 생성자가 오버로딩된 생성자나 매개변수를 사용하는 생성자인 경우는 직접 추가해주지 않으면 컴파일 에러가 뜬다.

## 패키지

- 패키지란, 클래스의 묶음이다. 클래스 또는 인터페이스를 포함시킬 수 있으며 관련된 클래스들끼리 그룹 단위로 묶어놓고 관리할 수 있다.

- 같은 이름의 클래스 일지라도 서로 다른 패키지에 존재하는 것이 가능하다. 따라서 자신만의 패키지 체계를 유지함으로써 다른 개발자가 개발한 클래스 라이브러리의 클래스와 이름이 충돌하는 것을 피할 수 있다.

- 패키지는 물리적으로 하나의 디렉토리이고 그 안의 클래스 파일이 해당 패키지의 클래스가 된다.

  - 예를 들어, `java.lang.String`클래스는 `java`의 서브디렉토리인 `lang`에 속한 `String.class`파일이다.

- 패키지도 디렉토리처럼 다른 패키지를 포함할 수 있고 `.`으로 구분한다.

  - 예를 들어 `java.lang`패키지는 `java`패키지의 하위 패키지이다.

- 중요 특징들을 정리하자면 다음과 같다.

  1. 하나의 소스파일에는 **첫 번째 문장으로 단 한 번의 패키지 선언만을 허용한다.**

  2. 모든 클래스는 **반드시 하나의 패키지에 속해야 한다.**

  3. 패키지는 `.`을 구분자로 하여 **계층구조로 구성할 수 있다.**

  4. 패키지는 물리적으로 클래스 파일(.class)을 포함하는 하나의 디렉토리이다.

## 패키지의 선언

- 클래스나 인터페이스의 소스파일(.java)의 맨 위에 `pacakage 패키지명;`을 적어주면 패키지가 선언된다.

- 패키지를 선언하지 않고 클래스를 만들면 `unnamed-package`에 자동으로 속한다.

- 큰 프로젝트나, Java API와 같은 클래스 라이브러리를 작성하는 경우 패키지를 구성하여 적용해야한다.

## import문

- 다른 패키지의 클래스를 사용하려면 원래는 패키지명이 포함된 클래스 이름을 사용해야 한다. 하지만 너무 불편하기에 `import 패지키명.클래스명`을 통해서 패키지를 `import`할 수 있다.

  - `import java.util.*`과 같이 사용하면 `java.util`의 패지키에 있는 모든 클래스를 가져올 수 있다.

  - 하지만 `import java.*`와 같이 사용한다고 해서 `java`의 패키지에 있는 모든 하위 패키지를 가져오는 것은 아니다.

## static import문

- 특정 패키지의 static 클래스를 가져올 때 사용한다.

- 예를 들어 콘솔에 출력하는 `System.out.println()`의 경우 사실 `System`패키지의 `out`클래스 중 `println`이라는 메서드를 사용하는 것이다.

  - 이를 `import static java.lang.System.out;`과 같이 `import`해주면 `out.println();`으로 사용가능하다.

## static 제어자

- static은 **클래스의**,**공통적인**의 의미를 가지고 있다. `static`이 붙은 멤버변수와 메서드, 초기화 블럭은 인스턴스가 아닌 모든 클래스가 공유한다.

- static메서드는 인스턴스 멤버들을 직접 사용할 수 없다.

- static초기화 블럭은 클래스가 메모리에 로드될 때 한 번 수행되며, 주로 static멤버 변수를 초기화할 때 사용한다.

## final 제어자

- final은 **마지막의**, **변경될 수 없는**의 의미를 가지고 있고 거의 모든 대상에 붙을 수 있다.

- final클래스는 자식 클래스를 만들 수 없다.

- final메서드는 오버라이딩을 통해 재정의 될 수 없다.

- final변수는 값을 변경할 수 없는 상수가 된다.

  - final이 붙은 변수는 일반적으로 선언과 초기화를 동시에 하지만, 인스턴스변수의 경우 생성자에서 초기화할 수 있다. 이 기능을 통해 같은 클래스의 final 멤버 변수이지만 인스턴스마다 값이 다르게 구현할 수 있다.

## abstract 제어자

- abstract는 **미완성의**의 의미를 가지고 있고 클래스와 메서드에만 붙을 수 있다.

- abstract 클래스는 클래스 내에 abstract 메서드가 선언되었음을 의미한다.

  - 추상 클래스는 미완성 설계도이므로 인스턴스를 생성할 수 없다.

- abstract 메서드는 선언부만 작성하고 구현부는 작성하지 않은 추상 메서드임을 의미한다.

- 주로 상속을 용도로 인터페이스를 제공하는 역할을 한다.

## 접근 제어자

- 멤버 또는 클래스에 사용되어 해당 멤버, 클래스를 외부에서 접근하지 못하도록 제한한다.

- private : 같은 클래스 내에서만 접근 가능하다.

- protected : 같은 패키지 내에서 혹은 다른 패키지의 자손클래스에서 접근이 가능하다.

- default : 접근 제어자를 지정하지 않으면 자동으로 default로 지정된다. 같은 패키지 내에서만 접근이 가능하다.

- public : 어디서든 접근할 수 있다.

## 생성자의 접근 제어자

- 보통 생성자의 접근 제어자는 클래스의 접근 제어자와 같지만, 다르게 지정할 수 있다.

- 생성자의 접근 제어자를 `private`로 지정하면 외부에서 생성자에 접근할 수 없으므로 인스턴스를 생성할 수 없다. 대신 클래스 내부에서는 인스턴스를 생성할 수 있다.

  - 이 경우 인스턴스를 생성해서 반환해주는 `public static`메서드를 제공하여 외부에서 이 클래스의 인스턴스를 생성할 수 있도록 할 수 있다.

  - 또 생성자가 `private`인 클래스는 다른 클래스의 조상 클래스가 될 수 없다. 자손 클래스의 인스턴스가 생성할 때 조상 클래스가 생성자를 호출해야 하는데, `private`이면 생성할 수 없기 때문이다.

## 제어자의 조합

- **메서드에 static과 abstract를 함께 사용할 수 없다.**

  - `static` 메서드는 몸통이 있는 메서드에만 사용할 수 있기 때문이다.

- **클래스에 abstrack와 final을 동시에 사용할 수 없다.**

  - `abstract` 클래스는 상속을 통해 확장되어야만 하고, `final`은 더이상 확장이 불가능 하다는 의미이기 때문이다.

- **abstract메서드의 접근 제어자가 private일 수 없다.**

  - `abstract` 메서드는 자손 클래스에서 반드시 접근해야 하기 때문이다.

- **메서드에 private와 final을 같이 사용할 필요는 없다.**

  - 접근 제어자가 `private`인 메서드는 오버라이딩될 수 없기 때문이다. `private`와 `final`모두 자손 클래스에서 접근할 수 없다.

## 다형성

- 다형성이란 **여러 가지 형태를 가지 수 있는 능력**을 의미하며, 자바에서는 **조상클래스 타입의 참조변수로 자손클래스의 인스턴스를 참조할 수 있도록 하게** 구현하였다.

- 아래의 예시로 살펴보자.

  ```
  class Tv{
    boolean power;
    int channel;

    void power()       {  power = !power; }
    void channelUp()   {  ++channel;      }
    void channelDown() {  --channel;      }
  }

  class CaptionTv extends Tv{
    String text;
    void caption{ ... }
  }
  ```

  위의 상황에서 조상 클래스 타입의 참조변수로 자손 클래스의 인스턴스를 참조하도록 하는 것이 가능하다.

  ```
  CaptionTv c = new CaptionTv();
  Tv        t = new CaptionTv();
  ```

  위와 같이 참조 변수 `c`, `t`를 선언하였을 때 `t`가 `CaptionTv`타입이라 할지라도, `CaptionTv`클래스의 멤버 중 `CaptionTv`에서 새로 정의한 `text`, `caption()`은 사용할 수 없다.

  - 즉 `t`와 `c` **둘 다 같은 타입의 인스턴스지만 참조변수의 타입에 따라 사용할 수 있는 멤버의 종류가 달라진다.**

  - 반대로 자손타입의 참조변수로 조상타입의 인스턴스를 참조할 수는 없다.
    ```
    CaptionTv c = new Tv();
    ```
    위의 문장은 불가능하다.

## 참조변수의 형변환

- 참조변수 또한 기본형 변수처럼 **상속관계에 있는 클래스 사이에서만** 형변환이 가능하다.

- 자손타입에서 조상타입으로 변환하는 `Up-casting`은 형변환을 생략 가능하다.

- 조상타입에서 자손타입으로 변환하는 `Down-casting`은 형변환 생략 불가능하다.

- 예를 들어, 조상 타입 `Car`과 그의 자손 `FireEngine`, `Ambulance`가 있다고 하자.

  - ```
    FireEngine f;
    Ambulance a;
      a = (Ambulance)f;
    ```

    위의 코드는 `FireEngine`과 `Ambulance`가 상속관계가 아니기에 불가능하다.

  - ```
    Car car = null;
    FireEngine fe = new FireEngine();
    FireEngine fe2 = null;

    car = fe;
    fe2 = (FireEngine)car;
    ```

    위의 예시에서 `FireEngine`을 `Car`로 형변환하는 Up-casting은 형변환이 생략 가능하고, `Car`을 `FireEngine`으로 형변환하는 Down-casting은 형변환이 생략 불가능하다.

- 아까 예시로 든 `Tv = new CaptionTv();`도 사실은 `Tv t = (Tv)new CaptionTv();`의 생략된 형태이다.

## instance of연산자

- 참조변수가 참조하고 있는 인스턴스의 실제 타입을 알아보기 위해 `instanceof`연산자를 사용할 수 있다.

  - `c instanceof FireEngine`와 같이 사용할 수 있고, `c`가 참조하고 있는 인스턴스의 실제 타입이 `FireEngine`이라면 `true`를, 아니라면 `false`를 리턴한다.

- 정확하게 같은 타입 외에도, 조상타입의 인스턴스에도 `true`를 리턴한다. 따라서 모든 참조변수에 `instanceof Object`를 하면 `true`를 리턴한다.

- 어떤 타입에 대해 `instanceof`연산의 결과가 `true`라는 것은 검사한 타입으로 형변환이 가능하다는 것을 뜻한다.

## 참조변수와 인스턴스의 연결

- 메서드의 경우 조상 클래스의 메서드를 자손의 클래스에서 오버라이딩한 경우, 참조 변수의 타입에 관계없이 항상 오버라이딩된 메서드가 호출된다.

- 하지만 멤버변수를 오버라이딩하는 경우 참조변수의 타입에 따라서 다르게 호출된다.

  - 즉 멤버변수를 오버라이딩했을 때 조상타입의 참조변수를 사용하면 조상 클래스의 멤버변수가 사용되고, 자손타입의 참조변수를 사용하면 자손 클래스의 멤버변수가 사용된다.

## 매개변수의 다형성

- 다음과 같이 정의된 클래스 `Product`와 이를 상속받은 `Tv, Computer, Audio`클래스가 있다고 가정하자. 또 위의 클래스들을 구매하는 구매자 `Buyer`클래스가 있다고 가정하자.

  ```
  class Product{
    int price, bonusPoint;
  }
  class Buyer{
    int money = 100, bonusPoint = 0;
  }
  ```

  `Buyer`클래스에 물건을 구입하는 기능의 메서드를 추가해보자. 그럼 구매하는 물품이 `Tv`, `Computer`, `Audio` 중 무엇인지 모르기에 다음과 같이 매개변수를 `Tv`, `Computer`, `Audio`를 매개변수로 사용하는 메서드를 생성해야만 한다.

  ```
  void buy(Tv t){
    money = money - t.price;
    bonusPoint = bonusPoint + t.bonusPoint;
  }
  void buy(Computer c){
    money = money - t.price;
    bonusPoint = bonusPoint + t.bonusPoint;
  }
  void buy(Audio a){
    money = money - t.price;
    bonusPoint = bonusPoint + t.bonusPoint;
  }
  ```

  이렇게 되면, 제품의 종류가 늘어날 때마다 `Buyer`클래스에 새로운 `buy`메서드를 추가해야 한다.

- 그러나 메서드의 매개변수에도 **다형성을 적용할 수 있다.**
  ```
  void buy(Product p){
    money = money - p.price;
    bonusPoint = bonusPoint + p.bonusPoint;
  }
  ```
  위와같이 **매개변수의 다형성**을 이용하여 메서드를 만들면 `Product`클래스를 상속받기만 하면, 그 클래스에 대해 `buy`를 사용할 수 있다.
  ```
  Buyer = new Buyer();
  Tv t = new Tv();
  b.buy(t);
  b.buy(new Computer());
  ```
  위의 예시에서 `Tv t = new Tv(); b.buy(t);`를 `b.buy(new Tv());`와 같이 사용할 수 있음을 알아두자.

## 여러 종류의 객체를 배열로 다루기

- 조상타입의 참조변수로 자손타입의 객체를 참조하는 것이 가능하다는 것을 배웠다.

  ```
  Product p1 = new Tv();
  Product p2 = new Computer();
  Product p3 = new Audio();
  ```

- 위의 코드를 `Product`타입의 참조변수 배열로 처리할 수 있다.
  ```
  Product p[] = new Product[3];
  p[0] = new Tv();
  p[1] = new Computer();
  p[2] = new Audio();
  ```

## 추상클래스

- 추상 클래스란, 미완성된 클래스를 뜻하며 미완성된 메서드를 포함하는 클래스라는 뜻이다.

- 추상 클래스는 새로운 클래스를 작성할 때 바탕이 되는 조상클래스로서 중요한 의미를 갖는다.

- `abstract`키워드를 클래스 선언부 앞에 붙여서 사용할 수 있다.

  ```
  abstract class 클래스이름{
    ...
  }
  ```

- 추상클래스도 생성자, 멤버변수, 메서드 모두를 가질 수 있다.

## 추상메서드

- 메서드의 선언부만 작성하고 구현부는 작성하지 않은 채 남겨둔 메서드를 추상메서드라한다.

- 메서드의 내용이 상속받는 클래스에 따라 달라지는 경우 주로 사용하며, 자손 클래스가 조상 클래스의 추상 메서드를 상속받아 오버라이딩하여 사용한다.

- 추상메서드 역시 `abstract`키워드를 앞에 붙여주고 구현부 없이 바로 `;`를 적어주면 된다.
  ```
  abstract 리턴타입 메서드이름();
  ```

## 인터페이스

- 인터페이스는 일종의 추상클래스이다.

- 추상클래스처럼 추상메서드를 갖는다.

- 추상클래스보다 추상도가 높아서 몸통을 갖춘 일반 메서드 또는 멤버변수를 가질 수 없다. 오직 추상메서드와 상수만을 멤버로 가질 수 있다.

- ```
  interface 인터페이스이름 {
    public static final 타입 상수이름 = 값;
    public abstract 메서드이름(매개변수목록);
  }
  ```

  과 같이 사용하며 몇 가지 제약사항이 있다.

  - **모든 멤버변수는 public static final이어야 하며 생략할 수 있다.**

  - **모든 메서드는 public abstract이어야 하며 생략할 수 있다.**

## 인터페이스 상속

- 인터페이스는 인터페이스로부터만 상속받을 수 있으며, 클래스와 달리 다중상속을 허용한다.

- 일반적인 클래스들과 달리 `Object`클래스와 같은 최고 조상이 없다.

## 인터페이스 구현

- 인터페이스도 추상클래스처럼 인스턴스를 생성할 수 없으며, 반드시 **클래스에 상속하여 사용해야 한다.**

- ```
  class 클래스이름 implements 인터페이스이름{

  }
  ```

  위와같이 클래스에서 상속받을 수 있으며, 구현한다는 의미로 `implements`를 사용한다.

- 구현하는 인터페이스의 메서드 중 일부만 구현한다면, `abstract`를 붙여 추상클래스로 구현해야 한다.

  ```
  abstract class Fighter implements Fightable{
    public void move(int x, int y){...}
  }
  ```

- 상속과 구현을 동시에 할 수 있다.
  ```
  class Fighter extends Unit implements Fightable{
    public void move(int x, int y){...}
    public void attack(Unit u)    {...}
  }
  ```

## 인터페이스를 이용한 다형성

- 인터페이스 타입의 참조변수로 **이를 구현한 클래스의 인스턴스를 참조, 형변환 할 수 있다.**

  ```
  Fightable f = (Fightable)new Fighter();
  ```

  - 위와 같이 사용하면 `Fightable`에 정의된 멤버들만 호출 가능하다.

- **리턴타입이 인터페이스라는 것은 메서드가 해당 인터페이스를 구현한 클래스의 인스턴스를 반환한다는 것을 의미한다.**

## 인터페이스의 장점

- **개발시간을 단축시킬 수 있다.**

  - 메서드를 호출하는 개발부에서 메서드의 내용에 관계없이 선언부만 알면 되기에 인터페이스를 이용해 프로그램을 작성할 수 있다. 그리고 동시에 인터페이스를 구현하는 클래스가 작성될 때까지 기다리지 않고도 그 기능을 사용하는 다른 프로그램도 작성할 수 있다.

- **표준화가 가능하다.**

  - 프로젝트에 사용되는 기본 틀을 인터페이스로 작성하면 표준화가 가능하다.

- **서로 관계없는 클래스들에게 관계를 맺어줄 수 있다.**

- **독립적인 프로그래밍이 가능하다.**

- 인터페이스가 잘 사용되는 예시들을 보자.

  - 예를 들어 한 데이터베이스 회사가 제공하는 특정 데이터베이스를 사용하는데 필요한 클래스를 사용해서 프로그램을 작성했다면 이 프로그램은 다른 종류의 데이터베이스를 사용하기위 해서는 전체 프로그램 중에서 데이터베이스 관련된 부분은 모두 변경해야할 것이다.  
    그러나 데이터베이스 관련 인터페이스를 정의하고 이를 이용해서 프로그램을 작성하면, 데이터베이스의 종류가 변경되더라도 프로그램을 변경하지 않도록 할 수 있다.

  - 스타크래프트에 나오는 유닛을 클래스로 표현하고 상속 관계를 표현하면  
    Unit -> Ground Unit ㅤ-> Marine  
    ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ -> SCV  
    ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ -> Tank  
    ㅤㅤ -> AirUnit ㅤㅤ ㅤ-> Dropship  
    위와 같이 표현할 수 있다. 이 때 `SCV`에게 `Tank`와 `Dropship`과 같은 기계화 유닛을 수리할 수 있는 기능을 제공하기 위해 `repair`메서드를 정의하면 다음과 같을 것이다.

    ```
    void repair(Tank t){
      ...
    }
    void reapair(Dropship p){
      ...
    }
    ```

    이런 식으로 수리가 가능한 유닛의 개수만큼 오버로딩된 메서드를 정의해야 할 것이다. 이를 피하기위해 공통조상의 타입으로 다형성을 이용해서 정의하자.

    ```
    void repair(GroundUnit g){
      ...
    }
    void repair(Dropship p){
      ...
    }
    ```

    이렇게 해도 최소한 2개의 메서드는 필요하다. 또 `GroundUnit`의 자손 중에서도 수리할 수 없는 유닛이 있기때문에 부적절하다. 가장 좋은 방법은 `Repairable`이라는 인터페이스를 정의하고 수리가 가능한 유닛에게만 구현하도록 하면 된다.

    ```
    interface Repairable{
      ...
    }

    class SCV extends GroundUnit implements Repairable{
      ...
    }

    class Tank extends GroundUnit implements Repairable{
      ...
    }

    class Dropship extends AirUnit implements Repairable{
      ...
    }
    ```

    이제 이 3개의 클래스에는 같은 인터페이스를 구현했다는 공통점이 생겼다. 따라서 이제 `repair`메서드의 매개변수 타입을 `Repairable`로 선언하면 손쉽게 구현할 수 있다.

    ```
    void repair(Repairable r){
      ...
    }
    ```

## 디폴트 메서드와 static 메서드

- 원래는 인터페이스에 추상 메서드만 선언할 수 있는데, JDK1.8부터 static메서드와 디폴트 메서드도 추가할 수 있게 되었다.

- 인터페이스에서는 조상 클래스에 새로운 메서드를 추가하는 것이 상당히 힘들다. 인터페이스에 새로운 메서드를 추가한다는 것은, 추상 메서드를 추가한다는 것이고, 이 인터페이스를 구현한 모든 클래스에 새로운 메서드를 구현해야 한다.  
  이 문제를 해결하기 위해 **디폴트 메서드**를 고안해 내었다. 디폴트 메서드는 추상 메서드의 기본적인 구현을 제공하는 메서드로, 추상 메서드가 아니다.

- `default`키워드를 붙여서 메서드를 선언하면 되며, 일반 메서드처럼 몸통이 있어야한다. 또 접근 제어자가 `public`이며 생략 가능하다.

## 내부 클래스

- 내부 클래스는 서로 긴밀한 관계에 있는 두 클래스 사이에서, 클래스 내에 선언된 클래스이다.

- **내부 클래스의 장점**

  - 내부 클래스에서 외부 클래스의 멤버들을 쉽게 접근할 수 있다.

  - 코드의 복잡성을 줄일 수 있다.

- 내부 클래스는 외부 클래스를 제외하고는 다른 클래스에서 잘 사용되지 않는 것이 좋다.

- 내부 클래스의 선언 위치에 따라 다음과 같이 구분되어 진다.

  - **인스턴스 클래스** : 외부 클래스의 멤버변수 선언위치에 선언하며, 외부 클래스의 인스턴스 멤버처럼 다루어진다.

  - **스태틱 클래스** ㅤ: 외부 클래스의 멤버변수 선언위치에 선언하며, 외부 클래스의 static 멤버처럼 다루어진다.

  - **지역 클래스** ㅤㅤ: 외부 클래스의 메서드나 초기화블럭 안에 선언하며, 선언된 영역 내부에서만 사용될 수 있다.

  - **익명 클래스** ㅤㅤ: 클래스의 선언과 객체의 생성을 동시에 하는 이름없는 일회용 클래스이다.

- 내부 클래스와 외부 클래스의 변수 이름이 같을 때, 내부 클래스의 메서드에서 변수 앞에 `this`를 붙이면 내부 클래스의 변수를, `외부 클래스명.this`를 붙이면 외부 클래스의 변수를 가리킨다.

## 익명 클래스

- 익명 클래스는 이름이 없고, 클래스의 선언과 객체의 생성을 동시에 하기 때문에 단 한번만 사용될 수 있고 오직 하나의 객체만을 생성할 수 있다.

- 생성자도 가질 수 없으며, 오로지 단 하나의 클래스를 상속받거나 단 하나의 인터페이스를 구현할 수 있다.

- 익명클래스로 변환하는 예를 살펴보자.
  ```
  class Inner{
    public static void main(String[] args){
      Button b = new Button("Start");
      b.addActionListener(new EventHandler());
    }
  }
  class EventHandler implements ActionListene
    public void actionPerformed(ActionEvent e){
      System.out.println("ActionEvent occurred!!");
    }
  }
  ```
  위의 `EventHandler`를 익명클래스로 변경해보자.
  ```
  class Inner{
    public static void main(String[] args){
      Button b = new Button("Start");
      b.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
           System.out.println("ActionEvent occurred!!");
         }
        } //익명 클래스의 끝
     }; //
    } //main의 끝
  } //class의 끝
  ```

---

# 예외처리

## 프로그램 오류

- 자바는 런타임에 발생할 수 있는 오류를 `에러`와 `오류`로 구분하였다. 메모리 부족이나 스택오버플로우같이 일단 발생하면 복구할 수 없는 비교적 심각한 오류를 **에러**라 하고, 발생하더라도 수습될 수 있는 비교적 덜 심각한 오류를 **예외**라고 한다.

- 자바에서는 이 에러와 예외를 클래스로 정의하였다. 모든 예외의 최고 조상은 `Exception`클래스이다.

  - 예외 클래스는 두 그룹으로 나누어 질 수 있다.  
    **Exception클래스와 그 자손들**(RuntimeException과 자손들 제외)을 `Exception클래스들`이라 하고,  
    **RuntimeException클래스와 그 자손들**을 `RuntimeException클래스들`이라 하자.

  - RuntimeException클래스들은 주로 프로그래머의 실수에 의해 발생될 수 있는 예외들로 자바의 프로그래밍 요소들과 관계가 싶다.

  - Exception클래스들은 주로 외부의 영향으로 발생할 수 있는, 프로그램의 사용자들의 동작에 의해 발생하는 경우가 많다.

## 예외처리하기 - try-catch문

- 예외처리를 통해서 **프로그램의 비정상 종료를 막고, 정상적인 실행상태를 유지할 수 있다.**

- 예외를 처리하기 위해서는 `try-catch`문을 사용한다.

  ```
  try{
    // 예외가 발생할 가능성이 있는 문장들을 넣는다.
  } catch (Exceptiona1 e1){
    // Exception1이 발생했을 경우, 이를 처리하기 위한 문장을 적는다.
  } catch (Exception2 e2){
    ...
  } catch (ExceptionN eN){
    ...
  }
  ```

  `try-catch`문은 메서드 내에서도 사용할 수 있고, `try`블럭 안에서, `catch`블럭 안에서 모두 사용 가능하다.

- 실제 사용 예시를 한 번 보자.

  ```
  class ExceptionEx2 {
    public static void main(String[] args){
      int number = 100;
      int result = 0;

      for(int i=0; i < 10; i++){
        result = number / (int)(Math.random() * 10);
        System.out.println(result);
      }
    }
  }
  ```

  위의 예제는 변수 `number`에 저장되어 있는 값 100을 0 ~ 9사이의 임의의 정수로 나눈 결과를 출력한다. `random()`을 사용했기에 0이 나올 수 있고, 0으로 나누면 **ArithmeticException** 예외가 발생한다. 이 예외를 처리해보자.

  ```
  class ExceptionEx2 {
    public static void main(String[] args){
      int number = 100;
      int result = 0;

      for(int i=0; i < 10; i++){
        try{
            result = number / (int)(Math.random() * 10);
            System.out.println(result);
        } catch(ArithmeticException e){
            System.out.println("0");
        }
      }
    }
  }
  ```

## try-catch문에서의 흐름

- **try블럭 내에서 예외가 발생하는 경우**

  1. 발생한 예외와 일치하는 catch블럭이 있는지 확인한다.

  2. 일치하는 catch블럭을 찾으면, 그 catch블럭 내의 문장들을 수행하고 전체 try-catch문을 빠져나가서 그 다음 문장을 계속 수행한다. 만약 일치하는 catch블럭이 없으면 예외는 처리되지 못한다.

- **try블럭 내에서 예외가 발생하지 않은 경우**

  1. catch블럭을 거치지 않고 전체 try-catch문을 빠져나가서 수행을 계속한다.

- 아래의 예시와 함께 이해하자.

  ```
  class Exception5 {
    public static void main(String[] args){
      System.out.println(1);
      System.out.println(2);
      try{
        System.out.println(3);
        System.out.println(0/0);
        System.out.println(4);
      } catch (ArithmeticException ae) {
        System.out.println(5);
      }

      System.out.println(6);
    }
  }
  ```

  위 예시의 결과는 1, 2, 3을 출력하고 다음 try블럭에서 예외가 발생해서 try블럭을 벗어난다. **따라서 4는 출력하지 않고** 5와 6을 출력한다.

## 예외의 발생과 catch블럭

- catch블럭의 `()`내에는 처리하고자 하는 예외와 같은 타입의 참조변수를 선언해야한다. 예외가 발생하면, 발생한 예외에 해당하는 클래스의 인스턴스가 만들어진다. 그리고 이 예외가 발생한 문장이 try블럭 내에 있다면, 이 예외를 처리할 수 있는 catch블럭이 있는지 찾게 된다.

  - 이 때 찾는 과정에서 catch블럭의 괄호내에 선언된 참조변수의 종류와 생성된 예외클래스의 인스턴스에 `instanceof`연산자를 이용하여 `true`가 나올 때 까지 검사는 계속된다. 따라서 `Exception`클래스 타입의 참조변수를 이용하면 어떤 종류의 예외가 발생하더라도 이 catch블럭에 의해 처리된다.

## printStackTrace()와 getMessage()

- **printStackTrace()** : 예외발생 당시의 호출스택에 있었던 메서드의 정보와 예외 메세지를 출력한다.  
  **getMessage()** : 발생한 예외클래스의 인스턴스에 저장된 메세지를 얻을 수 있다.
  ```
  class ExceptionEx8 {
    public static void main(String[] args) {
      System.out.println(1);
      System.out.println(2);
      try {
        System.out.println(3);
        System.out.println(0/0);
        System.out.println(4);
      } catch (ArithmeticException ae) {
        as.printStackTrace();
        System.out.println("예외메세지 : " + ae.getMessage());
      }
      System.out.println(6);
    }
  }
  ```

## 멀티 catch블럭

- 여러 catch블럭을 하나의 catch블럭으로 합칠 수 있다. `|`기호로 연결하면 된다.
  ```
  try{
    ...
  }catch(ExceptionA | ExceptionB a){
    ...
  }
  ```
  이 때 `|`로 연결한 예외 클래스가 조상과 자손 관계에 있어서는 안된다.

## 예외 발생시키기

- 키워드 `throw`를 이용해 발생시킬 수 있다. 아래의 예시와 같이 발생시키면 된다.

  ```
  Exception e = new Exception("고의로 발생시킴");
  throw e;
  ```

- Exception인스턴스를 생성할 때, 생성자에 String을 넣어 `getMessage()`로 출력할 수 있다.
  ```
  class Exception{
    public static void main(String[] args){
      try{
        Exception e = new Exception("테스트용 에러");
        throw e;
        //위의 두 문장을 `throw new Exception("테스트용 에러");`와 같이 사용할 수 있다.
      } catch(Exception e){
        System.out.println("에러 메세지 : " + e.getMessage());
      }
    }
  }
  ```
  위의 예시의 출력은 `에러 메세지 : 테스트용 에러`이다.

## 메서드에 예외 선언하기

- 예외를 처리하는 방법에는 지금까지 배운 try-catch문 외에 예외를 메서드에 선언하는 방법이 있다. 메서드의 선언부에 키워드 `throws`를 사용해서 메서드 내에서 발생할 수 있는 예외를 적기만하면 된다. 예외들은 쉼표로 구분한다.

  ```
  void method() throws Exception1, Exception2, ... {
    ..
  }
  ```

  만일 아래와 같이 모든 예외의 최고조상인 `Exception`클래스를 메서드에 선언하면 모든 예외에 대해 예외처리를 해준다.

  ```
  void method() throws Exception{
    ...
  }
  ```

  - 예외를 메서드에 선언하면, 예외가 발생하면 자신을 호출한 메서드에게 예외를 전달하여 예외처리를 맡기는 것이다. 즉, 어느 한 곳에서는 반드시 try-catch문으로 예외처리를 해주어야 한다.

- 메서드에 예외처리를 하면 호출스택에 있는 메서드들을 따라 전달되면서 예외를 처리한다.

  ```
  class Exception{
    public static void main(String[] args){
      method1();
    }

    static void method1() throws Exception{
      method2();
    }

    static void method2() throws Exception{
      throw new Exception();
    }
  }
  ```

  위의 소스코드를 실행하면 발생한 예외와 호출스택의 내용이 출력되면서 종료된다. 실행결과는 다음과 같다.

  ```
  java.lang.Exception
      at Exception.method2(Exception.java:11)
      at Exception.method1(Exception.java:7)
      at Exception.main(Exception.java:3)
  ```

  위의 결과에서, 예외가 발생했을 때 `method2`, `method1`, `main` 순으로 호출스택에 있었고 가장 위에있는 `method2`에서 예외가 발생했다는 것을 알 수 있다.

- Java API문서를 통해 사용하고자 하는 메서드의 선언부와 `Throws"`를 보고, 이 메서드에서 발생할 수 있는 예외들에 대해 알아두는 것이 좋다.

## finally블럭

- finally블럭은 try - catch문의 끝에 선택적으로 덧붙여 사용할 수 있으며, 예외의 발생여부에 관계없이 실행되어야할 코드를 포함시켜 사용한다.
  ```
  try {
    ...
  } catch(Exception e){
    ...
  } finally{
    ...
  }
  ```

## 자동 자원 반환 - try-with-resources문

- try-catch문의 변형 형태로, `try-with-resources`가 추가되었다. 주로 입출력과 관련된 클래스를 사용할 때 유용하다.

- 사용 예시를 보자.

  ```
  try{
    fis = new FileInputStream("score.dat");
    dis = new DataInputStream(fis);
      ...
  } catch (IOException ie){
    ie.printStackTrace();
  } finally{
    dis.close();
  }
  ```

  위의 코드는 `DataInputStream`을 사용해서 파일로부터 데이터를 읽는 코드인데, 데이터를 읽는 도중 예외가 발생하더라도 `dis`를 닫도록 구성하였다. **하지만 `close()`가 예외를 발생시키는 경우는 문제가 생긴다.** 따라서 아래와 같이 해야한다.

  ```
  try{
    fis = new FileInputStream("score.dat");
    dis = new DataInputStream(fis);
      ...
  } catch (IOException ie){
    ie.printStackTrace();
  } finally{
    try{
      if(dis != null)
        dis.close();
    } catch(IOException ie){
      ie.printStackTrace();
    }
  }
  ```

  위와 같이 `close()`에서 발생할 수 있는 예외를 처리하도록 변경했는데, 코드의 가독성이 너무 떨어지고 try블럭과 finally블럭에서 모두 예외가 발생하면, try블럭의 예외는 무시된다는 것이다. 따라서 위의 코드를 `try-with-resources`문으로 바꿔보자.

  ```
  try(FileInputStream fis = new FileInputStream("score.dat");
      DataInputStream dis = new DataInputStream(fis)){

    while(true){
          score = dis.readInt();
          System.out.println(score)l;
          sum += score;
    }
  } catch (EOFException e){
    System.out.prinln("점수의 총합은 " + sum + "입니다.");
  } catch (IOException ie){
    ie.printStackTrace();
  }
  ```

  위와같이 사용할 수 있고, `try-with-resources`문의 괄호안에 객체를 생성하는 문장을 넣으면, 이 객체는 따로 `close()`를 호출하지 않아도 try블럭을 벗어나면 자동으로 닫아준다. 그 다음에 catch블럭 또는 finally블럭이 수행된다.

- try-with-resources문에 의해 자동으로 객체를 닫아주려면, **클래스가 `AutoCloseable`이라는 인터페이스를 구현한 것이어야만 한다.**

## 사용자정의 예외 만들기

- 기존의 정의된 예외 클래스 외에 프로그래머가 새로운 예외 클래스를 정의하여 사용할 수 있다. 하지만 가능한 기존의 예외클래스를 활용하는 것이 좋다.

- ```
  class MyException extends Exception{
    MyException(String msg){
      super(msg); //조상클래스의 생성자 호출
    }
  }
  ```

  Exception클래스로부터 상속받아 MyException클래스를 만들었다. 필요에 따라 멤버 변수나 메서드를 추가할 수 있다. 내가 만들 예외클래스도 메세지를 저장하려면 생성자를 정의할 때 String을 매개변수로 받아서 저장해주면 된다.

  ```
  class MyException extends Exception{
    private final int ERR_CODE;

    MyException(String msg, int errCode){
      super(msg);
      ERR_CODE = errCode;
    }

    MyException(String msg){
      this(msg, 100);
    }

    public int getErrCode(){
      return ERR_CODE;
    }
  }
  ```

## 예외 되던지기

- 한 메서드에서 발생할 수 있는 예외가 여럿인 경우, 몇 개는 try-catch문을 통해 메서드 내에서 자체적으로 처리하고, 나머지는 선언부에 지정하여 호출한 메서드에서 처리하도록 할 수 있다. 이는 **예외를 처리한 후에 인위적으로 다시 발생시키면 된다.**

- ```
  class Exception{
    public static void main(String[] agrs){
      try {
        method1();
      } catch(Exception e){
        System.out.println("main에서 처리되었습니다.");
      }
    }

    static void method1() throws Exception{
      try {
        throw new Exception();
      } catch(Exception e){
        System.out.println("method1에서 처리되었습니다.");
        throw e;
      }
    }
  }
  ```

  위의 코드의 실행 결과는 다음과 같다.

  ```
  method1에서 처리되었습니다.
  main에서 처리되었습니다.
  ```

  결과에서 알 수 있듯이 `method1()`과 `main()`의 catch블럭이 모드 수행되었다.

- 반환값이 있는 return문의 경우, catch블럭에도 return문이 있어야 한다. 하지만 catch블럭에서 예외 되던지기를 해서 호출한 메서드로 예외를 전달하면, return문이 없어도 된다.

## 연결된 예외

- 한 예외가 다른 예외를 발생시킬 수 있다. 예를 들어 예외 A가 예외 B를 발생시켰다면, A를 B의 `원인 예외`라 한다. `initCause`를 통해 원인 예외로 등록할 수 있고 `getCause()`를 통해 원인 예외를 반환할 수 있다. Exception클래스의 조상인 Throwable클래스에 정의되어 있기 때문에 모든 예외에서 사용가능하다.

# java.lang패키지와 유용한 클래스

## Object클래스

- `public boolean equals(Object obj)`

  - 객체 자신과 객체 `obj`가 같은 객체이면 true를 리턴한다.

  - 두 개의 참조변수가 같은 객체를 참조하고 있는지, 즉 참조변수에 저장된 주소값이 같은지를 판단하는 기능을 한다. 따라서 참조변수가 가리키는 객체의 값이 같은지를 판단하려면 `equals`를 재정의해야 한다.

  ```
  class Person{
    long id;

    public boolean equals(Object obj){
      if(obj instanceof Person)
        return id == ((Person)obj).id;
      else
        return false;
    }
  }
  ```

  - 위의 예시처럼 재정의해주면, 참조변수가 같은 객체를 참조하고, 그 값까지 같을 경우에만 true를 리턴한다.

  - `String`클래스 역시 `Object`클래스의 `equals`메서드를 재정의하여 참조하는 `String`이 갖는 문자열 값을 비교하도록 되어있다.

- `public int hashCode()`

  - 해시함수를 구현한 메소드이다. 찾고자하는 값을 입력하면, 그 값이 저장된 위치를 알려주는 해시코드를 반환한다.

  - `hashCode`메소드는 객체의 주소값으로 해시코드를 만들어 반환한다. 따라서 32bit-JVM에서는 서로 다른 두 객체는 결코 같은 해시코드를 가질 수 없지만, **64bit-JVM에서는 해시코드가 중복될 수 있다.**

  - 앞의 예시처럼 클래스의 인스턴스변수 값으로 객체의 같고 다름을 판단해야 한다면 `equals`처럼 `hashCode`메서드도 오버라이딩해야 한다.

  - `String`클래스의 `hashCode`메서드는 오버라이딩되어 문자열의 내용이 같으면 항상 동일한 해시코드를 리턴한다.

  - `System.identityHashCode(Object x)`는 객체의 주소값을 이용하기에 모든 객체에 대해 항상 다른 해시코드값을 반환한다. 따라서
    ```
    String str1 = new String("abc");
    String str2 = new String("abc");
    ```
    위와 같이 사용해도 `System`클래스의 `HashCode`를 사용하면 다른 해시코드를 리턴한다.

- `public String toString()`

  - 인스턴스의 정보를 문자열로 제공한다. `Object`클래스에 정의된 `toString`메서드를 보자.

  ```
  public String toString(){
    return getClass().getName()+"@"+Integer.toHexString(hashCode());
  }
  ```

  클래스를 작성하고 그냥 `toString`을 사용한다면 클래스이름에 16진수의 해시코드를 얻게 된다.

  - ```
    class Card{
      String kind;
      int number;

      Card(){
        this("SPADE", 1);
      }
      Card(String kind, int number){
        this.kind = kind;
        this.number = number;
      }
    }

    class CardToString{
      public static void main(String[] args){
        Card c1 = new Card();
        Card c2 = new Card();

        System.out.println(c1.toString());
        System.out.println(c2.toString());
      }
    }
    ```

    위의 예시의 실행 결과를 보자.

    ```
    Card@19e0bfd
    Card@139a55
    ```

    두 인스턴스는 같은 내용의 객체를 가리키지만, 참조변수가 다른 주소를 가리키기에 다른 해시코드를 가진다. 하지만 `String`클래스와 `Date`클래스의 `toString`메서드를 사용하면 다른 결과가 출력된다.

    ```
    class ToStringTest{
      public static void main(String[] args){
        String str = new String("JAVA");
        java.util.Date today = new java.util.Date();

        System.out.println(str.toString);
        System.out.println(today);
        System.out.println(today.toString());
      }
    }
    ```

    위 예시의 실행 결과를 보자.

    ```
    KOREA
    Fri Oct 23 21:48:29 KST 2015
    Fri Oct 23 21:48:29 KST 2015
    ```

    `String`클래스와 `Date`클래스는 `toString`메서드를 오버라이딩하여 사용하기에 다른 결과가 나타난다. 이처럼 위에서 정의한 `Card`클래스에서도 `toString`의 결과가 쓸모있는 정보를 제공하기 위해 오버라이딩해보자.

    ```
    class Card{
      String kind;
      int number;

      Card(){
        this("SPADE", 1);
      }
      Card(String kind, int number){
        this.kind = kind;
        this.number = number;
      }

      public String toString(){
        return "kind : " + kind + ", number : " + number;
      }
    }

    class CardToString{
      public static void main(String[] args){
        Card c1 = new Card();
        Card c2 = new Card("HEART", 10);

        System.out.println(c1.toString());
        System.out.println(c2.toString());
      }
    }
    ```

    위 예시의 실행 결과를 보자.

    ```
    kind : SPADE, number : 1
    kind : HEART, number : 10
    ```

    이제 더 쓸모있는 정보를 제공하게끔 오버라이딩 하였다. 이 때 주의할 점은 `Object`클래스의 `toString`이 `public`이므로 `Card`클래스의 `toString`의 접근제어자 또한 `public`으로 하였다는 것이다.  
    조상에 정의된 메서드를 자손에서 오버라이딩 할 때는 조상에 정의된 접근범위보다 같거나 더 넓어야 하기 때문이다.

- `protected Object clone()`

  - 이 메서드는 자신을 복제하여 새로운 인스턴스를 생성하는 일을 한다. 어떤 인스턴스에 대해 작업을 할 때, 원래의 인스턴스는 보존하고 `clone`메서드를 이용해서 새로운 인스턴스를 생성하여 작업을 할 때 주로 사용한다.

  - `Object`클래스의 `clone`은 단순히 인스턴스변수의 값만 복사하기에 **참조타입의 인스턴스 변수가 있는 경우, 클래스는 완전한 인스턴스 복제가 이루어지지 않는다.**

    - 예를 들어 배열의 경우, 복제된 인스턴스도 같은 배열의 주소를 갖기에 복제된 인스턴스의 작업이 원래의 인스턴스에 영향을 미친다. 따라서 이런 경우에는 꼭 오버라이딩하여 사용해야 한다.

  - `clone`을 사용하려면 복제할 클래스가 `Cloneable`인터페이스를 구현해야 하고, `clone`을 오버라이딩하면서 접근 제어자를 `protected`에서 `public`으로 변경해야 한다. 그래야만 상속관계가 없는 다른 클래스에서 `clone`을 호출할 수 있다. 또 반드시 예외처리를 해줘야 한다.

    ```
    class Point implements Cloneable{
      ...
      public Object clone{
        Object obj = null;
        try{
          obj = super.colne();
        } catch(CloneNotSupportedException e) { }
        return obj;
      }
    }
    ```

  - JDK 1.5부터 오버라이딩할 때 조상 메서드의 반환타입을 자손 클래스의 타입으로 변경을 허용하는 공변 반환타입이 추가되었다. 사용 예시를 보자.
    ```
    public Object clone{
      Object obj = null;
      try{
        obj = super.colne();
      } catch(CloneNotSupportedException e) { }
      return (Point)obj;
    }
    ```
    이처럼 공변 반환타입을 이용하면 실제 반환되는 자손 객체의 타입으로 반환할 수 있어 번거로운 형변환이 줄어든다는 장점이 있다.

  ```
  Point copy = (Point)original.clone();
  ```

  =>

  ```
  Point copy = original.clone();
  ```

  - `clone()`을 이용해서 배열을 복사할 수 있다.

  ```
  int[] arr ={1, 2, 3};
  int[] arrClone = arr.clone();
  ```

  배열 분 아니라, `java.util`패키지의 `Vector`, `ArrayList`, `LinkedList`, `HashSet`, `TreeSet`, `HashMap`, `TreeMap`, `Calendar`, `Date`와 같은 클래스들이 이와 같은 방식으로 복제가 가능하다.

  ```
  ArrayList list = new ArrayList();
      ...
  ArrayList list2 = (ArrayList)list.clone();
  ```

  - `clone`는 단순히 객체에 저장된 값을 그대로 복제할 뿐, 객체가 참조하고 있는 객체까지 복제하지는 않는다. 기본형 배열인 경우 문제가 없지만, 객체배열을 `clone`로 복제하는 경우에는 원본과 복제본이 같은 객체를 공유하므로 완전한 복제라고 보기 어렵다. 이러한 복제를 **얕은 복사**라고 한다. 얕은 복사에서는 **원본의 변경이 복사본에도 영향을 미친다.**  
    반면에 원본이 참조하고 있는 객체까지 복제하는 것을 **깊은 복사**라고 한다. 깊은 복사에서는 **원본의 변경이 복사본에 영향을 미치지 않는다.** 예를 들어 살펴보자.

  ```
  class Circle implements Cloneable{
    Point p;
    double r;

    Circle(Point p, double r){
      this.p = p;
      this.r = r;
    }

    public Circle clone(){ //얕은 복사
      Object obj = null;

      try{
        obj = super.clone(); //조상인 Object의 clone()를 호출한다.
      } catch(CloneNotSupportedException e){ }

      return (Circle)obj;
    }
  }
  ```

  `Circle`인스턴스 `c1`을 생성하고, `clone`으로 복제해서 `c2`를 생성하자.

  ```
  Circle c1 = new Circle(new Point(1, 1), 2.0);
  Circle c2 = c1.clone();
  ```

  얕은 복사이기때문에 `c1`과 `c2`는 같은 주소의 `Point`인스턴스를 가리키게 된다. 따라서 `c2`의 원 중심 위치를 변경하면 `c1`의 원 중심 위치 또한 변경된다. 깊은 복사 또한 구현해보자.

  ```
  class Circle implements Cloneable{
    Point p;
    double r;

    Circle(Point p, double r){
      this.p = p;
      this.r = r;
    }

    public Circle shallowCopy(){ //얕은 복사
      Object obj = null;

      try{
        obj = super.clone(); //조상인 Object의 clone()를 호출한다.
      } catch(CloneNotSupportedException e){ }

      return (Circle)obj;
    }

    public Circle deepCopy(){
      object obj = null;

      try{
        obj = super.clone();
      } catch(CloneNotSupportedException e){ }
    }

    Circle c = (Circle)obj;
    c.p = new Point(this.p.x, this.p.y);

    return c;
  }
  ```

  위와 같이 구현하면 복제된 객체가 원본이 **참조하고 있는 객체까지 복사하였다.** 따라서 복제된 객체는 원본과는 다른 주소의 `Point`객체를 가리키고 있다.

- `public final class Class implements...`

  - 이 메서드는 자신이 속한 클래스의 객체를 반환하는 메서드이다. `Class`객체는 이름이 `Class`인 클래스의 객체이다. `Class`객체는 클래스의 모든 정보를 담고 있으며, 클래스당 1개만 존재한다. 그리고 클래스 파일이 `클래스 로더`에 의해 메모리에 올라갈 때, 자동으로 생성된다.

    - 클래스 로더는 실행 시에 필요한 클래스를 동적으로 메모리에 로드한다. 먼저 기존에 생성된 클래스 객체가 메모리에 존재하면 객체의 참조를 반환하고 아니라면 클래스 패스에 지정된 경로를 따라서 클래스 파일을 찾는다. 못 찾으면 `ClassNotFoundException`이 발생하고 찾으면 해당 클래스 파일을 읽어서 `Class`객체로 변환한다.

  - 클래스의 정보가 필요할 때 `Class`객체에 대한 참조를 얻어야하는데, 해당 Class객체에 대한 참조를 얻는 방법은 여러 가지가 있다.

    ```
    Class cObj = new Card().getClass;
    Class cObj2 = Card.class;
    Class cObj3 = Class.forName("Card");
    ```

    특히 `forName`은 특정 클래스 파일을 메모리에 올릴때 주로 사용한다. `Class`객체를 통해 동적으로 객체를 생성할 수 있다.

    ```
    final class Card{
      String kind;
      int num;

      Card(){
        this("SPADE", 1);
      }

      Card(String kind, int num){
        this.kind = kind;
        this.num = num;
      }

      public String toString(){
        return kind + ":" + num;
      }
    }

    class ClassEx1{
      public static void main(String args[]){
        Card c = new Card("HEART", 3);
        Card c2 = Card.class.newInstance();
        //Card객체의 class객체를 받아서 인스턴스를 생성한다.

        Class cObj = c.getClass();

        System.out.println(c2.toString());
        System.out.println(cObj.getName());
        System.out.println(cObj.toGenericString());
        System.out.println(cObj.toString());
      }
    }
    ```

    위 예시의 실행결과를 보자.

    ```
    SAPDE:1
    Card
    final class Card
    class Card
    ```

## String클래스

- String클래스에는 문자열을 저장하기 위해 문자형 배열 참조변수 `value`를 인스턴스 변수로 정의해놓고 있다. 한 번 생성된 String인스턴스가 갖고 있는 문자열은 읽어올 수만 있고 변경할 수는 없다.

  - ```
    String a = "a";
    String b = "b";
    a = a + b;
    ```
    위의 예시처럼 문자열 결합을 통해 새로운 문자열을 만들어도 기존에 "a"의 주소의 값이 변경되는게 아닌, 새로운 주소에 문자열 "ab"가 생성되어 그 문자열을 가리키는 것이다.

- 문자열의 비교

  - 문자열을 만들 때 주로 사용하는 두 가지 방법이 있다.

    1. `String str1 = "abc";`

    2. `String str2 = new String("abc");`

    1번 방법은 문자열 리터럴 "abc"의 주소가 `str1`에 저장된다.  
    2번 방법은 새로운 "abc"라는 String 인스턴스를 생성하고 그것을 참조변수 str2에게 가르키게 한다.  
    1번 방법을 사용하면 이미 존재하는 문자열 리터럴을 재사용하는 것이고, 2번 방법은 `new`에 의해 항상 새로운 String인스턴스를 생성하는 것이다.  
    여기서 주목해야할 점은 **1번 방법을 사용하면, "abc"를 가리키는 모든 String 참조변수는 같은 주소를 가리킨다** 는 점이다. 따라서 이 경우에는 같은 문자열을 가리키는 String 참조 변수를 `str1 == str2`와 같이 비교하면 true를 리턴한다. 하지만 **2번 방법을 사용하면 같은 문자열을 가지고 있더라도 참조변수가 다른 주소를 가리킨다.** 따라서 같은 문자열을 가리키는 String 참조 변수를 `str3 == str4`와 같이 해도 false를 리턴한다.  
    따라서 **equals()를 사용하여 두 문자열의 내용을 비교해야 한다.**

- 자바 소스파일에 포함된 모든 문자열 리터럴은 **컴파일 타임에 클래스 파일에 저장된다.** 이 때 같은 내용의 문자열은 한 번만 같은 주소로 저장된다.

- 길이가 0인 문자열도 존재할 수 있다. `String s = "";`과 같이 사용하며 이 때 참조변수 s가 참조하고 있는 String인스턴스는 내부에 길이가 0인 char형 배열을 저장하고 있는 것이다. 단, `char c = '';`처럼 빈 문자열은 불가능하다.

  - 일반적으로 String은 빈 문자열로, char은 기본값인 `\u0000`으로 초기화한다.

- **String클래스의 자주 사용되는 메서드**

  - `String(String s)` : 문자열 `s`를 갖는 String인스턴스를 생성하는 생성자이다.

  - `String(char[] value)` : char형 배열로도 생성할 수 있다.

  - `String(StringBuffer buf)` : `StringBuffer`인스턴스가 갖고 있는 문자열과 같은 내용의 String인스턴스를 생성하는 생성자이다.

  - `char charAt(int index)` : `index`에 있는 문자를 리턴한다.

  - `int compareTo(String str)` : `str`과 사전순으로 비교한다. 같으면 0, 이전이면 음수, 이후면 양수를 리턴한다.

  - `String concat(String str)` : `str`을 뒤에 덧붙인다.

  - `boolean contains(CharSequance s)` : 문자열 `s`가 포함되었는지 검사한다.

  - `boolean endsWith(String suffix)` : 문자열 `suffix`로 끝나는지 검사한다.

  - `boolean equals(Object obj)` : 문자열 `obj`와 String인스턴스의 문자열을 비교한다. `obj`가 String이 아니면 false를 리턴한다.

  - `boolean equalsIgnoreCase(String str)` : `str`을 대소문자 구분없이 비교한다.

  - `int indexOf(int ch)` : 문자 `ch`가 문자열에 존재하는지 확인하여 존재한다면 그 index를 리턴하고, 없다면 -1을 리턴한다.

  - `int indexOf(int ch, int pos)` : 문자 `ch`가 문자열의 `pos`부터 확인하여 수행한다.

  - `int indexOf(String str)` : 문자열 `str`이 있는지 확인하여 그 index를 리턴하고, 없으면 -1을 리턴한다.

  - `String intern()` : 문자열을 상수풀에 등록한다. 이미 상수풀에 그 문자열이 있을 경우, 그 문자열의 주소값을 반환한다.

    - ex
      ```
      String s = new String("abc");
      String s2 = new String("abc");
      boolean b = (s==s2);
      boolean b2 = (s.equals(s2));
      boolean b3 = (s.intern() == s2.intern());
      ```
      `s`, `s2`를 `new`를 이용해서 생성하였기에, 상수풀에 "abc"를 등록해서 사용하지 않고, 새로운 인스턴스를 생성하였다. 따라서 `s == s2`는 false를 리턴한다. `s.equals(s2)`는 문자열의 내용으로 판단하기에 true를 리턴한다. `s.intern()`을 하면 "abc"를 상수풀에 추가하고 상수풀에 있는 "abc"를 `s`가 가리키게 한다, 그리고 그 주소값을 리턴한다. `s2.intern()`을 하면 상수풀에 이미 "abc"가 있어서 그 주소를 `s2`가 가리키게 하고 리턴한다. 따라서 true이다.

  - `int lastIndexOf(int ch)` : 문자 `ch`를 문자열의 끝부터 찾는다. 못 찾으면 -1을 리턴한다.

  - `int lastIndexOf(String str)` : 문자열 `str`을 문자열의 끝부터 찾는다. 못 찾으면 -1을 리턴한다.

  - `int length()` : 문자열의 길이를 리턴한다.

  - `String replace(char old, char nw)` : 문자열의 `old`문자를 모두 `nw`문자로 바꾸고 리턴한다.

  - `String replace(CharSequence old, CharSequance nw)` : 문자열의 `old`문자열을 모두 `nw`문자열로 바꾸고 리턴한다.

  - `String replaceAll(String regex, String replacement)` : 문자열 중 `regex`와 일치하는 것을 `replacement`로 모두 변경한다. 이 때 `replace`와의 차이점은 `replaceAll`의 `regex`는 정규식을 사용한다는 점이다. 나중에 정규식을 배우면 차이점을 이용할 수 있다. 지금은 그냥 똑같다고 생각하고 써도 될 것 같다.

  - `String replaceFirst(String regex, String replacement)` : 문자열 중 `regex`와 일치하는 것들 중 첫 번째 것만 `replacement`로 변경한다.

  - `String[] split(String regex)` : 문자열을 `regex`로 나누어 문자열 배열에 담아 반환한다.

  - `String[] split(String regex, int limit)` : 문자열을 `regex`로 나누어 문자열 배열에 담아 반환하되, 문자열 배열의 수를 `limit`로 정한다. `regex`로 나누어질 수 있지만, `limit`때문에 새로운 문자열 배열을 생성할 수 없는 경우 그냥 다 넣는다.

    - ```
      String animals = "dog, cat, bear";
      String[] arr = animals.split(",", 2);
      ```
      위 예제의 실행 결과는 아래와 같다.
      ```
      arr[0] = "dog"
      arr[1] = "cat, bear"
      ```

  - `boolean startsWith(String prefix)` : `prefix`로 시작하는지 검사한다.

  - `String substring(int begin)`  
    `String substring(int begin, int end)` : `begin`부터 `end`까지 문자열을 리턴한다. 단, `end` index의 문자는 포함되지 않으며, `end`를 지정하지 않으면 끝까지 포함한다.

  - `String toLowerCase()` : 문자열을 소문자로 변환하여 반환한다.

  - `String toString()` : 문자열을 반환한다.

  - `String toUpperCase()` : 문자열을 대문자로 변환하여 반환한다.

  - `String trim()` : 문자열의 왼쪽 끝과 오른쪽 끝에 있는 공백을 제거하여 반환한다.

  - `static String valueOf(boolean b)` : `b`를 문자열로 변환하여 반환한다, `boolean`외에도 `char`, `int`, `long`, `float`, `double`, `Object` 들이 가능하다.

  - `static String join(CharSequence delimiter, CharSequence elements)` : 문자열 `delimiter`로 구분해서 문자열 `elements`를 결합한다.

  - `static String format(String format, Object... args)` : `printf`와 같은 형식으로 출력을 위한 String 포맷을 만들어 리턴한다. 사용법은 `printf`와 같다.

    - ```
      String str = String.format("%d 더하기 "%d는 %d입니다.", 3, 5, 3 + 5);
      System.out.print(str)
      ```
      위 코드의 실행 결과는 `3 더하기 5는 8입니다.` 이다.

- **기본형 값을 String으로 변환하기**

  1. `valueOf()` 사용

     - ```
       int i = 100;
       String str1 = String.valueOf(i);
       ```

  2. 빈 문자열 더하기
     - ```
       int i = 100;
       String str2 = i + "";
       ```

  2의 방법이 더 간편하지만, 1의 방법의 성능이 더 좋다.

- **String을 기본형 값으로 변환하기**

  - `valueOf()` 사용
    ```
    int i = Integer.valueOf("100");
    ```
    반환 타입은 `int`가 아니라 `Integer`인데, 오토박싱에 의해 `int`로 자동 변환된다. 다른 자료형 값으로 변환하고 싶으면 `Float.value("~")`와 같이 사용하면 된다.

## StringBuffer클래스와 StringBuilder클래스

- String클래스는 인스턴스를 생성할 때 지정된 문자열 변경할 수 없지만 StringBuffer클래스는 변경이 가능하다. 내부적으로 문자열 편집을 위한 버퍼를 가지고있으며, StringBuffer인스턴스를 생성할 때 크기를 지정할 수 있다.

- StringBuffer클래스는 char형 배열의 참조변수를 인스턴스변수로 선언하고 있다. StringBuffer인스턴스가 생성될 때, **char형 배열이 생성되며 이를 인스턴스변수 `value`가 참조한다.**

- StringBuffer클래스의 인스턴스를 생성할 때는 `StringBuffer(int length)`를 사용해서 인스턴스를 생성한다. 버퍼의 크기를 지정해주지 않으면 16개의 문자를 저장할 수 있는 크기의 버퍼를 생성한다.

  ```
  public StringBuffer(int length){
    value = new char[length];
    shared = false;
  }
  public StringBuffer(){
    this(16);
  }
  public StringBuffer(String str){
    this(str.length() + 16);
    append(str);
  }
  ```

- **StringBuffer는 내용을 변경할 수 있다.** 예시를 통해 살펴보자.

  ```
  StringBuffer sb = new StringBuffer("abc");
  sb.append("123");
  ```

  `append()`는 반환타입이 StringBuffer이고 자신의 주소를 반환한다. 따라서 위와 같이 사용하면, `sb`의 내용 뒤에 "123"을 추가한다. 버퍼를 사용하기에 문자열마다 인스턴스를 생성하거나 상수풀에서 문자열을 사용하는 String과는 다르다. `append()`는 자신의 주소를 반환하므로 아래의 방법도 가능하다.

  ```
  sb.append("123").append("ZZ");
  ```

- String클래스에서는 `equals`메서드를 오버라이딩해서 문자열의 내용을 비교하도록 구현되어 있다. 하지만 StringBuffer클래스는 `equals`메서드를 오버라이딩 하지 않아서 `==`으로 비교하는 것과 같은 결과를 얻는다. 따라서 **StringBuffer인스턴스간의 비교는 `toString()`를 통해 StringBuffer를 String으로 변환하고 비교해야 한다.**

  ```
  StringBuffer sb = new StringBuffer("abc");
  StringBuffer sb2 = new StringBuffer("abc");

  String s = sb.toString();
  String s2 = sb2.toString();

  s.equals(s2);
  ```

- **StringBuffer클래스의 자주 사용되는 메서드**

  - `int capacity()` : StringBuffer인스턴스의 버퍼크기를 알려준다.

  - `int length()` : StringBuffer인스턴스의 버퍼에 담긴 문자열의 길이를 알려준다.

  - `char charAt(int index)` : `index`위치의 문자를 알려준다.

  - `StringBuffer delete(int start, int end)` : `start`부터 `end - 1`까지의 문자를 제거한다.

  - `StringBuffer deleteCharAt(int index)` : `index`의 문자를 제거한다.

  - `String insert(int pos, char c)` : `pos`위치에 문자를 추가한다. 두 번째 파라메터로는 `char[]`, `boolean`, `int`, `String`, `Object` 등 다양한 자료형이 가능하다.

  - `StringBuffer replace(int start, int end, String str)` : `start`부터 `end - 1`까지의 문자들을 주어진 문자열로 바꾼다.

    - ```
      StringBuffer sb = new StringBuffer("0123456");
      sb.replace(3, 6, "AB")
      ```
      위를 실행하면 `sb = "012AB6"`이다.

  - `StrinBuffer reverse()` : StringBuffer인스턴스에 저장되어 있는 문자열의 순서를 거꾸로 나열한다.

  - `void setCharAt(int index, char ch)` : `index`의 문자를 `ch`로 바꾼다.

  - `void setLength(int newLength)` : `newLength`로 문자열의 길이를 변경한다. 길이를 늘리는 경우에는 나머지 빈 공간을 널문자로 채운다.

  - `String toString()` : StringBuffer인스턴스의 문자열을 String로 변환한다.

  - `String substring(int start, int end)` : `start`부터 `end - 1`까지 String를 뽑아서 반환한다. 두 번째 파라메터를 지정하지 않으면 `start`부터 끝까지 뽑아낸다.

- **StringBuilder**

  - StringBuffer는 멀티쓰레드에 `thread safe`하도록 동기화되어있다. 아직 멀티쓰레드에 대해 배우지 않았지만, 동기화가 StringBuffer의 성능을 떨어뜨린다고 이해하면 된다. 따라서 멀티쓰레드로 작성된 프로그램이 아닌 경우, StringBuffer는 불필요하게 성능이 떨어져있는 상태이다.  
    따라서 StringBuffer에서 쓰레드의 동기화만 뺀 StringBuilder가 새로 추가되었다. StringBuffer대신 StringBuilder를 사용하도록 바꾸기만 하면 된다.

## Math클래스

- Math클래스의 생성자는 접근 제어자가 `private`이기 때문에, 다른 클래스에서 Math클래스의 인스턴스는 생성할 수 없고 메서드만 사용할 수 있다. Math클래스는 클래스 내 멤버 변수가 하나도 없고 상수 `E`와 `PI` 그리고 `static`메서드들로만 이루어져 있다.

- **올림, 버림, 반올림**

  - 소수점 `n`번째 자리에서 반올림을 하기 위해서는 `round()`를 사용하면 된다. 하지만 이 메서드는 항상 소수점 첫째자리에서 반올림을 해서 `long`으로 리턴한다. 따라서 `n`번째 자리에서 반올림을 하기 위해서는 **10의 n - 1제곱을 곱하고 `Math.round()`를 사용하고 다시 10의 n - 1제곱을 나눠주면 된다.** 주의해야 할 점은 10의 n - 1제곱으로 나눌 때 소수형 자료형을 사용해서 나눠야 한다는 점이다.

  - `rint()`메서드는 소수점 첫 째자리에서 반올림하고, 반환값이 `double`이다. 그리고 `round()`는 소수점 첫 째자리가 5일 때 더 큰 값으로 반올림 한다. 따라서 `round(-1.5)`의 값은 `-1`이다. 반면에, `rint()`는 가장 가까운 정수를 반환하므로 `rind(-1.5)`의 값은 `-2.0`이다.

  - `ceil`은 올림, `floor`은 버림이다. `ceil()`은 소수점을 버리면서 큰 정수쪽으로 올림을 하고 `floor`은 소수점을 버리면서 작은 정수쪽으로 버림을 한다. 따라서 `ceil(-1.5) = -1.000`이고 `floor(-1.5) = -2.000`이다.

- 이 외에도 다양한 수학과 관련된 메서드들이 많이 존재한다. 이들은 JAVA API를 살펴보면서 그때그때 익혀서 사용하는 편이 더 좋을 것 같다.

## 래퍼클래스

- 자바에서는 기본형 변수를 객체로 다루지 않는다. 그런데 기본형 변수도 객체로 다뤄야 하는 경우가 있다. 이 때 사용되는 것이 래퍼 클래스이다.

- 래퍼 클래스의 이름은 `char`형은 `Character`, `int`형은 `Integer` 나머지는 자료형 이름의 첫 글자를 대문자로 한 것이다.

- 래퍼 클래스의 생성자는 매개변수로 문자열이나 각 자료형의 값들을 인자로 받는다. 이 때 `new Integer("1.0")`과 같이 자료형에 맞지 않는 문자열을 매개변수로 사용하면 `NumberFormatException`이 발생한다.

- 래퍼 클래스들은 모두 `equals()`가 오버라이딩되어 있어서 주소값이 아닌, 객체가 가지고 있는 값을 비교한다.

- **Number클래스**

  - Number클래스는 추상클래스로 내부적으로 숫자를 멤버변수로 갖는 래퍼 클래스들의 조상이다. 기본형 중에서 숫자와 관련된 래퍼 클래스들은 모두 Number클래스의 자손이다.

- 래퍼 클래스에는 `타입.parse타입(String s)`형식의 메서드와 `타입.valueOf(String s)`메서드가 존재한다. 둘 다 문자를 숫자로 바꾸어준다. 전자는 반환값이 기본형이고 후자는 반환값이 래퍼 클래스 타입이다.

  ```
  static int parseInt(String s, int radix)
  static Integer value(String s, int radix)
  ```

  다른 진법의 숫자도 변환이 가능하도록 위의 메서드들도 정의가 되어있다.

- **오토박싱, 언박싱**

  - JDK1.5이전에는 기본형과 참조형 간의 연산이 불가능했기에 아래와 같이 래퍼 클래스로 기본형을 객체로 만들어야 했다. 그러나 이제는 기본형과 참조형 간의 덧셈이 가능하도록 컴파일러가 자동으로 변환하는 코드를 넣어준다.

    ```
    int i = 5;
    Integer iObj = new Integer(7);

    int sum = i + iObj;
    ```

    | 컴파일 전 코드                   | 컴파일 후 코드                   |
    | -------------------------------- | -------------------------------- |
    | `int i = 5;`                     | `int i = 5;`                     |
    | `Integer iObj = new Integer(7);` | `Integer iObj = new Integer(7);` |
    | `int sum = i + iObj;`            | `int sum = i + iObj.intValue();` |

    위와 같이 기본형 값을 래퍼 클래스의 객체로 자동 변환해주는 것을 **오토박싱**이라 하고, 반대로 변환하는 것을 **언박싱**이라 한다.
