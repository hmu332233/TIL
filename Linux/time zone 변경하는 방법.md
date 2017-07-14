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
