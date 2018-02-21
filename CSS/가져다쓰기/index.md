## 텍스트 길 때 ...으로 줄이기
```css
.text-overflow-ellipsis {
	overflow: hidden;
	text-overflow: ellipsis;
	white-space: nowrap;
}
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
