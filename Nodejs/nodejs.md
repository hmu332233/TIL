### node 콘솔
- `node`만 치면 콘솔모드로 전환된다.
```bash
$ node
> 입력가능!
```

### NPM

- Node Package Manager
- 타인의 모듈을 가져다 쓰는 방법
- https://www.npmjs.com/

- #### NPM 독립적인 앱 설치(글로벌)
  - npm을 프로젝트에 상관없이 독립적인 앱으로 사용하고 싶을 때에는 다음과 같이 한다.
  - 시스템 디렉토리에 설치하는 것을 의미
```bash
$ npm install [packagename] -g
```

- #### NPM 모듈 설치
  - npm을 프로젝트에서 모듈로서 사용하기 위해서는 다음과 같이 한다.
```
$ npm init
name : 프로젝트이름
version : 버전..
description : 프로젝트의 설명
entry point : 어떠한 .js가 프로젝트를 구동하는 js파일인가
test command : 어떤 명령을 입력하면 테스트를 실행시킬 것인가
git repository : 깃 저장소 주소
... 생략(package.json에서 추후에 변경 가능)

$ npm install [packagename]
```
  - 다음과 같이 하면 dependencies가 동시에 수정된다
  - 일단은 `--save`를 붙여서 하는걸 추천한다
```
$ npm install [packagename] --save
```
  - 이후 다음과 같이 사용한다
test.js
```js
const name = require('name')
```

- #### 모듈 제거
```bash
$ npm uninstall [packagename]
```

- #### 모듈 업데이트
```bash
$ npm update [packagename]
```

### Nodejs sample

```js
const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;
/*
* 사용자에게 어떤 server의 내용을 보여줄 것인가
* req => request 내용을 담고 있음
* res => 사용자에게 보여줄 내용을 담음
*/
const server = http.createServer(function(req,res){
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello World\n');
});

//서버가 특정 ip, 특정 port를 바라보고 있게한다 (listen)
server.listen( port , hostname, function(){
  var addr = server.address();
  console.log("Chat server listening at", addr.address + ":" + addr.port);
});
```

### 파일의 디렉토리 경로 가져오기
  - **현재 파일 기준**
    - 현재 파일의 디렉토리는 `__dirname`에 저장되어있다.
    - 아래와 같이하면 찾고자 하는 파일의 절대 경로를 가져올 수 있다.
```js
var path = require('path');
path.join( __dirname, filename );
```
  - **노드가 실행되고 있는 디렉토리 기준**
    - 노드가 실행되고 있는 디렉토리 정보는 ` process.cwd();`로 가져올 수 있다.

### 파일 업로드
  - `multer`라는 라이브러리를 이용한다.

```js
var multer = require('multer'); //파일 업로드를 위한 것
var upload = multer({ dest: 'uploads/' });  //사용자가 업로드한 파일을 uploads/에 저장되는 미들웨어를 리턴


//첫번째 인자의 url로 들어오면 두번째 인자인 미들웨어를 통과한뒤 마지막 callback이 호출된다
//'/upload'로 접근했을때 파일이 포함되어 있다면 가공해서 req.file을 추가하도록 하는 미들웨어
// upload.single( 파라미터 이름)
app.post('/upload', upload.single('userfile'), function(req, res) {
  console.log(req.file);
});
```
  - 다음과 같은 값을 가지고 있다.
```
{ fieldname: 'userfile',
  originalname: '레일즈설치법.png',
  encoding: '7bit',
  mimetype: 'image/png',
  destination: 'uploads/',
  filename: '30ffc616f718430ad2302cf22b361c4b',
  path: 'uploads/30ffc616f718430ad2302cf22b361c4b',
  size: 1133090 }
```
  - 파일이 저장되는 이름과 위치를 커스텀하고 싶으면 다음과 같이 한다
```js
var _storage = multer.diskStorage({
  //어느 디렉토리에 저장할 것인가
  destination: function (req, file, cb) {
    cb(null, 'uploads/');
    /* 아래와 같이 자유롭게 가능

    if(파일의 형식이 이미지면)
      cb(null, 'uploads/img/');
    else if(파일의 형식이 텍스트면)
      cb(null, 'uploads/text/');
    */
  },
  //파일 이름은 어떻게 할 것인가
  filename: function (req, file, cb) {
    cb(null, file.originalname);
  }
});

var upload = multer({ storage: _storage })
```
