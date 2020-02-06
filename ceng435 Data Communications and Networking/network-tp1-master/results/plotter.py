import math
import statistics
import matplotlib.pyplot as plt

emulation_delays = [20,40,50]
values_20 = []
values_40 = []
values_50 = []

with open("./20/difference_times.txt","r") as diffFile :
	differenceString = diffFile.readline()
	while differenceString:
		difference = float(differenceString)*1000
		values_20.append(difference)
		differenceString = diffFile.readline()

with open("./40/difference_times.txt","r") as diffFile :
	differenceString = diffFile.readline()
	while differenceString:
		difference = float(differenceString)*1000
		values_40.append(difference)
		differenceString = diffFile.readline()

with open("./50/difference_times.txt","r") as diffFile :
	differenceString = diffFile.readline()
	while differenceString:
		difference = float(differenceString)*1000
		values_50.append(difference)
		differenceString = diffFile.readline()
plot_dic = {}
plot_dic[20] = values_20
plot_dic[40] = values_40
plot_dic[50] = values_50


fig, ax = plt.subplots()
ax.boxplot(plot_dic.values(),notch=True)
ax.set_xticklabels(plot_dic.keys())

plt.title('Emulation Delay vs End-to-end Delay')
plt.ylabel('End-to-end Delay(ms)')
plt.xlabel('Emulation Delay(ms)')

plt.show()