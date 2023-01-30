import numpy as np
import matplotlib.pyplot as plt

def normal_dist(x, mu=0, sigma=1):
    left = 1 / (sigma * np.sqrt(2 * np.pi))
    right = np.exp(-((x - mu) ** 2) / (2 * sigma ** 2))
    return left * right


evensum = []
for i in range(1000):
    evensum.append(np.sum(np.random.random(100)))

print(np.var(evensum))
es=np.array(evensum)
plt.hist(es, bins=20, density=True)
# plt.show()
# normal distribution
x = np.arange(-8, 8, 0.01)
y=normal_dist(x, mu=0, sigma=2.9)
x+=50
plt.plot(x,y,linestyle='--', color='r')
plt.ylim(0,0.2)
plt.savefig('central_limit.png')
plt.show()