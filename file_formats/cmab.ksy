meta:
  id: cmab
  file-extension: cmab
  endian: le
  imports: tex
  ks-opaque-types: true
seq:
  - id: magic
    contents: 'cmab'
  - id: version
    type: u4
  - id: size
    type: u4
  - id: unk_c
    type: u4
  - id: anmd_count
    type: u4
  - id: anmd_offset
    type: u4
  - id: string_table_offset
    type: u4
  - id: texture_data_offset
    type: u4
instances:
  anmd_chunk:
    pos: anmd_offset
    type: anmd
    size: string_table_offset - anmd_offset
  strt_chunk:
    pos: string_table_offset
    type: strt
    size-eos: true
types:
  anmd:
    seq:
      - id: tag
        type: u4
      - id: duration
        type: u4
      - id: loop_mode
        type: u4
        enum: loop_mode
      - id: mads_offset
        type: u4
      - id: txpt_offset
        type: u4
    instances:
      mads_chunk:
        pos: mads_offset
        type: mads
        if: mads_offset != 0
      txpt_chunk:
        pos: txpt_offset
        type: txpt
        if: txpt_offset != 0
    enums:
      loop_mode:
        0: once
        1: loop
    types:
      mads:
        seq:
          - id: magic
            contents: 'mads'
          - id: mmad_count
            type: u4
          - id: mmad_offsets
            type: u4
            repeat: expr
            repeat-expr: mmad_count
          - id: mmads
            type: mmad
            repeat: expr
            repeat-expr: mmad_count
        types:
          mmad:
            seq:
              - id: magic
                contents: 'mmad'
              - id: anim_type
                type: u4
                enum: animation_type
              - id: material_index
                type: u4
              - id: anim
                type:
                  switch-on: anim_type
                  cases:
                    'animation_type::translation': translation
                    'animation_type::palette': palette
                    'animation_type::scale': scale
                    'animation_type::color': color
            enums:
              animation_type:
                1: 
                  id: translation
                  doc: UV Scroll
                2:
                  id: palette
                  doc: Texture Swap
                3:
                  id: scale
                4:
                  id: color
                  doc: Material Color
                5:
                  id: rotation
            types:
              anim_track:
                seq:
                  - id: type
                    type: u4
                    enum: interpolation_type
                  - id: keyframes_count
                    type: u4
                  - id: start_frame
                    type: u4
                  - id: time_end
                    type: u4
                  - id: frames
                    type:
                      switch-on: type
                      cases:
                        'interpolation_type::linear': keyframe_linear
                        'interpolation_type::hermite': keyframe_hermite
                        'interpolation_type::integer': keyframe_linear
                    repeat: expr
                    repeat-expr: keyframes_count
                enums:
                  interpolation_type:
                    1: linear
                    2: hermite
                    3: integer
                types:
                  keyframe_linear:
                    seq:
                      - id: frame
                        type: u4
                      - id: value
                        type: f4
                  keyframe_hermite:
                    seq:
                      - id: frame
                        type: u4
                      - id: value
                        type: f4
                      - id: in_slope
                        type: f4
                      - id: out_slope
                        type: f4
              translation:
                seq:
                  - id: channel_index
                    type: u4
                  - id: offset_1
                    type: u2
                  - id: offset_2
                    type: u2
                  - id: anim_track_1
                    type: anim_track
                    if: offset_1 != 0
                  - id: anim_track_2
                    type: anim_track
                    if: offset_2 != 0
              palette:
                seq:
                  - id: channel_index
                    type: u4
                  - id: offsets
                    type: u2
                    repeat: expr
                    repeat-expr: 2
                  - id: anim
                    type: anim_track
              scale:
                seq:
                  - id: offset_1
                    type: u2
                  - id: offset_2
                    type: u2
                  - id: offset_3
                    type: u2
                  - id: pad
                    type: u2
                  - id: anim_track_1
                    type: anim_track
                    if: offset_1 != 0
                  - id: anim_track_2
                    type: anim_track
                    if: offset_2 != 0
                  - id: anim_track_3
                    type: anim_track
                    if: offset_3 != 0
              color:
                seq:
                  - id: channel_index
                    type: u4
                  - id: offset_1
                    type: u2
                  - id: offset_2
                    type: u2
                  - id: offset_3
                    type: u2
                  - id: offset_4
                    type: u2
                  - id: anim_track_1
                    type: anim_track
                    if: offset_1 != 0
                  - id: anim_track_2
                    type: anim_track
                    if: offset_2 != 0
                  - id: anim_track_3
                    type: anim_track
                    if: offset_3 != 0
                  - id: anim_track_4
                    type: anim_track
                    if: offset_4 != 0
      txpt:
        seq:
          - id: magic
            contents: 'txpt'
          - id: num
            type: u4
          # - id: textures
          #   type: 'tex::texture' TODO: this doesnt work
  strt:
    seq:
      - id: magic
        contents: 'strt'
      - id: num
        type: u4
      - id: offsets
        type: u4
        repeat: expr
        repeat-expr: num
    instances:
      data_begin:
        value: 0xC
      strings:
        pos: data_begin + offsets[_index]
        type: str
        encoding: UTF-8
        terminator: 0
        repeat: expr
        repeat-expr: num