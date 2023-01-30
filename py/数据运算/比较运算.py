# coding = utf-8
# 文件位置: dev_env/py/数据运算/比较运算.py

a = 2
b = 3.0
print(a == b)
print(a != b)
print(a >= b)
print(a <= b)
print(a > b)
print(a < b)
#整式、浮点、布尔三者兼容

#其它类型的数据比较
a = 'Hello'
b = 'Hello'
print(a == b)
a = 'World'
print(a > b)
#字符串比较：逐字符比较Unicode编码，本实例因W>H，故a>b
a = [4]
b = [2,1,3]
print(a > b)
#列表间可以相互比较，最大值相互比较
a = ['2']
print(a > b)
#列表中不同类型的元素不能相互比较