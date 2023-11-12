// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_LAST_H_
#define CPPMP_LAST_H_

#include "./head.h"
#include "./reverse.h"
#include "./tail.h"

#define LAST(...)          HEAD(REVERSE(__VA_ARGS__))
#define TRUNCATE_LAST(...) REVERSE(TAIL(REVERSE(__VA_ARGS__)))

#endif // CPPMP_LAST_H_
