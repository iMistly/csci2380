#I forgot how to use python
import math

something = 5
something += 1
print(something)
print()

for i in range(5):
    print(i)

def odd_even(x):
    y = x%2
    if y == 1:
        return "number is odd"
    else:
        return "number is even"

print(odd_even(something))

deci = int(input("Enter a decimal number: "))
print("Converting to hexidecimal...\n")
answer = ""
while(1):
    if deci%16 >= 10:
        answer += str(chr(int(deci%16+65-10)))
    elif deci%16 > 0:
        answer += str(deci%16)
    elif deci%16 == 0 and deci > 0:
        answer += str(0)
    else:
        break
    deci = math.floor(deci/16)
    
answer = answer[::-1]
print(answer)
# print(str(chr(65+deci%16-10)))