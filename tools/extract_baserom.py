import os
import subprocess

DEVKITARM = os.environ.get('DEVKITARM')

OD = DEVKITARM + "/bin/arm-none-eabi-objdump"

OUTDIR = 'baserom/'
BINDIR = 'binary/'
ASMDIR = 'asm/'

TOOLS = 'tools/'
CTRTOOL = TOOLS + 'ctrtool'

# subprocess.run(['mkdir', '-p', OUTDIR])
os.makedirs(OUTDIR, exist_ok = True)

print("extracting exefs...")
subprocess.run([CTRTOOL, '--exefsdir=' + OUTDIR + 'exefs', "baserom.3ds"], stdout=subprocess.DEVNULL)

print("extracting exheader...")
subprocess.run([CTRTOOL, '--exheader=' + OUTDIR + 'exheader.bin', "baserom.3ds"], stdout=subprocess.DEVNULL)

print("extracting romfs...")
subprocess.run([CTRTOOL, '--romfsdir=' + OUTDIR + 'romfs', "baserom.3ds"], stdout=subprocess.DEVNULL)

print("extacting plainrgn...")
subprocess.run([CTRTOOL, '--plainrgn=' + OUTDIR + 'plainrgn.bin', "baserom.3ds"], stdout=subprocess.DEVNULL)

# print("creating baserom.rsf...")
# ########

print("creating baserom.elf...")
# subprocess.run(['mkdir', '-p', OUTDIR + 'workdir'])
os.makedirs(OUTDIR + 'workdir', exist_ok = True)
subprocess.run(['python3', 'tools/exefs2elf.py'])

print("creating baserom.s...")
asmfile = OUTDIR + 'baserom.s'
with open(f'{OUTDIR}baserom.s', 'w') as asmfile:
    subprocess.run([OD, '-D', OUTDIR + 'baserom.elf'], stdout=asmfile)

print("splitting asm...")
# subprocess.run(['mkdir', '-p', BINDIR])
# subprocess.run(['mkdir', '-p', ASMDIR])
os.makedirs(BINDIR, exist_ok = True)
os.makedirs(ASMDIR, exist_ok = True)
subprocess.run(['python3', 'tools/split_asm.py'])
