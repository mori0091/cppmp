#ifndef CPPMP_LAST_H_
#define CPPMP_LAST_H_

#include "./head.h"
#include "./reverse.h"
#include "./tail.h"

#define LAST(...)          HEAD(REVERSE(__VA_ARGS__))
#define TRUNCATE_LAST(...) REVERSE(TAIL(REVERSE(__VA_ARGS__)))

#endif // CPPMP_LAST_H_
