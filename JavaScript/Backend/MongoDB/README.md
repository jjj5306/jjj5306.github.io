# MongoDB
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
***