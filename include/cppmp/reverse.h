// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_REVERSE_H_
#define CPPMP_REVERSE_H_

#include "./enclose.h"
#include "./foldl.h"
#include "./squash.h"

#define REVERSE(...) DISCLOSE(FOLDL(STACK_PUSH, (), __VA_ARGS__))
// REVERSE(1)     -> 1
// REVERSE(1,2)   -> 2, 1
// REVERSE(1,2,3) -> 3, 2, 1

#define STACK_PUSH(stack, x) (SQUASH(x, DISCLOSE(stack)))
// STACK_PUSH((), 1)    -> (1)
// STACK_PUSH((1), 2)   -> (2, 1)
// STACK_PUSH((2,1), 3) -> (3, 2, 1)

#endif // CPPMP_REVERSE_H_
