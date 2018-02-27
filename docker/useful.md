## 유용한 명령어 모음
- 중지된 컨테이너 한번에 삭제
```bash
$ docker rm -v $(docker ps -a -q -f status=exited)
```
