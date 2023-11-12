// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_SEP_BY_H_
#define CPPMP_SEP_BY_H_

#include "./defer.h"
#include "./enclose.h"
#include "./if.h"
#include "./is_nil.h"
#include "./sep.h"

#define SEP_BY(sep, f, ...) SEP_BY_EVAL(SEP_BY_I(sep, f, __VA_ARGS__, ))
#define SEP_BY_I(sep, f, x, ...)                                         \
  f ENCLOSE(DISCLOSE(x)) IF(IS_NIL(__VA_ARGS__))(                        \
    , DEFER2(sep)() DEFER2(SEP_BY_INDIRECT)()(sep, f, __VA_ARGS__))
#define SEP_BY_INDIRECT() SEP_BY_I
#define SEP_BY_EVAL1(...) __VA_ARGS__
#define SEP_BY_EVAL2(...) SEP_BY_EVAL1(SEP_BY_EVAL1(__VA_ARGS__))
#define SEP_BY_EVAL3(...) SEP_BY_EVAL2(SEP_BY_EVAL2(__VA_ARGS__))
#define SEP_BY_EVAL4(...) SEP_BY_EVAL3(SEP_BY_EVAL3(__VA_ARGS__))
#define SEP_BY_EVAL5(...) SEP_BY_EVAL4(SEP_BY_EVAL4(__VA_ARGS__))
#define SEP_BY_EVAL6(...) SEP_BY_EVAL5(SEP_BY_EVAL5(__VA_ARGS__))
#define SEP_BY_EVAL7(...) SEP_BY_EVAL6(SEP_BY_EVAL6(__VA_ARGS__))
#define SEP_BY_EVAL8(...) SEP_BY_EVAL7(SEP_BY_EVAL7(__VA_ARGS__))
#define SEP_BY_EVAL(...)  SEP_BY_EVAL8(__VA_ARGS__)
// SEP_BY(SEMICOLON, F, a, b, c)
// -> F(a) ; F(b) ; F(c)
// SEP_BY(SEMICOLON, F, (a,b), (c,d))
// -> F(a,b) ; F(c,d)

#endif // CPPMP_SEP_BY_H_
