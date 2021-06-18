# oot3d

Put the decrypted USA v0 version of OoT3D in the root folder named ```baserom.3ds```. If you want to get a matching rom at the end, make sure to use the "trimmed" version that godMode9 creates.

Here is the sha1sum of the matching baserom.3ds: ```a6e831e3b8322a493c19f258099733cd7dade264```

Note: if you have USA v1, you can just continue and when you build the rom, you should end up with a matching copy of v0.

Run ```extract_baserom.sh``` to extract everything and split the asm files.

Run ```build_rom.sh``` to put everything back together and compare SHAs.

If you want to link in some compiled C++ code, do something like this:

```
__attribute__((section("Actor_Kill")))
void Actor_Kill(Actor* actor) {
    actor->draw = 0;
    actor->update = 0;
    actor->flags &= ~0x1;
}
```

And edit the generated ```oot.ld``` file to place the ```Actor_Kill``` section in the right spot.
