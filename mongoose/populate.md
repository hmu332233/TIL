## mongoose populate

몽고DB를 사용하다보면 하나의 다큐먼트가 다른 다큐먼트의 ObjectId를 쓰는 경우가 있다.  

그럴 때 ObjectId를 실제 객체로 치환하는 작업이 필요한데  
이를 편하게 해주는게 바로 `populate`이다.

## 사용법

선생님이 아래와 같이 데이터가 있다는 예제로 시작한다.
```json
//teacher
{
    "_id": {$oid:"599b03151c6e6f0159a72815"},
    "name": "홍길동",
    "students": [
        {$oid:"599c75f7836cc308789f5902"},
        {$oid:"599b4041cefd5d07c5be9594"}
    ]
}
```
<br/>

선생님의 스키마를 다음과 같이 준비한다.
```js
const teacherSchema = new mongoose.Schema({
  name: String,
  students: [{ type: mongoose.Schema.Types.ObjectId, ref: 'Student' }],
});
mongoose.model('Teacher', teacherSchema);
```
<br/>

이후 다음과 같이 호출하면
```js
Teacher.findOne({ name: '홍길동' }).populate('students').exec((err, data) => {
  console.log(data);
});
```
<br/>

이렇게 자동으로 바뀌어서 나오게됨! 짱편
```json
{
    "_id": {$oid:"599b03151c6e6f0159a72815"},
    "name": "홍길동",
    "students": [
        {
          "_id":{$oid:"599c75f7836cc308789f5902"},
          "name":"학생1",
          "age": 20
        },
        {
          "_id":{$oid:"599b4041cefd5d07c5be9594"},
          "name":"학생2",
          "age": 22
        }
    ]
}
```
<br/>

만약 학생 중 일부 속성만을 가져오고 싶으면 다음과 같이 두번째 인자로 넣어주면 된다
```js
Teacher.findOne({ name: '홍길동' }).populate('students','name').exec((err, data) => {
  console.log(data);
});
```

<br/>

이러면 이렇게 나온다!
```json
{
    "_id": {$oid:"599b03151c6e6f0159a72815"},
    "name": "홍길동",
    "students": [
        {
          "_id":{$oid:"599c75f7836cc308789f5902"},
          "name":"학생1"
        },
        {
          "_id":{$oid:"599b4041cefd5d07c5be9594"},
          "name":"학생2"
        }
    ]
}
```
<br/>

### 참고
[Mongoose(몽구스) populate](https://www.zerocho.com/category/MongoDB/post/59a66f8372262500184b5363)
