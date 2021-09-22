# The Legend of Zelda: Ocarina of Time 3D

This is a WIP decompilation of The Legend of Zelda: Ocarina of Time 3D.
The purpose of the project is to recreate a source code base for the game from scratch, using information found inside the game along with static and/or dynamic analysis.
The only build currently supported is the USA version.

It builds the following ROM:


* **oot3d_usa.3ds**
* **code.bin** `md5: 20c7ec6288ba0af4feb6db646c6cc6d5`
* **romfs.bin** `md5: d2a0fa58cfb52ca9e584170195821364`

For simplicity, this repository only enforces binary matching on the portions of the ROM which contain compiled source code and assets.

**Note:** This repository does not include any of the assets necessary to build the ROM.
A prior copy of the game is required to extract the needed assets.

Website: <https://zelda64.dev/>

Discord: <https://discord.zelda64.dev>

## Installation
To set up the repository, place a USA version of `The Legend of Zelda: Ocarina of Time 3D (USA)` in the root directory of the repository and name it `baserom.3ds`. Any revision (v0 or v1) and either trimmed or untrimmed roms should be able to produce a correct repository.

Run `make setup` to extract all of the necessary materials for building from your rom.

## Building
Place `armcc` and `armasm` from RVCT4.0 [Build 821] in the root directory of the repository. These legacy tools are available for public download from ARM. Early research shows that these tools are sufficiently similar to those used to compile the original game.

Run `make`.


## Contributing
If you decompile a function or data, remove the `GLOBAL_ASM` for that function or data. If you rename a function, you will also need to change its name in `oot.ld` (`oot.ld` is the linkerscript which handles global ordering). Once the function matches, you can remove it from `function_addresses.txt` (`function_addresses.txt` is used by `split_asm.py` during rom extraction). For data, replace `ASM_[FileName]` with `[FileName].data` in `oot.ld`. This process is likely to change.

Most discussions happen on our [Discord Server](https://discord.zelda64.dev), where you are welcome to ask if you need help getting started, or if you have any questions regarding this project and other decompilation projects.
