function operatorWithGreaterSuperiority(operator){
    if (operator === '+' || operator === '-' || operator === '**') return 1;
    else if (operator === '*' || operator === '/') return 2;
    return 0;
}

function operations(value_one, value_two, operator){
    switch (operator) {
        case '+': return value_one + value_two;
        case '-': return value_one - value_two;
        case '*': return value_one *  value_two;
        case '/': return value_one / value_two;
        case '**': return value_one ** value_two;
    }
}

function removeValuesAndOperator(operands, operators){
    let value_one = operands.pop();
    let value_two = operands.pop();
    let operator = operators.pop();
    return operations(Number(value_two), Number(value_one), operator);
}

function expressionEvaluate(expression){
    const operators = [], values = [];
    expression = expression.split(' ');
    for(let index = 0; index < expression.length; index++){
        if(Number(expression[index])) values.push(expression[index]);
        else if(expression[index] === '(') operators.push(expression[index])
        else if(operators.length === 0) operators.push(expression[index]);
        else if(expression[index] === ')'){
            while(operators[operators.length-1] !== '('){
                values.push(removeValuesAndOperator(values, operators));
            }
            operators.pop();
        } else if(operatorWithGreaterSuperiority(operators[operators.length-1]) <= operatorWithGreaterSuperiority(expression[index])){
            operators.push(expression[index]);
        } else if(operatorWithGreaterSuperiority(operators[operators.length-1]) >= operatorWithGreaterSuperiority(expression[index])){
            values.push(removeValuesAndOperator(values, operators));
            operators.push(expression[index]);
        }
    }
    while(operators.length > 0){
        values.push(removeValuesAndOperator(values, operators));
    }
    return values;
}

console.log('Result = 10', expressionEvaluate('5 + 5')) // 10
console.log('Result = 5', expressionEvaluate('10 - 5')) // 5
console.log('Result = 20', expressionEvaluate('2 * 10')) // 20
console.log('Result = 5', expressionEvaluate('10 / 2')) // 5
console.log('Result = 27', expressionEvaluate('3 ** 3')) // 27
console.log('Result = 18', expressionEvaluate('5 + 5 * 2 + 3')) // 18
console.log('Result = 15', expressionEvaluate('5 * 2 + ( 4 + 1 )')) // 15
console.log('Result = 10', expressionEvaluate('10 / 2 + ( 5 * 1 )')) // 10
console.log('Result = 14', expressionEvaluate('28 / 2')) // 14
console.log('Result = 7', expressionEvaluate('10 / 2 + 2')) // 7
