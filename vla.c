#include "vla.h"

bool vla_init(struct vla *vla, size_t cap, int data_size)
{
    if (data_size <= 0) {
        return false;
    }

    void *data = malloc(cap * data_size);
    if (!data)
    {
        return false;
    }

    vla->_data = data;
    vla->_len = 0;
    vla->_cap = cap * data_size;
    vla->_data_size = data_size;

    return true;
}

size_t vla_len(struct vla *vla)
{
    return vla->_len / vla->_data_size;
}

size_t vla_cap(struct vla *vla)
{
    return vla->_cap / vla->_data_size;
}

bool _vla_grow_cap(struct vla *vla, size_t cap)
{
    if (cap <= vla->_cap)
        return true;

    void *data = realloc(vla->_data, cap);
    if (!data)
        return false;

    vla->_cap = cap;
    vla->_data = data;

    return true;
}

bool vla_grow_cap(struct vla *vla, size_t cap)
{
    cap *= vla->_data_size;// TODO: check for overflow
    return _vla_grow_cap(vla, cap);
}

void *vla_get(struct vla *vla, size_t i)
{
    size_t idx = i * vla->_data_size; // TODO: check for overflow
    if (idx < 0 || idx >= vla->_len)
    {
        return NULL; // TODO: should end the program?
    }
    return vla->_data + idx;
}

bool vla_push(struct vla *vla, void *item)
{
    size_t need_cap = vla->_len + vla->_data_size;

    // overflowed
    if (need_cap < vla->_len)
        return false;

    if (need_cap > vla->_cap)
    {
        bool ok = _vla_grow_cap(vla, vla->_cap*2); // TODO check for overflow
        if (!ok)
            return false;
    }

    memcpy(vla->_data + vla->_len, item, vla->_data_size);
    vla->_len += vla->_data_size;
    return true;
}
