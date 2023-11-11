#ifndef CPPMP_IS_NULL_H_
#define CPPMP_IS_NULL_H_

#include "./extract.h"

#define IS_NULL(x) EXTRACT_OR_DEFAULT(x JUST(1), 0)
// IS_NULL()      -> 1
// IS_NULL(())    -> 0
// IS_NULL(x)     -> 0
// IS_NULL((a,b)) -> 0
// IS_NULL(1)     -> 0

#endif // CPPMP_IS_NULL_H_
