def operatorWithGreaterSuperiority(operator):
    if operator == '+' or operator == '-' or operator == '**':
        return 1
    elif operator == '*' or operator == '/': 
        return 2
    else:
        return 0

def operations(value_one, value_two, operator):
    if operator == '+':
        return value_one + value_two
    elif operator == '-':
        return value_one - value_two
    elif operator == '*': 
        return value_one * value_two
    elif operator == '/':
        return value_one / value_two
    elif operator == '**':
        return value_one ** value_two
    else:
        return 0

def removeValuesAndOperator(operands, operators):
    value_one = operands.pop()
    value_two = operands.pop()
    operator = operators.pop()
    return operations(value_two, value_one, operator)

def transformDigitInNumber(number):
    transform = 0
    transform = (transform * 10)  + int(number)
    return transform

def expressionEvaluate(expression):
    operators = []
    values = []
    expression = expression.split(' ')
    for index, item in enumerate(expression):
        if expression[index].isdigit():
            values.append(transformDigitInNumber(expression[index]))
        elif expression[index] == '(':
            operators.append(item)
        elif len(operators) == 0:
            operators.append(item)
        elif expression[index] == ')':
            while len(operators) > 0 and operators[-1] != '(':
                values.append(removeValuesAndOperator(values, operators))
            operators.pop()
        elif operatorWithGreaterSuperiority(operators[-1]) <= operatorWithGreaterSuperiority(expression[index]):
            operators.append(item)          
        elif operatorWithGreaterSuperiority(operators[-1]) >= operatorWithGreaterSuperiority(expression[index]): 
                values.append(removeValuesAndOperator(values, operators))
                operators.append(item)
    while len(operators) > 0:
            values.append(removeValuesAndOperator(values, operators))
    return values

if __name__ == "__main__":
    print(f'Result 25: {expressionEvaluate("5 * 5")}')
    print(f'Result 12: {expressionEvaluate("6 + 6")}')
    print(f'Result 3: {expressionEvaluate("6 - 3")}')
    print(f'Result 3: {expressionEvaluate("6 / 2")}')
    print(f'Result 17: {expressionEvaluate("3 * 3 + ( 4 + 4 )")}')
    print(f'Result 56: {expressionEvaluate("50 + 2 * 3")}')
    print(f'Result 100: {expressionEvaluate("10 ** 2")}')
    print(f'Result 70: {expressionEvaluate("10 + 6 * 10")}')



