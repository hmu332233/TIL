## git-flow
git flow를 매우 편하게 사용할 수 있도록 명령어 셋을 제공하는 것

### 설치
기본적으로 git이 설치가 되어있어야 한다
```bash
$ apt-get install git-flow
```

### 사용법
초기화
- 브랜치 명명규칙을 정하는 단계
- 그냥 끝날 때까지 엔터를 누르자! (master, develop, feature, release, hotfix)
```bash
$ git flow init
```

시작하기(start)
- 기능 개발 또는 릴리즈 준비 등을 시작하기 위해 브랜치를 생성하는 방법이다
- `-F`옵션을 주면 명령 실행 전에 원격 저장소에서 업데이트 받겠다는 의미이다
```bash
$ git flow feature start -F <issue_name>
$ git flow release start -F <release_ver>
$ git flow hotfix start -F <release_ver>
```
게시하기(publish)
- 로컬 저장소에 있는 브랜치를 원격 저장소에 게시하는 방법
```bash
$ git flow feature publish <issue_name>
$ git flow release publish <release_ver>
```
닫기(finish)
- 릴리즈 준비가 완료되었을 때 브랜치를 병합하고 삭제하는 방법이다 (release도 추가된다)
- 차례대로 master에 병합할 커밋 메세지, 태그 메세지, develop에 병합할 커밋 메세지를 입력하게 된다
```bash
$ git flow release finish -Fp <release_ver>
$ git flow hotfix finish -Fp <release_ver>
```
가져오기(track)
- 다른 개발자가 개발한 기능, 릴리즈 될 코드를 테스트하기 위해 원격 저장소에 게시된 브랜치를 내 로컬 저장소로 최초에 가져오는 방법
```bash
$ git flow hotfix finish -Fp <release_ver>
```
