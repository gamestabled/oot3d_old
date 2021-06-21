meta:
  id: ctxb
  file-extension: ctxb
  endian: le
  imports: tex
seq:
  - id: magic
    contents: 'ctxb'
  - id: size
    type: u4
  - id: tex_num
    type: u4
  - id: unk_c
    type: u4
  - id: tex_offset
    type: u4
  - id: data_offset
    type: u4
  - id: texs
    type: tex
    size: size - header_size
    repeat: expr
    repeat-expr: tex_num
instances:
  header_size:
    value: 0x18