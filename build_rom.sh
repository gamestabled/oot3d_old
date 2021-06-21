#!/bin/sh -e

if [ ! -d "build" ]; then
	mkdir "build"
fi

if [ ! -d "build/src" ]; then
	mkdir "build/src"
fi

echo "compiling src..."
for src in src/*.cpp; do
	name=$( basename $src .cpp )
	# ./armcc.exe -o ./build/src/${name}.o -c --cpp --arm --gnu --apcs=/interwork --cpu=MPCore --fpu=VFPv2 --fpmode=fast --signed-chars --remove_unneeded_entities --split_sections --no_debug_macros --no-debug -O2 -Otime $src
	./armcc.exe --cpp --arm --split_sections --debug --no_debug_macros -c --gnu  --debug_info=line_inlining_extensions --cpu=MPCore --fpmode=fast --apcs=/interwork -O3 -Otime --data_reorder --diag_suppress=186,340,401,1256,1297,1568,1764,1786,1788,2523,96,1794,1801,2442,3017,optimizations --diag_error=68,88,174,188,223 -DNN_COMPILER_RVCT -DNN_COMPILER_RVCT_VERSION_MAJOR=4 -DNN_COMPILER_RVCT_VERSION_MINOR=0 -DNN_PROCESSOR_ARM -DNN_PROCESSOR_ARM11MPCORE -DNN_PROCESSOR_ARM_V6 -DNN_PROCESSOR_ARM_VFP_V2 -DNN_HARDWARE_CTR -DNN_EFFORT_FAST -DNN_PLATFORM_CTR -DNN_HARDWARE_CTR_TS -DNN_SYSTEM_PROCESS -DNN_SWITCH_DISABLE_DEBUG_PRINT=1 -DNN_SWITCH_DISABLE_DEBUG_PRINT_FOR_SDK=1 -DNN_SWITCH_DISABLE_ASSERT_WARNING=1 -DNN_SWITCH_DISABLE_ASSERT_WARNING_FOR_SDK=1 -DNN_COMPILER_OPTION_ARM -DNN_USE_MAKECCI -DNN_DEBUGGER_KMC_PARTNER --signed_chars --multibyte_chars --remove_unneeded_entities --force_new_nothrow --remarks --no_rtti -o ./build/src/${name}.o $src
	"$DEVKITARM/bin/arm-none-eabi-objcopy" --rename-section .data=${name}.data --rename-section .constdata=${name}.rodata ./build/src/${name}.o
done

echo "linking asm..."
"$DEVKITARM/bin/arm-none-eabi-gcc" -o ./build/text.o -mcpu=MPCore -mfloat-abi=hard -marm ./build/src/*.o binary/*.o -T oot.ld

echo "building code.bin..."
"$DEVKITARM/bin/arm-none-eabi-objcopy" -O binary ./build/text.o ./build/code.bin
python ./tools/pad_code_binary.py

echo "archiving romfs..."
./tools/3dstool -cvtf romfs ./build/romfs.bin --romfs-dir ./baserom/romfs > /dev/null

echo "building .3ds..."
./tools/makerom_oot3d -f cci -o oot3d_usa.3ds -DAPP_ENCRYPTED=false -target t -exefslogo -code ./build/code.bin -exheader ./baserom/exheader.bin -icon ./baserom/exefs/icon.bin -banner ./baserom/exefs/banner.bin -plainrgn ./baserom/plainrgn.bin -rsf ./baserom/baserom.rsf -romfs ./build/romfs.bin

sha1sum baserom.3ds oot3d_usa.3ds