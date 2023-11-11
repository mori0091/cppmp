#ifndef CPPMP_IF_H_
#define CPPMP_IF_H_

#define IF(x)     IF_(x)
#define IF_(x)    IF##x
#define IF0(t, f) f
#define IF1(t, f) t

#endif // CPPMP_IF_H_
