# 用蒙特卡洛方法计算生日问题
# 确定n个人中至少两个人生日相同的概率
# 要求多次实验与理论值比较

import random
import numpy as np

total = 100
same_count = 0
result = np.empty(100)

covered=set()
for k in range (100):
    for i in range(total):
        covered.clear()
        for j in range(50):
            covered.add(random.randint(1, 365))
        if len(covered) < 50:
            same_count += 1
    result[k] = same_count / total
    same_count = 0

print(result.mean())




###结果：
# 100人为11
# 1000人为659
# 10000人为9635