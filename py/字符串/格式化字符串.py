# coding = utf-8
# 代码文件：dev_env\py\字符串\格式化字符串.py

#format方法用于对字符串格式化

i = 32
print('i * i = {}'.format(i*i))

#format格式化可对占位符标注，包括序号和变量名

print('{0} * {0} = {1}'.format(i , i * i))
print('{p1} * {p1} = {p2}'.format(p1 = i , p2 = i * i))

# 格式化控制符,在占位符内，用冒号隔开，无空格，s字符串，d十进制整数，f十进制浮点，g按定点小数转换浮点数，e科学计数法，o八进制，x十六进制

money = 12334.2345
name = 'Tony'
print('{0:s}年龄{1:d}，工资是{2:g}元'.format(name,20,money))