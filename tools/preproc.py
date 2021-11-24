import sys
import re

#arg1 = source file
#arg2 = output deps file
with open(sys.argv[1], 'r') as srcFile:
    outdependencies = []
    srcLines = srcFile.readlines()
    for srcLine in srcLines:
        srcLine = srcLine.strip()
        if srcLine.startswith("GLOBAL_ASM("):
            fname = srcLine[srcLine.index('(') + 2 : -2]
            outdependencies.append(fname)
    if len(outdependencies) > 0:
        with open(sys.argv[2], 'w') as depsFile:
            for dep in outdependencies:
                depsFile.write(dep + ' ')
