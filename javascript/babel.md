## babel
- es6,es7등의 코드를 es5로 변환하기 위한 도구
### 명령어
- 설치
```bash
$ npm install --save-dev babel-cli
```

- 기본 사용법
```bash
$ babel example.js --out-file compiled.js
$ babel example.js -o compiled.js
// 두개가 같음
```

### 옵션
- `.babelrc`
  - 변환에 필요한 옵션들을 써놓는 파일
```
{
  "presets": [],
  "plugins": []
}
```
- presets
  - babel이 해석하게 도와주는 것?
```
$ npm install --save-dev babel-preset-es2015
$ npm install --save-dev babel-preset-react
```
```
.babelrc

{
  "presets": ["es2015", "react"],
  "plugins": []
}
```


- babel-polyfill
  - es6 문법을 사용가능하게 해준다
  - 코드에 직접 `import`해서 사용
  - 전역스코프에 덮어져씌우는 것이므로 주의가 필요하다.
  - 브라우저에서는 `dist/polyfill.js` 또는 `dist/polyfill.min.js`을 이용한다.
```bash
$ npm install --save-dev babel-polyfill
```

- ES2015 arrow functions transform
```bash
$ npm install --save-dev babel-plugin-transform-es2015-arrow-functions
```
```
.babelrc

{
  "plugins": ["transform-es2015-arrow-functions"]
}
```
