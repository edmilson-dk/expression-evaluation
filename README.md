# Expression Evaluate

## Whats is evaluate expression?

Basically, an expression evaluation is an algorithm that aims to receive a mathematical expression and return the result of that expression, however, that expression must be passed to the algorithm in the form of a string, that is, the algorithm has a duty to transform past values into integer values to return a correct result,this algorithm normally uses 2 stacks to store the operands and the operators.

also note that this algorithm is based on the infix expression, but it can be implemented using the prefix expression or postfix expression.

### Examples of the 3 expressions

#### Infix

`` 5 + 4``

#### prefix

`` + 5 4``

#### postfix

`` 5 4 + ``

the expression infix is more costly for the machine to evaluate, since this notation has a whole rule of precedence of operators, the examples of the implementations passed here use the unfortunate notation, feel free to implement your version using another notation.
## Algorithm complexity

It is interesting to note, that this algorithm is executed in linear time, since each number or operator is added or removed from the stack only once (this is if you are using stacks to keep the operands and operators)

#### Time complexity

`` O (n) ``

#### Space complexity

`` O (n) ``

## Step by step

### Until the end of the expression, obtain a character and perform only one of the steps (a) to (e):

``(a) If this is the operand, push it onto the stack of operands.``

``(b) If this is an operator and the operator stack is empty, push it into the operator stack.``

``(c) If this is an operator and the operator's stack is not empty, and the character's precedence is greater than that of the top operator of the stack, push the character to the operator's stack.``

``(d) If "("), push it towards the battery operator.``

``(e) If ")", until "(" is found, do the following:``

``1) dispose of the battery by operating it once (value1)``

``2) dispose of the operator's battery once (operator)``

``3) dispose of the battery by operating again (value2)``

``4) calculate value1 operator value2``

``5) push the value obtained in the battery in operation.``

``6) dispose of the operator's battery to ignore the "("
When there are no more input characters, continue processing the steps in (e), until the stack operator is empty. The value left in the stack of operands is the final result of the expression.``

### Let's consider the expression (5 + 3) * 6.
``1) "(" is sent (=>) to the operator's stack``

``2) 5 => battery in operation``

``3) + => battery operator``

``4) 3 => battery in operation``

``5) ")" was found. The operator and the main operands are removed from the stack, resulting in 5 + 3 being evaluated and pushed into the stack of operands. Now, we have 8 in the stack operator.``

``6) * => battery operator``

``7) 6 => battery in operation``

``8) The operator and the main operands are removed from the stack, resulting in 8 * 6 being evaluated and resulting in 48. This is the final value, as the operator's stack is empty.``

End :).
