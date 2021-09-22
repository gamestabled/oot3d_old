#pragma once

class CollisionHeader {
public:
    CollisionHeader(void* arg1) : unk_00(arg1) {
    }
    static void SetUnk00(void* arg1, CollisionHeader* col);

private:
    void* unk_00;
};
