## copy 구현

```js
var copyFromElement = function(element) {
  element.select();
  document.execCommand('Copy');
};

document.getElementById('.btn').addEventListener('click', function(e) {
  copyFromElement(document.getElementById('복사할 selector'));
});
```

## 특정 영역 제외하고 클릭하기
```js
$('html').click(function(e) {
	if(!$('특정 영역 selector').has(e.target).length) {
	  // do something
	}
});
```
