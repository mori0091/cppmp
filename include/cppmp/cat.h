// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/cppmp/blob/main/LICENSE
//
// GitHub cppmp project
// https://github.com/mori0091/cppmp

#ifndef CPPMP_CAT_H_
#define CPPMP_CAT_H_

#include "./eat.h"

// #define CAT(a, b)  CAT0(a, b)
// #define CAT0(a, b) a##b

// Find the result of testing whether a macros is enclosed or not
#define CAT_STRUCT(a, b) (a, CAT_STRUCT_ b, PRIMITIVE, b)
#define CAT_STRUCT_(...) EXPANDED, ENCLOSED, (__VA_ARGS__) ) EAT (
// CAT_STRUCT(x,y)     -> (x, CAT_STRUCT_ y, PRIMITIVE, y)
// CAT_STRUCT(x,(y,z)) -> (x, EXPANDED     , ENCLOSED , (y,z))

// Pattern match the result of testing if it is enclose or not
#define CAT_(a, _, f, b)    CAT_##f(a, b)
#define CAT_ENCLOSED(a, b)  a b
#define CAT_PRIMITIVE(a, b) a##b

// Defer the call to the CAT so that we get the updated parameters first
#define CAT(a, b) CAT0(CAT_STRUCT(a, b))
#define CAT0(...) CAT_ __VA_ARGS__
// CAT(a,b)            -> ab
// CAT(f, (x,y))       -> f (x,y)
// CAT((a,b,c), (d,e)) -> (a,b,c) (d,e)

#endif // CPPMP_CAT_H_
