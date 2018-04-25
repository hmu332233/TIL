## 유용한 명령어 모음
- 중지된 컨테이너 한번에 삭제
```bash
$ docker rm -v $(docker ps -a -q -f status=exited)
```
- 모든 컨테이너 삭제
```bash
$ docker rm $(docker ps -a -q)
```
- 모든 이미지 삭제
```bash
$ docker rmi $(docker images -q)
```
- 캐시된 이미지 삭제
```bash
$ docker image prune -a
```
