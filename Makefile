TARGET = oot3d_usa

NON_MATCHING ?= 0

SRC_DIR ?= src
BUILD_DIR ?= build

CPP_SRCS := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/**/*.cpp $(SRC_DIR)/**/**/*.cpp)
CPP_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_SRCS))
SUBDIRS  := $(sort $(dir $(CPP_OBJS)))
SPEC     := spec
PRECOMP_O := $(shell cat $(SPEC))

# Tools

SHA1 := $(shell { command -v sha1sum || command -v shasum; } 2>/dev/null)

HAS_WINE := $(shell wine --version 2>/dev/null)
HAS_WINE64 := $(shell wine64 --version 2>/dev/null)

ifdef HAS_WINE
	WINE := wine
else ifdef HAS_WINE64
	WINE := wine64
else
	WINE :=
endif

CC := $(WINE) ./armcc.exe
AS := $(WINE) ./armasm.exe
LK := $(DEVKITARM)/bin/arm-none-eabi-gcc
OBJCOPY := $(DEVKITARM)/bin/arm-none-eabi-objcopy

# Flags

DEBUG_PADDING :=
ifdef DEBUG_PADDING
	PAD_DIAG :=
else
	PAD_DIAG := 1301,2530
endif

CPPFLAGS += -Isrc -Iinclude --cpp --arm --split_sections --debug --no_debug_macros -c --gnu  --debug_info=line_inlining_extensions --cpu=MPCore --fpmode=fast --apcs=/interwork -O3 -Otime --data_reorder --diag_suppress=186,340,401,1256,1297,1568,1764,1786,1788,2523,96,1794,1801,2442,3017,optimizations,$(PAD_DIAG) --diag_error=68,88,174,188,223 -DNN_COMPILER_RVCT -DNN_COMPILER_RVCT_VERSION_MAJOR=4 -DNN_COMPILER_RVCT_VERSION_MINOR=0 -DNN_PROCESSOR_ARM -DNN_PROCESSOR_ARM11MPCORE -DNN_PROCESSOR_ARM_V6 -DNN_PROCESSOR_ARM_VFP_V2 -DNN_HARDWARE_CTR -DNN_EFFORT_FAST -DNN_PLATFORM_CTR -DNN_HARDWARE_CTR_TS -DNN_SYSTEM_PROCESS -DNN_SWITCH_DISABLE_DEBUG_PRINT=1 -DNN_SWITCH_DISABLE_DEBUG_PRINT_FOR_SDK=1 -DNN_SWITCH_DISABLE_ASSERT_WARNING=1 -DNN_SWITCH_DISABLE_ASSERT_WARNING_FOR_SDK=1 -DNN_COMPILER_OPTION_ARM -DNN_USE_MAKECCI -DNN_DEBUGGER_KMC_PARTNER --signed_chars --multibyte_chars --remove_unneeded_entities --force_new_nothrow --remarks --no_rtti
ASMFLAGS += --li --cpu=MPCore --apcs=/inter
LKFLAGS += -mcpu=MPCore -mfloat-abi=hard -marm -T oot.ld

# Clear the default suffixes
.SUFFIXES:

.PHONY: dir all clean
all: dir $(TARGET).3ds
	cat $(TARGET).sha1 
	@$(SHA1) $(TARGET).3ds
	
dir:
	mkdir -p $(BUILD_DIR) $(SUBDIRS)

clean:
	rm -f $(TARGET).3ds
	rm -f -r $(BUILD_DIR)

# Steps

$(BUILD_DIR)/text.o: $(CPP_OBJS)
	@echo "linking asm..."
	$(LK) $(LKFLAGS) -Xlinker -Map=$(TARGET).map $(PRECOMP_O) $(CPP_OBJS) -o $@

# $(CPP_OBJS): $(CPP_SRCS)
# 	$(CC) $(CPPFLAGS) $@ -o $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	python ./tools/preproc.py $(SRC_DIR)/$*.cpp $(BUILD_DIR)/$*_deps.txt
	$(CC) $(CPPFLAGS) $(SRC_DIR)/$*.cpp -S -o $(BUILD_DIR)/$*.s
ifeq ($(NON_MATCHING),0)
	python ./tools/partial_inlines.py $(BUILD_DIR)/$*.s
endif
	$(AS) $(ASMFLAGS) $(BUILD_DIR)/$*.s -o $(BUILD_DIR)/$*_temp.o
	$(LK) -r $(BUILD_DIR)/$*_temp.o $(shell cat '$(BUILD_DIR)/$*_deps.txt') -o $(BUILD_DIR)/$*.o
	$(OBJCOPY) --rename-section .data=$*.data --rename-section .constdata=$*.rodata $(BUILD_DIR)/$*.o

$(BUILD_DIR)/code.bin: $(BUILD_DIR)/text.o
	@echo building code.bin...
	$(OBJCOPY) -O binary $(BUILD_DIR)/text.o $@
	python ./tools/pad_code_binary.py

$(BUILD_DIR)/romfs.bin:
	@echo "archiving romfs..."
	./tools/3dstool -cvtf romfs $(BUILD_DIR)/romfs.bin --romfs-dir ./baserom/romfs > /dev/null

$(TARGET).3ds: $(BUILD_DIR)/romfs.bin $(BUILD_DIR)/code.bin
	@echo "building .3ds..."
	./tools/makerom_oot3d -f cci -o oot3d_usa.3ds -DAPP_ENCRYPTED=false -target t -exefslogo -code $(BUILD_DIR)/code.bin -exheader ./baserom/exheader.bin -icon ./baserom/exefs/icon.bin -banner ./baserom/exefs/banner.bin -plainrgn ./baserom/plainrgn.bin -rsf ./baserom/baserom.rsf -romfs $(BUILD_DIR)/romfs.bin
