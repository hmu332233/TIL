```js
MyComponent.propTypes = {
  // 기본적인 type
  optionalArray: PropTypes.array,
  optionalBool: PropTypes.bool,
  optionalFunc: PropTypes.func,
  optionalNumber: PropTypes.number,
  optionalObject: PropTypes.object,
  optionalString: PropTypes.string,
  optionalSymbol: PropTypes.symbol,

  // Anything that can be rendered: numbers, strings, elements or an array
  // (or fragment) containing these types.
  optionalNode: PropTypes.node,

  // 리엑트 엘리먼트
  optionalElement: PropTypes.element,

  // 특정 클래스의 인스턴스
  // JS의 instanceof 기능과 동일
  optionalMessage: PropTypes.instanceOf(Message),

  // 이것들 중에 하나로 제한
  optionalEnum: PropTypes.oneOf(['News', 'Photos']),

  // 이 타입들 중에 하나로 제한
  optionalUnion: PropTypes.oneOfType([
    PropTypes.string,
    PropTypes.number,
    PropTypes.instanceOf(Message)
  ]),

  // 특정 타입의 배열
  optionalArrayOf: PropTypes.arrayOf(PropTypes.number),

  /*
    object의 value들이 특정 타입이여야함
    const object = {
      key1: 37.331706,
      key2: -122.030783
    }
  */
  optionalObjectOf: PropTypes.objectOf(PropTypes.number),

  /*
    특정 모양을 하고 있는 object
    const object = {
      color: 'red',
      fontSize: 16
    }
  */
  optionalObjectWithShape: PropTypes.shape({
    color: PropTypes.string,
    fontSize: PropTypes.number
  }),

  // isRequired가 붙은건 props으로 안받으면 경고를 뿜는다
  requiredFunc: PropTypes.func.isRequired,
  requiredAny: PropTypes.any.isRequired,

  // 커스텀 validator도 명세가능하다.
  // 단, `oneOfType`에서는 동작하지않는다.
  customProp: function(props, propName, componentName) {
    if (!/matchme/.test(props[propName])) {
      return new Error(
        'Invalid prop `' + propName + '` supplied to' +
        ' `' + componentName + '`. Validation failed.'
      );
    }
  },

  // `arrayOf` 와 `objectOf` 또한 커스텀이 가능하다.
  // object 또는 array의 각 key들에 의해 validator가 호출된다
  // validator의 첫번째와 두번째 파라미터는 array 또는 object의 본인과 현재 아이템의 key이다.
  customArrayProp: PropTypes.arrayOf(function(propValue, key, componentName, location, propFullName) {
    if (!/matchme/.test(propValue[key])) {
      return new Error(
        'Invalid prop `' + propFullName + '` supplied to' +
        ' `' + componentName + '`. Validation failed.'
      );
    }
  })
};
```
