import os

code_size = os.path.getsize('build/code.bin')
padded_size = (code_size + 0xFFF) & ~0xFFF

with open('build/code.bin', 'a') as code:
    code.truncate(padded_size)
