// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_DEFER_H_
#define CPPMP_DEFER_H_

#include "./empty.h"

#define DEFER(x)  x EMPTY()
#define DEFER2(x) x DEFER(EMPTY)()

#endif // CPPMP_DEFER_H_
