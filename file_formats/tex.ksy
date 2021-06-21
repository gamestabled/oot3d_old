meta:
  id: tex
  file-extension: tex
  endian: le
seq:
  - id: magic
    contents: 'tex '
  - id: size
    type: u4
  - id: num
    type: u4
  - id: textures
    type: texture
    repeat: expr
    repeat-expr: num
instances:
  data_begin:
    value: num * 0x24 + 0xC
types:
  texture:
    seq:
      - id: len
        type: u4
      - id: mipmap_count
        type: u2
      - id: is_etc1
        type: u1
      - id: is_cubemap
        type: u1
      - id: width
        type: u2
      - id: height
        type: u2
      - id: pica_texture_format
        type: pica_texture_format
      - id: pica_data_type
        type: pica_data_type
      - id: data_offset
        type: u4
      - id: name
        type: str
        size: 16
        encoding: UTF-8
    instances:
      data:
        pos: _parent.data_begin + data_offset
        size: len
  pica_texture_format:
    seq:
      - id: format
        type: u2
        enum: pica_texture_formats
    enums:
      pica_texture_formats:
        0x6752: rgba_native_dmp
        0x6754: rgb_native_dmp
        0x6756: alpha_native_dmp
        0x6757: luminance_native_dmp
        0x6758: luminance_alpha_native_dmp
        0x675A: etc1_rgb8_native_dmp
        0x675B: etc1_alpha_rgb8a4_native_dmp
  pica_data_type:
    seq:
      - id: type
        type: u2
        enum: pica_data_types
    enums:
      pica_data_types:
        0x1400: s8
        0x1401: u8
        0x1402: s16
        0x1403: u16
        0x1404: s32
        0x1405: u32
        0x1406: f32
        0x6760: unsigned_byte44_dmp
        0x6761: unsigned_4bits_dmp
        0x8033: unsigned_short4444
        0x8034: unsigned_short5551
        0x8363: unsigned_short565