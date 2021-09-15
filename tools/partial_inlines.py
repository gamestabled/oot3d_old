import sys
import re

with open(sys.argv[1], 'r') as asmFileIn:
    content = asmFileIn.read()
    content_edited = re.sub('\sBL\s+Collider_DestroyCylinder', ' MOV      r0,#1', content)

with open(sys.argv[1], 'w') as asmFileOut:
    asmFileOut.write(content_edited)
