import csv

tissue1 = [29,28,1,5,4,8,7,30,11,20,12,22,23,24,25,26,27]
tissue2 = [19,18,17,21,3,10,2,15,9,16,13,14,6]

difference = 0

differences = []

with open("hw4data.txt") as tsv:
    for line in csv.reader(tsv, delimiter="\t"):
        tissue1Total = 0
        tissue2Total = 0
        if line[0] == "ID":
            continue
        for s in range(1,len(line)):
            if s in tissue1:
                tissue1Total += float(line[s])
            else:
                tissue2Total += float(line[s])

        difference = tissue1Total - tissue2Total
        differences.append({"id": line[0], "dif": difference})

print(differences)
topTenMax = []
topTenMin = []
for i in range(0, 10):
    topTenMax.append(max(differences, key=lambda x: x['dif']))
    topTenMin.append(min(differences, key=lambda x: x['dif']))
    differences.pop(differences.index(min(differences, key=lambda x: x['dif'])))
    differences.pop(differences.index(max(differences, key=lambda x: x['dif'])))


print(topTenMax)
print(topTenMin)
