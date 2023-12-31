// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_IS_NIL_H_
#define CPPMP_IS_NIL_H_

#include "./cat.h"
#include "./extract.h"
#include "./variadic_size.h"

#define IS_NIL(...)                                                      \
  EXTRACT_OR_DEFAULT(CAT(IS_NIL, VARIADIC_SIZE(__VA_ARGS__)), 0)
#define IS_NIL1 JUST(1)
// IS_NIL()    -> 1
// IS_NIL(a)   -> 1
// IS_NIL(a,b) -> 0

#endif // CPPMP_IS_NIL_H_
