#ifndef CPPMP_TAIL_H_
#define CPPMP_TAIL_H_

#include "./if.h"
#include "./is_nil.h"

#define TAIL(...)     IF(IS_NIL(__VA_ARGS__))(, TAIL1(__VA_ARGS__))
#define TAIL1(x, ...) __VA_ARGS__

#endif // CPPMP_TAIL_H_
