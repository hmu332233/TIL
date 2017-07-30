## drag and drop 만들기

```js

$("#drag_zone").on({
  //진입할때
  dragenter: function (e) {
    console.log('dragenter');
    e.preventDefault();
  },
  //안에 있을때
  dragleave: function (e) {
    console.log('dragleave');
  },
  //떠날때
  dragover: function (e) {
    console.log('dragover');
    e.preventDefault();
  },
  //놓았을때
  drop: function (e) {

    console.log('drop');
  }
});
```

### 주의할 점

- `dragenter`와 `dragover`에 `e.preventDefault();`가 없으면 `drop`이 작동하지 않는다.
