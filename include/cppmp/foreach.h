// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_FOREACH_H_
#define CPPMP_FOREACH_H_

#include "./defer.h"
#include "./enclose.h"
#include "./if.h"
#include "./is_nil.h"
#include "./sep.h"

#define FOREACH(f, ...) FOREACH_EVAL(FOREACH_I(f, __VA_ARGS__, ))
#define FOREACH_I(f, x, ...)                                             \
  f ENCLOSE(DISCLOSE(x)) IF(IS_NIL(__VA_ARGS__))(                        \
    , DEFER2(SEMICOLON)() DEFER2(FOREACH_INDIRECT)()(f, __VA_ARGS__))
#define FOREACH_INDIRECT() FOREACH_I
#define FOREACH_EVAL1(...) __VA_ARGS__
#define FOREACH_EVAL2(...) FOREACH_EVAL1(FOREACH_EVAL1(__VA_ARGS__))
#define FOREACH_EVAL3(...) FOREACH_EVAL2(FOREACH_EVAL2(__VA_ARGS__))
#define FOREACH_EVAL4(...) FOREACH_EVAL3(FOREACH_EVAL3(__VA_ARGS__))
#define FOREACH_EVAL5(...) FOREACH_EVAL4(FOREACH_EVAL4(__VA_ARGS__))
#define FOREACH_EVAL6(...) FOREACH_EVAL5(FOREACH_EVAL5(__VA_ARGS__))
#define FOREACH_EVAL7(...) FOREACH_EVAL6(FOREACH_EVAL6(__VA_ARGS__))
#define FOREACH_EVAL8(...) FOREACH_EVAL7(FOREACH_EVAL7(__VA_ARGS__))
#define FOREACH_EVAL(...)  FOREACH_EVAL8(__VA_ARGS__)

#endif // CPPMP_FOREACH_H_
