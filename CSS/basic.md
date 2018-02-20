## 웹폰트 불러오기
```css
@font-face {
    font-family: GraublauWeb;
    src: url("파일이 있는 위치/GraublauWeb.otf") format("opentype");
}

@font-face {
    font-family: GraublauWeb;
    font-weight: bold;
    src: url("파일이 있는 위치/GraublauWebBold.otf") format("opentype");
}

h1 {
    font-family: GraublauWeb, Helvetica, Verdana, Sans-Serif;
}
```
