import math
import statistics

counter = 0
values = []
with open("./40/difference_times.txt","r") as diffFile :
	differenceString = diffFile.readline()
	while differenceString:
		counter+=1
		difference = float(differenceString)
		values.append(difference)
		differenceString = diffFile.readline()

mean = statistics.mean(values)
std = statistics.stdev(values)
print("Mean is : ", 1000 * mean)
print("Std is : ", 1000 * std)
confidence_interval = 1.96 * std/math.sqrt(counter)
print("Confidence inteval is :",1000 * confidence_interval)
