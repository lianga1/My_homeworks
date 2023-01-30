# coding = utf-8
# 代码文件： dev_env/py/序列/字典/查询与修改字典.py

dict1 = {1 : 'a' , 2 : 'b' , 3 : 'c'}
print(dict1[1])
dict1[4] = 'd'
print(dict1)
dict1[1] = 'e'
print(dict1)
#删除键值对用pop方法
dict1.pop(3)
print(dict1)