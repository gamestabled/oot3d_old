with open('src/functions.cpp', 'w') as funcsSrc:
    with open('function_addresses.txt', 'r') as funcs:
        Lines = funcs.readlines()
        for i in range(0, len(Lines)):
            funcName = Lines[i].split(',')[0]
            objectName = "binary/" + funcName + ".o"
            funcsSrc.write('#pragma GLOBAL_ASM(\"' + objectName + '\")\n\n')

with open('src/rodata.cpp', 'w') as rodataSrc:
    with open('rodata_chunks.txt', 'r') as rodata:
        Lines = rodata.readlines()
        for i in range(0, len(Lines)):
            rodataName = Lines[i].split(',')[0]
            objectName = "binary/" + rodataName + ".o"
            rodataSrc.write('#pragma GLOBAL_ASM(\"' + objectName + '\")\n\n')

with open('src/data.cpp', 'w') as dataSrc:
    with open('data_chunks.txt', 'r') as data:
        Lines = data.readlines()
        for i in range(0, len(Lines)):
            dataName = Lines[i].split(',')[0]
            objectName = "binary/" + dataName + ".o"
            dataSrc.write('#pragma GLOBAL_ASM(\"' + objectName + '\")\n\n')