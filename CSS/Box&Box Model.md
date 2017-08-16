## Box와 Box Model

- content-box
  - 요소의 content의 크기만큼
- padding-box
  - 테두리와 content 사이 여백
- border-box
  - 테두리
- margin-box
  - 요소와 요소 사이 간격


모든 요소를 css 세계에서는 박스로 본다

### box의 종류
#### display
- **block**
  - 길막
  - 자신의 아래에 있는 요소들이 위로 올라오지 못하게 길막을 한다.
  - 그 한 줄은 이 아이만 차지한다고 생각하면됨
  - 별도의 width 값을 주지 않았을 때 **부모의 content-box의 width만큼** 쫙쫙 늘어난다
  - 별도의 width값이 주어졌을 땐, **남은 빈 공간을 margin으로** 꽉꽉 채워버린다
  - 별도의 height값이 주지 않았을 때 자신의 자식의 크기만큼 높이를 가진다
  ![block](/assets/html/block.PNG)
- **inline**
  - 흐름
  - 선 안에서 흐르는 녀석들이 바로 inline 박스
  - 선Line에 맞춰서 옆으로 쭉쭉 늘어설려고하는 특징을 가진다
  - `<p>`태그안의 text들이 대표적이다
  ![block](/assets/html/inline.PNG)
- **inline-block**
  - inline과 block의 성질을 모두 가진 아이
  - 영역의 성질과 옆으로 흐르는 성질을 모두 가진 아이
  - width, height, padding-top, padding-bottom, margin-top, margin-bottom 모두 사용가능! 근데 옆으로 흐름!
- **flex**
  - 따로 추가  

#### block, inline 비교
block:inline = 면:선  
block:inline = 영역:흐름  

width, height, padding-top, padding-bottom, margin-top, margin-bottom은 인라인 요소에게 사용 불가!  
이런 값들은 오로지 영역을 차지할 수 있는 블록 요소에게만 사용할 수 있다

#### box-sizing
box-sizing의 기본값은 content-box!
- 총 가로 길이 = width + padding + border
- 총 세로 길이 = height + padding + border
그래서 box-sizing를 border-box 기준으로 사이즈를 주면
- 총 가로 길이 = widht
- 총 세로 길이 = heigth


#### 예제코드
```html
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <style type="text/css">
      * {
        box-sizing: border-box;
      }

      a {
        text-decoration: none;
        color: #000;
      }

      .link-btn {
        display: block;
        width: 140px;
        height: 140px;
        padding: 20px;
        border-radius:20px;
        font-size:16px;
        font-weight: 700;
        font-family: 'Spoqa Han Sans', sans-serif;
        background-color: #ffcd10;
      }
    </style>
  </head>
  <body>
    <a href="#" class="link-btn">
      오늘의<br/>
      멋사소식
    </a>

    <p>
    가로/세로는 140px이고
    안쪽으로 각 20px 씩 여유가 있어야 해요!
    폰트는 스포카체, 글자 크기는 16px이고 줄간격은 20px입니다.
    모퉁이 반지름은 20px로 둥글게 깎아주시면 되고,
    마지막으로 글자 색상은 #000, 배경색은 #FFCD10입니다.
    </p>
  </body>
</html>
```
