import sys
import bz2
import zlib
import math
    

if __name__ == "__main__":
    col = sys.argv[1]
    row = sys.argv[2]
    matrix=[[2 for x in range(int(col))] for x in range(int(row))]
    closestDistances = [[200 for x in range(int(col))] for x in range(int(row))]
    lineNumber = 0;

    for line in sys.stdin:
        # print(str(lineNumber) + "GENERAL")
        if (lineNumber == 0):
            lineNumber+=1
            continue
        splits = line.split()
        xPos = float(splits[0])+20
        yPos = float(splits[1])+30
        curAngle = float(splits[2])
        obsDistance = float(splits[3])/30.48
        if (obsDistance != 0):
            xchangePos = xPos + math.cos(curAngle)*obsDistance
            ychangePos = yPos + math.sin(curAngle)*obsDistance
            if (xchangePos >= 0 and xchangePos < row 
                    and ychangePos >= 0 and ychangePos < col):
                if (obsDistance < closestDistances[int(ychangePos)][int(xchangePos)]):
                    # print "obstacle here"
                    # print xchangePos
                    # print ychangePos
                    # print obsDistance
                    matrix[int(ychangePos)][int(xchangePos)] = 1
                    closestDistances[int(ychangePos)][int(xchangePos)] = obsDistance
        else:
            for i in range(0, 5):
                # print "hi"
                xChangePos = math.cos(curAngle)*i + xPos
                yChangePos = math.sin(curAngle)*i + yPos
                if (xChangePos >= 0 and xChangePos < row 
                    and yChangePos >= 0 and yChangePos < col):
                    if (i < closestDistances[int(yChangePos)][int(xChangePos)]):
                        closestDistances[int(yChangePos)][int(xChangePos)] = i
                        # print "no obs dude"
                        matrix[int(yChangePos)][int(xChangePos)] = 0
        lineNumber+=1

    matrix[int(yPos)][int(xPos)] = 3
    for i in range(0, len(matrix)):
        for x in range(0, len(matrix[0])):
            print matrix[len(matrix)-1-i][x],
        print
    # for i in range(0, len(closestDistances)):
    #     print closestDistances[len(closestDistances)-1-i]


    




                
