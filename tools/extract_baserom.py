import os
import subprocess

DEVKITARM = os.environ.get('DEVKITARM')

OD = DEVKITARM + "/bin/arm-none-eabi-objdump"

OUTDIR = 'baserom/'
ASMDIR = 'asm/'
DATADIR = 'data/'

TOOLS = 'tools/'
CTRTOOL = TOOLS + 'ctrtool'
N3DSDISASM = TOOLS + 'n3dsdisasm/n3dsdisasm'

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
os.makedirs(OUTDIR + 'workdir', exist_ok = True)
subprocess.run(['python3', 'tools/exefs2elf.py'])

print("creating baserom.s... this will take a while...")
asmfile = OUTDIR + 'baserom.s'
with open(f'{OUTDIR}baserom.s', 'w') as asmfile:
    subprocess.run([N3DSDISASM, '-c', 'oot3d.cfg', OUTDIR + 'exefs/code.bin'], stdout=asmfile)

print("splitting asm...")
os.makedirs(ASMDIR, exist_ok = True)
os.makedirs(DATADIR, exist_ok  = True)
subprocess.run(['python3', 'tools/split_n3dsdisasm.py'])
subprocess.run(['python3', 'tools/split_asm.py'])
