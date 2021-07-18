c0 = int(input("digite um numero: "))
steps = 0

while c0 <= 0:
    c0 = int(input("digite um numero: "))

while c0 != 1:
    if c0 % 2 == 0:
        c0 = int(c0 / 2)
    else:
        c0 = int(3 * c0 + 1)
    
    print(c0)
    
    steps = steps + 1

print("steps =", steps)

