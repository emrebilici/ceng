#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt

# example data
loss_5 = [101.38071608543396,101.9100329875946,100.5304343700409,101.78037762641907,101.51954817771912,100.5234215259552]
loss_15 = [114.44809699058533,113.09195613861084,113.50142574310303,114.23340010643005,113.2140417098999,112.98606657981873]
loss_38 = [626.7469394207001,636.3781440258026,637.2863771915436,661.115889787674,646.7308175563812,644.4073181152344]

lossValues = [5,15,38]


line,caps,bars=plt.errorbar(
    [5,15,38],  # X
    [101.2740884621938,113.57916454474132,642.110914349556], # Y
    yerr=[0.4865771664968029,0.494754498538884,9.331456924037857],     # Y-errors
    label="Transfer Time",
    fmt="rs--",    # format line like for plot()
    linewidth=2,   # width of plot line
    elinewidth=0.5,# width of error bar line
    ecolor='k',    # color of error bar
    capsize=5,     # cap length for error bar
    capthick=0.5   # cap thickness for error bar
    )
plt.title("Transfer Time vs Loss Percentage")
plt.legend(numpoints=1,             #Set the number of markers in label
           loc=('upper left'))      #Set label location
plt.xlim((2,40))                 #Set X-axis limits
plt.xticks([5,15,38])               #get only ticks we want
plt.xlabel("Loss Percentage")
plt.ylabel("Transfer Time(seconds)")
plt.show()