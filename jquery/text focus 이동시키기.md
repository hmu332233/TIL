## text focus 이동시키기

```html
  
<textarea id="the-textarea" cols="40" rows="4">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</textarea>
<br><input type="button" id="set-textarea" value="Set in textarea">
<br><input id="the-input" type="text" size="40" value="Lorem ipsum dolor sit amet, consectetur adipiscing elit">
<br><input type="button" id="set-input" value="Set in input">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
  
  <script>
  function setSelectionRange(input, selectionStart, selectionEnd) {
  if (input.setSelectionRange) {
    input.focus();
    input.setSelectionRange(selectionStart, selectionEnd);
  } else if (input.createTextRange) {
    var range = input.createTextRange();
    range.collapse(true);
    range.moveEnd('character', selectionEnd);
    range.moveStart('character', selectionStart);
    range.select();
  }
}

function setCaretToPos(input, pos) {
  setSelectionRange(input, pos, pos);
}

$("#set-textarea").click(function() {
  setCaretToPos($("#the-textarea")[0], 10)
});
$("#set-input").click(function() {
  setCaretToPos($("#the-input")[0], 10);
});
  </script>
  
```

[출처](https://stackoverflow.com/questions/499126/jquery-set-cursor-position-in-text-area)
