#ifndef __SIMPLE_DYNAMIC_STRING_H__
#define __SIMPLE_DYNAMIC_STRING_H__
#include "defs.h"

typedef struct simpleDynamicString {
    _size_t_ length;
    _size_t_ alloca;
    _size_b_ pflags;
    char buffer[];
} sds;


#endif 