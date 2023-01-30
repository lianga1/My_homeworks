# coding = utf-8
# 文件位置 :dev_env/py/数据运算/逻辑运算.py
a = 1
b = 0
def f1():
    print('--进入函数f1--')
    return True
print((a > b) or f1())
print((a < b) or f1())
print((a < b) and f1())
print((a > b) and f1())
# f1函数返回结果为真，所以2、4返回为真