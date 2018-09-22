## nodejs 버전 변경하기

### nvm을 이용한 버전 변경

#### nvm 설치
```
$ apt-get update
$ apt-get install build-essential libssl-dev

$ curl https://raw.githubusercontent.com/creationix/nvm/v0.18.0/install.sh | bash
```
[nvm github](https://github.com/creationix/nvm)에서 최신버전의 nvm을 설치한다

#### 사용가능한 nodejs 버전 확인
`nvm ls-remote`

#### nodejs 설치
`nvm use 4.2.1`
#### 설치된 nodejs 목록 확인
`nvm ls`

#### 기타
- zsh 사용시 mac에서 추가할 것 (~/.zshrc)
```
export NVM_DIR="~/.nvm"
source ~/.nvm/nvm.sh
```

### n을 이용한 버전 변경
- apt-get을 사용해 nodejs를 설치한 경우 변경이 바로 되지 않는다.
- `npm n`을 이용해 버전을 변경하도록 한다.
- (추후 추가..)
