# Back-End
# 목차
* [Node Js](./NODEJs/README.md)
* [MongoDB](./MongoDB/README.md)
* [웹사이트의 구동 방식](#웹사이트의-구동-방식)
* [WebServer 기초](#WebServer-기초)
***
# 웹사이트의 구동 방식
* `HTML`을 한줄 한줄씩 차례로 `parsing`하다가  
 `<script src="main.js"></script>`
 를 만나게 되면 parsing을 멈춘 상태에서 `js파일`을 서버에서 받아서 `실행`한 다음 다시 parsing 하게 된다.   

=> script 안에 js파일을 포함하게 되면 속도가 많이 느려진다.
***
* `<body>` 의 제일 마지막부분에 `js`를 포함하게 되면 `parsing HTML`이 모두 끝나고 페이지가 준비되면 스크립트를 `fetching`하고 `executing`한다.    

=> 사용자가 웹사이트의 스크립트를 제외한 기본 정보를 빨리 볼 수 있지만 웹사이트가 스크립트에 많이 의존하는 상황에서는 사용자가 정상적인 페이지를 보기 전까지 기다려야한다.
***
* `async`옵션을 사용하게 되면 `<script asyn src="main.js"></script>` `parsing`과 `fetching js`를 병렬적으로 진행하고 fetching이 끝나면 parsing을 정지시키고 `executing`하는 방식으로 진행한다. 여러 스크립트들을 다운하는 경우 다운로드 속도에 따라 실행되는 순서가 정해진다.   

=> 빠르긴 하지만 fetching중인 스크립트를 조작하려는 경우 위험할 수 있고 HTML을 parsing하는 도중에 언제든지 block이 걸릴 수 있기에 사용자가 더 불편할 수 있다.
***
   
* defer옵션을 사용하게 되면 `<script defer src="main.js"></script>` `parsing`하면서 `fetching`을 다 해놓고 가장 마지막에 `executing`한다. 여러 스크립트를 다운하여도 정의된 순서대로 `excuting`한다.
***
# WebServer 기초
## 작동 방식
* `Web Client`가 `DNS`에 `URL`(`http://www.google.com` 같은)을 요청하면 `IP주소`를 응답한다. 그 주소를 `Web Server`에 요청하면 `Web Websever`는 `DB`에 자료를 요청하고 응답을 받아서 `html`을 `Web Client`에게 응답해주는 방식으로 작동한다.
***
## Port
* `port`는 서버를 생성할 때 임의로 지정할 수 있고 그 서버에 접속하거나 지정할 때 사용한다.
***
