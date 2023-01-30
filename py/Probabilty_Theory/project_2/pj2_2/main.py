'''
description:
    The purpose of this program is to divide the fetal weight data in a table into training and test sets, and to perform linear regression fitting of fetal weight using the training set parameters
    the weight of baby is ABW
'''

# Import the necessary packages
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
import statsmodels.formula.api as smf
# Read the data from the excel file

# Path: baby.xlsx

# Read the data from the excel file
data = pd.read_excel('baby.xlsx')

train, test = train_test_split(data, test_size=0.2, random_state=0)
#多元回归分析

mod = smf.ols(formula='ABW~BPD+HC+AC+FL',data=train)
res = mod.fit()
print(res.summary())

#对测试集进行预测
y_pred = res.predict(test)
#计算均方误差
print(mean_squared_error(test['ABW'],y_pred))


