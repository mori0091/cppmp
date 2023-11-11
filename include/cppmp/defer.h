#ifndef CPPMP_DEFER_H_
#define CPPMP_DEFER_H_

#include "./empty.h"

#define DEFER(x)  x EMPTY()
#define DEFER2(x) x DEFER(EMPTY)()

#endif // CPPMP_DEFER_H_
