const { odd, even } = require('./var');

function checkOddOrEven(num) {
    if(num % 2) {
        return odd;
    }
    return even;
}

export default checkOddOrEven;