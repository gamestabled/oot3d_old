def apply(config, args):
    config["baseimg"] = "baserom/baserom.elf"
    config["myimg"] = "build/text.o"
    #config["mapfile"] = "build.map"
    config["source_directories"] = ["."]
    config["arch"] = "armv6"
    #config["map_format"] = "gnu" # gnu or mw
    #config["mw_build_dir"] = "build/" # only needed for mw map format
    #config["makeflags"] = []
    config["objdump_executable"] = "/opt/devkitpro/devkitARM/bin/arm-none-eabi-objdump"
