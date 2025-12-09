#include "vmath.h"
#include "math.h"
#include "vstd.h"


f32 maxf(f32 a, f32 b)
{
    return a > b ? a : b;
}

vec2 GetDirectionVector(vec2 v)
{
    float mag = VectorLength(v); 
    return mag == 0 ? vec2{0, 0} : vec2{v.x /mag, v.y/mag};
}

f32 absf(f32 val)
{
    return val > 0 ? val : -val;
}

vec2 GetUnitVector(vec2 v)
{
    f32 magnitude = VectorLength(v);
    return {v.x/magnitude, v.y/magnitude};
}

f32 EaseOutCubic(f32 number)
{
    return f32(sin((number * PI) / 2.0f));}


f32 Lerp(f32 start, f32 end, f32 amount)
{
    return start + amount*(end-start);
}

f32 Dot(vec2 v1, vec2 v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

f32 VectorLength(vec2 v)
{
    return sqrtf(powf(v.x, 2) + powf(v.y, 2)); 
}

f32 AngleBetween2Vectors(vec2 v1, vec2 v2)
{
    f32 dot = Dot(v1, v2);
    f32 mag1 = VectorLength(v1);
    f32 mag2 = VectorLength(v2);


    f32 cos = dot / (mag1 * mag2);

    if (cos >  1) cos =  1;
    if (cos < -1) cos = -1;
    
    return acosf(cos);
}

