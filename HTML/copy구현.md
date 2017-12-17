## copy 구현


```js
var copyFromElement = function(element) {
  element.select();
  document.execCommand('Copy');
};

document.getElementById('api-table__copy-button').addEventListener('click', function(e) {
  copyFromElement(document.getElementById('api-table__user__access-id'));
});
```
