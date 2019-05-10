#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "intvector.h"

intvector *intvector_new(size_t init_capacity)
{
    intvector *v=malloc(sizeof(v));
    
    if (v!=NULL && init_capacity>0)
    {
		v->val=malloc(sizeof(v)*init_capacity);
		v->size=0;
		v->capacity=init_capacity;
		return v;
	}
	if (v->val == NULL)
	{
	    printf("cant access value\n");
	    free(v);
	    return NULL;
    }
    else
    {
		printf("error\n");
		return NULL;
    }
}

intvector *intvector_copy(const intvector *v)
{
    intvector *new=intvector_new(v->capacity);
    new->size=v->size;
    if (new==NULL || new->size<=0 || new->capacity<=0)
    {
		printf("error\n");
		return NULL;
	}
    for (int i=0; i<v->size; i++)
	{
	    new->val[i]=v->val[i];
	}
	return new;
}

void intvector_free(intvector *v)
{
    free(v);
}

int intvector_getitem(const intvector *v, size_t index)
{
    if (index>v->size || v->val==NULL)
    {
        printf("error\n");
		return 0;
    }
    int num=v->val[index];
    return num;
}
    
void intvector_setitem(intvector *v, size_t index, int item)
{
    if (index>v->capacity)
    {
		printf("out of capacity error\n");
    }
    if (index>v->size)
    {
		v->size=index;
	}
    if (v->val==NULL)
    {
		printf("value error\n");
	}
    else
    {
		v->val[index]=item;
	}
}

size_t intvector_getsize(const intvector *v)
{
    return v->size;
}

size_t intvector_getcapacity(const intvector *v)
{
    return v->capacity;
}

int intvector_pushback(intvector *v, int item)
{
    if (v->val==NULL || v==NULL || v->capacity < v->size)
    {
		printf("error\n");
		return -1;
    }
    if (v->capacity==0)
    {
		v->capacity=2;
    }
    if (v->size == v->capacity)
    {
		v->capacity *= 2;
		v->val=realloc(v->val, v->capacity*sizeof(int));
	}
	if (v->val==NULL)
	{
	    printf("error\n");
	    return -1;
	}
	v->size++;
	v->val[v->size-1]=item;
	return 0;
}

void intvector_popback(intvector *v)
{
    if(v->size!=0)
    {
		v->val[v->size-1]=0;
    }
}

int intvector_shrinktofit(intvector *v)
{
    if(v->size > v->capacity || v->val == NULL || v==NULL)
    {
		printf("error\n");
		return -1;
    }
    
    v->capacity=v->size;
    return 0;
}

int intvector_resize(intvector *v, size_t new_size)
{
    if (new_size >v->capacity || v->val==NULL || v==NULL)
    {
		return -1;
    }
    
    if (new_size >= v->size)
    {
	v->size=new_size;
	for (int i=v->size; i<new_size; i++)
	{
	    v->val[i]=0;
	}
    }
	if (new_size<v->size)
	{
	    intvector_shrinktofit(v);
	}
	return 0;
}

int intvector_reserve(intvector *v, size_t new_cap)
{
    
    if(new_cap>v->capacity)
    {
		v->capacity=new_cap;
		v->val=realloc(v->val, new_cap*(sizeof(int)));
	if (v->val==NULL)
	{
	    printf("memory error\n");
	    return -1;
	}
	return 0;
    }
    return -1;
}
