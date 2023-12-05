import re
import math
inputList = list()

with open("input/debuginput.txt") as f:
    inputList = f.readlines()


def partOne(inputList: list[str]) -> int:
    output = 0
    for lines in inputList:
        lines = re.sub(r"^.*?:", "", lines)
        temp = lines.split("|")
        list1 = [int(num) for num in temp[0].split()]
        list2 = [int(num) for num in temp[1].split()]
        c = sum(el in list1 for el in list2)
        if (c != 0):
            output += math.pow(2, c-1)
    return int(output)


def partTwo(inputList: list[str]) -> int:
    output = 0
    copies = dict()
    for i, lines in enumerate(inputList):
        lines = re.sub(r"^.*?:", "", lines)
        temp = lines.split("|")
        list1 = [int(num) for num in temp[0].split()]
        list2 = [int(num) for num in temp[1].split()]
        c = sum(el in list1 for el in list2)

    return output


print(partOne(inputList))
print(partTwo(inputList))
