# convert exefs to elf
import os
import sys
from subprocess import run

# Ugliness in order to keep the script self-contained
try:
    import tqdm
except ImportError:
    print("Installing tqdm...")
    def command():
        return run([sys.executable, '-m', 'pip', 'install', 'tqdm'])

    # Sigh
    if (command().returncode != 0):
        # Package managers are cool, I say, as I close my eyes and
        # ram through software with reckless abandon.
        if (run([sys.executable, '-m', 'ensurepip']).returncode == 0):
            # Alright pip is set up, lets give it another shot. If it
            # doesn't work, then it's left up to the user.
            command().check_returncode()
finally:
    import tqdm

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
DATADIR = 'data/'

DATA_CHUNK_FILE = 'data_chunks.txt'
FUNCTION_ADDRESSES_FILE = 'function_addresses.txt'
RODATA_CHUNK_FILE = 'rodata_chunks.txt'

def writefile(path, s) -> None:
    with open(path, "wb") as f:
        f.write(s)

def total_file_sizes() -> int:
    return os.path.getsize(DATA_CHUNK_FILE) + \
           os.path.getsize(FUNCTION_ADDRESSES_FILE) + \
           os.path.getsize(RODATA_CHUNK_FILE)

def handle_function_addresses(progress: tqdm.tqdm) -> None:
    with open(WORKDIR + 'text.bin', 'rb') as b:
        with open(FUNCTION_ADDRESSES_FILE) as funcs:
            for line in funcs:
                splitLine = line.split(',')
                funcName = splitLine[0]
                funcStart = int(splitLine[1].strip(), 16) - 0x100000
                funcEnd = int(splitLine[2].strip(), 16) - 0x100000
                funcSize = funcEnd - funcStart
                b.seek(funcStart)
                funcBin = b.read(funcSize)
                writefile(BINARYDIR + funcName + '.bin', funcBin)

                run([OC, '-I', 'binary', '-O', 'elf32-littlearm', '--rename-section', f'.data=i.{funcName}',
                     '--redefine-sym', f'_binary_binary_{funcName}_bin_start={funcName}',
                     f'--globalize-symbol={funcName}', f'{BINARYDIR}{funcName}.bin', f'{BINARYDIR}{funcName}.o'])
                with open(f'{ASMDIR}{funcName}.s', 'w') as asmfile:
                    run([OD, '-D', f'{BINARYDIR}{funcName}.o'], stdout=asmfile)

                progress.update(len(line))

def handle_SHT__INIT_ARRAY__Base():
    with open(WORKDIR + 'text.bin', 'rb') as b:
        arrayName = "SHT__INIT_ARRAY__Base"
        arrayStart = 0x4C97B8 - 0x100000
        arrayEnd = 0x4C99A8 - 0x100000
        arraySize = arrayEnd - arrayStart
        b.seek(arrayStart)
        arrayBin = b.read(arraySize)
        writefile(DATADIR + arrayName + ".bin", arrayBin)
        run([OC, '-I', 'binary', '-O', 'elf32-littlearm', '--rename-section', f'.data=ASM_{arrayName},alloc,load,readonly,data,contents',
             '--redefine-sym', f'_binary_binary_{arrayName}_bin_start={arrayName}', f'{DATADIR}{arrayName}.bin', f'{DATADIR}{arrayName}.o'])

def handle_rodata_chunks(progress: tqdm.tqdm) -> None:
    with open(WORKDIR + 'ro.bin', 'rb') as b:
        with open(RODATA_CHUNK_FILE) as rodata:
            for line in rodata:
                splitLine = line.split(',')
                chunkName = splitLine[0]
                chunkStart = int(splitLine[1].strip(), 16) - 0x4CA000
                chunkEnd = int(splitLine[2].strip(), 16) - 0x4CA000
                chunkSize = chunkEnd - chunkStart
                b.seek(chunkStart)
                chunkBin = b.read(chunkSize)
                writefile(DATADIR + chunkName + '.bin', chunkBin)
                run([OC, '-I', 'binary', '-O', 'elf32-littlearm', '--rename-section', f'.data=ASM_{chunkName},alloc,load,readonly,data,contents',
                     '--redefine-sym', f'_binary_binary_{chunkName}_bin_start={chunkName}', f'{DATADIR}{chunkName}.bin', f'{DATADIR}{chunkName}.o'])

                progress.update(len(line))

def handle_data_chunks(progress: tqdm.tqdm) -> None:
    with open(WORKDIR + 'rw.bin', 'rb') as b:
        with open(DATA_CHUNK_FILE) as data:
            for line in data:
                splitLine = line.split(',')
                chunkName = splitLine[0]
                chunkStart = int(splitLine[1].strip(), 16) - 0x4F9000
                chunkEnd = int(splitLine[2].strip(), 16) - 0x4F9000
                chunkSize = chunkEnd - chunkStart
                b.seek(chunkStart)
                chunkBin = b.read(chunkSize)
                writefile(DATADIR + chunkName + '.bin', chunkBin)
                run([OC, '-I', 'binary', '-O', 'elf32-littlearm', '--rename-section', f'.data=ASM_{chunkName},alloc,load,data,contents',
                     '--redefine-sym', f'_binary_binary_{chunkName}_bin_start={chunkName}', f'{DATADIR}{chunkName}.bin', f'{DATADIR}{chunkName}.o'])

                progress.update(len(line))

with tqdm.tqdm(total=total_file_sizes()) as progress:
    # handle_function_addresses(progress)
    handle_SHT__INIT_ARRAY__Base()
    handle_rodata_chunks(progress)
    handle_data_chunks(progress)
