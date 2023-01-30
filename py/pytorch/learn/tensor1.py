from __future__ import print_function
import torch
import numpy as np
x = torch.empty(5, 3)
print(x)

rand_x = torch.rand(5, 3)
print(rand_x)
zero_x=torch.zeros(5,3,dtype=torch.long)
print(zero_x)
tensor_x=torch.tensor([5.5,3])
print(tensor_x)
print("------------------")
# create a tensor based on an existing tensor
x = x.new_ones(5, 3, dtype=torch.double)      # new_* methods take in sizes
print(x)
x = torch.randn_like(x, dtype=torch.float)    # override dtype! 
print(x)                                    # result has the same size
print(x.size())
print("------------------")
# operations
y = torch.rand(5, 3)
result = torch.add(x, y)
print(result)
x.add_(y)
print(x)
print(x+y)
print("------------------")
# indexing
print(x[:, 0])
# resizing
x = torch.randn(4, 4)
y = x.view(16)
z = x.view(-1, 8)  # the size -1 is inferred from other dimensions
print(x.size(), y.size(), z.size())
print(x,y,z)

# transfer to numpy
print("------------------")
a = torch.ones(5)
print(a)
b = a.numpy()
print(b)
#transfer to tensor
print("------------------")
a = np.ones(5)
b = torch.from_numpy(a)
np.add(a, 1, out=a)
print(a)

# transfer to GPU
print("------------------")
if torch.cuda.is_available():
    device = torch.device("cuda")          # a CUDA device object
    y = torch.ones_like(x, device=device)  # directly create a tensor on GPU
    x = x.to(device)                       # or just use strings ``.to("cuda")``
    z = x + y
    print(z)
    print(z.to("cpu", torch.double))       # ``.to`` can also change dtype together!

