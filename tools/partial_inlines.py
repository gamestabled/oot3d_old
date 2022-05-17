import sys
import re

with open(sys.argv[1], 'r') as asmFileIn:
    content = asmFileIn.read()
    content_edited = re.sub('\sBL\s+Collider_DestroyCylinder', ' MOV      r0,#1', content)
    content_edited = re.sub('\sBL\s+ReadCollisionHeaderFromZsi', ' STR      r0,[r1]', content_edited)
    content_edited = re.sub('\sBL\s+__cxa_guard_release', ' MOV      r0,r0', content_edited)
    content_edited = re.sub('\sBL\s+GraphicsContext_UnknownStub', ' MOV      r0,r0', content_edited)

with open(sys.argv[1], 'w') as asmFileOut:
    asmFileOut.write(content_edited)
