## Navbar highlight for current page
- navbar에서 현재 페이지에 대해 하이라이팅을 줘야하는 상황
- [참고](https://stackoverflow.com/questions/26819675/navbar-highlight-for-current-page/33697152#33697152)

```html
<script src="http://code.jquery.com/jquery-2.1.4.min.js"></script>
<script>
    $(function(){
        $('a').each(function(){
            if ($(this).prop('href') == window.location.href) {
                $(this).addClass('active'); $(this).parents('li').addClass('active');
            }
        });
    });
</script>
```
```css
#nav_bar .active {
    color:            #F8F8F8;
    background-color: #4f81bd;
}
```
