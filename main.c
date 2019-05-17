#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <inttypes.h>
#include "intvector.h"

int main()
{
    int check;
    
    printf("enter size of array\n");
    size_t size;
    scanf("%zu",  &size);
    
    printf("enter capacity of array\n");
    size_t capacity;
    scanf("%zu", &capacity);
    
    if (size>capacity)
    {
		printf("size must be less than capacity, expecting errors\n");
    }
    
    printf("\nrunning new function\n");
    intvector *v = intvector_new(capacity);
    
    printf("\nrunning setitem function for every element in array\n");
    int j=0;
    for (size_t i=0; i<size; i++)
    {
		intvector_setitem(v, i, j);
		j++;
    }
    
    printf("\nrunning copy function\n");
    intvector *vcopy = intvector_copy(v);
    
    printf("\nrunning free function\n");
    intvector_free(vcopy);
    
    printf("\nrunning getitem function\n enter index\n");
    size_t index;
    scanf("%zu", &index);
    int item = intvector_getitem(v, index);
    printf("arr[%zu]=%d", index, item);
    
    printf("\nrunning pushback function\nenter element value\n");
    scanf("%d", &item);
    check=intvector_pushback(v, item);
    if (check==-1)
    {
		printf("%d", check);
    }
    else
    {
		size_t newcap=intvector_getcapacity(v);
		printf("\tusing getcap function\n\tcapacity after pushback=%zu\n", newcap);
    }
    
    printf("\n\nrunning popback function\n");
    intvector_popback(v);
    size_t newcap = intvector_getcapacity(v);
    size_t newsize = intvector_getsize(v);
    printf("\tusing getsize function\n\tsize after popback=%zu", newsize);
    
    printf("\n\nrunning shrinktofit function\n");
    check=intvector_shrinktofit(v);
    if (check==-1)
    {
	printf("%d", check);
    }
    else
    {
	newsize=intvector_getsize(v);
	newcap=intvector_getcapacity(v);
	printf("\nafter shrinktofit size=%zu, cap=%zu", newsize, newcap);
    }
    
    printf("\nrunning resize function\nenter new size");
    scanf("%zu", &newsize);
    check=intvector_resize(v, newsize);
    if (check==-1)
    {
	printf("%d", check);
    }
    else
    {
	newsize=intvector_getsize(v);
	printf("\tafter resize size=%zu", newsize);
    }
    
    printf("\n\nrunning reserve function\nenter new cap\n");
    scanf("%zu", &newcap);
    check=intvector_reserve(v, newcap);
    if (check==-1)
    {
	printf("%zu", newcap);
    }
    else
    {
	newcap=intvector_getcapacity(v);
	printf("after reserve capacity=%zu", newcap);
    }
    return 0;
}
