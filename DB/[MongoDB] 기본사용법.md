### 설치
- MongoDB 설치 :  
  `apt-get install mongodb`
- 몽고DB가 사용하는 기본 데이터 디렉토리를 생성 :  
  `mkdir -p /data/db`
```bash
$ apt-get install mongodb
$ mkdir -p /data/db
```
- 최신버전 설치
  - 위의 진행사항으로는 `2.4.9` 버전이 설치가 된다.
  - 아래의 방법으로 최신버전을 설치할 수 있다.
```bash
$ sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 7F0CEB10
$ echo "deb http://repo.mongodb.org/apt/ubuntu "$(lsb_release -sc)"/mongodb-org/3.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-3.0.list
$ sudo apt-get update

// 최신버전 설치
$ sudo apt-get install -y mongodb-org

// 버전 명시 설치
$ sudo apt-get install -y mongodb-org=3.0.6 mongodb-org-server=3.0.6 mongodb-org-shell=3.0.6 mongodb-org-mongos=3.0.6 mongodb-org-tools=3.0.6
```

### 삭제

```bash
$ sudo apt-get purge mongodb mongodb-clients mongodb-server mongodb-dev
$ sudo apt-get purge mongodb-10gen
$ sudo apt-get autoremove
```

### 실행
- 서버실행 : `mongod`
- 콘솔 접속 : `mongo`
<br/>
- 최소한의 용량이 없으면 실행이 되지 않는데 그 때 `mongod --smallfiles`를 하면 실행은 된다. (공부용일때는 괜찮을거 같다)

### 특징

| RDB(MySQL)  | MongoDB  |
|---|---|
| Table  | Collection  |
| Tuple  | Row	Document or BSON document  |
| Column  | Field  |
| Table Join  | Embedded Documents & Linking  |
| Primary Key  | Primary Key (_id)  |

## CRUD
### 데이터 베이스 생성
`use database_name`
```
> use mu_db
switched to db mu_db
```
`db`로 현재 사용중인 db이름 확인 가능
`show dbs`로 데이터베이스 목록들을 확인 가능
  - 단 최소 한개 이상의 document가 있어야한다.
  - `show databases`도 가능
### 데이터 삽입
- `insert()`메서드를 이용하여 collection에 document를 넣을 수 있다.
```
db.collection_name.insert(
  <document>,
  {
    writeConcern: <document>,
    ordered: <boolean>
  }
)
```
<document>는 json의 형태를 띄어야한다.
같은 collection이라도 서로 다른 스키마를 가질 수 있다

```
db.books.insert([
  { title: "Example2", author: "Lee", price: 200 },
  { title: "Example3", author: "Lee", price: 300 },
  { title: "Example4", author: "Lee" }
  ])
```

```
db.getCollectionNames()
["books"]
```

### 데이터 읽기
- `find()`를 이용해 collection 내의 document를 select 한다
```
db.collection.find(query, projection)
```
`pretty()`를 이용하면 이쁘게 출력해준다

```
db.users.find(
  { },
  { title: 1, author: 1 }
)
```
- `0`은 가져오지 않겠다는 것이고 `1`은 가져오겠다는 뜻이다
- `_id`는 기본적으로 포함이므로 명시적으로 `0`을 해줘야 안가져올 수 있다
```
SELECT title, author
FROM books
```
```
db.users.find(
  { },
  { _id: 0, title: 1, author: 1 }
)
```
### 데이터 수정
```
db.<collection_name>.update(
  <query>,
  <update>,
  {
    upsert: <boolean>,
    multi: <boolean>,
    writeConcern: <document>
  }
)
```

### 데이터 삭제
```
db.collection.remove(
  <query>,
  {
    justOne: <boolean>,
    writeConcern: <document>
  }
)
```
