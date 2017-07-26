## [ubuntu] mysql 설치 및 실행

### 설치
```bash
$ sudo apt-get install mysql-server mysql-client
```

### 실행 및 기타
```bash
실행
$ service mysql start
정지
$ service mysql stop
재시작
$ service mysql restart
상태확인
$ service mysql status
```
`service mysql` 대신 `/etc/init.d/mysql`를 써도 됨  
`mysql` 위치를 못 찾겠다면 `whereis mysql`로 찾아보자

### 접속
아래와 같이 입력하고 비밀번호를 입력한다
```bash
$ mysql -u root - p
```

### 에러
권한이 없는 경우로 `sudo`를 붙여 실행하면 정상적으로 작동한다
```bash
df: '/var/lib/mysql/.': Permission denied
 * /etc/init.d/mysql: ERROR: The partition with /var/lib/mysql is too full!
```
