#ifndef CPPMP_BIND_H_
#define CPPMP_BIND_H_

#include "./defer.h"
#include "./enclose.h"
#include "./if.h"
#include "./is_nil.h"
#include "./sep.h"

#define BIND(a, ...)          BIND_SEP_BY(COMMA, , a, __VA_ARGS__)

#define BIND_FOR(f, a, ...)   BIND_SEP_BY(SEMICOLON, f, a, __VA_ARGS__)

#define BIND_APPLY(f, a, ...) BIND_SEP_BY(COMMA, f, a, __VA_ARGS__)

#define BIND_SEP_BY(sep, f, a, ...)                                      \
  BIND_EVAL(BIND1(sep, f, a, __VA_ARGS__, ))
#define BIND_INDIRECT() BIND1
#define BIND1(sep, f, a, x, ...)                                         \
  f(DISCLOSE(a), x) IF(IS_NIL(__VA_ARGS__))(                             \
    , DEFER2(sep)() DEFER2(BIND_INDIRECT)()(sep, f, a, __VA_ARGS__))
#define BIND_EVAL1(...) __VA_ARGS__
#define BIND_EVAL2(...) BIND_EVAL1(BIND_EVAL1(__VA_ARGS__))
#define BIND_EVAL3(...) BIND_EVAL2(BIND_EVAL2(__VA_ARGS__))
#define BIND_EVAL4(...) BIND_EVAL3(BIND_EVAL3(__VA_ARGS__))
#define BIND_EVAL5(...) BIND_EVAL4(BIND_EVAL4(__VA_ARGS__))
#define BIND_EVAL6(...) BIND_EVAL5(BIND_EVAL5(__VA_ARGS__))
#define BIND_EVAL7(...) BIND_EVAL6(BIND_EVAL6(__VA_ARGS__))
#define BIND_EVAL8(...) BIND_EVAL7(BIND_EVAL7(__VA_ARGS__))
#define BIND_EVAL(...)  BIND_EVAL8(__VA_ARGS__)
// BIND(a, b, c, d)
// -> (a, b), (a, c), (a, d)
// BIND((a,b), c, d)
// -> (a,b,c), (a,b,d)

#endif // CPPMP_BIND_H_
