// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_IF_H_
#define CPPMP_IF_H_

#define IF(x)     IF_(x)
#define IF_(x)    IF##x
#define IF0(t, f) f
#define IF1(t, f) t

#endif // CPPMP_IF_H_
