## mongoose tip

### lean
- `lean()`을 사용하면 find시 **mongoose object가 아닌 일반 json으로 리턴**해준다
- 이를 통해 로드 속도가 빨라지므로 데이터만 필요한 경우에 `lean()`을 붙여 성능 향상을 주자
- [참고](http://www.tothenew.com/blog/high-performance-find-query-using-lean-in-mongoose-2/)

```js
Event.find({'schedule.closing': {'$gte': +new Date()}},
        {},
        {limit:20, skip:0}
    ).lean().exec(function (err, events){
 ........
 ........
  }
);
```