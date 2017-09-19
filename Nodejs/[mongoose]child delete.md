## childe delete

### 개요
디비를 이용하다보면 언제나 그렇지만
부모가 삭제될 경우 자식도 자동으로 삭제하도록 만들어야 할 때가 있다.  
`mysql`은 간단하게 가능하지만 아무래도 mongodb는 없는거 같다..  
그래서 찾아본 방법

### 해법
다음과 같이 `remove`시 먼저 실행되는 코드를 넣어 자식들도 삭제되도록 하면 된다.
```javascript
parentSchema.pre('remove', function(next) {
  //여기에 자식들도 삭제되는 코드를 넣는다
}
```

다음은 예제이다.
```javascript
parent.pre('remove', function(next) {
    // 'this' is the client being removed. Provide callbacks here if you want
    // to be notified of the calls' result.
    child1.remove({parent_id: this._id}).exec();
    child2.remove({parent_id: this._id}).exec();
    next();
});
```

### 출처
[Cascade style delete in Mongoose  - stackoverflow](https://stackoverflow.com/questions/14348516/cascade-style-delete-in-mongoose)
[mongoose middleware](http://mongoosejs.com/docs/middleware.html)
