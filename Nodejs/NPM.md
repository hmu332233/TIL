### 유용한 NPM 모음

- #### uglify-js
  - 불필요한 들여쓰기나 띄어쓰기를 없애 용량을 줄여준다.
  - [사이트](https://www.npmjs.com/package/uglify-js)

test.js
```js
function hello(name){
  console.log('Hi,' + name);
}
```

```bash
$ uglifyjs test.js
>> function hello(name){console.log("Hi,"+name)};

$ uglifyjs test.js -m
>> function hello(l){console.log("Hi,"+l)};
>> 변수 이름조차 짧게 줄여준다

$ uglifyjs test.js -o test.min.js -m
>> test.min.js로 실행결과를 저장해준다
```

- #### underscore
  - js의 빈약한 array기능을 보충해주는 패키지
  - [사이트](http://underscorejs.org/)

```js
const _ = require('underscore')

var arr = [3,6,9,12]

console.log(_.first(arr)) // => 3
console.log(_.last(arr))  // => 12
```

- #### supervisor
  - 서버쪽 코드가 수정될 때 자동으로 서버를 재실행 해준다.
  - [사이트](https://www.npmjs.com/package/supervisor)

```bash
$ npm install supervisor -g
```        
```bash
$ node app.js 대신 아래와 같이 한다
$ supervisor app.js
```

- #### decompress-zip
  - zip, tar 파일의 압축 해제, 내부 파일 목록 보기가 가능하다
  - [사이트](https://www.npmjs.com/package/decompress-zip)

```bash
$ npm install --save decompress-zip
```
```js
var Unzipper = require('decompress-zip');

app.post('/upload', upload.single('userfile'), function(req, res) {

    if (req.file){

        var filepath = path.join(req.file.destination, req.file.filename);
        var unzipper = new Unzipper(filepath);

        // .extract();
        unzipper.on("extract", function () {
            console.log("Finished extracting");
        });

        unzipper.extract({ path: "uploads/zip/"+req.file.filename});

        // .list();
        unzipper.on('list', function (files) {
            console.log('The archive contains:');
            console.log(files);
        });

        unzipper.list();
    }

    res.send('Uploaded : ' + req.file.filename );
});
```
