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
