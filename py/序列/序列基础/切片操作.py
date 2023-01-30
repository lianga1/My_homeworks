# coding = utf-8
# 代码文件：dev_env/py/序列/序列基础/切片操作.py

#语法：[start: end: step],start是开始索引，end是结束索引，step是步长

a = 'hello' 
print(a[0: 5:])
print(a[:3])
print(a[::-1])# 步长为负值时，从右向左索引
print(a[1: 3: 2])