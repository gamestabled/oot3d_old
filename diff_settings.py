import os

def apply(config, args):
    config["baseimg"] = "binary/EnBox_Init.o" #Change to your function name
    config["myimg"] = "build/actors/En_Box/z_en_box.o" #Change to your source file
    config["source_directories"] = ["."]
    config["arch"] = "armel"
    config["objdump_executable"] = os.environ.get('DEVKITARM') + "/bin/arm-none-eabi-objdump"
    config["disassemble_all"] = True
