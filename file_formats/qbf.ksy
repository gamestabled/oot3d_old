meta:
  id: qbf
  file-extension: qbf
  endian: le
seq:
  - id: magic
    contents: 'QBF1'
  - id: num
    type: u2
  - id: unk_6
    type: u2
  - id: unk_8
    type: u4
  - id: bits_per_pixel
    type: u1
  - id: glyph_width
    type: u1
  - id: glyph_height
    type: u1
  - id: unk_f
    type: u1
  - id: characters
    type: character_metadata
    repeat: expr
    repeat-expr: num
  - id: bitmaps
    type: bitmap
    repeat: eos
types:
  character_metadata:
    seq:
      - id: character
        type: str
        size: 2
        encoding: UTF-8
      - id: glyph_id
        type: u2
      - id: unk_4
        type: u1
      - id: unk_5
        type: u1
      - id: unk_6
        type: u2
  bitmap:
    seq:
      - id: data
        size: (_parent.glyph_width * _parent.glyph_height * _parent.bits_per_pixel) / 8
  
