#ifndef BITMATH_H
#define BITMATH_H
#define SET_BIT(var,b) ((var)|=(1<<(b)))
#define CLR_BIT(var,b) ((var)&=(~(1<<(b))))
#define TGL_BIT(var,b) ((var)^=((1<<(b)))
#define GET_BIT(var,b) (((var>>(b))&1))


#endif
