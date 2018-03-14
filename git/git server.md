## git server

사실상 ssh로 접속만 할 수 있으면 별게 없다.

### server
- server에 `--bare` 옵션을 붙인 저장소를 생성한다.
```bash
$ git init --bare [저장소이름]
$ pwd
/git/저장소이름
```

### client
- ssh로 remote를 등록해준다.
- 중요한 것은 `/git/저장소이름/`과 같이 뒤에 `/`를 붙인다.
```bash
$ git remote ssh://git@12.123.31.12/git/저장소이름/
```
