#include <assert.h>
#include "../vla.h"

int main()
{
    struct vla vla;

    assert(vla_init(&vla, 2, sizeof(char)));
    assert(vla_len(&vla) == 0);
    assert(vla_cap(&vla) == 2);

    char ch = 'A';
    assert(vla_push(&vla, &ch));
    assert(vla_len(&vla) == 1);

    assert(vla_grow_cap(&vla, 10));
    assert(vla_len(&vla) == 1);
    assert(vla_cap(&vla) == 10);

    assert(*((char*) vla_get(&vla, 0)) == 'A');
}