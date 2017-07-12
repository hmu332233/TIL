## express

### 설치
 - [설치](http://expressjs.com/ko/starter/installing.html)

```bash
$ npm init

$ npm install express --save
```

### sample

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
