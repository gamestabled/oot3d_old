#!/bin/sh -e

if [ ! -d "build" ]; then
	mkdir "build"
fi

echo "assembling asm..."
"$DEVKITARM/bin/arm-none-eabi-gcc" -o ./build/text.o binary/*.o -T oot.ld

echo "building text.bin..."
"$DEVKITARM/bin/arm-none-eabi-objcopy" -O binary ./build/text.o ./build/text.bin

echo "building code.bin..."
python ./tools/build_code_binary.py

echo "archiving romfs..."
./tools/3dstool -cvtf romfs ./build/romfs.bin --romfs-dir ./baserom/romfs > /dev/null

echo "building .3ds..."
./tools/makerom_oot3d -f cci -o oot3d_usa.3ds -DAPP_ENCRYPTED=false -target t -exefslogo -code ./build/code.bin -exheader ./baserom/exheader.bin -icon ./baserom/exefs/icon.bin -banner ./baserom/exefs/banner.bin -plainrgn ./baserom/plainrgn.bin -rsf ./baserom/baserom.rsf -romfs ./build/romfs.bin

sha1sum baserom.3ds oot3d_usa.3ds
