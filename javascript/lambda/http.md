## https
- v6.10
```js
var http = require('http');

exports.handler = function(event, context) {
  var url = 'http://sobi.chonbuk.ac.kr/chonbuk/m040101';
  console.log('start request to ' + event.url)
  http.get(url, function(res) {
  var body = '';
  res.on('data', function(chunk) {
    body += chunk;
  });
  res.on('end', function() {
    // console.log(body);
    context.done(null, body);
  });
}).on('error', function(e) {
  console.log("Got error: " + e.message);
});
}
```
