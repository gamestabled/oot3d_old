with open('build/code.bin', 'wb') as codebin:
    with open('build/text.bin', 'rb') as textbin:
        text = textbin.read(0x3CA000)
        codebin.write(text)
    with open('baserom/workdir/ro.bin', 'rb') as robin:
        ro = robin.read(0x2F000)
        codebin.write(ro)
    with open('baserom/workdir/rw.bin', 'rb') as rwbin:
        rw = rwbin.read(0x62000)
        codebin.write(rw)

