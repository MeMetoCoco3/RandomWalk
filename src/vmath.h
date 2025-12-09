#ifndef VMATH
#define VMATH

#include <raylib.h>
#include "vstd.h"

vec2 GetDirectionVector(vec2 v);
f32 Dot(vec2 v1, vec2 v2);
f32 AngleBetween2Vectors(vec2 v1, vec2 v2);
f32 Lerp(f32 start, f32 end, f32 amount);
f32 EaseOutCubic(f32 number);
f32 maxf(f32 a, f32 b);
f32 absf(f32 val);
f32 VectorLength(vec2 v);
//f32 EaseOutExpo(f32 x);
vec2 GetUnitVector(vec2 v);

#endif


