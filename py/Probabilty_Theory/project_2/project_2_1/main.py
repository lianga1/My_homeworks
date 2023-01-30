#description: This file is to read a dataset in excel and draw a histogram and a boxplot
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

#read the dataset
df = pd.read_excel('baby.xlsx', sheet_name='Sheet1')
#read column 1 from the second row
print(df)
data = df.iloc[1:,0]

#draw a histogram
plt.hist(data, bins=20, color='blue', edgecolor='black', alpha=0.5)
plt.title('Histogram')
plt.xlabel('Weight')
plt.ylabel('Frequency')
plt.savefig('histogram.png')
plt.show()

plt.boxplot(data,vert=False)
plt.title('Boxplot')
plt.savefig('boxplot.png')
plt.show()
