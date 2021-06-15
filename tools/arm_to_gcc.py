import os
import subprocess
import sys

arm_file = str(sys.argv[1])

result = subprocess.run([os.environ["DEVKITARM"] + r'/bin/arm-none-eabi-objdump', '--section-headers', arm_file], stdout=subprocess.PIPE)
lines = str(result.stdout).split('\\n')
sectionsInfo = [line.split()[1:6] for line in lines if line.split() and line.split()[0].isdigit()]
for section in sectionsInfo:
    if section[0][0] != '.':
        subprocess.run([os.environ["DEVKITARM"] + r'/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section={0}'.format(section[0]), arm_file, 'build/src/bin/{0}.bin'.format(section[0])])
        subprocess.run([os.environ["DEVKITARM"] + r'/bin/arm-none-eabi-objcopy', '-I', 'binary', '-O', 'elf32-littlearm', '--rename-section', '.data={0}'.format(section[0]), 'build/src/bin/{0}.bin'.format(section[0]), 'build/src/{0}.o'.format(section[0])])
