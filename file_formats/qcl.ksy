meta:
  id: qcl
  file-extension: qcl
  endian: le
seq:
  - id: records
    type: record
    repeat: eos
types:
  rgba:
    seq:
      - id: r
        type: u1
      - id: g
        type: u1
      - id: b
        type: u1
      - id: a
        type: u1
  record:
    seq:
      - id: index
        type: u4
      - id: color
        type: rgba