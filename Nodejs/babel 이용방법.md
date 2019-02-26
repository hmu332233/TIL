## nodejs에서 babel 이용하기

다음과 같이 설치 후 `index.js`에 babel/register를 불러오고 `app.js`에서부터 자유롭게 import 등을 사용하면 된다.
```bash
npm install --save-dev @babel/core @babel/register @babel/preset-env
```

```js
// index.js
require("@babel/register")({
  presets: [ '@babel/preset-env' ]
});
require('./app');
```