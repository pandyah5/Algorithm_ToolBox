def fibonacci(num):
    if (num <= 2):
        return 1
    if (num < 1):
        return 0
    num1, num2, num = 1, 1, num - 2
    while(num):
        num2, num1 = num1, num1 + num2
        num -= 1
    return num1

## Testing the code
for i in range(1, 11):
    print(fibonacci(i))
