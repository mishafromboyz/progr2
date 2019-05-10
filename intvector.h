#include <stddef.h>
#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

typedef struct
{
    size_t size;
    size_t capacity;
    int *val;
} intvector;

intvector *intvector_new(size_t init_capacity);

intvector *intvector_copy(const intvector *v);

void intvector_free(intvector *v);

int intvector_getitem(const intvector *v, size_t index);

void intvector_setitem(intvector *v, size_t index, int item);

size_t intvector_getsize(const intvector *v);

size_t intvector_getcapacity(const intvector *v);

int intvector_pushback(intvector *v, int item);

void intvector_popback(intvector *v);

int intvector_shrinktofit(intvector *v);

int intvector_resize(intvector *v, size_t newsize);

int intvector_reserve(intvector *v, size_t newcapacity);

#endif
