<<<<<<< HEAD
# Today I Learned
* 기록은 기억을 지배한다.
* 천천히 차근차근 내가 배운것들, 배웠던것들을 정리한다.
***
## md
* [md파일 작성법](./md/README.md)
***
## JavsScript
* [JavaScript 기초](./JavaScript/README.md)
* [Back-End](./JavaScript/Backend/README.md)
=======
# TIL
* 아직은 지식이 너무 적기에 작성 규칙 없이 작성한다.
* 카테고리를 잘 나누어서 하이퍼링크로 구현 하는 것이 목표이다.
* 잘 모르는 api나 함수를 이용하면 공식사이트를 이용하거나 ctrl을 누르고 api를 클릭하여 선언을 살펴본다.
* * *
JavaScript 참고 사이트   [Link](https://developer.mozilla.org/ko/docs/Web/, 'MDN link')  
JavaScript Object 정리   [Link](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference)
#  2021.06.20
# TIL작성법 숙지 
## README.md 파일 작성법
* [Reference](https://gist.github.com/ihoneymon/652be052a0727ad59601, "refernece")
***
##  글머리 기호 : `*`,` +`, `-` 
```
* 1단계
  - 2단계
    + 3단계
      * 4단계
```
* 1단계
  - 2단계
    + 3단계
      * 4단계
***
## 코드 블럭
* " ``` " 로 묶어서 코드 블럭을 생성한다
```
    ````
    class Stack 
    {
        ...
    }

    ````
```
***
## 줄 나누기
* `***`을 이용하여 줄을 나눈다
***
## 참조 하이퍼 링크
* `[Google](https://google.com, "google link")` 과 같이 사용하면   
[Google](https://google.com, "google link") 을 클릭하면 URL로 가는 하이퍼링크를 생성할 수 있다.
***
## 강조
* 
```
*single asterisks*
_single underscores_
**double asterisks**
__double underscores__
~~cancelline~~
```
*single asterisks*   
_single underscores_   
**double asterisks**   
__double underscores__   
~~cancelline~~   
***
## 줄바꿈
* 들여쓰기는 띄어쓰기 네 개 줄바꿈은 띄어쓰기 세 개를 기준으로 인식한다.
***
## 이미지
* 
```
![Alt text](/path/to/img.jpg)
![Alt text](/path/to/img.jpg "Optional title")
``` 
으로 사용한다. 
***
***
***
# 2021.06.21
## JavaScript Index
* node.js를 이용하여 node 파일 명으로 간단히 실행한다.
***
## 웹사이트의 구동 방식
* HTML을 한줄 한줄씩 차례로 parsing하다가   `<script src="main.js"></script>`
 를 만나게 되면 `parsin`g을 멈춘 상태에서 js파일을 서버에서 받아서 실행한 다음 다시 `parsing` 하게 된다.   
  => script 안에 js파일을 포함하게 되면 속도가 많이 느려진다.
   
* `<body>` 의 제일 마지막부분에 `js`를 포함하게 되면 `parsing HTML`이 모두 끝나고 Page가 ready되면 스크립트를 `fetching`하고 `executing`한다.    
=> 사용자가 웹사이트의 스크립트를 제외한 기본 정보를 빨리 볼 수 있지만 웹사이트가 스크립트에 많이 의존하는 상황에서는 사용자가 정상적인 페이지를 보기 전까지 기다려야한다.
   
* `async`옵션을 사용하게 되면 `<script asyn src="main.js"></script>` `parsing`과 `fetching js`를 병렬적으로 진행하고 `fetching`이 끝나면 `parsing`을 `block`시키고 `executing`하는 방식으로 진행한다. 여러 스크립트들을 다운하는 경우 다운로드 속도에 따라 `executing`되는 순서가 정해진다.   
=> 빠르긴 하지만 `fetching`중인 스크립트를 조작하려는 경우 위험할 수 있고 HTML을 `parsing`하는 도중에 언제든지 `block`이 걸릴 수 있기에 사용자가 더 불편할 수 있다.
   
* defer옵션을 사용하게 되면 `<script defer src="main.js"></script>` `parsing`하면서 `fetching`을 다 해놓고 가장 마지막에 `executing`한다. 여러 스크립트를 다운하여도 정의된 순서대로 `excuting`한다.
***
## 콘솔에 출력
* `console.log("string");`
으로 화면에 문자열을 출력하거나 HTML과 연동하여 출력할 수 있다.
***
## JavaScript
* 굉장히 유연하기에 그만큼 위험하다.    
따라서 맨 윗줄에 ` 'use strict'; ` 를 선언하여서 상식적인 범위 안에서 JavaScript를 효율적이고 상식적으로 사용할 수 있다.
* `console.clear();` 를 이용하여 `log`를 지울 수 있다.
***
***
***
#  2021.06.22
#  JavaScript Variable
## Dynamic typing
* JavaScript는 C, Java와 다르게 변수의 자료형을 Runtime에 결정하며 이를 `Dynamic typing`이라 한다.
* `Dynamic typing`은 편리하지만 `'7' + 5`는 `string`으로 `'8' / '2'`는 `number`로 인식하는 등의 문제가 생기면서 개발자가 생각하는 변수의 자료형이 실제 자료형과 달라지는 경우가 많이 생긴다는 문제점이 있다. 그래서 `TypeScript`가 나오게 된다.
***
## Variable
* `let`으로 선언한다.
* `{}` block으로 묶여져있는 공간에서 정의된 변수는 지역변수이고 그렇지 않은 변수를 전역변수(`global scope`)라고 한다.
* `var`로 선언할 수 있지만 `var`로 변수를 선언하면 선언된 위치에 관계 없이 선언을 항상 가장 위로 끌어 올려 주는 `var hoisting` 문제 때문에 사용하지 않는다. 또 `var`는 `block scope`를 무시하고 항상 전역변수로 취급된다는 문제가 있다.
* `const`로 변수를 선언하면 `immutable` 변수를 생성한다.
***
## Number
* 숫자는 모두 `number` 자료형이며 `JavaScript`는 변수를 선언할 때 `dynamic`하게 작동해서 자료형을 신경 쓸 필요가 없다. 또 `number`는 특별한 값들로 `Infinity`, `-Infinity`, `NaN`(`string`을 `number`로 나누는 경우)가 정의되어 있다. 
* 변수에 대입할 숫자 마지막에 n을 붙이면 `bigint` 자료형으로 생성된다. `number`보다 많은 메모리를 사용하는 숫자이다. 
***
## String
* 문자와 문자열은 모두 `string` 자료형이다. 
* 백틱을 출력하기 위해서 `\백틱`으로 출력한다.
* 문자열 앞에 `+`를 붙이면 `number`로 형변환한다.
 ***
 ## Boolean
 * `boolean`   
 `false` = `0`, `null`, `undefined`, `NaN`, `''`   
 `true` = any other value
 * `null`은 아무것도 아닌 값으로 할당을 하는 것이고 `undefined`는 선언은 되었지만 아무런 값도 할당하지 않은 상태이다.
 ***
 ## Symbol
 * `Symbol` 자료형은 고유한 식별자를 위한 자료형이다.   
 ```
   const symbol1 = Symbol('id');
   const symbol2 = Symbol('id');
   //symbol1 != symbol2
 ```
 ```
   const symbol1 = Symbol.for('id');
   const symbol2 = Symbol.for('id');
   //symbol1 == symbol2
 ```
* `symbol`자료형은 출력할 때 반드시 `symbol1.description`을 통해 string으로 변환하여 출력해야 한다.
***
## Object
* `object` 자료형 C의 구조체와 비슷하다.
```
   const me = { name: 'me', age: 21};
```
과 같이 정의할 수 있다. `const`로 정의되었기에 `me`가 가리키는 메모리의 `reference`는 다른 `object`로 할당은 불가능하다.
```
   me = {name: `you`, age: 22};
```
는 불가능하지만
```
   me.name = 22;
```
는 가능하다.
* `object`는 주소를 가리키는 `reference`이므로 대입 연산자 역시 `call by reference`로 작동한다. 
***
## Funtion
* `funtion`또한 자료형으로 취급한다.
***
***
***
#  2021.06.23
#  JavaScript Operator
## String operators
* 문자열은 `+`로 결합할 수 있다. 더 편한 방법으로 문자열을 ``로 묶고 `&{`string`}!` 를 통해 이어서 쓰는 방식을 이용할 수 있다. 
 ```
   `value: &{greeting}!`
   `value: ` + greeting 
   //두 문장은 같은 의미이다.
 ```
***
## Numeric operators
* `**`연산자를 통해 제곱을 할 수 있다.   
 `2 ** 3 = 8`
***
## Logical operators
* `|| (or)` 연산자는 조건 중 `True`가 나오면 바로 그 조건으로 리턴한다. 따라서 연산에 시간이 걸리는 함수들을 조건의 마지막에 놔두는 것이 효율적이다.
* `PORT`에 값이 없으면 8000을 사용한다.
```
const PORT = +(process.env.PORT || 8000);
```
* `&&` 연산자는 조건 중 `False`가 나오면 바로 `False`를 리턴하고 아니라면 다음으로 넘어가면서 끝까지 넘어가면 마지막 조건을 리턴한다.
* `nullobject`가 `null`이 아닐때만 `something`을 받아오는 조건을 `if`가 아닌 `&&`연산자로 `nullobject && something`으로 쓸 수 있다.
* `num`에 값이 할당되었을 때만 출력한다.
```
   let num;
   num && console.log(num); 
```
***
## Equality
* `==`는 `type`을 신경쓰지 않고 `equlity`를 판단한다. `===`는 `type`과 함께 판단한다.
```
   const stringFive = '5';
   const numberFive = 5;
   stringFive == numberFive //True
   stringFive === numberFive //False
```
* `object`는 `momory address`를 저장하는 `reference`이므로 `Equility`를 판단할 때 같은 값이 있어도 가리키는 주소가 다르면 다르다고 판단할 수 있다.
```
   const obj1 = { id: 1};
   const obj2 = { id: 1};
   const obj3 = obj1;
   obj1 == obj2 //False
   obj1 == obj3 //True
```
* `0 === false`는 `0`이 `boolean`이 아니라서 `False`이고
`null === undefined`또한 둘의 `type`이 달라서 `False`이다.
***
그 외의 연산자 `switch`, `if`, `for`, `while`등은 C와 같은 문법을 사용한다.
***
***
***
#  2021.06.24
#  JavaScript Function
##  Function declaration
* `funtion name{param1, ...} {body... return; }`과 같이 정의한다.
* `object`가 아닌 `parameter`에 대해서 `call by value`로 전달되고 `object`만 `call by reference`로 전달된다.
* `default parameter`도 지원된다.
* 함수 정의에서 `parameter`를 `(...args)`의 형태로 정의하면 배열을 전달할 수 있다. 
* `funtion`은 `object`의 일종이다.
* `JavaScript`의 특성상 `declaration`의 위치에 관계 없이 컴파일 할 때 가장 위로 올리기 때문에 `hoisting` (선언되기 전에 사용할 수 있는)문제가 발생할 수 있다.
***
##  Function expression 
* `expression`은 `declaration`과 다르게 `hoisitng`문제가 발생하지 않는다.
* 변수를 정의하면서 동시에 함수를 정의하여 할당한다.
```
   const print = function() {console.log('print'); };
   //anonymous function
   print();
   //콘솔에 print를 출력하는 함수가 호출된다.
   const sumAgain = sum;
   //이미 정의된 함수도 할당할 수 있다.
   const print2 = function print()
   {console.log('print');
   print()};
   //named function
```
* `named function`은 `recursive`하게 동작하거나 `debugging`할 때 유용하게 사용된다.
***
##  Callback function
* 상황에 맞게 `parameter`로 전달된 함수를 호출한다.
```
   function Quiz(answer, printYes, printNo) {
     if (answer === 'OK'){
       printYes();
     } else{
       printNo();
     }
   }
```
***
##  Arrow function
* 함수 호출을 간단하게 도와준다.
```
  //non-Arrow
  const simplePrint = function() {
    console.log('simplePrint');
  };

  //Arrow
  const simplePrint = () => console.log('simplePrint');
  const add = (a, b) => a + b;
  //a+b를 리턴하는 함수이다.

  const add = (a, b) => {
    body...
    return a + b;
  };
  //block역시 사용할 수 있고 이 경우 return 키워드를 사용해야 한다.
```
***
##  IIFE: Immediately Invoked Function Expression
* 함수의 정의와 동시에 호출한다.
```
(function hello() {
  console.log('hello');
}) ();
```
***
***
***
#  2021.06.25
## JavaScript Class
##  Class 선언
```
   class Person{
     //생성자
     constructor(name, age){
       this.name = name;
       this.age = age;
     }

     //methods
     speak(){
       ...
     }
   }
```
***
##  Object 선언
* 생성자를 호출하면서 객체를 선언한다.
```
  const me = new Person('Jo', 21)
  console.log(me.name);
```
***
##  getter와 setter
* `getter`와 `setter`을 지원하고 있고 이를 통해 값을 읽고 쓸 때 `getter`, `setter` 함수를 자동으로 호출할 수 있다.
```
  class User{
    body...

    get age() {
      return this.age;
    }
     //아래의 setter함수는 잘못되었다. Class의 age에 값을 할당할 때 즉 this.age = value를 실행할 때 자동으로 setter함수를 호출하기에 무한 루프를 돌게된다.
    set age(value) {
      this.age = value;
    }
  }
```
***
##  public and private Fields
* 클래스에서 그냥 정의시 `public field`에 정의되어 클래스 밖에서도 접근할 수 있다.
* `#`을 붙여서 정의하면 `private field`에 정의되어 클래스 밖에서 접근이 불가능하다.
```
   calss Article{
     publicField = 2;
     #privateField = 0;
   }
```
***
##  Static properties
* `static` 을 붙여서 정의하면 `object` 에 속하는 것이 아닌 `class` 에 속하여 모든 `object` 가 공통으로 사용하는 `변수` 와 `메소드` 이다.
```
   calss Article{
     static publisher = 'CBNU';

     static printpublisher() {
       console.log(Article.publisher);
     }
   }

   const article1 = new Article();
   article1.printpublisher(); //Error
   Article.printpublisher; //OK
```
***
##  상속과 다형성
* Shape Class를 상속받은 Rectangle Class
```
   class Rectangle extends Shape{} 
```
***
##  instanceof operator
* `A instanceof B` 와 같이 사용하며 A가 B의 `class` 를 통해 만든 `object` 인지 아닌지 판단한다.
* `A` 가 `B` 를 상속받은 경우에도 `True` 이며 `A` 가 `object` 이고 `B` 가 `object` 여도 항상 `True` 이다.
***
***
***
# 2021.07.05
#  JavaScript Object
##  Literals and properties
* `object` 는 `key : value` 로 이루어져 있다.
* `object literal` 을 이용   
`const obj1 = {};`
* `object constructor` 을 이용   
`const obj2 = new Object();`
* `변수`가 `dynamic` 하기때문에 `object` 를 선언한 후 필요한 `property` 를 추가, 삭제 할 수 있다. 하지만 유지, 보수할 때 불리하다.
```
const me = {name: 'jojun', age: 21};
me.hasjob = flase; //hasjob이라는 property 추가
delete me.name; //name property 제거
```
****
## Computed properties
* `me['name']` 처럼 `string type` 으로 `object` 에 접근할 수 있다. `me.name` 과 결과는 같다.
* `.(dot)` 을 쓸 때는 코딩하는 그 순간 그 `key` 의 값을 받아오고 싶을 때 사용한다.
* `[]` 로 받아오는 `computed properties` 를 쓸 때는 정확하게 어떤 `key` 가 필요한지 모를 때 즉 `run time` 에서 결정될 때 사용한다.
```
  function printValue(obj, key){
    console.log(obj.key); 
    //obj라는 object에 key라는 property가 있는지 판단하므로 옳지 않다.
    console.log(obj[key]); 
    //run time에 obj에 key가 있는지 판단하므로 옳은 다. 
  }
```
***
## Property value shorthand
* 
```
  const person1 = { name: 'bob', age: 2};
  const person2 = {name: 'steve', age: 3};
  //person3, 4, ...들을 생성할 때 너무 번거로워서 함수화시키면
  const person3 = makePerson{'jo', 21};

  function makePerson(name, age){
    return {
      name: name,
      age : age,
    };
  }
  //위의 함수와 같이 object를 선언할 수 있다.
  
  //shorthand기능으로 key와 value값이 동일하다면 생략할 수 있다.
  function makePerson_short(name, age){
    return {
      name,
      age,
    };
  }
```
***
## Constructor function
*
```
  //위의 예시와 같이 object를 선언하는 함수는 template처럼 construcotr function으로 구현할 수 있다.
  //이 함수를 호출할 때도 new를 이용하여 호출한다.
  const person4 = new Person('jun', 21);

  function Person(name, age){
    // this = {}; 문장은 생략되어도 된다.
    this.name = name;
    this.age = age;
    // return this; 또한 생략되어도 된다.
  }
```
***
## In operator
* `'name' in me` 를 하게되면 `object`안에 `name`이라는 `key`가 있으면 `true`를 아니라면 `false`를 `return`한다.
***
## for..in, for..of
* `for in`
```
  //key가 me안의 key들을 차례로 저장하면서 for loop를 돈다.
  for (key in me){
    console.log(key);
  }
```
* `for of`
```
  const array = [1, 2, 3, 4];
  //array의 모든 원소들을 출력하려면
  for(let i = 0; i < array.length; i++){
    console.log(array[i]);
  }
  //이렇게 해야하는데 for..of를 쓰면 간단하다.
  for(value of array){
    console.log(value);
  } 
  //value에 array의 값들을 순차적으로 할당된다.
```
***
## Cloning
* 
```
  const user = { name: 'jo', age: '20' }; 
  const user2 = user;
  //이렇게 복제하게되면 call by reference로 복제된다. call by value로 복제만 하려면
  const user3 = {};
  for (key in user){
    user3[key] = user[key];
  }
  //이렇게 복제했어야 한다.
  //다른 방법으로 
  const user4 = {};
  Object.assign(user4, user);
  //혹은
  const user4 = Object.assign({}, user);
  ```
  * `Object.assign`은 뒤쪽의 `parameter`를 덮어씌우므로 여러 `parameter`중 중복된 `key`가 있다면 뒤쪽의 `parameter`의 `key`가 최종적으로 저장된다.
***
***
***
# 2021.07.06
# JavaScript Array
* `JavaScript`에서는 `type`과 관계 없이 모든 자료형을 한 `array`로 묶을 수 있다.
***
## Declaration
* `const arr1 = new Array();`   
`const arr2 = [1, 2];`    
와 같이 선언하다.
***
## Index position
* `arr1[arr1.length - 1]`와 같이 배열의 마지막 원소에 접근할 수 있다.
***
## Looping
* `for loop`로 배열의 원소 출력
```
  for(let i = 0; i < fruits.length; i++){
    console.log(arr1[i]);
  }
```
* `for of`로 배열의 원소 출력
```
  for(let element of arr1){
    console.log(element);
  }
```
* `forEach`로 배열의 원소 출력
```
  arr1.forEach(function(element, index){
    console.log(element, index); 
    //배열 arr1을 탐색하면서 element 변수에는 원소의 값들이, index 변수에는 index가 차례로 저장된다.
  });
```
* 위의 `forEach`를 `arrow`로 구현
```
  arr1.forEach((element, index) => console.log(element, index););
```
***
## Addtion, deletion, copy
* `push`, `pop` 으로 배열의 뒤에서부터 원소를 삽입, 삭제한다.
* `unshift`, `shift` 로 배열의 앞에서부터 원소를 삽입, 삭제한다.
* `push`, `pop` 연산은 배열의 가장 끝 공간만 조작하기에 속도가 빠르지만 `unshift`, `shift` 연산은 배열의 모든 원소를 조작하기에 훨씬 느리다.
***
## splice
* `splice(start, count)`를 이용해서 `start index`부터 `count`만큼 원소를 지운다. `count`를 지정하지 않으면 끝까지 모두 지운다.
* `splice(start, count, 'apple', 'melon')` 이렇게 하게되면 `start`부터 `count`만큼 원소를 지우고 `start`자리에 `'apple'`, `'melon'`을 삽입한다.
***
## Combine two arrays
* `arr2`를 선언하고 `newarr`에 `arr1`과 `arr2`를 결합한 배열을 저장한다.
```
  const arr2 = [1, 2, 3];
  const newarr = arr1.concat(arr2);
```
***
## Searching
* `indexOf`
```
  arr1.indexOf('apple');
  //해당 element가 나오는 가장 첫 index를 리턴한다.
```
* `includes`
```
  arr1.includes('melon');
  //해당 element가 원소에 있는지 True, False로 리턴한다.
```
* `lastIndexOf`
```
  arr1.lastIndexOf('apple');
  //해당 element가 나오는 가장 마지막 index를 리턴한다.
```
***
# JavaScript Array-api
## join
* array의 모든 원소들을 `seperator`을 이용하여 `string`으로 결합한다. `seperator`은 `default`로 `,`가 들어간다.
***
## split
* `string`을 `seperator`로 쪼개어서 배열로 만들 수 있다. `limit`로 배열의 크기를 제한할 수 있다.
***
## reverse
* `array`의 원소들의 순서를 거꾸로 만든 `array`를 리턴한다.
***
## slice
* `array`의 특정 부분을 리턴한다. `start`에서 `end`까지 리턴하며 `end`는 `sliced array`에 포함되지 않는다.
* `splice`로 배열을 자르게되면 원본 배열이 바뀐다.
***
## find
* `call-back`함수를 사용한다. `call-back`함수가 `true`를 리턴하면 `find`함수는 즉시 멈추고 그 `index`를 리턴한다.
* 
```
students.find((student) => student.score === 90);
```   
와 같이 사용하며 `student.score`가 90이면 `true`를 리턴하면서 `find`함수가 `call-back`함수의 `true`를 받게되면 그 `index`를 리턴하면서 함수가 종료된다.
***
## filter
* `call-back`함수를 사용하여 `call-back`함수가 `true`인 원소들만 모아서 새로운 `array`를 리턴한다.
* 
```
const result = students.filter((student) => student.enrolled);
```   
와 같이 사용하며 `student.enrolled`가 `true`인 원소들만 `filtering`하여 새로운 `array`를 리턴한다.
***
## map
* 배열안에 있는 원소들을 `call-back`함수를 이용하여 다른 값으로 `mapping`한다.
* 
```
const result = students.map((student) => student.score);
```   
와 같이 사용하며 `studnet` 배열을 전달받아서 `student.score`만 `call-back`에서 리턴하고 이를 `map`에서 배열로 리턴한다.
***
## some
* 배열의 요소 중 `call-back`함수가 `true`를 리턴하는 원소가 하나라도 있으면 `true`를 리턴한다.
* 
```
const result = students.some((student) => student.score < 50);
```   
와 같이 사용하며 `student.score`가 50보다 작은 원소가 있으면 `call-back`함수가 `true`를 리턴한다.
***
## every
* `some`과 사용하는 방법은 똑같고 배열의 모든 요소가 `call-back`함수에 대해 `true`를 리턴하면 `every`도 `true`를 리턴한다.
***
## reduce
* `call-back`함수와 `initial value`를 전달하여 배열의 원소들을 `initial value`를 시작으로 누적하여 더할 때 주로 사용한다. 
* `call-back`함수를 처음 실행하면 첫 `parameter`는 `initial value`를 가리키고 두 번째 `parameter`는 배열의 첫 번째 값을 가리키며 다음 실행에서 각 `parameter`들은 배열의 다음 원소를 가리킨다.
* 
```
  const result = students.reduce((prev, curr) => prev + curr.score, 0);
```
와 같이 사용하며 배열의 `students.reduce`를 모두 더한다.
***
## sort
* `call-back`함수로 정렬한다. `call-back` 함수에는 배열의 원소가 차례로 전달되고 `call-back`함수가 `-`를 리턴하면 앞의 `parameter` 가 두 번째 보다 작다고 간주되어서 정렬된다. 
* 
```
  const result = students
  .map((student) => student.score)
  .sort((a, b) => a-b)
```
와 같이 사용하면 오름차순으로 `b-a`로 사용하면 내림차순으로 정렬된다.
***
***
***
# 2021.07.09
# JavaScript JSON
## JSON파일의 특징
* `object`들을 `serialize` (`직렬화`)해서 `string`으로 변환할 것이 `JSON`파일이다.
* `key`와 `value`로 이루어져있는 파일 포맷이다.
* `프로그래밍 언어`와 `플랫폼`에 관계없이 `Jason`파일을 언어에 맞게 `object`로 변환하여 사용할 수 있다.
***
## Object to JSON
* `JSON`의 `api` 중 `stringify`의 사용법
* `배열`을 `JSON`으로 변환
```
  let json = JSON.stringify(['apple', 'banana']);
```
  `JSON`파일으로 변환하면 `"`로 묶여져서 `["apple", "banana"]`와 같이 출력된다.

* `object`를 `JSON`으로 변환
```
  const dog = {
    name : 'mongsil', 
    clolr : 'brown',
    size: null, 
    birthDate: new Date(),
    jump: () => {
      console.log(`&{name} can jump!`);
    },
  };
```
 `JSON`파일로 변환하면 `{"name":"mongsil", "color":"brown","size":null, "birthDate":"2020-05-29T13:20:22.670Z"}`와 같이 `Date Object`는 `String`으로 변환되고 `함수`나 `javascript`에만 존재하는 `symbol`등을 제외하여 변환된다.
* `replacer-array`   
 배열로 전달한 `property`만 `JSON`으로 변환한다.
 ```
  json = JOSN.stringify(dog, ['name', 'color']);
 ```
 `name`과 `color` `property`만 `JSON`으로 변환된다.
 * `replacer-callback-function`   
 `callback-function`의 `key`, `value`에는 `object`의 모든 `key`와 `value`가 차례로 저장된다.
 ```
  json = JSON.stringify(dog, (key, value) => {
    return key === 'name' ? 'Jun' : value;
  });
 ```
이런식으로 `retrun`값을 통해 세부적으로 조절할 수 있다. 위의 예시는 `name`이라는 `property`의 `value`만 `Jun`으로 바꾼다.
***
## JSON to Object
* `JSON`의 `api` 중 `parse`의 사용법
* `const obj = JSON.parse(json);`과 같이 `JSON`파일을 전달만 하면 끝이다.
* `object`를 `JSON`으로 바꾸고 다시 `object`로 바꾸면 `메소드`는 포함되지 않는다. 예를 들면 `dog object`의 `jump`같은 함수.
* `reviver-callback-function`   
`stringify`의 `replacer`와 같이 사용한다.
```
  const obj = JSON.parse(json, (keym value) => {
    return key === 'name' ? 'Jun' : value;
  });
```
`name`이라는 `property`의 `value`만 `Jun`으로 바꾼다.
***
* `JSON파일` 포맷 복구 사이트   [JSON Beautifier](https://jsonbeautifier.org/ 'JSON Beautifier')
* `JSON파일` `Object`로 변환해주는 사이트   [JSON Parser](http://json.parser.online.fr/ 'JSON Parser')
* `JSON파일`이 이상할 때 확인하는 사이트   [JSON Validater](https://tools.learningcontainer.com/json-validator/ 'JSON Validater')
***
***
***
# 2021.07.10
# JavaScript Async-Call-back
## 동기와 비동기
* `JavsScript` is `synchronous`. 즉 `hoisting`이 일어난 후 코드가 작성된 순서대로 동기적으로 작동한다. 
* `async`   
```
setTimeout(function () {
  console.log('2');
}, 1000);
```
 와 같이 순서대로 실행하는 것이 아닌 것들을 `비동기` 라고 한다.
* `Synchronous callback`   
```
  //print라는 콜백함수를 parameter로 받아서 바로 실행하는 함수 정의
  function printImmediately(print){
    print();
  }
  //printImmediately함수에서 parameter를 console.log('hello');만 수행하는 함수로 하여 호출한다.
  printImmediately(() => console.log('hello'));
```
* `Asynchronous callback`
```
  function pirntWithDelay(print, timeout){
    setTimeout(print, timeout);
  }
  printWithDelay(() => console.log('async callback'), 2000);
```
***
## Callback의 단점
* Callback Hell example
```
  calss UserStorage{
    loginUser(id, password, onSuccess, onError) {
      setTimeout(() => {
        if((id === 'jojun' && password === 'hwa')){
          onSuccess(id);
        } else{
          onError(new Error('not found'));
        }
      }, 2000);
    }

    getRoles(user, onSuccess, onError) {
      setTimeout(() => {
        if (user === 'jojun'){
          onSuccess({name: 'jojun', role: 'admin'});
        } else {
          onError(new Eoor('no access'));
        }
      }, 1000);
     }
  }
```
  위의 `class`가 정의된 경우에서 사용자에게 `id`, `password`를 입력받아서 로그인하고 역할을 요청받아서 사용자의 `object`를 출력해보자.
  ```
  const userStorage = new UserStorage();
  const id = prompt('enter your id');
  const password = prompt('enter your password');
  userStorage.loginUser(id, password,
  user => {
    userStorage.getRoles(user,
    userWithRole => {
      alert(`Hello &{userWithRole.name}, you have a ${userWithRole.role} role`);
    },
    error => {
      console.log(error);
    }
    );
  },
  error => {
    console.log(error)
    }
  );
  ``` 
* `콜벡체인`은 `유지`, `보수`, `가독성`등의 면에서 모두 최악의 성능을 보여준다.
***
# JavaScript Async-Promise
* 파일을 받아오는 등 오래걸리는 작업을 비동기적으로 처리하여 효율을 높이고 이를 `Promise`를 사용하여 주로 구현한다.
* `callback`대신 `asynchronous`를 위해 사용되는 `JasvaScript`의 `object`이다.
* `promise`의 `state`는 `pending` -> `fulfilled` or `rejected` 로 변환된다.
***
## Promise-Producer
```
  const promise = new Promise((resolve, reject) => {
    console.log('doing something...');
    setTimeout(() => {
      resolve('jojun');
    }, 2000);
  });
```
`promise`를 만드는 순간 `executor`를 바로 실행한다. 
***
## Promise-Consumers
 `Promise`를 이용하는 `Consumers` : `then`, `catch`, `finally`   
`then`의 `value`는 `promise`의 `resolve`로 전달한 값이 전달된다. 
```
  promise
  .then((value) => {
    console.log(value);
  })
  ```
  `resolve`가 전달되지않고 무언가 실패해서 `reject`가 전달되면 `catch`로 받을 수 있다.
  ```
  .catch(error => {
    console.log(error);
  });
  ```
  `finally`는 성공 실패에 관계 없이 마지막에 무조건 수행된다.
  ```
  .finally(() => {
    console.log('finally');
  });
```
* 위의 예시처럼 `api`들을 `.`으로 묶어서 호출할 수 있었던 이유는 `then`의 `return` 값이 같은 `promise`이므로 거기에 대해서 `catch`를 호출할 수 있었던 것이다.
***
## Promise chaining
* `then`에서는 값을 바로 전달하거나 또 다른 비동기 `promise`를 전달해도 된다.
```
const fetchNumber = new Promise((resolve, reject) => {
  setTimeout(() => resolve(1), 1000)
});

fetchNumber
.then(num => num*2)
.then(num => num*3)
.then(num => {
  return new Promise((resolve, reject) => {
    setTimeout(() => resolve(num -1), 1000);
  });
})
``` 
***
## Error Handling
```
  const getHen = () =>
    new Promise((resolve, reject) => {
      setTimeout(() => resolve('chicken'), 1000);
    });
  const getEgg = hen =>
    new Promise((resolve, reject) => {
      setTimeout(() => reject(new Error(`error! &{hen} => egg`)), 1000);
    });
  const cook = egg =>
    new Promise((resolve, reject) => {
      setTimeout(() => resolve(`${egg} => fried egg`), 1000);
    });
```
```
  getHen()
  .then(hen => getEgg(hen))
``` 
  받아오는 `value`를 다른 함수로 바로 전달하는 경우    
  `.then(getEgg)`와 같이 사용할 수 있다.
  ```
  .then(cook)
  .then(console.log)
  ```
  이렇게만하면 오류처리를 하지 않았다.
  ```
  .catch(console.log); 
  ```
  이런식으로 오류처리를 꼭 해줘야한다. 그럼 `then`에서 오류가 발생했지만 바로 `catch`에서 받아줘서 정상적으로 에러 메세지를 출력하였다.
***
## Callback hell => Promise
* 위의 `callback hell` example을 `promise chain`으로 바꿔보자.
```
  calss UserStorage{
    loginUser(id, password) {
      return new Promise((resolve, reject) => {
         setTimeout(() => {
        if((id === 'jojun' && password === 'hwa')){
          resolve(id);
        } else{
          reject(new Error('not found'));
        }
       }, 2000);
      });
    }

    getRoles(user) {
      return new Promise((resolve, reject) => {
        setTimeout(() => {
        if (user === 'jojun'){
          resolve({name: 'jojun', role: 'admin'});
        } else {
          reject (new Eoor('no access'));
        }
      }, 1000);
      })
      
     }
  }
```
```
  const userStorage = new UserStorage();
  const id = prompt('enter your id');
  const password = prompt('enter your password');
  userStorage.loginUser(id, password)
  .then (uesr => userStorage.getRoles(user))
  .then(user => alert(`Hello &{userWithRole.name}, you have a ${userWithRole.role} role`))
  .catch(console.log);
```
***
***
***
# 2021.07.11
# JavaScript Async-Await
## Async & await
* `async & await`은 `promise`위에 좀 더 편한 `api`를 제공하는 것으로 이를 `syntactic sugar`라고 한다.
***
## Async
* 사용 방법
```
  async function fetchUser(){
    return 'jojun';
  }
```
와 같이 사용하며 자동으로 `function fetchUser`를 `Promise`로 만들어준다.
* `error`는 `throw 'error'`과 같이 사용할 수 있다.
***
## Await
* `async`함수 안에서 사용할 수 있으며 `await`이 붙은 문장을 실행하는 동안 기다린다.
```
  async function getApple(){
    return delay(3000)
    .then(()=>'apple');
  }
```
위와 같은 문장을 `await`을 이용하면 `promise chaining` 하지 않고도
```
  async function getApple(){
    await delay(3000);
    return 'apple';
  }
```
위와 같은 방식으로 동기적으로 작동하는 것처럼 사용할 수 있다.
***
## Async & await의 활용
* `promise-chaining`을 너무 중첩해서 사용하면 `callback hell`처럼 보이므로 `async & await`를 사용하는 것은 중요하다.   
* `promise-chaining`을 중첩 사용한 예시를 보자면
```
  async function getApple(){
    await delay(3000);
    return 'appple'
  }

  async function getBanana(){
    await delay(3000);
    return 'banana'
  }
```
```
  function pickFruits(){
    return getApple().then(apple => {
      return getBanana().then(banana => `${apple} + ${banana}`);
    });
  }

  pickFruits().then(console.log);
```
이를 `async & await`로 구현하면
```
  async function pickFruits(){
   const apple = await getApple();
   const banana = await getBanana();
   return `${apple} + ${banana}`;
 }
```
위와 같이 `동기적`으로 코딩하듯이 작성할 수 있다. `error`처리를 해야하는 경우에는
```
 async function pickFruits(){
   try {
    const apple = await getApple();
    const banana = await getBanana();
    return `${apple} + ${banana}`;
   } catch(){
     ...
   }
 }
```
위와 같이 일반적으로 사용하여 `error`처리 또한 해줄 수 있다. 그런데 위의 예시를 보면 `apple promise`에서 1초를 기다리고 `bananna promise`에서도 1초를 기다려서 비효율적이라는 점을 알 수 있다. 따라서 병렬적으로 구현해보면
```
  async function pickFruits(){
   const applePromise = getApple();
   const bananaPromise = getBanana();
   const apple = await applePromise;
   const banana = await bananaPromise;
   return `${apple} + ${banana}`;
 }
```
위와 같이 사용하면 `applePromise`를 선언하자마자 `executor`를 수행하고 `bananPromise`를 선언하자마자 `executor`를 수행한다. 따라서 병렬적으로 두 독립적인 `promise`를 생성하고 `await`에서 기다리므로 총 3초만 기다리면 된다.
***
## Useful Promise APIS
* 위의 예시처럼 병렬적으로 구현해야 하는 경우 `all`을 사용할 수 있다. `all`에 `promise`를 배열형식으로 전달하면 배열의 모든 `promise`를 병렬적으로 모아주고 다시 배열로 전달해준다.
```
  function pickAllFruits(){
    return Promise.all([getApple(), getBanana()])
    .then(fruits => fruits.join(' + '));
  }
```
위의 예시처럼 사용하면 배열로 `promise`들을 동시에 생성하여 `join`을 이용하여 다시 `string`으로 변환한다.
* `race` `api`를 사용하면 위와 같이 `배열`로 전달된 `promise`들 중 가장 먼저 값을 `리턴`하는 `promise`만 전달해준다.
```
  function pickOnlyOne(){
    return Promise.race([getApple(), getBanana()]);
  }
```
***
스터디에서 나온 과제 `array [20, 10, 30]`을 비동기적으로 `call-back`, `promise`, `async & await`를 이용하여 `10, 20, 30` , `20, 10, 30`으로 출력. task_print.js파일 참고
***
# Nodejs module& npm 
## Nodejs에서의 version
* (`major version`, `minor version`, `patch version`) 으로 이루어져 있다.   
`patch version`은 간단한 기능들이 수정되어 업데이트 된 것이고   
`minor version`은 새로운 기능들이 추가되었지만 하위호환을 지원하는 경우 즉 이전 `version`에서 기능을 그대로 지원하는 업데이트이며   
`major version`은 기존에 있던 기능을 제거하여 하위호환이 되지 않는 업데이트를 말한다.   
즉 `1.1.1 version`에서 작성된 프로그램은 `2.1.1 version`에서 작동하지 않을 수 있다.
***
## 모듈의 사용
* `const 변수 = require('모듈');`과 같이 사용한다.
* 지원하는 `표준 모듈`들은 [Nodejs](https://nodejs.org/dist/latest-v14.x/docs/api/ 'Nodejs')에서 확인할 수 있다.
* `const{ readFileSync } = require('fs');`와 같이 사용하여 `fs 모듈` 중 `readFileSync`만 떼와서 사용할 수 있다. 이 문법은 
```
let obj = {a: 1, b: 2, c: {name: '홍길동', age: 90}};
const{c} = obj;
```
와 같은 뜻이며 `변수` `c` `obj`의 `key`가 `c`인 `value`를 저장한다는 뜻이다.
***
## 모듈의 생성
* `JavaScript`의 `모듈`은 `파일`단위로 생성할 수 있고 꼭 `export`를 해야지 사용할 수 있다. 따라서 정보의 `은닉`이 가능하다.
```
  const a = 10;
  const b = {name: '홍길동', age: 90};

  export.a = a;
  export.human = b;
```
외부에서 `a`는 `a`로 `b`는 `human`으로 접근이 가능하다.   
혹은
```
  const a = 10;
  const b = {name: '홍길동', age: 90};

  module.exports = {
    a: a,
    human: b
  };
```
위의 방법으로 한 번에 추출할 수 있다.
* 직접 생성한 `모듈`은 `절대경로` 혹은 `상대경로`를 이용하여 `require`해야한다.
* `const {a, human} = require('./module');`와 같이 `module`전체 중에 `a`와 `human`만 `import`할 수 있다.
***
## npm
* `npm` => `node package manager` 즉 `node`에서 쓸 수 있는 여러 `모듈`들을 관리해주는 도구이다.
* `package.json` 파일을 이용하여 `package`들을 관리할 수 있다.
* 터미널에서 `npm init`을 입력하여 `package.json` 파일을 초기화할 수 있다. 이 때 `entry point`는 `C`의 `main function`처럼 어떤 파일이 가장 먼저 실행되어야하는 `진입점` 파일을 말한다. `-y` 옵션을 주게되면 모든 질문에대해 yes로 대답하여 생성한다.
* `npm install 패키지명`을 통해 패키지를 설치할 수 있고 `pacakage.json`파일에서 패키지에 대한 의존성을 기록할 수 있다. 
***
## nodemon
* 서버는 항상 켜져있기때문에 소스코드의 변동사항이 있으면 수동적으로 껐다켜야한다. `nodemon`은 소스코드에 변동사항이 생기면 자동으로 껐다켜주는 편리한 도구이다.
* 프로그램의 구동에는 관계 없이 개발에 편리성을 더해주는 객체이므로 `npm i -D nodemon`을 통해 `-D`옵션을 줘서 `개발자 Dependency`에 넣자. 
* 설치가 끝난 뒤에는 `package.json`파일의 `scripts` 밑에 `"dev" : "nodemon index.js",`라는 문장을 추가해서 `npm run dev`를 통해 `nodemon`으로 실행할 수 있게끔 한다.
***
***
***
# 2021.07.12
# WebServer 기초
## 작동 방식
* `Web Client`가 `DNS`에 `URL`(`http://www.google.com` 같은)을 요청하면 `IP주소`를 응답한다. 그 주소를 `Web Server`에 요청하면 `Web Websever`는 `DB`에 자료를 요청하고 응답을 받아서 `html`을 `Web Client`에게 응답해주는 방식으로 작동한다.
***
## Port
* `port`는 서버를 생성할 때 임의로 지정할 수 있고 그 서버에 접속하거나 지정할 때 사용한다.
***
## NODE_ENV
* 프로그램을 개발용, 배포용으로 구분하기 위해서 `.env`파일에 `NODE_ENV`라는 환경변수를 추가하여 `development`를 할당하여 사용할 수 있다.
* 아래의 환경변수 생성에 있는 예시처럼 `IS_DEV` 변수를 만들어서 `if(IS_DEV){ }`를 통해 개발용일때만 `if`문을 수행하게끔 사용한다.
***
## 환경변수 생성   
* `process.env`라는 객체가 시스템의 환경변수를 가져오는 역할을 하는데, 이 환경변수들을 `dotenv` 라는 패키지를 통해서 `.env`파일에 환경변수를 생성할 수 있다.
* `.env`파일에 환경변수를 기록한 후 `dotenv.config()`함수를 통해 환경변수를 생성할 수 있고 `process.env`파일에서 확인할 수 있다.
* 환경변수를 사용할 모든 파일에 `require('dotenv).config();` 와 같이 해줘야한다.
* 다른 방식으로는 환경변수도 모듈처럼 사용할 수 있다. 그 방법은 `env` 디렉터리 밑에 `index.js`파일을 만든 후 그 파일에  
```
  require('dotenv').config();

  const env = {
    IS_DEV: process.env.NODE_ENV === 'development',
    ...process.env,
  };

  module.exports = env;
```
와 같이 작성하고   
 `const { PORT, IS_DEV } = require('./env/index');` 를 통해 필요한 환경변수를 사용할 수 있다.
***
## .gitignore 파일
* `git`에 `add`를 할 때 제외할 파일들을 `.gitignore`이라는 파일에 기술하면 제외된다.
* 중요한 설정값들을 올리지 않으려면 `.env`파일, `*.pem`파일들을 `.gitignore`파일에 포함시키면 된다.
* [gitignore.io](https://www.toptal.com/developers/gitignore 'gitignore') 에서 자신의 개발환경, OS에 맞는 `.gitignore`파일을 만들어주므로 꼭 활용하자. `node modules`까지도 포함된다.
***
***
***
# 2021.07.13
## Morgan
* `log`를 찍어주는 패키지
* 옵션을 `dev`로 주면 간단하게, `combined`로 주면 복잡하게 찍어준다. 주로 개발할 때는 `dev`로 배포할 때는 `combined`로 사용한다.
* `미들웨어`를 리턴해주는 `클로저`같은 역할을 해주는 `class`이다.
* 사용 예시
```
  app.use(morgan(IS_DEV ? 'dev' : 'combined'));
```
# Express 
참고 문서   [Express](https://expressjs.com/ 'express') 
***
## 기초 메소드
* 간단한 서버 만드는 예제
```
  const express = require('express');
  const app = express();
  const { PORT } = require('./env);
```
```
  app.get('/', (req, res) => {
    res.send('<h1>Hello World! ~ <\h1>');
  });

  app.listen(PORT, () => console.log(`server running on ${PORT}`));
```
`host`주소로 접속했을 때 `PORT`번호로 `listening`하고 있다가 루트경로로 `Hello World!`라는 `html`을 응답해주는 예제이다.
 ***
 ***
 ***
 # 2021.07.14
 ## app관련 설정 및 미들웨어
 * `요청`은 `METHOD`, `URL`로 이루어져있다. `METHOD`는 `GET`, `POST`, `PUT`, `PATCH`, `DELETE`, `OPTION`, `HEAD`로 이루어져 있고 `USE`는 모든 요청을 말한다. `URL`은 `http://domain/path~~`의 형태로 이루어져 있다.
 * `URL http://localhost:9000/path` 에서 `http://localhost:9000`까지 부분 즉 도메인까지를 `호스트`라고 부른다. 호스트까지를 `/`(`루트경로`)라고 하며 이 호스트는 서버가 실행되고있는 하드웨어의 주소와 `mapping`이 된다.
 * `app.use((req, res, next) => {})`
 와 같은 형태의 `콜백함수`를 `미들웨어`라고한다.
* `미들웨어`에서 `콜백함수`앞에 경로명을 써줄 수 있는데, 이는 이 경로로 오는 요청만 받아들여서 `미들웨어`를 실행하겠다는 의미이다. 경로를 쓰지 않으면 모든 경로에 대해서 요청을 받아들이겠다는 의미이다.
* 사용 예시
```
  app.use('/hello', (req, res, next) => {
    console.log("hello");
  });
  app.use(morgan('dev'));
```

위의 문장의 뜻은 `hello` 경로로 들어온 모든 요청에 대해 콜백함수를 수행하겠다는 의미이다.
* `method`와 `url`에 의해 실행할 `미들웨어`가 정해지고 `응답`을 할 때까지 `미들웨어`들을 실행시킨다.
* 위의 사용 예시를 보면 `미들웨어`를 실행하고 다음 `미들웨어`인 `morgan`은 실행하지 않는다. 이 때 처음 `미들웨어`안에 `next();`를 넣어주면 바로 다음 `미들웨어`를 실행해준다.
* 그런데 위의 사용 예시에서 `next();`를 추가하여도 결국 응답을 하지 않았기에 `NOT FOUND ERROR`가 발생한다. 따라서 응답을 꼭 추가해줘야한다.
***
## Router
* 라우터는 앞 예시의 `app`과 비슷한 역할을 하지만 디렉터리를 편리하게 접근할 수 있게 해주는 역할을 한다.
* 예시로 살펴보자.   
`main` 디렉터리 아래에 `routs`디렉터리 아래에 `v1`디렉터리 아래에 user이라는 디렉터리에 `index.js`파일이 존재한다. 또 그 파일에는 라우터의 정의가 담겨있다.    
`/main/routes/v1/user/index.js`
```
  const { Router } = require('express');

  const router = Router();

  router.get('/', (req, res) => {
    res.json(['user1', 'user2', 'user3']);
  });

  router.get('/hello', (req, res) => {
    res.send('hello');
  });

  module.exports = routers;
```
`/main/routes/v1/index.js` 파일에는 아래의 내용이 담겨있다.
```
  const { Router } = require('express');

  const userRouter = require('./user');

  const router = Router();

  router.use('/user', userRouter);

  module.exports = routers;
```
`v1`의 `index.js`부터 살펴보자.    
`const userRouter = require('./user');` 은    
`userRouter`가 `user`디렉터리 안의 `index.js`파일에서 `export`하는 `routers`를 저장한다는 뜻이다.   
`router.use('/user', userRouter);` 는   
모든 메소드와 `/user`경로로 들어오는 요청은 `userRouter`로 처리한다는 뜻이다.   
`userRouter`가 실제로 존재하는 `/user`디렉터리 안의 `index.js`파일을 살펴보면   
```
  router.get('/', (req, res) => {
    res.json(['user1', 'user2', 'user3']);
  });

  router.get('/hello', (req, res) => {
    res.send('hello');
  });
```
이 존재한다. 여기서 `router`에게 `루트`는 `/user`이고 `/hello`는 `/user/hello`이다.
* 위의 예시처럼 `router`를 연결해서 만들게 되면 새로운 `api`를 만드는 상황에 훨씬 편리하게 사용이 가능하다. 예를 들어 기존의 `v1` 디렉터리 아래에 `post`라는 디렉터리를 추가해야하는 상황이 생겼다. 그러면 `post/index.js`에는 똑같이 `router`를 이용하여 정의를 한다.   
그리고 `v1/index.js`에 `const postRouter = require('./post');`를 추가하고 이 `post`에 접근이 필요할 때는 `router.use('/post', postRouter);`과 같이 쉽고 깔끔하게 새로운 `api`를 생성하고 관리할 수 있다.
***
***
***
# 2021.07.15
## Router 쉽게 사용하기 - fs이용
* 위의 방식대로 `router`을 사용하면 새로운 `api`를 추가할때마다 `index.js`파일을 수정해야하는 불편함이 있다. `fs`를 사용하면 쉽게 `router`를 생성하고 관리할 수 있다.
* `v1` 디렉터리의 `index.js`를 다음과 같이 수정할 수 있다.
```
  const { Router } = require('express');
  const { readdirSync, statSync } = require('fs');
  const { join } = require('path');
  const router = Router();

  readdirSync(__dirname)
      .filter(dir => {
          const st = statSync(join(_dirname, dir))
          return st.isDirectory();
      }).forEach(dir => {
          router.use(`/${dir}`, require(`./${dir}`));
      });

  module.exports = router;
```
* `_dirname`는 현재 디렉터리의 경로를 나타낸다.
* `readdirSync`는 디렉터리 경로를 파라메터로 사용하여 그 경로에 대해 모든 파일, 디렉터리의 목록을 배열로 가져오는 역할을 한다.
* `readdirSync`를 이용하여 생성한 배열에서 `라우팅`을 하려면 디렉터리만 필요하기때문에 `filter`을 이용해서 걸러낸다. 조건은 `join`으로 디렉터리의 정보를 가져와서 그 중 디렉터리인가 판단하는 문장이 참이면 통과시킨다.
* 배열의 각 원소에대해 `router.use`를 통해 `라우팅`한다. 이 때 경로는 `dir`변수 자체가 된다. 이 떄 `router`은 현재 디렉터리 아래의 디렉터리들의 `index.js`파일의 `router`를 사용한다.
* 이런식으로 사용하면 `api`를 `v1`디렉터리에 새로 추가하면 자동으로 `v1`의 `index.js`파일에 적용된다.
***
# Get방식 
## Query String
* `string`으로 값을 받아오는 형식으로 `/users?id=123`과 같은 형식을 사용한다.
* `const {id} = req.query;`와 같이 사용하며 `id`를 받아올 수 있다.
* 특정 `resource`를 필터링하고 싶은 경우 사용한다.
***
## Path value
* 경로로써 데이터를 받아오는 방식으로 `/users/123`과 같은 형식을 사용한다.
* `const {id} = req.params;`와 같이 사용한다.
* 특정 `resource`를 식별하고 싶은 경우 사용한다.
***
***
***
***
# 2021.07.17
## HTTP
참고 문서   
[HTPP 트랜잭션 해부](https://nodejs.org/ko/docs/guides/anatomy-of-an-http-transaction/ 'nodejs')   
 [HTTP APIS](https://nodejs.org/api/http.html#http_server_listen 'nodejs') 
 ***
* 사용 예시
```
  const app = require('./app');
  const http = require('http');
  const { PORT } = require('./env');
  
  const server = http.createServer(app);

  server.listen(PORT);

  server.on('error', console.error);
  server.on('listening', () => {
    const addr = server.address();
    console.log(`Server running on ${addr.address}:${addr.port}`);
  });
```
와 같이 사용한다. 
***
***
***
# 2021.07.20
# mongoose
* `MongoDB ODM`중 가장 유명한 라이브러리이다. 
* `ODM`은 객체와 문서를 1대 1로 매핑해준다. 즉 `MongoDB`에 있는 데이터를 `NodeJS`에서 `JavaScript` 객체로 사용할 수 있도록 해준다.
* `MongoDB`는 `nosql`이며 배열에 객체를 저장하고 각 객체를 `sql`의 레코드처럼 관리한다. 배열은 모델, 객체는 문서로 생각하면 된다.
***
## mongoose 연결하기
* 
```
  const mongoose = require("mongoose");

  mongoose
    .connect("mongodb://localhost/task-manager", {
      useNewUrlParser: true,
      useCreateIndex: true,
    })
    .then(() => {
      console.log("Connected to MongoDB");
    })
    .catch((err) => {
      console.log(err);
    });
```
와 같이 연결한다. `task-manager`라는 `DB`와 연결해주며 없으면 자동으로 생성한다.
* `.env`디렉터리에 `MONGO_TRI = https://localhost/test`와 같은 방식으로 주로 저장한다.
***
## 스키마 생성
```
  const UserSchema = new mongoose.Schema({
    name: String,
    age: Number,
    saveDate: {
      type: Date,
      default: Date.now,
    },
  });
```
와 같이 생성한다. `MongoDB`에는 스키마가 없지만 `Mongoose`에서는 생성해줄 수 있다. 컬렉션에 들어가는 내부의 필드를 정의한다.   
* `const User = mongoose.model("User", UserSchema);`   
와 같이 모델을 생성한다. 이 모델을 이용하여    
`const me = new User({
  name: "Mike",
  age: 27,
});`   
를 통해 객체를 생성할 수 있다.
* 
```
  me.save()
    .then(() => {
      console.log(me);
    })
    .catch((err) => {
      console.log("Error : " + err);
    });
```
위의 방식으로 `DB`에 저장한다.
***
## 스키마 검증
* `required`   
```
  const UserSchema = new mongoose.Schema({
    name: {
      type: String,
      required: true,
    },
```
처럼 `required`를 `true`로 설정해주면 나중에 `name`이란 필드의 값이 없으면 에러를 발생시킨다.
* `trim`   
`trim`을 `true`로 설정하면 `   abc   `라는 입력을 공백을 잘라내고 `abc`로 저장한다.
* `index`   
`index`를 `true`로 설정하면 `index`를 설정하여 검색을 할 때 빠르게 검색하게 도와준다.
* `validate`   
```
  const UserSchema = new mongoose.Schema({
    (...생략...)
    age: {
      type: Number,
      validate(value) {
        if (value < 0) {
          throw new Error("Age must be a postive number");
        }
      },
    },
```
처럼 `validate` 함수를 설정하여 값의 조건을 설정할 수 있다. 
* `validator 패키지`   
`validator`패키지를 설치하여 여러 기능들을 사용할 수 있다.   
[Validator](https://www.npmjs.com/package/validator#validators 'validator') 에서 기능들을 확인할 수 있다.
***
## 스키마 수정
* `update`   
```
  db.collection.update(
     <query>,
     <update>,
     {
       upsert: <boolean>,
       multi: <boolean>,
       writeConcern: <document>
     }
  )
```
와 같은 구조를 가지며 `Collection`안의 `document`를 수정한다. 
***
***
***
# 2021.07.22
## Virtuals
* `Getter & Setter`  

Define a schema
```
  const personSchema = new Schema({
    name: {
      first: String,
      last: String
    }
  });
```
Compile our model
```
  const Person = mongoose.model('Person', personSchema);
```
Create a document
```
  const axl = new Person({
    name: { first: 'Axl', last: 'Rose' }
  });
```
이 때 `first name`과 `last name`을 합친 `full name`을 정의해보자.
```
  personSchema.virtual('fullName').get(() => `${this.name.first} ${this.name.last}`);
```
와 같이 `virtual get`을 정의하면 `fullName`을 획득하려고 할 때 자동으로 `getter`이 실행돼서 `fullName`에 접근할 수 있다.
```
personSchema.virtual('fullName').
  get(function() {
    return this.name.first + ' ' + this.name.last;
    }).
  set(function(v) {
    this.name.first = v.substr(0, v.indexOf(' '));
    this.name.last = v.substr(v.indexOf(' ') + 1);
  });
```
와 같이 `set`도 정의할 수 있고 `axl.name.fullName = 'Jo JunHwa`를 하면 `set`이 실행되어 `firstname`, `lastname`이 자동으로 저장된다.
***
## Pre & post
* `모델.pre, post`와 같이 사용하며 특정 동작 이전, 이후에 어떤 행동을 취할지 정의할 수 있다. 
```
userSchema.pre('save', function(next) {
  if (!this.email) { 
    // email 필드가 없으면 에러 표시 후 저장 취소
    throw '이메일이 없습니다';
  }
  if (!this.createdAt) { // createdAt 필드가 없으면 추가
    this.createdAt = new Date();
  }
  next();
});
userSchema.post('find', function(result) {
  console.log('저장 완료', result);
});
```
와 같이 사용한다. `save`전에 `pre`를 실행하며 `next`함수를 실행하지 않으면 다음 `document`로 넘어가지 않는다. 즉 `save`를 실행하지 않는다.    
`find` 후에 `post`를 실행한다. `find`의 리턴값이 `result`로 전달되고 콜백함수를 실행한다.
***
## Plugins
* 스키마에서 logic을 재사용하기위해 사용할 수 있다.   
`loadedAt.js` 파일
```
module.exports = function loadedAtPlugin(schema, options) {
  schema.virtual('loadedAt').
    get(function() { return this._loadedAt; }).
    set(function(v) { this._loadedAt = v; });

  schema.post(['find', 'findOne'], function(docs) {
    if (!Array.isArray(docs)) {
      docs = [docs];
    }
    const now = new Date();
    for (const doc of docs) {
      doc.loadedAt = now;
    }
  });
};
```
`find`나 `findOne`을 실행한 후 그 결과를 `docs`로 받아서 배열이 아니라면 배열로 만들고 `loadedAt`을 현재 시간으로 바꾸는 작업을 한다.   
`game-schema.js` 파일
```
const loadedAtPlugin = require('./loadedAt');
const gameSchema = new Schema({ ... });
gameSchema.plugin(loadedAtPlugin);
```
`player-schema.js` 파일
```
const loadedAtPlugin = require('./loadedAt');
const playerSchema = new Schema({ ... });
playerSchema.plugin(loadedAtPlugin);
```
과 같이 사용하여 여러 스키마에 대해 공통된 작업을 수행할 수 있다.
>>>>>>> 7077096a2e3a01f7b728c9e50687517f987afa01
