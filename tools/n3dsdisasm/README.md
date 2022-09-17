# N3DSDISASM

This is a simple disassembler for Nintendo 3DS games.

## Usage

`n3dsdisasm code_file -c config_file`
where `code_file` is the code.bin file to disassemble, and `config_file` is an optional config file that gives hints to the disassembler.

## Config File

The config file consists of a list of statements, one per line. Lines beginning with `#` are treated as comments. An config file `rhm.cfg` for Rhythm Heaven Megamix (USA) is provided as an example.
