#include <iostream>
#include <cctype>
#include <stack>
#include <string>

using namespace std;

int operatorWithGreaterSuperiority(char operator_user){
    if(operator_user == '+' || operator_user == '-') return 1;
    else if(operator_user == '*' || operator_user == '/') return 2;
    return 0;
}

int operations(int value_one, int value_two, char operator_user){
    switch(operator_user){
        case '+': return value_one + value_two;
        case '-': return value_one - value_two;
        case '*': return value_one * value_two;
        case '/': return value_one / value_two;
    }
    return 0;
}

int transformDigitInNumber(char number){
    int transform = 0;
    transform = (transform * 10) + (number - '0');
    return transform;
}

int removeValuesAndOperator(stack <int> *values, stack <char> *operators){
   int value_one = values->top();
    values->pop();
    int value_two = values->top();
    values->pop();
    char operator_user = operators->top();
    operators->pop();

    return operations(value_two, value_one, operator_user);
}

int expressiomEvaluate(string expression){
    stack <int> values;
    stack <char> operators;
    int index;

    for(index = 0; index < expression.length(); index++){
        if(expression[index] == ' ') continue;
        else if(isdigit(expression[index])) values.push(transformDigitInNumber(expression[index]));
        else if(expression[index] == '(') operators.push(expression[index]);
        else if(operators.size() == 0) operators.push(expression[index]);
        else if(expression[index] == ')'){
            while(operators.top() != '('){
                values.push(removeValuesAndOperator(&values, &operators));
            }
            operators.pop();
        } else if(operatorWithGreaterSuperiority(operators.top()) <= operatorWithGreaterSuperiority(expression[index])){
            operators.push(expression[index]);
        } else if(operatorWithGreaterSuperiority(operators.top()) >= operatorWithGreaterSuperiority(expression[index])){
            values.push(removeValuesAndOperator(&values, &operators));
            operators.push(expression[index]); 
        }
    }
    while(operators.size() > 0){
        values.push(removeValuesAndOperator(&values, &operators));
    }
    return values.top();
}

int main(){
    
    cout << "Result 7: " << expressiomEvaluate("3 + 4") << "\n";
    cout << "Result 3: " << expressiomEvaluate("5 - 2") << "\n";
    cout << "Result 4: " << expressiomEvaluate("8 / 2") << "\n";
    cout << "Result 25: " << expressiomEvaluate("5 * 5") << "\n";
    cout << "Result 17: " << expressiomEvaluate("3 * 3 + ( 4 + 4 )") << "\n";
    cout << "Result 11: " << expressiomEvaluate("3 + 4 * 2") << "\n";
    cout << "Result 10: " << expressiomEvaluate("3 * 3 + 1") << "\n";

    return 0;
}
