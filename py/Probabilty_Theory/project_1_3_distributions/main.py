import numpy as np
import matplotlib.pyplot as plt

def poisson_distribution(lam, k):
    return (lam**k * np.exp(-lam)) / np.math.factorial(k)

evens = np.random.random(1000)
binary = np.random.randint(0, 2, 1000)
poisson = np.random.poisson(5, 1000)
normal = np.random.normal(0, 1, 1000)

plt.xlabel('x')
plt.ylabel('y')
# plt.title('Scatter Plot')
# savefig('scatter.png')
# plt.show()
# get the Expectation of the random variables


print("The expectation of the random variable evens is: ", evens.mean())
print("The expectation of the random variable binary is: ", binary.mean())
print("The expectation of the random variable poisson is: ", poisson.mean())
print("The expectation of the random variable normal is: ", normal.mean())

print("\n")
# get the medium of the random variables
print("The medium of the random variable evens is: ", np.median(evens))
print("The medium of the random variable binary is: ", np.median(binary))
print("The medium of the random variable poisson is: ", np.median(poisson))
print("The medium of the random variable normal is: ", np.median(normal))

#get the Varience of the random variables
print("\n")
print("The varience of the random variable evens is: ", np.var(evens))
print("The varience of the random variable binary is: ", np.var(binary))
print("The varience of the random variable poisson is: ", np.var(poisson))
print("The varience of the random variable normal is: ", np.var(normal))

# draw the histogram of the random variables
plt.hist(evens, bins=20)
x=np.arange(0, 1, 0.01)
y=50*np.ones(100)
plt.plot(x,y,linestyle='--', color='r')
plt.title("Histogram of evens")
plt.savefig('evens.png')
plt.show()

plt.hist(binary, bins=3)
x=np.arange(0, 1, 0.01)
y=500*np.ones(100)
plt.plot(x,y,linestyle='--', color='r')
plt.title("Histogram of binary")
plt.savefig('binary.png')
plt.show()

plt.hist(poisson, bins=100)
x = np.arange(0, 12, 0.01)
ylist = []
for i in range(12):
    y=poisson_distribution(5, i)*1000
    for j in range(100):
        ylist=np.append(ylist,y)

plt.plot(x,ylist,linestyle='--', color='r')
plt.title("Histogram of poisson")
plt.savefig('poisson.png')
plt.show()

x = np.arange(-3,3, 0.01)
plt.hist(normal, bins=100)
ylist = []
for i in range(100):
    y=1/np.sqrt(2*np.pi)*np.exp(-x**2/2)*80
    ylist=np.append(ylist,y)

plt.plot(x,y,linestyle='--', color='r')

plt.title("Histogram of normal")
plt.savefig('normal.png')
plt.show()