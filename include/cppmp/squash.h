// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_SQUASH_H_
#define CPPMP_SQUASH_H_

#include "./defer.h"
#include "./if.h"
#include "./is_nil.h"
#include "./is_null.h"
#include "./sep.h"
#include "./tail.h"

#define SQUASH(...)       TAIL(SQUASH_EVAL(SQUASH1(__VA_ARGS__, )))
#define SQUASH_INDIRECT() SQUASH1
#define SQUASH1(x, ...)                                                  \
  SQUASH0(x)                                                             \
  IF(IS_NIL(__VA_ARGS__))(, DEFER2(SQUASH_INDIRECT)()(__VA_ARGS__))
#define SQUASH0(x)        IF(IS_NULL(x))(, DEFER2(COMMA)() x)
#define SQUASH_EVAL1(...) __VA_ARGS__
#define SQUASH_EVAL2(...) SQUASH_EVAL1(SQUASH_EVAL1(__VA_ARGS__))
#define SQUASH_EVAL3(...) SQUASH_EVAL2(SQUASH_EVAL2(__VA_ARGS__))
#define SQUASH_EVAL4(...) SQUASH_EVAL3(SQUASH_EVAL3(__VA_ARGS__))
#define SQUASH_EVAL5(...) SQUASH_EVAL4(SQUASH_EVAL4(__VA_ARGS__))
#define SQUASH_EVAL6(...) SQUASH_EVAL5(SQUASH_EVAL5(__VA_ARGS__))
#define SQUASH_EVAL7(...) SQUASH_EVAL6(SQUASH_EVAL6(__VA_ARGS__))
#define SQUASH_EVAL8(...) SQUASH_EVAL7(SQUASH_EVAL7(__VA_ARGS__))
#define SQUASH_EVAL(...)  SQUASH_EVAL8(__VA_ARGS__)
// SQUASH(,,1,,2,3,,4,,,) -> 1, 2, 3, 4

#endif // CPPMP_SQUASH_H_
