# coding = utf-8
# 文件位置：dev_env/py/数据运算/运算优先级.py
a = 1
b = 4
c = 6
d1 = (a + b) ** c
print(d1) # 小括号优先级最高，幂运算其次
d2 = ~b ** c
print(d2) # 位反运算位于幂运算后
d3 = - ~ b
print(d3) # 正负号位于位反运算后
d4 = - c // b 
print(d4) # 乘、除、取余、地板除，位于正负号之后
d5 = a + b * c
print(d5) # 加减位于乘除后
d6 = a + c << b
print(d6) # 位移位于加减后
d7 = a << b & c
print(d7) # 位与位于位移后
d8 = a & b ^ c 
print(d8) # 位异或位于位与后
d9 = a ^ b | c
print(d9) # 位或位于位异或后
print(a | b > c) # 比大小位于位或后
print(not a == b) # 逻辑非位于比大小后
print(not a == b or a >=c) # 逻辑与或位于逻辑非后

