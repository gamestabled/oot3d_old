meta:
  id: qm
  file-extension: qm
  endian: le
seq:
  - id: magic
    contents: ['Q', 'M', '0x00', '0x00']
  - id: unk_4
    type: u4
  - id: num
    type: u4
  - id: unk_c
    type: u4
  - id: entries
    type: entry
    repeat: expr
    repeat-expr: num
types:
  entry:
    seq:
      - id: id
        type: u4
      - id: unk_4
        type: u4
      - id: box_type
        type: u4
      - id: box_pos
        type: u4
      - id: infos
        type: info
        repeat: expr
        repeat-expr: 10
    types:
      info:
        seq:
          - id: offset
            type: u4
          - id: len
            type: u4
        instances:
          message:
            pos: offset
            size: len
    enums:
      languages:
        0: j_japanese
        1: u_english
        2: e_english
        3: e_german
        4: e_french
        5: u_french
        6: e_spanish
        7: u_spanish
        8: e_italian
        9: e_dutch