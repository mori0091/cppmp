// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_APPLY_H_
#define CPPMP_APPLY_H_

#include "./defer.h"
#include "./enclose.h"
#include "./if.h"
#include "./is_nil.h"
#include "./sep.h"

#define APPLY(f, ...) APPLY_EVAL(APPLY_I(f, __VA_ARGS__, ))
#define APPLY_I(f, x, ...)                                               \
  f ENCLOSE(DISCLOSE(x)) IF(IS_NIL(__VA_ARGS__))(                        \
    , DEFER2(COMMA)() DEFER2(APPLY_INDIRECT)()(f, __VA_ARGS__))
#define APPLY_INDIRECT() APPLY_I
#define APPLY_EVAL1(...) __VA_ARGS__
#define APPLY_EVAL2(...) APPLY_EVAL1(APPLY_EVAL1(__VA_ARGS__))
#define APPLY_EVAL3(...) APPLY_EVAL2(APPLY_EVAL2(__VA_ARGS__))
#define APPLY_EVAL4(...) APPLY_EVAL3(APPLY_EVAL3(__VA_ARGS__))
#define APPLY_EVAL5(...) APPLY_EVAL4(APPLY_EVAL4(__VA_ARGS__))
#define APPLY_EVAL6(...) APPLY_EVAL5(APPLY_EVAL5(__VA_ARGS__))
#define APPLY_EVAL7(...) APPLY_EVAL6(APPLY_EVAL6(__VA_ARGS__))
#define APPLY_EVAL8(...) APPLY_EVAL7(APPLY_EVAL7(__VA_ARGS__))
#define APPLY_EVAL(...)  APPLY_EVAL8(__VA_ARGS__)

#endif // CPPMP_APPLY_H_
