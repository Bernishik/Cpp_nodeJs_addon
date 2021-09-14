const calculate = require('bindings')('calc')

console.time("c++");
calculate.calc()
console.timeEnd("c++");