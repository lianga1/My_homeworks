# coding = utf-8
#  代码文件: dev_env/py/流程控制/循环语句while1.py

i = 0

while i * i < 10:
    i += 1
    if i == 3:
        break
    print(str(i)+ ' * ' + str(i) + ' = ', i * i)
print('while Over')