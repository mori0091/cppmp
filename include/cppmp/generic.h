#ifndef CPPMP_GENERIC_H_
#define CPPMP_GENERIC_H_

#include "./defer.h"
#include "./enclose.h"
#include "./expand.h"
#include "./if.h"
#include "./is_nil.h"
#include "./sep.h"

#define GENERIC(...) GENERIC_REDUNDANT(__VA_ARGS__)

// ----------------------------------------------------------------------
#define CPPMP_TYPE_ERROR ((struct { char TypeError; }){0})

// ----------------------------------------------------------------------
#define GENERIC_REDUNDANT(expr, f, g, ...)                               \
  GENERIC_((expr), f, g, __VA_ARGS__)
#define GENERIC_(expr, f, g, ...)                                        \
  GENERIC_EVAL(GENERIC__(expr, f, g, __VA_ARGS__, ))
#define GENERIC__(expr, f, g, x, ...)                                    \
  _Generic(expr, f ENCLOSE(DISCLOSE(x))                                  \
           : g ENCLOSE(DISCLOSE(x)) DEFER2(COMMA)() default              \
           : IF(IS_NIL(__VA_ARGS__))(                                    \
             CPPMP_TYPE_ERROR,                                           \
             DEFER2(GENERIC_INDIRECT)()(expr, f, g, __VA_ARGS__)))
#define GENERIC_INDIRECT() GENERIC__
#define GENERIC_EVAL1(...) __VA_ARGS__
#define GENERIC_EVAL2(...) GENERIC_EVAL1(GENERIC_EVAL1(__VA_ARGS__))
#define GENERIC_EVAL3(...) GENERIC_EVAL2(GENERIC_EVAL2(__VA_ARGS__))
#define GENERIC_EVAL4(...) GENERIC_EVAL3(GENERIC_EVAL3(__VA_ARGS__))
#define GENERIC_EVAL5(...) GENERIC_EVAL4(GENERIC_EVAL4(__VA_ARGS__))
#define GENERIC_EVAL6(...) GENERIC_EVAL5(GENERIC_EVAL5(__VA_ARGS__))
#define GENERIC_EVAL7(...) GENERIC_EVAL6(GENERIC_EVAL6(__VA_ARGS__))
#define GENERIC_EVAL8(...) GENERIC_EVAL7(GENERIC_EVAL7(__VA_ARGS__))
#define GENERIC_EVAL(...)  GENERIC_EVAL8(__VA_ARGS__)

// ----------------------------------------------------------------------
#define GENERIC_STRICT(expr, f, g, ...)                                  \
  _Generic((expr), GENERIC_SELECTORS(f, g, __VA_ARGS__))
#define GENERIC_SELECTORS(f, g, ...)                                     \
  GENERIC_SELECTORS_EVAL(GENERIC_SELECTORS_(f, g, __VA_ARGS__, ))
#define GENERIC_SELECTORS_(f, g, x, ...)                                 \
  f ENCLOSE(DISCLOSE(x))                                                 \
      : g ENCLOSE(DISCLOSE(x)) IF(IS_NIL(__VA_ARGS__))(                  \
          , DEFER2(COMMA)()                                              \
              DEFER2(GENERIC_SELECTORS_INDIRECT)()(f, g, __VA_ARGS__))
#define GENERIC_SELECTORS_INDIRECT() GENERIC_SELECTORS_
#define GENERIC_SELECTORS_EVAL1(...) __VA_ARGS__
#define GENERIC_SELECTORS_EVAL2(...)                                     \
  GENERIC_SELECTORS_EVAL1(GENERIC_SELECTORS_EVAL1(__VA_ARGS__))
#define GENERIC_SELECTORS_EVAL3(...)                                     \
  GENERIC_SELECTORS_EVAL2(GENERIC_SELECTORS_EVAL2(__VA_ARGS__))
#define GENERIC_SELECTORS_EVAL4(...)                                     \
  GENERIC_SELECTORS_EVAL3(GENERIC_SELECTORS_EVAL3(__VA_ARGS__))
#define GENERIC_SELECTORS_EVAL5(...)                                     \
  GENERIC_SELECTORS_EVAL4(GENERIC_SELECTORS_EVAL4(__VA_ARGS__))
#define GENERIC_SELECTORS_EVAL6(...)                                     \
  GENERIC_SELECTORS_EVAL5(GENERIC_SELECTORS_EVAL5(__VA_ARGS__))
#define GENERIC_SELECTORS_EVAL7(...)                                     \
  GENERIC_SELECTORS_EVAL6(GENERIC_SELECTORS_EVAL6(__VA_ARGS__))
#define GENERIC_SELECTORS_EVAL8(...)                                     \
  GENERIC_SELECTORS_EVAL7(GENERIC_SELECTORS_EVAL7(__VA_ARGS__))
#define GENERIC_SELECTORS_EVAL(...) GENERIC_SELECTORS_EVAL8(__VA_ARGS__)

#endif // CPPMP_GENERIC_H_
