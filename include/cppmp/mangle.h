// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_MANGLE_H_
#define CPPMP_MANGLE_H_

#include "./cat.h"
#include "./variadic_size.h"

/**
 * \brief Constructs an identifier.
 *
 * ~~~c
 * MANGLE(A)       // -> A        // A
 * MANGLE(A, B)    // -> pA_B     // (A, B)
 * MANGLE(A, B, C) // -> ppA_B_C  // ((A, B), C)
 * ~~~
 */
#define MANGLE(...) CAT(MANGLE, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)
// clang-format off
#define MANGLE1(_1)                                                      \
  _1
#define MANGLE2(_1, _2)                                                  \
  p##_1##_##_2
#define MANGLE3(_1, _2, _3)                                              \
  pp##_1##_##_2##_##_3
#define MANGLE4(_1, _2, _3, _4)                                          \
  ppp##_1##_##_2##_##_3##_##_4
#define MANGLE5(_1, _2, _3, _4, _5)                                      \
  pppp##_1##_##_2##_##_3##_##_4##_##_5
#define MANGLE6(_1, _2, _3, _4, _5, _6)                                  \
  ppppp##_1##_##_2##_##_3##_##_4##_##_5##_##_6
#define MANGLE7(_1, _2, _3, _4, _5, _6, _7)                              \
  pppppp##_1##_##_2##_##_3##_##_4##_##_5##_##_6##_##_7
#define MANGLE8(_1, _2, _3, _4, _5, _6, _7, _8)                          \
  ppppppp##_1##_##_2##_##_3##_##_4##_##_5##_##_6##_##_7##_##_8
#define MANGLE9(_1, _2, _3, _4, _5, _6, _7, _8, _9)                      \
  pppppppp##_1##_##_2##_##_3##_##_4##_##_5##_##_6##_##_7##_##_8##_##_9
// clang-format on

#endif // CPPMP_MANGLE_H_
