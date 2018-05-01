import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = pd.read_csv("heap.csv",header = None,names = [0,1])

data.head()

data.sort_values(by = [0] , inplace = True)

log = np.log2(data[0])
nlog= data[0]*log


plt.plot(data[0], data[1], '-r', label = "comp")
plt.plot(data[0],nlog, '-b', label = "nlogn")
plt.plot(data[0],data[0], '-g', label = "n")
plt.legend()

plt.show()
