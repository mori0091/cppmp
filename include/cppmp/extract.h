#ifndef CPPMP_EXTRACT_H_
#define CPPMP_EXTRACT_H_

#include "./cat.h"
#include "./if.h"
#include "./maybe.h"

#define HAS_VALUE(maybe)    CAT(HAS_VALUE_, maybe)
#define HAS_VALUE_JUST(...) 1
#define HAS_VALUE_NOTHING   0
// HAS_VALUE(JUST(x)) -> 1
// HAS_VALUE(NOTHING) -> 0

#define EXTRACT_VALUE_OF(maybe)    CAT(EXTRACT_VALUE_OF_, maybe)
#define EXTRACT_VALUE_OF_JUST(...) __VA_ARGS__
// EXTRACT_VALUE_OF(JUST(FOO)) -> FOO

#define EXTRACT_OR_DEFAULT(x, ...)                                       \
  IF(HAS_VALUE(MAYBE(x)))(EXTRACT_VALUE_OF(x), __VA_ARGS__)
// EXTRACT_OR_DEFAULT(JUST(FOO), DEFAULT) -> FOO
// EXTRACT_OR_DEFAULT(FOO, DEFAULT)       -> DEFAULT

#endif // CPPMP_EXTRACT_H_
