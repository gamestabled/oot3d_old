# convert exefs to elf
import sys
import os
import struct

if 'DEVKITARM' not in os.environ:
    print('DEVKITARM environment variable is not set!')
    sys.exit(1)

DEVKITARM = os.environ.get('DEVKITARM')

CC = DEVKITARM + "/bin/arm-none-eabi-gcc"
CP = DEVKITARM + "/bin/arm-none-eabi-g++"
OC = DEVKITARM + "/bin/arm-none-eabi-objcopy"
OD = DEVKITARM + "/bin/arm-none-eabi-objdump"
LD = DEVKITARM + "/bin/arm-none-eabi-ld"

BASEROMDIR = 'baserom/'
WORKDIR = BASEROMDIR + 'workdir/'
BINARYDIR = 'binary/'
ASMDIR = 'asm/'

def run(cmd):
    os.system(cmd)

def writefile(path, s):
    with open(path, "wb") as f:
        f.write(s)

with open(WORKDIR + 'text.bin', 'rb') as b:
    with open('function_addresses.txt') as funcs:
        for line in funcs:
            splitLine = line.split(',')
            funcName = splitLine[0]
            funcStart = int(splitLine[1].strip(), 16) - 0x100000
            funcEnd = int(splitLine[2].strip(), 16) - 0x100000
            funcSize = funcEnd - funcStart
            b.seek(funcStart)
            funcBin = b.read(funcSize)
            writefile(BINARYDIR + funcName + '.bin', funcBin)
            run('{0} -I binary -O elf32-littlearm --rename-section .data="i.{1}" --redefine-sym _binary_binary_{1}_bin_start={1} --globalize-symbol={1} "{2}{3}.bin" "{2}{3}.o"'.format(OC, funcName, BINARYDIR, funcName))
            run('{0} -D "{1}{2}.o" > "{3}{2}.s"'.format(OD, BINARYDIR, funcName, ASMDIR))

with open(WORKDIR + 'ro.bin', 'rb') as b:
    with open('rodata_chunks.txt') as rodata:
        for line in rodata:
            splitLine = line.split(',')
            chunkName = splitLine[0]
            chunkStart = int(splitLine[1].strip(), 16) - 0x4CA000
            chunkEnd = int(splitLine[2].strip(), 16) - 0x4CA000
            chunkSize = chunkEnd - chunkStart
            b.seek(chunkStart)
            chunkBin = b.read(chunkSize)
            writefile(BINARYDIR + chunkName + '.bin', chunkBin)
            run('{0} -I binary -O elf32-littlearm --rename-section .data="ASM_{1}",alloc,load,readonly,data,contents --redefine-sym _binary_binary_{1}_bin_start={1} "{2}{3}.bin" "{2}{3}.o"'.format(OC, chunkName, BINARYDIR, chunkName))

with open(WORKDIR + 'rw.bin', 'rb') as b:
    with open('data_chunks.txt') as data:
        for line in data:
            splitLine = line.split(',')
            chunkName = splitLine[0]
            chunkStart = int(splitLine[1].strip(), 16) - 0x4F9000
            chunkEnd = int(splitLine[2].strip(), 16) - 0x4F9000
            chunkSize = chunkEnd - chunkStart
            b.seek(chunkStart)
            chunkBin = b.read(chunkSize)
            writefile(BINARYDIR + chunkName + '.bin', chunkBin)
            run('{0} -I binary -O elf32-littlearm --rename-section .data="ASM_{1}",alloc,load,data,contents --redefine-sym _binary_binary_{1}_bin_start={1} "{2}{3}.bin" "{2}{3}.o"'.format(OC, chunkName, BINARYDIR, chunkName))
