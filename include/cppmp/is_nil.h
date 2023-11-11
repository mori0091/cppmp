#ifndef CPPMP_IS_NIL_H_
#define CPPMP_IS_NIL_H_

#include "./cat.h"
#include "./extract.h"
#include "./variadic_size.h"

#define IS_NIL(...)                                                      \
  EXTRACT_OR_DEFAULT(CAT(IS_NIL, VARIADIC_SIZE(__VA_ARGS__)), 0)
#define IS_NIL1 JUST(1)
// IS_NIL()    -> 1
// IS_NIL(a)   -> 1
// IS_NIL(a,b) -> 0

#endif // CPPMP_IS_NIL_H_
