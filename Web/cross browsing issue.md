## IE 11
- ` `` `를 인식하지 않는다.
```js
var text = `abc${text2}`
=> var text = 'abc' + text2
```

- `window.focus` 동작
  - IE 시리즈는 `window.focus()` 동작시 기존에 포커스를 두고 있던 곳을 잃어버리고
  - 나머지 브라우저는 유지한다
