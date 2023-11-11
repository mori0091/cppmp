#ifndef CPPMP_ENCLOSE_H_
#define CPPMP_ENCLOSE_H_

#include "./cat.h"
#include "./extract.h"

#define IS_ENCLOSED(...)      IS_ENCLOSED1(__VA_ARGS__, )
#define IS_ENCLOSED1(x, ...)  EXTRACT_OR_DEFAULT(IS_ENCLOSED_TEST x, 0)
#define IS_ENCLOSED_TEST(...) JUST(1)
// IS_ENCLOSED(a, b)   -> 0
// IS_ENCLOSED((a, b)) -> 1
// IS_ENCLOSED((a), b) -> 1
// IS_ENCLOSED(a, (b)) -> 0

#define IF_ENCLOSED(...)     CAT(IF_ENCLOSED, IS_ENCLOSED(__VA_ARGS__))
#define IF_ENCLOSED0(t, ...) __VA_ARGS__
#define IF_ENCLOSED1(t, ...) t
// IF_ENCLOSED(a,b)(true, false)   -> false
// IF_ENCLOSED((a,b))(true, false) -> true

#define ENCLOSE(...) (__VA_ARGS__)
// ENCLOSE(a,b,c)    -> (a,b,c)

#define DISCLOSE(...)                                                    \
  IF_ENCLOSED(__VA_ARGS__)(DISCLOSE0(__VA_ARGS__), __VA_ARGS__)
#define DISCLOSE0(...) DISCLOSE1 __VA_ARGS__
#define DISCLOSE1(...) __VA_ARGS__
// DISCLOSE(a,b,c)   -> a,b,c
// DISCLOSE((a,b,c)) -> a,b,c

#endif // CPPMP_ENCLOSE_H_
