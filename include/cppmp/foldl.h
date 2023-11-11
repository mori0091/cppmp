#ifndef CPPMP_FOLDL_H_
#define CPPMP_FOLDL_H_

#include "./defer.h"
#include "./if.h"
#include "./is_nil.h"

#define FOLDL(f, ...) FOLDL_EVAL(FOLDL_(f, __VA_ARGS__, ))
#define FOLDL_(f, x, y, ...)                                             \
  IF(IS_NIL(__VA_ARGS__))                                                \
  (f(x, y), DEFER2(FOLDL_INDIRECT)()(f, f(x, y), __VA_ARGS__))
#define FOLDL_INDIRECT() FOLDL_
#define FOLDL_EVAL1(...) __VA_ARGS__
#define FOLDL_EVAL2(...) FOLDL_EVAL1(FOLDL_EVAL1(__VA_ARGS__))
#define FOLDL_EVAL3(...) FOLDL_EVAL2(FOLDL_EVAL2(__VA_ARGS__))
#define FOLDL_EVAL4(...) FOLDL_EVAL3(FOLDL_EVAL3(__VA_ARGS__))
#define FOLDL_EVAL5(...) FOLDL_EVAL4(FOLDL_EVAL4(__VA_ARGS__))
#define FOLDL_EVAL6(...) FOLDL_EVAL5(FOLDL_EVAL5(__VA_ARGS__))
#define FOLDL_EVAL7(...) FOLDL_EVAL6(FOLDL_EVAL6(__VA_ARGS__))
#define FOLDL_EVAL8(...) FOLDL_EVAL7(FOLDL_EVAL7(__VA_ARGS__))
#define FOLDL_EVAL(...)  FOLDL_EVAL8(__VA_ARGS__)
// FOLDL(f, a, b, c)             -> f(f(a, b), c)

#endif // CPPMP_FOLDL_H_
