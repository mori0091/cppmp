#ifndef CPPMP_MAYBE_H_
#define CPPMP_MAYBE_H_

#include "./cat.h"
#include "./eat.h"

#define MAYBE(x)         MAYBE0(MAYBE_STRUCT(x))
#define MAYBE0(x)        MAYBE1 x
#define MAYBE1(_, maybe) maybe
// MAYBE(JUST(x)) -> JUST(x)
// MAYBE(FOO)     -> NOTHING

#define MAYBE_STRUCT(x) (CAT(MAYBE_STRUCT_, x), NOTHING)
#define MAYBE_STRUCT_JUST(...) EXPANDED, JUST(__VA_ARGS__) ) EAT (
// MAYBE_STRUCT(JUST(x)) -> (EXPANDED, JUST(x))
// MAYBE_STRUCT(FOO)     -> (MAYBE_STRUCT_FOO, NOTHING)

#endif // MAYBE_H_
