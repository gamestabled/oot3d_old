TARGET = oot3d_usa

# If COMPARE is 1, check the output md5sum after building
COMPARE ?= 1
# If NON_MATCHING is 1, define the NON_MATCHING C flag when building
NON_MATCHING ?= 0

ifeq ($(NON_MATCHING),1)
  COMPARE := 0
endif

BUILD_DIR ?= build

SRC_DIR ?= src
NN_SRC_DIR ?= lib/CTR_SDK/src/nn
STD_SRC_DIR ?= lib/STD/src

SRC_BUILD_DIR ?= $(BUILD_DIR)/src
LIB_BUILD_DIR ?= $(BUILD_DIR)/lib
NN_BUILD_DIR ?= $(LIB_BUILD_DIR)/nn
STD_BUILD_DIR ?= $(LIB_BUILD_DIR)/std

CPP_SRCS := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/**/*.cpp $(SRC_DIR)/**/**/*.cpp)
CPP_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(SRC_BUILD_DIR)/%.o,$(CPP_SRCS))

NN_CPP_SRCS := $(wildcard $(NN_SRC_DIR)/*.cpp $(NN_SRC_DIR)/**/*.cpp $(NN_SRC_DIR)/**/**/*.cpp)
NN_CPP_OBJS := $(patsubst $(NN_SRC_DIR)/%.cpp,$(NN_BUILD_DIR)/%.o,$(NN_CPP_SRCS))

STD_CPP_SRCS := $(wildcard $(STD_SRC_DIR)/*.cpp $(STD_SRC_DIR)/**/*.cpp $(STD_SRC_DIR)/**/**/*.cpp)
STD_CPP_OBJS := $(patsubst $(STD_SRC_DIR)/%.cpp,$(STD_BUILD_DIR)/%.o,$(STD_CPP_SRCS))

LIB_OBJS := $(NN_CPP_OBJS) $(STD_CPP_OBJS)

SUBDIRS  := $(sort $(dir $(CPP_OBJS))) $(sort $(dir $(LIB_OBJS))) 

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

CPPFLAGS += -Isrc -Iinclude -Ilib/CTR_SDK/include -Ilib/STD/include --cpp --arm --split_sections --debug --no_debug_macros -c --gnu  --debug_info=line_inlining_extensions --cpu=MPCore --fpmode=fast --apcs=/interwork -O3 -Otime --data_reorder --diag_suppress=186,340,401,1256,1297,1568,1764,1786,1788,2523,96,1794,1801,2442,3017,optimizations,$(PAD_DIAG) --diag_error=68,88,174,188,223 -DNN_COMPILER_RVCT -DNN_COMPILER_RVCT_VERSION_MAJOR=4 -DNN_COMPILER_RVCT_VERSION_MINOR=0 -DNN_PROCESSOR_ARM -DNN_PROCESSOR_ARM11MPCORE -DNN_PROCESSOR_ARM_V6 -DNN_PROCESSOR_ARM_VFP_V2 -DNN_HARDWARE_CTR -DNN_EFFORT_FAST -DNN_PLATFORM_CTR -DNN_HARDWARE_CTR_TS -DNN_SYSTEM_PROCESS -DNN_SWITCH_DISABLE_DEBUG_PRINT=1 -DNN_SWITCH_DISABLE_DEBUG_PRINT_FOR_SDK=1 -DNN_SWITCH_DISABLE_ASSERT_WARNING=1 -DNN_SWITCH_DISABLE_ASSERT_WARNING_FOR_SDK=1 -DNN_COMPILER_OPTION_ARM -DNN_USE_MAKECCI -DNN_DEBUGGER_KMC_PARTNER --signed_chars --multibyte_chars --remove_unneeded_entities --force_new_nothrow --remarks --no_rtti
NN_CPPFLAGS += -Isrc -Iinclude -Ilib/CTR_SDK/include -Ilib/STD/include  --cpp --arm --split_sections --debug --no_debug_macros -c --gnu  --debug_info=line_inlining_extensions --cpu=MPCore --fpmode=fast --apcs=/interwork -O3 -Otime --no_data_reorder --diag_suppress=186,340,401,1256,1297,1568,1764,1786,1788,2523,96,1794,1801,2442,3017,optimizations,$(PAD_DIAG) --diag_error=68,88,174,188,223 -DNN_COMPILER_RVCT -DNN_COMPILER_RVCT_VERSION_MAJOR=4 -DNN_COMPILER_RVCT_VERSION_MINOR=0 -DNN_PROCESSOR_ARM -DNN_PROCESSOR_ARM11MPCORE -DNN_PROCESSOR_ARM_V6 -DNN_PROCESSOR_ARM_VFP_V2 -DNN_HARDWARE_CTR -DNN_EFFORT_FAST -DNN_PLATFORM_CTR -DNN_HARDWARE_CTR_TS -DNN_SYSTEM_PROCESS -DNN_SWITCH_DISABLE_DEBUG_PRINT=1 -DNN_SWITCH_DISABLE_DEBUG_PRINT_FOR_SDK=1 -DNN_SWITCH_DISABLE_ASSERT_WARNING=1 -DNN_SWITCH_DISABLE_ASSERT_WARNING_FOR_SDK=1 -DNN_COMPILER_OPTION_ARM -DNN_USE_MAKECCI -DNN_DEBUGGER_KMC_PARTNER --signed_chars --multibyte_chars --remove_unneeded_entities --force_new_nothrow --remarks --no_rtti
STD_CPPFLAGS = $(NN_CPPFLAGS)
ASMFLAGS += --li --cpu=MPCore --apcs=/inter
LKFLAGS += -mcpu=MPCore -mfloat-abi=hard -marm -T oot.ld

# Clear the default suffixes
.SUFFIXES:

.PHONY: dir all clean
all: dir $(TARGET).3ds
ifeq ($(COMPARE),1)
	@md5sum $(BUILD_DIR)/code.bin
	@md5sum $(BUILD_DIR)/romfs.bin
	@md5sum -c checksum.md5
endif
	
dir:
	mkdir -p $(BUILD_DIR) $(SUBDIRS)

clean:
	rm -f $(TARGET).3ds
	rm -f -r $(BUILD_DIR)

setup:
	python3 ./tools/extract_baserom.py

# Steps

$(BUILD_DIR)/text.o: $(CPP_OBJS) $(LIB_OBJS)
	@echo "linking asm..."
	$(LK) $(LKFLAGS) -nostdlib -Xlinker -Map=$(TARGET).map $(CPP_OBJS) $(LIB_OBJS) -o $@

# $(CPP_OBJS): $(CPP_SRCS)
# 	$(CC) $(CPPFLAGS) $@ -o $<

$(SRC_BUILD_DIR)/%.deps: $(SRC_DIR)/%.cpp
	python3 ./tools/preproc.py $(SRC_DIR)/$*.cpp $(SRC_BUILD_DIR)/$*.deps

$(SRC_BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_BUILD_DIR)/%.deps
	$(CC) $(CPPFLAGS) $(SRC_DIR)/$*.cpp -S -o $(SRC_BUILD_DIR)/$*.s
ifeq ($(NON_MATCHING),0)
	python3 ./tools/partial_inlines.py $(SRC_BUILD_DIR)/$*.s
endif
	$(AS) $(ASMFLAGS) $(SRC_BUILD_DIR)/$*.s -o $(SRC_BUILD_DIR)/$*_temp.o
	$(LK) -r $(SRC_BUILD_DIR)/$*_temp.o $(shell cat '$(SRC_BUILD_DIR)/$*.deps') -o $(SRC_BUILD_DIR)/$*.o
	$(OBJCOPY) --rename-section .data=$*.data --rename-section .constdata=$*.rodata --rename-section .bss=$*.bss $(SRC_BUILD_DIR)/$*.o

$(NN_BUILD_DIR)/%.deps: $(NN_SRC_DIR)/%.cpp
	python3 ./tools/preproc.py $(NN_SRC_DIR)/$*.cpp $(NN_BUILD_DIR)/$*.deps

$(NN_BUILD_DIR)/%.o: $(NN_SRC_DIR)/%.cpp $(NN_BUILD_DIR)/%.deps
	$(CC) $(NN_CPPFLAGS) $(NN_SRC_DIR)/$*.cpp -S -o $(NN_BUILD_DIR)/$*.s
ifeq ($(NON_MATCHING),0)
	python3 ./tools/partial_inlines.py $(NN_BUILD_DIR)/$*.s
endif
	$(AS) $(ASMFLAGS) $(NN_BUILD_DIR)/$*.s -o $(NN_BUILD_DIR)/$*_temp.o
	$(LK) -r $(NN_BUILD_DIR)/$*_temp.o $(shell cat '$(NN_BUILD_DIR)/$*.deps') -o $(NN_BUILD_DIR)/$*.o
	$(OBJCOPY) --rename-section .data=nn/$*.data --rename-section .constdata=nn/$*.rodata --rename-section .bss=nn/$*.bss $(NN_BUILD_DIR)/$*.o

$(STD_BUILD_DIR)/%.deps: $(STD_SRC_DIR)/%.cpp
	python3 ./tools/preproc.py $(STD_SRC_DIR)/$*.cpp $(STD_BUILD_DIR)/$*.deps

$(STD_BUILD_DIR)/%.o: $(STD_SRC_DIR)/%.cpp $(STD_BUILD_DIR)/%.deps
	$(CC) $(STD_CPPFLAGS) $(STD_SRC_DIR)/$*.cpp -S -o $(STD_BUILD_DIR)/$*.s
ifeq ($(NON_MATCHING),0)
	python3 ./tools/partial_inlines.py $(STD_BUILD_DIR)/$*.s
endif
	$(AS) $(ASMFLAGS) $(STD_BUILD_DIR)/$*.s -o $(STD_BUILD_DIR)/$*_temp.o
	$(LK) -r $(STD_BUILD_DIR)/$*_temp.o $(shell cat '$(STD_BUILD_DIR)/$*.deps') -o $(STD_BUILD_DIR)/$*.o
	$(OBJCOPY) --rename-section .data=nn/$*.data --rename-section .constdata=nn/$*.rodata --rename-section .bss=nn/$*.bss $(STD_BUILD_DIR)/$*.o

$(BUILD_DIR)/code.bin: $(BUILD_DIR)/text.o
	@echo building code.bin...
	$(OBJCOPY) -O binary $(BUILD_DIR)/text.o $@
	python3 ./tools/pad_code_binary.py

$(BUILD_DIR)/romfs.bin:
	@echo "archiving romfs..."
	./tools/3dstool -cvtf romfs $(BUILD_DIR)/romfs.bin --romfs-dir ./baserom/romfs > /dev/null

$(TARGET).3ds: $(BUILD_DIR)/romfs.bin $(BUILD_DIR)/code.bin
	@echo "building .3ds..."
	./tools/makerom_oot3d -f cci -o oot3d_usa.3ds -DAPP_ENCRYPTED=false -target t -exefslogo -code $(BUILD_DIR)/code.bin -exheader ./baserom/exheader.bin -icon ./baserom/exefs/icon.bin -banner ./baserom/exefs/banner.bin -plainrgn ./baserom/plainrgn.bin -rsf ./baserom/baserom.rsf -romfs $(BUILD_DIR)/romfs.bin
