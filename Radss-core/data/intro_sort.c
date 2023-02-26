#include "defs.h"

// swap sequence two pointer 
#define swapSeqPointer(TYPE, parmi, parmj, n){  \
    _size_t_ index = (n) / sizeof(TYPE);        \
    TYPE *pi = (TYPE *)(void *)(parmi);         \
    TYPE *pj = (TYPE *)(void *)(parmj);         \
    do {                                        \
        TYPE t = *pi;                           \
        *pi++ = *pj;                            \
        *pj++ = t;                              \
    } while(--index > 0);                       \
} 

// select medium in three 
static inline _uint_8_* 
med3(_uint_8_ *a, _uint_8_ *b, _uint_8_ *c,
    int (*cmp)(const void *, const void *))
{
    return cmp(a, b) < 0 ?
            (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a))
            :(cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c));
}

// swap whole sequence
static inline void 
swapSequence(_uint_8_ *a, _uint_8_ *b, _size_t_ n, int type)
{
    if (type <= 1)
        swapSeqPointer(_uint_32_, a, b, n)
    else 
        swapSeqPointer(_uint_8_, a, b, n)
}

#define swapPairPointer(a, b)                                           \
    if(type == 0) {                                                     \
        _uint_32_ t = *(_uint_32_ *) (void *)(a);                       \
        *(_uint_32_ *)(void *)(a) = *(_uint_32_ *)(void *)(b);          \
        *(_uint_32_ *)(void *)(b) = t;                                  \
    } else                                                              \
        swapSequence(a, b, es, type) 

#define SWAPINIT(a, es) type = (_uint_64_)a % sizeof(_uint_32_) ||      \
    es % sizeof(_uint_32_) ? 2 : es == sizeof(_uint_32_)? 0 : 1;

#define vecswap(a, b, n) if((n) > 0) swapSequence((a), (b), (_size_t_)(n), type)

static void 
_intro_sort(void *a, _size_t_ n, _size_t_ es, 
    _bool_ (*cmp) (const void *, const void *), void *lrange, void *rrange)
{
    _uint_8_ *pa, *pb, *pc, *pd, *pl, *pm, *pn;
    _size_t_ d, r;
    int type, cmp_result;

loop:   SWAPINIT(a, es);
    /// bubble sort
    if(n < _M_N_1){
        for(pm = (_uint_8_ *) a + es; pm < (_uint_8_ *)a + n * es; pm += es)
            for (pl = pm; pl > (_uint_8_ *) a && cmp(pl - es, pl) > 0; pl -= es)
                swapPairPointer(pl, pl - es);
        return;
    }
    pm = (_uint_8_ *) a + (n >> 1) * es;
    // quick_sort
    if (n > _M_N_1) {
        pl = (_uint_8_ *) a;
        pn = (_uint_8_ *) a + (n - 1) * es;
        if (n > _M_N_2) {
            d = (n >> 3) * es;
            pl = med3(pl, pl + d, pl + (d << 1), cmp);
            pm = med3(pm - d, pm, pm + d, cmp);
            pn = med3(pn - (d << 1), pn - d, pn, cmp);
        }
        pm = med3(pl, pm, pn, cmp);
    }
    swapPairPointer(a, pm);
    pa = pb = (_uint_8_ *) a + (n - 1) * es;
    // compaction
    while ( _TRUE_ ) { 
        while(pb <= pc && (cmp_result = cmp(pb, a)) <= 0) {
            if(cmp_result == 0) {
                swapPairPointer(pa, pb);
                pa += es;
            }
            pb += es;
        }
        while(pb <= pc && (cmp_result = cmp(pc, a)) >= 0) {
            if (cmp_result == 0) {
                swapPairPointer(pc, pd);
                pd -= es;
            }
            pc -= es;    
        }
        if( pb > pc)
            break;
        swapPairPointer(pb, pc);
        pb += es;
        pc -= es;
    }

    // recursive
    pn = (_uint_8_ *) a + n *es;
    r = _min_func_(pa - (_uint_8_ *)a, pb - pa);
    vecswap(a, pb - r, r);
    r = _min_func_((_size_t_)(pd - pc), pn - pd - es);
    vecswap(pb, pn - r, r);
    if ((r = pb - pa) > es) {
        void *_l = a, *_r = ((_uint_8_ *)a) + r - 1;
        if(!((lrange < _l && rrange < _l) || (lrange > _r && rrange > _r)))
            _intro_sort(a, r / es, es, cmp, lrange, rrange);
    } 
    if ((r = pd - pc)  > es) {
        a = pn - r, n = r / es;
        void *_l = a, *_r = ((_uint_8_ *)a) + r - 1;
        if(!((lrange < _l && rrange < _l) || (lrange > _r && rrange > _r)))
            goto loop;
    }
}

// union
void 
intro_sort(void *a, _size_t_ n, _size_t_ es,
    _bool_ (*cmp) (const void *, const void *), _size_t_ lrange, _size_t_ rrange)
{
    _intro_sort(a, n, es, cmp, ((_uint_8_*)a+(lrange+es)),
                                (_uint_8_*)a+((rrange+1)*es)-1);
}