## Vendor Prefix 
- 브라우저 공급 업체는 실험적 또는 비표준 CSS 속성 및 JavaScript API에 접두사를 추가하기도하기도 한다.
- 정식으로 추가되기 전까지

### 종류
- `-webkit-` (Chrome, Safari, newer versions of Opera, almost all iOS browsers (including Firefox for iOS); basically, any WebKit based browser)
- `-moz-` (Firefox)
- `-o-` (Old, pre-WebKit, versions of Opera)
- `-ms-` (Internet Explorer and Microsoft Edge)

### 사용법
- 브라우저 접두어가 붙은 아이들을 위쪽에, 정식 지원하는 애들을 아래쪽에 둔다
```css
div {
  -moz-border-radius: 10px;
  -webkit-border-radius: 10px;
  -o-border-radius: 10px;
  border-radius: 10px;
}
```
