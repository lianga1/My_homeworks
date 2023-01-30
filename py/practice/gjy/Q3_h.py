#description: Write a "while" loop to calculate , as a list , the first ten digits after the points of 0.8191 in binary.Assign this list to the variable int_digits
#Q3_h
int_digits = []
a=0.8191
while a >0 and len(int_digits)<10:
    a=a*2# multiply a by 2
    int_digits.append(int(a))# append the integer part of a to int_digits
    a = a % 1 # assign the fractional part of a to a
print(int_digits)