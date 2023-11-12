// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_IS_NULL_H_
#define CPPMP_IS_NULL_H_

#include "./extract.h"

#define IS_NULL(x) EXTRACT_OR_DEFAULT(x JUST(1), 0)
// IS_NULL()      -> 1
// IS_NULL(())    -> 0
// IS_NULL(x)     -> 0
// IS_NULL((a,b)) -> 0
// IS_NULL(1)     -> 0

#endif // CPPMP_IS_NULL_H_
