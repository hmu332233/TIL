### time zone 변경하는 법

  - 현재 시간 확인
  ```bash
  $ date
  Sat Jul 15 04:33:28 KST 2017
  ```

  - time zone 확인
  ```bash
  $ more /etc/timezone
  Asia/Seoul
  ```

  - time zone 변경  
  아래와 같이 입력한 후 원하는 국가와 도시를 선택해주면 된다.
  ```bash
  $ sudo dpkg-reconfigure tzdata
  ```
  아래와 같이 한 줄로도 가능하다
  ```bash
  # ubuntu
  $ sudo bash -c 'echo "Asia/Seoul" > /etc/timezone' && dpkg-reconfigure -f noninteractive tzdata
  # debian
  $ bash -c 'echo "Asia/Seoul" > /etc/timezone' && rm /etc/localtime && dpkg-reconfigure -f noninteractive tzdata
  ```
  또다른 방법
  ```bash
  $ ln -snf /usr/share/zoneinfo/Asia/Seoul /etc/localtime && echo Asia/Seoul > /etc/timezone
  ```