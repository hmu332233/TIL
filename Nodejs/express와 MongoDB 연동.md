## express와 MongoDB 연동하기

### 연결하기
- `mongoose`라는 모듈이 필요하다.

```bash
$ npm install --save mongoose
```

- `app.js`에 아래와 같이 써서 mongodb에 접속한다 ( `mongodb` 서버가 켜져있다는 하에 )
```js
// app.js
const mongoose   = require("mongoose");

var db = mongoose.connection;
db.on('error', console.error);
db.once('open', function(){
  console.log("Connected to mongod server");
});
mongoose.connect('mongodb://localhost:27017/study');
```

### Schema & Model
- MongoDB는 기본적으로 Schema가 존재하지 않으나 편의를 위해  
  mongoose는 제공을 해주고 있다.

```js
// models/user.js
var mongoose = require('mongoose'),
  Schema = mongoose.Schema;

var userSchema = new Schema({
  user_id: {type: String, unique: true},
  user_pw: String,
  user_name: {type: String, unique: true},
  email: String
});

module.exports = mongoose.model('User', UserSchema);
```

- 다음과 같은 데이터 타입을 지원한다.

| Data Type  | Description  |
|---|---|
|  String | 문자열 type  |
|  Number | 숫자 type  |
|  Boolean |  불리언 type |
|  Buffer |  Node.js의 binary type(이미지, PDF, 아카이브 등) |
|  Date | ISODate format data type(2016-08-08T12:52:30:009Z)  |
|  Array |  표준 자바스크립트와 Node.js의 배열 type |
| Schema.types.ObjectId  | 12byte binary 숫자에 대한 MongoDB 24자리 hex 문자열(501d86090d371bab2c0341c5)  |
|  Schema.types.Mixed | 모든 유형의 데이터 |

#### Model
- model() 메소드에 문자열과 schema를 전달하여 model을 생성한다. model은 보통 대문자로 시작한다.
- 보통 위와 같이 스키마를 정의한 후 model을 `export`하는 식으로 사용한다.
```js
var User = mongoose.model("User", userSchema);
```
