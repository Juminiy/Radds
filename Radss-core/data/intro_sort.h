#ifndef __INTRO_SORT__
#define __INTRO_SORT__

#include "defs.h"

void 
intro_sort(void *a, _size_t_ n, _size_t_ es,
    _bool_ (*cmp) (const void *, const void *), _size_t_ lrange, _size_t_ rrange);


#endif 