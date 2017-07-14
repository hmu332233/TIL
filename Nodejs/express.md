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
