def evaluer(expression: list) -> float:
    if not isinstance(expression, list) or len(expression) != 3:
        return None
    operand1, operator, operand2 = expression
    def eval_operand(operand):
        if isinstance(operand, (int, float)):
            return operand
        elif isinstance(operand, list):
            return evaluer(operand)
        else:
            return None
    operand1 = eval_operand(operand1)
    operand2 = eval_operand(operand2)
    if operand1 is None or operand2 is None:
        return None
    
    if operator == '+':
        return operand1 + operand2
    elif operator == '-':
        return operand1 - operand2
    elif operator == '*':
        return operand1 * operand2
    elif operator == '/':
        if operand2 == 0:
            return None
        return operand1 / operand2
    else:
        return None
