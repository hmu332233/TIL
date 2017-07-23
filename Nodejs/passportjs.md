## passportjs

- 사용자 로그인, '인증'을 편하게 할 수 있도록 도와주는 모듈
- 여러 회사들의 인증을 사용할때 동일한 방법으로 사용하도록 도와준다

### config
```bash
$ npm install --save passport passport-local
```

```js
var session = require('express-session');
var passport = require('passport')
  , LocalStrategy = require('passport-local').Strategy;

app.use(session({
  secret: '123456', // 암호화 key값
  resave: false,
  saveUninitialized: true
}));

app.use(passport.initialize());
app.use(passport.session());
```

### view
- 주의 할 점은 `name="username"`과 `name="password"`은 passport에서 약속해놓은 것이기때문에 바꾸면 안된다.
```html
<form action="/login" method="post">
    <div>
        <label>Username:</label>
        <input type="text" name="username"/>
    </div>
    <div>
        <label>Password:</label>
        <input type="password" name="password"/>
    </div>
    <div>
        <input type="submit" value="Log In"/>
    </div>
</form>
```
### route
- callback 함수를 직접 정의하지 않고 passport에게 위임한다
```js
app.post( '/auth/login',  
          passport.authenticate(
            //local 이라는 인증 방식이 사용됨
            //만약 facebook을 사용중이면 facebook을 입력하면된다.
            'local',
            {
              //로그인에 성공하면 redirect 되는 url
              successRedirect: '/welcome',
              //로그인에 실패하면 redirect 되는 url
              failureRedirect: '/auth/login',
              //실패했을 시, 메세지를 띄우기 위함
              failureFlash: false
            }
          )
);

//여기서 정의한 함수가 바로 위의 passport.authenticate에서
//만들어진 함수에서 사용자 인증에 사용된다
//username과 password는 사용자가 입력한 값이 넘어오고
//done은 함수가 담아져오는데
//done(null, 로그인된 사용자 객체)를 넣어주면 된다
//두번째 인자에 false를 넣으면 로그인에 실패한걸로 간주한다.
passport.use(new LocalStrategy(
  function(username, pwd, done) {

    for(var i in users){
      var user = users[i]

      if(username === user.username){
        if(pwd === user.password){
          done(null, user);
        } else {
          done(null,false);
        }
      })
    }
  }
));

//바로 위의 done(null,user); 가 실행되면 아래의 callback함수가 실행된다.
//첫번째 인자인 user가 사용자가 넘겨준 객체가 넘어온다
passport.serializeUser(function(user, done) {
  done(null, user.id);
});

//지금 로그인한 사용자가 페이지에 들어올때마다는 이 callback함수가 실행됨
// id는 바로 위에서 수행한 done(null,user,id); 에서의 user.id 값이 들어있다
passport.deserializeUser(function(id, done) {
  User.findById(id, function(err, user) {
    done(err, user);
  });
});
```
- 즉 `LocalStrategy` -> `serializeUser` -> `deserializeUser` 순으로 실행된다.  
  로그인 이후는 `deserializeUser`만 실행이된다

### 로그인 이후 사용자 정보 가져오기
  - 로그인 된 이후 user의 정보를 가져올 때는  
    `req.user` 만 하면 된다.
```js
app.get('/welcome', function (req, res) {

  if(req.user)
    res.send('hello,' , user.username );
});  
```

- 로그아웃 시에는 ` req.logout();`만 호출해주면 된다
```js
app.get('/auth/logout', function (req, res){
  req.logout();
  req.session.save(function(){
    res.redirect('/welcome');  
  });
})
```

- 회원가입 등으로 이미 user 객체가 있고  
  이를 바로 로그인 하고 싶을 경우에는 다음과 같이 하면 된다
```js
req.login(user,function(err){
  if(err) return next(err);
    return res.redirect('/welcome')
});
```
### 페이스북 로그인

- 페이스북 로그인과 같은 타사 인증은 대체로 route가 두개이다
- `/auth/facebook`는 페이스북에 인증을 요청하기 위함이고  
  `/auth/facebook/callback`는 페이스북에서 인증을 확인한 후 데이터를 다시 보내주기 위함이다  

```js
var passport = require('passport')
  , FacebookStrategy = require('passport-facebook').Strategy;

passport.use(new FacebookStrategy({
    clientID: FACEBOOK_APP_ID,
    clientSecret: FACEBOOK_APP_SECRET,
    callbackURL: "/auth/facebook/callback"
  },
  function(accessToken, refreshToken, profile, done) {
    User.findOrCreate(..., function(err, user) {
      if (err) { return done(err); }
      done(null, user);
    });
  }
));
```

```js
app.get('/auth/facebook', passport.authenticate('facebook'));

app.get('/auth/facebook/callback',
  passport.authenticate('facebook', { successRedirect: '/welcome',
                                      failureRedirect: '/auth/login' }));
```

- 사용자에게서 원하는 정보를 더 받아오고 싶으면 다음과 같이 한다
```js

passport.use(new FacebookStrategy({
    clientID: FACEBOOK_APP_ID,
    clientSecret: FACEBOOK_APP_SECRET,
    callbackURL: "/auth/facebook/callback",
    profileFields:['displayName','email'] // 이거 추가됨
    //명시적으로 받아올 필드를 써줘야한다
  }, //생략


app.get('/auth/facebook', passport.authenticate('facebook',{ scope: 'email' }));
```
[가져올 수 있는 정보 목록](https://developers.facebook.com/docs/facebook-login/permissions/)
