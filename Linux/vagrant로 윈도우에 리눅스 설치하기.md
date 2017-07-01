## vagrant를 이용해 윈도우에서 리눅스(ubuntu)를 설치하는 방법

### 필요 프로그램 설치

- #### virtual Box 설치
  - https://www.virtualbox.org/wiki/Downloads

- #### putty 설치
  - http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html
  - 여기서 putty.exe를 찾아 다운로드한다.

- #### vagrant 설치
  - https://www.vagrantup.com/downloads.html


### 리눅스 설치

  1. cmd를 켠 후 리눅스 환경이 되길 원하는 폴더로 이동한다.
  2. `vagrant init ubuntu/trusty64` 라고 입력한다
  3. 만들어진 `vagrantfile`에서  
     `config.vm.network "forwarded_port", guest: 3000, host: 3000`  
     이 부분 주석 풀고 위와 같이 변경한다.

### 실행

  1. 리눅스를 설치한 폴더로 이동한다.
  2. `vagrant up`이라고 입력한다.(가상머신 구동)
  3. putty를 이용해 다음과 같이 입력하고 실행한다.
      - hostname : `localhost`
      - port : `2222`
  4. 가상머신이 구동되고 아이디와 비밀번호를 입력한다
      - default id,pw : `vagrant`
  5. `cd /vagrant`를 입력해 기본 폴더로 이동한 후 작업한다.

  <br/>
  - `Microsoft Visual C++ 2010 SP1 Redistributable Package (x86)` 가 설치되어있지 않으면 에러가 나니 아래의 링크에서 설치하도록 한다.
  - https://www.microsoft.com/en-us/download/details.aspx?id=8328
