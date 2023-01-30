import json
import requests
import matplotlib.pyplot as plt
import numpy as np
from matplotlib import ticker

plt.rc('font', family='SimHei')  # 设置字体为黑体
plt.rc('axes', unicode_minus=False)  # 解决坐标轴负号显示问题

# 从腾讯获取数据
url = 'https://api.inews.qq.com/newsqa/v1/query/pubished/daily/list?adCode=440100&limit=30'
html = requests.get(url)
html_text = json.loads(html.text)
data = html_text['data']
# print(data)
# {
#     "y": "2022",
#     "date": "10.24",
#     "city": "广州",
#     "confirm": 1389,
#     "dead": 0,
#     "heal": 0,
#     "suspect": 0,
#     "adcode": "440100",
#     "confirm_add": "22",
#     "yes_confirm_add": 22,
#     "today_confirm_add": 0,
#     "yes_wzz_add": 43,
#     "today_wzz_add": 0,
#     "is_show_wzz_add": 1
# }
date = []  # 日期
confirm_add = []  # 新增确诊
wzz_add = []  # 无症状
for item in data:
    date.append(item['date'])
    confirm_add.append(item['yes_confirm_add'])
    wzz_add.append(item['yes_wzz_add'])

# data process
plt.figure(figsize=(20, 10))
plt.title("广州市每日新增确诊")
plt.xlabel("日期")
plt.ylabel("人数")

# 标注说明
x = date
y1 = confirm_add
y2 = wzz_add

plt.bar(x, y1, facecolor='red', label='每日新增确诊')
# plt.bar(x, y1, facecolor='red', label='每日新增确诊')

# 设置横坐标显示间隔
plt.gca().xaxis.set_major_locator(ticker.MultipleLocator(5))

# 在柱形图上显示数据
for x, y in zip(x, y1):
    # plt.text(x,y+1,y)
    plt.text(x, y + 2, y, ha='center')

plt.legend()
plt.show()
