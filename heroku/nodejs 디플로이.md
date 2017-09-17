## nodejs 디플로이

heroku에 nodejs 프로젝트를 디플로이하고 mongodb를 연결하는 법을 정리한다.

#### Heroku 설치
```bash
$ apt-get install heroku
```

#### 로그인 및 app 만들기
```bash
$ heroku login
$ heroku create [app_name]
```
이 때 나오는 url로 접근이 가능하다.  
또는 heroku app 페이지에서 확인이 가능하다.

#### Heroku 디플로이
```bash
$ git push heroku master
```

#### heroku mongodb 추가
```bash
$ heroku addons:create mongolab
```
`process.env.MONGODB_URL`로 접근이 가능하다.  
또는 heroku app 페이지에서 확인이 가능하다.

#### 기타
- **로그 확인**
```bash
$ heroku logs --tail
```
- **스크립트 실행**
```bash
$ heroku run [명령어]
ex)
$ heroku run run-script seed
```

#### 에러 모음
- **heroku[router]: at=error code=H10 desc="App crashed"...**
  - 해결
  process.env.PORT를 추가한다
   - [참고 사이트](https://stackoverflow.com/questions/14322989/first-heroku-deploy-failed-error-code-h10)
```js
app.listen(process.env.PORT || 3000, function(){
  console.log("Express server listening on port %d in %s mode", this.address().port, app.settings.env);
});
```

- **not authorized to execute command**
  - 허용된 유저로 로그인을 하지 않아서 생김
  - heroku mlab에 들어가 유저를 만들고 그것으로 로그인한다
```js
mongoose.connect('mongodb://<user>:<password>@<db url>/<database name>', { useMongoClient: true });
```

- **DeprecationWarning: `open()` is deprecated in mongoose >= 4.11.0, use `openUri()` instead, or set the `useMongoClient` option if using `connect()` or `createConnection()`.**
  - `{ useMongoClient: true }`를 추가한다.
```js
mongoose.connect('<mongodb url>', { useMongoClient: true });
```
