# convert exefs to elf
import sys
import os
import shlex
from subprocess import run

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

            run([OC, '-I', 'binary', '-O', 'elf32-littlearm', '--rename-section', f'.data="i.{funcName}"',
                 '--redefine-sym', f'_binary_binary_{funcName}_bin_start={funcName}',
                 f'--globalize-symbol={funcName}', f'{BINARYDIR}{funcName}.bin', f'{BINARYDIR}{funcName}.o'])
            with open(f'{ASMDIR}{funcName}.s', 'w') as asmfile:
                run([OD, '-D', f'{BINARYDIR}{funcName}.o'], stdout=asmfile)

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
            run([OC, '-I', 'binary', '-O', 'elf32-littlearm', '--rename-section', f'.data="ASM_{chunkName}",alloc,load,readonly,data,contents',
                 '--redefine-sym', f'_binary_binary_{chunkName}_bin_start={chunkName}', f'{BINARYDIR}{chunkName}.bin', f'{BINARYDIR}{chunkName}.o'])

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
            run([OC, '-I', 'binary', '-O', 'elf32-littlearm', '--rename-section', f'.data="ASM_{chunkName}",alloc,load,data,contents',
                 '--redefine-sym', f'_binary_binary_{chunkName}_bin_start={chunkName}', f'{BINARYDIR}{chunkName}.bin', f'{BINARYDIR}{chunkName}.o'])
