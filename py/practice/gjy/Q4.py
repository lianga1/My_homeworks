# fina pythagorean triples

import math

def pytriple (total):
    for a in range(1, total):
        for b in range(a, total-a):
            c = math.sqrt(a**2 + b**2)
            if c == int(c) and a+b+c == total:
                return a*b*c
    return 'No pythagorean triple satisies that total'

print(pytriple(7))