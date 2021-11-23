var Users = [{name:'소녀시대', age:20}, {name:'걸스데이', age:22}, {name:'티아라', age:23}];
console.log('배열 요소의 수 : %d', Users.length);

// Add the elements to to the beginning of an array
Users.unshift({name: 'STAYC', age:20}, {name: '에스파', age:21});

// Delete the an element to to the beginning of an array
Users.shift();

// splice(start index, delete count, a new element, a new element, ...);
// Inserting new elements
Users.splice(2, 0, {name: '블랙핑크', age:22},  {name: 'ITZY', age:23});

// Removing 2 elements at index 2
Users.splice(2, 2);