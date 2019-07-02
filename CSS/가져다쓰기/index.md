## 텍스트 길 때 ...으로 줄이기
```css
.text-overflow-ellipsis {
	overflow: hidden;
	text-overflow: ellipsis;
	white-space: nowrap;
}
```

## 줄바꿈

### 글자 단위로 자르기
```css
word-wrap: break-word;
word-break: break-all;
```

### 단어 단위로 자르기
```css
word-wrap: break-word;
word-break: keep-all;
```

## 텍스트 드래그 스타일링
```css
::selection
{
color: white;
background-color: #ff7473;
}

::-moz-selection  /* Firefox needs an extra attention for this */
{
color: white;
background-color: #ff7473;
}
```


## image wrapper
```css
.imageWrapper {
	position: relative;
	width: 12.8125rem; // 205px
	height: 6.625rem; // 106px
	margin-right: 1.5625rem; // 25px
	overflow: hidden;
}
.imageWrapper img {
	width: 100%;
	height: auto;
	position: absolute;
	top: -100%;
	bottom: -100%;
	margin: auto;
}
```

## flex warp 마진 상관없이 밑으로 내려가도록 하기
```css
.parent {
	display: flex;
	flex-wrap: wrap;
	margin-left: 10px;
	margin-right: 10px;
}
.child {
	margin-left: 10px;
	margin-right: 10px;
}
```
