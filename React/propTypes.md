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

  // You can chain any of the above with `isRequired` to make sure a warning
  // is shown if the prop isn't provided.
  requiredFunc: PropTypes.func.isRequired,

  // A value of any data type
  requiredAny: PropTypes.any.isRequired,

  // You can also specify a custom validator. It should return an Error
  // object if the validation fails. Don't `console.warn` or throw, as this
  // won't work inside `oneOfType`.
  customProp: function(props, propName, componentName) {
    if (!/matchme/.test(props[propName])) {
      return new Error(
        'Invalid prop `' + propName + '` supplied to' +
        ' `' + componentName + '`. Validation failed.'
      );
    }
  },

  // You can also supply a custom validator to `arrayOf` and `objectOf`.
  // It should return an Error object if the validation fails. The validator
  // will be called for each key in the array or object. The first two
  // arguments of the validator are the array or object itself, and the
  // current item's key.
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
