## macOS에서 nodejs 설치하기

### nvm 설치
#### 설치
```bash
$ curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.31.0/install.sh | bash
```
#### 설치 확인
```bash
$ nvm --version
```
만약 not found가 뜬다면 아래와 같은 방법을 이용
```bash
$ [[ -s $HOME/.nvm/nvm.sh ]] && . $HOME/.nvm/nvm.sh
```
`.nvm` 경로를 모를 경우 아래 명령어를 이용해서 위치를 찾아내면 된다
```bash
ls -a | grep .nvm
```

### nodejs 설치
#### lts 설치
```bash
$ nvm install node
```
#### ex) 5.0 설치
```bash
$ nvm install 5.0
```
#### 사용
```bash
$ nvm use 5.0
```


### nvm 사용법
#### 설치된 nodejs 목록
```bash
$ nvm ls
```

#### 설치
```bash
$ nvm install v4
```
4.x중 가장 최신버전을 가져와 설치해준다.
