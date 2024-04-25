#include <assert.h>
#include <stdio.h>
#include "../vla.h"

int main()
{
    struct vla vla;

    assert(vla_init(&vla, 1, sizeof(int)));
    assert(vla_len(&vla) == 0);
    assert(vla_cap(&vla) == 1);
    assert(vla._data_size == sizeof(int));
    assert(vla._data != NULL);

    int val = 32;
    assert(vla_push(&vla, &val));
    assert(vla_len(&vla) == 1);

    int *got_val = vla_get(&vla, 0);
    assert(*got_val == val);

    val = 15;
    assert(vla_push(&vla, &val));
    assert(vla_len(&vla) == 2);
    assert(vla_cap(&vla) == 2);

    got_val = vla_get(&vla, 1);
    assert(*got_val == val);

    val = 22;
    assert(vla_push(&vla, &val));
    assert(vla_len(&vla) == 3);
    assert(vla_cap(&vla) == 4);

    got_val = vla_get(&vla, 2);
    assert(*got_val == val);

    assert(*((int*)vla_get(&vla, 0)) == 32);
    assert(*((int*)vla_get(&vla, 1)) == 15);
    assert(*((int*)vla_get(&vla, 2)) == 22);
    assert(vla_get(&vla, 3) == NULL);
}