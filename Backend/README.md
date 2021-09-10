# Back-End
# 목차
 [웹사이트의 구동 방식](#웹사이트의-구동-방식)    
 [WebServer 기초](#WebServer-기초)    
 [NodeJs](#NodeJs)    
 [Express](#Express)    
 [Get방식](#Get방식)    
 [HTTP](#HTTP)    
 [MongoDB](#MongoDB)    


# 웹사이트의 구동 방식
* HTML을 한줄 한줄씩 차례로 parsing하다가  
 `<script src="main.js"></script>`    
 를 만나게 되면 parsing을 멈춘 상태에서 js파일을 서버에서 받아서 실행한 다음 다시 parsing 하게 된다.   
  => script 안에 js파일을 포함하게 되면 속도가 많이 느려진다.

* `<body>` 의 제일 마지막부분에 `js`를 포함하게 되면 parsing HTML이 모두 끝나고 페이지가 준비되면 스크립트를 fetching하고 executing한다.    
  => 사용자가 웹사이트의 스크립트를 제외한 기본 정보를 빨리 볼 수 있지만 웹사이트가 스크립트에 많이 의존하는 상황에서는 사용자가 정상적인 페이지를 보기 전까지 기다려야한다.

* `async`옵션을 사용하게 되면 `<script asyn src="main.js"></script>`     
parsing과 fetching js를 병렬적으로 진행하고 fetching이 끝나면 parsing을 정지시키고 executing하는 방식으로 진행한다.    
 여러 스크립트들을 다운하는 경우 다운로드 속도에 따라 실행되는 순서가 정해진다.   
  => 빠르긴 하지만 fetching중인 스크립트를 조작하려는 경우 위험할 수 있고 HTML을 parsing하는 도중에 언제든지 block이 걸릴 수 있기에 사용자가 더 불편할 수 있다.
   
* defer옵션을 사용하게 되면 `<script defer src="main.js"></script>`    
 parsing하면서 fetching을 다 해놓고 가장 마지막에 executing한다. 여러 스크립트를 다운하여도 정의된 순서대로 excuting한다.
***

# WebServer 기초
## 작동 방식
* Web Client가 DNS에 URL(`http://www.google.com` 같은)을 요청하면 IP주소를 응답한다. 그 주소를 `Web Server`에 요청하면 Web Websever는 DB에 자료를 요청하고 응답을 받아서 html을 Web Client에게 응답해주는 방식으로 작동한다.

## Port
* port는 서버를 생성할 때 임의로 지정할 수 있고 그 서버에 접속하거나 지정할 때 사용한다.
***

# Nodejs
## Nodejs에서의 version
* (`major version`, `minor version`, `patch version`) 으로 이루어져 있다.   
  * `patch version`은 간단한 기능들이 수정되어 업데이트 된 것이다.   

  * `minor version`은 새로운 기능들이 추가되었지만 하위호환을 지원하는 경우 즉 이전 `version`에서 기능을 그대로 지원하는 업데이트이다.   

  * `major version`은 기존에 있던 기능을 제거하여 하위호환이 되지 않는 업데이트를 말한다.   

  * 즉 `1.1.1 version`에서 작성된 프로그램은 `2.1.1 version`에서 작동하지 않을 수 있다.

## 모듈의 사용
* `const 변수 = require('모듈');`과 같이 사용한다.

* 지원하는 표준 모듈들은 [Nodejs](https://nodejs.org/dist/latest-v14.x/docs/api/ 'Nodejs')에서 확인할 수 있다.

* `const{ readFileSync } = require('fs');`    
와 같이 사용하여 fs모듈 중 `readFileSync`만 떼와서 사용할 수 있다. 이는 아래의 코드와 같은 뜻이다.
  ```
  let obj = {a: 1, b: 2, c: {name: '홍길동', age: 90}};
  const{c} = obj;
  ```
  변수 `c`가 `obj`의 `key`가 `c`인 `value`를 저장한다는 뜻이다.

## 모듈의 생성
* JavaScript의 모듈은 파일 단위로 생성할 수 있고 꼭 `export`를 해야지 사용할 수 있다. 따라서 정보의 은닉이 가능하다.
  ```const a = 10;
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

* 직접 생성한 모듈은 절대경로 혹은 상대경로를 이용하여 require해야한다.

* `const {a, human} = require('./module');`    
와 같이 module 전체 중에 `a`와 `human`만 `import`할 수 있다.

## npm
* npm이란 node package manager 즉 node에서 쓸 수 있는 여러 모듈들을 관리해주는 도구이다.

* `package.json` 파일을 이용하여 package들을 관리할 수 있다.

* 터미널에서 `npm init`을 입력하여 `package.json` 파일을 초기화할 수 있다. 이 때 `entry point`는 C언어의 `main function`처럼 어떤 파일이 가장 먼저 실행되어야하는 진입점 파일을 말한다. `-y` 옵션을 주게되면 모든 질문에대해 yes로 대답하여 생성한다.

* `npm install 패키지명`을 통해 패키지를 설치할 수 있고 `pacakage.json`파일에서 패키지에 대한 의존성을 기록할 수 있다. 

## nodemon
* 서버는 항상 켜져있기때문에 소스코드의 변동사항이 있으면 수동적으로 껐다켜야한다. `nodemon`은 소스코드에 변동사항이 생기면 자동으로 껐다켜주는 편리한 도구이다.

* 프로그램의 구동에는 관계 없이 개발에 편리성을 더해주는 객체이므로 `npm i -D nodemon`을 통해 `-D`옵션을 줘서 `개발자 Dependency`에 넣자. 

* 설치가 끝난 뒤에는 `package.json`파일의 `scripts` 밑에 `"dev" : "nodemon index.js",`라는 문장을 추가해서 `npm run dev`를 통해 `nodemon`으로 실행할 수 있게끔 한다.

## NODE_ENV
* 프로그램을 개발용, 배포용으로 구분하기 위해서 `.env`파일에 `NODE_ENV`라는 환경변수를 추가하여 `development`를 할당하여 사용할 수 있다.

* 아래의 환경변수 생성에 있는 예시처럼 `IS_DEV` 변수를 만들어서 `if(IS_DEV){ }`를 통해 개발용일때만 `if`문을 수행하게끔 사용한다.

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
  와 같이 작성하고 `const { PORT, IS_DEV } = require('./env/index');` 를 통해 필요한 환경변수를 사용할 수 있다.

## .gitignore 파일
* `git`에 `add`를 할 때 제외할 파일들을 `.gitignore`이라는 파일에 기술하면 제외된다.

* 중요한 설정값들을 올리지 않으려면 `.env`파일, `*.pem`파일들을 `.gitignore`파일에 포함시키면 된다.

* [gitignore.io](https://www.toptal.com/developers/gitignore 'gitignore') 에서 자신의 개발환경, OS에 맞는 `.gitignore`파일을 만들어주므로 꼭 활용하자. `node modules`까지도 포함된다.


## Morgan
* 로그를 찍어주는 패키지

* 옵션을 `dev`로 주면 간단하게, `combined`로 주면 복잡하게 찍어준다. 주로 개발할 때는 `dev`로 배포할 때는 `combined`로 사용한다.

* 미들웨어를 리턴해주는 클로저같은 역할을 해주는 class이다.

* 사용 예시
  ```
  app.use(morgan(IS_DEV ? 'dev' : 'combined'));
  ```
***

# Express 
참고 문서   [Express](https://expressjs.com/ 'express') 

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
host주소로 접속했을 때 `PORT`번호로 listening하고 있다가 루트경로로 `Hello World!`라는 `html`을 응답해주는 예제이다.
 
 ## app관련 설정 및 미들웨어
 * 요청은 METHOD, URL로 이루어져있다. 
   * METHOD는 `GET`, `POST`, `PUT`, `PATCH`, `DELETE`, `OPTION`, `HEAD`로 이루어져 있고 `USE`는 모든 요청을 말한다. 
   
   * URL은 `http://domain/path~~`의 형태로 이루어져 있다.

 * `URL http://localhost:9000/path` 에서 `http://localhost:9000`까지 부분 즉 도메인까지를 호스트라고 부른다. 호스트까지를 `/`(`루트경로`)라고 하며 이 호스트는 서버가 실행되고있는 하드웨어의 주소와 mapping된다.

* `app.use((req, res, next) => {})`와 같은 형태의 콜백함수를 미들웨어라고한다.
  * 미들웨어에서 콜백함수앞에 경로명을 써줄 수 있는데, 이는 이 경로로 오는 요청만 받아들여서 미들웨어를 실행하겠다는 의미이다. 경로를 쓰지 않으면 모든 경로에 대해서 요청을 받아들이겠다는 의미이다.

  * 사용 예시
    ```
    app.use('/hello', (req, res, next) => {
      console.log("hello");
    });
    app.use(morgan('dev'));
    ```
    위의 문장의 뜻은 `hello` 경로로 들어온 모든 요청에 대해 콜백함수를 수행하겠다는 의미이다.

  * `method`와 `url`에 의해 실행할 미들웨어가 정해지고 응답을 할 때까지 미들웨어들을 실행시킨다.

  * 위의 사용 예시를 보면 미들웨어를 실행하고 다음 미들웨어인 `morgan`은 실행하지 않는다. 이 때 처음 미들웨어안에 `next();`를 넣어주면 바로 다음 미들웨어를 실행해준다.

  * 그런데 위의 사용 예시에서 `next();`를 추가하여도 결국 응답을 하지 않았기에 `NOT FOUND ERROR`가 발생한다. 따라서 응답을 꼭 추가해줘야한다.

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
`userRouter`가 `user`디렉터리 안의 `index.js`파일에서 export하는 routers를 저장한다는 뜻이다.   
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
이 존재한다. 여기서 router에게 루트는 `/user`이고 `/hello`는 `/user/hello`이다.

  * 위의 예시처럼 router를 연결해서 만들게 되면 새로운 api를 만드는 상황에 훨씬 편리하게 사용이 가능하다. 
  
  * 예를 들어 기존의 `v1` 디렉터리 아래에 `post`라는 디렉터리를 추가해야하는 상황이 생겼다. 그러면 `post/index.js`에는 똑같이 `router`를 이용하여 정의를 한다.

  * 그리고 `v1/index.js`에 `const postRouter = require('./post');`를 추가하고 이 post에 접근이 필요할 때는 `router.use('/post', postRouter);`과 같이 쉽고 깔끔하게 새로운 api를 생성하고 관리할 수 있다.

## Router 쉽게 사용하기 - fs이용
* 위의 방식대로 router을 사용하면 새로운 api를 추가할때마다 `index.js`파일을 수정해야하는 불편함이 있다. fs를 사용하면 쉽게 router를 생성하고 관리할 수 있다.

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

* `readdirSync`를 이용하여 생성한 배열에서 라우팅을 하려면 디렉터리만 필요하기때문에 `filter`을 이용해서 걸러낸다. 조건은 `join`으로 디렉터리의 정보를 가져와서 그 중 디렉터리인가 판단하는 문장이 참이면 통과시킨다.

* 배열의 각 원소에대해 `router.use`를 통해 라우팅한다. 이 때 경로는 `dir`변수 자체가 된다. 이 떄 router는 현재 디렉터리 아래의 디렉터리들의 `index.js`파일의 router를 사용한다.

* 이런식으로 사용하면 api를 `v1`디렉터리에 새로 추가하면 자동으로 `v1`의 `index.js`파일에 적용된다.
***

# Get방식 
## Query String
* `string`으로 값을 받아오는 형식으로 `/users?id=123`과 같은 형식을 사용한다.

* `const {id} = req.query;`와 같이 사용하며 `id`를 받아올 수 있다.

* 특정 resource를 필터링하고 싶은 경우 사용한다.

## Path value
* 경로로써 데이터를 받아오는 방식으로 `/users/123`과 같은 형식을 사용한다.
* `const {id} = req.params;`와 같이 사용한다.
* 특정 resource를 식별하고 싶은 경우 사용한다.
***

# HTTP
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

# MongoDB
## mongoose
* MongoDB ODM중 가장 유명한 라이브러리이다.

* ODM은 객체와 문서를 1대 1로 매핑해준다. 즉 MongoDB에 있는 데이터를 NodeJS에서 JavaScript 객체로 사용할 수 있도록 해준다.

* MongoDB는 nosql이며 배열에 객체를 저장하고 각 객체를 sql의 레코드처럼 관리한다. 배열은 모델, 객체는 문서로 생각하면 된다.

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
  와 같이 연결한다. `task-manager`라는 DB와 연결해주며 없으면 자동으로 생성한다.

* `.env`디렉터리에 `MONGO_TRI = https://localhost/test`와 같은 방식으로 주로 저장한다.

## 스키마 생성
* 
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
  와 같이 생성한다. MongoDB에는 스키마가 없지만 Mongoose에서는 생성해줄 수 있다. 컬렉션에 들어가는 내부의 필드를 정의한다.   

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
  위의 방식으로 DB에 저장한다.
***
## 스키마 검증
* required   
  ```
  const UserSchema = new mongoose.Schema({
    name: {
      type: String,
      required: true,
    },
  ```
  처럼 `required`를 `true`로 설정해주면 나중에 `name`이란 필드의 값이 없으면 에러를 발생시킨다.

* trim    
`trim`을 `true`로 설정하면 `   abc   `라는 입력을 공백을 잘라내고 `abc`로 저장한다.

* index   
`index`를 `true`로 설정하면 `index`를 설정하여 검색을 할 때 빠르게 검색하게 도와준다.

* validate   
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

* validator 패키지   
`validator`패키지를 설치하여 여러 기능들을 사용할 수 있다.   
[Validator](https://www.npmjs.com/package/validator#validators 'validator') 에서 기능들을 확인할 수 있다.

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
  와 같은 구조를 가지며 Collection안의 document를 수정한다. 

## Virtuals
* `Getter & Setter`  

  * Define a schema
    ```
    const personSchema = new Schema({
      name: {
        first: String,
        last: String
      }
    });
    ```

  * Compile our model
    ```
    const Person = mongoose.model('Person', personSchema);
    ```

  * Create a document
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
  와 같이 사용한다. save전에 `pre`를 실행하며 `next`함수를 실행하지 않으면 다음 document로 넘어가지 않는다. 즉 `save`를 실행하지 않는다.    
`find` 후에 `post`를 실행한다. `find`의 리턴값이 `result`로 전달되고 콜백함수를 실행한다.

## Plugins
* 스키마에서 logic을 재사용하기위해 사용할 수 있다.   
  * `loadedAt.js` 파일
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

  * `game-schema.js` 파일
    ```
    const loadedAtPlugin = require('./loadedAt');
    const gameSchema = new Schema({ ... });
    gameSchema.plugin(loadedAtPlugin);
    ```

  * `player-schema.js` 파일
    ```
    const loadedAtPlugin = require('./loadedAt');
    const playerSchema = new Schema({ ... });
    playerSchema.plugin(loadedAtPlugin);
    ```
    과 같이 사용하여 여러 스키마에 대해 공통된 작업을 수행할 수 있다.
***
