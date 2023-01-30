# coding = utf-8
# 代码文件: dev_env/py/流程控制/水仙花数1.py

a = 1
b = 0
c = 0
d = 100 #初始化赋值
while d < 1000:
    d = 100 * a + 10 * b + c # 在循环中定义d的变化
    if d == a ** 3 + b ** 3 + c ** 3: # 水仙花数
        print(d)
    if c < 9: #以下部分为逐次循环d+1的过程，考虑到三位数进位
        c += 1
    else:
        c = 0
        if b < 9:
            b += 1
        else:
            b = 0
            if a < 9:
                a += 1
            else:
                break