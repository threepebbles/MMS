function Person(name, age) {
    this.name = name;
    this.age = age;
}

Person.prototype.walk = function(speed) {
    console.log(speed + 'km 속도로 걸어갑니다.');
}

var person01 = new Person('소녀시대', 20);

Person.prototype.num = 9;   
// "num" property is created to all of the Person objects including the existing objects.
person01
