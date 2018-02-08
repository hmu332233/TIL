## Array functions
- ES5
- [참고](http://programmingsummaries.tistory.com/357)

### Array.forEach
- 배열 전체를 돌며 해당 배열의 요소에 직접 어떤 작업을 수행하고 싶을 때 적합
- 리턴값은 `undefined`
```js
var testArray = ["aaa", "bbb", "ccc"];

//메서드 수행 후 리턴값은 undefined
testArray.forEach(function (item, index, array) {
	console.log(item, index, array);
});
```
```
//result
aaa 0 ["aaa", "bbb", "ccc"]
bbb 1 ["aaa", "bbb", "ccc"]
ccc 2 ["aaa", "bbb", "ccc"]
```

### Array.map
- 배열 전체를 돌며 배열값을 사용해서 "또 다른 배열"을 만들고 싶을 때 매우 적합
- 원본 배열은 바뀌지 않으며  
  리턴값은 `새로운 배열`
```js
//원본 배열
var testArray = ["aaa", "bbb", "ccc", "ddd"];

//메서드 수행 후 리턴값은 새로운 배열
var newArray = testArray.map(function (item, index, array) {
	return item += 'zzz';
});

console.log(testArray);
console.log(newArray);
```
```
//result
["aaa", "bbb", "ccc"]
["aaazzz", "bbbzzz", "ccczzz"]
```
### Array.filter
- 배열에서 특정 케이스만 필터링해서 추출하여 "새로운 배열"을 만들고 싶을 때 적합
- 메소드 수행 중 콜백에서 true를 리턴하는 경우 해당 배열 요소를 새로운 배열에 추가하고,  
  메소드가 종료될 때 `새로운 배열을 리턴`한다

```js
var testArray = [111,222,333,'aaa','bbb','ccc'];

//type이 number인 배열만 남기기
testArray.filter(function (item, index, array) {
	return typeof item === 'number'
});
```
```
//result
[111,222,333]
```

### Array.some
- 배열 요소 중에서 하나라도 특정 조건을 만족하는지 알고 싶을 때 매우 적합
- 메소드 수행 중 콜백에서 **한번이라도 true를 리턴**하면 바로 메소드 수행을 중단하고 `true를 리턴`하며,  
  전체 요소를 다 돌때까지 콜백에서 **true를 리턴하지 않으면** `false를 리턴`한다.

```js
//원본 배열
var testArray = ["aaa", "bbb", "ccc", "ddd"];

//배열의 중에서 "bbb"가 있으면 true를 리턴
//메서드 수행 중 true가 리턴되면 메서드 수행을 중단하고 true를 리턴
testArray.some(function (item, index, array) {
	console.log(index + "번째 요소 : " + item);
	return !!~item.search("bbb");
});

//로그에 찍히는 내용
//0번째 요소 : aaa
//1번째 요소 : bbb

//true를 리턴하는 콜백이 있었으므로 리턴값은 true
true
```

### Array.every
- 배열의 모든 요소가 특정 조건을 만족하는지 알고 싶을 때 매우 적합
- 메소드 수행 중 콜백에서 **한번이라도 false를 리턴**하면 바로 메소드 수행을 중단하고 `false`를 리턴하며,  
  전체 요소를 다 돌때까지 콜백에서 **false를 리턴하지 않으면** `true를 리턴`한다.

```js
//원본 배열
var testArray = ["aaa", "bbb", "ccc", "ddd"];

//모두 string type이면 true를 리턴
testArray.every(function (item, index, array) {
	console.log(typeof item === 'string');
	return typeof item === 'string'
});

//false를 리턴하는 콜백이 없으므로 리턴값은 true
true
```

### Array.reduce
- 배열의 요소들을 하나씩 돌며, 이전 콜백의 리턴값을 `previous item`으로 넘겨받아  
  어떤 작업을 수행하고 싶을 때 매우 적합
- Promise를 활용한 비동기 작업의 순차적 실행 등에 이용하는 등 유용한 메소드

```js
//원본 배열
var testArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

//각 콜백마다의 리턴값을 previousItem 으로 넘겨받아 어떤 작업을 수행
//메서드가 종료되면 마지막 콜백의 리턴값을 리턴
var result = testArray.reduce(function (previousItem, currentItem, index, array) {

	//반환된 결과는 다음번 콜백의 첫번째 파라메터로 다시 전달된다.
	return previousItem + currentItem;
}, 0); // 첫 콜백함수의 previouseItem에 주입될 값

//메서드 수행 후 원본 배열
console.log(testArray);
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

//메서드 수행 후 리턴값은 0부터 10까지의 합
console.log(result);
55
```

---

### Array.concat
- 두 배열을 이어붙인다.

```js
var num1 = [1, 2, 3],
    num2 = [4, 5, 6],
    num3 = [7, 8, 9];

var nums = num1.concat(num2, num3);

console.log(nums); // 결과: [1, 2, 3, 4, 5, 6, 7, 8, 9]
```
