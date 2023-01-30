# coding = utf-8
# 代码文件：dev_env\py\序列\字典\遍历字典.py

a = {1:'张三', 2:'李四', 3:'王五'}
for b in a.keys():
    print("键值" + str(b))
for c in a.values():
    print("值" + str(c))
for d , e in a.items():
    print('学号:{0} - 学生:{1}'.format(d,e))