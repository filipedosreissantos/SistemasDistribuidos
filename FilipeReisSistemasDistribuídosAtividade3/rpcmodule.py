'''Simple calculator with the four basic operations'''

def add( num1, num2 ):
    return num1 + num2

def sub( num1, num2 ):
    return num1 - num2

def mul( num1, num2 ):
    return num1 * num2

def div( num1, num2 ):
    try:
        return num1 / num2
    except:
        print("There is no possibility of divisison by zero.")
