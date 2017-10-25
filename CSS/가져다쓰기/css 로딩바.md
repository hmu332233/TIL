- html
```html

<div class="spinner"></div>
```
- css
```css
/* 키프레임 애니메이션*/
@keyframes spin {
  100% {
    transform: rotate(360deg);
  }
}
.spinner {
  display: inline-block;
  /* 직사각형을 만들고 */
  width: 50px;
  height: 50px;
  border: 5px solid red;
  /* border-top을 제외한 나머지를 투명하게 */
  border-color: red transparent transparent;
  /* border를 둥굴게 */
  border-radius: 50%;
  /* 키프레임 등록 : 키프레임 이름, 재생시간, 일정속도, 무한반복*/
  animation: spin 1s linear infinite;
}
```
