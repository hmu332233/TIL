## git remote url 변경하기

- ### 1. 현재 git remote url 확인
```bash
$ git remote -v
origin  https://github.com/hmu332233/원래저장소.git (fetch)
origin  https://github.com/hmu332233/원래저장소.git (push)
```

- ### 2. remote set-url을 통하여 remote url 변경
```bash
$ git remote set-url origin  https://github.com/hmu332233/바꿀저장소.git

```

- ### 3. 변경 결과 확인하기
```bash
$ git remote -v
origin  https://github.com/hmu332233/바뀐저장소.git (fetch)
origin  https://github.com/hmu332233/바뀐저장소.git (push)
```
