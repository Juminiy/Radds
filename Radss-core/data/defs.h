// #pragma once 

#ifndef __DEFS__
#define __DEFS__

/// type define
#define _uint_64_ unsigned long long int 
#define _uint_32_ unsigned long int
#define _uint_8_ unsigned char 
#define _int_64_ long long int
#define _int_32_ int 
#define _int_8_ char 
#define _bit_ _uint_32_
#define _bool_ _int_32_

#define _size_t_ _uint_64_
#define _size_b_ _uint_8_
#define SIZE_ZERO 0

#define _TRUE_  1
#define _FALSE_ 0

/// magic number
#define _M_N_1 7
#define _M_N_2 40

/// function define
#define _min_func_(a, b) (a) < (b) ? a : b
#define _max_func_(a, b) (a) > (b) ? a : b 

#endif 
