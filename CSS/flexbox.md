## flex box
- 정렬의 끝판왕
### 기억할거
1. 나 플렉스박스 쓸거임
2. 방향은 어디로 정렬할 거니?
3. 크기 유지할거야 아님 알아서 조정할까?
4. 느낌적 느낌대로 정렬!

#### 1. 나 플렉스박스 쓸거임
- 정렬을 할 요소를 가진 **부모** 에게  
  `display:flex`만 주면 flexbox 사용 준비 완료
```css
.parent{ display:flex }
```

#### 2. 아이템을 어느 방향으로 정렬지 결정
- `flex-direction: row || column`
- `row` 가로 (default)
- `column` 세로
```css
.parent{
  display:flex;
  flex-direction: row;
}
```
- flex-direction과 같은 방향의 축: main axis
- flex-direction과 반대 방향의 축: cross axis
![a](/assets/html/flex-direction.PNG)

#### 3. 어떻게든 한 줄을 유지할래? 아니면 본래 사이즈를 유지하는게 중요한가?
- `flex-wrap: wrap || nowrap`
- `wrap` 한 줄을 유지하기위해 자동으로 사이즈를 바꿈
- `nowrap` 본래의 사이즈를 유지함
```css
.parent{
  display:flex;
  flex-wrap: nowrap;
}
```
#### 4. 느낌대로 정렬
- `main axis`를 기준으로 정렬하려면 `justify-content`
- `cross axis`를 기준으로 정렬하려면 `align-items`

```css
{
  justify-content: flex-start; 자식 왼쪽(위)에 붙이기
  justify-content: center; 자식 가운데 정렬
  justify-content: flex-end; 자식 오른쪽(아래)에 붙이기

  justify-content: space-between; 공간에 맞게 퍼트뜨린다. 간격다 똑같이
  justify-content: space-around; 자식들의 마진을 모두 똑같이(그 공간 기준으로)
}
```

```css
/* 자식들 전체로*/
{
  align-items: flex-center; 중앙에 모우기
  align-items: flex-end; 끝에 붙이기
}
```

```css
/* 자식들 각각*/
{
  align-content: center; 각 자식들이 모두 중앙에 모임
  align-content: space-between; 각 자식들이 위 아래로 퍼진다
}
```

### 순서바꾸기
- 아이템의 순서를 바꾸고 싶을 땐, `order`속성 하나면 끝!
![A](/assets/html/order.PNG)


### 예제
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>FRONTEND101 | 갇 Flexbox</title>
  <link rel="stylesheet" href="css/ress.css">
  <link rel="stylesheet" href="css/flexbox.css">
</head>
<body>
  <h1 class="title">LEGACY CSS vs FLEXBOX</h1>
  <header class="header">
    <h1 class="brand">Mobile</h1>
    <nav class="gnb">
      <h2 class="sr-only">Menu</h2>
      <ul class="gnb-menu">
        <li><a href="#">Home</a></li>
        <li><a href="#">Benefits</a></li>
        <li><a href="#">Features</a></li>
        <li><a href="#">Testimonials</a></li>
        <li><a href="#">Get App</a></li>
        <li><a href="#" class="btn-link">CTA</a></li>
      </ul>
    </nav>
  </header>
</body>
</html>
```

```css
/* Common Settings */
html {
  font-family: 'Montserrat', sans-serif;
  font-size: 14px;
  line-height: 1;
  color: #fff;
  background-color: #000;
}

a {
  text-decoration: none;
  color: inherit;
}

ul {
  list-style-type: none;
  padding: 0;
}

.sr-only {
  font-size: 0;
}

.title {
  padding: 200px 0 70px;
  text-align: center;
}


/* Header */
.header {
  width: 100%;
  height: 80px;
  padding: 0 100px;
  text-transform: uppercase;
  background-color: #f12a2a;
}

.brand {
  font-size: 20px;
}

.gnb-menu {
  font-size: 13px;
}

.btn-link {
  display: inline-block;
  padding: 10px 38px;
  border-radius: 100px;
  border: 1px solid #fff;
}


/* Legacy Code */
/*.gnb-menu::after {
    content: '';
    display: block;
    clear: left;
}

.gnb-menu li {
    float: left;
    margin-right: 40px;
    line-height: 80px;
}

.gnb-menu li:last-child {
    padding: 22.5px 0;
    margin-right: 0px;
    line-height: 1px;
}

.header::after {
    content: '';
    display: block;
    clear: both;
}

.brand {
    float:left;
    line-height: 80px;
}

.gnb {
    float:right;
}*/

/* Flexbox Code */
.gnb-menu{
    display:flex;
    flex-direction: row;
    flex-wrap: nowrap;
    justify-content: space-between;
    align-items: center;
    width:646px;
}

.header{
    display:flex;
    flex-direction: row;
    flex-wrap: nowrap;
    justify-content: space-between;
    align-items: center;
}
```
