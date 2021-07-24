

def isOperator(ch):
    if ch is "+" or ch is "-" or ch is "*" or ch is "/":
        return True
    return False

def checkPrecedence(op1, op2):
    if op1 is "*" or op1 is "/":
        return True
    
    if op1 is "+" or op1 is "-":
        if op2 is "+" or op2 is "-":
            return True
    
    return False

def convert_to_postfix(exp):
    postfix = ""
    operators = []

    n = len(exp)
    i = 0

    while i < n:
        ch = exp[i]
        if isOperator(ch):
            while operators and checkPrecedence(operators[-1], ch):
                postfix+=operators.pop()
            operators.append(ch)
        else :
            postfix+=ch
        i+=1
    
    while len(operators) > 0:
        postfix+=operators.pop()
    
    return postfix

def evaluate_postfix(postfix):
    i = 0
    n = len(postfix)
    num = []

    while i < n:
        ch = postfix[i]
        if isOperator(ch):
            a = float(num.pop())
            b = float(num.pop())
            if ch is "+":
                res = a + b
            elif ch is "-":
                res = b - a
            elif ch is "*":
                res = a*b
            else :
                res = b / a
            num.append(res)
        elif ch is ".":
            x = str(int(num.pop())) + ch + postfix[i+1]
            num.append(float(x))
            i+=1
        else :
            num.append(float(ch))
        i+=1
    
    return num.pop()


def evaluate(exp):
    postfix = convert_to_postfix(exp)
    # print(postfix)
    return evaluate_postfix(postfix)

exp = "3+6*5-1/2.5"
print(evaluate(exp))
# print("evaluate(3+6*5-1/2.5) = " + str(evaluate("3+6*5-1/2.5")))