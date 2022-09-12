#!/usr/bin/env python3

import argparse
import json
import csv
import git
import os
import re

parser = argparse.ArgumentParser(description="Computes current progress throughout the whole project.")
parser.add_argument("format", nargs="?", default="text", choices=["text", "csv", "shield-json"])
parser.add_argument("-m", "--matching", dest='matching', action='store_true',
                    help="Output matching progress instead of decompilation progress")
args = parser.parse_args()

NON_MATCHING_PATTERN = r'#ifdef\s+NON_MATCHING.*?\s+GLOBAL_ASM\s*\(\s*\"(.*?)\"\s*\).*?#endif'
NOT_ATTEMPTED_PATTERN = r'\s+GLOBAL_ASM\s*\(\s*"asm/(.*?)"\s*\)'

def GetFunctionsByPattern(pattern, files):
    functions = []

    for file in files:
        with open(file) as f:
            functions += re.findall(pattern, f.read(), re.DOTALL)

    return functions

def ReadAllLines(fileName):
    lineList = list()
    with open(fileName) as f:
        lineList = f.readlines()

    return lineList

def GetFiles(path, ext):
    files = []
    
    for r, d, f in os.walk(path):
        for file in f:
            if file.endswith(ext):
                files.append(os.path.join(r, file))

    return files

allFiles = GetFiles("src", ".cpp")

nonMatchingFunctions = GetFunctionsByPattern(NON_MATCHING_PATTERN, allFiles)
notAttemptedFunctions = GetFunctionsByPattern(NOT_ATTEMPTED_PATTERN, allFiles)

if not args.matching:
    nonMatchingFunctions = []

def GetNonMatchingSize(path):
    size = 0

    asmFiles = GetFiles(path, ".s")

    for asmFilePath in asmFiles:
        if asmFilePath.split('/')[1] in notAttemptedFunctions:
            asmLines = ReadAllLines(asmFilePath)

            for asmLine in asmLines:
                if asmLine.startswith("\t"):
                    if not (asmLine.startswith("\t.") or asmLine.startswith("\tarm_func_start") or asmLine.startswith("\t.byte")):
                        size += 4
                    elif asmLine.startswith("\t.byte"):
                        size += int((len(asmLine.strip()) - 4) / 6)
                elif asmLine.count(".4byte") > 0:
                    size += 4

    return size


# mapFile = ReadAllLines("build/z64.map")
src = 3973120
# code = 0
# boot = 0
# ovl = 0

# for line in mapFile:
#     lineSplit =  list(filter(None, line.split(" ")))

#     if (len(lineSplit) == 4 and lineSplit[0].startswith(".")):
#         section = lineSplit[0]
#         size = int(lineSplit[2], 16)
#         objFile = lineSplit[3]

#         if (section == ".text"):
#             if (objFile.startswith("build/src")):
#                 src += size

#             if (objFile.startswith("build/src/code") or objFile.startswith("build/src/libultra_code")):
#                 code += size
#             elif (objFile.startswith("build/src/boot") or objFile.startswith("build/src/libultra_boot")):
#                 boot += size
#             elif (objFile.startswith("build/src/overlays")):
#                 ovl += size

nonMatchingASM = GetNonMatchingSize("asm")

src -= nonMatchingASM

total = src + nonMatchingASM
srcPct = 100 * src / total
# codePct = 100 * code / codeSize
# bootPct = 100 * boot / bootSize
# ovlPct = 100 * ovl / ovlSize

bytesPerHeartPiece = total / 80

if args.format == 'csv':
    version = 1
    git_object = git.Repo().head.object
    timestamp = str(git_object.committed_date)
    git_hash = git_object.hexsha
    # csv_list = [str(version), timestamp, git_hash, str(code), str(codeSize), str(boot), str(bootSize), str(ovl), str(ovlSize), str(src), str(nonMatchingASM), str(len(nonMatchingFunctions))]
    csv_list = [str(version), timestamp, git_hash, str(src), str(nonMatchingASM), str(len(nonMatchingFunctions))]
    print(",".join(csv_list))
elif args.format == 'shield-json':
    # https://shields.io/endpoint
    print(json.dumps({
        "schemaVersion": 1,
        "label": "progress",
        "message": f"{srcPct:.3g}%",
        "color": 'yellow',
    }))
elif args.format == 'text':
    adjective = "decompiled" if not args.matching else "matched"

    print(str(total) + " total bytes of decompilable code\n")
    print(str(src) + " bytes " + adjective + " in src " + str(srcPct) + "%\n")
    # print(str(boot) + "/" + str(bootSize) + " bytes " + adjective + " in boot " + str(bootPct) + "%\n")
    # print(str(code) + "/" + str(codeSize) + " bytes " + adjective + " in code " + str(codePct) + "%\n")
    # print(str(ovl) + "/" + str(ovlSize) + " bytes " + adjective + " in overlays " + str(ovlPct) + "%\n")
    print("------------------------------------\n")

    heartPieces = int(src / bytesPerHeartPiece)
    rupees = int(((src % bytesPerHeartPiece) * 100) / bytesPerHeartPiece)

    if (rupees > 0):
        print("You have " + str(heartPieces) + "/80 heart pieces and " + str(rupees) + " rupee(s).\n")
    else:
        print("You have " + str(heartPieces) + "/80 heart pieces.\n")
else:
    print("Unknown format argument: " + args.format)
