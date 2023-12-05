import re
import math
inputList = list()
output = 0
with open("input/inputday4.txt") as f:
    inputList = f.readlines()
for lines in inputList:
    lines = re.sub(r"^.*?:", "", lines)
    temp = lines.split("|")
    list1 = [int(num) for num in temp[0].split()]
    list2 = [int(num) for num in temp[1].split()]
    c = sum(el in list1 for el in list2)
    if (c != 0):
        output += math.pow(2, c-1)
print(int(output))
