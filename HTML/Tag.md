## tag

### img
- change image on hover
```html
<a href="TARGET URL GOES HERE">
    <img src="URL OF FIRST IMAGE GOES HERE"
         onmouseover="this.src='URL OF SECOND IMAGE GOES HERE';"
         onmouseout="this.src='URL OF FIRST IMAGE GOES HERE';">
    </img>
</a>
```
[참고](https://stackoverflow.com/questions/9400883/change-image-on-hover)

- onerror
```html
<img src="image" alt="image" onError={(e) => { e.target.src='alternative_image.png' }} />
```
