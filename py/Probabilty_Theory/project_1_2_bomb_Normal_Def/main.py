from numpy.random import default_rng
import matplotlib.pyplot as plt
from matplotlib.pyplot import plot, savefig

def in_circle(x, y):
    return (x**2)/((120)**2) + y**2/(80)**2 < 1

rng = default_rng()

# Generate 1000 random numbers from a normal distribution

# with mean 0 and standard deviation 60
x = rng.normal(0, 60, 1000)
y = rng.normal(0, 40, 1000)

# for i in range(1000):
#     plt.scatter(x[i], y[i], color='red')



# plt.xlabel('x')
# plt.ylabel('y')
# plt.title('Scatter Plot')
# savefig('scatter.png')
# plt.show()

x_range = 120
y_range = 80
count = 0
for i in range (1000):
    if in_circle(x[i], y[i]):
        count+= 1
print(count/1000)

#result 0.871