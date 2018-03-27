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

## input 없이 copy 구현
```js
function setClipboard(value) {
  var tempInput = document.createElement("input");
  tempInput.style = "position: absolute; left: -1000px; top: -1000px";
  tempInput.value = value;
  document.body.appendChild(tempInput);
  tempInput.select();
  document.execCommand("copy");
  document.body.removeChild(tempInput);
}
```

## 특정 영역 제외하고 클릭하기
```js
$('html').click(function(e) {
	if(!$('특정 영역 selector').has(e.target).length) {
	  // do something
	}
});
```

## div scroll 탐지하기
- scroll 바닥 탐지하기
```js
$('대상 selector').scroll(function() {
  if($(this).scrollTop() + $(this).innerHeight() >= $(this)[0].scrollHeight) {
    // do something..
  }
});
```

## 화면 중앙에 배치하기
```js
// target {jquery object}
function set_position(target) {
  var height = target.outerHeight();
  var width = target.outerWidth();

  var window_height = window.innerHeight;
  var window_width = window.innerWidth;

  var top = (window_height - height) / 2 - 50; // 50 for good looking position
  var left = (window_width - width) / 2;

  target.css('top', top + 'px');
  target.css('left', left + 'px');
}
```
