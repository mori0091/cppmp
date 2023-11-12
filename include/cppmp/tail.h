// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_TAIL_H_
#define CPPMP_TAIL_H_

#include "./if.h"
#include "./is_nil.h"

#define TAIL(...)     IF(IS_NIL(__VA_ARGS__))(, TAIL1(__VA_ARGS__))
#define TAIL1(x, ...) __VA_ARGS__

#endif // CPPMP_TAIL_H_
