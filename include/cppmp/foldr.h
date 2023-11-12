// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_FOLDR_H_
#define CPPMP_FOLDR_H_

#include "./defer.h"
#include "./if.h"
#include "./is_nil.h"
#include "./reverse.h"

#define FOLDR(f, ...) FOLDR_EVAL(DEFER(FOLDR_)(f, REVERSE(__VA_ARGS__), ))
#define FOLDR_(f, y, x, ...)                                             \
  IF(IS_NIL(__VA_ARGS__))                                                \
  (f(x, y), DEFER2(FOLDR_INDIRECT)()(f, f(x, y), __VA_ARGS__))
#define FOLDR_INDIRECT() FOLDR_
#define FOLDR_EVAL1(...) __VA_ARGS__
#define FOLDR_EVAL2(...) FOLDR_EVAL1(FOLDR_EVAL1(__VA_ARGS__))
#define FOLDR_EVAL3(...) FOLDR_EVAL2(FOLDR_EVAL2(__VA_ARGS__))
#define FOLDR_EVAL4(...) FOLDR_EVAL3(FOLDR_EVAL3(__VA_ARGS__))
#define FOLDR_EVAL5(...) FOLDR_EVAL4(FOLDR_EVAL4(__VA_ARGS__))
#define FOLDR_EVAL6(...) FOLDR_EVAL5(FOLDR_EVAL5(__VA_ARGS__))
#define FOLDR_EVAL7(...) FOLDR_EVAL6(FOLDR_EVAL6(__VA_ARGS__))
#define FOLDR_EVAL8(...) FOLDR_EVAL7(FOLDR_EVAL7(__VA_ARGS__))
#define FOLDR_EVAL(...)  FOLDR_EVAL8(__VA_ARGS__)
// FOLDR(f, a, b, c) -> f(a, f(b, c))

#endif // CPPMP_FOLDR_H_
