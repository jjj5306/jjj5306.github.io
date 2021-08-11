#  2021.06.20 
# 마크다운 파일 작성법
## [참고](https://gist.github.com/ihoneymon/652be052a0727ad59601, "refernece")
***
## 글머리 기호 : `*`,` +`, `-` 
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
## 다른 md파일로 이동
* `상대경로`를 통하여 디렉터리를 지정하여 이동할 수 있다.
  - `/` : 루트   
  - `./` : 작업 디렉터리
  - `../` : 상위 디렉터리    
* `Link`거는 것과 같은 방식으로 상대경로를 이용하여 다른 md파일로 이동할 수 있다. 
  - `[타이틀](이동할 파일의 상대경로)`와 같이 사용한다.
  ***
## 같은 md파일 안에서 이동
* md파일의 내용이 목차와 헤딩 태그로 분리되어 있는 경우 목차에서 원하는 영역으로 바로 이동할 수 있다.
***
## 목차 작성법
* `[타이틀](#이동할 헤더명)`과 같이 이동한다.
* 목차 작성시 주의사항
  - 공백은 하이픈(`-`)으로 바꿔야한다.
  - 마침표나 콤마 등의 기호, 이모지는 생략해야한다.    
* `[타이틀 입니다👍](#타이틀-입니다)` 과 같이 작성하면 된다.
***
## 수식
* 일반 텍스트와 붙여서 작성하는 경우 `$`로 묶어서 사용한다.
* `$$`로 묶어서 사용하는 경우 따로 들여쓰기가 적용된다.
* $\geq$ : `$\geq$`   
 $\leq$ : `$\leq$`   
 $\alpha$ : `$\alpha$`   
 $\times$ : `$\times$`   
 $\div$ : `$\div$`   
 $\pm$ : `$\pm$`   
 $\sqrt a$ : `$\sqrt a$`   
 $\frac a b$ : `$\frac a b$`   
 $a^b$ : `$a^b$`   
 $a^{p-2}$ : `a^{p-2}$`   
 $\therefore$ : `$\therefore$`   
 $\cdot$ : `$\cdot$`   
 공백 한 칸 : `$\,$`   
 공백 두 칸 : `$\;$`   


