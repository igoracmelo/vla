
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "../vla.h"

int main()
{
    struct vla vla;

    assert(vla_init(&vla, 1, sizeof(char)));

    // had to cheat since I can't malloc this size
    vla._len = SIZE_MAX;
    vla._cap = SIZE_MAX;

    char ch = 'Z';
    assert(!vla_push(&vla, &ch));
}