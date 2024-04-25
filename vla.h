#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

struct vla
{
    void *_data;
    size_t _len;
    size_t _cap;
    int _data_size;
};

bool vla_init(struct vla *vla, size_t cap, int data_size);

size_t vla_len(struct vla *vla);

size_t vla_cap(struct vla *vla);

void *vla_get(struct vla *vla, size_t i);

bool vla_push(struct vla *vla, void *item);