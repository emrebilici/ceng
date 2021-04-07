import math
import glob
import sys


class AminoAcid:
    def __init__(self, name, locationX, locationY, locationZ, resSeqNo, chainID, order):
        self.name = name
        self.locationX = locationX
        self.locationY = locationY
        self.locationZ = locationZ
        self.resSeqNo = resSeqNo
        self.chainID = chainID
        self.order = order

    def findDistance(self, AA):
        if self.chainID != AA.chainID:
            n = (self.locationX - AA.locationX)**2 + (self.locationY - AA.locationY)**2 + (self.locationZ - AA.locationZ)**2
            distance = math.sqrt(n)
            return distance
            #print(distance)

    def __repr__(self):
        return self.name+"("+str(self.order)+")"


class Pair:
    def __init__(self, aa1, aa2):
        self.aa1 = aa1
        self.aa2 = aa2
        self.group = None

    def findDistance(self, p):
        n = (self.aa1.locationX - p.aa1.locationX) ** 2 + (self.aa1.locationY - p.aa1.locationY) ** 2 + (self.aa1.locationZ - p.aa1.locationZ) ** 2
        btwA1A2 = math.sqrt(n)
        n = (self.aa1.locationX - p.aa2.locationX) ** 2 + (self.aa1.locationY - p.aa2.locationY) ** 2 + (self.aa1.locationZ - p.aa2.locationZ) ** 2
        btwA1B2 = math.sqrt(n)
        n = (self.aa2.locationX - p.aa2.locationX) ** 2 + (self.aa2.locationY - p.aa2.locationY) ** 2 + (self.aa2.locationZ - p.aa2.locationZ) ** 2
        btwB1B2 = math.sqrt(n)
        n = (self.aa2.locationX - p.aa1.locationX) ** 2 + (self.aa2.locationY - p.aa1.locationY) ** 2 + (self.aa2.locationZ - p.aa1.locationZ) ** 2
        btwA2B1 = math.sqrt(n)
        if (btwA1A2 < 8) or (btwA1B2 < 8) or (btwA2B1 < 8) or (btwB1B2 < 8):
            return True
        else:
            return False
        #print(distance)

    def __repr__(self):
        return str(self.aa1) + "-" + str(self.aa2)


def parsePdb(name, aaList):
    f = open(name, "r")
    terFlag = False
    order = 1
    preSeqNo = ""
    atomName = ""
    resName = ""
    locationX = 0
    locationY = 0
    locationZ = 0
    chainID = ""
    count = 0
    for line in f:
        if line[:6] == "ATOM  ":
            count += 1
            if terFlag:
                terFlag = False
                order = 1
                count = 1
                # aaList.append(chain)
            # print(line)
            if count == 1:
                chain = []
                preSeqNo = line[22:26]
                atomName = line[12:16].strip()
                resName = line[17:20]
                #print(atomName)
                if (atomName == "CB" and resName != "GLY") or (resName == "GLY" and atomName == "CA"):
                    locationX = float(line[30:38].strip())
                    locationY = float(line[38:46].strip())
                    locationZ = float(line[46:54].strip())
                    chainID = line[21]
                    aa = AminoAcid(resName, locationX, locationY, locationZ, line[22:26], chainID, order)
                    #print(aa)
                    chain.append(aa)
                # print(atomName, resName, locationX, locationY, locationZ, line[22:26], chainID)
            else:
                if not line[22:26] == preSeqNo:
                    preSeqNo = line[22:26]
                    order += 1
                    resName = line[17:20]
                atomName = line[12:16].strip()
                #print(atomName)
                if (atomName == "CB" and resName != "GLY") or (resName == "GLY" and atomName == "CA") :
                    locationX = float(line[30:38].strip())
                    locationY = float(line[38:46].strip())
                    locationZ = float(line[46:54].strip())
                    chainID = line[21]
                    # chaindId burada gereksiz
                    aa = AminoAcid(resName, locationX, locationY, locationZ, line[22:26], chainID, order)
                    #print(aa)
                    chain.append(aa)
        elif line[:6] == "TER   ":
            aaList.append(chain)
            terFlag = True
        elif terFlag:
            break

    f.close()


def makePair(aaList, pairList):
    visited = [0,0,0]
    i = 0
    for chain in aaList:
        visited[i] = 1
        for aa in chain:
            k = 0
            for oppositeChain in aaList:
                if visited[k] != 1:
                    for aa2 in oppositeChain:
                        dist = aa.findDistance(aa2)
                        if dist < 8:
                            pairList.append(Pair(aa, aa2))
                            #print(aa, dist, aa2)

                k += 1
        i += 1


def makeGroup(pairList, groupList):
    counter1 = 0
    for pair in pairList:
        group = []
        # if pair has a group take that group and append
        # if not then append group according to difpair
        # difpair firstly has no group
        if pair.group is not None:
            group = groupList[pair.group]
        else:
            pair.group = counter1
            group.append(pair)
        counter2 = 0
        for difPair in pairList:
            if counter2 <= counter1:
                pass
            else:
                if pair.findDistance(difPair):
                    if difPair not in group:
                        # check the difpair has a group?
                        # according to that group change the pair's group.
                        if difPair.group != None:
                            for p in group:
                                p.group = difPair.group
                            groupList[difPair.group] += group
                            group = groupList[difPair.group]
                        else:
                            group.append(difPair)
                            difPair.group = pair.group
            counter2 += 1

        if pair.group != counter1:
            groupList.append([])
        else:
            groupList.append(group)

        counter1 += 1

    retGroup = list(filter(lambda x: len(x) != 0, groupList))
    return retGroup


def printInfo(groups, pairNo):
    print("There are {0} interacting pairs.\n".format(pairNo))
    count = 1
    for g in groups:
        for p in g:
            print("Group {0}: {1}\n".format(count, p))
        count += 1
    print("Number of groups = {0}".format(len(groups)))


def printToFile(fileName, groups, pairNo):
    file1 = open("report.txt", "a")
    file1.write("This is result of {0}:\n\n".format(fileName))
    file1.write("There are {0} interacting pairs.\n".format(pairNo))
    count = 1
    for g in groups:
        for p in g:
            file1.write("Group {0}: {1}\n".format(count, p))
        count += 1
    file1.write("Number of groups = {0}\n".format(len(groups)))
    file1.write("\n\n\n")


if __name__ == '__main__':

    aaList = []
    pairList = []
    groupList = []

    pdb = sys.argv[1]
    parsePdb(pdb, aaList)
    makePair(aaList, pairList)
    ret = makeGroup(pairList, groupList)
    printInfo(ret, len(pairList))
    # printToFile(pdb, ret, len(pairList))

# It takes command line argument.
# But you can comment out 203rd line and directly give name of file in parsePdb()
# I used printToFile function while reporting. with
# pdbFiles = [f for f in glob.glob("*.pdb")]
# for pdb in pdbFiles:
#    printToFile(pdb, ret, len(pairList))
