## Jekyll로 github에 블로그 만들기


### 설치
```bash
$ sudo apt-get install ruby-full
$ sudo gem install jekyll bundler
```

### site 생성
```bash
$ jekyll new [blog-name]
```

### 개발 중 site 확인하기
- 아래 명령어를 실행하면 http://localhost:4000 으로 실행할 수 있다.
```bash
$ jekyll serve --watch
```
`_config.yml` 파일에서 아래와 같이 추가하면 host와 port를 바꿀 수 있다
```
# deployment
host: 0.0.0.0
port: 3000
```

### 포스팅하기
`_post` 폴더 안에  
` YYYY-MM-DD-[글 제목].md`라는 파일을 만들면 화면에서 볼 수 있다.
