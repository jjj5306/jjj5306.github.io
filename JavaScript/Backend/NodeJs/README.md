# NodeJs
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