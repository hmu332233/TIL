## express

### 설치
 - [설치](http://expressjs.com/ko/starter/installing.html)

```bash
$ npm init

$ npm install express --save
```

### basic sample

```js
const express = require('express');
const app = express();

// '/'로 접속하면 function이 실행됨
// res => request가 담아서 옴
// res => 사용자에게 보여줄 내용을 담음
app.get('/', function(req, res){
  res.send('hello world');
});

// (port,callback)
// callback은 listen에 성공했을때 호출됨
app.listen(3000,function(){
    console.log('Connected 3000 port!');
});
```

### 정적파일 서비스하는 법
public 폴더에 존재하는 파일들을 사용할 수 있게 해준다
```js
app.use(express.static('public'));
```
아래와 같이 접근이 가능해진다
```
http://localhost:3000/images/kitten.jpg
http://localhost:3000/css/style.css
http://localhost:3000/js/app.js
http://localhost:3000/images/bg.png
http://localhost:3000/hello.html
```
### sample

```js
const express = require('express');
const app = express();

//public 폴더의 정적 파일들을 접근할 수 있게 해준다.
app.use(express.static('public'));

// '/'로 접속하면 function이 실행됨
// res => request가 담아서 옴
// res => 사용자에게 보여줄 내용을 담음
app.get('/', function(req, res){
  res.send('hello world');
});

// (port,callback)
// callback은 listen에 성공했을때 호출됨
app.listen(3000,function(){
    console.log('Connected 3000 port!');
});
```

### 템플릿 엔진 사용하기
- **jade**
```bash
$ npm install jade --save
```
다음과 같이 view engine으로 jade를 쓰겠다고 선언한다    
(서버가 HTML 렌더링을 할때 jade 엔진을 사용하도록 설정)
```js
//템플릿이 있는 디렉토리 설정
//html을 렌더링시 jade 엔진을 사용하도록 설정
app.set('views', './views')
app.set('view engine','jade');
```
- **ejs**
```bash
$ npm install ejs --save
```

### sample
```js
const express = require('express');
const app = express();

//템플릿이 있는 디렉토리 설정
//html을 렌더링시 jade 엔진을 사용하도록 설정
app.set('views', './views')
app.set('view engine','jade');

app.get('/', function(req, res){
  res.render('index');
});


app.listen( process.env.PORT ,function(){
    console.log('Connected 3000 port!');
});
```

### 쿼리 스트링
url의 뒷부분에 `?val1=1&val2=2` 와 같이 되어있는 부분을 쿼리 스트링이라고 하며  
그 값을 받아오는 방법은 다음과 같다
```js
app.get('/',function(req,res){
   var val1 = req.query.val1
   res.send(val1);
});
```
req.query는 json의 형태를 띄고 있다.
```
{
  "val1": "1",
  "val2": "2"
  "__proto__": {}
}
```

### responce body의 정보를 가져오는 법

`req.body`를 사용하면 body의 정보를 가져와서 쓸 수 있다(post로 데이터를 전송했을 경우 등)  
json의 형태로 제공되는데 기본적으로는 정의되어있지 않고  
미들웨어인 `body-parser`와 `multer`를 이용해야만 정보를 가져올 수 있다

```js
var app = require('express')();
var bodyParser = require('body-parser');
var multer = require('multer'); // v1.0.5
var upload = multer(); // for parsing multipart/form-data

app.use(bodyParser.json()); // for parsing application/json
app.use(bodyParser.urlencoded({ extended: true })); // for parsing application/x-www-form-urlencoded

app.post('/profile', upload.array(), function (req, res, next) {
  console.log(req.body);
  res.json(req.body);
});
```

**참고**
[http 프로토콜](http://exoluse.egloos.com/v/4572381)

### put, delete method 사용하기
express 최신버전은 미들웨어가 따로 npm으로 분리가 되었다  
[참고](https://github.com/senchalabs/connect#middleware)
js
```js
var methodOverride = require('method-override')

app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: true }))
app.use(methodOverride('_method'))

app.put('/users/:id',function(req,res){
  //do something
});

```
form
```html
<form method="POST" action="/users/:id?_method=PUT">
  <!-- input -->
</form>
```
다른 framework에서 사용하는 방식으로 하려면 이렇게 하면 된다
```js
var methodOverride = require('method-override')

app.use(methodOverride(function (req, res) {
  if (req.body && typeof req.body === 'object' && '_method' in req.body) {
    // look in urlencoded POST bodies and delete it
    var method = req.body._method
    delete req.body._method
    return method
  }
}))
```
form
```html
<form method="POST">
  <input type="hidden" name="_method" value="put">
</form>
```

### cookie 사용하기

```js
var cookieParser = require('cookie-parser');
app.use(cookieParser());

//count 라는 쿠키에 1을 저장
res.cookie('count', 1);

//쿠기 불러오기
var count = req.cookies.count
```
보안을 위해 쿠키를 암호화하는 것이 좋다.
```js
//두번째 인자는 암호화 key
var cookieParser = require('cookie-parser');
app.use(cookieParser('1112345')); //파라미터는 암호화 key

//count 라는 쿠키에 1을 저장, 암호화해서
res.cookie('count', 1,{signed:true});

//쿠기 복호화 후 불러오기
var count = req.signedCookies.count
```
### sample
```js
var express = require("express");
var app = express();
//쿠기를 사용하기 위한 라이브러리
var cookieParser = require('cookie-parser');
app.use(cookieParser('123456'));

app.get('/count',function(req,res){

    if(req.signedcookies.count)
      var count = parseInt(req.signedcookies.count);
    else
      var count = 0;


    res.cookie('count', count+1,{signed:true});

    res.send('count :' + count );
});


app.listen(process.env.PORT,function(){
   console.log('Connected!');
});
```

### session
값을 클라이언트에 직접 저장하는  cookie와 달리  
클라이언트를 식별하는 id만을 저장하고  
이 id를 통해 서버에서 해당 값을 가져와 처리한다.

```bash
$ npm install express-session --save
```
다음과 같이 `req.session`으로 간단하게 사용이 가능하다
```js
var session = require('express-session')

app.use(session({
  secret: '123456', // 암호화 key값, 원하는걸로 아무거나 넣으면됨
  resave: false,
  saveUninitialized: true
}))

//session에 count 1을 넣는다
req.session.count = 1
```
기본적으로 `express-session`은 메모리를 이용한다.  
session정보를 file로 저장하고 싶으면 다음과 같이 한다
```js
var session = require('express-session')
var FileStore = require('session-file-store')(session);

app.use(session({
  store: new FileStore(),
  secret: '123456', // 암호화 key값
  resave: false,
  saveUninitialized: true
}))
```

session정보를 mysql에 저장하고 싶을 땐 다음과 같이 한다
```js
var session = require('express-session')
var MySQLStore = require('express-mysql-session')(session);

var options = {
    host: 'localhost',
    port: 3306,
    user: 'root',
    password: 'root',
    database: 'o2'
};

app.use(session({
  store: new MySQLStore(options),
  secret: '123456', // 암호화 key값
  resave: false,
  saveUninitialized: true
}))

```
다음과 같은 table이 자동으로 추가되는걸을 확인 할 수 있다
```
mysql> desc sessions;
+------------+------------------+------+-----+---------+-------+
| Field      | Type             | Null | Key | Default | Extra |
+------------+------------------+------+-----+---------+-------+
| session_id | varchar(128)     | NO   | PRI | NULL    |       |
| expires    | int(11) unsigned | NO   |     | NULL    |       |
| data       | text             | YES  |     | NULL    |       |
+------------+------------------+------+-----+---------+-------+
3 rows in set (0.00 sec)
```
