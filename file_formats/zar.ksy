meta:
  id: zar
  file-extension: zar
  endian: le
seq:
  - id: magic
    contents: ['Z', 'A', 'R', 1]
  - id: size
    type: u4
  - id: num_types
    type: u2
  - id: num_files
    type: u2
  - id: offset_filetypes
    type: u4
  - id: offset_file_metadatas
    type: u4
  - id: offset_data_section
    type: u4
  - id: magic_queen
    contents: 'queen'
    size: 8
instances:
  file_types:
    pos: offset_filetypes
    type: filetype
    repeat: expr
    repeat-expr: num_types
  file_metadatas:
    pos: offset_file_metadatas
    type: file_metadata
    repeat: expr
    repeat-expr: num_files
  data_section:
    pos: offset_data_section
    type: u4
    repeat: expr
    repeat-expr: num_files
  files:
    type: file(_index)
    repeat: expr
    repeat-expr: num_files
types:
  filetype:
    seq:
      - id: num_files
        type: u4
      - id: offset_files_list
        type: u4
      - id: offset_type_name
        type: u4
      - id: unk_c
        type: u4
    instances:
      files:
        pos: offset_files_list
        type: u4
        repeat: expr
        repeat-expr: num_files
      typename:
        pos: offset_type_name
        type: str
        encoding: UTF-8
        terminator: 0
  file_metadata:
    seq:
      - id: file_size
        type: u4
      - id: offset_filename
        type: u4
    instances:
      filename:
        pos: offset_filename
        type: str
        encoding: UTF-8
        terminator: 0
  file:
    params:
      - id: file_num
        type: u4
    instances:
      data:
        pos: _parent.data_section[file_num]
        size: _parent.file_metadatas[file_num].file_size