import random

total = 1000000
in_circle = 0
for i in range(total):
    x = random.random()  # 0-1
    y = random.random()  # 0-1

    distance = (x**2+y**2)**0.5

    if distance <= 1:
        in_circle += 1

print('PI is ', 4*in_circle/total)
