# coding = utf-8
# 代码文件: dev_env/py/序列/列表/改变元素.py

# 追加单个元素时，用append(x)方法
# 追加多个元素时，用（+）运算符或extend（t）方法
# 插入元素时，用list.insert(i,x),其中i为位置，x为元素
# 替换元素时，在list[x]进行赋值
# 删除元素时，用list.remove(x)方法，若找到多个匹配的元素，只删除第一个
a = [1,2,3,4,5]
a.append(6)
print(a)


b = [12,34]
c = [45,65]
b.extend(c)
print(b)
b += a
print(b)


a.insert(5,0)
print(a)

a[1] = 9
print(a)

b.remove(34)
print(b)
