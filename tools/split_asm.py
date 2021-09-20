# convert exefs to elf
import sys
import os
import struct

CC = "$DEVKITARM/bin/arm-none-eabi-gcc"
CP = "$DEVKITARM/bin/arm-none-eabi-g++"
OC = "$DEVKITARM/bin/arm-none-eabi-objcopy"
OD = "$DEVKITARM/bin/arm-none-eabi-objdump"
LD = "$DEVKITARM/bin/arm-none-eabi-ld"
	
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
    b.seek(0, os.SEEK_END)
    textSize = b.tell()
    b.seek(0)
    # linkerscript = ''
    # linkerscript += 'OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")\n'
    # linkerscript += 'OUTPUT_ARCH(arm)\n'
    # linkerscript += 'SECTIONS\n'
    # linkerscript += '{\n'
    # linkerscript += '\t. = 0x100000;\n'
    # linkerscript += '\t.text : {\n'
    with open('function_addresses.txt') as funcs:
        Lines = funcs.readlines()
        for i in range(0, len(Lines)):
            funcName = Lines[i].split(',')[0]
            funcStart = int(Lines[i].split(',')[1].strip(), 16) - 0x100000
            funcEnd = int(Lines[i].split(',')[2].strip(), 16) - 0x100000
            funcSize = funcEnd - funcStart
            b.seek(funcStart)
            funcBin = b.read(funcSize)
            writefile(BINARYDIR + funcName + '.bin', funcBin)
            run('{0} -I binary -O elf32-littlearm --rename-section .data="i.{1}" --redefine-sym _binary_binary_{1}_bin_start={1} --globalize-symbol={1} "{2}{3}.bin" "{2}{3}.o"'.format(OC, funcName, BINARYDIR, funcName))
            run('{0} -D "{1}{2}.o" > "{3}{2}.s"'.format(OD, BINARYDIR, funcName, ASMDIR))
            # linkerscript += '\t\t*({0})\n'.format('ASM_' + funcName)
    # linkerscript += '\t}\n'
    # linkerscript += '}\n'
    # with open('oot.ld', 'w') as l:
        # l.write(linkerscript)

with open(WORKDIR + 'ro.bin', 'rb') as b:
    with open('rodata_chunks.txt') as rodata:
        Lines = rodata.readlines()
        for i in range(0, len(Lines)):
            chunkName = Lines[i].split(',')[0]
            chunkStart = int(Lines[i].split(',')[1].strip(), 16) - 0x4CA000
            chunkEnd = int(Lines[i].split(',')[2].strip(), 16) - 0x4CA000
            chunkSize = chunkEnd - chunkStart
            b.seek(chunkStart)
            chunkBin = b.read(chunkSize)
            writefile(BINARYDIR + chunkName + '.bin', chunkBin)
            run('{0} -I binary -O elf32-littlearm --rename-section .data="ASM_{1}",alloc,load,readonly,data,contents --redefine-sym _binary_binary_{1}_bin_start={1} "{2}{3}.bin" "{2}{3}.o"'.format(OC, chunkName, BINARYDIR, chunkName))

with open(WORKDIR + 'rw.bin', 'rb') as b:
    with open('data_chunks.txt') as rodata:
        Lines = rodata.readlines()
        for i in range(0, len(Lines)):
            chunkName = Lines[i].split(',')[0]
            chunkStart = int(Lines[i].split(',')[1].strip(), 16) - 0x4F9000
            chunkEnd = int(Lines[i].split(',')[2].strip(), 16) - 0x4F9000
            chunkSize = chunkEnd - chunkStart
            b.seek(chunkStart)
            chunkBin = b.read(chunkSize)
            writefile(BINARYDIR + chunkName + '.bin', chunkBin)
            run('{0} -I binary -O elf32-littlearm --rename-section .data="ASM_{1}",alloc,load,data,contents --redefine-sym _binary_binary_{1}_bin_start={1} "{2}{3}.bin" "{2}{3}.o"'.format(OC, chunkName, BINARYDIR, chunkName))
