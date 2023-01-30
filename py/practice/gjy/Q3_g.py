#description: Write a "while" loop to calculate , as a list , the digits of 2213 in binary.Assign this list to the variable int_digits
#Q3_g
int_digits = []

a=2213
while a > 0:
    int_digits.append(a % 2)# append the remainder of a/2 to int_digits
    a = a // 2 # divide a by 2 and assign the value to a

print(int_digits)