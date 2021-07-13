import os
import struct

actorsFolder = "src/actors/"
gActorOverlayTableVAddr = 0x50CD84

code = open('baserom/exefs/code.bin', 'r+b')

def vAddrToPAddr(vAddr):
    return vAddr - 0x100000

def getActorSize(actorId):
    code.seek(vAddrToPAddr(gActorOverlayTableVAddr) + (actorId * 0x20) + 0x14)
    actorInitInfoVAddr = struct.unpack('<i', code.read(4))[0]
    code.seek(vAddrToPAddr(actorInitInfoVAddr) + 0xC)
    actorSize = struct.unpack('<i', code.read(4))[0]
    return actorSize

def createActorHeader(path, actorName, actorId):
    actorStructName = actorName.replace("_","")
    actorSize = getActorSize(actorId)

    fileStr = "#ifndef _Z_" + actorName.upper() + "_H_\n"
    fileStr += "#define _Z_" + actorName.upper() + "_H_\n"
    fileStr += "\n"
    fileStr += "#include \"global.hpp\"\n"
    fileStr += "\n"
    fileStr += "struct " + actorStructName + ";\n"
    fileStr += "\n"
    fileStr += "typedef struct " + actorStructName + " {\n"
    fileStr += "    /* 0x0000 */ Actor actor;\n"
    if actorSize > 0x1A4:
        fileStr += "    /* 0x01A4 */ char unk_1A4[" + "0x{:X}".format(actorSize - 0x1A4) + "];\n"
    fileStr += "} " + actorStructName + "; // size = " + "0x{:X}".format(actorSize) + "\n"
    fileStr += "\n"
    fileStr += "extern ActorInit " + actorName + "_InitVars;\n"
    fileStr += "\n"
    fileStr += "#endif\n"

    with open(path, 'w') as header:
        header.write(fileStr)

def createActorSource(path, actorName):
    return #todo

with open('notes/actor_list.txt', 'r') as actorList:
    actorLines = actorList.readlines()
    for i in range(0, len(actorLines)):
        actorName = actorLines[i].strip()
        if actorName == "unset":
            continue

        actorFolder = actorsFolder + actorName
        if not os.path.isdir(actorFolder):
            os.mkdir(actorFolder)

        actorSourceName = "z_" + actorName.lower()
        actorSourcePath = actorFolder + "/" + actorSourceName
        if not os.path.isfile(actorSourcePath + ".hpp"):
            createActorHeader(actorSourcePath + ".hpp", actorName, i)

        if not os.path.isfile(actorSourcePath + ".cpp"):
            createActorSource(actorSourcePath + ".cpp", actorName)

code.close()
