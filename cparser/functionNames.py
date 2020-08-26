import subprocess


def get_line_number(filename, valmapLocations):
    cmd = "ctags -x " + filename + " | sort -n -k2"

    output = subprocess.getoutput(cmd)
    lines = output.splitlines()

    function = []
    lineNumbers = []
    valmapFuncLine = []

    for line in lines:
        function.append(line.split()[0])
        lineNumbers.append(int(line.split()[1]))

    #lineNumbers.append(99999)

    loop = 0

    for valLine in valmapLocations:
        for fileLine in lineNumbers:
            loop += 1
            if valLine < fileLine:
                #valmapFuncLine.append(fileLine)
                print(str(valLine) + " : " + str(fileLine) + " : " + function[(lineNumbers.index(fileLine)) - 1])
                break

    print('****** new logic ******* : ' + str(loop))
    loop = 0

    for valLine in valmapLocations:
        for fileLine in lineNumbers[::-1]:
            loop += 1
            if valLine > fileLine:
                valmapFuncLine.append(function[(lineNumbers.index(fileLine))])
                #print(str(valLine) + " : " + str(fileLine) + " : " + function[(lineNumbers.index(fileLine))])
                break

    print(loop)

    print(function)
    print(lineNumbers)
    print(valmapLocations)
    print(valmapFuncLine)
    return True


def getFunctionNames(fileName, lineLocation):
    return True


get_line_number('src.cxx', [44, 34, 24, 10, 17, 39, 29, 49])
