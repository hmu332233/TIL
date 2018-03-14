## git server
- 내 server를 원격저장소로 사용하는 방법
- 사실상 ssh로 접속만 할 수 있으면 별게 없다
### ssh

- client
```bash
# ssh key 생성
$ ssh-keygen
# ssh public key를 git server의 authorized_keys 파일에 추가
$ ssh-copy-id root@12.123.31.12
# ssh 접속 확인
$ ssh root@12.123.31.12
```
- server
```bash
# authorized_keys 파일 확인
$ cat ~/cat/.ssh/authorized_keys
```

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
$ git remote ssh://root@12.123.31.12/git/저장소이름/
```
