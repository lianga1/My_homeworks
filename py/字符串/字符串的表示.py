# coding = utf-8
# 代码文件：dev_env\py\字符串\字符串的表示.py

# 字符串分为普通字符串，原始字符串，长字符串

# 普通字符串用单引号或双引号表示，字符串内的引号不需要转义

a = 'hello world'
b = 'hello"world'
c = 'hello/world'
print(a,b,c)

#字符转义：有以下几种特殊字符串表示其他意义

d = 'hello\nworld' #unicode编码为\u000a
e = 'hello\tworld' #\u0009
f = 'hello\rworld' #\u000d
g = 'hello\"world' #\u0022
h = 'hello\'world' #\u0027
i = 'hello\\world' #\u005c

print(d)
print(e)
print(f)
print(g)
print(h)
print(i)

#原始字符串：在普通字符串前加r即可。字符串内特殊字符不转义

j = r'hello\nworld'
print(j)

#长字符串：用三个单引号或双引号括起来，包括换行，缩进等
k = '''
        《早发白帝城》
    朝辞白帝彩云间，千里江陵一日还。
    两岸猿声啼不住，轻舟已过万重山。
'''
print(k)
