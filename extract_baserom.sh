#!/bin/sh -e

PWD=$( pwd )
OUTDIR="$PWD/baserom"
BINDIR="$PWD/binary"
ASMDIR="$PWD/asm"

invalid_file() {
	echo "ERROR: could not open baserom!"
	exit 1
}

mkdir -p "$OUTDIR"

echo "extracting exefs..."
./tools/ctrtool --exefsdir="$OUTDIR/exefs"   "baserom.3ds" > /dev/null || invalid_file

echo "extracting exheader..."
./tools/ctrtool --exheader="$OUTDIR/exheader.bin" "baserom.3ds" > /dev/null || invalid_file

echo "extracting romfs..."
./tools/ctrtool --romfsdir="$OUTDIR/romfs" "baserom.3ds" > /dev/null || invalid_file

echo "extracting plainrgn..."
./tools/ctrtool --plainrgn="$OUTDIR/plainrgn.bin" "baserom.3ds" > /dev/null || invalid_file

# echo "creating baserom.rsf..."
# cp tools/dummy.rsf $OUTDIR/baserom.rsf
# python tools/rsfgen.py -r baserom.3ds -e $OUTDIR/exheader.bin -o $OUTDIR/baserom.rsf

echo "creating baserom.elf..."
if [ ! -d "$OUTDIR/workdir" ]; then
	mkdir "$OUTDIR/workdir"
fi
python tools/exefs2elf.py

echo "creating baserom.s..."
"$DEVKITARM/bin/arm-none-eabi-objdump" -D "$OUTDIR/baserom.elf" > "$OUTDIR/baserom.s"

if [ ! -d "$BINDIR" ]; then
	mkdir "$BINDIR"
fi
if [ ! -d "$ASMDIR" ]; then
	mkdir "$ASMDIR"
fi

echo "splitting asm..."
python ./tools/split_asm.py
