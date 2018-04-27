## docker
[참고](https://subicura.com/2017/01/19/docker-guide-for-beginners-2.html)
### 용어정리
- 도커
  - 컨테이너 기반의 오픈소스 가상화 플랫폼
- 컨테이너
  - 격리된 공간에서 프로세스가 동작하는 기술
- 이미지
  - 컨테이너 실행에 필요한 파일과 설정값등을 포함하고 있는 것
  - 컨테이너는 이미지를 실행한 상태라고 볼 수 있음
  - 이미지는 레이어(layer)라는 개념을 이용


### 설치
- linux
```bash
$ curl -fsSL https://get.docker.com/ | sudo sh
```

### 컨테이너 관련 명령어
#### 실행
```bash
$ docker run [OPTIONS] IMAGE[:TAG|@DIGEST] [COMMAND] [ARG...]
````
| 옵션 | 설명 |
|---|---|
|-d|	detached mode 흔히 말하는 백그라운드 모드|
|-p|	호스트와 컨테이너의 포트를 연결 (포워딩)|
|-v|	호스트와 컨테이너의 디렉토리를 연결 (마운트)|
|-e|	컨테이너 내에서 사용할 환경변수 설정|
|–name|	컨테이너 이름 설정|
|–rm|	프로세스 종료시 컨테이너 자동 제거|
|-it|-i와 -t를 동시에 사용한 것으로 터미널 입력을 위한 옵션|
|–link|	컨테이너 연결 [컨테이너명:별칭]|
- 모든 순서는 host:container 이다.
#### 목록
- 컨테이너 목록 확인
```bash
$ docker ps [OPTION]
```
#### 중지
```bash
$ docker stop [OPTIONS] CONTAINER [CONTAINER...]
```
- `CONTAINER`에는 컨테이너의 아이디 값을 넣으면 된다.
- 컨테이너가 중지되어도 삭제되지 않고 남아있다.

#### 삭제
```bash
$ docker rm [OPTIONS] CONTAINER [CONTAINER...]
```

#### 로그 보기
```bash
$ docker logs [OPTIONS] CONTAINER
```
- `--tail 10` 10줄만 출력
- `-f` 실시간 확인

#### 컨테이너에 명령어 실행하기
```bash
$ docker exec [OPTIONS] CONTAINER COMMAND [ARG...]
```

### 이미지 관련 명령어
#### 이미지 목록 확인하기
- 다운로드한 이미지 목록을 확인
```bash
$ docker images [OPTIONS] [REPOSITORY[:TAG]]
```

#### 이미지 다운로드
```bash
$ docker pull [OPTIONS] NAME[:TAG|@DIGEST]

ex) docker pull ubuntu:14.04
```

#### 이미지 삭제
```bash
$ docker rmi [OPTIONS] IMAGE [IMAGE...]
```

### 이미지 빌드
- 파일과 함께 Dockerfile이 필요하다.
[참고](https://subicura.com/2017/02/10/docker-guide-for-beginners-create-image-and-deploy.html)
```
$ docker build [OPTIONS] PATH | URL | -
```
| 옵션 | 설명 |
|---|---|
|-t|생성할 이미지의 이름|


### 예제
```bash
# before
$ docker run -d -p 3306:3306 \
  -e MYSQL_ALLOW_EMPTY_PASSWORD=true \
  --name mysql \
  mysql:5.7

# after
$ docker run -d -p 3306:3306 \
  -e MYSQL_ALLOW_EMPTY_PASSWORD=true \
  --name mysql \
  -v /my/own/datadir:/var/lib/mysql \ # <- volume mount
  mysql:5.7
```
- mysql:5.7 이미지를 3306 포트로 백그라운드로 실행한다.
- 이름은 mysql 이고 컨테이너 내부의 `/var/lib/mysql` 디렉토리를 `/my/own/datadir`로 마운트시킨다.


### 배포
#### 로그인
```bash
$ docker login
```
#### 태그
```bash
$ docker tag TARGET_IMAGE[:TAG] IMAGE_NAME[:TAG]
```
```bash
$ docker tag target hmu332233/remote:1.0
```
$ docker tag
```
#### 배포
```bash
$ docker push IMAGE[:TAG]
```
```bash
$ docker push hmu332233/remote:1.0
```

### 기타
#### commit
컨테이너의 변경사항을 이미지파일로 저장
```bash
$ docker commit <옵션> <컨테이너 이름> <이미지 이름>:<태그>
// 예시
$ docker commit -a "hmu332233" -m "[Add] git" e54ca5efa2e9 minung--dev-env
```
| 옵션 | 설명 |
|---|---|
|-m|	로그 메세지|
|-a|	커밋한 사용자 이름|
