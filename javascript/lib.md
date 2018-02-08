## axios

```js
axios.get('/user?id=velopert')
    .then( response => { console.log(response); } ) // SUCCESS
    .catch( error => { console.log(error); } ); // ERROR

axios.get('/user', {
        params: { id: 'velopert' }
    })
    .then( response => { console.log(response) } );
    .catch( error => { console.log(error) } );

axios.post('/msg', {
    user: 'velopert',
    message: 'hi'
  })
  .then( response => { console.log(response) } )
  .catch( response => { console.log(response) } );
```
