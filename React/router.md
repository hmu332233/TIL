## react router
### 기본
```bash
$ npm install --save react-router react-router-dom
```

```jsx
import React from 'react';
import ReactDOM from 'react-dom';
import { BrowserRouter, Route } from 'react-router-dom'
import App from './components/App';

ReactDOM.render((
     <BrowserRouter>
          <Route path="/" component={App}/>
     </BrowserRouter>
     ),
     document.getElementById('root')
);
```
- filter
```jsx
<BrowserRouter>
  <Route path="/:filter?" component={Component} />
</BrowserRouter>
```
`this.props.match.params.filter`로 사용 가능

### +Redux
```jsx
ReactDOM.render((
  <Provider store = {store}>
    <BrowserRouter>
      <Route path="/" component={Component} />
    </BrowserRouter>
  </Provider>
  ),
  document.getElementById('root')
);
```
